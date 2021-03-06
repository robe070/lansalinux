﻿/*!
	(c) 2011, 2013 LANSA
	XHTML jQuery UI extensions
	$Workfile:: std_jqueryui.js             $
	$UTCDate:: 2014-02-20 02:06:45Z         $
	$Revision:: 83                          $
*/

/**
 * jQuery global extensions
 */
 
;(function($) {
	$.extend({lansa: {
		makeSafeId: function(id) {
				return Lstd.Utils.makeSafeId(id);
			}
		}
	});
})(jQuery);

/**
 * Weblet Utilities
 */

Lstd.Weblets.Utils = {

	/**
	 * Loads the jQuery i18n JavaScript file. If the qualified language code file.
	 *	If not found it loads the base language file.
	 * @param {string} jsfile The partial JS file path (Exclude the images path)
	 * @param {function} charsetCB An optional callback function that returns the charset to use for the script file. If not provided, charset defaults to "utf-8".
	 * @return {string} ISO language code for regional JS file loaded. If none loaded, it returns "".
	 */
	getI18nScript: function(jsfile, charsetCB) {
		var regionalJS = g_lweb_images_path + jsfile;
		var retLang = g_lxmlISOLang;

		jQuery.ajax({type: "GET",
			async: false,
			dataType: "script",
			url: regionalJS + g_lxmlISOLang + ".js",
			error: function() {
				var baseLang = Lstd.I18n.baseISOLang(g_lxmlISOLang);
				if (baseLang != g_lxmlISOLang)
				{
					retLang = baseLang;
					jQuery.ajax({type: "GET",
						async: false,
						dataType: "script",
						url: regionalJS + baseLang + ".js",
						error: function() {
							retLang = "";
						},
						scriptCharset: (typeof charsetCB == "function") ? charsetCB(baseLang) : "utf-8"
					});
				}
				else
				{
					retLang = "";
				}
			},
			scriptCharset: (typeof charsetCB == "function") ? charsetCB(g_lxmlISOLang) : "utf-8"
		});
		return retLang;
	},

	/**
	 * Returns the hidden division. If not found, it creates it
	 * @param {object} The jQuery object to which to append the hidden division if created
	 * @return {object} The jQuery object for the hidden division
	 */
	 getHiddenDiv: function(elem) {
		var theHiddenDiv = jQuery("#lweb_hidden");
		if (theHiddenDiv.length == 0) {
			theHiddenDiv = jQuery("<div id=\"lweb_hidden\" class=\"hidden\" style=\"display:none;\"></div>");
			if (elem) {
				theHiddenDiv.appendTo(elem);
			}
			else {
				theHiddenDiv.appendTo("body");
			}
		}
		return theHiddenDiv;
	 }
};

/**
 * Datepicker widget
 */

Lstd.Weblets.stdDatePicker = {
	/**
	 * Global initialization flag. Set to true when once-off static initialization is completed.
	 */
	globalInitFlag: false,

	/**
	 * Default regional settings;
	 */
	lang: "",

	/**
	 * Sets global defaults for all datepicker instances
	 */
	globalInit: function() {
		if (this.globalInitFlag) return;
		this.globalInitFlag = true;

		if (!(window.g_lxmlISOLang == "") && !(window.g_lxmlISOLang == "en"))
		{
			this.lang = Lstd.Weblets.Utils.getI18nScript("/jquery-ui/" + jQuery.ui.version + "/js/i18n/jquery.ui.datepicker-");
		}
	},

	/**
	 * Formats the proxy date field using the jQuery datepicker format funtion.
	 */
	proxyFormat: function(dateFormat, isoDate)
	{
		return jQuery.datepicker.formatDate(dateFormat, (new stdDateTimeParser(isoDate, "YYYY-MM-DD", "")).dateValue);
	},

	/**
	 * jQuery UI datepicker (input mode) weblet
	 * Options
	 * dateId: id of hidden field storing date in standard format
	 * dateFormat: Date format
	 * firstDay: Day to show as first day of the week in calendar
	 */
	input: function(args)
	{
		var sdp = this;
		sdp.globalInit();

		jQuery(function() {

			/* Arguments: dateId, dateFormat, firstDay, changeMonth, changeYear, showOn, buttonImage, buttonText,
				disabled, allowSQLNull, autoSize, showAnim, duration, onchangeScript */

			var proxy = jQuery(Lstd.Utils.makeSafeId("__" + args.dateId + "_PROXY"));
			var allowSQLNull = args.allowSQLNull ? args.allowSQLNull : false;
			var wdateFormat = args.dateFormat ? args.dateFormat : jQuery.datepicker.regional[sdp.lang].dateFormat;
			var val = sdp.proxyFormat(wdateFormat, document.getElementById(args.dateId).value);

			proxy.val(val);
			proxy.attr("_initVal", val);
			var options = {altField: Lstd.Utils.makeSafeId(args.dateId), altFormat: "yy-mm-dd"};

			// Directly mapped options
			Lstd.Utils.mapArg2Option(args, options, ["dateFormat", "firstDay", "autoSize", "firstDay", "showAnim", "duration",
				"changeMonth", "changeYear", "yearRange", "showOtherMonths", "selectOtherMonths", "minDate", "maxDate", "showMonthAfterYear",
				"disabled"]);

			if (args.showOn && ((args.showOn == "button") || (args.showOn == "both")))
			{
				options.showOn = args.showOn;
				options.buttonImageOnly = true;
				options.buttonImage = g_lweb_images_path + (args.buttonImage ? "/" + args.buttonImage : "/icons/normal/16/calendar_16.png");
				if (args.buttonText) options.buttonText = args.buttonText;
			}
			else
			{
				options.showOn = "focus";
			}
			if (args.shortYearCutoff)
			{
				if (args.shortYearCutoff.charAt(0) == '+') options.shortYearCutoff = args.shortYearCutoff;
				else options.shortYearCutoff = parseInt(args.shortYearCutoff, 10);
			}

			proxy.datepicker(options);

			proxy.change(function(event) {
				try
				{
					var proxy = jQuery(this);
					var val = proxy.val();
					if (val.length == 0)
					{
						if (!allowSQLNull)
						{
							Lstd.Weblets.dialog.alert({text: g_StdLocaleMgr.getMessageText("BlankDate2"),
								onClose: function() {
									setTimeout(function() { this.focus(); proxy.select(); }, 1); // Handles blur()
								}
							});
							return false;
						}
						else
						{
							document.getElementById(args.dateId).value = "";
						}
					}
					else
					{
						jQuery.datepicker.parseDate(wdateFormat, val);
					}
					proxy.attr("_initVal", val);
					return true;
				}
				catch (e)
				{
					console.error(e);
					Lstd.Weblets.dialog.alert({text: proxy.val() + g_StdLocaleMgr.getMessageText("BadDate1"),
						onClose: function() {
							setTimeout(function() { this.focus(); proxy.select(); }, 1); // Handles blur()
						}
					});
					return false;
				}
			});

			if (typeof args.onchangeScript == "function") proxy.change(args.onchangeScript);
		});
	},

	/**
	 * jQuery UI datepicker (output mode) weblet
	 * Options
	 * dateId: span holding date value
	 * dateFormat: Date format
	 */
	output: function(args)
	{
		var sdp = this;
		sdp.globalInit();

		jQuery(function() {
			var dateSpan = jQuery(Lstd.Utils.makeSafeId(args.dateId));
			dateSpan.prepend(sdp.proxyFormat(
				args.dateFormat ? args.dateFormat : jQuery.datepicker.regional[sdp.lang].dateFormat,
				dateSpan.attr("__isovalue")));
		});
	}
};

/**
 * Timepicker widget
 */

