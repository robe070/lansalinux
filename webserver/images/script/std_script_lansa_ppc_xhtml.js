﻿/*!
	(c) 2002, 2012 LANSA
	PPC XHTML Standard Scripts
	$Workfile:: std_script_lansa_ppc_xhtml.js   $
	$UTCDate:: 2012-09-04 06:30:25Z             $
	$Revision:: 15                              $
*/

// Global Multilingual Message Text Manager.
var g_StdLocaleMgr = null;

function stdGetMTextMessageText(messageId)
{
	return g_StdLocaleMgr.getMessageText.apply(g_StdLocaleMgr,arguments);
}
function stdGetMTextMessageTextArr(messageId)
{
	return g_StdLocaleMgr.getMessageTextArr(messageId);
}

// Sets up the function to call based on the language to retrieve multilingual messages.
function StdLocaleMgr(languageId, isDBCS)
{
	this.m_langId = languageId;
	this.m_isDBCS = isDBCS != null ? isDBCS : false;
	this.getMessageText = function (messageId)
	{
		var strings = Lstd.L10N.strings[Lstd.L10N.lang];
		var theMsg = (strings) ? (strings[messageId] || "") : "";
		for (var i=1; i < arguments.length; i++)
		{
			theMsg = theMsg.replace("%" + i.toString(), arguments[i].toString());
		}
		return theMsg;
	}
	this.getMessageTextArr = function(messageId) {
		var arrays = Lstd.L10N.arrays[Lstd.L10N.lang];
		return (arrays) ? (arrays[messageId] || null) : null;
	}

	g_StdLocaleMgr = this;
}
// Deprecated
function StdMessageMgr(languageId)
{
	new StdLocaleMgr(languageId, false);
}

