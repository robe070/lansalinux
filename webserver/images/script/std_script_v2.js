/*!
	(c) 2002, 2013 LANSA
	XHTML Standard Scripts
	$Workfile:: std_script_v2.js            $
	$UTCDate:: 2013-05-01 05:19:38Z         $
	$Revision:: 103                         $
*/

//////////////////////////////////////////////////////////////////////////////////////////
//
// Assorted updates to standard object prototypes
//
//////////////////////////////////////////////////////////////////////////////////////////
if (document.all && !document.getElementById)
{
	document.prototype.getElementById = function(id)
	{
		return document.all[id];
	}
}

// Create a console object that is consistent across browsers - at least consistent enough
// to prevent runtime errors. From http://clubajax.org/examples/consolefix/
(function()
{
	var dbg = window.g_debug || /[?+]debug=(yes|y)/i.test(document.location.href) || false;
	var count = window.loglimit || 299;
	window.loglimit = count;
	if(!window.console) console = {};
	var common = "info,error,log,warn";
	var more = "debug,time,timeEnd,assert,count,trace,dir,dirxml,group,groupEnd,groupCollapsed,exception";
	var fixIE = function(){
		var calls = common.split(",");
		for(var i=0;i<calls.length;i++){
			var m = calls[i];
			var n = "_"+calls[i]
			console[n] = console[m];
			console[m] = (function(){
				var type = n;
				return function(){
					count--;
					if(count == 0) console._log("***LOG LIMIT OF "+loglimit+" HAS BEEN REACHED***");
					if(count < 1) return;
					if (console[type]) console[type](Array.prototype.slice.call(arguments).join(" "));
				}
			})();
		}
		// clear the console on load. This is more than a convenience - too many logs crashes it.
		// (If closed it throws an error)
		try{ console.clear(); }catch(e){}
	}

	var fixMobile = function() {
		// iPad and iPhone use the crappy old Safari debugger.
		var calls = common.split(",");
		for(var i=0;i<calls.length;i++){
			(function(){
				var m = calls[i];
				var n = "_"+calls[i]
				console[n] = console[m];
				console[m] = function(){
					console[n](Array.prototype.slice.call(arguments).join(" "));
				};
			})();
		}
	}

	var hideCalls = function(str) {
		var calls = str.split(",");
		for(var i=0;i<calls.length;i++){
			console[calls[i]] = function(){};
		}
	}

	var tweak = function() {
		var calls = more.split(",");
		for(var i=0;i<calls.length;i++){
			if(!console[calls[i]]) console[calls[i]] = function(){};
		}
	}

	var ua = window.navigator.userAgent;
	if (dbg && /Trident/.test(ua)) {
		fixIE();
		hideCalls(more);
	} else if(dbg && /WebKit|iPad|iPhone/.test(ua)){
		fixMobile();
		tweak();
	} else if((/IE/.test(ua) && !/Trident/.test(ua)) || !dbg || !window.console){ // IE6 or no console
		hideCalls(more+","+common);
	} else {
		tweak();
	}
})();

var debug = function(){ console.log.apply(console, arguments); };
var jslog = {debug:debug,info:debug, warning:debug, error:debug, text: debug};
console.log("JavaScript debugging enabled");

// Return the string padded with leading zeros
String.prototype.zeropad = function(l)
{
	var s = '', i = this.length;
	while (i++ < l) { s += '0'; }
	return s + this;
}

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

String.prototype.ltrim = function() { return this.replace(/^\s+/g, ""); }
String.prototype.rtrim = function() { return this.replace(/\s+$/g, ""); }
String.prototype.trim = function() { return this.replace(/^\s+|\s+$/g, ""); }

// Return the number as a string padded with leading zeros
Number.prototype.zeropad = function(l) { return this.toString().zeropad(l); }
// Return the index of the first array item matching the supplied value
if (!Array.prototype.indexOf)
{
	Array.prototype.indexOf = function(elt /*, from*/)
	{
	var len = this.length;

	var from = Number(arguments[1]) || 0;
	from = (from < 0)
			? Math.ceil(from)
			: Math.floor(from);
	if (from < 0) from += len;

	for (; from < len; from++)
	{
		if (from in this && this[from] === elt) return from;
	}
	return -1;
	};
}
if (!Array.prototype.forEach)
{
	Array.prototype.forEach = function(fun /*, thisp*/)
	{
		var len = this.length;
		if (typeof fun != "function")
		throw new TypeError();

		var thisp = arguments[1];
		for (var i = 0; i < len; i++)
		{
			if (i in this)
			fun.call(thisp, this[i], i, this);
		}
	};
}
// Set the value of the date object to the supplied ISO8601 string
Date.prototype.setISO8601 = function (dateStr) {
	if (dateStr.length == 0)
	{
		this.sqlNull = true;
		return;
	}
	var regexp = /(\d\d\d\d)(?:-?(\d\d)(?:-?(\d\d)(?:[T ](\d\d)(?::?(\d\d)(?::?(\d\d)(?:\.(\d+))?)?)?(?:Z|(?:([-+])(\d\d)(?::?(\d\d))?)?)?)?)?)?/
	var d = dateStr.match(regexp);
	var offset = 0;
	if (!d || !d[1]) { return null; }
	var date = new Date(d[1], 0, 1);
	if (d[2]) { date.setMonth(d[2] - 1); }
	if (d[3]) { date.setDate(d[3]); }
	if (d[4]) { date.setHours(d[4]); }
	if (d[5]) { date.setMinutes(d[5]); }
	if (d[6]) { date.setSeconds(d[6]); }
	if (d[7]) { date.setMilliseconds(Number("0." + d[7]) * 1000); }
	if (d[8]) {
		offset = (Number(d[9]) * 60) + Number(d[10]);
		offset *= ((d[8] == '-') ? 1 : -1);
	}
	// date plus offset = UTC time.  Need to subtract TimezoneOffset to convert to local browser time
	offset -= date.getTimezoneOffset();
	time = (Number(date) + (offset * 60000));
	this.setTime(Number(time));
	this.sqlNull = false;
}
// Returns the date as an ISO8601 string
Date.prototype.toISO8601String = function (includeTime, useLocalTime) {
	if (includeTime == undefined) { var includeTime = true; }
	if (useLocalTime == undefined) { var useLocalTime = true; }
	var date = this;
	var nY = 0, nM = 0, nD = 0, nH = 0, nMin = 0, nS = 0, nMs = 0, nOffset = 0;
	if (useLocalTime) {
		nY = date.getFullYear();
		nM = date.getMonth() + 1;
		nD = date.getDate();
		nH = date.getHours();
		nMin = date.getMinutes();
		nS = date.getSeconds();
		nMs = date.getMilliseconds();
		nOffset = -date.getTimezoneOffset();
	}
	else
	{
		nY = date.getUTCFullYear();
		nM = date.getUTCMonth() + 1;
		nD = date.getUTCDate();
		nH = date.getUTCHours();
		nMin = date.getUTCMinutes();
		nS = date.getUTCSeconds();
		nMs = date.getUTCMilliseconds();
		nOffset = 0;   
	}
	var str = nY + "-" + nM.zeropad(2) + "-" + nD.zeropad(2);
	if (includeTime)
	{
		str += "T" + nH.zeropad(2) + ":" + nMin.zeropad(2) + ":" + nS.zeropad(2);
		if (nMs > 0)
		{
			str += "." + nMs.zeropad(3);
		}
	}
	if (nOffset == 0)
	{
		str += "Z";
	}
	else
	{
		if (nOffset >= 0) { str += "+"; }
		str += Math.round(nOffset / 60).zeropad(2) + ":" + (nOffset % 60).zeropad(2);
	}
	 return str;
}
// Attach the Localised month and date name arrays to the Date object
// Implemented as functions because the arrays are not defined until 
// std_script.messages.js is loaded.
Date.prototype.arrayMstringDays = function () { return stdGetMTextMessageTextArr("DaysOfWeek"); }
Date.prototype.arrayMstringMonths = function() { return stdGetMTextMessageTextArr("Months"); }
// Returns the date as a string formatted according to the supplied format mask.
Date.prototype.toFormattedString = function(f)
{
	var d = this;
	return f.replace(/(YYYY|YY|Y|MMMM|MM|M|DDD|DD|D|HH|H|hh|h|mm|m|sss|ss|s|t)/g,
		function($1)
		{
			switch ($1)
			{
				case 'YYYY': return d.getFullYear();
				case 'YY':   return (d.getFullYear() % 100).zeropad(2);
				case 'MMMM': return d.arrayMstringMonths()[d.getMonth()];
				case 'MM':   return (d.getMonth() + 1).zeropad(2);
				case 'M':    return (d.getMonth() + 1);
				case 'DDD': return d.arrayMstringDays()[(d.getDay()+6) % 7];
				case 'DD':   return d.getDate().zeropad(2);
				case 'D':	 return d.getDate();
				case 'HH':   return d.getHours().zeropad(2);
				case 'H':    return d.getHours();
				case 'hh':   return ((h = d.getHours() % 12) ? h : 12).zeropad(2);
				case 'h':    return ((h = d.getHours() % 12) ? h : 12);
				case 'mm':   return d.getMinutes().zeropad(2);
				case 'm':    return d.getMinutes();
				case 'ss':   return d.getSeconds().zeropad(2);
				case 's':    return d.getSeconds();
				case 'sss':  return d.getMilliseconds().zeropad(3);
				case 't':	 return d.getHours() < 12 ? 'A.M.' : 'P.M.';
			}
		} );
}

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
	var onLoadFunc = function() { Lstd.init(); }
	if (window.jQuery) {
		if (window.g_lweb_jQueryNoConflict) jQuery.noConflict();
		jQuery(document).ready(onLoadFunc);
	} else if (window.addEventListener) {
		window.addEventListener("load", onLoadFunc, false);
	} else if (window.attachEvent) {
		window.attachEvent("onload", onLoadFunc);
	}	
}

/**
 * Initialise the framework
 * @private
 */