Lstd.Weblets.stdTimePicker = {
	/**
	 * Global initialization flag. Set to true when once-off static initialization is completed.
	 */
	globalInitFlag: false,

	/**
	 * Default regional settings;
	 */
	lang: "",

	/**
	 * Sets global defaults for all timepicker instances
	 */
	globalInit: function() {
		if (this.globalInitFlag) return;
		this.globalInitFlag = true;

		if (window.g_lxmlISOLang != "")
		{
			this.lang = Lstd.Weblets.Utils.getI18nScript("/timepicker/" + jQuery.ui.timepicker.version + "/i18n/jquery-ui-timepicker-");
		}
	},

	/**
	 * jQuery UI timepicker formatter
	 * args:
	 * timeFormat
	 */
	Format: function(timeFormat, allowSQLNull) {
		var tf = this;
		tf.timeFormat = timeFormat;
		tf.ampm = timeFormat.match(/tt/ig) == null ? false : true;
		tf.hPos = 0;
		tf.mPos = 0;
		tf.sPos = 0;
		tf.tPos = 0;
		tf.allowSQLNull = allowSQLNull;

		var nCurPos = 0;

		var regstr = timeFormat.replace(/(\s\+|HH|hh|H|h|mm|m|ss|s|tt|t)/ig, function($1) {
			switch ($1)
			{
				case "\\s+":	return "\\s+";
				case "hh":	tf.hPos = ++nCurPos; return "(\\d?\\d)";
				case "HH":	tf.hPos = ++nCurPos; return "(\\d?\\d)";
				case "h":	tf.hPos = ++nCurPos; return "(\\d?\\d)";
				case "H":	tf.hPos = ++nCurPos; return "(\\d?\\d)";
				case "mm":	tf.mPos = ++nCurPos; return "(\\d?\\d)";
				case "m":	tf.mPos = ++nCurPos; return "(\\d?\\d)";
				case "ss":	tf.sPos = ++nCurPos; return "(\\d?\\d)";
				case "s":	tf.sPos = ++nCurPos; return "(\\d?\\d)";
				case "tt":	tf.tPos = ++nCurPos; return "(am|pm)";
				case "TT":	tf.tPos = ++nCurPos; return "(AM|PM)";
			}
		});

		regstr += "$";
		tf.regex = new RegExp(regstr, "i");

		this.parseISO = function(timeStr) {
			var errorMsg = timeStr != "" ? (timeStr + g_StdLocaleMgr.getMessageText("BadTime1")) : g_StdLocaleMgr.getMessageText("BlankTime2");

			if (timeStr != null)
			{
				if ((timeStr == "") && this.allowSQLNull) return null;

				var d = timeStr.match(/(\d\d):(\d\d):(\d\d)/i);
				if (d)
				{
					var nHrs = Number(d[1]).valueOf();
					var nMin = Number(d[2]).valueOf();
					var nSec = Number(d[3]).valueOf();

					if ((nHrs < 0 ) || (nHrs > 23)) throw errorMsg;
					if ((nMin < 0 ) || (nMin > 59)) throw errorMsg;
					if ((nSec < 0 ) || (nSec > 59)) throw errorMsg;

					var time = new Date();
					time.setHours(nHrs, nMin, nSec);
					return time;
				}
				throw errorMsg;
			}
			throw errorMsg;
		};

		this.parse = function(timeStr) {
			var errorMsg = timeStr != "" ? (timeStr + g_StdLocaleMgr.getMessageText("BadTime1")) : g_StdLocaleMgr.getMessageText("BlankTime2");

			if (timeStr != null)
			{
				if ((timeStr == "") && this.allowSQLNull) return null;

				var d = timeStr.match(this.regex);
				if (d)
				{
					var nHrs = tf.hPos ? (d[tf.hPos] ? Number(d[tf.hPos]).valueOf() : -1) : 0;
					var nMin = tf.mPos ? (d[tf.mPos] ? Number(d[tf.mPos]).valueOf() : -1) : 0;
					var nSec = tf.sPos ? (d[tf.sPos] ? Number(d[tf.sPos]).valueOf() : -1) : 0;
					var ampm = tf.tPos ? d[tf.tPos] : "";

					if (ampm != "")
					{
						if ((nHrs < 1 ) || (nHrs > 12)) throw errorMsg;
						if ((ampm == "pm") || (ampm == "PM"))
						{
							if (nHrs != 12) nHrs += 12;
						}
						else if (nHrs == 12)
						{
							nHrs = 0;
						}
					}
					else
					{
						if ((nHrs < 0 ) || (nHrs > 23)) throw errorMsg;
					}
					if ((nMin < 0 ) || (nMin > 59)) throw errorMsg;
					if ((nSec < 0 ) || (nSec > 59)) throw errorMsg;

					var time = new Date();
					time.setHours(nHrs, nMin, nSec);
					return time;
				}
				throw errorMsg;
			}
			throw errorMsg;
		};

		this.formatISO = function(timeVal) {
			var h1 = timeVal.getHours();
			var m = timeVal.getMinutes();
			var s = timeVal.getSeconds();
			return h1.zeropad(2) + ":" + m.zeropad(2) + ":" + s.zeropad(2);
		};

		this.format = function(timeVal) {
			if (timeVal != null)
			{
				var h1 = timeVal.getHours();
				var h2 = tf.ampm ? h1 > 12 ? (h1 - 12) : (h1 == 0 ? 12 : h1) : 0;
				var m = timeVal.getMinutes();
				var s = timeVal.getSeconds();

				return this.timeFormat.replace(/(HH|hh|H|h|mm|m|ss|s|TT|T|tt|t)/g,
					function($1) {
						switch ($1)
						{
							case "hh":	return (tf.ampm ? (h2 ? h2 : h1) : h1).zeropad(2);
							case "HH":	return (tf.ampm ? (h2 ? h2 : h1) : h1).zeropad(2);
							case "h":	return tf.ampm ? (h2 ? h2 : h1) : h1;
							case "H":	return tf.ampm ? (h2 ? h2 : h1) : h1;
							case "mm":	return m.zeropad(2);
							case "m":	return m;
							case "ss":	return s.zeropad(2);
							case "s":	return s;
							case "TT":	return h1 > 11 ? "PM" : "AM";
							case "T":	return h1 > 11 ? "P" : "A";
							case "tt":	return h1 > 11 ? "pm" : "am";
							case "t":	return h1 > 11 ? "p" : "a";
						}
					});
			}
			return "";
		};
	},

	/**
	 * jQuery UI timepicker (input mode) weblet
	 * Options
	 * timeId: id of hidden field storing time in standard format
	 * timeFormat: Time format
	 */
	input: function(args)
	{
		var stp = this;
		stp.globalInit();

		jQuery(function() {
			/* Arguments: timeId, timeFormat, hourMin, hourMax, minuteMin, minuteMax, stepHour, stepMinute, stepSecond,
				showOn, buttonImage, buttonText, disabled, allowSQLNull, autoSize, showAnim, duration, onchangeScript */

			var proxy = jQuery(Lstd.Utils.makeSafeId("__" + args.timeId + "_PROXY"));
			var allowSQLNull = args.allowSQLNull ? args.allowSQLNull : false;
			var wtimeFormat = args.timeFormat ? args.timeFormat : jQuery.timepicker.regional[stp.lang].timeFormat;
			var tf = new stp.Format(wtimeFormat, allowSQLNull);

			try
			{
				var val = tf.format(tf.parseISO(document.getElementById(args.timeId).value));
				proxy.val(val);
				proxy.attr("_initVal", val);
			}
			catch (e)
			{
				proxy.attr("_initVal", "");
				console.error(e);
			}

			var options = {timeFormat: wtimeFormat, ampm: tf.ampm};

			// Directly mapped options
			Lstd.Utils.mapArg2Option(args, options, ["autoSize", "showAnim", "duration", "hourMin", "hourMax", "minuteMin",
				"minuteMax", "stepHour", "stepMinute", "stepSecond", "disabled"]);

			if (wtimeFormat.match(/ss/g) != null)
			{
				options.showSecond = true;
			}

			if (args.showOn && ((args.showOn == "button") || (args.showOn == "both")))
			{
				options.showOn = args.showOn;
				options.buttonImageOnly = true;
				options.buttonImage = g_lweb_images_path + (args.buttonImage ? "/" + args.buttonImage : "/icons/normal/16/calendar_16.png");
				if (args.buttonText) options.buttonText = args.buttonText;
			}
			else
			{
				options.showOn = "focus";
			}

			// Datetimepicker slider doesn't trigger change()
			options.onClose = function(dateText, inst) {
				if (proxy.val() != proxy.attr("_initVal")) proxy.change();
			};

			proxy.timepicker(options);

			proxy.change(function(event) {
				// Must be asynch: change() is triggered by Datepicker. Datetimepicker hasn't yet updated time portion.
				setTimeout(function(event) {
					try
					{
						var val = proxy.val();

						if (val.length == 0)
						{
							if (!allowSQLNull)
							{
								Lstd.Weblets.dialog.alert({text: g_StdLocaleMgr.getMessageText("BlankTime2"),
									onClose: function() {
										setTimeout(function() { this.focus(); proxy.select(); }, 1); // Handles blur()
									}
								});
								return false;
							}
							else
							{
								document.getElementById(args.timeId).value = "";
							}
						}
						else
						{
							document.getElementById(args.timeId).value = tf.formatISO(tf.parse(val));
						}
						return true;
					}
					catch (e)
					{
						console.error(e);
						Lstd.Weblets.dialog.alert({text: val + g_StdLocaleMgr.getMessageText("BadTime1"),
							onClose: function() {
								setTimeout(function() { this.focus(); proxy.select(); }, 1); // Handles blur()
							}
						});
						return false;
					}
				}, 1);
			});

			if (typeof args.onchangeScript == "function") proxy.change(args.onchangeScript);
		});
	},

	/**
	 * jQuery UI timepicker (output mode) weblet
	 * Options
	 * timeId: id of time field
	 * timeFormat: Time format
	 */
	output: function(args) {
		var stp = this;
		stp.globalInit();

		jQuery(function() {
			var timeSpan = jQuery(Lstd.Utils.makeSafeId(args.timeId));
			var tf = new stp.Format(args.timeFormat ? args.timeFormat : jQuery.timepicker.regional[stp.lang].timeFormat, true);
			try
			{
				timeSpan.prepend(tf.format(tf.parseISO(timeSpan.attr("__isovalue"))));
			}
			catch (e)
			{
				console.error(e);
			}
		});
	}
};