// Convert the value property of input elements to upper or lower case as required.
// Deprecated: Use toValueCase() called from isValidText()
function SetValueCase(oInput, propertyName, className)
{
	if( oInput == null )
	{
	 return;
	}
	if( propertyName == "value" )
	{
	 var textTransform = null;
	 var curStyle = null;//oInput.currentStyle;
	 if( curStyle != null )
	 {
		 textTransform = curStyle.textTransform;
	  }
	  else if( className != null )
	  {
			if( className == "utext" )
			{
				textTransform = "uppercase";
			}
			else if( className == "ltext" )
			{
			}
	  }
	 if( textTransform != null && textTransform == "uppercase" )
	 {
		var value = oInput.value;
		var valueUpper = value.toUpperCase();
		if( value != valueUpper )
		{
		  oInput.value = valueUpper;
		}
	 }
	 else if( textTransform != null && textTransform == "lowercase" )
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
	var action="";
	if( optProtocol != null && optProtocol.length > 0 )
	{
		action += optProtocol;
		if( optProtocol.search(new RegExp("//", "g")) < 0 )
		{
			action += "//" + optForm.ownerDocument.location.host;
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
	var prevTarget;
	if( optTarget != null )
	{
		prevTarget = optForm.target;
		optForm.target = optTarget;
	}
	optForm.submit();
	if( optTarget != null )
	{
		optForm.target = prevTarget;
	}
	optForm.action = prevAction;
}

function _HandleServiceEvent(ServiceName, techServ, actionRequest, partition, language, optForm, optTarget, optProtocol, optSessionKey, optDebugMode)
{
	var Form = optForm != null ? optForm : document.LANSA;
	var prevAction = Form.action;

	var action = "";
	if( optProtocol != null && optProtocol.length > 0 )
	{
		action += optProtocol;
		if( optProtocol.search(new RegExp("//", "g")) < 0 )
		{
			action += "//" + Form.ownerDocument.location.host;
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
	if (optTarget != null)
	{
		var prevTarget = Form.target;
		Form.target = optTarget;
		Form.submit();
		Form.target = prevTarget;
	}
	else
	{
		Form.submit();
	}

	Form.action = prevAction;
}

function _HandleEventTarget(Form, Target, techServ, actionRequest, partition, language, WebApp, WebRoutine, optProtocol, optSessionKey, optDebugMode)
{
	if( Form == null )
	{
	 Form = document.LANSA;
	}

	var prevTarget = Form.target;
	Form.target = Target;
	var prevAction = Form.action;
	var action="";
	if( optProtocol != null && optProtocol.length > 0 )
	{
		action += optProtocol;
		if( optProtocol.search(new RegExp("//", "g")) < 0 )
		{
			action += "//" + Form.ownerDocument.location.host;
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

function StdDfltButtonMgr()
{
	this.register = function(oForm, btnName, oHandler) {
		eval("this.form_" + oForm.name + " = oHandler");
		eval("this.form_" + oForm.name + "_defBtn = btnName");
	};
	this.getDefaultButton = function(oForm) {
		if (oForm == null) return null;
		var btnName = null;
		eval("btnName = this.form_" + oForm.name + "_defBtn");
		return stdGetElementById(btnName, oForm);
	}
}
var gStdDfltButtonMgr = new StdDfltButtonMgr();

function stdRegisterDfltButton(oHandler)
{
	gDfltButtonArr.push(oHandler);
}

function _HandleDefaultSubmit(oForm)
{
	if( oForm == null ) return false;
	eval("var oHandler = gStdDfltButtonMgr.form_" + oForm.name);
	if( oHandler == null ) return false;
	return oHandler.apply(oForm, new Array(oForm));
}
function IsIE()
{
	return (navigator.userAgent.indexOf("MSIE")>-1);
}

function InsertHidden(Form, FieldName, FieldValue)
{
	if( Form == null ) return;
	
	var field = null;
	for (var i=0; i<Form.elements.length; i++)
	{
		if (Form.elements[i].name == FieldName)
		{
			field = Form.elements[i];
			break;
		}
	}
	if (field == null)
	{
		var bIsIE = IsIE();
		var html;
		if( bIsIE )
		{
			html = "<input type=\"hidden\" name=\"" + FieldName + "\" value=\"" + FieldValue + "\" />";
		}
		else
		{
			html = "input";
		}
		var elem;
		if( !bIsIE )
		{
			elem = Form.ownerDocument.createElement(html);
		}
		else
		{
			if (document.createElement && Form.appendChild) elem = document.createElement(html);
			else alert(stdGetMTextMessageText("BadHidFld", FieldName));
		}

		if( elem != null )
		{
			if( !bIsIE )
			{
				elem.setAttribute("type", "hidden");
				elem.setAttribute("name", FieldName);
				elem.setAttribute("value", FieldValue);
			}
			Form.appendChild(elem);
		}
	}
	else
	{
		field.value = FieldValue;
	}
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
			Form.elements[name].checked = true;
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
				elem.checked = false;
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

function _isValidNumber(theObj, length, decimals, decimalPoint)
{
	var integers = length - decimals;
	if( theObj != null )
	{
		var valueStr = theObj.value;
		if( valueStr.length <= 0 ) return true;
		var re = new RegExp("^[+-]?\d{0," + integers + "}(\.\d{0," + decimals + "})?$");
		return showMessageOnFalse(theObj, stdGetMTextMessageText("BadNum", integers, decimals), re.test(valueStr));
	}
	return showMessageOnFalse(theObj, stdGetMTextMessageText("BadNum", integers, decimals), false);
}

function isDigit(theDigit)
{
	digitArray = new Array('0', '1', '2', '3', '4', '5', '6', '7', '8', '9')
	for (var j = 0; j < digitArray.length; j++)
		if (theDigit == digitArray[j])
			return true;
	return false;
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
			if  (valueStr.charAt(0) == "-")
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
function toValueCase(theObj)
{
	var value = theObj.value;
	var textTransform = theObj.currentStyle.textTransform;
	if (textTransform == "uppercase") value = value.toUpperCase();
	else if (textTransform == "lowercase") value = value.toLowerCase();
	if (theObj.value != value)
	{
		theObj.value = value;
		if (theObj.id != "") setTimeout("stdSetElementValue('" + theObj.id + "', '" + value + "')", 1); // Workaround IE bug
	}
}

function stdSetElementValue(id, value)
{
	var elem = stdGetElementById(id);
	if (elem != null) elem.value = value;
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
		theObj.value = returnString;
		theObj.focus();
		theObj.select();
		return false;
	}

	if ((KeybdShift == 'J') && (totalSBCS > 0))
	{
		alert(g_StdLocaleMgr.getMessageText("BadDBCS_SBCSNotAllowed", totalSBCS));
		theObj.value = returnString;
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
		theObj.value = returnString;
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
					if( elem.disabled != true /*&& elem.readOnly != true && (elem.tabIndex == null || elem.tabIndex >= 0)*/ )
					{
						// If focus is already set on an element and this elements tabIndex <= the current focus element's tabIndex
						// then set the focus, so that it is in correct tab order.
						if( elemToFocus == null /*|| (elem.tabIndex == null || (elemToFocus.tabIndex != null && elemToFocus.tabIndex > elem.tabIndex))*/ )
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

function trapError(errorMsg, url, line)
{
	return true;
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
function stdGetElementById(id, doc)
{
	if (!doc) doc = document;
	if (doc.getElementById) return doc.getElementById(id);
	if (doc.all) return doc.all[id];
	var children = doc.children;
	var ret = null;
	for (var i=0,c; c=children[i]; i++)
	{
		if (c.id == id) return c;
		ret = stdGetElementById(id, c);
		if (ret) return ret;
	}
	return null;
}
function stdGetFromDocumentByNameOrId(oDoc, objNameOrId)
{
	if( oDoc == null )
	{
		oDoc = window;
	}
	var oWnd = oDoc;
	if( oWnd.parentWindow != null )
	{
		oWnd = oWnd.parentWindow;
	}
	eval("var obj = oWnd." + objNameOrId);
	return obj;
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
	if (objId == null) return "";
	var text = "";
	var sp = stdGetElementById(objId, oParent);
	if (sp) text = sp.innerHTML;
	// Strip <!----> appended to avoid self-closing
	var re = new RegExp("(<!---->)$");
	return text.replace(re, "");
}

//////////////////////////////////////////////////////////////////////////////////////////
//
// Javascript support for std_tab_pages weblet
//
//////////////////////////////////////////////////////////////////////////////////////////

function StdTabPagesTab(bIsDisabled)
{
	this.m_isDisabled = bIsDisabled;
}

function StdTabPagesTabHolderFuncGetTab(tabIndex)
{
	return this.m_tabArr[tabIndex];
}

function StdTabPagesTabHolder(activeTabIndex, tabTotal)
{
	this.m_activeTabIndex = activeTabIndex;
	this.m_tabArr = new Array(tabTotal);
	for(var index = 0; index < tabTotal; index++)
	{
		this.m_tabArr[index] = new StdTabPagesTab(false);
	}
	this.getTab = StdTabPagesTabHolderFuncGetTab;
}

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
	var isDisabled = oTabHolder.getTab(tabIndex-1).m_isDisabled;
	if( isDisabled != null && isDisabled )
	{
		return;
	}
	isDisabled = oTab.disabled;
	if( isDisabled != null && isDisabled )
	{
		return;
	}
	if( tabImageName != null )
	{
		var oTabImage = null;//stdGetDescendantByNameOrId(oTab, tabImageName);
		if( oTabImage != null )
		{
			oTabImage.src = tabImagePath;
		}
	}
	var curIndex = oTabHolder.m_activeTabIndex;
	var oActiveTab = stdGetFromDocumentByNameOrId(window, tabNameBase + curIndex);
	if( oActiveTab != null )
	{
		if( tabImageName != null )
		{
			var oActiveTabImage = null;//stdGetDescendantByNameOrId(oActiveTab, tabImageName);
			if( oActiveTabImage != null )
			{
				oActiveTabImage.src = oActiveTabImage.getAttribute("_unsel_src");
			}
		}
		oActiveTab.className = unselTabClassName;
	}
	oTab.className = selTabClassName;
	oTabHolder.m_activeTabIndex = tabIndex;
	var oActiveFrame = stdGetFromDocumentByNameOrId(window, viewBaseName + curIndex);
	if( oActiveFrame != null )
	{
		oActiveFrame.style.display = "none";
	}
	oActiveFrame = stdGetFromDocumentByNameOrId(window, viewBaseName + tabIndex);
	oActiveFrame.style.display = "";
	oActiveFrame.style.width = "100%";
	oActiveFrame.style.height = "100%";
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
				targetElement = stdGetElementById(nameOrId, oDocOrForm);
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
			return oElem.addEventListener(eventName, funcAttachHandler, false);
	}
}

//////////////////////////////////////////////////////////////////////////////////////////
//
// Javascript support for std_select_list weblet
//
//////////////////////////////////////////////////////////////////////////////////////////

function stdSelectTagMgrAddTag(oTagName1, oTagValue1, oTagName2, oTagValue2, oTagName3, oTagValue3)
{
	this.tagArr.push(new StdSelectTagHolder(oTagName1, oTagValue1, oTagName2, oTagValue2, oTagName3, oTagValue3));
}

function stdSelectTagMgrGetTag(index)
{
	return this.tagArr[index];
}

function StdSelectTagMgr()
{
	this.tagArr = new Array();
	this.addTag = stdSelectTagMgrAddTag;
	this.getTag = stdSelectTagMgrGetTag;
}

function StdSelectTagHolder(oTagName1, oTagValue1, oTagName2, oTagValue2, oTagName3, oTagValue3)
{
	if( oTagName1 != null && oTagName1.length > 0)
	{
		this.tagName1 = oTagName1;
		this.tagValue1 = oTagValue1;
	}
	if( oTagName2 != null && oTagName2.length > 0 )
	{
		this.tagName2 = oTagName2;
		this.tagValue2 = oTagValue2;
	}
	if( oTagName3 != null && oTagName3.length > 0 )
	{
		this.tagName3 = oTagName3;
		this.tagValue3 = oTagValue3;
	}
}
