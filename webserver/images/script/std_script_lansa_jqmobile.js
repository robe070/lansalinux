/*!
	(c) 2012, 2013 LANSA
	jQuery Mobile Standard Scripts
	$Workfile:: std_script_lansa_jqmobile.js $
	$UTCDate:: 2013-10-28 22:17:02Z          $
	$Revision:: 48                           $
*/

/**
 * Date.parse with progressive enhancement for ISO 8601 <https://github.com/csnover/js-iso8601>
 * © 2011 Colin Snover <http://zetafleet.com>
 * Released under MIT license.
 */
(function (Date, undefined) {
    var origParse = Date.parse, numericKeys = [ 1, 4, 5, 6, 7, 10, 11 ];
    Date.parse = function (date) {
        var timestamp, struct, minutesOffset = 0;

        // ES5 §15.9.4.2 states that the string should attempt to be parsed as a Date Time String Format string
        // before falling back to any implementation-specific date parsing, so that’s what we do, even if native
        // implementations could be faster
        //              1 YYYY                2 MM       3 DD           4 HH    5 mm       6 ss        7 msec        8 Z 9 ±    10 tzHH    11 tzmm
        if ((struct = /^(\d{4}|[+\-]\d{6})(?:-(\d{2})(?:-(\d{2}))?)?(?:T(\d{2}):(\d{2})(?::(\d{2})(?:\.(\d{3}))?)?(?:(Z)|([+\-])(\d{2})(?::(\d{2}))?)?)?$/.exec(date))) {
            // avoid NaN timestamps caused by “undefined” values being passed to Date.UTC
            for (var i = 0, k; (k = numericKeys[i]); ++i) {
                struct[k] = +struct[k] || 0;
            }

            // allow undefined days and months
            struct[2] = (+struct[2] || 1) - 1;
            struct[3] = +struct[3] || 1;

            if (struct[8] !== 'Z' && struct[9] !== undefined) {
                minutesOffset = struct[10] * 60 + struct[11];

                if (struct[9] === '+') {
                    minutesOffset = 0 - minutesOffset;
                }
            }

            timestamp = Date.UTC(struct[1], struct[2], struct[3], struct[4], struct[5] + minutesOffset, struct[6], struct[7]);
        }
        else {
            timestamp = origParse ? origParse(date) : NaN;
        }

        return timestamp;
    };
}(Date));

/**
* Left pads the string
* @param {Integer} length The length of the result string.
* @param {String} padWith The character to pad the string with.  If longer than one character, only the first is used. If empty a space is used.
* @returns {String}
*/
String.prototype.lpad = function(len, pad) {
	pad = (!pad) ? " " : pad.substring(0,1);
	return (len -= this.length) > 0 ? (new Array(len + 1).join(pad) + this) : "" + this;
};

/**
* Right pads the string
* @param {Integer} length The length of the result string.
* @param {String} padWith The character to pad the string with.  If longer than one character, only the first is used. If empty a space is used.
* @returns {String}
*/
String.prototype.rpad = function(len, pad) {
	pad = (!pad) ? " " : pad.substring(0,1);
	return (len -= this.length) > 0 ? (this + new Array(len + 1).join(pad)) : "" + this;
};
/**
 * Return the string padded with leading zeros
 */
String.prototype.zeropad = function(len) { return this.lpad(len, "0"); }
/**
 * Return the number as a string padded with leading zeros
 */
Number.prototype.zeropad = function(len) { return this.toString().zeropad(len); }


//////////////////////////////////////////////////////////////////////////////////////////
//
// Initialise Lstd namespace
//
//////////////////////////////////////////////////////////////////////////////////////////

/**
 * @namespace
 */
Lstd = window.Lstd || {};
/**
 * Hooks up the Lstd framework init method to an appropriate "ready" event.
 */
Lstd.bootstrap = function() {
	jQuery(document).ready(function() {Lstd.init();});
}

/**
 * Initialise the framework
 * @private
 */
Lstd.init = function() {
	Lstd.I18n.init();
	
	this.Weblets.initAll();
	
	$(document).on("vmouseup", "a.lstd_anchor", Lstd.Weblets.stdAnchor.prepareURL);
	
	$(document).on("click", "button.lstd_button[type=submit]", function(e) {
		var $t = $(e.target), action = $t.attr("formaction"), presubmitJS = $t.attr("data-presubmitjs");
		$f = $(e.target.form),
		transition = $t.data("transition"), direction = $t.data("direction"),
		oldAction="", oldTrans="", oldDir="", wrOptions = Lstd.wrOptions; wrContext = Lstd.wrContext;
		
		if (presubmitJS) {
			try {
				var js = new Function(presubmitJS), val = js();
				if (val === false) {
					e.stopImmediatePropagation();
					e.preventDefault();
					return;
				}
			}
			catch (e) {
				console.error(e);
			}
		}

		if ((wrOptions["debug"] != null) && (wrOptions["debug"].length > 0)) action += ("&debug=" + wrOptions["debug"]);
		if ((wrContext["session-key-method"] == "url") && (wrContext["session-key"] != "")) action += ("&sid=" + wrContext["session-key"]);
		
		var extraFields = $t.data("lansaextrafields");
		
		if (extraFields) {
			 Lstd.Fields.insertExtraFields($f[0], extraFields, $t.data("lansaxmlcolumnid"))
		}
		
		if (action) {
			oldAction = $f.attr("action") || "";
			$f.attr("action", action);
		}
		if (transition) {
			oldTrans = $f.jqmData("transition") || "";
			$f.jqmData("transition", transition);
		}
		if (direction) {
				oldDir = $f.jqmData("direction") || "";
				$f.jqmData("direction", direction);
			}
		if (action || transition || direction) {
			window.setTimeout(function() {
				if (oldAction) $f.attr("action", oldAction);
				if (oldTrans) $f.jqmData("transition", oldTrans);
				if (oldDir) $f.jqmData("direction", oldDir);
			}, 500);
		}
	});

	$(document).on("click", "button.lstd_button[type=button]", function(e) {
		var presubmitJS = $(e.target).attr("data-presubmitjs");
		if (presubmitJS) {
			try {
				var js = new Function(presubmitJS), val = js();
				if (val === false) {
					e.stopImmediatePropagation();
					e.preventDefault();
					return;
				}
			}
			catch (e) {
				console.error(e);
			}
		}
	});
	
	$("body").bind("pagechange", function(e, data) {
		Lstd.Weblets.initAll();
	});
	
	$("body").bind("pagebeforechange", function(e) {
		// This event gets fired multiple times before pagechange. we only want to do this the first time as
		// new weblets may be registered in between.
		if (Lstd.Weblets.initDone) {
			Lstd.Weblets.destroyAll();
			Lstd.Lists = {};
		}
	});
	
	// Set up validation handling
	$("body").on("submit", "form", function(e) {
		var errFound = false, $this = $(this), form = this;
		if (Lstd.Validator.asyncValidation) {
			window.clearTimeout(Lstd.Validator.asyncValidation);
			Lstd.Validator.asyncValidation = null;
		}
		$(e.target).addClass("submitted");
		$this.find("input,textarea,select").each(function(i, inp) {
			errFound |= !Lstd.Validator.validateField(inp);
		});
		if (errFound) {
			e.preventDefault();
			return false;
		}
		$this.find("[data-lstdmultiselect]").each(function(index, sel) {
			var listInfo = $(sel).jqmData("lstdmultiselect").split(","), values = [];
			for (var i=0, o; o=this.options[i]; i++) {
				if (o.selected) values.push([o.value]);
			}
			Lstd.Utils.insertHiddenList(form, listInfo[0], [listInfo[1]], values);
		});
		
	}).on("input", "input,textarea,select", function(e) {
		Lstd.Validator.validateField(e.target);
	}).on("blur", "input,textarea,select", function(e) {
		$("#" + e.target.id + "_error").addClass("visited");
	});
	
	$("body").bind("pageload", function(e, data) {
		pageLoadXhr = data.xhr;

		var html = data.xhr.responseText, match, found, newEl,
		currentLinks = $("link[type='text/css']"), l=currentLinks.length,
		linkRegex = /<link rel="stylesheet" type="text\/css" href="([^"'>]*)" charset="([^"'>]*)"[^>]*>/g;
		
		$("link[data-lstdtype='ajax']").remove();

		while (match = linkRegex.exec(html)) {
			found = false;
			for (var i=0; i<l; i++ ) {
				if (currentLinks[i].getAttribute("href") == match[1]) {
					found = true;
					break;
				}
			}
			if (!found) {
				newEl = document.createElement("link");
				newEl.type = "text/css";
				newEl.rel = "stylesheet";
				newEl.href = match[1];
				newEl.charset = match[2];
				newEl.setAttribute("data-lstdtype", "ajax");
				document.getElementsByTagName("head")[0].appendChild(newEl);
			}
		}
	});
	
	
	document.addEventListener("invalid", function(e) {
		var $form = $(e.srcElement.form);
		if (!Lstd.Validator.isLstdValidation) {
			// Error not triggered by Lstd framework validation
			// On some browsers the submit will not be fired resulting in Lstd validation not happening
			// Set a timeout to make it happen. Submit handler will cancel it if it does fire.
			if (Lstd.Validator.asyncValidation == null) {
				Lstd.Validator.asyncValidation = window.setTimeout(function() {
					$form.addClass("submitted");
					if ($form.parents(".lstdErrorNone").length == 0) {
						$form.find("[data-lstddatatype]").each(function(i, inp) {
							Lstd.Validator.validateField(inp);
						});
					}
					Lstd.Validator.asyncValidation = null;
				}, 10);
			}
		}
		if ($form.parents(".lstdErrorShowInDiv").length > 0) {
			e.preventDefault();
			e.stopPropagation();
			return false;
		}
	}, true);
}