// Datetimepicker widget
Lstd.Weblets.stdDatetimePicker = {
	/**
	 * Global initialization flag. Set to true when once-off static initialization is completed.
	 */
	globalInitFlag: false,

	/**
	 * Sets global defaults for all datepicker instances
	 */
	globalInit: function() {
		if (this.globalInitFlag) return;
		this.globalInitFlag = true;
		Lstd.Weblets.stdDatePicker.globalInit();
		Lstd.Weblets.stdTimePicker.globalInit();
	},

	/**
	 * Format
	 * Formats the datetimepicker
	 */
	Format: function(dateFormat, timeFormat, displayInUTC, allowSQLNull) {
		var dtf = this;
		dtf.dateFormat = dateFormat;
		dtf.displayInUTC = displayInUTC;
		dtf.allowSQLNull = allowSQLNull;
		dtf.time = new Lstd.Weblets.stdTimePicker.Format(timeFormat, allowSQLNull);

		this.parse = function(datetimeStr) {
			// Let datepicker validate the date portion.
			var index = datetimeStr.search(dtf.time.regex);
			var dateStr = index != -1 ? datetimeStr.substr(0, index) : datetimeStr;
			var dtVal = jQuery.datepicker.parseDate(dateFormat, dateStr);

			// Parse time portion
			var timeStr = datetimeStr.substring(index, datetimeStr.length);
			var tVal = dtf.time.parse(timeStr);
			dtVal.setHours(tVal.getHours(), tVal.getMinutes(), tVal.getSeconds());
			return dtVal;
		};

		this.format = function(isoDatetime) {
			if (isoDatetime != "")
			{
				var dateVal = new Date();
				dateVal.setISO8601(isoDatetime);
				if (dtf.displayInUTC)
				{
					// Offset so "local time" shows the UTC value
					dateVal.setTime(dateVal.getTime() + (dateVal.getTimezoneOffset() * 60000));
				}
				return jQuery.datepicker.formatDate(dtf.dateFormat, dateVal) + " " + dtf.time.format(dateVal);
			}
			else
			{
				if (!this.allowSQLNull) throw g_StdLocaleMgr.getMessageText("BlankDate2");
			}
		};
	},

	/**
	 * jQuery UI datetimepicker (input mode) weblet
	 * Options
	 * dateId: id of hidden field storing date in standard format
	 * dateFormat: Date format
	 * timeFormat, firstDay, changeMonth, changeYear, showOtherMonths,
	 * minDate, maxDate, shortYearCutoff, hourMin, hourMax, minuteMin, minuteMax, stepHour, stepMinute, stepSecond, showOn,
	 * buttonImage, buttonText, disabled, displayInUTC, allowSQLNull, autoSize, showAnim, duration, onchangeScript
	 */
	input: function(args) {
		var sdtp = this;
		sdtp.globalInit();

		jQuery(function() {
			var proxy = jQuery(Lstd.Utils.makeSafeId("__" + args.dateId + "_PROXY"));
			var displayInUTC = args.displayInUTC ? args.displayInUTC : false;
			var allowSQLNull = args.allowSQLNull ? args.allowSQLNull : false;
			var wdateFormat = args.dateFormat ? args.dateFormat : jQuery.datepicker.regional[Lstd.Weblets.stdDatePicker.lang].dateFormat;
			var wtimeFormat = args.timeFormat ? args.timeFormat : jQuery.timepicker.regional[Lstd.Weblets.stdTimePicker.lang].timeFormat;
			var dtf = new sdtp.Format(wdateFormat, wtimeFormat, displayInUTC, allowSQLNull);

			try
			{
				var val = dtf.format(document.getElementById(args.dateId).value);
				proxy.val(val);
				proxy.attr("_initVal", val);
			}
			catch (e)
			{
				proxy.attr("_initVal", "");
				console.error(e);
			}

			var options = {dateFormat: wdateFormat,
				timeFormat: wtimeFormat,
				ampm: dtf.time.ampm
			};

			// Directly mapped options
			Lstd.Utils.mapArg2Option(args, options, ["autoSize", "firstDay", "showAnim", "duration", "changeMonth", "changeYear",
				"yearRange", "showOtherMonths", "selectOtherMonths", "minDate", "maxDate", "hourMin", "hourMax", "minuteMin",
				"minuteMax", "stepHour", "stepMinute", "stepSecond", "showMonthAfterYear", "disabled"]);

			if (wtimeFormat.match(/ss/g) != null)
			{
				options.showSecond = true;
			}

			if (args.showOn && ((args.showOn == "button") || (args.showOn == "both")))
			{
				options.showOn = args.showOn;
				options.buttonImageOnly = true;
				options.buttonImage = g_lweb_images_path + (args.buttonImage ? "/" + args.buttonImage : "/icons/normal/16/calendar_16.png");
				if (args.buttonText) options.buttonText = args.buttonText;
			}
			else
			{
				options.showOn = "focus";
			}
			if (args.shortYearCutoff)
			{
				if (args.shortYearCutoff.charAt(0) == '+') options.shortYearCutoff = args.shortYearCutoff;
				else options.shortYearCutoff = parseInt(args.shortYearCutoff, 10);
			}

			// Datetimepicker slider doesn't trigger change()
			options.onClose = function(dateText, inst) {
				if (proxy.val() != proxy.attr("_initVal")) proxy.change();
			};

			proxy.datetimepicker(options);

			proxy.change(function(event) {
				// Must be asynch: change() is triggered by Datepicker. Datetimepicker hasn't yet updated time portion.
				setTimeout(function(event) {
					try
					{
						var val = proxy.val();

						if (val.length == 0)
						{
							if (!allowSQLNull)
							{
								Lstd.Weblets.dialog.alert({text: g_StdLocaleMgr.getMessageText("BlankDate2"),
									onClose: function() {
										setTimeout(function() { this.focus(); proxy.select(); }, 1); // Handles blur()
									}
								});
								return false;
							}
							else
							{
								document.getElementById(args.dateId).value = "";
							}
						}
						else
						{
							var dtVal = dtf.parse(val);
							if (displayInUTC)
							{
								// Offset so UTC value matches display time
								dtVal.setTime(dtVal.getTime() - (dtVal.getTimezoneOffset() * 60000));
							}
							document.getElementById(args.dateId).value = dtVal.toISO8601String(true, false);
						}
						return true;
					}
					catch (e)
					{
						console.error(e);
						Lstd.Weblets.dialog.alert({text: g_StdLocaleMgr.getMessageText("BadDateTime"),
							onClose: function() {
								setTimeout(function() { this.focus(); proxy.select(); }, 1); // Handles blur()
							}
						});
						return false;
					}
				}, 1);
			});

			if (typeof args.onchangeScript == "function") proxy.change(args.onchangeScript);
		});
	},

	/**
	 * jQuery UI datetimepicker (output mode) weblet
	 * Options
	 * dateId, dateFormat, displayInUTC
	 */
	output: function(args) {
		var sdtp = this;
		sdtp.globalInit();

		jQuery(function() {
			var dateSpan = jQuery(Lstd.Utils.makeSafeId(args.dateId));
			var wdateFormat = args.dateFormat ? args.dateFormat : jQuery.datepicker.regional[Lstd.Weblets.stdDatePicker.lang].dateFormat;
			var wtimeFormat = args.timeFormat ? args.timeFormat : jQuery.timepicker.regional[Lstd.Weblets.stdTimePicker.lang].timeFormat;
			var dtf = new sdtp.Format(wdateFormat, wtimeFormat, args.displayInUTC ? args.displayInUTC : false, true);
			try
			{
				dateSpan.prepend(dtf.format(dateSpan.attr("__isovalue")));
			}
			catch (e)
			{
				console.error(e);
			}	
		});
	}
};

// Autocomplete widget
Lstd.Weblets.stdAutocomplete = {

	/**
	 * jQuery UI autocomplete (input mode)
	 * Options
	 * inputId: Input field id
	 * keybdShift: Keyboard shift
	 * disabled:
	 * delay, minLength, sourceWamName, sourceWrName, termField,
	 * labelField, valueField, extraFields, cache, matchContains, scroll, scrollHeight, onchangeScript
	 */
	 
	init: function(args) {
		var input = jQuery(Lstd.Utils.makeSafeId(args.inputId));

		jQuery(function() {
			var options = {};
			var keybdShift = args.keybdShift ? args.keybdShift : ' ';

			// Directly mapped options
			Lstd.Utils.mapArg2Option(args, options, ["disabled", "delay", "minLength"]);

			// Header map: Stores column indices (by column name)
			var PosArr = null;

			/**
			 * Adapter to convert Webroutine JSON response into format expected by the jQuery UI autocomplete widget
			 */
			function formatResponse(labelField, valueField, data)
			{
				result = [];
				if (data.webroutine && data.webroutine.lists)
				{
					// Only one list should be returned
					var list = args.listName ? data.webroutine.lists[args.listName] : Lstd.Utils.getPropertyValueAtIndex(data.webroutine.lists, 0);
					if (PosArr == null) PosArr = Lstd.Utils.getListHeaderMap(list.header);
					var entries = list.entries;

					if (labelField && valueField)
					{
						var labelPos = PosArr[labelField];
						var valuePos = PosArr[valueField];
						for (var i = 0, entry; entry = entries[i]; i++) result.push({"label": entry[labelPos], "value": entry[valuePos]});
					}
					else if (labelField)
					{
						var labelPos = PosArr[labelField];
						for (var i = 0, entry; entry = entries[i]; i++) result.push(entry[labelPos]);
					}
					else if (valueField)
					{
						var valuePos = PosArr[valueField];
						for (var i = 0, entry; entry = entries[i]; i++) result.push(entry[valuePos]);
					}
					else
					{
						for (var i = 0, entry; entry = entries[i]; i++) result.push(entry[0]);
					}
				}
				else
				{
					console.error("Invalid webroutine response");
				}
				return result;
			}

			var subCacheId = Lstd.Weblets.stdAutocomplete.getSubCacheId(args.inputId);
			if (!Lstd.Weblets.stdAutocomplete.cache[subCacheId]) Lstd.Weblets.stdAutocomplete.cache[subCacheId] = {};
			var cache = Lstd.Weblets.stdAutocomplete.cache[subCacheId];

			var lastXhr = null;
			var useGET = (g_lmxlSKMethod != "hidden") || (g_lxmlSK == "");
			var termField = args.termField ? args.termField : args.inputId;
			var lansaweb = stdFormatHttpRequest(null, args.sourceWamName, args.sourceWrName, null, null, true) + "&f(" + termField + ")=";
			var fieldNames = args.extraFields ? args.extraFields.split(',') : [];
			var form = null;

			var xhrFunc = useGET ?
				function(request, response, func) {
					var fieldsQS = Lstd.Utils.formatFieldsQueryString(fieldNames);
					return jQuery.ajax({
						url: lansaweb + request.term + fieldsQS,
						cache: false,
						dataType: "json",
						success: func,
						error: function(xhr, s, e) {
							console.error("JSON response: " + s);
						}
					});
				} :
				function(request, response, func) {
					if (form == null)
					{
						var f = createStdHiddenForm(args.sourceWamName, args.sourceWrName, "autocomplete_" + args.inputId);
						Lstd.Utils.addHiddenFields(f, fieldNames);
						form = jQuery(f);
					}
					return jQuery.ajax({
						url: lansaweb + request.term,
						cache: false,
						type: "POST",
						dataType: "json",
						data: form.serialize(),
						success: func,
						error: function(xhr, s, e) {
							console.error("JSON response: " + s);
						}
					});
				};

			if (args.cache)
			{
				var matchContains = args.matchContains ? args.matchContains : false;

				options.source = function(request, response) {
					var requestTermUP = request.term.toUpperCase();
					for (term in cache)
					{
						if (requestTermUP.search("^" + Lstd.Utils.escapeRegex(term)) != -1)
						{
							if (term == requestTermUP)
							{
								response(cache[term]);
							}
							else
							{
								/**
								 * Local cache filter. Returns a subset of a suggest list
								 */
								function cacheFilter(data) {
									var regexp = new RegExp((matchContains ? "" : "^") + Lstd.Utils.escapeRegex(request.term), "i");
									var subset = [];
									var sample = data[0];

									if (typeof sample == "string")
									{
										for (var i = 0, item; item = data[i]; i++) if (regexp.test(item)) subset.push(item);
									}
									else if (sample.label && sample.value)
									{
										for (var i = 0, item; item = data[i]; i++) if (regexp.test(item.label)) subset.push(item);
									}
									else if (sample.label)
									{
										for (var i = 0, item; item = data[i]; i++) if (regexp.test(item.label)) subset.push(item);
									}
									else if (sample.value)
									{
										for (var i = 0, item; item = data[i]; i++) if (regexp.test(item.value)) subset.push(item);
									}
									return subset;
								}
								response(cacheFilter(cache[term]));
							}
							return;
						}
					}

					lastXhr = xhrFunc(request, response, function(data, status, xhr) {
							// Case insentive cache: Use uppercase term index
							var termUP = request.term.toUpperCase();
							cache[termUP] = formatResponse(args.labelField, args.valueField, data);
							if (xhr === lastXhr)
							{
								response(cache[termUP]);
							}
						});
				};
			}
			else
			{
				options.source = function(request, response) {
					xhrFunc(request, response, function(data) {
							response(formatResponse(args.labelField, args.valueField, data));
						});
				};
			}

			if (typeof args.onchangeScript == "function") options.change = args.onchangeScript;
			if (typeof args.onselectScript == "function") options.select = args.onselectScript;

			input.autocomplete(options);
			if (args.scroll) jQuery(input.autocomplete("widget")).css({"max-height": args.scrollHeight ? args.scrollHeight : "180px", "overflow-y": "auto"});

			input.change(function(event) {
				if (!isValidText(this, keybdShift))
				{
					event.stopImmediatePropagation();
					setTimeout(function(){ this.focus(); input.select(); }, 1); // Handles blur()
					return false;
				}
				return true;
			});
			
			input.blur(function(event) {
				if (form != null)
				{
					try
					{
						form.remove();
						form = null;
					}
					catch (e)
					{
						console.error(e);
					}
				}
			});
		});
	},

	/**
	 * Cache
	 * Stores the terms as they get returned from the server. There is a cache for each field.
	 * For lists, a cache is created for with and id of LISTNAME.COLUMNNAME
	 */
	cache: {},

	/*
	 * Gets the subCache Id. The subCache Id is the same as the id for fields. For list columns
	 * the subCache Id is the LISTNAME.COLUMNNAME.
	 * @param [string] Field/column Id
	 * @return subCache Id
	 */
	getSubCacheId: function(id) {
		// Test is not strict. Just looking for List row column pattern
		var reg = id.match(/(^[A-Za-z].*)\.(\d{4})\.([A-Za-z].*)/);
		return reg ? (reg[1] + "." + reg[3]) : id;
	}
};

