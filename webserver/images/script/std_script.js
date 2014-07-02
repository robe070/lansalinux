/*!
	(c) 2002, 2014 LANSA
	XHTML Standard Scripts
	$Workfile:: std_script.js               $
	$UTCDate:: 2014-01-10 01:37:34Z         $
	$Revision:: 23                          $
*/

// Global Locale Manager.
var g_StdLocaleMgr = null;
var g_v1SupportIncluded = true;
var g_dq = '"';
var g_bs = "\\";

function stdGetMTextMessageText(messageId)
{
	return g_StdLocaleMgr.getMessageText.apply(g_StdLocaleMgr,arguments);
}

function stdGetMTextMessageTextArr(messageId)
{
	return g_StdLocaleMgr.getMessageTextArr(messageId);
}

/* Sets up the function to call based on the language to retrieve multilingual messages
	Note: LanguageID and DBCS flag arguments have been deprecated
 */
function StdLocaleMgr()
{
	this.m_isDBCS = window.g_lxmlDBCS != null ? window.g_lxmlDBCS : false;
	this.getMessageText = function(messageId)
	{
		var strings = Lstd.I18n._strings;
		var theMsg = (strings) ? (strings[messageId] || "") : "";
		return (arguments.length > 1) ? Lstd.Utils.strargs(theMsg, Array.prototype.slice.call(arguments, 1, arguments.length)) : theMsg;
	}
	this.getMessageTextArr = function(messageId) {
		var arrays = Lstd.I18n._arrays;
		return (arrays) ? (arrays[messageId] || null) : null;
	}
	g_StdLocaleMgr = this;
}

// Deprecated
function StdMessageMgr(languageId)
{
	new StdLocaleMgr(languageId, false);
}

// Numeric values parser constructor
function StdNumberParser(dec_sep)
{
	var expr = dec_sep == '.' ? "[^\\d.]" : dec_sep == ',' ? "[^\\d,]" : dec_sep == 'e' ? "(\\+|-)\\d+\\.\\d{1,16}E\\+\\d{3}" : "[\\D]";
	this.regExp = new RegExp(expr, "g");
	this.negValueExp = new RegExp("(^-)|((-|CR)$)");
	this.isCommaSep = dec_sep == ',';

	this.parseInt = StdNumberParser_parseInt;
	this.parseDecimal = StdNumberParser_parseDecimal;
	this.parseFloat = StdNumberParser_parseFloat;
}

function StdNumberParser_parseInt(str)
{
	var isNegative = str.search(this.negValueExp) != -1;
	var intStr = str.replace(this.regExp, "");
	var intValue = intStr.length > 0 ? parseInt(intStr, 10) : 0;
	return isNegative ? -intValue : intValue;
}

function StdNumberParser_parseDecimal(str)
{
	var isNegative = str.search(this.negValueExp) != -1;
	var floatStr = str.replace(this.regExp, "");
	var floatValue = floatStr.length > 0 ? parseFloat(this.isCommaSep ? floatStr.replace(",", ".") : floatStr) : 0;
	return isNegative ? -floatValue : floatValue;
}

function StdNumberParser_parseFloat(str)
{
	var isValidFloat = str.search(this.regExp) == 0;
	return isValidFloat ? parseFloat(str) : 0;
}

// Convert the value property of input elements to upper or lower case as required.
// Deprecated: Use toValueCase() called from isValidText()
function SetValueCase(oInput, propertyName)
{
	if( oInput == null )
	{
		return;
	}
	if( propertyName == "value" )
	{
		var textTransform = oInput.currentStyle.textTransform;
		if( textTransform == "uppercase" )
		{
			var value = oInput.value;
			var valueUpper = value.toUpperCase();
			if( value != valueUpper )
			{
				oInput.value = valueUpper;
			}
		}
		else if( textTransform == "lowercase" )
		{
			var value = oInput.value;
			var valueLow = value.toLowerCase();
			if( valueLow != value )
			{
				oInput.value = valueLow;
			}
		}
	}
}

function _HandleEvent(WAM, WebRoutine, techServ, actionRequest, partition, language, optForm, optTarget, optProtocol, optSessionKey, optDebugMode)
{
	if( optForm == null )
	{
		optForm= document.LANSA;
	}

	var prevAction = optForm.action;
	var prevTarget = optForm.target;
	var action="";
	if( optProtocol != null && optProtocol.length > 0 )
	{
		action += optProtocol;
		if( optProtocol.search(new RegExp("//", "g")) < 0 )
		{
			action += "//" + stdGetOwnerDocument(optForm).location.host;
		}
	}
	action += actionRequest + "?wam=";
	action += WAM;
	action += "&webrtn=";
	action += WebRoutine;
	action += "&ml=" + techServ;
	action += "&part=" + partition + "&lang=" + language;
	if( optDebugMode != null && optDebugMode.length > 0 )
	{
		action += "&debug=" + optDebugMode;
	}
	if( optSessionKey != null )
	{
		action += "&sid=" + optSessionKey;
	}
	optForm.action = action;
	optForm.target = (optTarget) ? optTarget : "";
	optForm.submit();
	optForm.target = prevTarget;
	optForm.action = prevAction;
}

function _HandleServiceEvent(ServiceName, techServ, actionRequest, partition, language, optForm, optTarget, optProtocol, optSessionKey, optDebugMode)
{
	var Form = optForm != null ? optForm : document.LANSA;
	var prevAction = Form.action;
	var prevTarget = Form.target;
	
	var action = "";
	if( optProtocol != null && optProtocol.length > 0 )
	{
		action += optProtocol;
		if( optProtocol.search(new RegExp("//", "g")) < 0 )
		{
			action += "//" + stdGetOwnerDocument(Form).location.host;
		}
	}
	action += actionRequest + "?srve=" + ServiceName + "&part=" + partition + "&lang=" + language;
	action += "&ml=" + techServ;
	if( optDebugMode != null && optDebugMode.length > 0 )
	{
		action += "&debug=" + optDebugMode;
	}
	if( optSessionKey != null )
	{
		action += "&sid=" + optSessionKey;
	}
	Form.action = action;
	Form.target = (optTarget) ? optTarget : "";
	Form.submit();
	Form.target = prevTarget;
	Form.action = prevAction;
}

function _HandleEventTarget(Form, Target, techServ, actionRequest, partition, language, WebApp, WebRoutine, optProtocol, optSessionKey, optDebugMode)
{
	if( Form == null )
	{
		Form = document.LANSA;
	}

	var prevTarget = Form.target;
	Form.target = (Target) ? Target : "";
	var prevAction = Form.action;
	var action="";
	if( optProtocol != null && optProtocol.length > 0 )
	{
		action += optProtocol;
		if( optProtocol.search(new RegExp("//", "g")) < 0 )
		{
			action += "//" + stdGetOwnerDocument(Form).location.host;
		}
	}
	action += actionRequest + "?wam=";
	action += WebApp;
	action += "&webrtn=";
	action += WebRoutine;
	action += "&ml=" + techServ;
	action += "&part=" + partition + "&lang=" + language;
	if( optDebugMode != null && optDebugMode.length > 0 )
	{
		action += "&debug=" + optDebugMode;
	}
	if( optSessionKey != null )
	{
		action += "&sid=" + optSessionKey;
	}
	Form.action = action;
	Form.submit();
	Form.target = prevTarget;
	Form.action = prevAction;
}

function _HandleDefaultSubmit(oForm)
{
	if( oForm == null )
	{
		return false;
	}
	var oHandler = oForm.getAttribute("__defaultSubmitHandler");
	if( oHandler == null )
	{
		return false;
	}
	// Can't call oHandler directly, as that fails in Mozilla, so do it indirectly.
	return new Function("oForm", oHandler)(oForm);
}

function stdCreateTempForm(ownerDoc)
{
	var oTempForm = ownerDoc.createElement("form");

	if (oTempForm != null)
	{
		if (typeof oTempForm.setAttribute === "function")
		{
			oTempForm.setAttribute("method", "post");
		}
		else
		{
			oTempForm = ownerDoc.createElement("<form method=\"post\"></form>");
		}
	}
	return oTempForm;
}

function _HandleWebEventEx(Process, Webevent, Form, Target, actionRequest, Partition, Language, optDebugMode, optAnchorValue, argArr, startArgPos)
{
	if( Form == null )
	{
		Form = document.LANSA;
	}

	var ownerDoc = stdGetOwnerDocument(Form), oTempForm = stdCreateTempForm(ownerDoc);

	if (oTempForm != null)
	{
		ownerDoc.body.appendChild(oTempForm);
		var argLen = argArr.length;//arguments.length;
		if( argLen > startArgPos )
		{
			for(var index = startArgPos; index < argLen; index++)
			{
				var fieldNameWithPrefix = argArr[index];
				var fieldName = fieldNameWithPrefix.substr(1, fieldNameWithPrefix.length-1);
				var fieldValue = Form.elements[fieldName].value;
				InsertHidden(oTempForm, fieldNameWithPrefix, fieldValue);
			}
		}
		if( optAnchorValue != null )
		{
			InsertHidden(oTempForm, "ASTDANCHOR", optAnchorValue);
		}
		var prevAction = oTempForm.action;
		var prevTarget = oTempForm.target;
		var action = "";
		if( actionRequest == null || actionRequest.length <= 0 )
		{
			actionRequest = "/cgi-bin/lansaweb";
		}
		action += actionRequest + "?" + "procfun+";
		action += Process;
		action += "+";
		action += Webevent;
		action += "+" + Partition + "+" + Language;
		if( optDebugMode != null && optDebugMode.length > 0 )
		{
			action += "+BDEBUG";
		}
		oTempForm.action = action;
		oTempForm.target = (Target) ? Target : "";
		oTempForm.submit();
		oTempForm.target = prevTarget;
		oTempForm.action = prevAction;
		oTempForm.parentNode.removeChild(oTempForm);
	}
}

function _HandleWebEvent(Process, Webevent, Form, Target, actionRequest, Partition, Language, optDebugMode, optAnchorValue/*, field1, field2, etc...*/)
{
	_HandleWebEventEx(Process, Webevent, Form, Target, actionRequest, Partition, Language, optDebugMode, optAnchorValue, arguments, 9);
}

function IsIE()
{
	return (navigator.userAgent.indexOf("MSIE")>-1);
}

function InsertHidden(Form, FieldName, FieldValue)
{
	// Deprecated. Replaced with insertHiddenfield
	insertHiddenField(Form, FieldName, FieldValue);
}

//////////////////////////////////////////////////////////////////////////////////////////
//
// Inserts a hidden list for submitting it on a form
//
//////////////////////////////////////////////////////////////////////////////////////////

function stdInsertHiddenList(Form, listName, listColumnNameArr, listValueArrOfArr)
{
  if( listName == null || listName.length <= 0 )
  {
		return false;
	}
	if( listColumnNameArr == null || listValueArrOfArr == null )
	{
		return false;
	}
	var index = 0;
	InsertHidden(Form, listName + "..", listValueArrOfArr.length.toString());
	for(index = 0; index < listValueArrOfArr.length; index++)
	{
		var row = listValueArrOfArr[index];
		var rowid = (index+1).toString();
		for( count = rowid.length; count < 4; count++)
		{
			rowid = "0" + rowid;
		}
		for(var colIndex = 0; colIndex < row.length; colIndex++)
		{
			var name = listName + ".";
			name += rowid;
			name += ".";
			name += listColumnNameArr[colIndex];
			var tagValue = row[colIndex];
			InsertHidden(Form, name, tagValue);
		}
	}
	var bBreakLoop = false;
	while(!bBreakLoop)
	{
		var name;
		var rowid = (index+1).toString();
		for( count = rowid.length; count < 4; count++)
		{
			rowid = "0" + rowid;
		}
		for(var colIndex = 0; colIndex < listColumnNameArr.length; colIndex++)
		{
			name = listName + ".";
			name += rowid;
			name += ".";
			name += listColumnNameArr[colIndex];
			var elem = Form.elements[name];
			if( elem != null )
			{
				elem.parentNode.removeChild(elem);
			}
			else
			{
				bBreakLoop = true;
				break;
			}
		}
		index++;
	}
	return true;
}