Lstd.Validator = {
	isLstdValidation: false,
	asyncValidation: null,
	validateField: function(field) {
		var dtInfoStr = $(field).data("lstddatatype"), dtInfo, errOnThisFld = "", result;
		if (dtInfoStr) dtInfo = dtInfoStr.split("|");
		field.setCustomValidity("");
		this.isLstdValidation = true;
		// If built-in validation fails then we are done.
		if (field.checkValidity() && dtInfo) {
			switch (dtInfo[0]) {
				case 'alpha':
				case 'char':
				case 'varchar':
				case 'nchar':
				case 'nvarchar':
					errOnThisFld = this.isValidText(field.value, dtInfo[1], dtInfo[2]);
					break;
				case "dec":
				case 'packed':
				case 'signed':
					errOnThisFld = this.isValidNumber(field.value, dtInfo[1], dtInfo[2], dtInfo[3]);
					break;
				case 'integer':
					errOnThisFld = this.isValidInteger(field.value, dtInfo[1]);
					break;
				case 'float':
					errOnThisFld = this.isValidFloat(field.value, dtInfo[1]);
					break;
				case 'date':
					errOnThisFld = this.isValidDate(field.value);
					break;
				case 'time':
					errOnThisFld = this.isValidTime(field.value);
					break;
				case 'datetime':
					errOnThisFld = this.isValidDateTime(field.value, dtInfo[1]);
					break;
				case 'boolean':
					errOnThisFld = this.isValidBoolean(field.value);
					break;
			}
			if (errOnThisFld != "") {
				field.setCustomValidity(errOnThisFld);
				field.checkValidity();
			}
		}
		this.isLstdValidation = false;
		result = field.validity.valid;
		$("#" + field.id + "_error").text(field.validationMessage).toggleClass("lstdValidationError", !result);
		return result;
	},
	validateFloat: function(value, size) {
		size = size || 8;
		return isNaN(new Number(value)) ? Lstd.I18n.getString("BadFloat") : "";
		Lstd.Messaging.sendMessage(senderId + ".ValidationMessage", {
			senderId: senderId,
			value: value,
			error: isNaN(new Number(value)) ? Lstd.I18n.getString("BadFloat") : ""
		});
	},
	isValidNumber: function(valueStr, length, decimals, decimalPoint) {
		if (Lstd.wrOptions["check-numeric"] != "true") return "";
		var integers = (length == "") ? "" : length - ((decimals == "") ? 0 : decimals);
		integers = (integers < 0) ? 0 : integers;
		decimalPoint = decimalPoint || ".";
		if( valueStr.length <= 0 ) return "";
		var re = new RegExp("^[+-]?\\d{0," + integers + "}(\\" + decimalPoint + "\\d{0," + decimals + "})?$");
		return re.test(valueStr) ? "" : Lstd.I18n.getString("BadNum", integers, decimals);
	},
	isValidInteger: function(valueStr, size) {
		var isValid = false, minVal = 0, maxVal = 0, limit, valueVal, cmpStr, i;
		if( valueStr.length <= 0 ) return "";
		if (valueStr.match(/^[+-]?\d*$/) == null)
		{
		    return Lstd.I18n.getString("BadInt");
		}
		
		if (size < 7) {
			limit = Math.pow(256, size) / 2;
			minVal = -1 * limit;
			maxVal = limit - 1;

			valueVal = new Number(valueStr);
			isValid = (valueVal >= minVal) && (valueVal <= maxVal);
		} else {
			// JavaScript can't handle a precision of more than 16 digits so integers
			// of more than that have to be processed as strings.
			if (size == 7) {
				minVal = "-36028797018963968";
				maxVal = "36028797018963967";
			} else {
				minVal = "-9223372036854775808";
				maxVal = "9223372036854775807";
			}

			cmpStr = maxVal;
			i = 0;
			if (valueStr.charAt(0) == "-") {
				cmpStr = minVal;
				i = 1;
			}
			if (valueStr.length < cmpStr.length) return "";
			if (valueStr.length == cmpStr.length) {
				isValid = true;
				while (i < valueStr.length) {
					if (Number(valueStr.charAt(i)) > Number(cmpStr.charAt(i))) {
							isValid = false;
							break;
					} else if (Number(valueStr.charAt(i)) < Number(cmpStr.charAt(i))) {
							isValid = true;
							break;
					}
					i++;
				}
			}
		}
		return isValid ? "" : Lstd.I18n.getString("BadIntWithRange", minVal, maxVal);
	},
	isValidFloat: function(valueStr, size) {
		var numeric = new Number(valueStr);
		return isNaN(numeric) ? Lstd.I18n.getString("BadFloat") : "";
	},
	isValidDate: function(valueStr) {
		var isValid = false;
		// Date.parse will default month and day if not present. We need to be a bit more strict
		if (/^\d{4}-\d{1,2}-\d{1,2}$/.test(valueStr)) {
			isValid = !isNaN(Date.parse(valueStr));
		}
		return isValid ? "" : Lstd.I18n.getString("BadDate");
	},
	isValidTime: function(valueStr) {
		return (/^(?:[01]?[0-9]|2[0123]):[012345][0-9]:[012345][0-9]$/.test(valueStr)) ? "" : Lstd.I18n.getString("BadTime");
	},
	isValidDateTime: function(valueStr) {
		return isNaN(Date.parse(valueStr)) ? Lstd.I18n.getString("BadDateTime") : "";
	},
	isValidText: function(valueStr, keyboardShift, size) {
		var i, l = valueStr.length, totalDBCS = 0, totalSBCS = 0, totalLength = 0, inDBCS = false;
		keyboardShift = keyboardShift || " ";
		if (Lstd.wrOptions["DBCS"] == "true") {
			// Calculate the byte length
			for (var i = 0; i < l; i++) {
				if (escape(valueStr.charAt(i)).length >= 4) {
					if (!inDBCS) {
						inDBCS = true;
						totalLength += 2;
					}
					totalLength += 2;
					totalDBCS++;
				} else {
					totalLength++;
					totalSBCS++;
					if (inDBCS) inDBCS = false;
				}
			}
		
			if (totalLength > size) return Lstd.I18n.getString("BadDBCS_TooLong", totalLength, size);
			if ((keyboardShift == 'J') && (totalSBCS > 0)) return Lstd.I18n.getString("BadDBCS_SBCSNotAllowed", totalSBCS);
			if ((keyboardShift == 'A') && (totalSBCS > 0)) return Lstd.I18n.getString("BadDBCS_DBCSNotAllowed", totalDBCS);
			if ((keyboardShift == 'E') && (totalSBCS > 0) && (totalDBCS > 0)) return Lstd.I18n.getString("BadDBCS_BothNotAllowed", totalSBCS, totalDBCS);
		}
		return "";
	}

}