// Internal utilities

/**
 * Shows the option names and values
 */
Lstd.Utils.showOptions = function(options) {
	var s = "Options:\n";
	for (opt in options)
	{
		s += opt + ": " + options[opt] + "\n";
	}
	console.log(s);
};

/**
 * Build a map of list header column index positions
 * @param (array) JSON response list headers
 * @returns (array) Array of index positions by column name
 */
Lstd.Utils.getListHeaderMap = function(headers) {
	var arr = [];
	for (var i = 0, header; header = headers[i]; i++) arr[header.name] = i;
	return arr;
};

(function($) {

$.widget("ui.menubar", {
	options: 
	{
		orientation: "top"
	},
	_create: function() {
		var self = this, options = self.options;
		this.element
			.addClass("ui-menubar ui-widget")
			.addClass("ui-menubar-orient-" + (options.orientation?options.orientation:"top"))
			.attr({
				role: "menubar",
				"aria-activedescendant": "ui-active-menu"
			})
			.bind("click.menubar", function( event ) {
				var $t = $(event.target);
				if (options.disabled) {
					return false;
				}
				if ( !$t.closest( ".ui-menubar-item a" ).length ) {
					return;
				}
				var item = $t.closest(".ui-menubar-item"), hasSubmenu = Boolean(item.children("ul").length);
				if (self.active && (self.active.get(0) == item.get(0)) && hasSubmenu) 
				{
					self.deactivate();
				}
				else 
				{
					self.activate(event, item);
					if (!hasSubmenu) self._trigger("select", event, { menu: self.active, item: item });
				}
				if ($t.attr("href") == "#") event.preventDefault();
			});
		this.refresh();

		this.element.bind("keydown.menubar", function(event) {
			if (options.disabled) {
				return;
			}
			switch (event.keyCode) {
				case $.ui.keyCode.LEFT:
					if (options.orientation == "top" || options.orientation == "bottom") {
						self.previous();
						event.preventDefault();
						event.stopImmediatePropagation();
					}
					else if (options.orientation == "right") {
						self.down();
						event.preventDefault();
						event.stopImmediatePropagation();
					}
					break;
				case $.ui.keyCode.RIGHT:
					if (options.orientation == "top" || options.orientation == "bottom") {
						self.next();
						event.preventDefault();
						event.stopImmediatePropagation();
					}
					else if (options.orientation == "left") {
						self.down();
						event.preventDefault();
						event.stopImmediatePropagation();
					}
					break;
				case $.ui.keyCode.UP:
					if (options.orientation == "left" || options.orientation == "right") {
						self.previous();
						event.preventDefault();
						event.stopImmediatePropagation();
					}
					else if (options.orientation == "bottom") {
						self.down();
						event.preventDefault();
						event.stopImmediatePropagation();
					}
					break;
				case $.ui.keyCode.DOWN:
					if (options.orientation == "left" || options.orientation == "right") {
						self.next();
						event.preventDefault();
						event.stopImmediatePropagation();
					}
					else if (options.orientation == "top") {
						self.down();
						event.preventDefault();
						event.stopImmediatePropagation();
					}
					break;
				case $.ui.keyCode.ENTER:
					var item = $(self.active).closest(".ui-menubar-item"), hasSubmenu = Boolean(item.children("ul").length);
					if (!hasSubmenu) self._trigger("select", event, { menu: self.active, item: item });
					event.preventDefault();
					event.stopImmediatePropagation();
					break;
			}
		});
	},

	destroy: function() {
		$.Widget.prototype.destroy.apply(this, arguments);

		this.element
			.removeClass("ui-menubar ui-widget ui-widget-content ui-helper-clearfix ui-menubar-orient-top ui-menubar-orient-bottom ui-menubar-orient-left ui-menubar-orient-right")
			.removeAttr("tabIndex")
			.removeAttr("role")
			.removeAttr("aria-activedescendant");

		this.element.children(".ui-menubar-item")
			.removeClass("ui-menubar-item")
			.removeAttr("role")
			.children("a")
			.removeClass("ui-corner-top ui-corner-bottom ui-corner-left ui-corner-right ui-state-default ui-state-hover")
			.removeAttr("tabIndex")
			.unbind(".menubar")
			.children(".ui-icon").remove();
	},

	refresh: function() {
		var self = this, options=self.options;

		// don't refresh list items that are already adapted
		var items = this.element.children("li:not(.ui-menubar-item):has(a)")
			.addClass("ui-menubar-item")
			.attr("role", "menu");

		items.children("a")
			.addClass("ui-state-default ui-corner-all")
			.attr("tabIndex", -1)
			.bind("mouseenter.menubar", function( event ) {
				if (options.disabled) {
					return;
				}
				$( this ).addClass( "ui-state-hover" );
				if ( self.active ) 
				{
					self.activate(event, $( this ).parent());
				}
			})
			.bind("mouseleave.menubar", function() {
				if (options.disabled) {
					return;
				}
				$( this ).removeClass( "ui-state-hover" );
			});
			if (options.showArrows) 
			{
				var icon;
				switch (options.orientation) 
				{
					case "left":
					icon = "ui-icon-triangle-1-e";
					break;
					case "right":
					icon = "ui-icon-triangle-1-w";
					break;
					case "bottom":
					icon = "ui-icon-triangle-1-n";
					break;
					default:
					icon = "ui-icon-triangle-1-s";
				}
				items.addClass("ui-menubar-item-icon");
				items.children("a").append('<span class="ui-menubar-icon ui-icon ' + icon + '"></span>');
			}

		items.children("ul").filter(".ui-nestedmenu").nestedmenu("refresh")
		.end().not(".ui-nestedmenu").each(function() {
			$(this).nestedmenu({
				select: function(event, ui) {
					self._trigger("select", event, {
						menu: self.active,
						item: ui.item
					});
					self.deactivate();
				},
				direction: (options.orientation == "right" ? "left " : "right ") + (options.orientation == "bottom" ? "up" : "down"),
				input: $(this).parent()
			}).hide();
		});
	},

	activate: function( event, item ) {
		var self = this;
		this.deactivate();
		this.active = item.eq(0)
			.children("a")
				.addClass("ui-state-active")
				.attr("id", "ui-active-menu").focus()
			.end();
		this._trigger("focus", event, { item: item });
		var position = {of: this.active.get(0)};
		switch (self.options.orientation) 
		{
			case "bottom":
				position.my = "left bottom";
				position.at = "left top";
				break;
			case "left":
				position.my = "left top";
				position.at = "right top";
				break;
			case "right":
				position.my = "right top";
				position.at = "left top";
				break;
			default:
				position.my = "left top";
				position.at = "left bottom";
		}
		this.active.children("ul").nestedmenu("show").css({top:0, left:0}).position(position);
		$(document).bind("click", function(event) {
			var item = $(event.target).closest(".ui-menubar-item");
			if (self.active && (self.active.get(0) != item.get(0))) 
			{
				self.deactivate();
			}
			if (!self.active) $(this).unbind(event);
		});
	},

	deactivate: function() {
		if (!this.active) { return; }

		this.active.children("a")
			.removeClass("ui-state-active")
			.removeAttr("id");
		this.active.children("ul").nestedmenu("hide");
		this._trigger("blur");
		this.active = null;
	},

	next: function(event) {
		this._move("next", ".ui-menubar-item:first", event);
	},

	previous: function(event) {
		this._move("prev", ".ui-menubar-item:last", event);
	},

	first: function() {
		return this.active && !this.active.prevAll(".ui-menubar-item").length;
	},

	last: function() {
		return this.active && !this.active.nextAll(".ui-menubar-item").length;
	},
	down: function() 
	{
		if (this.active) this.active.find(">ul").menu("activate", event, this.active.find(">ul>li:first"));
	},
	_move: function(direction, edge, event) {
		if (!this.active) {
			return;
		}
		var next = this.active[direction + "All"](".ui-menubar-item").eq(0);
		if (next.length) {
			this.activate(event, next);
		} else {
			this.activate(event, this.element.children(edge));
		}
	},

	select: function( event, ui ) {
		this._trigger("select", event, { menu: this.active, item: ui.active });
	}
	
	
});

})(jQuery);