function stdInsertFieldsIntoUrl(fieldList)
{
	if (fieldList == "") return "";
	var fieldNames = fieldList.replace(/ /g, '').split(',');
	var nameValuePairs = "";
	for (var i = 0; i < fieldNames.length; i++)
	{
		var field = document.getElementById(fieldNames[i]);
		if (field) nameValuePairs += ("+f(" + fieldNames[i] + ")=" + encodeURIComponent(field.value));
	}
	return nameValuePairs;
}

function _isValidNumber(theObj, length, decimals, decimalPoint)
{
	var integers = length - decimals;
	if( theObj != null )
	{
		var valueStr = theObj.value;
		if( valueStr.length <= 0 ) return true;
		var re = new RegExp("^[+-]?\\d{0," + integers + "}(\\" + decimalPoint + "\\d{0," + decimals + "})?$");

        return showMessageOnFalse(theObj, stdGetMTextMessageText("BadNum", integers, decimals), re.test(valueStr));
	}
	return showMessageOnFalse(theObj, stdGetMTextMessageText("BadNum", integers, decimals), false);
}

function isDigit(theDigit)
{
	digitArray = new Array('0', '1', '2', '3', '4', '5', '6', '7', '8', '9')
	for (var j = 0; j < digitArray.length; j++)
		if (theDigit == digitArray[j])
			return true
	return false
}

function isNumeric(valueStr, length)
{
	if( valueStr.length > length )
	{
		return false;
	}
	for(var index = 0; index < valueStr.length; index++)
	{
		if( !isDigit(valueStr.charAt(index)) )
		{
			if( index != 0 || valueStr.charAt(index) != "-" )
			{
				return false;
			}
		}
	}
	return true;
}