Lstd.I18n = {
	_strings: {},
	_arrays: {},
	init: function() {
		var path = "/script/i18n/lansa_jqmobile/std_messages-%1.json";
		// Always load "en"
		this.lang = this.getI18nStrings(path, null, "en") || "en";
		if (Lstd.wrContext["language-iso"] != "en") {
			this.lang = this.getI18nStrings(path) || "en";
		}
	},
	/**
	 * Returns the base language given the composite IANA language-qualifier code
	 * @param {string} isoLang The qualified language code (for example: en-US)
	 * @returns {string} The base language
	 */
	 baseISOLang: function(isoLang) {
		try {
			return isoLang.split('-')[0];
		} catch (e) {
			console.error("Lstd.I18n.baseISOLang(): " + e);
			return "";
		}
	 },
	
	/**
	 * Loads the jQuery localization JavaScript file. If the qualified language code file.
	 *	If not found it loads the base language file.
	 * @param {string} jsfile The partial JS file path (Exclude the images path and extension). The name must contain '%1' which will be replaced by the language code.
	 * @param {function} charsetCB An optional callback function that returns the charset to use for the script file. If not provided, charset defaults to "utf-8".
	 * @return {string} ISO language code for regional JS file loaded. If none loaded, it returns "".
	 */
	getI18nStrings: function(jsfile, charsetCB, lang) {
		lang = lang || Lstd.wrContext["language-iso"];
		var baseLang = this.baseISOLang(lang),
			filePath = Lstd.wrContext["images-path"] + jsfile,
			loadedBase = "", loadedFull = "";

		baseLang = this.baseISOLang(lang);
		if ((lang != baseLang) && (baseLang != "en")) {
			loadedBase = this._getJSONData(baseLang, filePath);
		}
		loadedFull = this._getJSONData(lang, filePath);
		return loadedFull || loadedBase;
	},
	_getJSONData: function(lang, file) {
		if (lang == "") return "";
		var retVal = "", tmp, self = this;
		jQuery.ajax({type: "GET",
			async: false,
			dataType: "json",
			cache: true,
			url: Lstd.Utils.strargs(file, lang),
			success: function(data) { 
				if (data.strings) {
					tmp = self._strings[lang];
					if (tmp == undefined) tmp = self._strings[lang] = {};
					jQuery.extend(tmp, data.strings);
				}
				if (data.arrays) {
					tmp = self._arrays[lang];
					if (tmp == undefined) tmp = self._arrays[lang] = {};
					jQuery.extend(tmp, data.arrays);
				}
				retVal = lang;
			},
			scriptCharset: (typeof charsetCB == "function") ? charsetCB(lang) : "utf-8"
		});
		return retVal;
	},
	getString: function(stringId) {
		var strings = this._strings[this.lang], enStrings = this._strings["en"];
		var theString = (strings) ? (strings[stringId] || enStrings[stringId] || "") : (enStrings[stringId] || "");
		return (arguments.length > 1) ? Lstd.Utils.strargs(theString, Array.prototype.slice.call(arguments, 1,arguments.length)) : theString;
	},
	getArray: function(arrayId) {
		var langArrays = this._arrays[this.lang], enArrays = this._arrays["en"];
		return (langArrays) ? (langArrays[arrayId] || enArrays[arrayId] || []) : (enArrays[arrayId] || []);
	}
	
};


/**
 * @namespace
 * Contains assorted utilities
 */