(function($) {

$.widget("ui.nestedmenu", {
	options: 
	{
		direction: "right down"
	},
	_create: function() {
		var self = this, options = self.options;

		this.active = this.element;

		if (!options.input) {
			options.input = this.element.attr("tabIndex", 0);
		}

		this._rightDir = /right/.test(options.direction);

		this.element.addClass("ui-nestedmenu ui-nestedmenu-direction-" + (this._rightDir?"right":"left"));

		this.refresh();

		options.input.bind("keydown.nestedmenu", function(event) {
			if (options.disabled || !self.active) {
				return;
			}

			var eventHandled = false;
			switch (event.keyCode) 
			{
				case $.ui.keyCode.RIGHT:
					eventHandled = self._rightDir ? self.down(event) : self.up(event);
					break;
				case $.ui.keyCode.LEFT:
					eventHandled = self._rightDir ? self.up(event) : self.down(event);
					break;
				case $.ui.keyCode.PAGE_UP:
					self.active.menu("previousPage", event);
					eventHandled = true;
					break;
				case $.ui.keyCode.PAGE_DOWN:
					self.active.menu("nextPage", event);
					eventHandled = true;
					break;
				case $.ui.keyCode.UP:
					self.active.menu("previous", event);
					eventHandled = true;
					break;
				case $.ui.keyCode.DOWN:
					self.active.menu("next", event);
					eventHandled = true;
					break;
				case $.ui.keyCode.ENTER:
					self.active.menu("select", event);
					eventHandled = true;
					break;
			}
			if (eventHandled) {
				event.preventDefault();
				event.stopImmediatePropagation();
			}
		});
	},

	destroy: function() {
		$.Widget.prototype.destroy.apply(this, arguments);
		
		this.element.removeClass("ui-nestedmenu ui-nestedmenu-direction-right ui-nestedmenu-direction-left");
		var menus = this.element.find("ul");
		menus.prev("a").children(".ui-icon").remove();
		menus.andSelf().menu("destroy");
	},

	refresh: function() {
		var self = this, options = self.options, 
		subMenus = this.element.find("ul"), 
		newSubs = subMenus.not(".ui-menu");

		subMenus.andSelf().filter(".ui-menu").menu("refresh");
		
		// hide submenus and create indicator icons
		newSubs.hide().prev("a").prepend('<span class="ui-icon ui-icon-triangle-1-' + (this._rightDir?"e":"w") + '"></span>');	
		
		newSubs.add(this.element.not(".ui-menu")).menu({
			input: $(),
			select: options.select,
			selected: options.select,
			focus: function(event, ui) {
				self.active = ui.item.parent();
				self.activeItem = ui.item;
				ui.item.parent().find("ul").hide();
				var nested = $(">ul", ui.item);
				if (event.originalEvent && nested.length && /^mouse/.test(event.originalEvent.type)) {
					self._open(nested);
				}
			}
		}).bind("click", function(e) {
			// The ui.menu handles the click but we need to stop it propagating up to parent menus
			e.stopPropagation();
		});
	},

	_open: function(submenu) {
		var downDir = (/down/i).test(this.options.direction);
		var position = {
			of: this.activeItem,
			my: (this._rightDir ? "left " : "right ") + (downDir ? "top" : "bottom"),
			at: (this._rightDir ? "right " : "left ") + (downDir ? "top" : "bottom")
		/*,
		 offset: (this._rightDir?"-3 ":"3 ") + (downDir?"-3":"3")*/
		};
		submenu.show().css({
			top: 0,
			left: 0
		}).position(position);
	},

	up: function(event) {
		var newActive = this.active.menu("collapse").hide().parent().parent();
		var newItem = newActive.data("menu");
		if (newItem) {
			this.active = newActive;
			this.activeItem = newItem;
			return true;
		}
		this.active = null;
		this.activeItem = null;
		return false;
	},

	down: function(event) {
		if (this.activeItem && this.activeItem.length) {
			var submenu = $(">ul", this.activeItem);
			if (submenu.length) {
				this._open(submenu, this.activeItem);
				submenu.menu("activate", event, submenu.children((/down/i).test(this.options.direction) ? ":first" : ":last"));
				return true;
			}
		}
		return false;
	},

	show: function() {
		this.active = this.element;
		if (document.documentMode && (document.documentMode < 8)) {
			if (this.element[0].style.width == "") {
				var imgs = this.element.find(".ui-icon").hide();
				this.element.css("width", (this.element.outerWidth() + imgs.outerWidth() + 4) + "px");
				imgs.show();
				this.element.find(".ui-menu").show().hide();
			}
		}
		this.element.show();
	},

	hide: function() {
		this.element.find("ul").andSelf().menu("collapse").hide();
		this.active = null;
	}
});
})(jQuery);


// And now the LANSA Weblet
Lstd.Weblets.stdMenuBar = 
{
	init: function(id, data)
	{
		if (id == "") {
			console.error("A MenuBar weblet must have an ID");
			return;
		}
		var $elem = jQuery(Lstd.Utils.makeSafeId(id));
		var itemsArray = data.itemsArray ? data.itemsArray : data.list ? Lstd.Weblets.stdMenuBar.makeItemsArray(data.list) : null;

		if (itemsArray)
		{
			for (var i=0, menuItem; menuItem = itemsArray[i]; i++)
			{
				var li = document.createElement("li");
				li.id = id + "_" + menuItem[0];
				var a = document.createElement("a");
				a.href = menuItem[3] || "#";
				a.setAttribute("data-wam", menuItem[4]);
				a.setAttribute("data-webroutine", menuItem[5]);
				if ((menuItem[6] != null) && (menuItem[6] != "")) a.setAttribute("data-vf-wamevent", menuItem[6]);
				a.appendChild(document.createTextNode( menuItem[2]));
				li.appendChild(a);
				var $ul;
				if (menuItem[1]) 
				{
					var $parentLI = jQuery(Lstd.Utils.makeSafeId(id + "_" + menuItem[1]));
					$ul = $parentLI.children("ul");
					if ($ul.length == 0) 
					{
						$ul = jQuery("<ul/>",{"class":"display:none;"}).appendTo($parentLI);
					}
				} else
				{
					$ul = $elem;
				}
				$ul.append(li);
			}
		}

		var options = {select: function(e, ui)
		{
			var $a = ui.item.children("a").first(), href = $a.attr("href");
			if (href == "#") 
			{
				e.preventDefault();
				var wam = $a.attr("data-wam"), wr = $a.attr("data-webroutine"), vf_wamevent = $a.attr("data-vf-wamevent");
				if (wam && wr) 
				{
					var f = getParentForm($a.get(0));
					if (!f) f = createStdHiddenForm(wam, wr, null, null, null);
					if (f != null) 
					{
						var id = ui.item.attr("id").split("_").slice(1).join(",");
						insertHiddenField(f, data.submitSelectedTo, id);
						Lstd.Fields.check4VF_WAMEVENT(f, $a.get(0));
						submitForm(f, wam, wr, null, null);
					}
				}
			} else {
				// jQuery UI does a preventDefault on the click event so we will have to handle the href
				// The jQuery code that does this has a comment saying "temporary" so it may change in the future
				// and we may need to remove the following.
				document.location = href;
			}
		}};
		data.orientation = data.orientation || "top";
		Lstd.Utils.mapArg2Option(data, options, ["orientation", "showArrows"]);
		$elem.menubar(options);
	},

	makeItemsArray: function(listName)
	{
		var lst = Lstd.Lists[listName],
			lstEntries = lst.entries(),
			colCount = lstEntries.columnCount(),
			itemsArray = [];

		if (colCount < 7) {
			lstEntries.rawEach(function(i, entry) {
				itemsArray.push([entry[0], entry[1], entry[2], entry[3], entry[4], entry[5]]);
			});
		}
		else {
			lstEntries.rawEach(function(i, entry) {
				itemsArray.push([entry[0], entry[1], entry[2], entry[3], entry[4], entry[5], entry[6]]);
			});
		}
		return itemsArray;
	}
};

(function($) 
{
	if ($.ui.version.substring(0, 3) == "1.8") 
	{
		// We need to slightly modify the jQuery UI menu. Mouse enter/leave event handlers
		// need to be attached to the LI rather than the A to avoid leave events when
		// moving to a submenu
		$.ui.menu.prototype.refresh = function()
		{
			var self = this;
			
			// don't refresh list items that are already adapted
			var items = this.element.children("li:not(.ui-menu-item):has(a)").addClass("ui-menu-item")
			.attr("role", "menuitem") // mouseenter doesn't work with event delegation
			.bind("mouseenter.menu", function(event) {
				if (self.options.disabled) 
				{
					return;
				}
				self.activate(event, $(this));
			}).bind("mouseleave.menu", function() {
				if (self.options.disabled) 
				{
					return;
				}
				self.deactivate();
			});
			
			items.children("a").addClass("ui-corner-all").attr("tabIndex", -1);
		}
	}
})(jQuery);