function isValidInteger(theObj, size)
{
	if( theObj != null )
	{
		var valueStr = theObj.value;
		if( valueStr.length <= 0 ) return true;
		if (valueStr.match(/^[+-]?\d*$/) == null)
		{
		    return showMessageOnFalse(theObj, g_StdLocaleMgr.getMessageText("BadInt"), false);
		}
		
		var isValid = false;
		var minVal = 0;
		var maxVal = 0;
		if (size < 7)
		{
			var limit = Math.pow(256, size) / 2;
			minVal = -1 * limit;
			maxVal = limit - 1;

			var valueVal = new Number(valueStr);
			isValid = (valueVal >= minVal) && (valueVal <= maxVal);
		}
		else
		{
			// JavaScript can't handle a precision of more than 16 digits so integers
			// of more than that have to be processed as strings.
			if (size == 7)
			{
				minVal = "-36028797018963968";
				maxVal = "36028797018963967";
			}
			else
			{
				minVal = "-9223372036854775808";
				maxVal = "9223372036854775807";
			}

			var cmpStr = maxVal;
			var i = 0;
			if (valueStr.charAt(0) == "-")
			{
				cmpStr = minVal;
				i = 1;
			}
			if (valueStr.length < cmpStr.length) return true;
			if (valueStr.length == cmpStr.length)
			{
				isValid = true;
				while (i < valueStr.length)
				{
					if (Number(valueStr.charAt(i)) > Number(cmpStr.charAt(i)))
					{
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
	}
	return showMessageOnFalse(theObj, stdGetMTextMessageText("BadIntWithRange", minVal, maxVal), isValid);
}

function isValidFloat(theObj, size)
{
	if( theObj != null )
	{
		var valueStr = theObj.value;
		var numeric = new Number(valueStr);
		return showMessageOnFalse(theObj, g_StdLocaleMgr.getMessageText("BadFloat"), !isNaN(numeric));
	}
	return showMessageOnFalse(theObj, g_StdLocaleMgr.getMessageText("BadFloat"), false);
}

function isValidDate(theObj)
{
	if( theObj != null )
	{
		var dateStr = theObj.value;
		var partArr = dateStr.split("-");
		if( partArr.length == 3 )
		{
			dateStr = partArr[1];
			dateStr += "-";
			dateStr += partArr[2];
			dateStr += "-";
			dateStr += partArr[0];
			var oDate = new Date(dateStr);
			return showMessageOnFalse(theObj, g_StdLocaleMgr.getMessageText("BadDate"), !isNaN(oDate.valueOf()));
		}
	}
	return showMessageOnFalse(theObj, g_StdLocaleMgr.getMessageText("BadDate"), false);
}

function isValidTime(theObj)
{
	if( theObj != null )
	{
		var timeStr = theObj.value;
		if( timeStr.length > 0 )
		{
			var timeComps = timeStr.split(":");
			if( timeComps.length == 3 )
			{
				var hours = new Number(timeComps[0]);
				if( hours >= 0 && hours < 24 )
				{
					var mins = new Number(timeComps[1]);
					if( mins >= 0 && mins < 60 )
					{
						var secs = timeComps[2];
						var secComps = secs.split(".");
						if( secComps.length == 1 )
						{
							secs = new Number(timeComps[2]);
							if( secs >= 0 && secs < 60 )
							{
								return true;
							}
						}
					}
				}
			}
		}
	}
	return showMessageOnFalse(theObj, g_StdLocaleMgr.getMessageText("BadTime"), false);
}

function isValidDateTime(theObj, size)
{
	if( theObj == null )
	{
		return false;
	}
	var dateStr = theObj.value;
	var milliSecs = null;
	if( dateStr.length > 0 )
	{
		var dateComps = dateStr.split("T");
		if( dateComps.length >= 1 )
		{
			var datePart = dateComps[0];
			var partArr = datePart.split("-");
			if( partArr.length == 3 )
			{
				dateStr = partArr[1];
				dateStr += "-";
				dateStr += partArr[2];
				dateStr += "-";
				dateStr += partArr[0];
			}
			else
			{
				dateStr = dateComps[0];
			}
		}
		if( dateComps.length == 2 )
		{
			var timePart = dateComps[1];
			dateStr += " ";
			var partArr = timePart.split("Z");
			if( partArr.length == 2 )
			{
				var fracSec = partArr[0].split(".");
				if( fracSec.length == 2 )
				{
						dateStr += fracSec[0];
						milliSecs = fracSec[1].substring(0, 3);
				}
				else
				{
						dateStr += partArr[0];
				}
				dateStr += " UTC";
			}
			else
			{
				var tzdChar = "+";
				partArr = timePart.split(tzdChar);
				if( partArr.length != 2 )
				{
						tzdChar = "-";
						partArr = timePart.split(tzdChar);
				}
				if( partArr.length == 2 )
				{
						dateStr += partArr[0];
						dateStr += " UTC";
						dateStr += tzdChar;
						dateStr += partArr[1];
				}
				else
				{
						dateStr += dateComps[1];
				}
			}
		}
	}
	var oDate = new Date(dateStr);
	if( !isNaN(oDate.valueOf()) )
	{
		if( milliSecs != null )
		{
			oDate.setMilliseconds(milliSecs);
		}
		return showMessageOnFalse(theObj, g_StdLocaleMgr.getMessageText("BadDateTime"), !isNaN(oDate.valueOf()));
	}
	return showMessageOnFalse(theObj, g_StdLocaleMgr.getMessageText("BadDateTime"), false);
}

function isValidLength(elem, maxlen)
{
	if (elem.value.length < maxlen)
	{
		return true;
	}
	else
	{
		alert(g_StdLocaleMgr.getMessageText("BadLength1"));
		return false;
	}
}

function showMessageOnFalse(theObj, message, bResult)
{
	if( !bResult )
	{
		if( theObj != null )
		{
			theObj.focus();
			theObj.select();
		}
		alert(message);
	}
	return bResult;
}

function isValidBoolean(theObj)
{
	toValueCase(theObj);
	var FieldValue = theObj.value;
	if ((FieldValue == "true") || (FieldValue == "false")) return true;
	alert(g_StdLocaleMgr.getMessageText("BadBool"));
	theObj.focus();
	theObj.select();
	return false;
}

function isValidText(theObj, KeybdShift)
{
	toValueCase(theObj);
	if (KeybdShift == '') KeybdShift = ' ';
	return g_StdLocaleMgr.m_isDBCS ? isValidDBCS(theObj, KeybdShift, theObj.maxLength) : true;
}

function isValidTextArea(theObj, KeybdShift, maxlen)
{
	toValueCase(theObj);
	if (KeybdShift == '') KeybdShift = ' ';
	return g_StdLocaleMgr.m_isDBCS ? isValidDBCS(theObj, KeybdShift, maxlen) : isValidLength(theObj, ++maxlen);
}

// Convert the value property of input elements to upper or lower case as required.
// Deprecated. Replaced by new version in std_script_v2.
function toValueCase(theObj)
{
	var value = theObj.value;
	var textTransform = theObj.currentStyle.textTransform;
	if (textTransform == "uppercase") value = value.toUpperCase();
	else if (textTransform == "lowercase") value = value.toLowerCase();
	if (theObj.value != value)
	{
		theObj.value = value;
		if (theObj.id != "") stdSetElementValue(theObj.id, value, true); // Workaround IE bug
	}
}

function stdSetElementValue(id, value, async)
{
	if (async)
	{
		setTimeout("stdSetElementValue('" + id + "', '" + value + "', false)", 1);
	}
	else
	{
		var elem = document.getElementById(id);
		if (elem != null) elem.value = value;
	}
}

function isValidDBCS(theObj, KeybdShift, EBCDICLength)
{
	var FieldValue = theObj.value;
	var returnString = "";
	var totalDBCS = 0;
	var totalSBCS = 0;
	var totalLength = 0;
	var inDBCS = false;
	var chkDBCSChar = false;

	for (var i = 0; i < FieldValue.length; i++)
	{
		var ch = FieldValue.charAt(i);
		chkDBCSChar = isDBCSChar(ch);

		if (chkDBCSChar)
		{
			if (!inDBCS)
			{
				inDBCS = true;
				totalLength += 2;
			}

			totalLength += 2;
			if ((totalLength <= EBCDICLength) && (KeybdShift != 'A'))
			{
				returnString += ch;
			}
			totalDBCS++;
		}
		else
		{
			totalLength += 1;
			if ((totalLength <= EBCDICLength) && (KeybdShift != 'J'))
			{
				returnString += ch;
			}
			if (inDBCS) inDBCS = false;
			totalSBCS++;
		}
	}

	if (totalLength > EBCDICLength)
	{
		alert(g_StdLocaleMgr.getMessageText("BadDBCS_TooLong", totalLength, EBCDICLength));
		if (theObj.id != "")
		{
			stdSetElementValue(theObj.id, returnString, true);
		}
		else
		{
			theObj.value = returnString;
		}
		theObj.focus();
		theObj.select();
		return false;
	}

	if ((KeybdShift == 'J') && (totalSBCS > 0))
	{
		alert(g_StdLocaleMgr.getMessageText("BadDBCS_SBCSNotAllowed", totalSBCS));
		if (theObj.id != "")
		{
			stdSetElementValue(theObj.id, returnString, true);
		}
		else
		{
			theObj.value = returnString;
		}
		theObj.focus();
		theObj.select();
		return false;
	}

	if ((KeybdShift == 'E') && (totalSBCS > 0) && (totalDBCS > 0))
	{
		alert(g_StdLocaleMgr.getMessageText("BadDBCS_BothNotAllowed", totalSBCS, totalDBCS));
		theObj.focus();
		theObj.select();
		return false;
	}

	if ((KeybdShift == 'A') && (totalDBCS > 0))
	{
		alert(g_StdLocaleMgr.getMessageText("BadDBCS_DBCSNotAllowed", totalDBCS));

		if (theObj.id != "")
		{
			stdSetElementValue(theObj.id, returnString, true);
		}
		else
		{
			theObj.value = returnString;
		}
		theObj.focus();
		theObj.select();
		return false;
	}

	return true;
}

function isDBCSChar(theChar)
{
	return (escape(theChar).length >= 4) ? true : false;
}

function SetFocus()
{
	var formArr = document.forms;
	var length = formArr.length;
	var elemToFocus = null;
	for(var index = 0; index < length; index++)
	{
		var oForm = formArr[index];
		if( oForm == null )
		{
				return;
		}
		var NumElements = oForm.elements.length;

		for (i = 0; i < NumElements; i++)
		{
			var elem = oForm.elements[i];
			var type = elem.type;
			if (type == "checkbox" ||
					type == "password" ||
					type == "radio" ||
					type == "select-one" ||
					type == "text" ||
					type == "textarea")
			{
				try
				{
					// Only set focus if not disabled, not readonly and tabIndex is not negative.
					if( elem.disabled != true && elem.readOnly != true && (elem.tabIndex == null || elem.tabIndex >= 0) )
					{
						// If focus is already set on an element and this elements tabIndex <= the current focus element's tabIndex
						// then set the focus, so that it is in correct tab order.
						if( elemToFocus == null || (elem.tabIndex == null || (elemToFocus.tabIndex != null && elemToFocus.tabIndex > elem.tabIndex)) )
						{
							elem.focus();
							elemToFocus = elem;
						}
					}
				}
				catch(exception)
				{
				}
			}
		}
	}
	if( elemToFocus != null )
	{
		elemToFocus.focus();
	}
}

function preload(imgObj, imgSrc)
{
	if (document.images)
	{
		eval(imgObj + ' = new Image()');
		eval(imgObj + '.src = "' + imgSrc + '"');
	}
}

function changeImage(layer, imgObj, imgName)
{
	if (document.images)
	{
		if (document.layers && layer!=null)
			 eval('document.' + layer + '.document.images["' + imgName + '"].src = ' + imgObj + '.src');
		else
			 document.images[imgName].src = eval(imgObj + ".src");
	}
}

function CheckNUpdate(Fld, Value)
{
	if( RFld == null || RFld == "" )
	{
		return;
	}
	var NumElements = document.LANSA.elements.length;

	for (i = 0; i < NumElements; i++)
	{
		if (document.LANSA.elements[i].name == Fld)
		{
			 document.LANSA.elements[i].value = Value;
			 break;
		}
	}
}

function FieldExists(Fld)
{
	if( RFld == null || RFld == "" )
	{
		return false;
	}
	var NumElements = document.LANSA.elements.length;

	for (i = 0; i < NumElements; i++)
	{
		if (document.LANSA.elements[i].name == Fld) return true;
	}
	return false;
}

function SetState(obj, RFld, chkValue, unchkValue)
{
	if( RFld == null || RFld == "" || obj == null )
	{
		return;
	}
	var oForm = null;
	try
	{
		oForm = obj.form;
	}
	catch(exception)
	{
		oForm = null;
	}
	if( oForm == null )
	{
		var oParentElem = obj;
		while(oParentElem != null)
		{
			if( oParentElem.nodeName.toLowerCase() == "form" )
			{
				oForm = oParentElem;
				break;
			}
			oParentElem = oParentElem.parentNode;
		}
	}
	if( oForm == null )
	{
		return;
	}
	var oFieldInput = oForm.elements[RFld];
	if( oFieldInput != null )
	{
		oFieldInput.value = obj.checked ? chkValue : unchkValue;
	}
}

function GetFieldValue(RFld)
{
	if( RFld == null || RFld == "" )
	{
		return null;
	}
	var NumElements = document.LANSA.elements.length;

	for (i = 0; i < NumElements; i++)
	{
		if (document.LANSA.elements[i].name == RFld) return document.LANSA.elements[i].value;
	}
	return null;
}

function SetCBState(obj, RFld, CY, CN)
{
	if( RFld == null || RFld == "" )
	{
		return;
	}
	var NumElements = document.LANSA.elements.length;

	for (i = 0; i < NumElements; i++)
	{
		if (document.LANSA.elements[i].name == RFld)
		{
			 if (obj.checked)
				document.LANSA.elements[i].value = CY;
			 else
				document.LANSA.elements[i].value = CN;
			 break;
		}
	}
}
function stdCreateXMLHttpRequest()
{
	if (window.XMLHttpRequest)
	{
		return new XMLHttpRequest();
	}
	else
	{
		try
		{
			return new ActiveXObject("Msxml2.XMLHTTP");
		}
		catch (e) {}
		try
		{
			return new ActiveXObject("Microsoft.XMLHTTP");
		}
		catch (e) {}
		alert(g_StdLocaleMgr.getMessageText("NoXMLHttpRequest"));
		return null;
	}
}

function StdHttpRequest()
{
	this.m_xhr = stdCreateXMLHttpRequest();
}

StdHttpRequest.prototype.sendRequest = function(url, handler, async)
{
	this.m_xhr.open('get', url, async);
	var req = this;

	this.m_xhr.onreadystatechange = function()
	{
		var xhr = req.m_xhr;

		if (xhr.readyState == 4)
		{
			handler(xhr);
			delete xhr["onreadystatechange"]; // Remove circular reference in closure
		}
	}

	this.m_xhr.send(null);
}

StdHttpRequest.prototype.cleanUp = function()
{
	if ((this.m_xhr != undefined) && (this.m_xhr != null))
	{
		delete this["m_xhr"];
	}
}

function stdAddEventListener(target, eventName, listener, useCapture)
{
	if ((target == undefined) || (target == null)) return false;

	if (target.attachEvent)
	{
		return target.attachEvent("on" + eventName, listener);
	}
	else if (target.addEventListener)
	{
		addEventListener(eventName, listener, useCapture);
		return true;
	}
	return false;
}

// Debug scripts

function pathOnly(InString)
{
		LastSlash = InString.lastIndexOf('/', InString.length - 1);
		OutString = InString.substring(0, LastSlash + 1);
		return OutString;
}

//////////////////////////////////////////////////////////////////////////////////////////
//
// Javascript support for std_datetime weblets
//
//////////////////////////////////////////////////////////////////////////////////////////
function datetimeProxyChangedHandler(oInputBox, oHiddenInput, date_mask, bDateOnly, bDUTC, bAllowSQLNull)
{
	var dateStr = oInputBox.value;
	bDUTC = (bDUTC == null) ? false : bDUTC;
	bAllowSQLNull = (bAllowSQLNull == null) ? false : bAllowSQLNull;
	if (dateStr.length <= 0)
	{
		if (bAllowSQLNull)
		{
				datetimeSetDateValue(null, oInputBox, oHiddenInput, date_mask, bDateOnly, bDUTC);
				return true;
		}
		else
		{
			alert(g_StdLocaleMgr.getMessageText("BlankDate2"));
			datetimeSetDateValue(datetimeGetUTCDate(oHiddenInput.value), oInputBox, oHiddenInput, date_mask, bDateOnly, bDUTC);
			return false;
		}
	}
	var part1;
	var part2;
	var part3;
	var year;
	var month;
	var date;
	var dateCompArr  = dateStr.split("-");
	if( dateCompArr.length != 3 )
	{
		dateCompArr = dateStr.split("/");
	}
	if( dateCompArr.length != 3 )
	{
		alert(dateStr + g_StdLocaleMgr.getMessageText("BadDate1"));
		return false;
	}
	part1 = new Number(dateCompArr[0]);
	part2 = new Number(dateCompArr[1]);
	var dateCompArr = dateCompArr[2].split(" ");
	if( dateCompArr.length < 1 )
	{
		alert(dateStr + g_StdLocaleMgr.getMessageText("BadDate1"));
		return false;
	}
	part3 = new Number(dateCompArr[0]);
	year = part1;
	month = part2;
	date = part3;
	if( date_mask=="DD/MM/YYYY" )
	{
		year = part3;
		month = part2;
		date = part1;
	}
	else if( date_mask=="DD-MM-YYYY" )
	{
		year = part3;
		month = part2;
		date = part1;
	}
	else if( date_mask=="MM/DD/YYYY" )
	{
		year = part3;
		month = part1;
		date = part2;
	}
	else if( date_mask=="MM-DD-YYYY" )
	{
		year = part3;
		month = part1;
		date = part2;
	}
	var timeStr = "";
	if( dateCompArr.length > 1 )
	{
		var len = dateCompArr.length;
		for(var index = 1; index < len; index++)
		{
			timeStr += dateCompArr[index];
			if( index < len-1 )
			{
				timeStr += " ";
			}
		}
	}
	var enteredDateStr = dateStr;
	var dateStr = month.toString() + "-" + date.toString() + "-" + year.toString();
	if( !bDateOnly )
	{
		dateStr += " ";
		dateStr += timeStr;
	}
	if (bDUTC)
	{
		dateStr += " UTC";
	}
	var oDate = new Date(dateStr);
	if( isNaN(oDate.valueOf()) )
	{
		alert(enteredDateStr + g_StdLocaleMgr.getMessageText("BadDate1"));
		return false;
	}
	var bDateMatch = bDUTC ? (oDate.getUTCMonth()+1) == month && (oDate.getUTCDate() == date) && (oDate.getUTCFullYear() == year)
				: (oDate.getMonth()+1) == month && (oDate.getDate() == date) && (oDate.getFullYear() == year);
				
	if( !bDateMatch )
	{
		alert(enteredDateStr + g_StdLocaleMgr.getMessageText("BadDate1"));
		return false;
	}
	datetimeSetDateValue(oDate, oInputBox, oHiddenInput, date_mask, bDateOnly, bDUTC);
	return true;
}

function timeProxyChangedHandler(oInputBox, oHiddenInput, bAllowSQLNull)
{
	var dateStr = oInputBox.value;
	bAllowSQLNull = (bAllowSQLNull == null) ? false : bAllowSQLNull;
	if( dateStr.length <= 0 )
	{
		if (bAllowSQLNull)
		{
			timeSetDateValue(null, oInputBox, oHiddenInput);
			return true;
		}
		else
		{
			alert(g_StdLocaleMgr.getMessageText("BlankTime"));
			timeSetDateValue(new Date(), oInputBox, oHiddenInput);
			return false;
		}
	}
	var curDate = new Date();
	var year = new Number(curDate.getYear());
	var month = new Number(curDate.getMonth()+1);
	var date = new Number(curDate.getDate());
	var dateCompArr = dateStr.split(" ");
	if( dateCompArr.length < 1 )
	{
		alert(dateStr + g_StdLocaleMgr.getMessageText("BadTime1"));
		return false;
	}
	var timeStr = "";
	if( dateCompArr.length > 0 )
	{
		var len = dateCompArr.length;
		for(var index = 0; index < len; index++)
		{
				timeStr += dateCompArr[index];
				if( index < len-1 )
				{
					timeStr += " ";
				}
		}
	}
	var dateStr = month.toString() + "-" + date.toString() + "-" + year.toString();
	dateStr += " ";
	dateStr += timeStr;
	var oDate = new Date(dateStr);
	if( isNaN(oDate.valueOf()) )
	{
		alert(timeStr + g_StdLocaleMgr.getMessageText("BadTime1"));
		return false;
	}
	timeSetDateValue(oDate, oInputBox, oHiddenInput);
	return true;
}

function datetimeSetDateValue(oDate, oInputBox, oHiddenInput, date_mask, bDateOnly, bDUTC)
{
	var dateStr = "";
	if (oDate != null)
	{
		if (bDateOnly)
		{
			dateStr = oDate.getFullYear();
			dateStr += "-";
			dateStr += oDate.getMonth() < 9 ? "0" + (oDate.getMonth() + 1) : (oDate.getMonth() + 1);
			dateStr += "-";
			dateStr += oDate.getDate() < 10 ? "0" + oDate.getDate() : oDate.getDate();	
		}
		else
		{
			dateStr = oDate.getUTCFullYear();
			dateStr += "-";
			dateStr += oDate.getUTCMonth() < 9 ? "0" + (oDate.getUTCMonth() + 1) : (oDate.getUTCMonth() + 1);
			dateStr += "-";
			dateStr += oDate.getUTCDate() < 10 ? "0" + oDate.getUTCDate() : oDate.getUTCDate();	
			dateStr += "T";
			dateStr += oDate.getUTCHours() < 10 ? "0" + oDate.getUTCHours() : oDate.getUTCHours();
			dateStr += ":";
			dateStr += oDate.getUTCMinutes() < 10 ? "0" + oDate.getUTCMinutes() : oDate.getUTCMinutes();
			dateStr += ":";
			dateStr += oDate.getUTCSeconds() < 10 ? "0" + oDate.getUTCSeconds() : oDate.getUTCSeconds();
			dateStr += ".";
			dateStr += oDate.getUTCMilliseconds() < 10 ? "00" + oDate.getUTCMilliseconds()
				: oDate.getUTCSeconds() < 100 ? "0" + oDate.getUTCMilliseconds() : oDate.getUTCMilliseconds();
			dateStr += "Z";
		}
	}
	datetimeSetUTCDate(dateStr, true, oInputBox, oHiddenInput, date_mask, bDateOnly, bDUTC);
	oInputBox.focus();
}

function timeSetDateValue(oDate, oInputBox, oHiddenInput)
{
	var utcDateStr = oHiddenInput.value;
	var dateStr = "";
	var oTime = null;
	var timeStr = "";
	if (oDate != null)
	{
		if( isNaN(oDate.getTime()) )
		{
			if( utcDateStr.length > 0 )
			{
				timeStr += utcDateStr;
			}
			else
			{
				oTime = new Date();
			}
		}
		else
		{
			oTime = oDate;
		}
	}
	if( oTime != null )
	{
		timeStr += (oTime.getHours()<10?"0" + oTime.getHours():oTime.getHours());
		timeStr += ":";
		timeStr += (oTime.getMinutes()<10?"0" + oTime.getMinutes():oTime.getMinutes());
		timeStr += ":";
		timeStr += (oTime.getSeconds()<10?"0" + oTime.getSeconds():oTime.getSeconds());
	}
	dateStr += timeStr;
	timeSetUTCDate(dateStr, true, oInputBox, oHiddenInput);
	oInputBox.focus();
}

// Get Date object from ISO 8601 date string
function datetimeGetUTCDate(utcDateStr)
{
	var dateStr = utcDateStr;
	var milliSecs = null;
	if( utcDateStr.length > 0 )
	{
		var dateComps = utcDateStr.split("T");
		if( dateComps.length >= 1 )
		{
				var datePart = dateComps[0];
				var partArr = datePart.split("-");
				if( partArr.length == 3 )
				{
					dateStr = partArr[1];
					dateStr += "-";
					dateStr += partArr[2];
					dateStr += "-";
					dateStr += partArr[0];
				}
				else
				{
					dateStr = dateComps[0];
				}
		}
		if( dateComps.length == 2 )
		{
				var timePart = dateComps[1];
				dateStr += " ";
				var partArr = timePart.split("Z");
				if( partArr.length == 2 )
				{
					var fracSec = partArr[0].split(".");
					if( fracSec.length == 2 )
					{
							dateStr += fracSec[0];
							milliSecs = fracSec[1].substring(0, 3);
					}
					else
					{
							dateStr += partArr[0];
					}
					dateStr += " UTC";
				}
				else
				{
					var tzdChar = "+";
					partArr = timePart.split(tzdChar);
					if( partArr.length != 2 )
					{
							tzdChar = "-";
							partArr = timePart.split(tzdChar);
					}
					if( partArr.length == 2 )
					{
							var fracSec = partArr[0].split(".");
							if( fracSec.length == 2 )
							{
									dateStr += fracSec[0];
									milliSecs = fracSec[1].substring(0, 3);
							}
							else
							{
									dateStr += partArr[0];
							}
							dateStr += " UTC";
							dateStr += tzdChar;
							dateStr += partArr[1].replace(":", "");
					}
					else
					{
							dateStr += dateComps[1];
					}
				}
		}
	}
	var oDate = new Date(dateStr);
	if( milliSecs != null )
	{
		oDate.setMilliseconds(milliSecs);
	}
	oDate.sqlNull = utcDateStr.length > 0 ? false : true;
	return oDate;
}

// Sets the hidden date field in ISO 8601 and sets the proxy formatted in the requested date mask
// from an input date string in ISO 8601 format
function datetimeSetUTCDate(utcDateStr, bInputMode, oInputBox, oHiddenInput, date_mask, bDateOnly, bDUTC)
{
	if( bInputMode )
	{
		oHiddenInput.value = utcDateStr;
	}
	var oDate = datetimeGetUTCDate(utcDateStr);
	if ((oDate != null) && !isNaN(oDate.valueOf()))
	{
		var year; var month; var date;
		bDUTC = (bDUTC == null) ? false : bDUTC;  // If true, use UTC value to display proxy
		if (bDUTC)
		{
			year = oDate.getUTCFullYear();
			month = (oDate.getUTCMonth()<9?"0" + (oDate.getUTCMonth()+1):(oDate.getUTCMonth()+1));
			date = (oDate.getUTCDate()<10?"0" + oDate.getUTCDate():oDate.getUTCDate());
		}
		else
		{
			year = oDate.getFullYear();
			month = (oDate.getMonth()<9?"0" + (oDate.getMonth()+1):(oDate.getMonth()+1));
			date = (oDate.getDate()<10?"0" + oDate.getDate():oDate.getDate());
		}
		var part1 = year;
		var part2 = month;
		var part3 = date;
		var sep = "-";
		if( date_mask=="DD/MM/YYYY" )
		{
			part1 = date;
			part2 = month;
			part3 = year;
			sep = "/";
		}
		else if( date_mask=="DD-MM-YYYY" )
		{
			part1 = date;
			part2 = month;
			part3 = year;
		}
		else if( date_mask=="MM/DD/YYYY" )
		{
			part1 = month;
			part2 = date;
			part3 = year;
			sep = "/";
		}
		else if( date_mask=="MM-DD-YYYY" )
		{
			part1 = month;
			part2 = date;
			part3 = year;
		}
		var dispStr = part1;
		dispStr += sep;
		dispStr += part2;
		dispStr += sep;
		dispStr += part3;
		if( !bDateOnly )
		{
			var timeDispStr;
			
			if (!bDUTC)
			{
				timeDispStr = oDate.toLocaleTimeString();
			}
			else
			{
				oCheatDate = new Date();
				// Offset time so that "local time" shows UTC time instead
				oCheatDate.setTime(oDate.getTime() + (oDate.getTimezoneOffset() * 60000));
				timeDispStr = oCheatDate.toLocaleTimeString();
			}

			if( timeDispStr != null && timeDispStr.length > 0 )
			{
					dispStr += " ";
					dispStr += timeDispStr;
			}
		}
		if( bInputMode )
		{
				oInputBox.value = dispStr;
		}
		else
		{
				oInputBox.innerText = dispStr;
		}
	}
	else
	{
		if( bInputMode )
		{
			oInputBox.value = utcDateStr;
		}
		else
		{
			oInputBox.innerText = utcDateStr;
		}
	}
}

function timeSetUTCDate(utcDateStr, bInputMode, oInputBox, oHiddenInput)
{
	if( bInputMode )
	{
		oHiddenInput.value = utcDateStr;
	}
	var dispStr = "";
	if (utcDateStr.length > 0)
	{
		var oDate = new Date();
		dispStr = oDate.toLocaleDateString() + " ";
		dispStr += utcDateStr;
		oDate = new Date(dispStr);
		dispStr = oDate.toLocaleTimeString();
		if (isNaN(oDate.valueOf()))
		{
			dispStr = utcDateStr;
		}
	}
	if( bInputMode )
	{
		oInputBox.value = dispStr;
	}
	else
	{
		oInputBox.innerText = dispStr;
	}
}

// Offsets the Date for calendar to show the "UTC date"
function datetimeOffsetUTCDate(oDate, subtract)
{
	if (!isNaN(oDate.valueOf()))
	{
		var offset = oDate.getTimezoneOffset() * 60000; // East of UTC is negative
		oDate.setTime(subtract ? oDate.getTime() + offset : oDate.getTime() - offset);
	}
	return oDate;
}
//////////////////////////////////////////////////////////////////////////////////////////
//
// Javascript support for std_button and std_image_button weblets
//
//////////////////////////////////////////////////////////////////////////////////////////

// Call inside <script> immediately after <button type="submit"> or <input type="submit"> to set as default submit
function stdSetDefaultSubmitButton(oForm, oTagName, oName)
{
	if (oForm == null) return;
	var oElems = document.getElementsByName(oName);
	var oLast = null;

	for (i = 0; i < oElems.length; i++)
	{
		var oCurr = oElems[i];
		if ((oCurr.getAttribute("type").toLowerCase() == "submit") && (oCurr.tagName.toLowerCase() == oTagName)) oLast = oElems[i];
	}
	oForm.setAttribute("__defaultSubmitButton", oLast);
}

function stdGetDefaultSubmitButton(oForm)
{
	return oForm != null ? oForm.getAttribute("__defaultSubmitButton") : null;
}
//////////////////////////////////////////////////////////////////////////////////////////
//
// Javascript support for std_prompter weblet
//
//////////////////////////////////////////////////////////////////////////////////////////

function prompterCheckPrompter(oPanel, oPrompter, oPromptButton, funcCheckPrompter)
{
	var bIsHidden = false;
	var activeElem = document.activeElement;
	if( document.hasFocus() && activeElem != oPanel )
	{
		if( !oPromptButton.contains(activeElem) )
		{
				oPrompter.style.display = "none";
				bIsHidden = true;
		}
	}
	if( !bIsHidden )
	{
		setTimeout(funcCheckPrompter, 1000);
	}
}

function prompterClosePrompter(oPanel, oPrompter, oPromptButton)
{
	var activeElem = document.activeElement;
	if( document.hasFocus() && activeElem != oPanel )
	{
		if( !oPromptButton.contains(activeElem) )
		{
				oPrompter.style.display = "none";
				return true;
		}
	}
	return false;
}

function prompterDoPrompt(oButton, oPanel, oPrompter, oPrompterShadow, oPromptButton, funcLoadFrame, funcClosePrompter, funcCheckPrompter, funcLeftAlign, funcTopAlign)
{
	if( oPrompter != null && oPrompter.parentNode != window.top.document.body )
	{
		var body = stdGetOwnerDocument(oPrompter).body;
		if( oPrompter.parentNode != body )
		{
			body.appendChild(oPrompter);
			if( oPrompterShadow != null && oPrompterShadow.parentNode != body )
			{
				body.appendChild(oPrompterShadow);
			}
		}
	}
	if( oPrompter.style.display == "none" )
	{
		var button = oPromptButton;
		var buttonStyle = button.style;
		var xPos = button.offsetLeft;
		var yPos = button.offsetTop;
		var offParent = button.offsetParent;
		while( offParent != null && offParent != oPrompter.parentNode )
		{
			xPos -= offParent.scrollLeft;
			yPos -= offParent.scrollTop;
			xPos += offParent.offsetLeft;
			yPos += offParent.offsetTop;
			offParent = offParent.offsetParent;
		}
		oPrompter.style.left = xPos + button.offsetWidth;
		oPrompter.style.top = yPos;
		oPanel.setAttribute("_not_loaded", "1");
		oPanel.setAttribute("_not_sized", "1");
		oPanel.setAttribute("_left_align_func", funcLeftAlign);
		oPanel.setAttribute("_top_align_func", funcTopAlign);
		var clientWidth = document.body.scrollLeft + document.body.clientWidth;
		var clientHeight = document.body.scrollTop + document.body.clientHeight;
		funcLoadFrame(oPanel);
		oPrompter.style.visibility = "hidden";
		oPrompter.style.display = "";
		oButton.onblur = funcClosePrompter;
		setTimeout(funcCheckPrompter, 1000);
	}
	else
	{
		oButton.onblur = null;
		oPrompter.style.display = "none";
	}
}

function prompterLeftAlign(pWidth, oPrompter, oPromptButton)
{
	var clientWidth = document.body.scrollLeft + document.body.clientWidth;
	if( clientWidth < oPrompter.style.pixelLeft + pWidth )
	{
		var button = oPromptButton;
		oPrompter.style.left = oPrompter.style.pixelLeft - pWidth - button.offsetWidth - 8;
	}
}

function prompterTopAlign(pHeight, oPrompter, oPromptButton)
{
	var clientHeight = document.body.scrollTop + document.body.clientHeight;
	if( clientHeight < oPrompter.style.pixelTop + pHeight )
	{
		oPrompter.style.top = oPrompter.style.pixelTop - pHeight - 8;
	}
	oPrompter.style.visibility = "";
}

function prompterOnreadystatechange(oPanel, oPrompter, panelName, closingWRName, closingURL, formname, field_name_to_exchange, funcOnChangeHandler)
{
	var oFrame = oPanel;
	if( oFrame.readyState == null || oFrame.readyState == "complete" )
	{
		var doc;
		try
		{
			doc = window.frames[panelName].document;
		}
		catch(exception)
		{
			doc = null;
		}
		if( doc != null )
		{
			var bMatchFound = false;
			var oColOrObj = stdGetFromDocumentByNameOrId(doc, "_WEBROUTINE");
			if( oColOrObj != null )
			{
				var oWRInput = oColOrObj;
				var match = closingWRName.toUpperCase();
				if( oColOrObj.value == null )
				{
					var length = oColOrObj.length;
					if( length != null )
					{
						if( length > 0 )
						{
							oWRInput = oColOrObj[index];
						}
						for(var index = 0; index < length; index++)
						{
							var obj = oColOrObj[index];
							if( obj != null )
							{
								if( obj.form == null || obj.form.getAttribute("__x_temp_form") == null )
								{
									oWRInput = obj;
									break;
								}
							}
						}
					}
				}
				var wrName = oWRInput.value.toUpperCase();
				if( wrName == match )
				{
					bMatchFound = true;
				}
			}
			else
			{
				var url = doc.location.search;
				url = url.toUpperCase();
				if( closingWRName != "" )
				{
					var match = "webrtn=" + closingWRName;
					match = match.toUpperCase();
					var keys = url.split("+");
				}
				else
				{
					var match = closingURL.toUpperCase();
					var keys = url.split("/");
				}
				var length = keys.length;
				for(var index = 0; index < length; index++)
				{
					var key = keys[index];
					if( key == match )
					{
						bMatchFound = true;
						break;
					}
				}
			}
			if( bMatchFound )
			{
				oPrompter.style.display = "none";
				if( field_name_to_exchange != "" )
				{
					var targElem = null;
					if( document.getElementsByName(field_name_to_exchange).length == 1 )
					{
						targElem = stdGetFromDocumentByNameOrId(document, field_name_to_exchange);
					}
					else if( formname != null && formname.length > 0 )
					{
						targElem = document.forms[formname].elements[field_name_to_exchange];
					}
					else if( oPanel != null )
					{
						var oForm = stdGetParentForm(oPanel);
						if( oForm != null )
						{
							targElem = oForm.elements[field_name_to_exchange];
						}
					}
					if( targElem != null )
					{
						var elem = stdGetFromDocumentByNameOrId(doc, field_name_to_exchange);
						if( elem != null )
						{
							targElem.value = elem.value;
							try
							{
								targElem.focus();
								var oRange = targElem.createTextRange();
								oRange.select();
							}
							catch(exception)
							{
							}
							if( IsIE() )
							{
								targElem.fireEvent("onchange");
							}
							else
							{
								targElem.onchange();
							}
							if( funcOnChangeHandler != null )
							{
								funcOnChangeHandler();
							}
						}
					}
				}
				else
				{
					var elems = stdGetFromDocumentByNameOrId(doc, formname).elements;
					var length = elems.length;
					for(var index = 0; index < length; index++)
					{
						var elem = elems[index];
						var name = elem.name;
						if( name.length <= 0 )
						{
							name = elem.id;
						}
							if( name.length > 0 && name[0] != "_" )
							{
								if( elem.tagName.toLowerCase() == "input" && (elem.type == "hidden" || elem.type == "text"))
								{
									var value = elem.value;
									if( value != null )
									{
										var targElem = stdGetFromDocumentByNameOrId(document, formname).elements[name];
										if( targElem != null )
										{
											targElem.value = value;
											if( index == 0 )
											{
												try
												{
													targElem.focus();
													var oRange = targElem.createTextRange();
													oRange.select();
												}
												catch(exception)
												{
												}
											}
											if( IsIE() )
											{
												targElem.fireEvent("onchange");
											}
											else
											{
												targElem.onchange();
											}
										}
									}
								}
							}
						}
						if( funcOnChangeHandler != null )
						{
							funcOnChangeHandler();
						}
					}
					doc.body.innerHTML = "";
				}
				else
				{
				if( doc.body != null )
				{
					var width = doc.body.scrollWidth;
					if( width > 0 )
					{
						oFrame.style.width = width.toString() + "px";
					}
				}
			}
		}
	}
}

function prompterOnMoveHandler(oPrompter, oShadowFrame)
{
	oShadowFrame.style.pixelLeft = oPrompter.style.pixelLeft;
	oShadowFrame.style.pixelTop = oPrompter.style.pixelTop;
	oShadowFrame.style.pixelWidth = oPrompter.offsetWidth;
	oShadowFrame.style.pixelHeight = oPrompter.offsetHeight;
}

function prompterOnResizeHandler(oPrompter, oShadowFrame)
{
	oShadowFrame.style.pixelLeft = oPrompter.style.pixelLeft;
	oShadowFrame.style.pixelTop = oPrompter.style.pixelTop;
	oShadowFrame.style.pixelWidth = oPrompter.offsetWidth;
	oShadowFrame.style.pixelHeight = oPrompter.offsetHeight;
}

function prompterOnPropChangeHandler(oPrompter, oShadowFrame)
{
	var eventObj = window.event;
	if( eventObj.propertyName == "style.display" )
	{
		oShadowFrame.style.display = oPrompter.style.display;
	}
	else if( eventObj.propertyName == "style.visibility" )
	{
		oShadowFrame.style.visibility = oPrompter.style.visibility;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////
//
// Javascript support for std_nav_panel weblet
//
//////////////////////////////////////////////////////////////////////////////////////////

function stdNavPanelLoadFrame(oFrame,
		delayLoadNavsAttrName,
		delayLoadNavsArrAttrName,
		funcReloadFrame,
		funcNavigate,
		funcResizeFrame,
		funcResetLoadState)
{
	if( oFrame.getAttribute("_not_loaded") == "1" )
	{
		if( oFrame.getAttribute("_delayload_queued") != "1" )
		{
			var parentElem = stdGetParentElement(oFrame);
			while( parentElem != null )
			{
				var vStyle = parentElem.style;
				if( vStyle != null )
				{
					if( vStyle.display == "none" || vStyle.visibility == "hidden" )
					{
						var vDelayLoadNavs = parentElem.getAttribute(delayLoadNavsAttrName);
						if( vDelayLoadNavs != null && vDelayLoadNavs == "true" )
						{
							var objArr = parentElem.getAttribute(delayLoadNavsArrAttrName);
							if( objArr == null )
							{
								objArr = new Array();
								parentElem.setAttribute(delayLoadNavsArrAttrName, objArr);
							}
							objArr.push(funcReloadFrame);
							oFrame.setAttribute("_delayload_queued", "1");
							return;
						}
					}
				}
				parentElem = stdGetParentElement(parentElem);
			}
		}
		oFrame.removeAttribute("_not_loaded");
		if( funcNavigate != null )
		{
			funcNavigate(oFrame);
		}
	}
	else
	{
		if( funcResizeFrame != null )
		{
			funcResizeFrame(oFrame);
		}
		if( funcResetLoadState != null )
		{
			funcResetLoadState(oFrame);
		}
	}
}

function stdNavPanelResetLoadState(oFrame,
		reloadNavsAttrName,
		reloadNavsArrAttrName,
		funcReloadFrame)
{
	if( oFrame.getAttribute("_reload_queued") != "1" )
	{
		var parentElem = stdGetParentElement(oFrame);
		while( parentElem != null )
		{
			var vReloadNavs = parentElem.getAttribute(reloadNavsAttrName);
			if( vReloadNavs != null && vReloadNavs == "true" )
			{
				var objArr = parentElem.getAttribute(reloadNavsArrAttrName);
				if( objArr == null )
				{
					objArr = new Array();
					parentElem.setAttribute(reloadNavsArrAttrName, objArr);
				}
				objArr.push(funcReloadFrame);
				oFrame.setAttribute("_reload_queued", "1");
				break;
			}
			parentElem = stdGetParentElement(parentElem);
		}
	}
}

function stdNavPanelReloadFrame(oFrame,
		bResetLoaded,
		funcLoadFrame)
{
	if( bResetLoaded != null && bResetLoaded )
	{
		oFrame.setAttribute("_not_loaded", "1");
	}
	if( funcLoadFrame != null )
	{
		funcLoadFrame(oFrame);
	}
}

function navPanelResizeFrame(oFrame, frameName, size_panel_to_content, size_panel_axis)
{
	var isResized = false;
	if( oFrame.getAttribute("_not_sized") == "1" )
	{
		if( size_panel_to_content )
		{
			if( oFrame.readyState == null || oFrame.readyState == "complete" )
			{
				var doc;
				try {
					doc = window.frames[frameName].document;
				}
				catch(exception)
				{
					doc = null;
				}
				if( doc != null && doc.body != null )
				{
					var funcLeftAlign = oFrame.getAttribute("_left_align_func");
					var funcTopAlign = oFrame.getAttribute("_top_align_func");
					oFrame.removeAttribute("_left_align_func");
					oFrame.removeAttribute("_top_align_func");
					if( size_panel_axis == null || size_panel_axis == 'width' || size_panel_axis == 'both' )
					{
						var width = doc.body.scrollWidth;
						if( width > 0 )
						{
							if( funcLeftAlign != null )
							{
								funcLeftAlign(width);
							}
							oFrame.style.width = width.toString() + "px";
							oFrame.removeAttribute("_not_sized");
							isResized = true;
						}
					}
					if( size_panel_axis == null || size_panel_axis == 'height' || size_panel_axis == 'both' )
					{
						var height = doc.body.scrollHeight;
						if( height > 0 )
						{
							if( funcTopAlign != null )
							{
								funcTopAlign(height);
							}
							oFrame.style.height = height.toString() + "px";
							oFrame.removeAttribute("_not_sized");
							isResized = true;
						}
					}
				}
				else
				{
					oFrame.removeAttribute("_not_sized");
					oFrame.removeAttribute("_left_align_func");
					oFrame.removeAttribute("_top_align_func");
				}
			}
		}
		else
		{
			oFrame.removeAttribute("_not_sized");
			oFrame.removeAttribute("_left_align_func");
			oFrame.removeAttribute("_top_align_func");
		}
	}
	return isResized;
}

function stdNavPanelGetLinksHTML()
{
	var linksHTML = "";
	var allLinks = document.styleSheets;
	if( allLinks != null )
	{
		var length = allLinks.length;
		for(var index = 0; index < length; index++)
		{
			var aLink = allLinks[index];
			var href = stdNavPanelGetExpandedURL(aLink.href);
			if( href != null && href.length > 0 )
			{
				linksHTML += "<link href=\"" + href + "\"" + " type=\"text/css\" rel=\"stylesheet\" />";
			}
		}
	}
	return linksHTML;
}

function stdNavPanelGetExpandedURL(relURL)
{
	var expURL = relURL;
	if( expURL != null && expURL.length > 0 )
	{
		if( expURL.substr(0, 2) != "//" && expURL.search(":") < 0 )
		{
			if( expURL.charAt(0) == '/' )
			{
				expURL = "//" + document.location.host + expURL;
			}
			else
			{
				expURL = "//" + document.location.host + "/" + expURL;
			}
		}
	}
	return expURL;
}

function stdNavPanelWaitImageLoaded(oFrame)
{
	oFrame.setAttribute("_wait_image_loaded", 1);
}

function stdNavPanelGetWaitHTML(oFrame, wait_absolute_image_path, wait_content_image_alignment, wait_content_image_class, wait_content, wait_content_class)
{
	var waitHTML = stdNavPanelGetLinksHTML();
	if( wait_absolute_image_path != null && wait_absolute_image_path.length > 0 )
	{
		if( wait_content_image_alignment == "top" )
		{
			waitHTML += "<img onerror=\"window.parent.document.Script.stdNavPanelWaitImageLoaded(document.parentWindow.frameElement)\" onload=\"window.parent.document.Script.stdNavPanelWaitImageLoaded(document.parentWindow.frameElement)\" class=\"" + wait_content_image_class + "\" src=\"" + stdNavPanelGetExpandedURL(wait_absolute_image_path) + "\" /><br />" + wait_content;
		}
		else if( wait_content_image_alignment == "right" )
		{
			waitHTML += wait_content + "<img onerror=\"window.parent.document.Script.stdNavPanelWaitImageLoaded(document.parentWindow.frameElement)\" onload=\"window.parent.document.Script.stdNavPanelWaitImageLoaded(document.parentWindow.frameElement)\" class=\"" + wait_content_image_class + "\" src=\"" + stdNavPanelGetExpandedURL(wait_absolute_image_path) + "\" />";
		}
		else if( wait_content_image_alignment == "bottom" )
		{
			waitHTML += wait_content + "<br /><img onerror=\"window.parent.document.Script.stdNavPanelWaitImageLoaded(document.parentWindow.frameElement)\" onload=\"window.parent.document.Script.stdNavPanelWaitImageLoaded(document.parentWindow.frameElement)\" class=\"" + wait_content_image_class + "\" src=\"" + stdNavPanelGetExpandedURL(wait_absolute_image_path) + "\" />";
		}
		else
		{
			waitHTML += "<img onerror=\"window.parent.document.Script.stdNavPanelWaitImageLoaded(document.parentWindow.frameElement)\" onload=\"window.parent.document.Script.stdNavPanelWaitImageLoaded(document.parentWindow.frameElement)\" class=\"" + wait_content_image_class + "\" src=\"" + stdNavPanelGetExpandedURL(wait_absolute_image_path) + "\" />" + wait_content;
		}
	}
	else
	{
		waitHTML += wait_content;
		stdNavPanelWaitImageLoaded(oFrame);
	}
	return "<table style=\"height:100%;width:100%\" cellpadding=\"0\" cellspacing=\"0\"><tbody><tr><td class=\"" + wait_content_class + "\">" + waitHTML + "</td></tr></tbody></table>";
}

function stdGetOwnerDocument(oElem)
{
	if( oElem == null )
	{
		return document;
	}
	var oDoc = oElem.document;
	if( oDoc == null )
	{
		oDoc = oElem.ownerDocument;
	}
	return oDoc;
}

function stdGetParentElement(oElem)
{
	if( oElem == null )
	{
		return null;
	}
	var parentNode = oElem.parentElement;
	if( parentNode != null )
	{
		return parentNode;
	}
	parentNode = oElem.parentNode;
	while( parentNode != null && parentNode.getAttribute == null )
	{
		parentNode = parentNode.parentNode;
	}
	return parentNode;
}

function stdGetParentForm(oElem)
{
	if( oElem == null )
	{
		return null;
	}
	var oForm = null;
	try
	{
		oForm = oElem.form;
	}
	catch(exception)
	{
		oForm = null;
	}
	if( oForm == null )
	{
		var oForm = oElem;
		while( oForm != null )
		{
			if( oForm.nodeName.toLowerCase() == "form" )
			{
				return oForm;
			}
			oForm = oForm.parentNode;
		}
	}
	return null;
}

function stdGetFromDocumentByNameOrId(oDoc, objNameOrId)
{
	if( oDoc == null )
	{
		oDoc = document;
	}
	if( oDoc.all != null )
	{
		return oDoc.all[objNameOrId];
	}
	var oMatchList = oDoc.getElementsByName(objNameOrId);
	if( oMatchList.length > 0 )
	{
		return oMatchList[0];
	}
	return oDoc.getElementById(objNameOrId);
}

function stdGetDescendantByNameOrId(oParent, objNameOrId)
{
	if( oParent.all != null )
	{
		return oParent.all[objNameOrId];
	}
	return stdRecGetDescendantByNameOrId(oParent, objNameOrId);
}

function stdRecGetDescendantByNameOrId(oParent, objNameOrId)
{
	if( oParent == null )
	{
		return null;
	}
	var oChild = oParent.firstChild;
	while( oChild != null )
	{
		if( oChild.getAttribute != null && oChild.getAttribute("name") == objNameOrId )
		{
			return oChild;
		}
		if( oChild.id == objNameOrId )
		{
			return oChild;
		}
		oChild = oChild.nextSibling;
	}
	var oChild = oParent.firstChild;
	while( oChild != null )
	{
		var oMatch = stdRecGetDescendantByNameOrId(oChild, objNameOrId);
		if( oMatch != null )
		{
			return oMatch;
		}
		oChild = oChild.nextSibling;
	}
	return null;
}

function stdGetSpanText(oParent, objId)
{
	if (oParent == null)
	{
		return objId != null ? document.getElementById(objId).innerHTML.replace(/(<!---->)$/, "") : "";
	}
	else
	{
		var spans = oParent.getElementsByTagName("span");
		for (i = 0; i <spans.length; i++)
		{
			if (spans[i].getAttribute("id") == objId)
			{
				// Strip <!----> appended to avoid self-closing
				return spans[i].innerHTML.replace(/(<!---->)$/, "");
			}
		}
		return "";
	}
}

//////////////////////////////////////////////////////////////////////////////////////////
//
// Javascript support for std_tab_pages weblet
//
//////////////////////////////////////////////////////////////////////////////////////////

function stdTabPagesHandleClick(oTab, tabIndex,
		oTabHolder,
		tabImageName,
		tabImagePath,
		tabNameBase,
		unselTabClassName,
		selTabClassName,
		viewBaseName,
		reloadNavsArrAttrName,
		delayLoadNavsArrAttrName
		)
{
	var isDisabled = oTab.getAttribute("_tab_disabled");
	if( isDisabled != null && isDisabled=='true' )
	{
		return;
	}
	isDisabled = oTab.disabled;
	if( isDisabled != null && isDisabled )
	{
		return;
	}
	var curIndex = oTabHolder.getAttribute("_active_tab_index");
	var oActiveTab = stdGetFromDocumentByNameOrId(document, tabNameBase + curIndex);
	if( tabImageName != null && oActiveTab != null && oActiveTab != oTab )
	{
		var oTabImage = stdGetDescendantByNameOrId(oTab, tabImageName);
		if( oTabImage != null )
		{
			oTabImage.src = tabImagePath;
		}
	}
	if( oActiveTab != null && oActiveTab != oTab )
	{
		if( tabImageName != null )
		{
			var oActiveTabImage = stdGetDescendantByNameOrId(oActiveTab, tabImageName);
			if( oActiveTabImage != null )
			{
				oActiveTabImage.src = oActiveTabImage.getAttribute("_unsel_src");
			}
		}
		oActiveTab.className = unselTabClassName;
	}
	oTab.className = selTabClassName;
	oTabHolder.setAttribute("_active_tab_index", tabIndex);
	var oActiveFrame = stdGetFromDocumentByNameOrId(document, viewBaseName + curIndex);
	if( oActiveFrame != null )
	{
		oActiveFrame.style.display = "none";
	}
	oActiveFrame = stdGetFromDocumentByNameOrId(document, viewBaseName + tabIndex);
	oActiveFrame.style.display = "";
	oActiveFrame.style.width = "100%";
	oActiveFrame.style.height = "100%";
	lansaEvent_Fire(oActiveFrame, "lansaEventOnDisplay");
	lansaEvent_Fire(oActiveFrame, reloadNavsArrAttrName, true);
	lansaEvent_Fire(oActiveFrame, delayLoadNavsArrAttrName, false);
	oActiveFrame.removeAttribute(delayLoadNavsArrAttrName);
}

//////////////////////////////////////////////////////////////////////////////////////////
//
// Javascript support for std_messages weblet
//
//////////////////////////////////////////////////////////////////////////////////////////
function stdTransferMessages(htmlMarkup, targetWindowName, msgElemId)
{
	if( msgElemId == null || msgElemId.length <= 0 )
	{
		return;
	}

	var oWnd = null;
	var doc = null;
	if( targetWindowName == null || targetWindowName.length <= 0 || targetWindowName == "_top" )
	{
		oWnd = window.top;
		doc = oWnd.document;
	}
	if( oWnd == null && window.name != targetWindowName )
	{
		doc = document;
		while( doc != null && stdGetFromDocumentByNameOrId(doc, targetWindowName) == null )
		{
			var oWnd = doc.parentWindow;
			doc = null;
			if( oWnd != null && oWnd != window.top && oWnd.parent != null )
			{
				doc = oWnd.parent.document;
			}
		}
	}
	if( doc != null )
	{
		var oMsgElem = stdGetFromDocumentByNameOrId(doc, msgElemId);
		if( oMsgElem != null )
		{
			oMsgElem.innerHTML = htmlMarkup;
			if( htmlMarkup == null || htmlMarkup.length <= 0 )
			{
				oMsgElem.className = "messages hidden";
			}
			else
			{
				oMsgElem.className = "messages";
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////
//
// Javascript support for dhtml_hide_show weblet
//
//////////////////////////////////////////////////////////////////////////////////////////
function stdFindByNameOrId(oDocOrForm, nameOrId)
{
	if( oDocOrForm == null || nameOrId == null || nameOrId.length <= 0 )
	{
		return null;
	}
	var bIsAForm = (oDocOrForm.nodeName.toLowerCase() == "form");
	var targetElement = null;
	if( bIsAForm )
	{
		targetElement = oDocOrForm.elements[nameOrId];
		if( targetElement == null )
		{
			oDocOrForm = oDocOrForm.ownerDocument;
		}
	}
	if( targetElement == null )
	{
		var oElemList = oDocOrForm.getElementsByName(nameOrId);
		if( oElemList.length <= 0 )
		{
			targetElement = oDocOrForm.getElementById(nameOrId);
		}
		else
		{
			targetElement = oElemList;
		}
	}
	return targetElement;
}

function stdDhtmlHideShowOnchangeHandler(oEvent, oSrcElem, srcDoc, srcName, hideTargetDoc, hideTargetName, showTargetDoc, showTargetName, funcHideEval, visible_css_class, hidden_css_class, clear_all_fields, clear_input_fields, clear_button_fields, clear_select_fields, clear_textarea_fields)
{
	var hideTargetElement = stdFindByNameOrId(hideTargetDoc, hideTargetName);
	var showTargetElement = stdFindByNameOrId(showTargetDoc, showTargetName);
	var srcElement = stdFindByNameOrId(srcDoc, srcName);
	try{ if(srcElement.tagName==null){srcElement = oSrcElem;} }catch(exception){srcElement = oSrcElem;}
	if(srcElement==null && event!=null){srcElement = event.srcElement;}
	var srcElementControl = srcElement;
	if( srcElement!= null && srcElement.tagName.toLowerCase() == "input" && srcElement.type.toLowerCase() == "hidden" )
	{
		var targetName = '__' + srcElement.name + '_PROXY';
		var srcElementControl = stdFindByNameOrId(srcDoc, targetName);
		if( srcElementControl == null )
		{
			srcElementControl = srcElement;
		}
	}
	var boolHideEval = (funcHideEval(srcDoc, hideTargetDoc, showTargetDoc, srcElement, srcElementControl, hideTargetElement, showTargetElement));
	stdDhtmlHideShowHide(boolHideEval, hideTargetElement, hideTargetDoc, visible_css_class, hidden_css_class, clear_all_fields, clear_input_fields, clear_button_fields, clear_select_fields, clear_textarea_fields);
	stdDhtmlHideShowHide(!boolHideEval, showTargetElement, showTargetDoc, visible_css_class, hidden_css_class, clear_all_fields, clear_input_fields, clear_button_fields, clear_select_fields, clear_textarea_fields);
}

function stdDhtmlHideShowHide(boolHideEval, targetElement, targetOwner, visible_css_class, hidden_css_class, clear_all_fields, clear_input_fields, clear_button_fields, clear_select_fields, clear_textarea_fields)
{
	if( targetElement == null )
	{
		return;
	}
	var targColl = null;
	var colIndex = 0;
	try{ if(targetElement.tagName==null){targColl = targetElement;} }catch(exception){targColl = targetElement;}
	while(true)
	{
		if( targColl != null && colIndex >= targColl.length )
		{
			break;
		}
		if( targColl != null )
		{
			targetElement = targColl[colIndex];
		}
		if( targetElement != null && targetElement.tagName.toLowerCase() == "input" && targetElement.type.toLowerCase() == "hidden" )
		{
			var targetName = '__' + targetElement.name + '_PROXY';
			var targetElementProxy = stdFindByNameOrId(targetOwner, targetName);
			if( targetElementProxy != null )
			{
				targetElement = targetElementProxy;
			}
		}
		if( boolHideEval )
		{
			if( visible_css_class == null || visible_css_class.length <= 0 )
			{
				var curVisibleClassName = targetElement.getAttribute("__visibleClassName");
				if( curVisibleClassName == null )
				{
					var prevVisClassName = targetElement.className;
					if( prevVisClassName == null )
					{
						prevVisClassName = "";
					}
					targetElement.setAttribute("__visibleClassName", prevVisClassName);
				}
			}
			targetElement.className = hidden_css_class;
			if( clear_all_fields || clear_input_fields )
			{
				var oTargetChildList = targetElement.getElementsByTagName("input");
				var length = oTargetChildList.length;
				for(var index = 0; index < length; index++)
				{
					oTargetChildList[index].value = '';
				}
				if( targetElement.tagName.toLowerCase() == "input" )
				{
					targetElement.value = '';
				}
			}
			if( clear_all_fields || clear_button_fields )
			{
				var oTargetChildList = targetElement.getElementsByTagName("button");
				var length = oTargetChildList.length;
				for(var index = 0; index < length; index++)
				{
					oTargetChildList[index].value = '';
				}
				if( targetElement.tagName.toLowerCase() == "button" )
				{
					targetElement.value = '';
				}
			}
			if( clear_all_fields || clear_select_fields )
			{
				var oTargetChildList = targetElement.getElementsByTagName("select");
				var length = oTargetChildList.length;
				for(var index = 0; index < length; index++)
				{
					oTargetChildList[index].selectedIndex = -1;
				}
				if( targetElement.tagName.toLowerCase() == "select" )
				{
					targetElement.selectedIndex = -1;
				}
			}
			if( clear_all_fields || clear_textarea_fields )
			{
				var oTargetChildList = targetElement.getElementsByTagName("textarea");
				var length = oTargetChildList.length;
				for(var index = 0; index < length; index++)
				{
					oTargetChildList[index].value = '';
				}
				if( targetElement.tagName.toLowerCase() == "textarea" )
				{
					targetElement.value = '';
				}
			}
		}
		else
		{
			if( visible_css_class != null && visible_css_class.length > 0 )
			{
				targetElement.className = visible_css_class;
			}
			else
			{
				var prevVisClassName = targetElement.getAttribute("__visibleClassName");
				if( prevVisClassName != null )
				{
					targetElement.className = prevVisClassName;
					targetElement.removeAttribute("__visibleClassName");
				}
				else
				{
					if( targetElement.className == hidden_css_class )
					{
						targetElement.className = visible_css_class;
					}
				}
			}
		}
		if( targColl == null )
		{
			break;
		}
		colIndex++;
	}
}

function stdDhtmlHideShowAttachHandler(src_doc, source_name, event_type, funcOnchangeHandler, run_handler_onload)
{
	var srcElement = stdFindByNameOrId(src_doc, source_name);
	if( srcElement != null )
	{
		var colIndex = 0;
		var srcCollection = null;try { if(srcElement.tagName==null){srcCollection = srcElement;} } catch(exception) { srcCollection = srcElement; }
		while(true)
		{
			if( srcCollection != null )
			{
				if( colIndex >= srcCollection.length )
				{
					break;
				}
				srcElement = srcCollection[colIndex];
			}
			if( srcElement.tagName.toLowerCase() == "input" && srcElement.type.toLowerCase() == "hidden" )
			{
				var targetName = '__' + srcElement.name + '_PROXY';
				var srcElementProxy = stdFindByNameOrId(src_doc, targetName);
				if( srcElementProxy != null )
				{
					srcElement = srcElementProxy;
				}
			}
			var eventName = "change";
			if( event_type != null && event_type.length > 0 )
			{
				eventName = event_type;
			}
			else
			{
				var eventName = "change";
				if( srcElement.nodeName.toLowerCase() == "input" )
				{
					var inpType = srcElement.type.toLowerCase();
					if( inpType == "button" || inpType == "checkbox" || inpType == "file" || inpType == "image" || inpType == "radio" || inpType == "submit" || inpType == "reset" )
					{
						eventName = "click";
					}
				}
				else if( srcElement.tagName.toLowerCase() == "button" )
				{
					eventName = "click";
				}
			}
			if( srcElement.attachEvent != null )
			{
				srcElement.attachEvent("on" + eventName, funcOnchangeHandler);
			}
			else
			{
				srcElement.addEventListener(eventName, funcOnchangeHandler, false);
			}
			if( run_handler_onload )
			{
				if( srcElement.nodeName.toLowerCase() != "input" || srcElement.type.toLowerCase() != "radio" || srcElement.checked )
				{
					funcOnchangeHandler(null, srcElement);
				}
			}
			if( srcCollection == null )
			{
				break;
			}
			colIndex++;
		}
	}
}

function stdDhtmlHideShowInitHandler(funcAttachHandler)
{
	if( window.attachEvent != null )
	{
		window.attachEvent("onload", funcAttachHandler);
	}
	else
	{
		window.addEventListener("load", funcAttachHandler, false);
	}
}

function stdDhtmlAttachHandler(oElem, eventName, funcAttachHandler)
{
	if( oElem == null )
	{
		return false;
	}
	if( oElem.attachEvent != null )
	{
		return oElem.attachEvent("on" + eventName, funcAttachHandler);
	}
	else
	{
		return oElem.addEventListener(eventName, funcAttachHandler, false); /* HERE */
	}
}

//////////////////////////////////////////////////////////////////////////////////////////
//
// Javascript support for std_grid weblet
//
//////////////////////////////////////////////////////////////////////////////////////////
function stdGridInitCell(fieldName, row_pos, oFuncBlur, oFuncFocus, formname, bIsReadonly)
{
	var oElem = stdGetRealElement(document, fieldName, formname);
	if( oElem != null )
	{
		oElem.style.backgroundColor = "transparent";
		oElem.style.borderStyle = "none";
		var src_doc = null;
		if( formname != null && formname.length > 0 )
		{
			src_doc = document.forms[formname];
		}
		if( src_doc == null )
		{
			 src_doc = document;
		}
		if( !bIsReadonly )
		{
			stdDhtmlHideShowInitHandler(function(){stdDhtmlHideShowAttachHandler(src_doc, fieldName, "blur", oFuncBlur, false)});
			stdDhtmlHideShowInitHandler(function(){stdDhtmlHideShowAttachHandler(src_doc, fieldName, "focus", oFuncFocus, false)});
		}
	}
}

function stdGetRealElement(oDoc, fieldName, formname)
{
	if( fieldName == null || fieldName.length <= 0 )
	{
		return null;
	}
	if( fieldName.length < 8 || fieldName.substr(0, 2) != "__" || fieldName.substr(fieldName.length-6, 6) != "_PROXY" )
	{
		var oFld = stdGetElement(oDoc, "__" + fieldName + "_PROXY", formname);
		if( oFld != null )
		{
			return oFld;
		}
	}
	return stdGetElement(oDoc, fieldName, formname);
}

function stdGetElement(oDoc, fieldName, formname)
{
	var oElem = null;
	if( formname != null && formname != "" )
	{
		 var oForm = oDoc.forms[formname];
		if( oForm != null )
		{
			oElem = oForm.elements[fieldName];
		}
		else
		{
			oElem = stdGetFromDocumentByNameOrId(oDoc, fieldName);
		}
	}
	else
	{
		oElem = stdGetFromDocumentByNameOrId(oDoc, fieldName);
	}
	return oElem;
}

function stdGridSizeTables(head_div_name, head_tbl_name, body_div_name, body_tbl_name, head_col_div_name, head_col_div_div_name, head_col_tbl_name, objName, bCorrectWidth, bDontAdjustBody)
{
	var oContainerObj = stdGetFromDocumentByNameOrId(document, objName);
	var oHeadDiv = stdGetFromDocumentByNameOrId(document, head_div_name);
	var oHead = stdGetFromDocumentByNameOrId(document, head_tbl_name);
	var oBodyDiv = stdGetFromDocumentByNameOrId(document, body_div_name);
	var oBody = stdGetFromDocumentByNameOrId(document, body_tbl_name);
	var oHeadColDiv = stdGetFromDocumentByNameOrId(document, head_col_div_name);
	var oHeadColDivDiv = stdGetFromDocumentByNameOrId(document, head_col_div_div_name);
	var oHeadCol = stdGetFromDocumentByNameOrId(document, head_col_tbl_name);
	var outerBorderWidth = 0;
	if( oContainerObj != null )
	{
		outerBorderWidth = oContainerObj.offsetWidth - oContainerObj.clientWidth;
	}
	var bAdjustBody = (bDontAdjustBody==null||!bDontAdjustBody);
	if( oBodyDiv != null )
	{
		if( oHeadDiv != null )
		{
			if( bAdjustBody && oBodyDiv.style.pixelHeight > 0 )
			{
				oBodyDiv.style.pixelHeight -= oHeadDiv.offsetHeight;
			}
		}
		if( bAdjustBody && oBodyDiv.style.pixelWidth > 0 )
		{
			if( oHeadColDivDiv != null )
			{
				oBodyDiv.style.pixelWidth -= oHeadColDivDiv.offsetWidth;
			}
			if( oContainerObj != null )
			{
				oBodyDiv.style.pixelWidth -= outerBorderWidth;
			}
		}
		if( oHeadColDivDiv != null )
		{
			 oHeadColDivDiv.style.pixelHeight = oBodyDiv.clientHeight;
		}
	}
	if( oHead != null && oBody != null )
	{
		var length = oHead.rows[0].cells.length;
		if( oBody.rows.length > 0 )
		{
			for(var index = 0; index < length; index++)
			{
				var oHeadCell = oHead.rows[0].cells[index];
				var oBodyCell = oBody.rows[0].cells[index];
				var headWidth = oHeadCell.offsetWidth;
				var headBorder = headWidth - oHeadCell.clientWidth;
				var bodyWidth = oBodyCell.offsetWidth;
				var bodyBorder = bodyWidth - oBodyCell.clientWidth;
				var diff = headWidth - bodyWidth;
				oHeadCell.style.paddingLeft = "0px";
				oHeadCell.style.paddingRight = "0px";
				if( diff > 0 )
				{
					var newWidth = headWidth;
					if( oHeadColDivDiv != null )
					{
						newWidth -= ((headBorder - bodyBorder)+1)/2;
					}
					oBodyCell.style.pixelWidth = newWidth;
				}
				else if( diff < 0 )
				{
					var newWidth = bodyWidth;
					if( oHeadColDivDiv != null )
					{
						newWidth += ((headBorder - bodyBorder)+1)/2;
					}
					oHeadCell.style.pixelWidth = bodyWidth;
				}
			}
		}
		else
		{
			oHead.style.pixelWidth = oContainerObj.scrollWidth;
		}
	}
	if( oBodyDiv != null )
	{
		if( bCorrectWidth != null && bCorrectWidth && oContainerObj != null && oBodyDiv.scrollWidth > 0 && oBodyDiv.scrollWidth < oContainerObj.scrollWidth && oBodyDiv.clientWidth > 0 )
		{
			oBodyDiv.style.pixelWidth = oBody.offsetWidth + (oBodyDiv.offsetWidth - oBodyDiv.clientWidth);
		}
		if( oHeadDiv != null )
		{
			oHeadDiv.style.pixelWidth = oBodyDiv.scrollWidth;
		}
	}
	if( oHeadCol != null && oBody != null )
	{
		var length = oHeadCol.rows.length;
		for(var index = 0; index < length; index++)
		{
			var oHeadCell = oHeadCol.rows[index];
			var oBodyCell = oBody.rows[index];
			var headHeight = oHeadCell.offsetHeight;
			var headBorder = headHeight - oHeadCell.clientHeight;
			var bodyHeight = oBodyCell.offsetHeight;
			var bodyBorder = bodyHeight - oBodyCell.clientHeight;
			var diff = headHeight - bodyHeight;
			if( diff > 0 )
			{
				var newHeight = headHeight;
				if( oBodyDiv != null && oBodyDiv.scrollWidth - oBodyDiv.offsetWidth > 0 )
				{
					newHeight -= ((headBorder - bodyBorder))/2;
				}
				oBodyCell.style.pixelHeight = newHeight;
			}
			else if( diff < 0 )
			{
				oHeadCell.style.paddingTop = "0px";
				oHeadCell.style.paddingBottom = "0px";
				oHeadCell.style.pixelHeight = bodyHeight - headBorder;
			}
		}
	}
	if( oHeadColDiv != null && oBodyDiv != null )
	{
		oHeadColDiv.style.pixelHeight = oBodyDiv.scrollHeight;
	}
	if( bCorrectWidth != null && bCorrectWidth && oHeadColDivDiv != null && oBodyDiv != null )
	{
		oHeadColDivDiv.style.pixelHeight = oBodyDiv.clientHeight;
	}
}

function stdGridCursorInResizeZone(e, cell)
{
	var mouseX = getRelativeMouseX(cell, e);
	if (cell.offsetWidth - mouseX <= 5) return 1;
	if (cell.cellIndex > 0 && mouseX <= 4) return -1;
	return 0;
}
function stdGridOnHeaderMouseDown(e, oHeadCell, head_tbl_name, body_tbl_name)
{
	if(!e) { if( window.event ) { e = window.event; } else { return; } }
	var oHeadTable = stdGetFromDocumentByNameOrId(document, head_tbl_name);
	var oBodyTable = stdGetFromDocumentByNameOrId(document, body_tbl_name);
	if( oHeadTable != null ) oHeadTable.removeAttribute("__is_in_resize");
	
	var btn = -1;
	if( typeof( e.which ) == 'number' ) { btn = e.which; } else { if( typeof( e.button ) == 'number' ) { btn = e.button; } else { btn = 1; } }
	if( btn == 1 )
	{
		var rsz = stdGridCursorInResizeZone(e, oHeadCell);
		if( rsz < 0 )
		{
			var oHeadLeftCell = oHeadCell.parentNode.cells[oHeadCell.cellIndex-1];
			if( oHeadLeftCell != null )
			{
				stdGridStartColResize(oHeadTable, oBodyTable, oHeadLeftCell);
				e.returnValue = false;
				if (e.preventDefault) e.preventDefault();
			}
		}
		else if( rsz > 0 )
		{
			stdGridStartColResize(oHeadTable, oBodyTable, oHeadCell);
			e.returnValue = false;
			if (e.preventDefault) e.preventDefault();
		}
	}
}
function stdGridStartColResize(oHeadTable, oBodyTable, oHeadCell)
{
	oHeadCell.setCapture();
	oHeadCell.setAttribute("__headTable", oHeadTable.id);
	oHeadCell.setAttribute("__bodyTable", oBodyTable.id);
	if( oHeadTable != null ) oHeadTable.setAttribute("__is_in_resize", true);
	var rsDiv = document.getElementById('StdGridColResize');
	if (rsDiv) document.body.removeChild(rsDiv);
	rsDiv = document.createElement('div');
	rsDiv.id = "StdGridColResize";
	rsDiv.className = "std_grid_col_resize";
	var s = rsDiv.style;
	var top = getAbsoluteTop(oHeadCell);
	var bottom = getAbsoluteTop(oBodyTable) + oBodyTable.offsetHeight;
	s.position = "absolute";
	s.left = getAbsoluteLeft(oHeadCell) + "px";
	s.top = top + "px";
	s.width = oHeadCell.offsetWidth + "px";
	s.height = (bottom - top) + "px";
	document.body.appendChild(rsDiv);
}
function stdGridOnHeaderMouseUp(e, oHeadCell, funcSizeTables)
{
	var oHeadTable = document.getElementById(oHeadCell.getAttribute("__headTable"));
	if (oHeadTable && (oHeadTable.getAttribute("__is_in_resize")!=null))
	{
		var newWidth = getRelativeMouseX(oHeadCell, e) + "px";
		oHeadCell.style.width = newWidth;

		var oTblBody = document.getElementById(oHeadCell.getAttribute("__bodyTable"));
		if( oTblBody != null )
		{
			var rows = oTblBody.rows;
			if( rows.length > 0 )
			{
				stdGridResizeCellContent(oTblBody, oHeadCell.cellIndex, oHeadCell.clientWidth + "px");
				rows[0].cells[oHeadCell.cellIndex].style.width = newWidth;

				if( funcSizeTables != null )
				{
					var oldW = rows[0].cells[oHeadCell.cellIndex].offsetWidth;
					funcSizeTables(null, true);
					var newW = rows[0].cells[oHeadCell.cellIndex].offsetWidth;
					if (oldW != newW)
					{
						stdGridResizeCellContent(oTblBody, oHeadCell.cellIndex, rows[0].cells[oHeadCell.cellIndex].clientWidth + "px");
					}
				}
			}
		}
		oHeadTable.removeAttribute("__is_in_resize");
	}
	oHeadCell.releaseCapture();
	var rsDiv = document.getElementById('StdGridColResize');
	if (rsDiv) document.body.removeChild(rsDiv);

	if (oHeadCell.getAttribute("__prevCursor") != null )
	{
		oHeadCell.style.cursor = oHeadCell.getAttribute("__prevCursor");
		oHeadCell.removeAttribute("__prevCursor")
	}
}
function stdGridResizeCellContent(tBody, col, newSize)
{
	var c;
	for (var i=0, r; r=tBody.rows[i]; i++)
	{
		c = r.cells[col];
		var child = null;
		var childCount = 0;
		for (var j=0, cn; cn=c.childNodes[j]; j++)
		{
			if ((cn.nodeType != 8) && (cn.nodeName != "SCRIPT"))
			{
				child = cn;
				childCount++;
			}
		}
		if (childCount == 1)
		{
			child.style.overflow = "hidden";
			child.style.width = newSize;
		}
	}
}
function stdGridOnHeaderMouseMove(e, oHeadCell)
{
	var oHeadTable = document.getElementById(oHeadCell.getAttribute("__headTable"));
	if (oHeadTable && (oHeadTable.getAttribute("__is_in_resize")!=null))
	{
		var rsDiv = document.getElementById('StdGridColResize');
		if (rsDiv)
		{
				var w = getRelativeMouseX(rsDiv, e);
				if (w > 0) rsDiv.style.width = w + "px";
		}
		e.returnValue = false;
		if (e.preventDefault) e.preventDefault();  
	}
	else
	{
		var rsz = stdGridCursorInResizeZone(e, oHeadCell);
		if (rsz != 0)
		{
			if( oHeadCell.getAttribute("__prevCursor") == null )
			{
				oHeadCell.setAttribute("__prevCursor", oHeadCell.style.cursor);
			}
			oHeadCell.style.cursor = "e-resize";
		}
		else
		{
			if( oHeadCell.getAttribute("__prevCursor") != null )
			{
				oHeadCell.style.cursor = oHeadCell.getAttribute("__prevCursor");
			}
		}
	}
}
function stdGridOnScroll(oBodyDiv, head_div_name, head_col_div_name)
{
	var scrollLeft = oBodyDiv.scrollLeft;
	var scrollTop = oBodyDiv.scrollTop;
	var oHeadDiv = stdGetFromDocumentByNameOrId(document, head_div_name);
	var oHeadColDiv = stdGetFromDocumentByNameOrId(document, head_col_div_name);
	if( oHeadDiv != null )
	{
		if( scrollLeft > 0 )
		{
			oHeadDiv.style.pixelLeft = -scrollLeft;
		}
		else
		{
			oHeadDiv.style.pixelLeft = 0;
		}
	}
	if( oHeadColDiv != null )
	{
		if( scrollTop > 0 )
		{
			oHeadColDiv.style.pixelTop = -scrollTop;
		}
		else
		{
			oHeadColDiv.style.pixelTop = 0;
		}
	}
}

function stdGridSortColumn(oCell, arr, sortBoxName, tbl_body_name, funcSortAsc, funcSortDesc, sort_fixed_rows_with_body, head_col_tbl_name, even_row_class, odd_row_class)
{
	var box = stdGetDescendantByNameOrId(oCell, sortBoxName);
	if( box != null )
	{
		var tbody = stdGetFromDocumentByNameOrId(document, tbl_body_name);
		var rows = tbody.rows;
		var innerText = box.innerText;
		if( innerText == "6" )
		{
			box.innerText = "5";
			arr.sort(funcSortAsc);
		}
		else if( innerText == "5" )
		{
			box.innerText = "6";
			arr.sort(funcSortDesc);
		}
		if( sort_fixed_rows_with_body )
		{
			var oColHeadTbl = stdGetFromDocumentByNameOrId(document, head_col_tbl_name);
			if( oColHeadTbl != null )
			{
				var thead = oColHeadTbl.tHead;
				var headRows = null;
				if( thead != null )
				{
					headRows = thead.rows;
					var length = headRows.length;
					var rowArr = new Array();
					for(var index = 0; index < length; index++)
					{
						rowArr.push(headRows[arr[index].itemRowIndex]);
					}
					for(var index = 0; index < length; index++)
					{
						thead.moveRow(rowArr[index].sectionRowIndex, index);
					}
				}
			}
		}
		var length = rows.length;
		var rowArr = new Array();
		for(var index = 0; index < length; index++)
		{
			rowArr.push(rows[arr[index].itemRowIndex]);
		}
		var prevWidthArr = null;
		if( length > 0 )
		{
			prevWidthArr = new Array();
			var cells = rows[0].cells;
			var cellLength = cells.length;
			for(var cellIndex = 0; cellIndex < cellLength; cellIndex++)
			{
				var cell = cells[cellIndex];
				prevWidthArr.push(cell.style.width);
				cell.style.width = "";
			}
		}
		for(var index = 0; index < length; index++)
		{
			tbody.moveRow(rowArr[index].sectionRowIndex, index);
			arr[index].itemRowIndex = index;
		}
		if( prevWidthArr != null )
		{
			var cellLength = prevWidthArr.length;
			for(var cellIndex = 0; cellIndex < cellLength; cellIndex++)
			{
				var cells = rows[0].cells;
				var cell = cells[cellIndex];
				cell.style.width = prevWidthArr[cellIndex];
			}
		}
		for(var index = 0; index < length; index++)
		{
			if( ((index+1)%2) == 0 )
			{
				rows[index].className = even_row_class;
			}
			else
			{
				rows[index].className = odd_row_class;
			}
		}
		var col = stdGetFromDocumentByNameOrId(document, sortBoxName);
		length = col.length;
		for(var index = 0; index < length; index++)
		{
			col.item(index).style.visibility = "hidden";
			box.style.visibility = "";
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////
//
// Javascript support for std_largelist weblet
//
//////////////////////////////////////////////////////////////////////////////////////////

// Set linked and inline CSS stylesheets same as parent window
function stdInheritStyles(oWindow)
{
	var oParentWindow = oWindow.parent;
	if (oParentWindow == oWindow) return; // Not iframe

	var links = oParentWindow.document.styleSheets;

	for (var i = 0; i < links.length; i++)
	{
		var href = links.item(i).href;
		if ((href != null) && (href != "")) oWindow.document.writeln("<link href=\"" + href + "\" type=\"text/css\" rel=\"stylesheet\" />");
	}
	var styles = oParentWindow.document.getElementsByTagName("style");

	for (var i = 0; i < styles.length; i++) oWindow.document.writeln("<style type=\"text/css\">" + styles[i].innerHTML + "</style>");
}

function stdGetWindowHeight(oWindow)
{
	if (oWindow.document.height)
	{
		return oWindow.document.height;
	}
	else
	{
		var scrollh = oWindow.document.body.scrollHeight ? oWindow.document.body.scrollHeight : 0;
		var offseth = oWindow.document.body.offsetHeight ? oWindow.document.body.offsetHeight : 0;
		return scrollh > offseth ? scrollh : offseth;
	}
}

function stdGetWindowWidth(oWindow)
{
	if (oWindow.document.width)
	{
		return oWindow.document.width;
	}
	else
	{
		var scrollw = oWindow.document.body.scrollWidth ? oWindow.document.body.scrollWidth : 0;
		var offsetw = oWindow.document.body.offsetWidth ? oWindow.document.body.offsetWidth : 0;
		return scrollw > offsetw ? scrollw : offsetw;
	}
}

function stdAutoSizeIFrame(oIFrameWindow, iframeId, width, height)
{
	var pad = 10;
	var iframe = oIFrameWindow.parent.document.getElementById(iframeId);
	iframe.style.width = (width == "auto") ? ((stdGetWindowWidth(oIFrameWindow) + pad) + "px") : width;
	iframe.style.height = (height == "auto") ? ((stdGetWindowHeight(oIFrameWindow) + pad) + "px") : height;
}

// Needs castlebusybox.js
function stdStartBusyBox(busyBoxFrame, busyBoxVar, imagesPath, msg)
{
	var busyBox = null;
	var procMsg = g_StdLocaleMgr.getMessageText("Processing1");
	if (imagesPath == null) imagesPath = "/images";

	try
	{
		busyBox = new BusyBox(busyBoxFrame, busyBoxVar, 4, imagesPath + "/gears_ani_", ".gif", 125, 147, 207, null, msg);
	}
	catch (e) {}
	if (busyBox) busyBox.Show();
	window.status = procMsg;
	return busyBox;
}

// Needs castlebusybox.js
function stdStopBusyBox(busyBox)
{
	if ((busyBox != null) && busyBox.Hide) busyBox.Hide(); // castlebusybox.js must be included by caller XHTML
	window.status = g_StdLocaleMgr.getMessageText("Done1");
}

function stdIFrameOnLoad(oIFrameWindow, iframeId, width, height, busyBox)
{
	stdAutoSizeIFrame(oIFrameWindow, iframeId, width, height);
	var iFrame = document.getElementById(iframeId);
	stdStopBusyBox(busyBox);
}
