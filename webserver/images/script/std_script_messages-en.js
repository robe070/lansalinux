﻿/*!
	(c) 2002, 2012 LANSA
	Standard Scripts messages
	$Workfile:: std_script_messages-en.js   $
	$UTCDate:: 2012-02-20 04:27:51Z         $
	$Revision:: 15                          $
*/


if (!window.Lstd) Lstd = {};
if (!Lstd.L10N) Lstd.L10N = { lang: "en" };
if (!Lstd.L10N.strings) Lstd.L10N.strings = {};
if (!Lstd.L10N.arrays) Lstd.L10N.arrays = {};

Lstd.L10N.strings.en = {
	"PCNoForm": "This browser does not support document.createElement. You must have a FORM which must be specified in the calling objects formname property.",
	"BadHidFld": "This browser does not support document.createElement. You must predefine the hidden field %1%.",
	"BadHidFld1": "document.createElement is not implemented, ",
	"BadHidFld2": " hidden field must be available in the form.",
	"BadNum": "Invalid number.  The number must contain only digits (no more than %1% before the decimal point and no more than %2% after).",
	"BadNum1": "Allowable digits before decimal point = ",
	"BadNum2": "\nAllowable digits after decimal point = ",
	"BadNum3": "\nData will be truncated accordingly.",
	"BadInt": "Invalid integer number.",
	"BadIntWithRange": "Invalid integer number. Cannot be less than %1%, or greater than %2%.",
	"BadInt1": " Cannot be less than ",
	"BadInt2": ", or greater than ",
	"BadFloat": "Invalid floating point number!",
	"BadDate": "Invalid date!",
	"BadDate1": " is an invalid date!",
	"BlankDate": "Blank is an invalid date. Defaulting to today's date.",
	"BlankDate2": "Blank is an invalid date.",
	"BadTime": "Invalid time!",
	"BadTime1": " is an invalid time!",
	"BlankTime": "Blank is an invalid time! Defaulting to current time!",
	"BlankTime2": "Blank is an invalid time!",
	"BadDateTime": "Invalid datetime!",
	"BadBool": "Invalid value.\nValue must be \"true\" or \"false\"",
	"BadDBCS_TooLong": "Converted length of characters entered is %1 which exceeds the maximum allowable length of %2.",
	"BadDBCS_SBCSNotAllowed": "Only DBCS characters are allowed in this field. %1 SBCS characters have been entered.",
	"BadDBCS_DBCSNotAllowed": "Only SBCS characters are allowed in this field. %1 DBCS characters have been entered.",
	"BadDBCS_BothNotAllowed": "Either all DBCS characters or all SBCS characters are allowed in this field. %1 SBCS characters have been entered. %2 DBCS characters have been entered.",
	"BadDBCS": "Converted length of characters entered is ",
	"BadDBCS1": "Only DBCS characters are allowed in this field.\n",
	"BadDBCS2": " SBCS characters have been entered.\n",
	"BadDBCS3": "SBCS characters will be removed.",
	"BadDBCS4": "Either all DBCS characters or all SBCS characters ",
	"BadDBCS5": "are allowed in this field.\n",
	"BadDBCS6": " SBCS characters have been entered.\n",
	"BadDBCS7": " DBCS characters have been entered.\n",
	"BadDBCS8": "Please modify field data accordingly.",
	"BadDBCS9": "Only SBCS characters are allowed in this field.\n",
	"BadDBCS10": " DBCS characters have been entered.\n",
	"BadDBCS11": "DBCS characters will be removed.",
	"BadDBCS12": "\nwhich exceeds the maximum allowable length of ",
	"BadDBCS13": "\nData will be truncated accordingly.",
	"BadLength1": "Maximum characters reached.",
	"NoXMLHttpRequest": "XMLHttpRequest not supported by this browser.",
	"Processing1": "Processing",
	"Done1": "Done",
	"mobiscroll-cancelText": "Cancel",
	"mobiscroll-setText": "Set",
	"mobiscroll-dayText": "Day",
	"mobiscroll-monthText": "Month",
	"mobiscroll-yearText": "Year",
	"mobiscroll-hourText": "Hours",
	"mobiscroll-minuteText": "Minutes",
	"mobiscroll-secText": "Seconds"	
}

Lstd.L10N.arrays.en = {
	"DaysOfWeek": ["Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"],
	"DaysOfWeekLong": ["Monday", "Tueday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"],
	"Months": ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"],
	"MonthsShort": ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"]
}