// This is a tree implemented as a jQuery UI Widget.
(function($) {

$.widget("ui.treeview", {
	options: 
	{
		useJQueryUITheme: false
	},
	_create: function() {
		var self = this, options = self.options, usejqui = options.useJQueryUITheme;
		var tree = this.element;

		if (!usejqui) options.jQueryUINodeIcon = "";
		switch (options.jQueryUINodeIcon) {
			case "carat":
				this.jQueryUINodeClosedIcon = "ui-icon-carat-1-e";
				this.jQueryUINodeOpenIcon = "ui-icon-carat-1-s";
				break;
			case "triangle":
				this.jQueryUINodeClosedIcon = "ui-icon-triangle-1-e";
				this.jQueryUINodeOpenIcon = "ui-icon-triangle-1-s";
				break;
			case "folder":
				this.jQueryUINodeClosedIcon = "ui-icon-folder-collapsed";
				this.jQueryUINodeOpenIcon = "ui-icon-folder-open";
				break;
			default:
				this.jQueryUINodeClosedIcon = "";
				this.jQueryUINodeOpenIcon = "";
				break;
		}

		tree.addClass(usejqui ? "tree ui-widget ui-widget-content" : "tree tree-default").attr({role: "application tree"})

		tree.find("a:eq(0)").attr("tabindex","0");
		//set all others to -1
		tree.find("a:gt(0)").attr("tabindex","-1");

		this.refresh();

		//expanded at load
		if (options.expanded) {
			var exp = tree.find(options.expanded).each(function() {
				var $span, $t = $(this), img = $t.data("imageOpen") || options.nodeOpenImage || "";

				$span = $t.attr("aria-expanded", "true")
					.find(">a").removeClass("tree-parent-collapsed")
					.next().removeClass("tree-group-collapsed")
					.end().find("span:eq(0)");
				$span[0].setAttribute("style", (img) ? "background: url(" + img + ") no-repeat 50% 50%;" : "");
				if (usejqui) {
					$span.removeClass(this.jQueryUINodeClosedIcon).addClass(this.jQueryUINodeOpenIcon);
				}
			});
		}

		tree
			//expand a tree node
			.bind("expand",function(event){
				var target = $(event.target) || tree.find("a[tabindex=0]");
				var item = target.closest("li"), span = target.find("span:eq(0)");
				self._trigger("expand", event, { item: item });
				target.removeClass("tree-parent-collapsed");
				target.next().hide().removeClass("tree-group-collapsed").slideDown(150, function(){
					$(this).removeAttr("style");
					target.parent().attr("aria-expanded", "true");
				});
				if (usejqui) span.removeClass(self.jQueryUINodeClosedIcon).addClass(self.jQueryUINodeOpenIcon);
				
				var img = item.data("imageOpen") || options.nodeOpenImage || "";
				span[0].setAttribute("style", (img) ? "background: url(" + img + ") no-repeat 50% 50%;" : "");
			})
			//collapse a tree node
			.bind("collapse",function(event){
				var target = $(event.target) || tree.find("a[tabindex=0]");
				var item = target.closest("li"), span = target.find("span:eq(0)");
				target.addClass("tree-parent-collapsed");
				target.next().slideUp(150, function(){
					target.parent().attr("aria-expanded", "false");
					$(this).addClass("tree-group-collapsed").removeAttr("style");
				});
				if (usejqui) span.removeClass(self.jQueryUINodeOpenIcon).addClass(self.jQueryUINodeClosedIcon);
			
				var img = item.data("image") || options.nodeClosedImage || "";
				span[0].setAttribute("style", (img) ? "background: url(" + img + ") no-repeat 50% 50%;" : "");
			})
			.bind("toggle",function(event){
				var target = $(event.target) || tree.find("a[tabindex=0]");
				//check if target parent LI is collapsed
				if( target.parent().is("[aria-expanded=false]") ){ 
					//call expand function on the target
					target.trigger("expand");
				}
				//otherwise, parent must be expanded
				else{ 
					//collapse the target
					target.trigger("collapse");
				}
			})
			//shift focus down one item		
			.bind("traverseDown",function(event){
				var target = $(event.target) || tree.find("a[tabindex=0]");
				var targetLi = target.parent();
				if(targetLi.is("[aria-expanded=true]")){
					target.next().find("a").eq(0).focus();
				}
				else if(targetLi.next().length) {
					targetLi.next().find("a").eq(0).focus();
				}	
				else {				
					targetLi.parents("li").next().find("a").eq(0).focus();
				}
			})
			//shift focus up one item
			.bind("traverseUp",function(event){
				var target = $(event.target) || tree.find("a[tabindex=0]");
				var targetLi = target.parent();
				if(targetLi.prev().length){ 
					if( targetLi.prev().is("[aria-expanded=true]") ){
						targetLi.prev().find("li:visible:last a").eq(0).focus();
					}
					else{
						targetLi.prev().find("a").eq(0).focus();
					}
				}
				else { 				
					targetLi.parents("li:eq(0)").find("a").eq(0).focus();
				}
			});

		//and now for the native events
		tree	
			.focus(function(event){
				var classes = "tree-item-active" + (usejqui ? " ui-state-highlight" : "");
				//deactivate previously active tree node, if one exists
				tree.find("[tabindex=0]").attr("tabindex","-1").removeClass(classes);
				//assign 0 tabindex to focused item
				$(event.target).attr("tabindex","0").addClass(classes);
			})
			.click(function(event){
				var target = $(event.target), doSelect = doToggle = false, retVal = true;
				//check if target is a tree node
				if( target.closest("a.tree-parent").length ) {
					if (target.is("a.tree-parent")) {
						doSelect = (options.nodeTextOnClick != "toggle");
						doToggle = (options.nodeTextOnClick != "select");
					} else if (target.is(".tree-icon")) {
						target = target.parent();
						doToggle = true;
					}
				} else if (target.is("a")) {
					doSelect = true;
				}
				
				if (doSelect) {
					self._trigger("select", event, { item: target.closest("li") });
					target.eq(0).focus();
				}
				if (doToggle) {
					target.trigger("toggle");
					//return click event false because it's a tree node (folder)
					retVal = false;
				}
				return retVal;
			})
			.keydown(function(event){	
					var target = tree.find("a[tabindex=0]");
					switch (event.keyCode) {
						case $.ui.keyCode.LEFT:
							//if list is expanded
							if (target.parent().is("[aria-expanded=true]")){
								target.trigger("collapse");
							}
							else
							{
								//try traversing to parent
								target.parents("li:eq(1)").find("a").eq(0).focus();
							}
							return false;
							break;
						case $.ui.keyCode.RIGHT:
							//if list is collapsed
							if(target.parent().is("[aria-expanded=false]")){
								target.trigger("expand");
							}
							else 
							{
								//try traversing to child
								target.parents("li:eq(0)").find("li a").eq(0).focus();
							}
							return false;
							break;
						case $.ui.keyCode.UP:
							target.trigger("traverseUp");
							return false;
							break;
						case $.ui.keyCode.DOWN:
							target.trigger("traverseDown");
							return false;
							break;
						case $.ui.keyCode.ENTER:
						case $.ui.keyCode.SPACE:
							if (target.is("a.tree-parent")) 
							{
								target.trigger("toggle");
							} else 
							{
								return true;
							}
						default:
							return true;
					}
					return false;
			});
	},

	destroy: function() {
		$.Widget.prototype.destroy.apply(this, arguments);

		this.element
			.removeClass("tree")
			.removeAttr("tabIndex")
			.removeAttr("role");

		this.element.find("li")
			.removeClass("ui-menubar-item")
			.removeAttr("role").removeAttr("aria-expanded");
		this.element.find("a")
			.removeClass("tree-parent tree-parent-collapsed tree-parent-expanded")
			.removeAttr("tabIndex");
		this.element.find("ul")
			.removeClass("tree-group-collapsed tree-group-expanded")
			.removeAttr("role");
			
	},

	refresh: function(branch) {
		var self = this, options=self.options, usejqui = options.useJQueryUITheme;
		
		var items = (branch) ? branch.find("li") : this.element.find("li");
		
		items.attr("role","treeitem");
		var groupItems = items.has("ul").attr("aria-expanded", "false");
		groupItems.children("a").addClass("tree-parent tree-parent-collapsed");
		groupItems.children("ul").attr("role","group").addClass("tree-group-collapsed");
		
		items.each(function() {
			var $item = $(this), $a = $item.children("a"), className = "tree-icon ", span, img;
			
			$a.addClass(usejqui?"ui-corner-all":"")
			.hover(function() {
				$(this).addClass(usejqui?"ui-state-hover":"");
			}, function() {
				$(this).removeClass(usejqui?"ui-state-hover":"");
			})
			
			span = document.createElement("span");
				
			if (usejqui) className += "ui-icon "
			if ($a.is(".tree-parent")) {
				className += usejqui ? self.jQueryUINodeClosedIcon : self.jQueryUINodeOpenIcon;
				img = $item.data("image") || options.nodeClosedImage || "";
			} else {
				className += usejqui ? "ui-icon-document" : "tree-icon-document";
				img = $item.data("image") || options.itemImage || "";
			}
			if (img) span.style["background"] = "url(" + img + ") no-repeat 50% 50%";
			span.className = className;
			
			$a.prepend(span);
		});

		if (false) 
		{

		items.children("a").addClass(usejqui?"ui-corner-all":"")
			.hover(function() {
				$(this).addClass(usejqui?"ui-state-hover":"");
			}, function() {
				$(this).removeClass(usejqui?"ui-state-hover":"");
			})
			.each(function() {
				var $t = $(this), className = "tree-icon ",
				span = document.createElement("span");
				
				if (usejqui) className += "ui-icon "
				if ($t.is(".tree-parent")) {
					className += usejqui ? self.jQueryUINodeClosedIcon : self.jQueryUINodeOpenIcon;
				} else {
					className += usejqui ? "ui-icon-document" : "tree-icon-document"
				}
				span.className = className;
				
				$t.prepend(span);
			});

			items.children("a").addClass("ui-corner-all").hover(function()
			{
				$(this).addClass("ui-state-hover");
			}, function()
			{
				$(this).removeClass("ui-state-hover");
			}).not(".tree-parent").prepend('<span class="ui-icon ui-icon-document"></span>');
			
			groupItems.children("a").prepend('<span class="ui-icon ui-icon-folder-collapsed"></span>');
		}
	},

	select: function(item) {
		this._trigger("select", null, { item: item });
		item.find("a").eq(0).focus();
	}
});

})(jQuery);

