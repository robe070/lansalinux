/*!
	(c) 2002, 2012 LANSA
	PPC XHTML Standard Scripts
	$Workfile:: std_script_lansa_ppc_xhtml_v2.js   $
	$UTCDate:: 2012-09-28 05:47:14Z                $
	$Revision:: 17                                 $
*/

//////////////////////////////////////////////////////////////////////////////////////////
//
// Assorted updates to standard object prototypes
//
//////////////////////////////////////////////////////////////////////////////////////////

// Create a console object that is consistent across browsers - at least consistent enough
// to prevent runtime errors. From http://clubajax.org/examples/consolefix/
(function()
{
	var g = window.jsdebug || /enablejslog/.test(document.location.href) || false, e = window.loglimit || 299;
	window.loglimit = e;
	if (!window.console) console = {};
	var k = function()
	{
		for (var b = "info,error,log,warn".split(","), a = 0; a < b.length; a++) 
		{
			var c = b[a], d = "_" + b[a];
			console[d] = console[c];
			console[c] = function()
			{
				var j = d;
				return function()
				{
					e--;
					e == 0 && console._log("***LOG LIMIT OF " + loglimit + " HAS BEEN REACHED***");
					e < 1 || console[j](Array.prototype.slice.call(arguments).join(" "))
				}
			}()
		}
		try 
		{
			console.clear()
		} catch (m) 
		{
		}
	}, /** @ignore */ l = function()
	{
		for (var b = "info,error,log,warn".split(","), a = 0; a < b.length; a++) 
			(function()
			{
				var c = b[a], d = "_" + b[a];
				console[d] = console[c];
				console[c] = function()
				{
					console[d](Array.prototype.slice.call(arguments).join(" "))
				}
			})()
	}, /** @ignore */ h = function(b)
	{
		b = b.split(",");
		for (var a = 0; a < b.length; a++) 
			console[b[a]] = function()
			{
			}
	}, /** @ignore */ i = function()
	{
		for (var b = "debug,time,timeEnd,assert,count,trace,dir,dirxml,group,groupEnd,groupCollapsed,exception".split(","), a = 0; a < b.length; a++) 
			console[b[a]] || (console[b[a]] = function()
			{
			})
	}, f = window.navigator.userAgent;
	if (g && /Trident/.test(f)) 
	{
		k();
		h("debug,time,timeEnd,assert,count,trace,dir,dirxml,group,groupEnd,groupCollapsed,exception")
	}
	else if (g && /WebKit|iPad|iPhone/.test(f))
	{
		l();
		i()
	}
	else
		/IE/.test(f) && !/Trident/.test(f) || !g || !window.console ? h("debug,time,timeEnd,assert,count,trace,dir,dirxml,group,groupEnd,groupCollapsed,exception,info,error,log,warn") : i()
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
String.prototype.ltrim = function() { return this.replace(/^\s+/g, ""); }
String.prototype.rtrim = function() { return this.replace(/\s+$/g, ""); }
String.prototype.trim = function() { return this.replace(/^\s+|\s+$/g, ""); }

// Return the number as a string padded with leading zeros
Number.prototype.zeropad = function(l) { return this.toString().zeropad(l); }
// Return the index of the first array item matching the supplied value
Array.prototype.indexOf = function(toFind)
{
	for (var i=0, item; item=this[i]; i++)
	{
		if (item == toFind) return i;
	}
	return -1;
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
// Implimented as functions because the arrays are not defined until 
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
				case 'DDD':  return d.arrayMstringDays()[(d.getDay()+6) % 7];
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
function stdOnFocus(targ)
{
	if (targ) targ.className += " focus";
}
function stdOnBlur(targ)
{
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

//////////////////////////////////////////////////////////////////////////////////////////
//
// Assorted utility functions
//
//////////////////////////////////////////////////////////////////////////////////////////
function trapError(errorMsg, url, line)
{
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
function getFormElement(f, elemName)
{
	if (!f) return null;
	for (var i=0, e; e=f.elements[i]; i++)
	{
		if (e.name == elemName) return e;
	}
	return null;
}
function getParentElement(child, parentTagName) {
	var e = child;
	var tn = parentTagName.toUpperCase();
	while (e.parentNode)
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
function addCSSRule(theSS, theSelector, theRule) {
	if (theSS.insertRule) {
			theSS.insertRule( theSelector + ' {' + theRule + '}', theSS.cssRules.length);
	} else if (theSS.addRule) {
		theSS.addRule(theSelector, theRule);
	}
}
function createStdHiddenForm(WAMName, WRName, formName, protocol, target)
{
	var f = null;
	if (formName && formName.length > 0)
	{
		if (formName.indexOf('.') >= 0) {
			f = eval("document." + formName);
		} else {
			f = document.forms[formName];
		}
	}
	if (f && !f.elements) f = f[0];
	if (f == null)
	{
		if (!document.createElement)
		{
			alert(stdGetMTextMessageText("PPCNoForm"));
			return null;
		}
		f = document.createElement('form');
		f.name = formName;
		var action = "";
		if( protocol && protocol.length > 0 )
		{
			action += protocol;
			if( protocol.search(new RegExp("//", "g")) < 0 )
			{
				action += "//" + document.location.host;
			}
		}
		action += g_lxmlAR + "?wam=" + WAMName + "&webrtn=" + WRName
				  + "&ml=" + g_lxmlTs + "&part=" + g_lxmlPartition + "&lang=" + g_lxmlLang;
		if( g_debug && g_debug.length > 0 ) action += "&debug=" + g_debug;
		if( g_lmxlSKMethod == "url" ) action += "&sid=" + g_lxmlSK;
		if (location.href.match(/\?.*enablejslog/)) action += "&enablejslog";

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
		f.target = target;
		document.body.appendChild(f);
	}
	return f;
}
function insertHiddenField(form, fieldName, fieldValue)
{
	if( form == null ) return null;
	if (!fieldValue) fieldValue = "";
	var field = form.elements[fieldName];
	if (field == null)
	{
		if (!document.createElement)
		{
			alert(stdGetMTextMessageText("BadHidFld", fieldName));
			return null;
		}
		field = form.ownerDocument.createElement('input');
		field.setAttribute("type", "hidden");
		field.setAttribute("name", fieldName);
		field.setAttribute("value", fieldValue);
		form.appendChild(field);
	}
	else
	{
		field.value = fieldValue;
	}
	return field;
}
function submitForm(theForm, WAM, WebRoutine, optTarget, optProtocol)
{
	var action="";
	var backupAction = theForm.action;
	var backupTarget = theForm.target;
	if( optProtocol != null && optProtocol.length > 0 )
	{
		action += optProtocol;
		if( optProtocol.search(new RegExp("//", "g")) < 0 )
		{
			action += "//" + document.location.host;
		}
	}
	action += g_lxmlAR + "?wam=" + WAM + "&webrtn=" + WebRoutine + "&ml=" + g_lxmlTs + "&part=" + g_lxmlPartition + "&lang=" + g_lxmlLang;
	if( g_debug != null && g_debug.length > 0 ) action += "&debug=" + g_debug;
	if( g_lmxlSKMethod == "url" ) action += "&sid=" + g_lxmlSK;
	if (location.href.match(/\?.*enablejslog/)) action += "&enablejslog";
	theForm.action = action;
	theForm.target = optTarget;
	theForm.submit();
	theForm.action = backupAction;
	theForm.target = backupTarget;
}
function createReentryFields(f, spansParent)
{
	if (f != null)
	{
		var spans = getReentrySpans(spansParent, null);
		var reentryField = null;
		var reentryValue = null;
		var re = new RegExp("(<!---->)$");
		for (var i=0, s; s=spans[i]; i++)
		{
			if (s.id == "reentryfield") reentryField = s.innerHTML.replace(re, "");
			if (s.id == "reentryvalue") reentryValue = s.innerHTML.replace(re, "");
			if (reentryField && reentryValue)
			{
				insertHiddenField(f, reentryField, reentryValue);
				reentryField = null;
				reentryValue = null;
			}
		}
	}
}

function getReentrySpans(parent, elemArray)
{
	if (elemArray == null) elemArray = new Array();
	if (!parent) return elemArray;
	var children = parent.children;
	var ret = null;
	for (var i=0,c; c=children[i]; i++)
	{
		if ((c.id == "reentryfield") || (c.id == "reentryvalue")) elemArray[elemArray.length] = c;
		elemArray = getReentrySpans(c, elemArray);
		if (ret) return ret;
	}
	return elemArray;
}
function isDblClick(elem)
{
	return false;
}
function isValidNumber(theObj, length, decimals, decimalPoint)
{
	return g_checkNumeric? _isValidNumber(theObj, length, decimals, decimalPoint) : true;
}
function stdFieldOnChangeHandler(fld) {
	switch (fld.getAttribute("__FormatType"))
	{
		case 'alpha':
		case 'char':
		case 'varchar':
			return isValidText(fld, fld.getAttribute("__KeyboardShift"));
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
		else return false;
	}
}
function stdAddScriptFile(location, scriptFile, charset)
{
	var script = document.createElement("script");
	script.setAttribute("type", "text/javascript");
	script.setAttribute("src", scriptFile);
	script.setAttribute("charset", charset);
	document.getElementsByTagName(location)[0].appendChild(script);
}
function stdQScriptsOnLoad(location, scriptFileList)
{
	var scriptPath = g_lweb_images_path + "/";
	for (var i = 0, scriptFile; scriptFile = scriptFileList[i]; i++)
	{
		stdAddScriptFile(location, scriptPath + scriptFile[0], scriptFile[1]);
	}
}
function stdQScripts(scriptFileList)
{
	if (!addEvent(window, "load", function() {stdQScriptsOnLoad("body", scriptFileList);}))
	{
		stdQScriptsOnLoad("head", scriptFileList);
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
	if (targetWindowName == null || targetWindowName.length == 0) targetWindowName = "_top";
	
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
				frames = w.document.frames;
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
		var srcElem = document.all[msgElemId];
		var tgtElem = targetWindow.document.all[msgElemId];
		if (srcElem && tgtElem && (srcElem != tgtElem))
		{
			var html = srcElem.innerHTML;
			tgtElem.innerHTML = html;
			tgtElem.style.display = "";
		}

		// Localize messages label
		var msgLabel = targetWindow.document.all["__std_x_message_label"];
		if (msgLabel != null) msgLabel.innerHTML = g_StdLocaleMgr.getMessageText("Messages");
	}
}

//////////////////////////////////////////////////////////////////////////////////////////
//
// Javascript support for std_anchor
//
//////////////////////////////////////////////////////////////////////////////////////////
function stdAnchorClicked(elem, WAMName, WRName, formName, protocol, target, currentrowhfield, currentrownumval)
{
	if (WRName != '')
	{
		var f = createStdHiddenForm(WAMName, WRName, formName, protocol, target);
		if (f != null)
		{
			createReentryFields(f, elem);
			if (currentrowhfield && currentrowhfield.length > 0) insertHiddenField(f, currentrowhfield, currentrownumval);
			submitForm(f, WAMName, WRName, target, protocol);
		}
		return false;
	}
	return true;
}
//////////////////////////////////////////////////////////////////////////////////////////
//
// Javascript support for std_menu_item
//
/////////////////////////////////////////////////////////////////////////////////////////
function stdMenuItemClicked(menuItem, WAMName, WRName, formName, protocol, target)
{
	return stdAnchorClicked(menuItem, WAMName, WRName, formName, protocol, target, null, null)
}
//////////////////////////////////////////////////////////////////////////////////////////
//
// Javascript support for std_button
//
//////////////////////////////////////////////////////////////////////////////////////////
function stdButton_clicked(elem, WAMName, WRName, formName, protocol, target, currentrowhfield, currentrownumval)
{
	var f = (!formName) ? getParentForm(elem) : createStdHiddenForm(WAMName, WRName, formName, protocol, target);
	if (f != null)
	{
		var pe = (elem.parentNode) ? elem.parentNode : elem.parentElement;
		createReentryFields(f, pe);
		if (currentrowhfield && currentrowhfield.length > 0) insertHiddenField(f, currentrowhfield, currentrownumval);
		submitForm(f, WAMName, WRName, target, protocol);
	}
	return false;
}
function stdButton_setDefault(btnType, formName, btnName, onSubmitFunc)
{
	var btn = document.all[btnName];
	if (btn)
	{
		var f = (!formName) ? getParentForm(btn) : document.forms[formName];
		if (f)
		{
			// PocketIE doesn't support string indexed collections so
			// we have to use eval.
			eval("gStdDfltButtonMgr.form_" + f.name + " = onSubmitFunc");
			eval("gStdDfltButtonMgr.dBtn_" + f.name + " = btn"); 
		}
	}
}
function stdForm_Submit(form, WAMName, WRName, protocol, target)
{
	var btn = null;
	eval("btn = gStdDfltButtonMgr.dBtn_" + form.name);
	createReentryFields(form, btn.parentElement);
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
			var pe = (checkBox.parentNode) ? checkBox.parentNode : checkBox.parentElement;
			createReentryFields(f, pe);
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
		var pe = (radioBtn.parentNode) ? radioBtn.parentNode : radioBtn.parentElement;
		createReentryFields(f, pe);
		submitForm(f, WAMName, WRName, target, protocol);
	}
}
function stdRadioBtnGrp_onClick(radioBtn, grpName, WAMName, WRName, formName, protocol, target, RFld)
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
		var spID = "rbgroup_" + grpName;
		while (sp = (sp.parentNode) ? sp.parentNode : sp.parentElement) { if (sp.id == spID) break; }
		createReentryFields(f, sp);
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
function stdFloatFixValues(fieldName)
{
	var f = document.forms[document.forms.length-1];
	var e = f.elements[fieldName];
	if (e) e.value = new Number(e.value);
}
//////////////////////////////////////////////////////////////////////////////////////////
//
// Javascript support for std_datetime
//
/////////////////////////////////////////////////////////////////////////////////////////
g_stdDateTimes = new Object();
function stdDateTimeInfo (fieldName, displayMode, inputType, dateMask, timeMask, displayInUTC, allowSQLNull)
{
	this.fieldName = fieldName;
	this.displayMode = displayMode;
	this.inputType = inputType;
	this.dateMask = dateMask;
	this.timeMask = timeMask;
	this.displayInUTC = displayInUTC;
	this.allowSQLNull = allowSQLNull;
	this.masterInput = null;
	this.proxyInput = null;
}
function stdDateTimeGetDateValue(dtInfo)
{
	var dateVal = new Date();
	dateVal.setISO8601(dtInfo.masterInput.value);
	if (dtInfo.displayInUTC)
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
function stdDateTimeSetDateValue(dtInfo, dateVal)
{
	var masterDateVal = null;
	if ((dateVal == null) || dateVal.sqlNull)
	{
		dtInfo.masterInput.value = "";
	}
	else
	{
		masterDateVal = new Date(dateVal.getTime());
		if (dtInfo.displayInUTC)
		{
			// The value being supplied is in the "local" part of the date object
			// but it is supposed to represent a UTC value so we need to shift it back
			masterDateVal.setTime(dateVal.getTime() - (dateVal.getTimezoneOffset() * 60000));
		}
		switch (dtInfo.inputType)
		{
			case "timeonly":
				dtInfo.masterInput.value = masterDateVal.toFormattedString("HH:mm:ss");
				break;
			case "dateonly":
				dtInfo.masterInput.value = masterDateVal.toFormattedString("YYYY-MM-DD");
				break;
			default:
				dtInfo.masterInput.value = masterDateVal.toISO8601String(true, false);
				break;
		}
	}
	stdDateTimeUpdateProxyValue(dtInfo, masterDateVal);
}
function stdDateTimeUpdateProxyValue(dtInfo, dateValue)
{
	if (!dateValue || (dateValue == NaN) || isNaN(dateValue.valueOf()) || dateValue.sqlNull)
	{
		dtInfo.proxyInput.value = "";
		return;
	}
	var displayDate = new Date(dateValue.getTime());
	if (dtInfo.displayInUTC) displayDate.setTime(displayDate.getTime() + (dateValue.getTimezoneOffset() * 60000));
	var proxyVal = "";
	switch (dtInfo.inputType)
	{
		case "timeonly":
			proxyVal = (dtInfo.timeMask == "") ? displayDate.toLocaleTimeString() : displayDate.toFormattedString(dtInfo.timeMask);
			break;
		case "dateonly":
			proxyVal = (dtInfo.dateMask == "") ? displayDate.toLocaleDateString() : displayDate.toFormattedString(dtInfo.dateMask);
			break;
		case "datetime":
			proxyVal = displayDate.toFormattedString(dtInfo.dateMask + " " + dtInfo.timeMask);
			if (dtInfo.dateMask == "") proxyVal = displayDate.toLocaleDateString() + proxyVal;
			if (dtInfo.timeMask == "") proxyVal += displayDate.toLocaleTimeString();
			break;
	}
	if (dtInfo.displayMode == "output")
	{
		dtInfo.proxyInput.innerHTML = proxyVal;
	}
	else
	{
		dtInfo.proxyInput.value = proxyVal;
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
	var fieldName = proxyInp.name.replace(/__(.*)_PROXY/, "$1");
	var dtInfo = g_stdDateTimes[fieldName];
	var hiddenInp = dtInfo.masterInput;
	var dateStr = proxyInp.value.toLowerCase();

	if (dateStr.length == 0)
	{
		if (dtInfo.allowSQLNull)
		{
			stdDateTimeSetDateValue(dtInfo, null);
			return true;
		}
		else
		{
			if (dtInfo.inputType == "timeonly") {
				alert(g_StdLocaleMgr.getMessageText("BlankTime2"));
			} else {
				alert(g_StdLocaleMgr.getMessageText("BlankDate2"));
			}
			var dateVal = stdDateTimeDateObjectFromMasterVal(dtInfo, dtInfo.masterInput.value);
			stdDateTimeUpdateProxyValue(dtInfo, dateVal);
			proxyInp.focus();
			proxyInp.select();
			return false;
		}
	}
	var newDate = NaN;
	switch (dtInfo.inputType)
	{
		case 'timeonly':
			newDate = (new stdDateTimeParser(dateStr, "", dtInfo.timeMask)).dateValue;
			break;
		case 'dateonly':
			newDate = (new stdDateTimeParser(dateStr, dtInfo.dateMask, "")).dateValue;
			break;
		case 'datetime':
			if ((dtInfo.dateMask == "") == (dtInfo.timeMask == ""))
			{
				// Both masks are empty or both are set
				newDate = (new stdDateTimeParser(dateStr, dtInfo.dateMask, dtInfo.timeMask)).dateValue;
			}
			else if (dtInfo.dateMask == "")
			{
				dp = new stdDateTimeParser(dateStr, "", dtInfo.timeMask);
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
				dp = new stdDateTimeParser(dateStr, dtInfo.dateMask, "");
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
		if (dtInfo.inputType == "timeonly") {
			alert(proxyInp.value + g_StdLocaleMgr.getMessageText("BadTime1"));
		} else {
			alert(proxyInp.value + g_StdLocaleMgr.getMessageText("BadDate1"));
		}
		proxyInp.focus();
		proxyInp.select();
		return false;
	}
	stdDateTimeSetDateValue(dtInfo, newDate);
	return true;
}
function stdDateTimeInitDiv(fieldName, displayMode, inputType, dateMask, timeMask, displayInUTC, allowSQLNull, isoValue)
{
	// This is called just after the DIV is completed.  So find the last instance
	// of the field with the required name.
	var dtInfo = new stdDateTimeInfo(fieldName, displayMode, inputType, dateMask, timeMask, displayInUTC, allowSQLNull);
	g_stdDateTimes[fieldName] = dtInfo;
	var masterValue = "";
	if (displayMode == "output")
	{
		var f = document.forms[document.forms.length];
		var e = getFormElement(f, fieldName);
		dtInfo.proxyInput = dtInfo.masterInput = document.all[fieldName];
		if (dtInfo.masterInput) masterValue = isoValue;;
	}
	else
	{
		var f = document.forms[document.forms.length-1];
		dtInfo.masterInput = f.elements[fieldName];
		if (dtInfo.masterInput) masterValue = dtInfo.masterInput.value;
		dtInfo.proxyInput = f.elements["__" + fieldName + "_PROXY"];
	}
	var dateVal = stdDateTimeDateObjectFromMasterVal(dtInfo, masterValue);
	stdDateTimeUpdateProxyValue(dtInfo, dateVal);
}
function stdDateTimeDateObjectFromMasterVal(dtInfo, masterValue)
{
	switch (dtInfo.inputType)
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

	if (WRName != '') submitForm(f, WAMName, WRName, target, protocol);
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
			if (o.getAttribute("selected"))
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
// Javascript support for list paging buttons
//
//////////////////////////////////////////////////////////////////////////////////////////
function stdListPageBtnClick(btn, btnType, WAMName, WRName, formName, protocol, reentryField, prevCondFld, prevCondVal, nextCondFld, nextCondVal, pageCountFld, pageCountVal)
{
	if (btn == null) return;
	var f = (!formName) ? getParentForm(btn) : createStdHiddenForm(WAMName, WRName, formName, protocol, "");
	if (f != null)
	{
		insertHiddenField(f, reentryField, btnType);
		insertHiddenField(f, prevCondFld, prevCondVal);
		insertHiddenField(f, nextCondFld, nextCondVal);
		insertHiddenField(f, pageCountFld, pageCountVal);
		submitForm(f, WAMName, WRName, "", protocol);
	}
	return false;
}
