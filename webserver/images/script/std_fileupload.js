﻿/*!
	(c) 2014 LANSA
	jQuery File upload plugin weblet
	$Workfile:: std_fileupload.js           $
	$UTCDate:: 2014-03-12 05:33:55Z         $
	$Revision:: 9                           $

	Based on:
	jQuery File Upload Plugin Basic Plus Demo 1.3.5
	https://github.com/blueimp/jQuery-File-Upload

	Copyright 2013, Sebastian Tschan
	https://blueimp.net
 
	Licensed under the MIT license:
	http://www.opensource.org/licenses/MIT
*/

//Initialize file upload weblets
(function() {
	jQuery(function() {

		jQuery("div.std_fileupload").each(function(i, elem) {
			var $elem = jQuery(elem),
				id = $elem.data("lstdfileupload-id"),
				$input = jQuery(Lstd.Utils.makeSafeId(id)).detach(),
				isDisabled = ($input.attr("disabled") === "disabled"),
				uploadWamName = $input.data("lansawam"),
				uploadWrName = $input.data("lansawr"),
				lansaweb = stdFormatHttpRequest(null, uploadWamName, uploadWrName, null, null, true),
				maxSizeMb = $input.data("lstdmaxfilesize"),
				maxSize = maxSizeMb * 1000000,
				maxNumber = $input.data("lstdmaxnumberoffiles"),
				extraFields = $input.data("lansaextrafields"),
				$span = $elem.find("span.fileinput-button"),
				$caption = $span.find("span"),
				$container = jQuery(Lstd.Utils.makeSafeId("__" + id + "_FILES")).find("tbody"),
				useAjax = $input.data("lstduseajax"),
				pb = "__" + id + "_PROGRESS",
				btnClass = "std_button_v2" + (($input.data("lstdclass") != undefined) ? (" " + $input.data("lstdclass")) : ""),
				successCB = ($input.data("lstdsuccesscallback") != undefined) ? window[$input.data("lstdsuccesscallback")] : null,
				failCB = ($input.data("lstdfailcallback") != undefined) ? window[$input.data("lstdfailcallback")] : null,
				uploadForm = null;

			if (($caption.text() == "Default") || ($caption.text() == "")) {
				$caption.text(g_StdLocaleMgr.getMessageText("SelectFiles"));
			}

			$span.button({icons: {primary: 'ui-icon-plusthick'}, disabled: isDisabled}).append($input); // Detach and append follows jQuery UI Demo sample.
			Lstd.Weblets.stdProgressBar.init(pb, {value: 0, transitory: true, delayClose: 200});

			$input.fileupload({
				url: lansaweb,
				dataType: 'json',
				autoUpload: false,
				maxFileSize: maxSize,
				maxNumberOfFiles: maxNumber,
				add: function(e, data) {
					jQuery.each(data.files, function (index, file) {
						var count = $container.children("tr").length;

						// Validate
						if (count >= maxNumber) {
							errFlag = true;
							var msgText = (maxNumber == 1) ? g_StdLocaleMgr.getMessageText("OnlyOneFile") : g_StdLocaleMgr.getMessageText("TooManyFiles", maxNumber);
							Lstd.Weblets.dialog.alert({text: msgText});
						}
						else if (file.size && (file.size > maxSize)) {
							errFlag = true;
							Lstd.Weblets.dialog.alert({text: g_StdLocaleMgr.getMessageText("MaxFileSize", maxSizeMb, file.name)});
						}
						else {
							var $uploadBtn = Lstd.Weblets.stdFileUpload.uploadBtnFactory(btnClass, pb, failCB);

							data.context = jQuery("<tr/>").appendTo($container);
							var $row = data.context;
							$row.append(jQuery("<td/>").text(file.name));
							$row.append(jQuery("<td/>").append($uploadBtn.data(data)));
						}
					});
				},
				submit: function (e, data) {
					if (!uploadForm) {
						uploadForm = createStdHiddenForm(uploadWamName, uploadWrName, ("__" + id + "_FORM"));
					}
					Lstd.Fields.insertExtraFields(uploadForm, (extraFields ? extraFields : []));
					data.formData = jQuery(uploadForm).serializeArray();
					return true;
				},
				done: function (e, data) {
					if (typeof successCB == "function") {
						try {
							successCB(e, Lstd.Json.factory(data.result));
						}
						catch (err) {
							console.error(err);
						}
					}
				},
				fail: function (e, data) {
					var responseText = data.jqXHR ? (data.jqXHR.responseText ? data.jqXHR.responseText : null) : null;
					Lstd.Weblets.stdFileUpload.fail(failCB, e, responseText, data.errorThrown);
				},
				progressall: function (e, data) {
					var progress = parseInt(data.loaded / data.total * 100, 10);
					Lstd.Weblets.stdProgressBar.value(pb, progress);
				}
			});
		});
	});
})();

// File upload weblet

Lstd.Weblets.stdFileUpload = {
	/**
	 * Creates an upload button for a file
	 * @param [string] Button class
	 * @param [string] Progress bar id
	 * @param [function] Fail callback
	 */
	uploadBtnFactory: function(btnClass, pb, failCB) {
		var $uploadBtn = jQuery("<button/>").addClass(btnClass);
		$uploadBtn.button({icons: {primary: "ui-icon-circle-arrow-e"}, label: g_StdLocaleMgr.getMessageText("Upload")});

		$uploadBtn.on('click', function () {
			var $this = jQuery(this),
				data = $this.data();

			$this.off('click');
			$this.button("option", {icons: {primary: "ui-icon-cancel"}, label: g_StdLocaleMgr.getMessageText("Abort")});
			$this.on('click', function () {
				$this.remove();
				data.abort();
			});

			Lstd.Weblets.stdProgressBar.start(pb);

			data.submit()
				.fail(function() {
					jQuery("<span class=\"ui-icon ui-icon-close\" />").appendTo($this.parent());
				})
				.done(function() {
					jQuery("<span class=\"ui-icon ui-icon-check\" />").appendTo($this.parent());
				})
				.always(function () {
					Lstd.Weblets.stdProgressBar.stop(pb);
					$this.remove();
			});
		});
		return $uploadBtn;
	},
	/**
	 * Handles upload failure
	 * @param [function] Fail callback
	 * @param [object] Event object
	 * @param [string] XHR response text
	 * @param [string] Error thrown
	 */
	fail: function(failCB, e, responseText, errorThrown) {
		if (typeof failCB == "function") {
			var wr = null;

			if (responseText) {
				try {
					var o = jQuery.parseJSON(responseText);
					if (Lstd.Json.isWebroutine(o)) {
						wr = Lstd.Json.factory(o);
					}
				}
				catch (err) {
					console.error(err);
				}
			}

			if (wr == null) {
				wr = Lstd.Json.factory(),
				msgs = wr.messages();
				msgs.add(errorThrown);
			}

			try {
				failCB(null, wr);
			}
			catch (err) {
				console.error(err);
			}
		}
	}
};