// And now the LANSA Weblet
Lstd.Weblets.stdTreeview =
{
	init: function(treeID, treeData) {
		var $elem = jQuery(Lstd.Utils.makeSafeId(treeID)), i = 0,
		itemInfo, li, a, treeItem, $ul, $li, options;

		if (treeData.list)
		{
			//var list = new Lstd.Json.List({id: treeData.listName, obj:treeData.list});
			if (treeData.listType == "unlevelled")
			{
				this._addListEntries1(treeID, $elem, treeData, treeData.list);
			} else if (treeData.listType == "levelled")
			{
				this._addListEntries2(treeID, $elem, treeData, treeData.list);
			}
			treeData.list = null;
			list = null;
		}

		options = {
			select: function(e, ui) {
				e.preventDefault();
				var treeData = ui.item.closest(".tree").data("treeviewData"),
					itemInfo = ui.item.data("itemInfo"),
					subGroup = ui.item.children("ul"),
					wam = itemInfo.onSelectWAM || treeData.onSelectWAMName || g_lxmlWAMName,
					wr = itemInfo.onSelectWR || treeData.onSelectWRName,
					wrFields, win;

				if (wam && wr)
				{
					wrFields = Lstd.Weblets.stdTreeview._buildFieldListForRequest(ui.item, treeData);
					var url = stdFormatHttpRequest(null, wam, wr, null, wrFields, true), win = window;
					if (treeData.target)
					{
						// Look for a frame with a matching name
						win = window.frames[treeData.target];
						if (!win)
						{
							// Try a matching id
							var fr = document.getElementById(treeData.target), doc;
							if (fr && fr.contentDocument)
							{
								doc = fr.contentDocument;
								win = fr.contentWindow || doc.parentWindow || doc.defaultView;
							}
						}
					}
					if (win) win.location = url;
				}
			},
			expand: function(e, ui) {
				var treeData = ui.item.closest(".tree").data("treeviewData");
				var itemInfo = ui.item.data("itemInfo");
				var subGroup = ui.item.children("ul");
				if (treeData.onExpandWAMName && treeData.onExpandWRName && subGroup.length && subGroup.children("li").length == 0)
				{
					var li = document.createElement("li");
					li.appendChild(document.createTextNode("Loading..."));
					subGroup.append(li);

					var wrFields = Lstd.Weblets.stdTreeview._buildFieldListForRequest(ui.item, treeData);

					var request = new Lstd.HTTP.Request();
					request.wam = treeData.onExpandWAMName;
					request.webroutine = treeData.onExpandWRName;
					request.addFields(wrFields);
					Lstd.HTTP.getWebroutine(request, function(wr) {
						subGroup.empty();
						Lstd.Weblets.stdTreeview._addListEntries1(treeID, subGroup, treeData, wr.list(treeData.listName));
						$elem.treeview("refresh", ui.item);
						if (!subGroup.hasClass("tree-group-collapsed"))
						{
							subGroup.hide().slideDown(150);
						}
					});
				}
			}
		};

		var itemsForOptions = ["itemImage", "nodeClosedImage", "nodeOpenImage"];
		jQuery.each(itemsForOptions, function(i, v) {
			if (treeData[v]) treeData[v] = g_lweb_images_path + "/" + treeData[v];
		});
		itemsForOptions = itemsForOptions.concat("useJQueryUITheme", "jQueryUINodeIcon", "nodeTextOnClick");

		Lstd.Utils.mapArg2Option(treeData, options, itemsForOptions);
		$elem.data("treeviewData", treeData).treeview(options);

		var si = this._selectedItem;
		if (si)
		{
			if (si.type == "freeze")
			{
				si.$li.find("a").eq(0).focus();
			} else
			{
				$elem.treeview("select", si.$li);
			}
		}
		if (this._openItems) this._openItems.children("a").trigger("expand");
	},
	_addChildList: function($parentLI) {
		var $ul = $parentLI.children("ul");
		if ($ul.length == 0)
		{
			$ul = jQuery("<ul/>").appendTo($parentLI);
		}
		return $ul;
	},
	_addListEntries1: function(treeId, $defaultParent, webletData, list) {
		// Create LI elements for a unlevelled list
		var self = this, tmp;
		this._selectedItem = null;
		this._openItems = jQuery();

		list.entries().each(function(entry) {
			itemInfo = {
				id: entry.col(webletData.list_id_field),
				caption: entry.col(webletData.list_caption_field),
				image: entry.col(webletData.list_image_field),
				openImage: entry.col(webletData.list_open_image_field),
				onSelectWAM: entry.col(webletData.list_onselect_wamname_field),
				onSelectWR: entry.col(webletData.list_onselect_wrname_field),
				hasChildren: entry.col(webletData.list_haschildren_field),
				parentId: entry.col(webletData.list_parent_id_field)
			};
			itemInfo.hasChildren = (itemInfo.hasChildren) ? (itemInfo.hasChildren.toLowerCase() != "n") : false;
			if ((itemInfo.caption && itemInfo.id))
			{
				var itemInfo, li, a, $ul, $li;
				li = document.createElement("li");
				li.id = treeId + "_" + itemInfo.id;
				if (itemInfo.image)
				{
					li.setAttribute("data-image", g_lweb_images_path + "/" + itemInfo.image);
				}
				if (itemInfo.openImage)
				{
					li.setAttribute("data-imageOpen", g_lweb_images_path + "/" + itemInfo.openImage);
				}
				a = document.createElement("a");
				a.href = "#";
				a.innerHTML = itemInfo.caption;
				li.appendChild(a);

				$li = jQuery(li).data("itemInfo", itemInfo);
				if (itemInfo.hasChildren) self._addChildList($li);

				if (itemInfo.parentId)
				{
					$ul = self._addChildList(jQuery(Lstd.Utils.makeSafeId(treeId + "_" + itemInfo.parentId)));
				} else
				{
					$ul = $defaultParent;
				}
				$ul.append(li);

				tmp = (entry.col(webletData.list_is_selected_field) || "").toLowerCase();
				if (tmp == "true" || tmp == "freeze")
				{
					self._selectedItem = { $li: $li, type: tmp };
				}
				tmp = (entry.col(webletData.list_is_expanded_field) || "").toLowerCase();
				if (tmp == "true" || tmp == "y" || tmp == "1")
				{
					self._openItems = self._openItems.add($li);
				}
			}
		});
	},
	_addListEntries2: function(treeId, $defaultParent, webletData, list) {
		// Create LI elements for an levelled list
		var self = this;
		var keyFields = webletData.keyFields.split(",");
		var displayFields = webletData.displayFields.split(",");
		var currentKeys = [], ancestors = [$defaultParent[0]];

		list.entries().each(function(entry) {
			var ul, li, a, id;
			for (var i = currentKeys.length - 1; i >= 0; i--)
			{
				if (currentKeys[i] != entry.col(keyFields[i]))
				{
					currentKeys.length = i;
					ancestors.length = i + 1;
				}
			}
			for (var i = currentKeys.length; i < keyFields.length - 1; i++)
			{
				li = document.createElement("li");
				li.id = treeId + "_" + entry.col(keyFields[i]);
				a = document.createElement("a");
				a.href = "#";
				a.innerHTML = entry.col(displayFields[i]);
				li.appendChild(a);

				ul = document.createElement("ul");
				li.appendChild(ul);
				ancestors[ancestors.length - 1].appendChild(li);
				ancestors.push(ul);
				id = currentKeys[currentKeys.length] = entry.col(keyFields[i]);
				jQuery(li).data("itemInfo", { id: id });
			}
			li = document.createElement("li");
			li.id = treeId + "_" + entry.col(keyFields[i]);
			a = document.createElement("a");
			a.href = "#";
			a.innerHTML = entry.col(displayFields[i]);
			li.appendChild(a);
			ancestors[ancestors.length - 1].appendChild(li);
			jQuery(li).data("itemInfo", { id: entry.col(keyFields[i]) });
		});
	},
	_buildFieldListForRequest: function(treeItem, treeData) {
		var itemInfo = treeItem.data("itemInfo"),
		ancestors = treeItem.parentsUntil(".tree").filter("li").get().reverse(),
		fldName = treeData.onSubmitIdField || treeData.list_id_field || "",
		wrFields = [], alst = treeData.onSubmitAncestorList;
		if (fldName) wrFields.push({ name: fldName, value: itemInfo.id });
		if (fldName = treeData.onSubmitLevelField || "") wrFields.push({ name: fldName, value: ancestors.length + 1 });
		if (alst)
		{
			wrFields.push({ name: alst + "..", value: ancestors.length + 1 });
			for (var index = 0, ancestor; ancestor = ancestors[index]; index++)
			{
				wrFields.push({
					name: alst + "." + (index + 1).zeropad(4) + "." + treeData.list_id_field,
					value: jQuery(ancestors[index]).data("itemInfo").id
				});
			}
			wrFields.push({
				name: alst + "." + (index + 1).zeropad(4) + "." + treeData.list_id_field,
				value: itemInfo.id
			});
		}
		return wrFields;
	}
};

// std_button_v2

Lstd.Weblets.stdButton = {
	init: function(buttonID, args) {
		var btn = jQuery(Lstd.Utils.makeSafeId(buttonID));
		var _options = {};

		// Directly mapped options
		Lstd.Utils.mapArg2Option(args, _options, ["disabled"]);
		btn.button(_options);
		btn.addClass("std_button_v2");

		if (args.target)
		{
			var target = args.target;
			var elem = btn.get(0);

			if (args.defaultButton && args.defaultButton == true)
			{
				stdButton_setDefault("button", target.form, elem, function(event) {
					try
					{
						if (isDblClick(elem))
						{
							return false;
						}
						if (args.confirm)
						{
							Lstd.Weblets.dialog.confirm({text: args.confirm.text,
								confirmCallback: function(r) {
									if (r === true)
									{
										if (args.presubmit)
										{
											var res = args.presubmit.call(elem);
											if ((res != null) && (res != true)) return false;
										}
										Lstd.Weblets.stdButton.submitForm(btn,
											document.forms[target.form],
											target.wam,
											target.webroutine,
											target.protocol ? target.protocol : "",
											target.windowName ? target.windowName : "",
											args.extraFields,
											args.xmlColumnId);
									}
								}
							});
							return false; // Cancel onsubmit event. Let the response to confirm dialog box do the submit
						}
						else
						{
							if (args.presubmit)
							{
								var res = args.presubmit.call(elem);
								if ((res != null) && (res != true)) return false;
							}
							return Lstd.Weblets.stdButton.submitForm(btn,
								document.forms[target.form],
								target.wam,
								target.webroutine,
								target.protocol ? target.protocol : "",
								target.windowName ? target.windowName : "",
								args.extraFields,
								args.xmlColumnId);
						}
					}
					catch (e)
					{
						console.error(e);
					}
				});
			}
			else
			{
				btn.click(function(event) {
					try
					{
						event.stopPropagation();
						if (isDblClick(elem))
						{
							return false;
						}
						if (args.confirm)
						{
							Lstd.Weblets.dialog.confirm({text: args.confirm.text,
								confirmCallback: function(r) {
									if (r === true)
									{
										if (args.presubmit)
										{
											var res = args.presubmit.call(elem);
											if ((res != null) && (res != true)) return false;
										}
										Lstd.Weblets.stdButton.click(event,
											btn,
											target.wam,
											target.webroutine,
											target.form,
											target.protocol ? target.protocol : "",
											target.windowName ? target.windowName : "",
											args.currentRow.field,
											args.currentRow.value,
											args.extraFields,
											args.xmlColumnId);
										}
									}
							});
						}
						else
						{
							if (args.presubmit)
							{
								var res = args.presubmit.call(elem);
								if ((res != null) && (res != true)) return false;
							}
							return Lstd.Weblets.stdButton.click(event,
								btn,
								target.wam,
								target.webroutine,
								target.form,
								target.protocol ? target.protocol : "",
								target.windowName ? target.windowName : "",
								args.currentRow.field,
								args.currentRow.value,
								args.extraFields,
								args.xmlColumnId);
						}
					}
					catch (e)
					{
						console.error(e);
					}
				});
			}
		}
	},

	click: function(e, btn, WAMName, WRName, formName, protocol, target, currentrowhfield, currentrownumval, extraFields, xmlColumnId) {
		if (!e) e = window.e; 
		if (!e) return;

		var f = (!formName) ? getParentForm(elem) : createStdHiddenForm(WAMName, WRName, formName, protocol, target);
		if (f != null)
		{
			if (currentrowhfield && currentrowhfield.length > 0) insertHiddenField(f, currentrowhfield, currentrownumval);
			Lstd.Fields.insertExtraFields(f, extraFields ? extraFields : [], xmlColumnId);
			Lstd.Fields.check4VF_WAMEVENT(f, btn.get(0));
			submitForm(f, WAMName, WRName, target, protocol);
		}
		cancelEvent(e);
		return false;
	},

	submitForm: function(btn, form, WAMName, WRName, protocol, target, extraFields, xmlColumnId) {
		Lstd.Fields.insertExtraFields(form, extraFields ? extraFields : [], xmlColumnId);
		Lstd.Fields.check4VF_WAMEVENT(form, btn.get(0));
		submitForm(form, WAMName, WRName, target, protocol);
		return false;
	}
};

// std_toexcel

