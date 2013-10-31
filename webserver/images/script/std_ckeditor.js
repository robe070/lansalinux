/*!
	(c) 2011, 2013 LANSA
	CKEditor Rich Text Editor
	$Workfile:: std_ckeditor.js             $
	$UTCDate:: 2013-10-02 00:48:07Z         $
	$Revision:: 15                          $
*/

Lstd.Utils.stylesheets = function()
{
	var links = document.styleSheets;
	var ar = [];
	for (var i = 0; i < links.length; i++)
	{
		var href = links.item(i).href;
		if ((href != null) && (href != "")) ar.push(href);
	}
	return ar;
};

/**
 * CKEditor Rich Text Editor widget
 * Options
 * textAreaId: Text area id
 * toolbar: Basic of Full
 * toolbarCanCollapse: boolean
 * width
 * height
 * resize_enabled
 * resize_dir
 * autoGrow
 * autoGrow_maxHeight
 * autoGrow_minHeight
 * resize_maxHeight
 * resize_maxWidth
 * resize_minHeight
 * resize_minWidth
 * tabIndex
 * uiColor
 */
Lstd.Weblets.stdCKEditor = {
	input: function(args) {
		jQuery(function() {
			var textArea = jQuery(Lstd.Utils.makeSafeId(args.textAreaId));

			// Get initial value stored either in Lstd.Fields or the grid cell value
			if (args.valueFromField === true)
			{
				// Check for empty or new-line-only content
				if (Lstd.Utils.isTextAreaEmpty(Lstd.Fields.getValue(args.textAreaId)))
				{
					if (Lstd.Utils.isListID(args.textAreaId))
					{
						var td = textArea.closest("td[__cellvalue]");
						var cellvalue = td ? td.attr("__cellvalue") : undefined;
						if (cellvalue != undefined) document.getElementById(args.textAreaId).value = cellvalue;
					}
					else
					{
						document.getElementById(args.textAreaId).value = Lstd.Fields.getInitialValue(args.textAreaId);
					}
				}
			}

			var calcColor = "#" + Lstd.Utils.getHexColor(args.uiColor ? args.uiColor : textArea.siblings(".ui-widget-header").css("background-color"));
			
			var toolbar_Basic = [
				['Bold', 'Italic', '-', 'NumberedList', 'BulletedList', '-', 'Link', 'Unlink','-','About']
			];

			var toolbar_Full = [
				['Source', '-', 'Templates'],
				['Cut','Copy','Paste','PasteText','PasteFromWord','-','Print', 'SpellChecker', 'Scayt'],
				['Undo','Redo','-','Find','Replace','-','SelectAll','RemoveFormat'],
				'/',
				['Bold','Italic','Underline','Strike','-','Subscript','Superscript'],
				['NumberedList','BulletedList','-','Outdent','Indent','Blockquote','CreateDiv'],
				['JustifyLeft','JustifyCenter','JustifyRight','JustifyBlock'],
				['Link','Unlink','Anchor'],
				['Image','Flash','Table','HorizontalRule','Smiley','SpecialChar','PageBreak'],
				'/',
				['Styles','Format','Font','FontSize'],
				['TextColor','BGColor'],
				['Maximize', 'ShowBlocks','-','About']
			];

			var bodyId = "lckeditor_" + args.textAreaId;
			var removePlugins = "save";

			var options = {
				customConfig: "",
				bodyClass: "ui-widget-content",
				bodyId: bodyId,
				dialog_backgroundCoverColor: calcColor,
				uiColor: calcColor
			};

			if (window.g_lxmlISOLang != "") options.language = window.g_lxmlISOLang;

			switch (args.toolbar)
			{
				case "Full":
					if (!args.showSource) toolbar_Full[0] = toolbar_Full[0].slice(2); // Remove source from toolbar
					options.toolbar = toolbar_Full;
					Lstd.Weblets.stdCKEditor.localizeFont(options);
					break;
				case "Basic":
				default:
					options.toolbar = toolbar_Basic;
					break;
			}

			options.resize_enabled = args.resize_enabled ? args.resize_enabled : false;

			if (args.showElementsPath === false) removePlugins += ",elementspath";
			if (!args.autoGrow) removePlugins += ",autogrow";

			// Directly mapped options
			Lstd.Utils.mapArg2Option(args, options, ["toolbarCanCollapse", "width", "height", "resize_dir", "autoGrow_maxHeight",
				"autoGrow_minHeight", "resize_maxHeight", "resize_maxWidth", "resize_minHeight", "resize_minWidth", "tabIndex"]);

			if (args.contentsCss)
			{
				var css = args.contentsCss.split(",");
				for (var i = 0; i < css.length; i++) css[i].trim();
				options.contentsCss = css;
			}
			else
			{
				options.contentsCss = Lstd.Utils.stylesheets(); // Inherit
			}

			options.removePlugins = removePlugins; // Must assign after removePlugins value is finalised
			var ed = textArea.ckeditor(options);

			if (typeof args.onchangeScript == "function") {
				try {
					CKEDITOR.instances[args.textAreaId].on("blur", function(event) {
						if (event.editor.checkDirty()) {
							args.onchangeScript();
						}
					});
				}
				catch (e) {
					alert(e);
				}
			}

			// Update the textarea when the form is submitted.
			var f = ed.closest("form");
			Lstd.Messaging.addListener((f.get(0) ? f.attr("name") : "") + ".submit", function() {
				ed.ckeditorGet().updateElement();
			},
			ed);
		});
	},
	localizeFont: function(options) {
		var lang = jQuery("body").attr("lang");
		if (lang != undefined) {
			switch (lang) {
				case "ja":
					options.font_names = "Meiryo UI; Meiryo; Hiragino Kaku Gothic Pro; MS Gothic;" + CKEDITOR.config.font_names;
					options.font_defaultLabel = "Meiryo";
					break;
				case "ko":
					options.font_names = "Dotum;" + CKEDITOR.config.font_names;
					options.font_defaultLabel = "Dotum";
					break;
				case "zh":
				case "zh-CN":
				case "zh-SG":
					options.font_names = "Microsoft YaHei UI; Microsoft YaHei; SimSun;" + CKEDITOR.config.font_names;
					options.font_defaultLabel = "SimSun";
					break;
				case "zh-HK":
				case "zh-TW":
					options.font_names = "Microsoft JhengHei UI; Microsoft JhengHei; PMingLiU;" + CKEDITOR.config.font_names;
					options.font_defaultLabel = "PMingLiU";
					break;
				default:
					break;
			}
		}
	}
};