Lstd.Utils = {
	/**
	 * Replaces %1-%n in a string with the supplied arguments. Any %% in the string is replaced with a single %. Any % not preceeding a digit is left untouched.
	 * @param {String} str
	 * @param {String[]} args
	 */
	strargs: function(str, args) {
		// make sure args is an array
		if (args == null || typeof(args) == "undefined") 
		{
			args = [];
		}
		else if (args.constructor != Array) 
		{
			args = [args];
		}
		
		return str.replace(/%(%|\d+)/gm, function(match, p1, offset, s)
		{
			if (p1 == "%") return "%";
			var argNo = parseInt(p1) - 1;
			return (args[argNo]) ? args[argNo] : "";
		});
	},
	/**
	 * Creates an escaped jQuery ID selector.
	 */
	makeSafeId: function(id) {
		return '#' + this.escapeForJQSelector(id);
	},
	/**
	 * Escapes characters that have special meaning when used in jQuery selector expressions.
	 */
	escapeForJQSelector: function(str) {
		return str.replace(/([$:.])/g,'\\$1');
	},
	/**
	 * Adds the options passed as arguments to weblets to the options map of jQuery widgets.
	 * @param {Object} args An object hash
	 * @param {Object} options An object hash
	 * @param [String] names An array of property names to copy from arg to options.
	 * @return {Object} The updated options object (The object is updated in place so you don't need to use this value)
	 */
	mapArg2Option: function(args, options, names) {
		for (i in names)
		{
			var nm = names[i];
			if (args[nm] != undefined) options[nm] = args[nm];
		}
	},
	/**
	 * Decimal to Hexadecimal converter
	 * @param {number} d The number (base 10)
	 * @returns {string} The number in hexadecimal
	 */
	dec2hex: function(d) {
		var hex = d.toString(16);
		return hex.length == 1 ? "0" + hex : hex;
	},
	/**
	 * rgb(r, g, b) to Hexadecimal format converter
	 * @param {string} rgb The rgb(r, g, b) string
	 * @returns {string} The color in hex format (sans # prefix)
	 */
	rgb2hex: function(rgb) {
		var reg = rgb.match(new RegExp("^rgb\\((\\d{1,3}), ?(\\d{1,3}), ?(\\d{1,3})\\)", "i"));
		var s = "";
		if (reg)
		{
			for (var i = 1; i < reg.length; i++) s += this.dec2hex(parseInt(reg[i]));
		}
		return s;
	},
	/**
	 * getHexColor
	 * @param {color} color The color in either rgb(r, g, b) or hex format
	 * @returns {string} The color in hex format (sans # prefix)
	 */
	getHexColor: function(color) {
		var reg = color.match(/^#([0-9a-fA-F]{6})/);
		if (reg) return reg[1];
		reg = color.match(/^rgb\(/i);
		return reg ? Lstd.Utils.rgb2hex(color) : "";
	},
	/**
	 * Escapes regex special characters
	 * @param [string] The regex expression
	 * @returns [string] The regex expression with special characters escaped
	 */
	escapeRegex: function(expr) {
		return expr.replace(/[-[\]{}()*+?.,\\^$|#\s]/g, "\\$&");
	},
	/**
	 * Returns the object's property name at a given index position
	 * @param {object} The object
	 * @param [number] The index position
	 * @return [string] the property name at the index position or null if not found
	 */
	getPropertyNameAtIndex: function(obj, index) {
		var i = 0;
		for (x in obj) if (i++ == index) return x;
		return null;	
	},
	/**
	 * Returns the object's property value at a given index position
	 * @param {object} The object
	 * @param [number] The index position
	 * @return [string] the property value at the index position or null if not found
	 */
	getPropertyValueAtIndex: function(obj, index) {
		var i = 0;
		for (x in obj) if (i++ == index) return obj[x];
		return null;	
	},
	/**
	 * Inserts a hidden field in a form
	 * @param {object} form The form to add the field to.
	 * @param {String} fieldName The name of the field to add.
	 * @param {String} fieldValue The value to place in the field.
	 */
	insertHiddenField: function(form, fieldName, fieldValue)
	{
		if( form == null ) return null;
		if (!fieldName) return null;
		if (!fieldValue) fieldValue = "";
		var field = form.elements[fieldName];
		if (field == null)
		{
			field = document.createElement("input");
			field.name = fieldName;
			field.setAttribute("type", "hidden");
			field.setAttribute("value", fieldValue);
			form.appendChild(field);
		}
		else
		{
			field.value = fieldValue;
		}
		return field;
	},
	insertHiddenList: function(form, listName, listColumnNames, listValuesTable)
	{
		if( listName == null || listName.length <= 0 ) return false;
		if( listColumnNames == null || listValuesTable == null ) return false;

		var index = 0, rows = listValuesTable.length, cols = listColumnNames.length, fieldName, bBreakLoop, elem;
		this.insertHiddenField(form, listName + "..", rows.toString());
		for(index = 0; index < rows; index++)
		{
			for (var colIndex = 0; colIndex < cols; colIndex++)
			{
				fieldName = [listName, (index+1).zeropad(4), listColumnNames[colIndex]].join(".");
				this.insertHiddenField(form, fieldName, listValuesTable[index][colIndex]);
			}
		}
		bBreakLoop = false;
		while(!bBreakLoop)
		{
			for (var colIndex = 0; colIndex < cols; colIndex++)
			{
				fieldName = [listName, (index+1).zeropad(4), listColumnNames[colIndex]].join(".");
				elem = form.elements[fieldName];
				if( elem ) {
					elem.parentNode.removeChild(elem);
				} else {
					bBreakLoop = true;
					break;
				}
			}
			index++;
		}
		return true;
	},
	/**
	 * Formats field name=value pairs in url query string format
	 * @param [Array] Array of field names
	 * @return [string] name=value pairs in url query string format
	 */
	formatFieldsQueryString: function(fieldNames) {
		var s = "";
		for (var i = 0, fld; fld = fieldNames[i]; i++)
		{
			fld = fld.trim();
			try
			{
				s += "&f%28" + fld + "%29=" + escape(Lstd.Fields.getValue(fld));
			}
			catch (e)
			{
				console.error(fld + ": " + e);
			}
		}
		return s;
	},
	/**
	* Confirm dialog box
	*/
	showConfirm: function(text) {
		if (confirm(text) == true) return true;
		else return false;
	},
};
/**
 * Manages access to Webroutine values (abstraction wrapper for all TSPs)
 */
Lstd.Webroutine = {
	getContext: function(item) {
		return Lstd.wrContext[item];
	}
};
/**
 * Manages access to field values
 */
Lstd.Fields = {
	getField: function(fieldName) {
		fieldName = fieldName.toUpperCase();;
		var p = $.mobile.activePage, fld = p.find('select[name="' + fieldName + '"],input[name="' + fieldName + '"]');
		if (fld.length > 0) {
			fld = fld.filter("[type=radio],[type=checkbox]");
			if (fld.length == 0) {
				fld = fld.end();
			} else {
				fld = fld.filter(":checked");
			}
		} else {
			if (fld.length == 0) {
				fld = p.find('span[data-lstdfield="' + fieldName + '"]');
			}
		}
		return fld;
	},
	fieldExists: function(fieldName) {
		return (this.getField(fieldName).length > 0);
	},
	getValue: function(fieldName) {
		var field = this.getField(fieldName), retVal = undefined, i, l;
		
		if (field.length > 0) {
			switch (field[0].nodeName) {
				case "SPAN":
					retVal = field.text();
					break;
				case "INPUT":
				{
					switch (field.type) {
						case "radio":
							l = field.length;
							for (i=0; i<l; i++) {
								if (field[i].checked) {retVal = field[i].value;break;}
							}
							break;
						case "checkbox":
							if (field[0].checked) retVal = field[0].value;
							break;
						case "select-one":
						case "select-multiple":
							retVal = field.value;
							break;
						case "button":
						case "reset":
						case "submit":
						case "image":
							break;
						default:
							retVal = field.val();
					}
					break;
				}
				case "SELECT":
					retVal = field.val();
					break;
			}
		}
		return retVal;
	},
	/**
	 * Gets the field or column id from the field name.
	 * @param {string} Field name
	 * @param {string} List row-number context (null or empty string if not available)
	 */
	getOtherFieldID: function(fieldName, xmlColumnId) {
		var a, id="";
		if (fieldName) {
			if (xmlColumnId && xmlColumnId != "") {
				a = xmlColumnId.split(".");
				a[2] = fieldName;
				id = a.join(".");
				if (!this.fieldExists(id)) id = "";
			}
			if (!id) {
				id = this.fieldExists(fieldName) ? fieldName : "";
			}
		}
		return id;
	},
	/**
	 * Resolves extraFields values, when the values come from fields
	 * @param {array} List of fields from the std:multiple_fields_and_values property customizer
	 * @param {string} List row-number context (null or empty string if not available)
	 */
	resolveExtraFields: function(fieldList, xmlColumnId) {
		resFields = [];
		for (var i = 0, fld; fld = fieldList[i]; i++) {
			var extraField = { name: fld.field, value: fld.value };
			if (fld.value === undefined) {
				var fldId = this.getOtherFieldID(fld.valueField, xmlColumnId);
				extraField.value = fldId ? (this.getValue(fldId) || "") : "";
			}
			resFields.push(extraField);
		}
		return resFields;
	},
	/**
	 * Inserts extra fields to post
	 * @param {string} Form element
	 * @param {array} List of fields from the std:multiple_fields_and_values property customizer
	 * @param {string} List row-number context (null or empty string if not available)
	 */
	insertExtraFields: function(f, extraFields, xmlColumnId) {
		var resExtraFields = Lstd.Fields.resolveExtraFields(extraFields, xmlColumnId);
		for (var i = 0, fld; fld = resExtraFields[i]; i++) Lstd.Utils.insertHiddenField(f, fld.name, fld.value);
	}
};
Lstd.Lists = {};

/**
 * Registers JSON lists
 */
Lstd.registerLists = function(lists) {
	if (Lstd.Json) {
		for (var i = 0, cur; cur = lists[i]; i++) {
			try {
				var lst = Lstd.Json.factory(cur);
				Lstd.Lists[lst.name()] = lst;
			}
			catch (e) {
				console.error("Lstd.registerLists() [list index: " + i + "]: " + e);
			}
		}
	}
}

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
 * Manages weblets
 * @namespace
 */
Lstd.Weblets = {
	_weblets: {},
	initDone: false,
	/**
	 * Register a weblet and an optional data object with the framework.
	 * @param {String} id
	 * @param {Object} options
	 * @param {Function} [options.init] A function to call when the DOM is ready.
	 * @param {Object} [data]
	 */
	registerWeblet: function(id, options, data)
	{
		if (id == "") {
			console.error("A weblet must have an ID");
			return;
		}
		if (this._weblets[id] != undefined) 
		{
			console.warn(Lstd.Utils.strargs("Weblet %1 is already registered. Overwriting with new registration.", id));
		}
		this._weblets[id] = {
			id: id,
			options: options,
			data: data || null
		};
	},
	/**
	 * Returns the data object supplied when registering a weblet.
	 * @param {String} id The id of the weblet.
	 * @returns {Object} The data object.
	 */
	getWebletData: function(id)
	{
		var w = this._weblets[id];
		return w ? w.data : null;
	},
	initAll: function() {
		var w, wn, weblets = this._weblets;
		for (wn in weblets) 
		{
			w = weblets[wn];
			try {
				if (w.options.init) w.options.init(w.id, w.data);
			} catch(err) {
				console.error(Lstd.Utils.strargs("Error initialising weblet %1: ", w.id), err)
			}
		}
		this.initDone = true;

		// Lazy load images
		if ($.fn.lazyload) {
			$("img.std_lazy").lazyload({effect: "fadeIn"});
		}
	},
	destroyAll: function() {
		var w, wn, weblets = this._weblets;
		for (wn in weblets) 
		{
			w = weblets[wn];
			try {
				if (w.options.destroy) w.options.destroy(w.id);
			} catch(err) {
				console.error(Lstd.Utils.strargs("Error destroying weblet %1: ", w.id), err)
			}
		}
		this._weblets = {};
		this.initDone = false;
	}
}

/**
 * Provides messaging services
 * @namespace
 */
Lstd.Messaging = 
{
	_listeners: {},
	/**
	 * Register a function to receive messages from the framework. Messages are namespaced
	 * (e.g. webletid.messageid.subitem). A listener can listen to all messages from a 
	 * weblet by registering just the weblet id. A message sender may include extra detail in a
	 * message id and the receiver can choose to filter on that detail.
	 * <br /><br />
	 * When a message is sent the listener function will receive two parameters: the message id
	 * and an optional data object that will contain message specific data.
	 * 
	 * @example
	 * // Listen for changes to #STD_TEXT
	 * Lstd.Messaging.addListener("Weblet1.ValueChanged", myobject.handlerfunc, myobject);
	 * 
	 * // Listen for "showtab" messages from a tab weblet, sent whenever a tab is shown
	 * Lstd.Messaging.addListener("tab1.showtab", myobject.handlerfunc, myobject);
	 * 
	 * // Listen for "showtab" messages from a tab weblet, sent whenever tab 2 is shown
	 * Lstd.Messaging.addListener("tab1.showtab.2", myobject.handlerfunc, myobject);
	 * 
	 * @param {String} messageId The message ID, or partial ID, to listen for.
	 * @param {Function} listenerFunction The function to call to process the message. Avoid using inline functions as these cannot be easily removed later.
	 * @param {Object} [context=window] The context to use when calling the function (i.e. what the "this" keyword will refer to inside the function). The default is the global context.
	 */
	addListener: function(messageId, listenerFunction, context) 
	{
		messageId = messageId.toLowerCase();
		var a = this._listeners[messageId];
		if (a == undefined) a = this._listeners[messageId] = [];
		a.push({
			listener: listenerFunction,
			context: context
		});
	},
	/**
	 * Remove a listener
	 * @param {String} messageId The message the listener is listening for
	 * @param {Function} listenerFunction The listener function to remove
	 */
	removeListener: function(messageId, listenerFunction) 
	{
		messageId = messageId.toLowerCase();
		var a, i, l;
		a = this._listeners[messageId];
		if (a != undefined) 
		{
			for (i = a.length - 1, l; i >= 0; i--) 
			{
				l = a[i];
				if (l.listener === listenerFunction) a.splice(i, 1);
			}
			if (a.length == 0) delete this._listeners[messageId];
		}
	},
	/**
	 * Remove all listeners for a message and, optionally, all decendent messages
	 * @example
	 * // Remove all functions listening for showtab or showtab.1 or showtab.2 (etc) from tab1.
	 * Lstd.Messages.removeAllListeners("tab1.showtab", true);
	 * 
	 * // Remove all functions listening for any message from tab1
	 * Lstd.Messages.removeAllListeners("tab1", true);
	 * 
	 * @param {String} messageId
	 * @param {Boolean} [removeDecendents=false]
	 */
	removeAllListeners: function(messageId, removeDecendents) 
	{
		messageId = messageId.toLowerCase();
		removeDecendents = Boolean(removeDecendents);
		var l = messageId.length, listeners = this._listeners, currentMsgId;
		if (removeDecendents) 
		{
			for (var currentMsgId in listeners) 
			{
				if (currentMsgId.substring(0, l) == messageId) delete listeners[currentMsgId];
			}
		} else 
		{
			delete listeners[messageId];
		}
	},
	/**
	 * Sends a message to all registered listeners
	 * @param {String} messageId
	 * @param {Object} [messageData]
	 * @returns {Boolean} False if any listener returns false, true otherwise.
	 */
	sendMessage: function(messageId, messageData) 
	{
		// MessageId is namespaced. Listeners may be listening for a partial namespace match
		messageId = messageId.toLowerCase();
		var end = messageId.length, msg, a, i, l, r, retVal=true;
		while (end >= 0) 
		{
			msg = messageId.substring(0,end);
			a = this._listeners[msg];
			if (a != undefined) 
			{
				for (i=0, l; l=a[i]; i++) 
				{
					try 
					{
						r = l.listener.call((l.context || window), messageId, messageData);
						if (r === false) retVal = false;
					} catch(e) 
					{
						console.error(Lstd.Utils.strargs("JavaScript error sending message %1.", msg), e);
					}
				}
			}
			end = (end > 0) ? messageId.lastIndexOf(".", end-1) : -1;
		}
		return retVal;
	}
};
/**
 * Manages HTTP Requests for ajax and form posting
 * @namespace
 */
Lstd.HTTP = {
	/**
	 * Represents an HTTP request
	 * @class
	 * @property {String} wam
	 * @property {String} webroutine
	 * @property {String} partition
	 * @property {String} language
	 * @property {String} protocol
	 * @property {String} hostname
	 * @property {String} hostname
	 * @property {String} method
	 * @property {Boolean} cache
	 */
	Request: function() {
		var wrContext = Lstd.wrContext, wrOptions = Lstd.wrOptions;
		this.wam = wrContext["webapplication"];
		this.webroutine = wrContext["webroutine"];
		this.partition = wrContext["partition"];
		this.language = wrContext["language"];
		this.protocol = "";
		this.hostname = "";
		this.document = document;
		this.cache = false;
		this._fields = {
			"_SERVICENAME": wrContext["service-name"],
			"_WEBAPP": wrContext["webapplication"],
			"_WEBROUTINE": wrContext["webroutine"],
			"_PARTITION": wrContext["partition"],
			"_LANGUAGE": wrContext["language"],
			"_LW3TRCID": wrOptions["trace"]
		};
		this._lists = {};
		if (wrContext["session-key-method"] == "hidden") this._fields["_SESSIONKEY"] = wrContext["session-key"];	
		this.method = ((wrContext["session-key-method"] != "hidden") || (wrContext["session-key"] == "")) ? "GET" : "POST";

		this.getURL = function() {
			// Return the url to use (will have fields added to it if this.method == GET
			var url = "", params, fields, fName;
			if ((this.protocol != null) && (this.protocol.length > 0))
			{
				url += this.protocol + "//" + this.hostname;
				if (!this.hostname) {
					url += (this.document || document).location.host;
				}
			}
			url += wrContext["action-request"] + "?";
			
			params = ["wam=" + this.wam, "webrtn=" + this.webroutine,
			"ml=" + wrContext["technology-service"], "part=" + wrContext["partition"], "lang=" + wrContext["language"]];
			
			if ((wrOptions["debug"] != null) && (wrOptions["debug"].length > 0)) params.push("debug=" + wrOptions["debug"]);
			if ((wrContext["session-key-method"] == "url") && (wrContext["session-key"] != "")) params.push("sid=" + wrContext["session-key"]);
			
			if (this.method.toUpperCase() == "GET") {
				fields = this.getFieldsMap();
				for (fName in fields) {
					params.push("f%28" + fName + "%29=" + encodeURIComponent(fields[fName]));
				}
			}
			return url + params.join("&");
		}
		this.getFieldsMap = function() {
			// return a map of fields to be sent with an ajax POST.
			var retVal = {}, name, list, i, row, colName;
			for (name in this._fields) {
				retVal[name] = this._fields[name];
			}
			for (name in this._lists) {
				list = this._lists[name];
				retVal[name + ".."] = list.length;
				for (i=0, row; row=list[i];i++) {
					row = list[i];
					for (colName in row) {
						retVal[[name,(i+1).zeropad(4),colName].join(".")] = row[colName];
					}
				}
			}
			return retVal;
		}
		this.addField = function(name, value) {
			this._fields[name] = value.toString();
		}
		this.addFields = function(fieldMapOrArray) {
			var i, field, fieldName;
			if (fieldMapOrArray.length) {
				for (i=0; i<fieldMapOrArray.length; i++) {
					field = fieldMapOrArray[i];
					if (field) this._fields[field.name] = field.value.toString();
				}
			} else {
				for (fieldName in fieldMapOrArray) {
					this._fields[fieldName] = fieldMapOrArray[fieldName].toString();
				}
			}
		}
		this.addList = function(name, rows) {
			// add a list where rows is an array of maps: [{colname: "value", colname: "value"}, {...}]
			this._lists[name] = rows;
		}
	},
	/**
	* Represents an HTML form used for posting data to the server
	* @class
	* @param {String|Form} The form or or name of the form to post. If a name is supplied and one doesn't exist, it will be created.
	* @param {Object} doc
	*/
	Form: function(theForm, doc) {
		// Returns a modified version of Lstd.HTTP.Request
		var retVal = new Lstd.HTTP.Request();
		retVal.form = null;
		retVal.target = null;
		var formCreated = false;
		
		if (theForm) {
			if ((typeof(theForm) == "string") && (theForm.length > 0)) {
				doc = (doc && doc.forms) ? doc : document;
				retVal.document = doc;
				var f = doc.forms[theForm];
				if (f == null) {
					f = createNamedElement(doc, 'form', theForm);
					f.style.display = "none";
					f.setAttribute("method", "POST");
					formCreated = true;
				}
				retVal.form = f;
			} else if (theForm.submit) {
				retVal.form = theForm;
				retVal.document = theForm.document || theForm.ownerDocument;
			}
		}

		retVal.submitForm = function() {
			// submit (and then restore) the previously prepared form.
			if (this._form == null) return;
			this.method = "POST";
			
			var i, name, colName, list, field, f = this.form, fields = this.getFieldsMap(), done = false;
			for (name in this._fields) {
				Lstd.Utils.insertHiddenField(f, name, fields[name]);
			}
			for (name in this._lists) {
				list = this._lists[name]
				Lstd.Utils.insertHiddenField(f, name + "..", list.length);
				for (i=0, row; row=list[i];i++) {
					row = list[i];
					for (colName in row) {
						Lstd.Utils.insertHiddenField(f,[name,(i+1).zeropad(4),colName].join("."), row[colName]);
					}
				}
				// Now delete any extra rows that may be present from previous actions
				while (!done) {
					for (i=0, row; row=list[i];i++) {
						row = list[i];
						for (colName in row) {
							field = f.elements[colName]
							if (field) {
								field.parentNode.removeChild(field);
							} else {
								done = true;
								break;
							}
						}
						i++;
					}
				}
			}
			
			var backupAction = f.action;
			var backupTarget = f.target;
			f.action = this.getURL();
			f.target = this.target;
			Lstd.Messaging.sendMessage(f.name + ".submit"); // Inform listeners
			f.submit(); // Asynch in Chrome
			setTimeout(function() { 
				if (formCreated) {
					f.parentNode.removeChild(f);
				} else {
					f.action = backupAction;
					f.target = backupTarget;
				}
			}, 100);
		};
		return retVal;
	},
	/**
	* Executes a webroutine
	* @param {Lstd.HTTP.Request} request
	* @param {Function} callback
	*/
	getWebroutine: function(request, callback) {
		jQuery.ajax({
			url: request.getURL(),
			type: request.method,
			cache: request.cache,
			dataType: "json",
			data: (request.method == "POST") ? request.getFieldsMap() : null,
			success: function(data) {
				var wr = (Lstd.Json) ? Lstd.Json.factory(data) : data;
				if (jQuery.isFunction(callback)) callback(wr);
			},
			error: function(xhr, s, e) {
				console.error("JSON response: " + s);
			}
		});
	}
};

Lstd.Weblets.stdAnchor = {
	prepareURL: function(e) {
		var $t = $(this), req = new Lstd.HTTP.Request(), extraFields = $t.data("lansaextrafields");
		req.wam = $t.data("lansawam");
		req.webroutine = $t.data("lansawr");
		if ((req.wam != "") && (req.webroutine != "")) {
			req.method = "GET";
			
			if (extraFields) {
				var fieldToSubmit, fldId, wrFields = Lstd.Fields.resolveExtraFields(extraFields, $t.data("lansaxmlcolumnid"));
			
				req.addFields(wrFields);
			}
			$t.attr("href", req.getURL());
		}
	}
}

Lstd.Weblets.stdDropdown = function () {};

Lstd.Weblets.stdDropdown.prototype.init = function(id, data) {
	var p = $.mobile.activePage, fldId, fieldsToWatch, $elem = this.$elem = p.find(Lstd.Utils.makeSafeId(id));
	
	if (id == "") {
		console.error("A Dropdown weblet must have an ID");
		return;
	}
	this.id = id;
	this.data = data;
	
	if (data.listname) {
		if (data.list === null) {
			data.list = Lstd.Lists[data.listname];
		}
	} else {
		data.codeField = "value";
		data.captionField = "caption";
		data.selectorField = "selector";
	}
	data.updateFieldsToSubmit = data.updateFieldsToSubmit || [];

	if (data.displayMode != "output") {
		$elem.bind("refreshList", this, function(e){
			e.data.refreshList();
		});

		if (data.updateOnFieldChange) {
			fldId = Lstd.Fields.getOtherFieldID(data.updateOnFieldChange, data.xmlColumnId);
			if (fldId) {
				fieldsToWatch = p.find("input#@,select#@".replace(/@/g,Lstd.Utils.escapeForJQSelector(fldId)));
				if (fieldsToWatch.length == 0) {
					fieldsToWatch = p.find("input[name=@],select[name=@]".replace(/@/g,Lstd.Utils.escapeForJQSelector(fldId)));
				}
				fieldsToWatch.change(function(e) {
					$elem.trigger("refreshList");
				});
			}
		}
	}
	this.buildSelect();
	if (data.displayMode != "output") $elem.selectmenu("refresh");
}
Lstd.Weblets.stdDropdown.prototype.buildSelect = function() {
	var $sel = this.$elem, d = this.data, valueList = {}, selectorValue;
	
	if (d.allowMultiSelect && d.multiSelectListname && d.multiSelectCodeField) {
		var list = Lstd.Lists[d.multiSelectListname];
		if (list) {
			list.entries().each(function(entry) {
				valueList[entry.col(d.multiSelectCodeField)] = true;
			});
		}
	} else {
		valueList[d.value] = true;
	}

	if (d.selectorValueField) {
		var fldId = Lstd.Fields.getOtherFieldID(d.selectorValueField, d.xmlColumnId)
		selectorValue = fldId ? (Lstd.Fields.getValue(fldId) || "") : "";
	}
	selectorValue = selectorValue || "";

	if (d.displayMode == "output") {
		$sel.empty();
		if (d.allowMultiSelect && d.multiSelectListname && d.multiSelectCodeField) {
			p = document.createElement("ul");
			p.className = "std_plain";
			d.list.entries().each(function(entry) {
				if (((d.selectorField == "") || (d.selectorValueField == "")) || ( (selectorValue == entry.col(d.selectorField)))) {
					if (valueList[entry.col(d.codeField)]) {
						var li = document.createElement("li");
						li.innerHTML = entry.col(d.captionField);
						p.appendChild(li);
					}
				}
			});
			$sel.append(p);
		} else {
			d.list.entries().each(function(entry) {
				if (((d.selectorField == "") || (d.selectorValueField == "")) || ( (selectorValue == entry.col(d.selectorField)))) {
					if (valueList[entry.col(d.codeField)]) {
						$sel[0].innerHTML = entry.col(d.captionField);
					}
				}
			});
		}
	} else {
		$sel[0].options.length = 0;
		$sel[0].selectedIndex = -1;

		if (d.list) {
			var noValue = (d.value === "");
			d.list.entries().each(function(entry) {
				if (((d.selectorField == "") || (d.selectorValueField == "")) || ( (selectorValue == entry.col(d.selectorField)))) {
					var opt = new Option("", entry.col(d.codeField));
					$sel[0].options[$sel[0].options.length] = opt;
					opt.innerHTML = entry.col(d.captionField);
					if (valueList[entry.col(d.codeField)] || (noValue && entry.col("default"))) opt.setAttribute("selected", "selected");
				}
			});
		}
	}
}
Lstd.Weblets.stdDropdown.prototype.refreshList = function() {
	var d = this.data, wrFields=[], request, self = this, initialVal = this.$elem.val();
	if (d.updateWamName && d.updateWrName) {
		if (d.updateFieldsToSubmit && d.updateFieldsToSubmit.length) {
			for (var i=0,fld; fld=d.updateFieldsToSubmit[i]; i++) {
				fieldToSubmit = { name: fld.field, value: fld.value };
				if (fld.value === undefined) {
					var fldId = Lstd.Fields.getOtherFieldID(fld.valueField, d.xmlColumnId)
					fieldToSubmit.value = fldId ? (Lstd.Fields.getValue(fldId) || "") : "";
				}
				wrFields.push(fieldToSubmit);
			}
		}
		
		this.latestRequest = request = new Lstd.HTTP.Request();
		request.wam = d.updateWamName;
		request.webroutine = d.updateWrName;
		request.protocol = d.updateProtocol;
		request.addFields(wrFields);
		Lstd.HTTP.getWebroutine(request, function(wr) {
			if (self.latestRequest !== request) return;
			d.list = wr.list(d.listname);
			self.buildSelect();
			if (self.$elem.val() != initialVal) self.$elem.change();
		});
	} else {
		this.buildSelect();
		if (self.$elem.val() != initialVal) self.$elem.change();
	}
}


Lstd.Weblets.stdMobiscroll = 
{
	_defaultsSet: false,
	init: function(id, data)
	{
		var $masterField, $proxy, initVal, dt, fmt = "";
		if (!this._defaultsSet) this.setDefaults();
		if (id == "") {
			console.error("A Mobiscroll weblet must have an ID");
			return;
		}
		data.lstdMasterID = id;
		data.lstdProxyID = "__" + id + "_PROXY";
		data.dateFormat = data.dateFormat || this._dateFormat;
		data.timeFormat = data.timeFormat || this._timeFormat;
		data.dateOrder = data.dateOrder || this._dateOrder;
		data.timeWheels = data.timeWheels || this._timeWheels;
		data.stepHour = data.stepHour || 1;
		data.stepMinute = data.stepMinute || 1;
		data.stepSecond = data.stepSecond || 1;
		
		$masterField = jQuery(Lstd.Utils.makeSafeId(id));
		$proxy = jQuery(Lstd.Utils.makeSafeId(data.lstdProxyID));
		$proxy.data("masterFieldId", id).scroller(data);
		
		initVal = $masterField.val();
		if (initVal != "") {
			dt = jQuery.scroller.parseDate(this.getServerFormat($masterField), initVal);
			switch ($masterField.data("lstddatatype")) {
				case "date":
					fmt = data.dateFormat;
					break;
				case "time":
					fmt = data.timeFormat;
					break;
				case "datetime":
					fmt = data.dateFormat + " " + data.timeFormat;
					break;
			}
			$proxy.val($.scroller.formatDate(fmt, dt));
		}
	},
	destroy: function(id) {
		jQuery(Lstd.Utils.makeSafeId("__" + id + "_PROXY")).scroller("hide").scroller("destroy");
	},
	setDefaults: function() {
		var i18n = Lstd.I18n;
		jQuery.scroller.setDefaults({
			cancelText: i18n.getString("mobiscroll-cancelText"),
			setText: i18n.getString("mobiscroll-setText"),
			dayText: i18n.getString("mobiscroll-dayText"),
			monthText: i18n.getString("mobiscroll-monthText"),
			yearText: i18n.getString("mobiscroll-yearText"),
			hourText: i18n.getString("mobiscroll-hourText"),
			minuteText: i18n.getString("mobiscroll-minuteText"),
			secText: i18n.getString("mobiscroll-secText"),
			monthNames: i18n.getArray("MonthsLong"),
			monthNamesShort: i18n.getArray("MonthsShort"),
			dayNames: i18n.getArray("DaysOfWeekSundayStartLong"),
			dayNamesShort: i18n.getArray("DaysOfWeekSundayStartShort"),
			onSelect: this.onSelect
		});
		this._dateFormat = i18n.getString("mobiscroll-dateFormat");
		this._timeFormat = i18n.getString("mobiscroll-timeFormat");
		this._dateOrder = i18n.getString("mobiscroll-dateOrder");
		this._timeWheels = i18n.getString("mobiscroll-timeWheels");
		this._defaultsSet = true;
	},
	getServerFormat: function($masterField) {
		var fmt = "";
		switch ($masterField.data("lstddatatype")) {
			case "date":
				fmt = "yy-mm-dd";
				break;
			case "time":
				fmt = "HH:ii:ss";
				break;
			case "datetime":
				fmt = "yy-mm-ddTHH:ii:ss";
				break;
		}
		return fmt;
	},
	onSelect: function(valueText, inst) {
		var $masterField = jQuery(Lstd.Utils.makeSafeId(inst.settings.lstdMasterID))
		
		$masterField.val(jQuery.scroller.formatDate(Lstd.Weblets.stdMobiscroll.getServerFormat($masterField),  inst.getDate(inst.values)));
	}
};

// std_progressbar

Lstd.Weblets.stdProgressBar = {
	instances: {},
	init: function(id, args) {
		var transitory = args.transitory || false;
		var overlay = args.overlay || false;
		var delayClose = args.delayClose || 0;

		function stdProgressBar(id, args) {
			var $pb = jQuery(Lstd.Utils.makeSafeId(id));
			var $pbo = jQuery(Lstd.Utils.makeSafeId("_" + id + "_OVERLAY"));
			var $pbc = $pb.find("div.lstd-progressbar-content");
			var $pbt = jQuery("<div class=\"lstd-progressbar-text\"></div>");
			var initValue = args.value != undefined ? args.value : 0;
			var maxVal = args.max != undefined ? args.max : 100;

			// Note: Cannot get default string here as i18n strings not loaded yet.
			var captionText = (args.caption != undefined) ? args.caption : null;

			var std_pb = this;
			this.started = false;

			$pbc.css("height", $pb.height());

			var swatch = $pbc.attr("data-theme");
			if (swatch) {
				$pbc.addClass("ui-bar-" + swatch);
			}

			$pbc.appendTo($pb);
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
				console.log("value: " + pct); //FIXME
				if (pct > 100) pct = 100;
				var pcts = (pct < 100) ? pct + "%" : (captionText != null) ? captionText : this.getDefaultCaption();
				$pbc.css("width", pct + "%");
				$pbt.text(pcts);
			};

			/**
			 * Gets default caption now or delays until DOM is ready
			 */
			this.getDefaultCaption = function() {
				try {
					return Lstd.I18n.getString("Complete");
				}
				catch (e) {
					jQuery(function() {
						$pbt.text(Lstd.I18n.getString("Complete"));
					});
					return "";
				}
			};

			/**
			 * Starts the progress bar
			 */
			this.start = function() {
				if (!std_pb.started) {
					std_pb.percentage(initValue);

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
				std_pb.percentage(val);
			};

			if (!transitory) {
				this.start();
			}
			else {
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

// std_loader

Lstd.Weblets.stdLoader = {
	start: function(id) {
		var $div = jQuery(Lstd.Utils.makeSafeId(id));
		var theme = $div.jqmData("theme") || jQuery.mobile.loader.prototype.options.theme;
		var msgText = $div.text();
		var textVisible = $div.jqmData("show-text") || jQuery.mobile.loader.prototype.options.textVisible;
		var textonly = ($div.jqmData("show-icon") == false);

		if (msgText === "") msgText = jQuery.mobile.loader.prototype.options.text;
		jQuery.mobile.loading("show", {text: msgText, textVisible: textVisible, theme: theme, textonly: textonly});
	},

	stop: function() {
		jQuery.mobile.loading("hide");
	}
};