Lstd.Weblets.stdToExcel = {
	init: function(buttonID, args) {
		var btn = jQuery(Lstd.Utils.makeSafeId(buttonID));
		var _options = {};

		// Directly mapped options
		Lstd.Utils.mapArg2Option(args, _options, ["disabled"]);

		if (window.ActiveXObject == null) _options.disabled = true;
		btn.button(_options);

		btn.click(function(event) {
			try {
				event.stopPropagation();
				var tableRows = document.getElementById(args.listname).rows;
				var xlObject = new ActiveXObject("Excel.Application");
				if (xlObject != null) {
					var xlWorkbook = xlObject.Workbooks.Add;
					var xlSheet = xlWorkbook.ActiveSheet;
					var startingColumnIndex = args.startingColumnIndex ? args.startingColumnIndex : 0;
					
					if (tableRows.length > 0) {
						var numberOfColumns = args.numberOfColumns ? args.numberOfColumns : tableRows[0].cells.length - startingColumnIndex;
						var nLastCol = startingColumnIndex + numberOfColumns;
						 
						for (i = 0; i < tableRows.length; i++) {
							var tableRow = tableRows[i].cells;

							for (j = startingColumnIndex, k = 1; j < nLastCol; j++, k++) {
								var xlCell = xlObject.Cells(i + 1, k);
								xlCell.Value = tableRow[j].innerText;
								xlCell.EntireColumn.AutoFit();
							}
							if (i == 0) {
								xlObject.ActiveCell.EntireRow.Font.Bold = true;
								xlObject.ActiveCell.HorizontalAlignment = -4108;            
							}
						}
						xlObject.Visible = true;
						xlObject.UserControl = true;
					}
				}
				else {
					btn.button("disable");
				}
			}
			catch (e) {
				alert(e);
				console.error(e);
			}
		});
	}
};

// jQuery UI dialog

Lstd.Weblets.dialog = {

	/**
	 * Global initialization flag. Set to true when once-off static initialization is completed.
	 */
	globalInitFlag: false,

	/**
	 * Regional settings
	 */
	lang: "",
	regional: [],

	/**
	 * Sets global defaults for all dialog instances
	 */
	globalInit: function() {
		if (this.globalInitFlag) return;
		this.globalInitFlag = true;

		this.regional[''] = {
			OK: 'OK',
			Cancel: 'Cancel',
			alertTitle: 'Message',
			confirmTitle: 'Confirm action',
			isRTL: false
		};

		if (!(window.g_lxmlISOLang == "") && !(window.g_lxmlISOLang == "en"))
		{
			this.lang = Lstd.Weblets.Utils.getI18nScript("/script/i18n/jquery/lstd.weblets.dialog-");
		}
	},

	/*
	 * Set default settings
	 * @param [object] Regional settings
	 */
	setDefaults: function(settings) {
		var regional = this.regional[''];
		for (p in settings) {
			regional[p] = settings[p];
		}
	},

	/**
	 * Alert dialog box
	 * Options:
	 * text: [String] Message text
	 * onClose: [function] Callback function to perform actions when dialog box is closed (optional)
	 * title [String] Dialog box title (optional)
	 */
	alert: function(args) {
		this.globalInit();
		var regional = this.regional[''];

		try {
			var theDiv = Lstd.Weblets.dialog.getDiv();
			theDiv.append(Lstd.Weblets.dialog.format(args.text ? args.text : ""));

			var buttons = {};
			buttons[regional.OK] = function() {
				theDiv.dialog("close");
			};

			var options = {
				modal: true,
				resizable: false,
				closeOnEscape: false,
				"buttons": buttons,
				"title": args.title ? args.title : regional.alertTitle,
				close: function(event, ui) {
					if (typeof args.onClose == "function") {
						try {
							args.onClose();
						}
						catch (e) {
							console.error(e);
						}
					}
					Lstd.Weblets.dialog.destroy(theDiv);
				}
			};

			theDiv.dialog(options);
		}
		catch (e) {
			console.error(e);
		}
	},

	/**
	 * Callback confirmation dialog box
	 * Options:
	 * text [String] Message text
	 * confirmCallback [function] Callback function to receive boolean result of confirm action
	 * title [String] confirmation dialog box title (optional)
	 */
	confirm: function(args) {
		this.globalInit();
		var regional = this.regional[''];

		try {
			var theDiv = Lstd.Weblets.dialog.getDiv();
			theDiv.append(Lstd.Weblets.dialog.format(args.text ? args.text : ""));

			var buttons = {};
			buttons[regional.OK] = function() {
				try {
					args.confirmCallback(true);
				}
				catch (e) {}
				theDiv.dialog("option", "close", null); // Cancel default
				Lstd.Weblets.dialog.destroy(theDiv);
			};

			buttons[regional.Cancel] = function() {
				try {
					args.confirmCallback(false);
				}
				catch (e) {}
				theDiv.dialog("option", "close", null); // Cancel default
				Lstd.Weblets.dialog.destroy(theDiv);
			};

			var options = {
				modal: true,
				resizable: false,
				closeOnEscape: false,
				"buttons": buttons,
				"title": args.title ? args.title : regional.confirmTitle,
				close: function(event, ui) {
					args.confirmCallback(false); // Defaults to "Cancel"
					Lstd.Weblets.dialog.destroy(theDiv);
				}
			};
			theDiv.dialog(options);
		}
		catch (e) {
			window.alert(e)
		}
	},

	/*
	 * Gets the dialog element where the message will be appended
	 */
	getDiv: function() {
		var theDiv = jQuery("#lweb_dialog");
		if (theDiv.length == 0) {
			var theHiddenDiv = Lstd.Weblets.Utils.getHiddenDiv();
			theDiv = jQuery("<div id=\"lweb_dialog\"><div>").appendTo(theHiddenDiv);
		}
		else {
			theDiv.empty();
		}
		return theDiv;
	},

	/*
	 * Formats (with HTML) the message to display
	 * @param [string] Text message
	 */
	format: function(text) {
		return !(this.regional[''].isRTL)
			? "<p><span class=\"ui-icon ui-icon-alert\" style=\"float:left; margin:0 7px 20px 0;\"></span>" + text + "</p>"
			: "<p>" + text + "<span class=\"ui-icon ui-icon-alert\" style=\"float:right; margin:0 0 20px 7px;\"></span></p>";
	},

	/*
	 * Closes the dialog, destroys the dialog instance and removes the contents of the dialog
	 * @param [obj] The dialog jQuery object
	 */
	destroy: function(obj) {
		if (obj.dialog("isOpen")) {
			obj.dialog("close");
		}
		obj.dialog("destroy").empty();
	}
};

// std_progressbar

Lstd.Weblets.stdProgressBar = {
	instances: {},
	init: function(id, args) {
		var transitory = args.transitory || false;
		var indeterminate = args.indeterminate || false;
		var overlay = args.overlay || false;
		var delayClose = args.delayClose || 0;

		function stdProgressBar(id, args) {
			var $pb = jQuery(Lstd.Utils.makeSafeId(id));
			var $pbo = jQuery(Lstd.Utils.makeSafeId("_" + id + "_OVERLAY"));
			var $pbt = jQuery("<div class=\"std_progressbar_text\"></div>");
			var initValue = args.value != undefined ? args.value : 0;
			var maxVal = args.max != undefined ? args.max : 100;
			var captionText = (args.caption != undefined) ? args.caption : window.g_StdLocaleMgr.getMessageText(indeterminate? "InProgress" : "Complete");
			var std_pb = this;
			this.started = false;

			$pbt.appendTo($pb);

			/**
			 * Centers the progress bar in the window (overlaying the page)
			 */
			this.center = function() {
				var $window = jQuery(window);
				$pb.css("position","absolute");
				$pb.css("top", Math.max(0, (($window.height() - $pb.outerHeight()) / 2) + $window.scrollTop()) + "px");
				$pb.css("left", Math.max(0, (($window.width() - $pb.outerWidth()) / 2) + $window.scrollLeft()) + "px");
			};

			/**
			 * Computes the percentage of the current value relative to the max value.
			 */
			this.percentage = function(val) {
				var pct = parseInt((val/maxVal * 100), 10);
				$pbt.text(pct + "%");
			};

			/**
			 * Starts the progress bar
			 */
			this.start = function() {
				if (!std_pb.started) {
					if (indeterminate) {
						$pb.progressbar({value: false,
							complete: function() {
							}
						});
						$pbt.text(captionText);
						std_pb.started = true;
					}
					else {
						$pb.progressbar({max: maxVal,
							value: initValue,
							change: function() {
								std_pb.percentage($pb.progressbar("value"));
							},
							complete: function() {
								$pbt.text(captionText);
							}
						});

						if (initValue !== 0) {
							std_pb.percentage(initValue);
						}
					}

					if (transitory) {
						if (overlay) {
							$pbo.css("display", "block");
							$pb.show();
							this.center();
							var zplus = parseInt($pbo.css("z-index")) + 1;
							$pb.css("z-index", zplus);
						}
						else {
							$pb.show();
						}
					}
					std_pb.started = true;
				}
			};

			/**
			 * Stops the progress bar (private)
			 */
			this._stop = function() {
				if (transitory) {
					if (overlay) {
						$pbo.css("display", "none");
					}
				}
				$pb.hide();
				$pb.progressbar("destroy");
				std_pb.started = false;
			};

			/**
			 * Stops the progress bar
			 */
			this.stop = function() {
				if (delayClose > 0) {
					setTimeout(this._stop, delayClose);
					std_pb.started = false;
				}
				else {
					std_pb._stop();
				}				
			};

			/**
			 * Updates the value of the progress bar
			 */
			this.value = function(val) {
				$pb.progressbar("option", "value", val);
			};

			if (!(indeterminate || transitory)) {
				this.start();
			}
			else if (transitory) {
				$pb.hide();
			}
		}
		Lstd.Weblets.stdProgressBar.instances[id] = new stdProgressBar(id, args);
	},

	start: function(id) {
		var inst = Lstd.Weblets.stdProgressBar.instances[id];
		if (inst) inst.start();
	},

	stop: function(id) {
		var inst = Lstd.Weblets.stdProgressBar.instances[id];
		if (inst) inst.stop();
	},

	value: function(id, val) {
		var inst = Lstd.Weblets.stdProgressBar.instances[id];
		if (inst) inst.value(val);
	}
};

// Lazy image loading
(function() {
	try {
		jQuery(function() {
			if (jQuery.fn.lazyload) {			
				jQuery("img.std_lazy").lazyload({effect: "fadeIn"});
			}
		});
	}
	catch (e) {
		console.error(e);
	}
})();