Lstd.init = function()
{
	var w, wn, weblets = this.Weblets._weblets;
	for (wn in weblets) 
	{
		w = weblets[wn];
		if (w.options.init) w.options.init(w.id, w.data);
	}

	// Add support for the autofocus attribute to browser that don't support it
	if (!Lstd.Utils.testAttribute("input", "autofocus")) {
		var ae;
		try { ae = document.activeElement; } catch(e) {}
		if ((!ae || ae.nodeName == "BODY")) {
			var focusDone = false;
			for (var i=0, f; f=document.forms[i]; i++) {
				for (var j=0, e; e = f.elements[j]; j++) {
					if (e.getAttribute("autofocus")) {
						try {
							e.focus();
							focusDone = true;
							break;
						} catch (err) {}
					}
				}
				if (focusDone) break;
			}
		}
	}
}

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
	validateFloat: function(senderId, value, size) {
		size = size || 8;
		Lstd.Messaging.sendMessage(senderId + ".ValidationMessage", {
			senderId: senderId,
			value: value,
			error: isNaN(new Number(value)) ? g_StdLocaleMgr.getMessageText("BadFloat") : ""
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
			if (args[nm]) options[nm] = args[nm];
		}
	},
	/**
	 * Returns true if the browser is using the W3C box model. Not valid until after the page has loaded.
	 * @returns {Boolean}
	 */
	boxModel: function() {
		if (window.jQuery) {
			return jQuery.support.boxModel;
		} else if (this._boxModel !== undefined) {
			return this._boxModel;
		} else {
			var div = document.createElement("div");
			div.style.width = div.style.paddingLeft = "1px";
			document.body.appendChild( div );
			this._boxModel = div.offsetWidth === 2;
			document.body.removeChild( div ).style.display = 'none';
			return this._boxModel;
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
		var reg = color.match(/^#([0-9a-fA-F]{3,6})/);
		// Expand shorthand notation: #abc -> #aabbcc
		if (reg) {
			return reg[1].replace(/^([0-9a-fA-F])([0-9a-fA-F])([0-9a-fA-F])$/, "$1$1$2$2$3$3");
		}
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
	 * Adds a script file to the document
	 * @param [string] Element under which to add the script element
	 * @param [string] Script file name (with path)
	 * @param [string] Script file charset
	 */
	addScriptFile: function(location, scriptFile, charset) {
		var script = document.createElement("script");
		script.setAttribute("type", "text/javascript");
		script.setAttribute("src", scriptFile);
		script.setAttribute("charset", charset);
		document.getElementsByTagName(location)[0].appendChild(script);
	},
	/**
	 * Dynamically adds the script files
	 * @param [string] Element under which to add the script element
	 * @param [Array] Array of [scriptFile, charset] pairs
	 */
	qScriptsOnLoad: function(location, scriptFileList) {
		var scriptPath = g_lweb_images_path + "/";
		for (var i = 0, scriptFile; scriptFile = scriptFileList[i]; i++)
		{
			Lstd.Utils.addScriptFile(location, scriptPath + scriptFile[0], scriptFile[1]);
		}
	},
	/**
	 * Dynamically adds the script files when the document completes loading
	 * @param [Array] Array of [scriptFile, charset] pairs
	 */
	qScripts: function(scriptFileList) {
		if (!addEvent(window, "load", function() {Lstd.Utils.qScriptsOnLoad("body", scriptFileList);}))
		{
			Lstd.Utils.qScriptsOnLoad("head", scriptFileList);
		}
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
	 * Adds a list of hidden fields to a form
	 * @param {object} The form
	 * @param [Array] Array of field names
	 */
	addHiddenFields: function(f, fieldNames) {
		for (var i = 0, fld; fld = fieldNames[i]; i++)
		{
			fld = fld.trim();
			try
			{
				insertHiddenField(f, fld, document.getElementById(fld).value);
			}
			catch (e)
			{
				console.error(fld + ": " + e);
			}
		}
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
				s += "&f(" + fld + ")=" + encodeURIComponent(document.getElementById(fld).value);
			}
			catch (e)
			{
				console.error(fld + ": " + e);
			}
		}
		return s;
	},
	/**
	 * Prints the page
	 */
	printPage: function() {
		self.print();
	},
	/**
	 * Confirm dialog box
	 * @param [String] Message text
	 */
	showConfirm: function(text) {
		return confirm(text);
	},
	/**
	 * Alert dialog box
	 * @param [String] Message text
	 * @param [function] Callback function to perform actions when dialog box is closed (optional)
	 * @param [String] Dialog box title (optional)
	 */
	alert: function(text, func, title) {
		if (Lstd.Weblets.dialog && Lstd.Weblets.dialog.alert) {
			Lstd.Weblets.dialog.alert({"text": text, onClose: func, "title": title});
		}
		else {
			window.alert(text);
			if (typeof func == "function") {
				try {
					func();
				}
				catch (e) {
					console.error(e);
				}
			}
		}
	},
	/**
	 * Callback confirm dialog box
	 * @param [String] Message text
	 * @param [function] Callback function to receive boolean result of confirm action
	 * @param [String] confirmation dialog box title (optional)
	 */
	confirm: function(text, func, title) {
		if (Lstd.Weblets.dialog && Lstd.Weblets.dialog.confirm) {
			Lstd.Weblets.dialog.confirm({"text": text, confirmCallback: func, "title": title});
		}
		else {
			if (typeof func == "function") {
				try {
					func(window.confirm(text));
				}
				catch (e) {
					window.alert(e);
				}
			}
		}
	},
	/**
	 * Tests if the current browser supports a particular attribute on a particular element
	 * @param {String} The element to test
	 * @param {String} The attribute to test
	 * @return {Boolean}
	 */
	testAttribute: function(element, attribute) {
		var e = document.createElement(element);
		return (attribute in e) ? true : false;
	},
	/**
	 * List id regex match
	 */
	listIDRegExp: new RegExp(/(^[A-Za-z].*)\.(\d{4})\.([A-Za-z].*)/),
	/**
	 * List id regex match test
	 * @param [String] id
	 * @returns [boolean] True if the id matches the pattern for a list entry
	 */
	 isListID: function(id) {
		return Lstd.Utils.listIDRegExp.test(id);
	},
	/**
	 * Returns an XMLHttpRequest
	 * @returns {Object} XMLHttpRequest
	 */
	XMLHttpRequest: function() {
		if (window.XMLHttpRequest) {
			return new XMLHttpRequest();
		}
		else {
			try {
				return new ActiveXObject("Microsoft.XMLHTTP");
			}
			catch (e) {
				alert(window.g_StdLocaleMgr ? window.g_StdLocaleMgr.getMessageText("NoXMLHttpRequest") : "No XMLHttpRequest");
			}
		}
		return null;
	},
	/**
	 * Gets a file from the server
	 * @returns {string} True if successful, false otherwise
	 */
	getJSONData: function(f) {
		var xmlhttp = Lstd.Utils.XMLHttpRequest();
		xmlhttp.open("GET", f, false);
		try {
			xmlhttp.send();
			return (xmlhttp.status == 200) ? xmlhttp.responseText : "";
		}
		catch (e) {
			return "";
		}		
	},
	/**
	 * Parses a JSON string. Uses the JSON object if available, otherwise uses eval.
	 * @param [String] JSON string
	 * @returns Object or array
	 */
	parseJSON: function(data) {
		try {
			if ((typeof(JSON) !== 'undefined') && (typeof(JSON.parse) === 'function')) return JSON.parse(data);
			else {
				return eval('(' + data + ')');
			}
		}
		catch(e) {
			alert(e);
			console.error("Lstd.Utils.parseJSON: " + e);
			return null;
		}
	},
	/**
	 * Checks if textarea content is empty or LF/CRLF
	 * @param [string] textarea value
	 * @return [boolean] True if empty, false otherwise
	 */
	isTextAreaEmpty: function(val) {
		if (!val) return true;
		var len = val.length;
		if (val == 0) return true;
		if ((len == 1) && (val.charCodeAt(0) == 10)) return true;

		// handles IE8 and Safari
		if ((len == 2) && ((val.charCodeAt(0) == 13) || (val.charCodeAt(0) == 10)) && (val.charCodeAt(1) == 10)) return true;
		return false;
	}
};

/**
 * @namespace
 * Contains assorted utilities
 */
Lstd.I18n = {
	 /**
	  * Message strings
	  */
	 _strings: {},
	 /**
	  * Message arrays
	  */
	 _arrays: {},
	/**
	 * Returns the base language given the composite IANA language-qualifier code
	 * @param {string} isoLang The qualified language code (for example: en-US)
	 * @returns {string} The base language
	 */
	 baseISOLang: function(isoLang) {
		try {
			return isoLang.split('-')[0];
		}
		catch (e) {
			console.error("Lstd.I18n.baseISOLang(): " + e);
			return "";
		}
	 },
	 /**
	  * Merge language message strings and arrays
	  * @param {object} Target I18N strings and arrays
	  * @param {object} Source I18N strings and arrays
	  */
	mergeMessages: function(tgt, src) {
		if (src.strings) {
			var srcS = src.strings, tgtS = tgt.strings;
			for (x in srcS) { tgtS[x] = srcS[x]; }
		}
		if (src.arrays) {
			var srcA = src.arrays, tgtA = tgt.arrays;
			for (y in srcA) { tgtA[y] = srcA[y]; }
		}
	}
};

/**
 * Loads the language script messages file.
 * Loads "en" first. Then override with base ISO language (if available)
 * and then the language-country file (if available)
 */
(function() {
	var path = g_lweb_images_path + "/script/i18n/lansa_xhtml/std_messages-%1.json";
	var f = Lstd.Utils.strargs(path, "en");

	try {
		var langO = Lstd.Utils.parseJSON(Lstd.Utils.getJSONData(f));
		var baseLang = Lstd.I18n.baseISOLang(g_lxmlISOLang);

		if (baseLang !== "en") {
			f = Lstd.Utils.strargs(path, baseLang);
			var baseLangS = Lstd.Utils.getJSONData(f);
			if (baseLangS !== "") {
				var deltaO = Lstd.Utils.parseJSON(baseLangS);
				Lstd.I18n.mergeMessages(langO, deltaO);
			}
		}
		if (g_lxmlISOLang !== baseLang) {
			f = Lstd.Utils.strargs(path, g_lxmlISOLang);
			var langS = Lstd.Utils.getJSONData(f);			
			if (langS !== "") {
				deltaO = Lstd.Utils.parseJSON(langS);
				Lstd.I18n.mergeMessages(langO, deltaO);
			}
		}
		Lstd.I18n._strings = langO.strings;
		Lstd.I18n._arrays = langO.arrays;
	}
	catch (e) {
		console.error("Failed to load " + f);
	}
	new StdLocaleMgr();
})();

/**
 * Manages access to Webroutine values (abstraction wrapper for all TSPs)
 */
Lstd.Webroutine = {
	getContext: function(item) {
		switch (item) {
			case "action-request": return g_lxmlAR;
			case "images-path": return g_lweb_images_path;
			case "iso-lang": return g_lxmlISOLang;
			case "language": return g_lxmlLang;
			case "partition": return g_lxmlPartition;
			case "service-name": return g_lxmlServiceName;
			case "session-key": return g_lxmlSK;
			case "session-key-name": return "_SESSIONKEY";
			case "session-key-method": return g_lmxlSKMethod;
			case "technology-service": return g_lxmlTs;
			case "webapplication": return g_lxmlWAMName;
			case "webroutine": return g_lxmlWAMName;
			default: return null;
		}
	}
};

/**
 * Manages access to field values
 */
Lstd.Fields = {
	fieldExists: function(fieldName) {
		var i, l, f = document.forms["LANSA"];
		fieldName = fieldName.toUpperCase();
		if (f && f.elements[fieldName]) {
			return true;
		} else {
			l = document.forms.length;
			for (i=0; i<l; i++) {
				if (document.forms[i].elements[fieldName]) return true;
			}
		}
		return document.getElementById("Lstd.Fields." + fieldName) ? true : false;
	},
	getInitialValue: function(fieldName) {
		fieldName = fieldName.toUpperCase();
		var span = document.getElementById("Lstd.Fields." + fieldName);
		return (span) ? span.textContent || span.innerText || "" : undefined;
	},
	getFormValue: function(fieldName) {
		var i, l, field, f = document.forms["LANSA"];
		fieldName = fieldName.toUpperCase();
		if (f && f.elements[fieldName]) {
			field = f.elements[fieldName];
		} else {
			l = document.forms.length;
			for (i=0; i<l; i++) {
				field = document.forms[i].elements[fieldName];
				if (field) break;
			}
		}
		if (field) {
			switch (field.type) {
				case "radio":
					l = field.length;
					for (i=0; i<l; i++) {
						if (field[i].checked) return field.value;
					}
					return "";
				case "checkbox":
					return field.checked ? field.value : "";
					break;
				case "select-one":
				case "select-multiple":
					return field.value;
					break;
				case "button":
				case "reset":
				case "submit":
				case "image":
					break;
				default:
					return field.value;
			}
		}		
		return undefined;
	},
	getValue: function(fieldName) {
		var val = Lstd.Fields.getFormValue(fieldName);
		return (val != undefined) ? val : Lstd.Fields.getInitialValue(fieldName);
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
				if (!Lstd.Fields.fieldExists(id)) id = "";
			}
			if (!id) {
				id = Lstd.Fields.fieldExists(fieldName) ? fieldName : "";
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
				var fldId = Lstd.Fields.getOtherFieldID(fld.valueField, xmlColumnId);
				extraField.value = fldId ? (Lstd.Fields.getValue(fldId) || "") : "";
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
		for (var i = 0, fld; fld = resExtraFields[i]; i++) insertHiddenField(f, fld.name, fld.value);
	},
	/**
	 * Checks for special VLF attribute VF_WAMEVENT
	 * @param {string} Form element
	 * @param {object} DOM element
	 */
	check4VF_WAMEVENT: function(f, elem) {
		var vf_wamevent = elem.getAttribute("data-vf-wamevent");
		if (vf_wamevent) {
			insertHiddenField(f, "VF_WAMEVENT", vf_wamevent);
		}
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
 * Manages weblets
 * @namespace
 */
Lstd.Weblets = {
	_weblets: {},
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
		this.wam = g_lxmlWAMName;
		this.webroutine = g_lxmlWRName;
		this.partition = g_lxmlPartition;
		this.language = g_lxmlLang;
		this.protocol = "";
		this.hostname = "";
		this.document = document;
		this.cache = false;
		this._fields = {
			"_SERVICENAME": g_lxmlServiceName,
			"_WEBAPP": g_lxmlWAMName,
			"_WEBROUTINE": g_lxmlWRName,
			"_PARTITION": g_lxmlPartition,
			"_LANGUAGE": g_lxmlLang,
			"_LW3TRCID": g_lw3Trace
		};
		this._lists = {};
		if (g_lmxlSKMethod == "hidden") this._fields["_SESSIONKEY"] = g_lxmlSK;	
		this.method = ((g_lmxlSKMethod != "hidden") || (g_lxmlSK == "")) ? "GET" : "POST";

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
			url += g_lxmlAR + "?";
			
			params = ["wam=" + this.wam, "webrtn=" + this.webroutine,
			"ml=" + g_lxmlTs, "part=" + g_lxmlPartition, "lang=" + g_lxmlLang];
			
			if ((g_debug != null) && (g_debug.length > 0)) params.push("debug=" + g_debug);
			if ((g_lmxlSKMethod == "url") && (g_lxmlSK != "")) params.push("sid=" + g_lxmlSK);
			
			if (this.method.toUpperCase() == "GET") {
				fields = this.getFieldsMap();
				for (fName in fields) {
					params.push("f(" + fName + ")=" + encodeURIComponent(fields[fName]));
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
				insertHiddenField(f, name, fields[name]);
			}
			for (name in this._lists) {
				list = this._lists[name]
				insertHiddenField(f, name + "..", list.length);
				for (i=0, row; row=list[i];i++) {
					row = list[i];
					for (colName in row) {
						insertHiddenField(f,[name,(i+1).zeropad(4),colName].join("."), row[colName]);
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

//////////////////////////////////////////////////////////////////////////////////////////
//
// Assorted utility functions
//
//////////////////////////////////////////////////////////////////////////////////////////
function trapError(errorMsg, url, line)
{
	console.error(errorMsg + "\n" + url + ", line " + line);
	return true;
}
function getParentForm(formElement)
{
	var f = null;
	try
	{
		f = formElement.form;
	}
	catch(ex)
	{
		f = null;
	}
	if( f == null )
	{
		f = getParentElement(formElement, "form");
	}
	return f;
}
function getParentElement(child, parentTagName) {
	var e = child.parentNode;
	var tn = parentTagName.toUpperCase();
	while (e)
	{
		if (e.nodeName == tn)
		{
			return e;
		}
		else
		{
			e = e.parentNode;
		}
	}
	return null;
}
function getRelativeMouseX(relTo, evt)
{
	var mouseX = 0;
	if (evt.pageX)
	{
		mouseX = evt.pageX;
	}
	else if (evt.clientX)
	{
		mouseX = evt.clientX + document.body.scrollLeft;
	}
	mouseX -= getAbsoluteLeft(relTo);
	return mouseX;
}
function getRelativeMouseY(relTo, evt) {
	var mouseY = 0;
	if (evt.pageY)
	{
		mouseY = evt.pageY;
	}
	else if (evt.clientY)
	{
		mouseY = evt.clientY + document.body.scrollTop;
	}
	mouseY -= getAbsoluteTop(relTo);
	return mouseY;
}
function getCorrectedOffsetTop(obj)
{
	// offsetTop returns a value relative to the scrolled top of the offsetParent.
	// We need subtract the scroll amount of the offsetParent to get a value
	// relative to the visible top
	var ot = obj.offsetTop;
	var op = obj.offsetParent;
	if (op && op.scrollTop) ot -= op.scrollTop;
	// scrollTop in non IE browsers is relative to the parentNode.  So we need
	// to add up the values for every parent node up to the offsetParent.
	// IE automatically makes anything with size and scroll values a positioned
	// object and part of the offsetParent tree so these scrollTops will all be 0.
	if (!op) return ot;
	var p = obj.parentNode;
	while (p != op)
	{
		if (p.scrollTop)
		{
			// Opera has a bug where it sometimes returns the offsetTop in scrollTop
			// (but only when it should be zero)
			if (!window.opera || (p.scrollTop != p.offsetTop)) ot -= p.scrollTop;
		}
		p = p.parentNode;
	}
	return ot;
}
function getCorrectedOffsetLeft(obj)
{
	// See comments in getCorrectedOffsetTop for details of what this function is doing.
	var ol = obj.offsetLeft;
	var op = obj.offsetParent;
	if (op && op.scrollLeft) ol -= op.scrollLeft;
	var p = obj.parentNode;
	if (!op) return ol;
	while (p != op)
	{
		if (p.scrollLeft)
		{
			if (!window.opera || (p.scrollLeft != p.offsetLeft)) ol -= p.scrollLeft;
		}
		p = p.parentNode;
	}
	return ol;
}
function getAbsoluteTop(obj) {
	var top = getCorrectedOffsetTop(obj);
	while (obj = obj.offsetParent)
	{
		top += getCorrectedOffsetTop(obj);
	}
	top += document.body.scrollTop;
	return top;
}
function getAbsoluteLeft(obj) {
	var left = getCorrectedOffsetLeft(obj);
	while (obj = obj.offsetParent)
	{
		left += getCorrectedOffsetLeft(obj);
	}
	left += document.body.scrollLeft;
	return left;
}
function getCurrentStyle(el,styleProp)
{
	var x = (typeof el == 'string') ? document.getElementById(el) : el;
	var y = null;
	if (x.currentStyle)
		y = x.currentStyle[styleProp.replace( /(-)([a-z])/g, function(t,a,b) { return b.toUpperCase(); } )];
	else if (window.getComputedStyle)
	{
		try {
			y = document.defaultView.getComputedStyle(x,null).getPropertyValue(styleProp);
		} catch (e) {}
	}
	return y;
}
function getElementsByClassAndTag(parent, theClass, theTag)
{
	if (!parent) parent = document;
	if (!theTag) theTag = "*";
	var all = !theClass;
	var tags = parent.getElementsByTagName(theTag);
	var a = new Array();
	for (var i=0, t; t = tags[i]; i++)
	{
		if (all || (t.className == theClass)) a[a.length] = t;
	}
	return a;
}
function addEvent(obj, type, fn, useCapture)
{
	if (!useCapture) useCapture = false;
	if (obj)
	{
		if (obj.addEventListener)
		{
			obj.addEventListener( type, fn, useCapture );
			return true;
		}
		else if (obj.attachEvent)
		{
			obj["e"+type+fn] = fn;
			obj[type+fn] = function() { obj["e"+type+fn]( window.event ); }
			obj.attachEvent( "on"+type, obj[type+fn] );
			return true;
		}
		return false;
	}
	return false;
}
function removeEvent(obj, type, fn)
{
	if (obj.removeEventListener)
		obj.removeEventListener( type, fn, false );
	else if (obj.detachEvent)
	{
		if (obj[type+fn]) obj.detachEvent( "on"+type, obj[type+fn] );
		obj[type+fn] = null;
		obj["e"+type+fn] = null;
	}
}
function cancelEvent(e)
{
    e.cancelBubble = true; // for IE
    if (typeof e.stopPropagation == 'function')
        e.stopPropagation();

    e.returnValue = false; // for IE
    if (typeof e.preventDefault == 'function')
        e.preventDefault();
}
function addCSSRule(theSS, theSelector, theRule)
{
	// Must add to internal stylesheet. If external provided, override it
	var ss = null;
	if (theSS.ownerNode)
	{
		ss = (theSS.ownerNode instanceof HTMLStyleElement) ? theSS : get1stStyleElement();
	}
	else if (theSS.owningElement)
	{
		ss = (theSS.owningElement.nodeName == "STYLE") ? theSS : get1stStyleElement();
	}
	addCSSRuleN(ss, theSelector, theRule);
}
function addCSSRuleN(theSS, theSelector, theRule)
{
	if (theSS.insertRule)
	{
		theSS.insertRule( theSelector + ' {' + theRule + '}', theSS.cssRules.length);
	}
	else if (theSS.addRule)
	{
		theSS.addRule(theSelector, theRule);
	}
}
function get1stStyleElement()
{
	if (document.styleSheets.length)
	{
		if (document.styleSheets[0].ownerNode)
		{
			for (var i = 0, ss; ss = document.styleSheets[i]; i++)
			{
				if (ss.ownerNode instanceof HTMLStyleElement) return ss;
			}
		}
		else if (document.styleSheets[0].owningElement)
		{
			for (var i = 0, ss; ss = document.styleSheets[i]; i++)
			{
				if (ss.owningElement.nodeName == "STYLE") return ss;
			}
		}
		return null;
	}
}
function createNamedElement(doc, type, name) {
	var element = null;
	// The DOM way of creating named elements (form, input) doesn't work properly
	// in IE - it doesn't add it to the appropriate forms or elements collections properly.
	// Try the IE way; this fails on standards-compliant browsers
	try {
		element = doc.createElement('<'+type+' name="'+name+'">');
	} catch (e) {
	}
	if (!element || element.nodeName != type.toUpperCase()) {
		// Non-IE browser; use canonical method to create named element
		element = doc.createElement(type);
		element.name = name;
	}
	return element;
}
function stdFindForm(doc, formName)
{
	return (formName && formName.length > 0) ? doc.forms[formName] : null;
}
function createStdHiddenForm(WAMName, WRName, formName, protocol, target, optDocument)
{
	var doc = (optDocument) ? optDocument : document;
	f = stdFindForm(doc, formName);

	if (f == null)
	{
		f = createNamedElement(doc, 'form', formName);
		var action = stdFormatHttpRequest(null, WAMName, WRName, protocol);
		f.setAttribute("action", action);
		f.style.display = "none";
		f.setAttribute("method", "POST");
		insertHiddenField(f, "_SERVICENAME", g_lxmlServiceName);
		insertHiddenField(f, "_WEBAPP", g_lxmlWAMName);
		insertHiddenField(f, "_WEBROUTINE", g_lxmlWRName);
		insertHiddenField(f, "_PARTITION", g_lxmlPartition);
		insertHiddenField(f, "_LANGUAGE", g_lxmlLang);
		
		if (g_lmxlSKMethod == "hidden") insertHiddenField(f, "_SESSIONKEY", g_lxmlSK);
		insertHiddenField(f, "_LW3TRCID", g_lw3Trace);
		f.target = (target) ? target : "";
		doc.body.appendChild(f);
	}
	return f;
}
// Convert the value property of input elements to upper or lower case as required.
function toValueCase(theObj)
{
	var value = theObj.value;
	var textTransform = getCurrentStyle(theObj, "text-transform");
	if (textTransform == "uppercase") value = value.toUpperCase();
	else if (textTransform == "lowercase") value = value.toLowerCase();
	if (theObj.value != value)
	{
		theObj.value = value;
		if (theObj.id != "") stdSetElementValue(theObj.id, value, true); // Workaround IE bug
	}
}
function insertHiddenField(form, fieldName, fieldValue)
{
	if( form == null ) return null;
	if (!fieldName) return null;
	if (!fieldValue) fieldValue = "";
	var field = form.elements[fieldName];
	if (field == null)
	{
		field = createNamedElement(form.ownerDocument, 'input', fieldName);
		field.setAttribute("type", "hidden");
		field.setAttribute("value", fieldValue);
		form.appendChild(field);
	}
	else
	{
		field.value = fieldValue;
	}
	return field;
}
function stdFormatHttpRequest(theForm, WAM, WebRoutine, optProtocol, optFields, optTimestamp)
{
	var action = "";
	if ((optProtocol != null) && (optProtocol.length > 0))
	{
		action += optProtocol;
		// If protocol is specified then we need to build a complete URL
		// If the protocol contains "//" assume the hostname is included as well
		// (this must be here for historical reasons)
		if (optProtocol.search(new RegExp("//", "g")) < 0) {
			var doc = theForm ? (theForm.document || theForm.ownerDocument) : document;
			action += "//" + doc.location.host;
		}
	}
	action += g_lxmlAR + "?wam=" + WAM + "&webrtn=" + WebRoutine + "&ml=" + g_lxmlTs + "&part=" + g_lxmlPartition + "&lang=" + g_lxmlLang;
	if ((g_debug != null) && (g_debug.length > 0)) action += "&debug=" + g_debug;
	if ((g_lmxlSKMethod == "url") && (g_lxmlSK != "")) action += "&sid=" + g_lxmlSK;
	if (optFields && optFields.length)
	{
		for (var i = 0, fld; fld = optFields[i]; i++) action += "&f(" + fld.name + ")=" + encodeURIComponent(fld.value);
	}
	if ((optTimestamp != null) && (optTimestamp === true)) action += "&_=" + (new Date()).getTime();
	if (location.href.match(/\?.*enablejslog/)) action += "&enablejslog";
	return action;
}
function submitForm(theForm, WAM, WebRoutine, optTarget, optProtocol, optFields)
{
	/* WARNING: If this function is being changed please notify the VLF team     */
	/* They may need to make a parallel change to functions in file VF_SY503.JS  */
	var action="";
	var backupAction = theForm.action;
	var backupTarget = theForm.target;
	theForm.action = stdFormatHttpRequest(theForm, WAM, WebRoutine, optProtocol, optFields);
	theForm.target = (optTarget) ? optTarget : "";
	Lstd.Messaging.sendMessage(theForm.name + ".submit"); // Inform listeners
	theForm.submit(); // Asynch in Chrome
	setTimeout(function() { theForm.action = backupAction; theForm.target = backupTarget; }, 100);
}
function getHiddenSpanContent(spansParent, spanClass)
{
	var spans = spansParent.getElementsByTagName('span');
	for (var i=0, s; s=spans[i]; i++)
	{
		if (s.className == spanClass) return s.innerHTML.replace(/(<!---->)$/, "");
	}
	return "";
}
function findReentryFields(f, spansParent, callback)
{
	var spans = spansParent.getElementsByTagName('span');
	var reentryField = null;
	var reentryValue = null;
	for (var i = 0, s; s = spans[i]; i++)
	{
		if (s.className == "reentryfield") reentryField = s.innerHTML.replace(/(<!---->)$/, "");
		if (s.className == "reentryvalue") reentryValue = s.innerHTML.replace(/(<!---->)$/, "");
		if (reentryField && (reentryValue != null)) // Allow empty value
		{
			// callback must match insertHiddenField() signature
			callback(f, reentryField, reentryValue);
			reentryField = null;
			reentryValue = null;
		}
	}
}
function createReentryFields(f, spansParent)
{
	if ((f != null) && (spansParent != null)) findReentryFields(f, spansParent, insertHiddenField);
}
function isDblClick(elem)
{
	var t = new Date().getTime();
	if ((elem.__lastClickedTime) && ((t - elem.__lastClickedTime) < 1000))
	{
		return true;
	}
	elem.__lastClickedTime = t;
	return false;
}
function isValidNumber(theObj, length, decimals, decimalPoint)
{
	return g_checkNumeric ? _isValidNumber(theObj, length, decimals, decimalPoint) : true;
}
function stdFieldOnChangeHandler(fld) {
	switch (fld.getAttribute("__FormatType"))
	{
		case 'alpha':
		case 'char':
		case 'varchar':
			return isValidText(fld, fld.getAttribute("__KeyboardShift"));
		case "dec":
		case 'packed':
		case 'signed':
			return isValidNumber(fld, fld.getAttribute("__TotalDigits"), fld.getAttribute("__FractionDigits"), fld.getAttribute("__DecimalSeparator"))
		case 'integer':
			return isValidInteger(fld, fld.getAttribute("__MaxLength"))
		case 'float':
			return isValidFloat(fld, fld.getAttribute("__MaxLength"));
		case 'date':
			return isValidDate(fld);
		case 'time':
			return isValidTime(fld);
		case 'datetime':
			return isValidDateTime(fld, fld.getAttribute("__MaxLength"));
		case 'boolean':
			return isValidBoolean(fld);
	}
	return true;
}
function stdStrFieldKeyPress(fld, maxlen)
{
	// We have to let the keypress take effect before testing the field
	// because the key may be delete or there may be a selection being replaced
	var prevValue = fld.value;
	if (fld.setSelectionRange)
	{
		var ss = fld.selectionStart;
		var se = fld.selectionEnd;
		window.setTimeout(function() { if (fld.value.length > maxlen)
					{
						fld.value = prevValue;
						window.alert(g_StdLocaleMgr.getMessageText("BadLength1"));
						fld.setSelectionRange(ss, se);
					} }, 1);
	} else if (fld.createTextRange) {
		var range = fld.createTextRange();	
		window.setTimeout(function() { if (fld.value.length > maxlen)
					{
						fld.value = prevValue;
						window.alert(g_StdLocaleMgr.getMessageText("BadLength1"));
						range.select();
					} }, 1);
	}
	return true;
}
function getEventTarget(e)
{
	var targ = null;
	if (e.target) targ = e.target;
	else if (e.srcElement) targ = e.srcElement;
	if (targ.nodeType == 3) targ = targ.parentNode; // defeat Safari bug
	return targ;
}
function stdOnFocus(e)
{
	if(!e) { if( window.event ) { e = window.event; } else { return; } }
	var targ = getEventTarget(e);
	if (targ) targ.className += " focus";
}
function stdOnBlur(e)
{
	if(!e) { if( window.event ) { e = window.event; } else { return; } }
	var targ = getEventTarget(e);
	if (targ) targ.className = targ.className.replace(/\b ?focus\b/, "");
}
function LANSAObjectStore()
{
	this.objects = new Object();
	this.types = new Object();
	
	this.addObject = function(obj, type, id)
	{
		this.objects[id] = obj;
		if (type)
		{
			if (!this.types[type]) this.types[type] = new Array();
			this.types[type][this.types[type].length] = obj;
		}
	}
	this.getObjectById = function(id)
	{
		return this.objects[id];
	}
	this.getObjectsByType = function(type)
	{
		return this.types[type];
	}
	this.typeExists = function(type)
	{
		return Boolean(this.types[type]);
	}
}
var g_LANSAObjects = new LANSAObjectStore();

function lansaEvent_RegisterListener(parentElement, evtName, evtHandler)
{
	evtName = evtName.toLowerCase();
	var p = parentElement;
	while( p != null )
	{
		if (p.getAttribute && p.getAttribute(evtName) && (p.getAttribute(evtName) == "true")) p[evtName] = new Array();
		var handlerArray = p[evtName];
		if (handlerArray  && (handlerArray instanceof Array))
		{
			handlerArray.push(evtHandler)
			return true;
		}
		p = p.parentNode
	}
	return false;
}
function lansaEvent_Fire(element, evtName)
{
	evtName = evtName.toLowerCase();
	var handlerArray = element[evtName];
	if (handlerArray  && (handlerArray instanceof Array))
	{
		var evtArgs = new Array();
		for (var i=2; i < arguments.length; i++) evtArgs.push(arguments[i]);
		for (var i=0, func; func=handlerArray[i]; i++)
		{
			func.apply(element, evtArgs);
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////
//
// JavaScript support for std_messages weblet
//
//////////////////////////////////////////////////////////////////////////////////////////
function stdTransferMessages(targetWindowName, msgElemId)
{
	if (msgElemId == null || msgElemId.length <= 0 ) return;
	if (targetWindowName == null || targetWindowName.length == 0) targetWindowName = "_self";
	
	var targetWindow = null;
	switch (targetWindowName)
	{
		case "_top":
			targetWindow = window.top;
			break;
		case "_self":
			targetWindow = window;
			break;
		case "_blank":
		case "_media":
		case "_search":
			return;
		case "_parent":
			targetWindow = window.parent;
			break;
		default:
			var w = window;
			do
			{
				frames = w.document.getElementsByTagName("frame");
				for (var i=0, f; f=frames[i]; i++)
				{
					if (f.name == targetWindowName)
					{
						targetWindow = f;
						break;
					}
				}
				w = w.parent;
			} while (w != w.parent || targetWindow == null)
	}
	if (targetWindow != null)
	{
		var srcElem = document.getElementById(msgElemId);
		var tgtElem = targetWindow.document.getElementById(msgElemId);
		if (srcElem && tgtElem && (srcElem != tgtElem))
		{
			var html = srcElem.innerHTML;
			tgtElem.innerHTML = html;
			tgtElem.style.display = "";
		}

		// Localize messages label
		var msgLabel = targetWindow.document.getElementById("__std_x_message_label");
		if (msgLabel != null) msgLabel.innerHTML = window.g_StdLocaleMgr.getMessageText("Messages");
	}
}
/**
 * Mark-up weblet
 */
Lstd.Weblets.stdMarkup = {
	init: function(markupID, markupData) {
		var div = document.getElementById(markupID);
		if (div)
		{
			// Check for empty or new-line-only content
			if (Lstd.Utils.isTextAreaEmpty(Lstd.Fields.getFormValue(markupID)))
			{
				if (Lstd.Utils.isListID(markupID))
				{
					var $div = jQuery(div);
					var td = $div.closest("td[__cellvalue]");
					var cellvalue = td ? td.attr("__cellvalue") : undefined;
					if (cellvalue != undefined) div.innerHTML = cellvalue;
				}
				else
				{
					div.innerHTML = Lstd.Fields.getInitialValue(markupID);
				}
			}
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////
//
// Javascript support for std_menu_item
//
/////////////////////////////////////////////////////////////////////////////////////////
function stdMenuItemClicked(e, menuItem, WAMName, WRName, formName, protocol, target)
{
	return stdAnchorClicked(e, menuItem, WAMName, WRName, formName, protocol, target, null, null)
}
Lstd.Weblets.stdMenuItem = {
	init: function(menuItemID, menuItemData) {
		if (window.jQuery) {
			var $elem = jQuery(Lstd.Utils.makeSafeId(menuItemID));
			
			$elem.addClass(menuItemData.selected ? "ui-state-highlight" : "ui-state-default");
			if (menuItemData.selected) {
				$elem.addClass("ui-state-highlight");
			} else {
				$elem.addClass("ui-state-default").hover(function() {
					jQuery(this).addClass("ui-state-hover");
				}, function() {
					jQuery(this).removeClass("ui-state-hover");
				}).mousedown(function() {
					jQuery(this).addClass("ui-state-active");
				}).mouseup(function() {
					jQuery(this).removeClass("ui-state-active");
				});
			}
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////
//
// Javascript support for image mouseovers
//
//////////////////////////////////////////////////////////////////////////////////////////
function stdImageMouseOver(theImg)
{
	var newSrc = theImg.getAttribute("__moImage");
	var oldSrc = theImg.getAttribute("__stdImage");
	if ((newSrc) && (!oldSrc))
	{
		theImg.setAttribute("__stdImage", theImg.src);
		theImg.src = newSrc;
	}
}
function stdImageMouseOut(theImg)
{
	var oldSrc = theImg.getAttribute("__stdImage");
	if (oldSrc)
	{
		theImg.src = oldSrc;
		theImg.setAttribute("__stdImage", "");
	}
}
function stdImagePreloadMO(theImg)
{
	var src = theImg.getAttribute("__moImage");
	if (src && src != "")
	{
		var img = new Image();
		img.src = src;
	}
}
function preloadStdImageMouseOvers()
{
	var images = document.getElementsByTagName("IMG");
	for(var i=0, img; img=images[i]; i++)
	{
		stdImagePreloadMO(img);
	}
}
var g_imgPreloadScheduled = false;
function setStdImagePreload()
{
	if (!g_imgPreloadScheduled)
	{
		addEvent(window, "load", preloadStdImageMouseOvers);
		g_imgPreloadScheduled = true;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////
//
// Javascript support for std_anchor
//
//////////////////////////////////////////////////////////////////////////////////////////
function stdAnchorClicked(e, elem, WAMName, WRName, formName, protocol, target, currentrowhfield, currentrownumval)
{
	if(!e) { if( window.event ) { e = window.event; } else { return; } }
	elem.target = elem.target;
	if (WRName != '')
	{
		var f = createStdHiddenForm(WAMName, WRName, formName, protocol, target);
		if (f != null)
		{
			createReentryFields(f, elem);
			if (currentrowhfield && currentrowhfield.length > 0) insertHiddenField(f, currentrowhfield, currentrownumval);
			Lstd.Fields.check4VF_WAMEVENT(f, elem);
			submitForm(f, WAMName, WRName, target, protocol);
		}
		cancelEvent(e);
		return false;
	}
	return true;
}
//////////////////////////////////////////////////////////////////////////////////////////
//
// Javascript support for std_button
//
//////////////////////////////////////////////////////////////////////////////////////////
function stdButton_clicked(e, elem, WAMName, WRName, formName, protocol, target, currentrowhfield, currentrownumval)
{
	if(!e) { if( window.event ) { e = window.event; } else { return; } }
	var f = (!formName) ? getParentForm(elem) : createStdHiddenForm(WAMName, WRName, formName, protocol, target);
	if (f != null)
	{
		createReentryFields(f, elem.parentNode);
		if (currentrowhfield && currentrowhfield.length > 0) insertHiddenField(f, currentrowhfield, currentrownumval);
		submitForm(f, WAMName, WRName, target, protocol);
	}
	cancelEvent(e);
	return false;
}
function stdButton_setDefault(btnType, formName, btn, onSubmitFunc)
{
	if (!btn)
	{
		// if the button is not specified, use the last one in the document
		// (i.e. the one created just before the call to this function)
		var btns = document.getElementsByTagName(btnType);
		if (btns.length > 0) btn = btns[btns.length-1];
	}
	if (btn)
	{
		var f = (!formName) ? getParentForm(btn) : document.forms[formName];
		if (f)
		{
			f.__defaultSubmitButton = btn;
			f.onsubmit = onSubmitFunc;
		}
	}
}
function stdForm_Submit(form, WAMName, WRName, protocol, target)
{
	createReentryFields(form, form.__defaultSubmitButton.parentNode);
	submitForm(form, WAMName, WRName, target, protocol);
	return false;
}

//////////////////////////////////////////////////////////////////////////////////////////
//
// Javascript support for std_checkbox
//
/////////////////////////////////////////////////////////////////////////////////////////
function stdCheckboxClicked(checkBox, WAMName, WRName, formName, protocol, target, RFld, chkValue, unchkValue)
{
	var f = getParentForm(checkBox);
	if (f != null)
	{
		var fld = f.elements[RFld];
		if( fld != null )
		{
			fld.value = checkBox.checked ? chkValue : unchkValue;
		}
	}
	if ((WAMName != '') && (WRName != ''))
	{
		if (formName != '') f = createStdHiddenForm(WAMName, WRName, formName, protocol, target);
		if (f != null)
		{
			createReentryFields(f, checkBox.parentNode);
			Lstd.Fields.check4VF_WAMEVENT(f, checkBox);
			submitForm(f, WAMName, WRName, target, protocol);
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////
//
// Javascript support for std_rad_button and std_radbuttons
//
/////////////////////////////////////////////////////////////////////////////////////////
function stdRadioBtn_onClick(radioBtn, WAMName, WRName, formName, protocol, target, RFld)
{
	var f;
	if (formName)
	{
		f = createStdHiddenForm(WAMName, WRName, formName, protocol, target);
	} else {
		f = getParentForm(radioBtn);
	}
	if (f != null)
	{
		createReentryFields(f, radioBtn.parentNode);
		Lstd.Fields.check4VF_WAMEVENT(f, radioBtn);
		submitForm(f, WAMName, WRName, target, protocol);
	}
}
function stdRadioBtnGrp_onClick(radioBtn, WAMName, WRName, formName, protocol, target, RFld)
{
	var f = null;
	if (formName)
	{
		f = createStdHiddenForm(WAMName, WRName, formName, protocol, target);
	} else {
		f = getParentForm(radioBtn);
	}
	if (f != null)
	{
		var sp = radioBtn;
		while (sp = sp.parentNode) { if (sp.className.indexOf("std_radbuttons") >= 0) break; }
		createReentryFields(f, sp);
		var fldSet = document.getElementById(radioBtn.getAttribute("name") + "_RADBUTTONGRP");
		Lstd.Fields.check4VF_WAMEVENT(f, fldSet);
		submitForm(f, WAMName, WRName, target, protocol);
	}
}
function stdRadioBtnChkDft(name, defaultValue)
{
	var radioBtns = document.getElementsByName(name);
	var defaultRadioBtn = null;
	for (var i = 0, rb; rb = radioBtns[i]; i++)
	{
		if (rb.checked) return;
		if (!defaultRadioBtn && (rb.value == defaultValue)) defaultRadioBtn = rb;
	}
	if (defaultRadioBtn) defaultRadioBtn.checked = true;
}
//////////////////////////////////////////////////////////////////////////////////////////
//
// Javascript support for std_float
//
/////////////////////////////////////////////////////////////////////////////////////////
function stdFloatFixValues(fieldName, justLast)
{
	var elemList = document.getElementsByName(fieldName);
	for (var i = elemList.length-1; i>=0; i--)
	{
		var e = elemList[i];
		if (e.nodeName == 'INPUT')
		{
			e.value = new Number(e.value);
			if (justLast) return;
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////
//
// Javascript support for std_datetime
//
/////////////////////////////////////////////////////////////////////////////////////////
function stdDateTimeSetOnBlur()
{
	var iframe = document.getElementById("stdDateTimeCalendarFrame");
	iframe.contentWindow.gfuncLostFocusCallback = stdDateTimeIFrameLostFocus;
}
function stdDateTimeIFrameLoaded(contentWindow)
{
	var iframe = document.getElementById("stdDateTimeCalendarFrame");
	iframe.__loaded = true;
	contentWindow.Init(stdDateTimeGetValueForCalendar, stdDateTimeSetValueFromCalendar, stdDateTimeIFrameSetSize, null);
	if (!iframe.contentWindow) iframe.contentWindow = contentWindow;
	iframe.style.display = "block";
	// If this window is opened via showModelessDialog then the focus
	// (done by the calendar_panel after this function) will actually
	// generate an onblur.  So we need to make sure the onblur handler
	// is set after this.
	window.setTimeout("stdDateTimeSetOnBlur();", 1);
}
function stdDateTimeIFrameSetSize(width, height)
{
	var iframe = document.getElementById("stdDateTimeCalendarFrame");
	if (iframe)
	{
		iframe.style.width = width + "px";
		iframe.style.height = height + "px";
		stdDateTimeIFrameSetPosition(iframe);
	}
}
function stdDateTimeIFrameSetPosition(iframe)
{
	if (iframe)
	{
		var theBtn = iframe.__currentBtn;
		var w = iframe.offsetWidth;
		var h = iframe.offsetHeight;
		var windowRight = document.body.scrollLeft + document.body.clientWidth;
		var windowBottom = document.body.scrollTop + document.body.clientHeight;
		var btnLeft = getAbsoluteLeft(theBtn);
		var btnTop = getAbsoluteTop(theBtn);
		var align;
		align = new Object();
		align.horiz = 1;
		align.vert = 1;
		if (((btnLeft + theBtn.offsetWidth + w) > windowRight)
			&& ((btnLeft - w) > document.body.scrollLeft))
				align.horiz = -1;
		if (((btnTop + h) > windowBottom)
			&& ((btnTop - h) > document.body.scrollTop))
				align.vert = -1;

		iframe.style.left = ((align.horiz == 1) ? (btnLeft + theBtn.offsetWidth) : (btnLeft - w)) + "px";
		iframe.style.top = ((align.vert == 1) ? (btnTop) : (btnTop + theBtn.offsetHeight - h)) + "px";
	}
}
function stdDateTimeIFrameClose()
{
	var iframe = document.getElementById("stdDateTimeCalendarFrame");
	if (iframe != null)
	{
		if (iframe.__closeMeTO)
		{
			clearTimeout(iframe.__closeMeTO);
			iframe.__closeMeTO = null;
		}
		iframe.__dtContainer = null;
		iframe.contentWindow.gfuncLostFocusCallback = null;
		iframe.style.display = "none";
	}
}
function stdDateTimeIFrameLostFocus()
{
	var iframe = document.getElementById("stdDateTimeCalendarFrame");
	if (iframe.style.display != "none")
	{
		if (!iframe.__closeMeTO) iframe.__closeMeTO = setTimeout(stdDateTimeIFrameClose, 200);
	}
}
function stdDateTimeGetValueForCalendar()
{
	var iframe = document.getElementById("stdDateTimeCalendarFrame");
	return stdDateTimeGetDateValue(iframe.__dtContainer)
}
function stdDateTimeSetValueFromCalendar(dateValue)
{
	var iframe = document.getElementById("stdDateTimeCalendarFrame");
	stdDateTimeSetDateValue(iframe.__dtContainer, dateValue);
	iframe.__dtContainer.__dtProxyInput.focus();
	stdDateTimeIFrameClose();
}
function stdDateTimeGetDateValue(dtContainer)
{
	var dateVal = new Date();
	dateVal.setISO8601(dtContainer.__dtMasterInput.value);
	if ((dtContainer.__inputType != "datetime") || dtContainer.__displayInUTC)
	{
		// Functions that call this are unaware of the DisplayInUTC option and utilise the 
		// local date methods of the Date object.  So we need to shift the value by the
		// TimezoneOffset to that they will work with the right value.
		dateVal.setTime(dateVal.getTime() + (dateVal.getTimezoneOffset() * 60000));
	}
	if( ( dateVal == null ) || isNaN(dateVal.valueOf()) )
	{
		dateVal = new Date();
		dateVal.sqlNull = true;
	}
	return dateVal;
}
function stdDateTimeSetDateValue(dtContainer, dateVal)
{
	var masterDateVal = null;
	if ((dateVal == null) || isNaN(dateVal.valueOf()) || dateVal.sqlNull)
	{
		dtContainer.__dtMasterInput.value = "";
	}
	else
	{
		masterDateVal = new Date(dateVal.getTime());
		if (dtContainer.__displayInUTC)
		{
			// The value being supplied is in the "local" part of the date object
			// but it is supposed to represent a UTC value so we need to shift it back
			masterDateVal.setTime(dateVal.getTime() - (dateVal.getTimezoneOffset() * 60000));
		}
		switch (dtContainer.__inputType)
		{
			case "timeonly":
				dtContainer.__dtMasterInput.value = masterDateVal.toFormattedString("HH:mm:ss");
				break;
			case "dateonly":
				dtContainer.__dtMasterInput.value = masterDateVal.toFormattedString("YYYY-MM-DD");
				break;
			default:
				dtContainer.__dtMasterInput.value = masterDateVal.toISO8601String(true, false);
				break;
		}
	}
	stdDateTimeUpdateProxyValue(dtContainer, masterDateVal);
}
function stdDateTimeUpdateProxyValue(dtContainer, dateValue)
{
	if (!dateValue || (dateValue == NaN) || isNaN(dateValue.valueOf()) || dateValue.sqlNull)
	{
		dtContainer.__dtProxyInput.value = "";
		return;
	}
	var displayDate = new Date(dateValue.getTime());
	if (dtContainer.__displayInUTC) displayDate.setTime(displayDate.getTime() + (dateValue.getTimezoneOffset() * 60000));
	var proxyVal = "";
	switch (dtContainer.__inputType)
	{
		case "timeonly":
			proxyVal = (dtContainer.__timeMask == "") ? displayDate.toLocaleTimeString() : displayDate.toFormattedString(dtContainer.__timeMask);
			break;
		case "dateonly":
			proxyVal = (dtContainer.__dateMask == "") ? displayDate.toLocaleDateString() : displayDate.toFormattedString(dtContainer.__dateMask);
			break;
		case "datetime":
			proxyVal = displayDate.toFormattedString(dtContainer.__dateMask + " " + dtContainer.__timeMask);
			if (dtContainer.__dateMask == "") proxyVal = displayDate.toLocaleDateString() + proxyVal;
			if (dtContainer.__timeMask == "") proxyVal += displayDate.toLocaleTimeString();
			break;
	}
	if (dtContainer.__displayMode == "output")
	{
		dtContainer.__dtProxyInput.innerHTML = proxyVal;
	}
	else
	{
		dtContainer.__dtProxyInput.value = proxyVal;
	}
}
function stdDateTimeParser(dateStr, dateMask, timeMask)
{
	this.dateValue = NaN;
	this.dateStr = dateStr;
	this.matchIndex = -1;
	this.matchLength = 0;
	if ((dateMask == "") && (timeMask == ""))
	{
		// Let JavaScript have a go at it
		this.dateValue = new Date(dateStr);
		if (!isNaN(this.dateValue.valueOf()))
		{
			this.matchIndex = 0;
			this.matchLength = dateStr.length;
		}
		return;
	}
	var dm = dateMask.replace(/(\/|\(|\[|\^|\$|\.|\||\?|\*|\+|\(|\)|\\)/g, "\\$1");
	var tm = timeMask.replace(/(\/|\(|\[|\^|\$|\.|\||\?|\*|\+|\(|\)|\\)/g, "\\$1");
	var mask = dm;
	if ((dm != "") && (tm != "")) mask += "\\s+";
	mask += tm;
	var nYPos = 0, nMPos = 0, nDPos = 0, nMStrPos = 0, nDStrPos = 0;
	var nHPos = 0, nMinPos = 0, nSPos = 0, nMsPos = 0, nAPPos = 0;
	var aMonthNames = new Array();
	var aDayNames = new Array();
	var count = 1;
	var regExStr = mask.replace(/(\\s\+|YYYY|YY|Y|MMMM|MM|M|DDD|DD|D|HH|H|hh|h|mm|m|sss|ss|s|t)/g,
		function($1)
		{
			switch ($1)
			{
				case '\\s+': return '\\s+';
				case 'YYYY': nYPos = count++;return "(\\d{2,4})";
				case 'YY':   nYPos = count++;return "(\\d{2,4})";
				case 'MMMM':
					nMStrPos = count++;
					var names = (new Date()).arrayMstringMonths().join("|").toLowerCase();
					aMonthNames = names.split("|");
					return "(" + names + ")";
				case 'MM':   nMPos = count++;return "(\\d{1,2})";
				case 'M':    nMPos = count++;return "(\\d{1,2})";
				case 'DDD':
					nDStrPos = count++;
					var names = (new Date()).arrayMstringDays().join("|").toLowerCase();
					aDayNames = names.split("|");
					return "(" + names + ")";
				case 'DD':   nDPos = count++;return "(\\d\\d)";
				case 'D':	 nDPos = count++;return "(\\d{1,2})";
				case 'HH':   nHPos = count++;return "(\\d\\d)";
				case 'H':    nHPos = count++;return "(\\d{1,2})";
				case 'hh':   nHPos = count++;return "(\\d\\d)";
				case 'h':    nHPos = count++;return "(\\d{1,2})";
				case 'mm':   nMinPos = count++;return "(\\d\\d)";
				case 'm':    nMinPos = count++;return "(\\d{1,2})";
				case 'ss':   nSPos = count++;return "(\\d\\d)";
				case 's':    nSPos = count++;return "(\\d{1,2})";
				case 'sss':  nMsPos = count++;return "(\\d\\d\\d)";
				case 't':	 nAPPos = count++;return "([AaPp]\.?[Mm]?\.?)";
			}
		} );
	
	var d = dateStr.match(new RegExp(regExStr, "i"));
	if (d)
	{
		var today = new Date();
		var nY = (nYPos > 0) ? Number(d[nYPos]) : today.getFullYear();
		var nM = (nMPos > 0) ? (Number(d[nMPos]) - 1) : today.getMonth();
		var nD = (nDPos > 0) ? Number(d[nDPos]) : today.getDate();
		if ((nMPos == 0) && (nMStrPos > 0)) { nM = aMonthNames.indexOf(d[nMStrPos]); }
		if ((nDPos == 0) && (nDStrPos > 0)) { nD = (aDayNames.indexOf(d[nDStrPos]) + 9 - (new Date(nY, nM, 1)).getDay()) % 7; }
		var nH = (nHPos > 0) ? Number(d[nHPos]) : 0;
		var nMin = (nMinPos > 0) ? Number(d[nMinPos]) : 0;
		var nS = (nSPos > 0) ? Number(d[nSPos]) : 0;
		var nMs = (nMsPos > 0) ? Number(d[nMsPos]) : 0;
		if (nAPPos > 0)
		{
			if ((d[nAPPos].substr(0,1).toLowerCase() == "p") && (nH < 12)) nH += 12;
			if ((d[nAPPos].substr(0,1).toLowerCase() == "a") && (nH == 12)) nH = 0;
		}
		if ((nY > 0) && (nM >= 0) && (nM < 12) && (nD >= 0) && (nH < 24) && (nMin < 60) && (nS < 60))
		{
			this.dateValue = new Date(nY, nM, nD, nH, nMin, nS, nMs);
			// if nD is more than the days in the month, getDate() will return a different value;
			if (this.dateValue.getDate() != nD) this.dateValue = NaN;
		}
		this.matchIndex = d.index;
		this.matchLength = d[0].length;
	}
	if (this.dateValue == NaN)
	{
		console.warn("stdDateTimeParser unable to parse " + dateStr + " with mask " + dateMask + " " + timeMask);
	}
	return;
}
function stdDateTimeProxyChanged(proxyInp)
{
	var dtContainer = getParentElement(proxyInp, 'div');
	var hiddenInp = dtContainer.__dtMasterInput;
	var dateStr = proxyInp.value.toLowerCase();
	
	if (dateStr.length == 0)
	{
		if (dtContainer.__allowSQLNull)
		{
			stdDateTimeSetDateValue(dtContainer, null);
			proxyInp._initVal = proxyInp.value;
			return true;
		}
		else
		{
			if (dtContainer.__inputType == "timeonly") {
				window.alert(g_StdLocaleMgr.getMessageText("BlankTime2"));
			} else {
				window.alert(g_StdLocaleMgr.getMessageText("BlankDate2"));
			}
			var dateVal = stdDateTimeDateObjectFromMasterVal(dtContainer, dtContainer.__dtMasterInput.value);
			stdDateTimeUpdateProxyValue(dtContainer, dateVal);
			proxyInp.focus();
			proxyInp.select();
			return false;
		}
	}
	var newDate = NaN;
	if (dtContainer.__timeMask == "")
	{
		// Fix firefox bug
		dateStr = dateStr.replace(/([AaPp])\.([Mm])\./g, "$1$2");
	}
	switch (dtContainer.__inputType)
	{
		case 'timeonly':
			newDate = (new stdDateTimeParser(dateStr, "", dtContainer.__timeMask)).dateValue;
			break;
		case 'dateonly':
			newDate = (new stdDateTimeParser(dateStr, dtContainer.__dateMask, "")).dateValue;
			break;
		case 'datetime':
			if ((dtContainer.__dateMask == "") == (dtContainer.__timeMask == ""))
			{
				// Both masks are empty or both are set
				newDate = (new stdDateTimeParser(dateStr, dtContainer.__dateMask, dtContainer.__timeMask)).dateValue;
			}
			else if (dtContainer.__dateMask == "")
			{
				dp = new stdDateTimeParser(dateStr, "", dtContainer.__timeMask);
				if (dp.matchIndex > 1)
				{
					var datePart = dateStr.substring(0, dp.matchIndex - 1);
					if (isNaN(datePart.valueOf()))
					{
						newDate = new Date(datePart);
						if (!isNaN(newDate))
						{
							newDate.setHours(dp.dateValue.getHours());
							newDate.setMinutes(dp.dateValue.getMinutes());
							newDate.setSeconds(dp.dateValue.getSeconds());
							newDate.setMilliseconds(dp.dateValue.getMilliseconds());
						}
					}
				}
			}
			else
			{
				// timeMask must be blank
				dp = new stdDateTimeParser(dateStr, dtContainer.__dateMask, "");
				if (dp.matchIndex >= 0)
				{
					// JavaScript will not recognise a string that is time only
					newDate = new Date(dp.dateValue.toLocaleDateString() + " " + dateStr.substring(dp.matchIndex + dp.matchLength));
				}
			}
			break;
	}
	if (isNaN(newDate.valueOf()))
	{
		if (dtContainer.__inputType == "timeonly") {
			window.alert(proxyInp.value + g_StdLocaleMgr.getMessageText("BadTime1"));
		} else {
			window.alert(proxyInp.value + g_StdLocaleMgr.getMessageText("BadDate1"));
		}
		proxyInp.focus();
		proxyInp.select();
		return false;
	}
	stdDateTimeSetDateValue(dtContainer, newDate);
	proxyInp._initVal = proxyInp.value;
	return true;
}
function stdDateTimeOnFocus(e)
{
	if(!e) { if( window.event ) { e = window.event; } else { return; } }
	var targ = getEventTarget(e);
	targ._initVal = targ.value;
	stdOnFocus(e);
}
function stdDateTimeOnBlur(e)
{
	if(!e) { if( window.event ) { e = window.event; } else { return; } }
	var targ = getEventTarget(e);
	if (typeof(targ._initVal) == "string") {
		if (targ._initVal != targ.value) targ.onchange(e);
	}
	stdOnBlur(e);
}
function stdDateTimeInitDiv(fieldName, displayMode, inputType, dateMask, timeMask, displayInUTC, allowSQLNull)
{
	// This is called just after the DIV is completed.  So find the last instance
	// of the field with the required name.
	var dtContainer = null;
	var masterValue = "";
	if (displayMode == "output")
	{
		var e = document.getElementById(fieldName);
		dtContainer = getParentElement(e, 'div');
		if (dtContainer && dtContainer.className.match(/\bstd_datetime\b/))
		{
			dtContainer.__dtProxyInput = e;
			dtContainer.__dtMasterInput = e;
			masterValue = e.getAttribute("__isovalue");
		}
		else
		{
			dtContainer = null;
		}
	}
	else
	{
		var elemList = document.getElementsByName(fieldName);
		for (var i = elemList.length-1; i>=0; i--)
		{
			var e = elemList[i];
			if (e.nodeName == 'INPUT')
			{
				dtContainer = getParentElement(e, 'div');
				if (dtContainer && dtContainer.className.match(/\bstd_datetime\b/))
				{
					var inputs = dtContainer.getElementsByTagName('input');
					for (var j=0,input; input=inputs[j]; j++)
					{
						if (input.getAttribute('name').lastIndexOf('_PROXY') >= 0)
						{
							dtContainer.__dtProxyInput = input;
						} else {
							dtContainer.__dtMasterInput = input;
						}
					}
					masterValue = dtContainer.__dtMasterInput.value;
					break;
				}
			}
			dtContainer = null;
		}
	}
	if (dtContainer)
	{
		dtContainer.__displayMode = displayMode;
		dtContainer.__inputType = inputType;
		dtContainer.__dateMask = dateMask;
		dtContainer.__timeMask = timeMask;
		dtContainer.__displayInUTC = displayInUTC;
		dtContainer.__allowSQLNull = allowSQLNull;
		var dateVal = stdDateTimeDateObjectFromMasterVal(dtContainer, masterValue);
		switch (dtContainer.__inputType)
		{
			case "timeonly":
				dateVal = (new stdDateTimeParser(masterValue, "", "HH:mm:ss")).dateValue;
				break;
			case "dateonly":
				dateVal = (new stdDateTimeParser(masterValue, "YYYY-MM-DD", "")).dateValue;
				break;
			case "datetime":
				dateVal = new Date();
				dateVal.setISO8601(masterValue);
				break;
		}
		stdDateTimeUpdateProxyValue(dtContainer, dateVal);
	}
}
function stdDateTimeDateObjectFromMasterVal(dtContainer, masterValue)
{
	switch (dtContainer.__inputType)
	{
		case "timeonly":
			dateVal = (new stdDateTimeParser(masterValue, "", "HH:mm:ss")).dateValue;
			break;
		case "dateonly":
			dateVal = (new stdDateTimeParser(masterValue, "YYYY-MM-DD", "")).dateValue;
			break;
		case "datetime":
			dateVal = new Date();
			dateVal.setISO8601(masterValue);
			break;
	}
	return dateVal;
}
function stdDateTimeInitIFrame() {
	var iframe = document.getElementById("stdDateTimeCalendarFrame");
	if (iframe == null)
	{
		iframe = document.createElement('iframe');
		iframe.id = "stdDateTimeCalendarFrame";
		iframe.src = g_lweb_images_path + '/calendar_panel.htm';
		iframe.setAttribute("frameborder", "0");
		iframe.style.position = "absolute";
		iframe.style.display = "none";
		iframe.style.width = "1px";
		iframe.style.height = "1px";
		iframe.style.overflow = "hidden";
		iframe.__dtContainer = null;
		iframe.__loaded = false;
		// I don't like doing browser detection like this but there's no feature to detect for this one.
		// Safari does not generate onBlur events for the frame content.  On the other hand, other browsers
		// will generate an onblur for the frame when it's content gets focus (which we don't want).
		if (navigator.userAgent.match(/AppleWebKit/))
		{
			iframe.onblur = stdDateTimeIFrameLostFocus;
		}
		document.body.appendChild(iframe);
	}
	return iframe;
}
function stdDateTimeBtnClick(theBtn)
{
	if (theBtn.className == "disabled") return;
	var dtContainer = getParentElement(theBtn, 'div');
	var iframe = stdDateTimeInitIFrame();
	if ((iframe.__dtContainer != dtContainer) || (iframe.style.display == "none"))
	{
		if (iframe.__closeMeTO)
		{
			clearTimeout(iframe.__closeMeTO);
			iframe.__closeMeTO = null;
		}
		iframe.style.display = "none";
		iframe.__dtContainer = dtContainer;
		iframe.__currentBtn = theBtn;
		iframe.style.left = getAbsoluteLeft(theBtn) + theBtn.offsetWidth + "px";
		iframe.style.top = getAbsoluteTop(theBtn) + "px";
		if (iframe.__loaded && iframe.contentWindow)
		{
			iframe.contentWindow.SetDialogHTML();
			iframe.style.display = "block";
			stdDateTimeIFrameSetPosition(iframe);
			iframe.focus();
			iframe.contentWindow.focus();
			// If this window is opened via showModelessDialog then the focus above
			// will actually generate an onblur.  So we need to make sure the
			// onblur handler is set after this.
			window.setTimeout("stdDateTimeSetOnBlur();", 1);
		}
	}
	else
	{
		stdDateTimeIFrameClose();
	}
}
//////////////////////////////////////////////////////////////////////////////////////////
//
// JavaScript support for std_list_textarea
//
//////////////////////////////////////////////////////////////////////////////////////////
function stdLTA_ItemsToForm(theForm, theItems, listName, listField, maxRows)
{
	var i = 0;
	var l = theItems.length;
	if (isNaN(maxRows)) maxRows = 0;
	if ((maxRows > 0) && (maxRows < l)) l = maxRows;
	for (i=1; i<=l; i++)
	{
		var fieldName = listName.concat(".",i.zeropad(4),".",listField);
		insertHiddenField(theForm, fieldName, theItems[i-1].rtrim());
	}
	var field = theForm.elements[listName.concat(".",(i++).zeropad(4),".",listField)];
	while (field)
	{
		field.parentNode.removeChild(field);
		field = theForm.elements[listName.concat(".",(i++).zeropad(4),".",listField)];
	}
}
function stdLTAv1_TextAreaToList(theTA, listName, listField, formName, maxRows)
{
	var f = theTA.form;
	if (formName) f = document.forms[formName];
	var theText = theTA.value;
	var items = new Array();
	var arrayIndex = 0;
	var charPos = 0;
	var itemLen = theTA.cols;
	while (charPos < theText.length)
	{
		var endPos = charPos + itemLen;
		items[items.length] = theText.substring(charPos, endPos);
		charPos = endPos;
	}
	stdLTA_ItemsToForm(f, items, listName, listField, maxRows);
}
function stdLTA_TextAreaToList(theTA, listName, listField, wordWrap, maxLineLength, maxRows)
{
	var f = theTA.form;
	var theText = theTA.value;
	var l = maxLineLength;
	if (wordWrap && theTA.cols < maxLineLength) l = theTA.cols;
	theText = theText.replace(/\r\n/g,"\n");
	var paras = theText.split("\n");
	var items = new Array();
	for (var i=0; i < paras.length; i++)
	{
		var p = paras[i];
		do
		{		
			if (p.length > l)
			{
				var lineEnd = p.lastIndexOf(" ", l);
				var hyphen = p.lastIndexOf("-", l);
				if (hyphen > lineEnd) lineEnd = hyphen;
				if (lineEnd == -1) lineEnd = l-1;
				items.push(p.substring(0, lineEnd+1).rtrim());
				p = p.substring(lineEnd + 1);
			} else {
				items.push(p);
				p = "";
			}
		} while (p.length > 0)
	}
	stdLTA_ItemsToForm(f, items, listName, listField, maxRows);
}
//////////////////////////////////////////////////////////////////////////////////////////
//
// JavaScript support for std_list and std_grid_v2
//
//////////////////////////////////////////////////////////////////////////////////////////

function cursorInElement(elem, evt)
{
	var mouseX = getRelativeMouseX(elem, evt);
	if ((mouseX >= 0) && (mouseX <= elem.offsetWidth))
	{
		var mouseY = getRelativeMouseY(elem, evt);
		if ((mouseY >= 0) && (mouseY <= elem.offsetHeight))
		{
			return true;
		}
	}
	return false;
}

var std_grids;

function stdGridColumn()
{
	this.tsmlDecimalSeparator=".";
	this.tsmlType="";
	this.tsmlMode="output";
	this.NumberParser = new StdNumberParser(this.tsmlDecimalSeparator);
	this.parseValString = function(valStr) {return valStr;}
	this.prevVisible = null;
	
	this.setTsmlDecimalSeparator = function(val)
	{
		this.tsmlDecimalSeparator = val;
		this.NumberParser = new StdNumberParser(this.tsmlDecimalSeparator);
		this.setTsmlType(this.tsmlType);
	}
	this.setTsmlType = function(val)
	{
		this.tsmlType = val;
		switch (this.tsmlType)
		{
			case "packed":
			case "signed":
				this.parseValString = function(valStr) {return this.NumberParser.parseDecimal(valStr);}
				break;
			case "integer":
				this.parseValString = function(valStr) {return this.NumberParser.parseInt(valStr);}
				break;
			case "float":
				this.parseValString = function(valStr) {return this.NumberParser.parseFloat(valStr);}
				break;
			default:
				this.parseValString = function(valStr) {return valStr;}
		}
	}
}

Lstd.Weblets.stdGrid = function () {};

Lstd.Weblets.stdGrid.prototype.init = function(gridID, gridData) {
	this.id = gridID;
	// Older list code may have already set these)
	if (this.allowSort == undefined) this.allowSort = gridData.allowSort != null ? gridData.allowSort : false;
	if (this.allowColResize == undefined) this.allowColResize = gridData.allowColResize != null ? gridData.allowColResize : false;
	if (this.rowHeaderCol == undefined) this.rowHeaderCol = gridData.rowHeaderCol != null ? gridData.rowHeaderCol : '';
	if (this.sortFixedRows == undefined) this.sortFixedRows = gridData.sortFixedRows != null ? gridData.sortFixedRows : true;

	this.hoverEffect = gridData.hoverEffect != null ? gridData.hoverEffect : false;
	this.selectableRows = gridData.selectableRows != null ? gridData.selectableRows : false;
	this.onRowClickJS = gridData.onRowClickJS || null;
	
	this.cols = new Array(gridData.columns);
	
	var self = this, fn = function() {
		try {self.connectToHTML();}
		catch(e) {debug("Initialisation of grid " + gridID + " failed: " + e.description); }
	};
	if (window.jQuery) {
		jQuery(document).ready(fn);
	} else {
		addEvent(window, "load", fn, false);
	}
}

Lstd.Weblets.stdGrid.prototype.connectToHTML = function()
{
	var lastVis = null, self = this;
	this.outerDiv = document.getElementById(this.id + "_wrap");
	this.table = document.getElementById(this.id);
	this.headRow = (this.table.tHead) ? this.table.tHead.rows[0] : null;
	this.tBody = this.table.tBodies[0];
	this.fixedWidth = this.outerDiv.style.width;
	this.fixedHeight = this.outerDiv.style.height;
	this.fixWrapperSize();

	if (this.hoverEffect) {
		this.tBody.className += " hoverEffect";
	}
	if (this.selectableRows) {
		this.tBody.className += " selectableRows";
	}
	addEvent(this.tBody, "click", stdGrid_body_onClick, false);
	
	lansaEvent_RegisterListener(this.outerDiv, "lansaEventOnDisplay", function() {self.fixWrapperSize();});
	if (this.headRow)
	{
		this.allowColResize = this.allowColResize && (((document.addEventListener) || (this.table.setCapture)) ? true : false);
		if (this.allowColResize)
		{
			this.table.onmousemove = stdGrid_onMouseMove;
			this.table.onmousedown = stdGrid_onMouseDown;
		}
		for (var i=0, headCell; headCell = this.headRow.cells[i]; i++)
		{
			var col = new stdGridColumn();
			// The cellIndex value returned by some browsers(IE) is not always the cells position
			// in the cells collection.  We need a 2-way connection between the cell and the cols array
			// so the header cell is stored in the array at the position indicated by it's cellIndex
			// and a cellIndex is added to the col indicating the correct cellIndex.
			this.cols[headCell.cellIndex] = col;
			col.cellIndex = i;
			col.setTsmlDecimalSeparator(headCell.getAttribute("__DecimalSeparator"));
			col.setTsmlType(headCell.getAttribute("__FormatType"));
			col.tsmlMode = headCell.getAttribute("__Mode");
			col.AllowSort = headCell.getAttribute("__AllowSort") == "true" ? true : false;
			col.headerCell = headCell;
			col.prevVisible = lastVis;
			if (getCurrentStyle(headCell, "display") != 'none')
			{ 
				if (this.allowColResize)
				{
					headCell.onmousemove = stdGrid_hdr_onMouseMove;
					headCell.onmousedown = stdGrid_hdr_onMouseDown;
					headCell.onmouseup = stdGrid_hdr_onMouseUp;
				}
				if (this.allowSort && col.AllowSort)
				{
					headCell.onclick = stdGrid_hdr_onClick;
				}
				lastVis = col;
			}
		}
		if (this.allowSort)
		{
			this.rows = new Array(this.tBody.rows.length);
			if ((!this.sortFixedRows) && (this.rowHeaderCol != '')) this.fixedCells = new Array(this.tBody.rows.length);
			for (var i=0, r; r=this.tBody.rows[i]; i++)
			{
				this.rows[i] = r;
				if (this.fixedCells) this.fixedCells[i] = r.cells[0];
			}
			this.sortCol = -1;
			this.sortIndicator = null;
			this.sortDir = 1;
		}
	}
}
Lstd.Weblets.stdGrid.prototype.fixWrapperSize = function()
{
	if (!this.fixedWidth)
	{
		var outerW = this.table.offsetWidth
		if (this.outerDiv.clientWidth > 0)
		{
			outerW += (this.outerDiv.offsetWidth - this.outerDiv.clientWidth);
		}
		this.outerDiv.style.width = outerW + "px";
	}
	if (!this.fixedHeight)
	{
		var diff = 0;
		var outerH = this.table.offsetHeight
		if (this.outerDiv.clientHeight > 0)
		{
			diff = (this.outerDiv.offsetHeight - this.outerDiv.clientHeight);
		}
		if (diff) this.outerDiv.style.height = (outerH + diff + 1) + "px";
	}
}
Lstd.Weblets.stdGrid.prototype.getCellValueString = function(row, colNum)
{
	var td = row.cells[colNum];
	return td.getAttribute("__cellValue");
}
Lstd.Weblets.stdGrid.prototype.getCellValue = function(row, colNum)
{
	var colInfo = this.cols[colNum];
	var strVal = this.getCellValueString(row, colInfo.cellIndex);
	return colInfo.parseValString(strVal);
}
Lstd.Weblets.stdGrid.prototype.setSortIndicator = function(dir)
{
	var cn = this.sortIndicator.className;
	cn = cn.replace(/((?:^| )std_grid_sort_indicator)(_up|_down)?($| )/g, "$1" + dir + "$3");
	this.sortIndicator.className = cn;
}
Lstd.Weblets.stdGrid.prototype.sort = function(headerCell)
{
	window.stdGrid_current_sort = this;
	var colIndex = headerCell.cellIndex;
	if (this.sortCol != colIndex)
	{
		if (this.sortIndicator) this.setSortIndicator("");
		this.sortCol = colIndex;
		this.sortIndicator = headerCell;
		this.sortDir = 1;
	}
	else
	{
		this.sortDir *= -1;
	}
	if(this.sortDir == 1)
	{
		this.rows.sort(stdGrid_SortCompareA);
		this.setSortIndicator("_up");
	} else {
		this.rows.sort(stdGrid_SortCompareD);
		this.setSortIndicator("_down");
	}
	var tbdy = this.table.removeChild(this.table.tBodies[0]);
	for (var i=0, r; r=this.rows[i]; i++)
	{
		if (this.fixedCells)
		{
			 r.insertBefore(this.fixedCells[i], r.firstChild);
		}
		tbdy.appendChild(r);
		r.className = (i % 2) == 0 ? r.getAttribute("__oddrc") : r.getAttribute("__evenrc");
	}
	this.table.appendChild(tbdy);
}

function register_std_grid(gridID, columns, allowSort, allowColResize, rowHeaderCol, sortFixedRows)
{
	var grid = new Lstd.Weblets.stdGrid(), gridData;
	if (!std_grids) std_grids = new Object();
	std_grids[gridID] = grid;
	
	if (arguments.length == 2) {
		gridData = arguments[1];
	} else {
		gridData = {
			columns: arguments[1], 
			allowSort: arguments[2], 
			allowColResize: arguments[3], 
			rowHeaderCol: arguments[4], 
			sortFixedRows: arguments[5]
		}
	}
	
	Lstd.Weblets.registerWeblet(gridID, grid, gridData);
	// Return grid for backwards compatibility
	return grid;
}

function stdGrid_SortCompareA(a,b)
{
	var g = window.stdGrid_current_sort;
	var aVal = g.getCellValue(a,g.sortCol);
	var bVal = g.getCellValue(b,g.sortCol);
	return aVal < bVal ? -1 : aVal > bVal ? 1 : 0;
}
function stdGrid_SortCompareD(a,b)
{
	return stdGrid_SortCompareA(b,a);
}

function stdGrid_getContainingList(elem)
{
	var r = elem;
	while (r.parentNode) 
	{
		if (r.className.match(/\bstd_grid\b/))
		{
			return std_grids[r.getAttribute('id')];
		} else {
			r = r.parentNode;
		}
	}
	return null;
}
function stdGrid_cursorInResizeZone(cell, evt)
{
	var mouseX = getRelativeMouseX(cell, evt);
	if (cell.offsetWidth - mouseX <= 5) return 1;
	if ((cell.cellIndex > 0) && (mouseX <= 4)) return -1;
	return 0;
}
function stdGrid_onMouseMoveInDrag(e)
{
	if(!e) { if( window.event ) { e = window.event; } else { return; } }
	var l = document.stdGrid_currentDrag;
	var rsDiv = document.getElementById('StdListColResize');
	if (rsDiv)
	{
		 var w = getRelativeMouseX(rsDiv, e) + l.resizeMouseOffset;
		 if (w > 0) rsDiv.style.width = w + "px";
	}
}
function stdGrid_onMouseUpInDrag(e)
{
	if(!e) { if( window.event ) { e = window.event; } else { return; } }
	document.removeEventListener('mousemove',stdGrid_onMouseMoveInDrag,true);
	document.removeEventListener('mouseup',stdGrid_onMouseUpInDrag,true);
	
	var l = document.stdGrid_currentDrag;
	if (l && l.resizeCol)
	{
		stdGrid_EndDrag(e);
	}
	document.stdGrid_currentDrag = null;
}
function stdGrid_StartDrag(l, e)
{
	var headCell = l.resizeCol.headerCell;
	document.stdGrid_currentDrag = l;
	if (document.addEventListener)
	{
		document.addEventListener('mousemove',stdGrid_onMouseMoveInDrag,true);
		document.addEventListener('mouseup',stdGrid_onMouseUpInDrag,true);
	}
	else
	{
		if (headCell.setCapture) { headCell.setCapture(); };
	}
	var nextCellLeft = l.table.offsetWidth;
	for (var i=headCell.cellIndex+1,c; c=l.cols[i]; i++)
	{
		if (getCurrentStyle(c.headerCell, "display") != 'none')
		{
			nextCellLeft = c.headerCell.offsetLeft;
			break;
		}
	}
	var cellRight = headCell.offsetLeft + headCell.offsetWidth;
	var centerLine = headCell.offsetWidth + Math.round((nextCellLeft - cellRight) / 2);
	l.resizeStartX = getRelativeMouseX(headCell, e);
	l.resizeMouseOffset = centerLine - l.resizeStartX;

	var rsDiv = document.getElementById('StdListColResize');
	if (rsDiv) document.body.removeChild(rsDiv);
	rsDiv = document.createElement('div');
	rsDiv.id = "StdListColResize";
	rsDiv.className = "std_grid_col_resize";
	var s = rsDiv.style;
	s.position = "absolute";
	s.left = getAbsoluteLeft(headCell) + "px";
	s.top = getAbsoluteTop(l.outerDiv) + "px";
	s.width = centerLine + "px";
	s.height = l.outerDiv.offsetHeight + "px";
	document.body.appendChild(rsDiv);
}
function stdGrid_EndDrag(e)
{
	var l = document.stdGrid_currentDrag;
	document.stdGrid_currentDrag = null;
	var headCell = l.resizeCol.headerCell;
	// Browsers are very inconsistent in their ideas of what "width" exactly means
	// so try to do everything using a difference rather than an absolute size.
	var diff = getRelativeMouseX(headCell, e) - l.resizeStartX;
	var newWidth = headCell.offsetWidth + diff;
	if (newWidth < 0) { diff -= newWidth; newWidth = 0; }
	
	if (l.tBody.rows.length > 0)
	{
		// cellIndex returned by the browser is unreliable so we have our own
		var cellIndex = l.cols[headCell.cellIndex].cellIndex
		if (diff > 0)
		{
			stdGrid_adjustHeadCellWidth(headCell, diff);
			stdGrid_ResizeCollContent(l.tBody, cellIndex, diff);
		}
		else if (diff < 0)
		{
			var firstCellContent = stdGrid_GetCellContentforResize(l.tBody.rows[0].cells[cellIndex]);
			var startHeadW = headCell.offsetWidth;
			var startContentW = 0;
			if (firstCellContent)
			{
				startContentW = firstCellContent.offsetWidth;
				stdGrid_ResizeCollContent(l.tBody, cellIndex, diff);
			}
			stdGrid_adjustHeadCellWidth(headCell, diff);
			if (headCell.offsetWidth != newWidth)
			{
				// Browser wouldn't go to the size we wanted. Cell contents may need correcting
				if (firstCellContent)
				{
					var cDelta = startContentW - firstCellContent.offsetWidth;
					var hDelta = startHeadW - headCell.offsetWidth;
					stdGrid_ResizeCollContent(l.tBody, cellIndex, cDelta - hDelta);
				}
				stdGrid_adjustHeadCellWidth(headCell, null);
			}
		}		
	}
	else
	{
		stdGrid_adjustHeadCellWidth(headCell, diff);
	}
	l.fixWrapperSize();
	l.resizeCol = null;
	l.table.style.cursor = 'default';
	var rsDiv = document.getElementById('StdListColResize');
	if (rsDiv) document.body.removeChild(rsDiv);
}
function stdGrid_onMouseMove(e)
{
	if(!e) { if( window.event ) { e = window.event; } else { return; } }
	var l = std_grids[this.getAttribute('id')];
	if (l.resizeCol == null) {
		var mouseY = getRelativeMouseY(l.headRow, e);
		if ((mouseY >= 0) && (mouseY < l.headRow.offsetHeight))
		{
			// Header cells stop this event so the mouse must be over the cellspacing area
			var mouseX = getRelativeMouseX(l.headRow.cells[0], e);
			if (mouseX > 0)
			{
				this.style.cursor = 'e-resize';
				this.style.cursor = 'col-resize';
			}
			else
			{
				this.style.cursor = 'default';
			}
		}
		else
		{
			this.style.cursor = 'default';
		}
	}
}
function stdGrid_onMouseDown(e)
{
	if(!e) { if( window.event ) { e = window.event; } else { return; } }
	var l = std_grids[this.getAttribute('id')];
	if (l.resizeCol == null) {
		var mouseY = getRelativeMouseY(l.headRow, e);
		if ((mouseY >= 0) && (mouseY <= l.headRow.offsetHeight))
		{
			// Header cells stop this event so the mouse must be over the cellspacing area
			// Need to work out which cell is to the left.
			l.resizeCol = null;
			for (var i=0, c; c = l.cols[i]; i++)
			{
				if (getRelativeMouseX(c.headerCell, e) <= 0) break;
				l.resizeCol = c;
			}
			if (l.resizeCol != null) stdGrid_StartDrag(l, e);
			e.returnValue = false;
			if (e.preventDefault) e.preventDefault();
		}
	}
}
function stdGrid_hdr_onMouseDown(e)
{
	if(!e) { if( window.event ) { e = window.event; } else { return; } }
	var l = stdGrid_getContainingList(this);
	l.ignoreNextClickIn = null;
	
	var btn = -1;
	if( typeof( e.which ) == 'number' ) { btn = e.which; } else { if( typeof( e.button ) == 'number' ) { btn = e.button; } else { btn = 1; } }
	l.inResize = false;
	if (btn == 1) {
		switch (stdGrid_cursorInResizeZone(this,e))
		{
			case -1:
				l.resizeCol = l.cols[this.cellIndex].prevVisible;
				break;
			case 1:
				l.resizeCol = l.cols[this.cellIndex];
				break;
			default:
				l.resizeCol = null;
		}
		if (l.resizeCol != null)
		{
			l.ignoreNextClickIn = this;
			stdGrid_StartDrag(l, e);
		}
	}
	cancelEvent(e);
}
function stdGrid_hdr_onMouseMove(e)
{
	if(!e) { if( window.event ) { e = window.event; } else { return; } }
	var l = stdGrid_getContainingList(this);
	if (l.resizeCol == null)
	{
		if(stdGrid_cursorInResizeZone(this,e) != 0)
		{
			l.table.style.cursor = 'e-resize';
			// Browsers that don't support this should ignore it and use e-resize
			l.table.style.cursor = 'col-resize';
		} else {
			l.table.style.cursor = 'default';
		}
	} else {
		stdGrid_onMouseMoveInDrag(e);
	}
	e.cancelBubble = true;
	if (e.stopPropagation) e.stopPropagation();
}
function stdGrid_hdr_onMouseUp(e)
{
	if(!e) { if( window.event ) { e = window.event; } else { return; } }
	var l = stdGrid_getContainingList(this);
	if (l.resizeCol != null)
	{
		var headCell = l.resizeCol.headerCell;
		if (headCell.releaseCapture) { headCell.releaseCapture(); }
		stdGrid_EndDrag(e);
	}
}
function stdGrid_hdr_onClick(e)
{
	if(!e) { if( window.event ) { e = window.event; } else { return; } }
	var l = stdGrid_getContainingList(this);
	if (l.ignoreNextClickIn != this) {
		l.sort(this);
	}
	l.ignoreNextClickIn = null;
}
function stdGrid_body_onClick(e)
{
	if(!e) { if( window.event ) { e = window.event; } else { return; } }
	var target = e.target || e.srcElement, tr = getParentElement(target, "tr"), table = getParentElement(tr, "table");
	
	while (table && !table.className.match(/\bstd_grid\b/)) {
		tr = getParentElement(table, "tr");
		table = getParentElement(tr, "table");
	}
	if (table) {
		var l = std_grids[table.getAttribute('id')],
			jsResult = (l.onRowClickJS) ? l.onRowClickJS.call(tr, e, parseInt(tr.getAttribute("data-rowNum"))) : true;
		if (jsResult !== false) {
			if (l._selectedRow) l._selectedRow.className = l._selectedRow.className.replace(/ selected/g,"");
			l._selectedRow = tr;
			tr.className += " selected";
		}
	}
}
function stdGrid_adjustHeadCellWidth(cell, adjustBy)
{
	var elem = cell;
	var elems = getElementsByClassAndTag(cell, "std_grid_cell_sizer", "div");
	if (elems) elem = elems[0];
	var currentW = 0;
	if (document.defaultView && document.defaultView.getComputedStyle)
	{
		currentW = parseInt(document.defaultView.getComputedStyle(elem,"").getPropertyValue("width"));
	}
	else
	{
		currentW = elem.offsetWidth;
	}
	if (adjustBy)
	{
		newW = currentW + adjustBy;
		elem.style.width = (newW < 0) ? "0px" : newW + "px";
	} else {
		elem.style.width = "100%";
	}
}
function stdGrid_ResizeCollContent(tBody, col, diff)
{
	var r; var c;
	if ((r = tBody.rows[0]) && (c = r.cells[col]))
	{
		var elem = stdGrid_GetCellContentforResize(c);
		if (elem)
		{
			var w = elem.offsetWidth + diff;
			var ws = (w < 0) ? "0px" : w + "px";
			// Although the css width property normally has different meanings depending on the browser
			// and box model being used, it seems that this doesn't apply in JavaScript.  Provided the
			// element is not a table cell, setting style.width is like setting the offsetWidth.
			elem.style.width = ws;
			for (var i=1; r=tBody.rows[i]; i++)
			{
				elem = stdGrid_GetCellContentforResize(r.cells[col]);
				if (elem) elem.style.width = ws;
			}
		}
	}
}
function stdGrid_GetCellContentforResize(cell)
{
	var child = null;
	var childCount = 0;
	for (var j=0, cn; cn=cell.childNodes[j]; j++)
	{
		if ((cn.nodeType != 3) && (cn.nodeType != 8) && (cn.nodeName != "SCRIPT"))
		{
			child = cn;
			childCount++;
		}
	}
	if (childCount == 1) return child;
	return null;
}
function stdGrid_HideCols(gid, sels)
{
	var ss = get1stStyleElement();
	for (var i = 0, sel; sel = sels[i]; i++)
	{
		addCSSRuleN(ss, (gid + sel), "display: none;");
	}
}
//////////////////////////////////////////////////////////////////////////////////////////
//
// Javascript support for std_dropdown and std_listbox
//
//////////////////////////////////////////////////////////////////////////////////////////
function std_DD_ListBoxOnChange(elem, WAMName, WRName, formName, target, bSubmitTagFields, sTagFld1, sTagFld2, sTagFld3, bAllowMultiSel, multiSelListName, multiSelCodeField, protocol)
{
	var f = createStdHiddenForm(WAMName, WRName, formName, null, target);
	var reentryfld = elem.getAttribute("reentryfld");

	if ( (f != null) && (reentryfld != '') )
	{
		insertHiddenField(f, reentryfld, elem.getAttribute("reentryval"));
	}

	if ( bSubmitTagFields  ) 
	{
		var oSelOption = elem.options[elem.selectedIndex];

		if (sTagFld1 != '') insertHiddenField(f, sTagFld1, oSelOption.getAttribute("tag_" + sTagFld1));
		if (sTagFld2 != '') insertHiddenField(f, sTagFld2, oSelOption.getAttribute("tag_" + sTagFld2));
		if (sTagFld3 != '') insertHiddenField(f, sTagFld3, oSelOption.getAttribute("tag_" + sTagFld3));
	}

	if (bAllowMultiSel) 
	{
		stdListBoxInsertMultiSelectList(f, elem, bSubmitTagFields, sTagFld1, sTagFld2, sTagFld3, bAllowMultiSel, multiSelListName, multiSelCodeField)
	}

	if (WRName != '')
	{
		Lstd.Fields.check4VF_WAMEVENT(f, elem);
		submitForm(f, WAMName, WRName, target, protocol);
	}
}

function std_DD_ListBoxOnKeyDown(oForm, e)
{
	if(!e) { if( window.event ) { e = window.event; } else { return; } }
	if (e.keyCode == 13) setTimeout(function(){{_HandleDefaultSubmit(oForm);}}, 0);
}
function stdListBoxInsertMultiSelectList(f, elem, bSubmitTagFields, sTagFld1, sTagFld2, sTagFld3, bAllowMultiSel, multiSelListName, multiSelCodeField)
{
	var dataArray = new Array();
	var columns = new Array();

	columns.push(multiSelCodeField);
	if (bSubmitTagFields)
	{
		if (sTagFld1 != '') columns.push(sTagFld1);
		if (sTagFld2 != '') columns.push(sTagFld2);
		if (sTagFld3 != '') columns.push(sTagFld3);
	}
	var options = elem.options;
	if( options != null )
	{
		for(var i=0, o; o = options[i]; i++)
		{
			if (o.selected)
			{
				var newRow = new Array();
				newRow.push(o.value);
				if (bSubmitTagFields)
				{
					if (sTagFld1 != '') newRow.push(o.getAttribute("tag_" + sTagFld1));
					if (sTagFld2 != '') newRow.push(o.getAttribute("tag_" + sTagFld2));
					if (sTagFld3 != '') newRow.push(o.getAttribute("tag_" + sTagFld3));
				}
				dataArray.push(newRow);
			}
		}
	}
	stdInsertHiddenList(f, multiSelListName, columns, dataArray);
}
function stdListBoxInit(name, formname, bSubmitTagFields, sTagFld1, sTagFld2, sTagFld3, bAllowMultiSel, multiSelListName, multiSelCodeField, value, selsize, defaultOption)
{
	var listBoxInfo = new Object();
	listBoxInfo.name = name;
	listBoxInfo.formname = formname;
	listBoxInfo.bSubmitTagFields = bSubmitTagFields;
	listBoxInfo.sTagFld1 = sTagFld1;
	listBoxInfo.sTagFld2 = sTagFld2;
	listBoxInfo.sTagFld3 = sTagFld3;
	listBoxInfo.bAllowMultiSel = bAllowMultiSel;
	listBoxInfo.multiSelListName = multiSelListName;
	listBoxInfo.multiSelCodeField = multiSelCodeField;

	if (!g_LANSAObjects.typeExists("std_listbox"))
	{
		addEvent(window, "load", stdListboxWindowLoaded);
	}
	g_LANSAObjects.addObject(listBoxInfo, "std_listbox", name);
	if (defaultOption)
	{
		stdListboxSelDft(name, value, selsize, defaultOption);
	}
}
function stdListboxWindowLoaded()
{
	var listboxes = g_LANSAObjects.getObjectsByType("std_listbox");
	for (var i=0, lbi; lbi = listboxes[i]; i++)
	{
		var lb = document.getElementById(lbi.name);
		if (lb)
		{
			var f = document.forms[lbi.formname];
			if (!f) f = lb.form;
			if (f) {
				stdListBoxInsertMultiSelectList(f, lb, lbi.bSubmitTagFields, lbi.sTagFld1, lbi.sTagFld2, lbi.sTagFld3, lbi.bAllowMultiSel, lbi.multiSelListName, lbi.multiSelCodeField)
			}
		}
	}
}
function stdListboxSelectedOptions(elem)
{
	var opts = elem.options;
	var selopts = new Array();
	for (var i = 0, o; o = opts[i]; i++)
	{
		if (o.selected) selopts.push(o);
	}
	return selopts;
}
function stdListboxSelDft(name, value, selsize, defaultOption)
{
	var elem = document.getElementById(name);
	if (elem)
	{
		var selopts = stdListboxSelectedOptions(elem);
		// If select size is 1 the first item is preselected by the browser
		if ((selopts.length == 0) || ((selsize == 1) && (value != selopts[0].value)))
		{
			var opts = elem.options;
			for (var i = 0, o; o = opts[i]; i++)
			{
				if (o.value == defaultOption)
				{
					o.selected = true;
					break;
				}
			}
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////
//
// Javascript support for std_banner
//
//////////////////////////////////////////////////////////////////////////////////////////
function stdBannerClicked(e, elem, url, WAMName, WRName, formName, protocol, target)
{
	if (!e) { if( window.event ) { e = window.event; } else { return; } }
	if ((url == "") && (WRName != ""))
	{
		var f = (!formName) ? getParentForm(elem) : createStdHiddenForm(WAMName, WRName, formName, protocol, target);
		if (f != null)
		{
			createReentryFields(f, elem.parentNode);
			submitForm(f, WAMName, WRName, target, protocol);
		}
		cancelEvent(e);
		return false;
	}
	else
	{
		if ((url != "") && (target != ""))
		{
			window.open(url, target);
			return false;
		}
	}
	return true;
}

//////////////////////////////////////////////////////////////////////////////////////////
//
// Javascript support for std_prompter
//
//////////////////////////////////////////////////////////////////////////////////////////
function stdPrompterInitIFrame() {
	var iframe = g_LANSAObjects.getObjectById("stdPrompterFrame");
	if (iframe == null)
	{
		iframe = document.createElement('iframe');
		iframe.id = (window.name == "") ? "stdPrompterFrame" : window.name + ".stdPrompterFrame";
		iframe.name = iframe.id;
		iframe.src = "";
		iframe.setAttribute("frameborder", "0");
		iframe.style.position = "absolute";
		iframe.style.visibility = "hidden";
		iframe.style.width = "1px";
		iframe.style.height = "1px";
		iframe.style.zIndex = 99999;

		iframe.getContentDoc = function() {
			try
			{
				return (this.contentDocument) ? this.contentDocument : iframe.contentWindow.document;
			} catch(err) {
				console.error("JavaScript error in iframe.getContentDoc: " + err.toString());
				return null;
			}
		};
		iframe.getContentDocLocation = function() {
			var doc = this.getContentDoc();
			if (doc)
			{
				try
				{
					return doc.location;
				} catch(err) {
					console.error("JavaScript error in iframe.getContentDocLocation: " + err.toString());
					return null;
				}
			}
		};
		g_LANSAObjects.addObject(iframe, "stdPrompterFrame", "stdPrompterFrame");

		// Firefox and Safari generate onload events, IE generates
		// onreadystatechange events. Opera generates both.
		iframe.onload = stdPrompterIFrameLoaded;
		if (!window.opera) iframe.onreadystatechange = stdPrompterIFrameRSChange;
		document.body.appendChild(iframe);
		if (iframe.contentWindow) iframe.contentWindow.name = iframe.id;
	}
	if (!iframe.__theBtn) iframe.__theBtn = null;
	return iframe;
}
function stdPrompterBtnClick(theBtn, formname, url, WAMName, WRName, protocol, width, height, autoResize, borderStyle, borderWidth, className, constrainSize)
{
	if (theBtn.className == "disabled") return;
	var iframe = stdPrompterInitIFrame();
	if ((iframe.__theBtn != theBtn) || (iframe.style.visibility == "hidden"))
	{
		if (iframe.__closeMeTO)
		{
			clearTimeout(iframe.__closeMeTO);
			iframe.__closeMeTO = null;
		}
		iframe.style.visibility = "hidden";
		iframe.windowRight = document.body.scrollLeft + document.body.clientWidth;
		iframe.windowBottom = document.body.scrollTop + document.body.clientHeight;
		iframe.winScrollLeft = document.body.scrollLeft;
		iframe.winScrollTop = document.body.scrollTop;
		//iframe.setAttribute("scrolling", "no");
		if (!width) width = "20px";
		if (!height) height = "20px";
		iframe.__width = width;
		iframe.__height = height;
		iframe.__theBtn = theBtn;
		iframe.__align = null;
		iframe.__isclosing = false;
		iframe.__autoResize = autoResize;
		iframe.__constrainSize = constrainSize;
		iframe.className = className;
		iframe.style.left = getAbsoluteLeft(theBtn) + theBtn.offsetWidth + "px";
		iframe.style.top = getAbsoluteTop(theBtn) + "px";
		iframe.style.borderStyle = borderStyle;
		iframe.style.borderWidth = borderWidth;
		iframe.style.width = "20px";
		iframe.style.height = "20px";
		iframe.__horizCorrection = iframe.offsetWidth - 20;
		iframe.__vertCorrection = iframe.offsetHeight - 20;
		iframe.style.width = width;
		iframe.style.height = height;
		if (WRName != '')
		{
			var f;
			if (formname == '') {
				var doc = iframe.getContentDoc();
				iframe.__ignoreRSChange = true;
				doc.open();
				doc.close();
				iframe.__ignoreRSChange = false;
				f = createStdHiddenForm(WAMName, WRName, "LANSA", protocol, iframe.id, doc);
			} else {
				f = createStdHiddenForm(WAMName, WRName, formname, protocol, iframe.id);
			}
			if (f != null)
			{
				createReentryFields(f, theBtn.parentNode);
				Lstd.Fields.check4VF_WAMEVENT(f, theBtn);
				submitForm(f, WAMName, WRName, iframe.id, protocol);
			}
		} else if (url != "") {
			iframe.src = "";
			iframe.src = url;
		}
		
		var spans = theBtn.parentNode.getElementsByTagName("span");
		var pi = new Object();
		for (var i=0, s; s = spans[i]; i++)
		{
			if (s.className == "field_mapping")
			{
				if (!pi["field_mapping"]) pi["field_mapping"] = new Object();
				var mapInfoStr = s.innerHTML.replace(/(<!---->)$/, "");
				var mapInfoArr = mapInfoStr.split(",");
				pi["field_mapping"][mapInfoArr[0]] = mapInfoArr[1];
			}
			else
			{
				pi[s.className] = s.innerHTML.replace(/(<!---->)$/, "");
			}
		}
		iframe.__prompterInfo = pi;
	}
	else
	{
		stdPrompterIFrameClose();
	}
}
function stdPrompterIFrameRSChange()
{
	var iframe = g_LANSAObjects.getObjectById("stdPrompterFrame");
	if (iframe.__ignoreRSChange) return;
	var doc = iframe.getContentDoc();
	if (doc && doc.readyState == "complete")
	{
		stdPrompterIFrameLoaded();
	}
}
function stdPrompterGetProperty(iframe, propName)
{
	var r = iframe.__prompterInfo[propName];
	if (r) return r;
	return "";
}
function stdPrompterIsCloseWR(iframe)
{
	var closingWRName = stdPrompterGetProperty(iframe, "closing_wrname").toLowerCase();
	var closingURL = stdPrompterGetProperty(iframe, "closing_url").toLowerCase();
	var contentDoc = iframe.getContentDoc();
	if (contentDoc == null) return false;
	var currLoc = iframe.getContentDocLocation();
	if (currLoc == null) return false;
	if (closingWRName != "")
	{
		var fields = iframe.getContentDoc().getElementsByName("_WEBROUTINE");
		for (var i=0, f; f=fields[i]; i++)
		{
			if( f.form == null || f.form.getAttribute("__x_temp_form") == null )
			{
				if (f.value.toLowerCase() == closingWRName) return true;
			}
		}
		var re = new RegExp("[?+&]webrtn=" + closingWRName + "([+&]|$)", "i");
		return (re.test(currLoc.search));
	}
	if (closingURL != "")
	{
		if (closingURL.charAt(0) == "/")
		{
			var match = currLoc.pathname + currLoc.search + currLoc.hash;
			return (closingURL == match.toLowerCase());
		}
		if (closingURL.match(/^https?:\/\//i)) return (closingURL == currLoc.href);
		var match = currLoc.host + currLoc.pathname + currLoc.search + currLoc.hash;
		return (closingURL == match.toLowerCase());
	}
	return false;
}
function stdPrompterExchangeFields(iframe)
{
	var fieldName = stdPrompterGetProperty(iframe, "field_name_to_exchange");
	var formName = stdPrompterGetProperty(iframe, "formname");
	var fieldMapping = stdPrompterGetProperty(iframe, "field_mapping");
	var srcFields = new Array();
	if (fieldName != "")
	{
		srcFields = iframe.getContentDoc().getElementsByName(fieldName);
	} else {
		var inputs = iframe.getContentDoc().getElementsByTagName("input");
		for (var i=0, f; f=inputs[i]; i++)
		{
			if (f.name && (f.name.length > 0) && (f.name.charAt(0) != "_") && (f.type == "text" || f.type == "hidden"))
			{
				srcFields.push(f);
			}
		}
	}
	var focusField = null;
	for (var i=0, f; f=srcFields[i]; i++)
	{
		var tfName = (fieldMapping) ? fieldMapping[f.name] : f.name;
		if (tfName)
		{
			var tf = stdPrompterGetTargetField(iframe, tfName, formName);
			if (tf)
			{
				tf.value = f.value;
				if (!focusField) focusField = tf;
				if (tf.dispatchEvent)
				{
					var evtObj = document.createEvent('HTMLEvents');
					evtObj.initEvent( 'change', false, true )
					tf.dispatchEvent(evtObj);
				}
				else if (tf.fireEvent) tf.fireEvent("onchange");
				else tf.onchange();
			}
		}
	}
	if (focusField)
	{
		// If the field is hidden the following will cause an error.
		try {
			focusField.focus();
			focusField.select();
		} catch(e) {}
	}
}
function stdPrompterGetTargetField(iframe, fieldName, formName)
{
	var fields = document.getElementsByName(fieldName);
	var f = null;
	var pf = iframe.__theBtn.form;
	for (var i=0; i<fields.length; i++)
	{
		if (i == 0) f = fields[0];
		if (formName && fields[i].form.name == formName)
		{
			f = fields[i];
			break;
		}
		if (fields[i].form == pf) f = fields[i];
	}
	return f;
}
function stdPrompterSetFrameSize(iframe)
{
	if (!iframe) iframe = g_LANSAObjects.getObjectById("stdPrompterFrame");
	
	var doc = iframe.getContentDoc();
	if( doc && doc.body )
	{
		doc.body.style["margin"] = "0px";
		var theBtn = iframe.__theBtn;
		var btnPos = {left:getAbsoluteLeft(theBtn), top:getAbsoluteTop(theBtn)};
		btnPos.right = btnPos.left + theBtn.offsetWidth;
		btnPos.bottom = btnPos.top + theBtn.offsetHeight;
		
		if (iframe.__autoResize)
		{
			var w, h;
			iframe.style.width = iframe.__width;
			iframe.style.height = iframe.__height;
			if ((document.compatMode == "BackCompat") || !Lstd.Utils.boxModel() || (navigator.userAgent.indexOf("MSIE 7") != -1)) {
				w = doc.body.scrollWidth + (iframe.offsetWidth - iframe.clientWidth) + 2;
				h = doc.body.scrollHeight + (iframe.offsetHeight - iframe.clientHeight) + 2;
			} else {
				w = doc.documentElement.scrollWidth;
				h = doc.documentElement.scrollHeight;
				doc.documentElement.style["overflow"] = "hidden";
			}
			iframe.style.width = w.toString() + "px";
			iframe.style.height = h.toString() + "px";
		}
		var newSize = {width:iframe.offsetWidth, height:iframe.offsetHeight};
		
		var space = {	right: iframe.windowRight - btnPos.right,
						left: btnPos.left - iframe.winScrollLeft,
						bottom: iframe.windowBottom - btnPos.top,
						top: btnPos.bottom - iframe.winScrollTop };
		var align = iframe.__align;
		if (!iframe.__align)
		{
			align = {horiz:1, vert:1};
			if ((newSize.width > space.right) && (space.left > space.right)) {
				if ((newSize.width <= space.left) || iframe.__constrainSize) align.horiz = -1;
			}
			if ((newSize.height > space.bottom) && (space.top > space.bottom)) {
				if ((newSize.height <= space.top) || iframe.__constrainSize) align.vert = -1;
			}
			iframe.__align = align;
		}
		
		if (iframe.__constrainSize) {
			var max = (align.horiz == 1) ? space.right : space.left;
			if (newSize.width > max) {
				newSize.width = max;
				iframe.style.width = (newSize.width - iframe.__horizCorrection) + "px";
			}
			max = (align.vert == 1) ? space.bottom : space.top;
			if (newSize.height > max) {
				newSize.height = max;
				iframe.style.height = (newSize.height - iframe.__vertCorrection) + "px";
			}
		}
		iframe.style.left = ((align.horiz == 1) ? btnPos.right : (btnPos.left - newSize.width)) + "px";
		iframe.style.top = ((align.vert == 1) ? btnPos.top : (btnPos.bottom - newSize.height)) + "px";
	}
}
function stdPrompterIFrameLoaded()
{
	var iframe = g_LANSAObjects.getObjectById("stdPrompterFrame");
	if (iframe && iframe.__isclosing) return;
	if (iframe.getContentDocLocation() == "about:blank") return;
	if (stdPrompterIsCloseWR(iframe))
	{
		stdPrompterExchangeFields(iframe);
		stdPrompterOnChange(iframe);
	}
	else
	{
		iframe.style.visibility = "visible";
		// If this window is opened via showModelessDialog then the focus below
		// will actually generate an onblur.  So we need to make sure the
		// onblur handler is removed and reset after the focus (and resulting blur).
		// (only needed for IE but it's easier to do the same for all browsers)
		iframe.onblur = null;
		removeEvent(iframe.getContentDoc(), "blur", stdPrompterIFrameLostFocus);
		iframe.focus();
		if (iframe.contentWindow) iframe.contentWindow.focus();
		window.setTimeout("stdPrompterSetOnBlur();", 1);
		if (window.opera)
		{
			// Opera scrolls the page to the top when a hidden iframe loads so 
			// scroll back to original position
			document.body.scrollLeft = iframe.winScrollLeft;
			document.body.scrollTop = iframe.winScrollTop;
			// Opera returns incorrect sizes if SetFrameSize is done now.
			// It needs a timeout to sort itself out.
			window.setTimeout("stdPrompterSetFrameSize()", 10);
		} else {
			stdPrompterSetFrameSize(iframe);
		}
	}
}
function stdPrompterSetOnBlur()
{
	// Firefox generates a frame.onblur when content elements get the focus
	// and Opera does not generate an onblur for the iframe but adding an 
	// onblur handler to the content document doesn't work in IE
	var iframe = g_LANSAObjects.getObjectById("stdPrompterFrame");
	if (!navigator.userAgent.match(/Firefox/) && !window.opera)
	{
		iframe.onblur = stdPrompterIFrameLostFocus;
	} else {
		addEvent(iframe.getContentDoc(), "blur", stdPrompterIFrameLostFocus);
	}
}
function stdPrompterOnChange(iframe)
{
	var formName = stdPrompterGetProperty(iframe, "formname");
	var WAMName = stdPrompterGetProperty(iframe, "on_change_wamname");
	var WRName = stdPrompterGetProperty(iframe, "on_change_wrname");
	var protocol = stdPrompterGetProperty(iframe, "on_change_protocol");
	var target = stdPrompterGetProperty(iframe, "on_change_target_window_name");
	var reentryField = stdPrompterGetProperty(iframe, "on_change_reentryfield");
	var reentryValue = stdPrompterGetProperty(iframe, "on_change_reentryvalue");
	var theBtn = iframe.__theBtn;

	stdPrompterIFrameClose(iframe);

	if (WAMName != "" && WRName != "")
	{
		var f = (!formName) ? getParentForm(theBtn) : createStdHiddenForm(WAMName, WRName, formName, protocol, target);
		if (f != null)
		{
			if (reentryField != "") insertHiddenField(f, reentryField, reentryValue);
			submitForm(f, WAMName, WRName, target, protocol);
		}
	}
}
function stdPrompterIFrameClose(iframe)
{
	if (!iframe) iframe = g_LANSAObjects.getObjectById("stdPrompterFrame");
	if (iframe != null)
	{
		if (iframe.__closeMeTO)
		{
			clearTimeout(iframe.__closeMeTO);
			iframe.__closeMeTO = null;
		}
		iframe.__theBtn = null;
		iframe.__propmterInfo = new Object();
		iframe.style.visibility = "hidden";
		iframe.style.height = "0px";
		iframe.style.width = "0px";
		var d = iframe.getContentDoc();
		iframe.__isclosing = true;
		d.close();
		d.open();
		d.close();
	}
}
function stdPrompterIFrameLostFocus()
{
	var iframe = g_LANSAObjects.getObjectById("stdPrompterFrame");
	if (iframe.style.visibility != "hidden")
	{
		if (!iframe.__closeMeTO) iframe.__closeMeTO = setTimeout("stdPrompterIFrameClose()", 200);
	}
}

//////////////////////////////////////////////////////////////////////////////////////////
//
// Javascript support for std_splitter_vert and std_splitter_horz
//
//////////////////////////////////////////////////////////////////////////////////////////
Lstd.Weblets.stdSplitter = function () {};
Lstd.Weblets.stdSplitter.addResizeCheck = function(splitter) {
	// Non IE browsers have no resize event on DOM elements so we need to use a timeout to
	// check the size every so often.
	if (!this._splitters) {
		this._splitters = [];
	}
	this._splitters.push(splitter);
	splitter._lastSize = {w: splitter.element.offsetWidth, h: splitter.element.offsetHeight};
	this._resizeCheck();
}
Lstd.Weblets.stdSplitter._resizeCheck = function() {
	if (!this._splitters || this._timeoutID) return;
	var self = this;
	this._timeoutID = window.setTimeout(function() {
		for (var i=0,s; s=self._splitters[i]; i++) {
			var newSize = {w: s.element.offsetWidth, h: s.element.offsetHeight};
			if ((newSize.w != s._lastSize.w) || (newSize.h != s._lastSize.h)) {
				s.resize();
				s._lastSize = newSize;
			}
		}
		self._timeoutID = 0;
		self._resizeCheck();
	},250);
}
Lstd.Weblets.stdSplitter.prototype.init = function(splitterID, splitterData) {
		this.div1Size = splitterData.panel1Size || 20;
		this.element = document.getElementById(splitterID);
		this.div1 = this.element.childNodes[0];
		this.divider = this.element.childNodes[1];
		this.div2 = this.element.childNodes[2];
		this.type = splitterData.type;
		this.styleSizeProp = this.type == "v" ? "width" : "height";
		this.stylePosProp = this.type == "v" ? "left" : "top";
		this.offsetProp = this.type == "v" ? "offsetWidth" : "offsetHeight";
		this.clientProp = this.type == "v" ? "clientWidth" : "clientHeight";
		if (!Lstd.Utils.boxModel()) {
			this.element.parentNode.style.overflow = "hidden";
		}
		this.divider.style.display = "block";
		this.resize();
		var self = this;
		//addEvent(this.element, "resize", function(e) { self.resize(); }, false);
		addEvent(this.divider, "mousedown", function(e) { self.onMouseDown(e); }, false);
		
		Lstd.Weblets.stdSplitter.addResizeCheck(this);
	};
Lstd.Weblets.stdSplitter.prototype.resize = function() {
		var total = this.element[this.clientProp];
		this.div1.style[this.styleSizeProp] = (total * this.div1Size / 100) + "px";
		this.divider.style[this.stylePosProp] = this.div1[this.offsetProp] + "px";
		this.div2.style[this.styleSizeProp] = (total - this.div1[this.offsetProp] - this.divider[this.offsetProp]) + "px";
		this.div2.style[this.stylePosProp] = (this.div1[this.offsetProp] + this.divider[this.offsetProp]) + "px";
		this.div1.firstChild.style.width = this.div1.clientWidth + "px";
		this.div1.firstChild.style.height = this.div1.clientHeight + "px";
		this.div2.firstChild.style.width = this.div2.clientWidth + "px";
		this.div2.firstChild.style.height = this.div2.clientHeight + "px";
	};
Lstd.Weblets.stdSplitter.prototype.onMouseDown = function(e) {
	this.endDrag();
	
	this._mouseOffset = (this.type == "v") ? getRelativeMouseX(this.divider, e) : getRelativeMouseY(this.divider, e);

	var spCover = document.getElementById('StdSplitterDragBar');
	if (spCover) spCover.parentNode.removeChild(spCover);
	
	var spCover = document.createElement('div');
	spCover.id = "StdSplitterDragCover";

	var s = spCover.style;
	s.cursor = getCurrentStyle(this.divider, "cursor");
	
	var spBar = document.createElement('div');
	spBar.appendChild(document.createComment(""));
	spBar.id = "StdSplitterDragBar";
	s = spBar.style;
	s.cursor = getCurrentStyle(this.divider, "cursor");
	s.position = "absolute";
	s.left = this.divider.offsetLeft + "px";
	s.top = this.divider.offsetTop + "px";
	s.width = this.divider.offsetWidth + "px";
	s.height = this.divider.offsetHeight + "px";
	
	// An IE bug causes some mouse events to be sent to objects under the cover
	// instead of the drag bar. causing the divider to "freeze".  Placing a div
	// with a background colour over everything stops the problem.  Giving the
	// div an opacity of 0 makes it invisible to the user.
	var spCover2 = document.createElement('div');
	spCover2.appendChild(document.createComment(""));
	spCover2.id = "StdSplitterDragCover2";


	spCover.appendChild(spBar);
	spCover.appendChild(spCover2);
	this.element.appendChild(spCover);
	this.dragBar = spBar;
	this.dragCover = spCover;

	var self = this;
	this._onMouseMove = function(e) { self.onMouseMove(e); };
	this._onMouseUp = function(e) { self.onMouseUp(e); };
	if (document.addEventListener)
	{
		document.addEventListener('mousemove',self._onMouseMove,true);
		document.addEventListener('mouseup',self._onMouseUp,true);
	}
	else
	{
		spBar.attachEvent("onmousemove", self._onMouseMove);
		spBar.attachEvent("onmouseup", self._onMouseUp);
		if (spBar.setCapture) { spBar.setCapture(); };
	}
	
	cancelEvent(e);
	return false;
};
Lstd.Weblets.stdSplitter.prototype.onMouseMove = function(e) {
	var p = this.dragCover, db = this.dragBar, max = p[this.clientProp] - db[this.offsetProp];

	var newPos = ((this.type == "v") ? getRelativeMouseX(p, e) : getRelativeMouseY(p, e)) - this._mouseOffset;
	if (newPos < 0) newPos = 0;
	if (newPos > max) newPos = max;
	db.style[this.stylePosProp] = newPos + "px";

	cancelEvent(e);
	return false;
};
Lstd.Weblets.stdSplitter.prototype.onMouseUp = function(e) {
	var s = this.styleSizeProp, c = this.clientProp, o = this.offsetProp,
	delta = ((this.type == "v") ? getRelativeMouseX(this.divider, e):getRelativeMouseY(this.divider, e)) - this._mouseOffset,
	size1 = this.div1[o] + delta, size2 = this.div2[o] - delta;
	
	if (size1 < 0) {
		size2 += size1;
		size1 = 0;
	} else if (size2 < 0) {
		size1 += size2;
		size2 = 0;
	}
	
	this.div1.style[s] = size1 + "px";
	this.div2.style[s] = size2 + "px";
	this.div1.firstChild.style[s] = this.div1[c] + "px";
	this.div2.firstChild.style[s] = this.div2[c] + "px";

	this.div1Size = size1 / this.element[this.clientProp] * 100;
	this.divider.style[this.stylePosProp] = this.div1[this.offsetProp] + "px";
	this.div2.style[this.stylePosProp] = (this.div1[this.offsetProp] + this.divider[this.offsetProp]) + "px";
	
	this.endDrag();
	cancelEvent(e);
	return false;

};
Lstd.Weblets.stdSplitter.prototype.endDrag = function(e) {
	if (this.dragCover) {
		if (document.removeEventListener)
		{
			document.removeEventListener('mousemove',this._onMouseMove,true);
			document.removeEventListener('mouseup',this._onMouseUp,true);
		}
		else
		{
			if (this.dragBar.releaseCapture) { this.dragBar.releaseCapture(); };
			this.dragBar.detachEvent("onmousemove", this._onMouseMove);
			this.dragBar.detachEvent("onmouseup", this._onMouseUp);
		}
		this.dragCover.parentNode.removeChild(this.dragCover);
	}
	this._mouseOffset = 0;
	this.dragBar = null;
	this.dragCover = null;
};

//////////////////////////////////////////////////////////////////////////////////////////
//
// Javascript support for std_tab_pages
//
//////////////////////////////////////////////////////////////////////////////////////////
function stdTabPagesInit(name, formname, selectedIndexField, selectedIndex)
{
	var tabInfo = new Object();
	tabInfo.form = formname;
	tabInfo.selectedIndexField = selectedIndexField;
	if (!g_LANSAObjects.typeExists("std_tab_pages"))
	{
		addEvent(window, "load", stdTabPagesWindowLoaded);
	}
	g_LANSAObjects.addObject(tabInfo, "std_tab_pages", name);
	
	var tabPages = document.getElementById(name);
	if (document.compatMode && (document.compatMode == "BackCompat")) {
		tabPages.className += " quirksMode";
	}
	tabInfo.table = tabPages;
	tabInfo.initialIndex = selectedIndex;
	var si = selectedIndex-1;
	var theUL = getElementsByClassAndTag(tabPages, "std_tab_pages_tabs", "ul")[0];
	var theItems = theUL.getElementsByTagName("li");
	if (si >= theItems.length) si = 0;
	var selectedLI = theItems[si];
	while (selectedLI && (selectedLI.className == "std_tab_disabled"))
	{
		selectedLI = theItems[++si];
	}
	if (selectedLI)
	{
		tabInfo.selectedLI = selectedLI;
		selectedLI.className = "std_tab_active";
		var theImgs = getElementsByClassAndTag(selectedLI, "", "img");
		if (theImgs && theImgs.length > 0)
		{
			var src = theImgs[0].getAttribute("_sel_src");
			if (src && src != "") theImgs[0].src = src;
		}
		var t = getParentElement(theUL, "table");
		var contentDivs = getElementsByClassAndTag(t, "std_tab_pages_content", "div");
		stdTabPagesShowContent(contentDivs, si);
	}
}
function stdTabPagesWindowLoaded()
{
	var tabs = g_LANSAObjects.getObjectsByType("std_tab_pages");
	for (var i=0, tabInfo; tabInfo = tabs[i]; i++)
	{
		if (tabInfo.selectedIndexField != "")
		{
			var f = document.forms[tabInfo.form];
			if (!f) f = getParentForm(tabInfo.table);
			if (f) {
				insertHiddenField(f, tabInfo.selectedIndexField, tabInfo.initialIndex)
			}
		}
	}
}
function stdTabPagesSelectTab(tabsID, tabNumber) {
	if ((!tabNumber) || (tabNumber < 1)) tabNumber = 1;
	var li = document.getElementById(tabsID + "_tab" + tabNumber);
	if (li) {
		var a = li.getElementsByTagName("a")[0];
		if (a) {
			stdTabPagesTabClicked(a, tabNumber);
		}
	}
}
function stdTabPagesTabClicked(theAnchor, contentDivNum)
{
	var theLI = getParentElement(theAnchor, "li");
	if (theLI.className == "std_tab_disabled") return false;
	var theUL = getParentElement(theAnchor, "ul");
	var table = getParentElement(theUL, "table");
	var tabInfo = g_LANSAObjects.getObjectById(table.id);

	if (theLI)
	{
		var oldLI = tabInfo.selectedLI;
		if (oldLI)
		{
			if (oldLI.className == "std_tab_active") oldLI.className =  "";
			var theImgs = getElementsByClassAndTag(oldLI, "", "img");
			if (theImgs && theImgs.length > 0)
			{
				var src = theImgs[0].getAttribute("_unsel_src");
				if (src && src != "") theImgs[0].src = src;
			}
		}

		tabInfo.selectedLI = theLI;
		theLI.className =  "std_tab_active";
		var theImgs = getElementsByClassAndTag(theLI, "", "img");
		if (theImgs && theImgs.length > 0)
		{
			var src = theImgs[0].getAttribute("_sel_src");
			if (src && src != "") theImgs[0].src = src;
		}
	
		var contentDivs = getElementsByClassAndTag(table, "std_tab_pages_content", "div");
		stdTabPagesShowContent(contentDivs, contentDivNum-1);
		if ((tabInfo.form != '') && (tabInfo.selectedIndexField != ''))
		{
			var f = document.forms[tabInfo.form];
			insertHiddenField(f, tabInfo.selectedIndexField, contentDivNum);
		}
	}
	return false;
}
function stdTabPagesShowContent(contentDivs, selectedDivIndex)
{
	for (var i=0, c; c=contentDivs[i]; i++)
	{
		c.style.display = (i == selectedDivIndex) ? "" : "none";
		if (i == selectedDivIndex)
		{
			lansaEvent_Fire(c, "lansaEventOnDisplay");
			lansaEvent_Fire(c, g_lweb_navPanelReloadArrayName, true);
			lansaEvent_Fire(c, g_lweb_navPanelDelayLoadArrayName, false);
			c.removeAttribute(g_lweb_navPanelDelayLoadArrayName);
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////
//
// Javascript support for list paging buttons
//
//////////////////////////////////////////////////////////////////////////////////////////
function stdListPageBtnClick(e, btnType, WAMName, WRName, formName, protocol, reentryField, prevCondFld, prevCondVal, nextCondFld, nextCondVal, pageCountFld, pageCountVal)
{
	if(!e) { if( window.event ) { e = window.event; } else { return; } }
	var btn = getEventTarget(e);
	if (btn == null) return;
	if(isDblClick(btn)){{return false;}};
	var f = (!formName) ? getParentForm(btn) : createStdHiddenForm(WAMName, WRName, formName, protocol, "");
	if (f != null)
	{
		insertHiddenField(f, reentryField, btnType);
		insertHiddenField(f, prevCondFld, prevCondVal);
		insertHiddenField(f, nextCondFld, nextCondVal);
		insertHiddenField(f, pageCountFld, pageCountVal);
		Lstd.Fields.check4VF_WAMEVENT(f, btn);
		submitForm(f, WAMName, WRName, "", protocol);
	}
	cancelEvent(e);
	return false;
}
Lstd.Weblets.stdListPagingImages = {
	_initDone: false,
	init: function(id, data) {
		var slpi = Lstd.Weblets.stdListPagingImages;
		if (!slpi._initDone && window.jQuery) {
			$(".stdListPagingButtons img").hover(function() {
				this.src = this.src.replace(/\/normal\//,"/hot/");
			}, function() {
				this.src = this.src.replace(/\/hot\//,"/normal/");
			});
		}
		slpi._initDone = true;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////
//
// Javascript support for nav panel weblet
//
//////////////////////////////////////////////////////////////////////////////////////////
function stdNavPanel2FrameInfo(iframeName, formname,
	wamName, wrName, protocol, async, sizeToContent, sizeToContentAxis, width, height,
	waitContentImg, waitContentImgAlignment, waitContentImgClass, waitContentClass, 
	waitContentTimeout)
{
	this.name = iframeName;
	this.formname = formname;
	this.id = formname + "_" + iframeName;

	this.iframe = null; // iframe not created yet

	this.wamName = wamName;
	this.wrName = wrName;
	this.protocol = protocol;
	this.async = async;
	this.sizeToContent = sizeToContent;
	this.sizeToContentAxis = sizeToContentAxis;
	this.width = width;
	this.height = height;
	this.waitContentImg = waitContentImg;
	this.waitContentImgAlignment = waitContentImgAlignment;
	this.waitContentImgClass = waitContentImgClass;
	this.waitContentClass = waitContentClass;
	this.waitContentTimeout = waitContentTimeout;

	this.url = null;
	this.waitContent = null;
	
	this.loaded = false;
	this.loadQueued = false;
	this.reloadQueued = false;
	this.sized = false;
	this.waitImgLoaded = false;
	this.waitContentDone = false;

	var ifo = this;

	this.getFrame = function()
	{
		if (ifo.iframe == null)
		{
			ifo.iframe = document.getElementById(ifo.id);
		}
		return ifo.iframe;
	};

	this.getDocument = function()
	{
		var theFrame = ifo.getFrame();
		return (theFrame.contentDocument) ? theFrame.contentDocument : theFrame.contentWindow.document; // Don't cache
	};

	this.getUrl = function()
	{
		if (ifo.url == null)
		{
			ifo.url = getHiddenSpanContent(ifo.getFrame().parentNode, "nav_url");
		}
		return ifo.url;
	};

	this.getWaitContent = function()
	{
		if (ifo.waitContent == null)
		{
			ifo.waitContent = getHiddenSpanContent(ifo.getFrame().parentNode, "wait_content");
		}
		return ifo.waitContent;
	};

	this.loadFrame = function()
	{
		if (!ifo.loaded)
		{
			if (!ifo.loadQueued)
			{
				// Parent elements can tell the nav_panel not to load until it is
				// displayed (e.g. the tab_pages weblet).  They do this by
				// registering support for the g_lweb_navPanelDelayLoadArrayName
				// event.
				ifo.loadQueued = lansaEvent_RegisterListener(ifo.getFrame().parentNode, g_lweb_navPanelDelayLoadArrayName, ifo.reloadFrame);
				if (ifo.loadQueued) return;
			}
			ifo.loaded = true;
			ifo.loadQueued = false;
			if (!ifo.async && ifo.wrName != "" && ifo.getUrl() == "")
			{
				ifo.navigate();
			} else {
				setTimeout(function(){ifo.navigate()}, 0);
			}
		}
		else
		{
			ifo.resizeFrame();
			ifo.resetLoadState();
		}
	};
	this.reloadFrame = function(bResetLoaded)
	{
		if( bResetLoaded != null && bResetLoaded ) ifo.loaded = false;
		ifo.loadFrame();
	};
	this.navigate = function()
	{
		var doc = ifo.getDocument();
		if ((ifo.getWaitContent() != "" || ifo.waitContentImg != "") && ifo.waitContentTimeout > -1)
		{
			if (!ifo.IntervalId)
			{
				ifo.IntervalId = setInterval(ifo.navigate, ifo.waitContentTimeout);
				return;
			}
			else
			{
				if (!ifo.waitImgLoaded || !doc.body) { return; }
				clearInterval(ifo.IntervalId);
				delete ifo.IntervalId;
			}
		}
		var theFrame = ifo.getFrame();
		var theUrl = ifo.getUrl();

		if (ifo.wrName != '' && theUrl == '')
		{
			// Create form inside the iframe to avoid IE "Operation aborted" (kb927917). However, if form name
			// is an existing form, we must use it.
			var fdoc = stdFindForm(document, ifo.formname) ? document : doc;
			var f = createStdHiddenForm(ifo.wamName, ifo.wrName, ifo.formname, ifo.protocol, ifo.name, fdoc);
			if (f != null)
			{
				var reentryFieldList = [];

				// Update reentry field if it exists in the existing form. If it is an existing form and the field
				// isn't already there, send it in the url. If the form is a new form, create it in the new form.
				findReentryFields(
					f,
					theFrame.parentNode,
					function(form, reentryField, reentryValue) {
						if (form.elements[reentryField] || (fdoc == ifo.getDocument()))
						{
							insertHiddenField(form, reentryField, reentryValue);
						}
						else
						{
							reentryFieldList.push({name: reentryField, value: reentryValue});
						}
					});
				Lstd.Fields.check4VF_WAMEVENT(f, theFrame);
				submitForm(f, ifo.wamName, ifo.wrName, ifo.name, ifo.protocol, reentryFieldList);
			}
		}
		else if (theUrl != '')
		{
			theFrame.src = theUrl;
		}
	};
	this.resetLoadState = function()
	{
		if (!ifo.reloadQueued)
		{
			ifo.reloadQueued = lansaEvent_RegisterListener(ifo.getFrame().parentNode, g_lweb_navPanelReloadArrayName, ifo.reloadFrame);
		}
	};
	this.resizeFrame = function(isEvt)
	{
		var theFrame = ifo.getFrame();
		if(theFrame.getAttribute("_fr") == 1) return;

		if (ifo.sizeToContent != "false" && !ifo.sized)
		{
			var prevW = null;
			var prevH = null;
	
			var isResized = false;
			if( theFrame.readyState == null || theFrame.readyState == "complete" )
			{
				var doc = ifo.getDocument();
				if (doc && doc.body)
				{
					if (ifo.sizeToContentAxis != "height")
					{
						prevW = theFrame.style.width;
						theFrame.style.width = this.width;
					}
					if (ifo.sizeToContentAxis != "width")
					{
						prevH = theFrame.style.height;
						theFrame.style.height = this.height;
					}
					// Old version of the prompter uses nav_panel and attaches alignment
					// functions as attributes.  New prompter doesn't and it will not work in
					// IE but, just in case this is called by an old prompter or similar code
					// we will continue to support it.
					var funcLeftAlign = theFrame["_left_align_func"];
					var funcTopAlign = theFrame["_top_align_func"];
					if( ifo.sizeToContentAxis != "height" )
					{
						var w = doc.body.scrollWidth;
						w = doc.body.scrollWidth + theFrame.offsetWidth - theFrame.clientWidth;
						if(w > 0)
						{
							if (funcLeftAlign != null) funcLeftAlign(w);
							theFrame.style.width = w.toString() + "px";
							isResized = true;
						}
					}
					if( ifo.sizeToContentAxis != "width"  )
					{
						var h = doc.body.scrollHeight;
						h = doc.body.scrollHeight + theFrame.offsetHeight - theFrame.clientHeight;
						if(h > 0)
						{
							if( funcTopAlign != null ) funcTopAlign(h);
							theFrame.style.height = h.toString() + "px";
							isResized = true;
						}
					}
				}
				ifo.sized = true;
				if (ifo.sizeToContent == "once") ifo.sizeToContent = false;
				theFrame.removeAttribute("_left_align_func");
				theFrame.removeAttribute("_top_align_func");
			}

			if (!isEvt && !isResized)
			{
				if (prevW != null) theFrame.style.width = prevW;
				if (prevH != null) theFrame.style.height = prevH;
			}
		}
	};
}
function stdNavPanel2Init(iframeName, formname,
	wamName, wrName, protocol, async, sizeToContent, sizeToContentAxis, width, height,
	waitContentImg, waitContentImgAlignment, waitContentImgClass, waitContentClass, 
	waitContentTimeout)
{
	var iFrameInfo = new stdNavPanel2FrameInfo(iframeName, formname,
	wamName, wrName, protocol, async, sizeToContent, sizeToContentAxis, width, height,
	waitContentImg, waitContentImgAlignment, waitContentImgClass, waitContentClass, 
	waitContentTimeout);

	g_LANSAObjects.addObject(iFrameInfo, "std_nav_panel", iFrameInfo.id);
}
function stdNavPanel2OnLoad(theFrame)
{
	var ifo = g_LANSAObjects.getObjectById(theFrame.id);
	if (navigator.userAgent.indexOf("WebKit") > 0) 
	{
		// See CCS 142006
		if (!ifo.webkitCount) 
		{
			ifo.webkitCount = 1;
			return;
		}
		ifo.webkitCount++;
	}
	if(theFrame.getAttribute("_fr") == 1) return;
	var doc = (theFrame.contentDocument) ? theFrame.contentDocument : theFrame.contentWindow.document;
	if (doc && doc.defaultView && doc.defaultView.waitImgLoaded) return;
	
	if (ifo.loadQueued) return;

	var theUrl = ifo.getUrl();
	var theWaitContent = ifo.getWaitContent();

	if (!ifo.waitContentDone && (((theWaitContent != "" || ifo.waitContentImg != "") && ifo.wrName != "" && theUrl == "") || (theUrl != "")))
	{
		if (!ifo.loaded)
		{
			if( doc != null )
			{
				doc.open();
				doc.writeln("<html><head>");
				if (document.styleSheets)
				{
					for (var i=0; i<document.styleSheets.length; i++)
					{
						var l = document.styleSheets[i];
						var isLink = false;
						if (l.ownerNode && l.ownerNode instanceof HTMLLinkElement) isLink = true;
						if (l.owningElement && l.owningElement.nodeName == "LINK") isLink = true;
						var href = stdNavPanelGetExpandedURL(l.href);
						if (isLink && href != null && href.length > 0)
						{
							doc.writeln("<link href=\"" + href + "\"" + " type=\"text/css\" rel=\"stylesheet\" />");
						}
					}
				}
				doc.writeln("<" + "script type=\"text/javascript\">");
				doc.writeln("function waitImgLoaded() {");
				doc.writeln("parent.stdNavPanel2WaitImageLoaded(parent.document.getElementById('" + ifo.id + "'));");
				doc.writeln("}");
				doc.writeln("</script>");
				doc.writeln("</head>\n<body>");
				doc.writeln("<table style=\"height:100%;width:100%\" cellpadding=\"0\" cellspacing=\"0\">");
				doc.writeln("<tbody><tr><td class=\"" + ifo.waitContentClass + "\">");
				if (ifo.waitContentImg != "")
				{
					var imgTag = "<img onerror=\"waitImgLoaded();\" onload=\"waitImgLoaded();\" class=\"" + ifo.waitContentImgClass + "\" src=\"" + stdNavPanelGetExpandedURL(ifo.waitContentImg) + "\" />";
					switch (ifo.waitContentImgAlignment)
					{
						case "top":
							doc.writeln(imgTag + "<br />" + theWaitContent);
							break;
						case "right":
							doc.writeln(theWaitContent + imgTag);
							break;
						case "bottom":
							doc.writeln(theWaitContent + "<br />" + imgTag);
							break;
						default:
							doc.writeln(imgTag + theWaitContent);
					}
				}
				else
				{
					doc.writeln(theWaitContent);
					ifo.waitImgLoaded = true;
				}
				doc.writeln("</td></tr></tbody></table>");
				doc.writeln("</body>\n</html>");
				theFrame.setAttribute("_fr", 1);
				doc.close();
				ifo.waitContentDone = true;
				doc.frameInfo = ifo;
				theFrame.removeAttribute("_fr");
			}
		}
	}
	if (ifo.sizeToContent == "true") ifo.sized = false;
	ifo.loadFrame();
}
function stdNavPanel2OnResize(theFrame)
{
	var ifo = g_LANSAObjects.getObjectById(theFrame.id);
	if (ifo.sized) ifo.resizeFrame(true);
}
function stdNavPanel2WaitImageLoaded(theFrame)
{
	var ifo = g_LANSAObjects.getObjectById(theFrame.id);
	ifo.waitImgLoaded = true;
}
//////////////////////////////////////////////////////////////////////////////////////////
//
// Javascript support for LargeList weblet
//
//////////////////////////////////////////////////////////////////////////////////////////

function stdLargeList(name, WAMName, WRName, listname, columnCssClass, showBusyBox, formatTarget, width, height, fieldNamesToExchange)
{
	this.name = name;
	this.WAMName = WAMName;
	this.WRName = WRName;
	this.listname = listname;
	this.columnCssClass = columnCssClass;
	var tmp = formatTarget.split("-");
	this.format = tmp[0];
	this.target = tmp[1];
	this.busyBox = null;
	this.width = width;
	this.height = height;
	this.fieldNamesToExchange = fieldNamesToExchange;
	if (g_lmxlSKMethod == "hidden")
	{
		if (this.fieldNamesToExchange != "") this.fieldNamesToExchange += ", ";
		this.fieldNamesToExchange += "_SESSIONKEY";
	}
	this.pageElement = document.getElementById(name);

	var me = this;
	this.listURL = function ()
	{
		var theURL = g_lxmlAR + "?wam=" + this.WAMName + "&webrtn=" + this.WRName +
				"&part=" + g_lxmlPartition + "&lang=" + g_lxmlLang;
		if ((g_debug != null) && (g_debug.length > 0)) theURL += "&debug=" + g_debug;
		if ((g_lmxlSKMethod == "url") && (g_lxmlSK != "")) theURL += "&sid=" + g_lxmlSK;

		theURL += "&lfmt=1&fmtarg(format)=" + this.format
		if (this.format == "xhtml")
		{
			if (this.target == "inline")
			{
				theURL += "-inline";
			}
			else
			{
				theURL += "-iframe&fmtarg(iframeid)=" + this.name;
			}
			theURL += "&fmtarg(css)=" + ((columnCssClass) ? "col" : "row");
		}
		theURL += "&fmtarg(list)=" + this.listname + this.fieldsForURL();
		if (this.format == "csv") theURL += "&fmtarg(ext)=.csv";
		theURL += "&_=" + (new Date()).getTime();
		return theURL;
	}
	this.fieldsForURL = function()
	{
		return stdInsertFieldsIntoUrl(this.fieldNamesToExchange);
	}
	this.httpRequestHandleResponse = function(xhr)
	{
		if (xhr.status == 200) me.pageElement.innerHTML = xhr.responseText;
		else me.pageElement.innerHTML = xhr.status + ": " + xhr.statusText;
		if (me.busyBox) stdStopBusyBox(me.busyBox);
	}
	this.httpRequestCleanUp = function()
	{
		me.httpRequest.cleanUp();
	}
}
function initStdLargeList(name, WAMName, WRName, listname, columnCssClass, showBusyBox, formatTarget, imagesPath, width, height, fieldNamesToExchange)
{
	var listInfo = new stdLargeList(name, WAMName, WRName, listname, columnCssClass, showBusyBox, formatTarget, width, height, fieldNamesToExchange);
	g_LANSAObjects.addObject(listInfo, "std_largelist", name);
	
	if (showBusyBox && (listInfo.target != "window"))
	{
		var procMsg = g_StdLocaleMgr.getMessageText("Processing1");
		if (imagesPath == null) imagesPath = "/images";

		try
		{
			listInfo.busyBox = new BusyBox(name + "_busyboxframe", 
				"g_LANSAObjects.getObjectById('" + name +"').busyBox",
				4, imagesPath + "/gears_ani_", ".gif", 125, 147, 207, null,
				getHiddenSpanContent(listInfo.pageElement.parentNode, "wait_content"));
		}
		catch (e) {}
		if (listInfo.busyBox) listInfo.busyBox.Show();
		window.status = procMsg;
	}

	if (listInfo.target == "iframe")
	{
		listInfo.pageElement.src = listInfo.listURL();
	} else if (listInfo.target == "inline") {
		listInfo.httpRequest = new StdHttpRequest();
		addEvent(window, "unload", listInfo.httpRequestCleanUp, false);
		listInfo.httpRequest.sendRequest(listInfo.listURL(), listInfo.httpRequestHandleResponse, true);
	} else if (listInfo.target == "window") {
		listInfo.pageElement.href = listInfo.listURL();
	}
}
function stdLargeList_onLoad(iframe)
{
	var listInfo = g_LANSAObjects.getObjectById(iframe.id);
	if (!listInfo) return;
	if (listInfo.format = "xhtml")
	{
		var pad = 10;
		var pw = iframe.contentWindow.parent;	
		iframe.style.width = (listInfo.width == "auto") ? ((stdGetWindowWidth(pw) + pad) + "px") : listInfo.width;
		iframe.style.height = (listInfo.height == "auto") ? ((stdGetWindowHeight(pw) + pad) + "px") : listInfo.height;
	}
	if ((listInfo.busyBox != null) && listInfo.busyBox.Hide) listInfo.busyBox.Hide(); // castlebusybox.js must be included by caller XHTML
	window.status = g_StdLocaleMgr.getMessageText("Done1");
	stdStopBusyBox(listInfo.busyBox);
}
function stdLargeList_onReadyStateChange(iframe)
{
	var listInfo = g_LANSAObjects.getObjectById(iframe.id);
	if ((iframe.readyState == "interactive") || (iframe.readyState == "complete")) stdStopBusyBox(listInfo.busyBox);
}

// Dynamic Select weblet
Lstd.Weblets.stdDynamicSelect = function () {};

Lstd.Weblets.stdDynamicSelect.prototype.init = function(id, data) {
	if (id == "") {
		console.error("A Dynamic Select weblet must have an ID");
		return;
	}
	this.id = id;
	this.data = data;

	var $elem = this.$elem = jQuery(Lstd.Utils.makeSafeId(id));
	
	if (!data.listname) {
		data.codeField = "value";
		data.captionField = "caption";
		data.selectorField = "selector";
	}
	data.onChangeExtraFields = data.onChangeExtraFields || [];
	data.updateFieldsToSubmit = data.updateFieldsToSubmit || [];

	if (data.displayMode != "output") {
		$elem.bind("refreshList", this, function(e){
			e.data.refreshList();
		});
		$elem.bind("change", this, function(e){
			e.data.selectionChanged();
		});

		if (data.updateOnFieldChange) {
			var fldId = this._getOtherFieldID(data.updateOnFieldChange);
			if (fldId) {
				jQuery("input[name=@],select[name=@]".replace(/@/g,Lstd.Utils.escapeForJQSelector(fldId))).change(function(e) {
					$elem.trigger("refreshList");
				});
			}
		}
	}
	this.buildSelect();
}
Lstd.Weblets.stdDynamicSelect.prototype._getOtherFieldID = function(fieldName) {
	var d = this.data, a, id="";
	if (fieldName) {
		if (d.xmlColumnId) {
			a = d.xmlColumnId.split(".");
			a[2] = fieldName;
			id = a.join(".");
			if (!Lstd.Fields.fieldExists(id)) id = "";
		}
		if (!id) {
			id = Lstd.Fields.fieldExists(fieldName) ? fieldName : "";
		}
	}
	return id;
}
Lstd.Weblets.stdDynamicSelect.prototype.buildSelect = function() {
	var $sel = this.$elem, d = this.data, valueList = {}, selectorValue;
	
	if (d.allowMultiSelect && d.multiSelectListname && d.multiSelectCodefield) {
		var list = Lstd.Lists[d.multiSelectListname];
		if (list) {
			list.entries().each(function(entry) {
				valueList[entry.col(d.multiSelectCodefield)] = true;
			});
		}
	} else {
		valueList[d.value] = true;
	}

	if (d.selectorValueField) {
		var fldId = this._getOtherFieldID(d.selectorValueField);
		selectorValue = fldId ? (Lstd.Fields.getValue(fldId) || "") : "";
	}
	selectorValue = selectorValue || "";

	if (d.displayMode == "output") {
		$sel.empty();
		if (d.allowMultiSelect && d.multiSelectListname && d.multiSelectCodefield) {
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
		
		d.list.entries().each(function(entry) {
			if (((d.selectorField == "") || (d.selectorValueField == "")) || ( (selectorValue == entry.col(d.selectorField)))) {
				var opt = new Option("", entry.col(d.codeField));
				$sel[0].options[$sel[0].options.length] = opt;
				opt.innerHTML = entry.col(d.captionField);
				if (valueList[entry.col(d.codeField)]) opt.setAttribute("selected", "selected");
			}
		});
	}
}
Lstd.Weblets.stdDynamicSelect.prototype.refreshList = function() {
	var d = this.data, wrFields=[], request, self = this, initialVal = this.$elem.val();
	if (d.updateWamName && d.updateWrName) {
		if (d.updateFieldsToSubmit && d.updateFieldsToSubmit.length) {
			for (var i=0,fld; fld=d.updateFieldsToSubmit[i]; i++) {
				fieldToSubmit = { name: fld.field, value: fld.value };
				if (fld.value === undefined) {
					var fldId = this._getOtherFieldID(fld.valueField);
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
Lstd.Weblets.stdDynamicSelect.prototype.selectionChanged = function() {
	var d = this.data, wrFields=[], request, self = this, win = window, url, val,
	wam = d.onChangeWamName, wr = d.onChangeWrName, selValues=[];
	
	var f = createStdHiddenForm(wam, wr, d.onChangeFormname, d.onChangeProtocol, d.onChangeTarget);
	
	if (f) {
		if (d.allowMultiSelect && d.multiSelectListname && d.multiSelectCodefield) {
			for (var i=0, opts=this.$elem[0].options, o; o=opts[i]; i++) {
				if (o.selected) selValues.push([o.value]);
			}
			stdInsertHiddenList(f, d.multiSelectListname, [d.multiSelectCodefield], selValues);
		}

		if (wam && wr) {
			for (var i=0,fld; fld=d.onChangeExtraFields[i]; i++) {
				val = fld.value;
				if (val === undefined) {
					var fldId = this._getOtherFieldID(fld.valueField);
					val = "";
					if (fldId) {
						val = Lstd.Fields.getValue(fldId);
					} else {
						//If we are in a grid/list we may be able to get the value from the cell
						val = this.$elem.closest("td[__cellValue]").parent().children("td." + fld.valueField).attr("__cellValue") || "";
					}
				}
				insertHiddenField(f, fld.field, val);
			}
			Lstd.Fields.check4VF_WAMEVENT(f, this.$elem.get(0));
			submitForm(f, wam, wr, d.onChangeTarget, d.onChangeProtocol);
		}
	}
}
