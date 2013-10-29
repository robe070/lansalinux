/*!
	(c) 2002, 2012 LANSA
	Standard Scripts messages (JPN)
	$Workfile:: std_script_messages-ja.js    $
	$UTCDate:: 2012-02-20 04:27:51Z          $
	$Revision:: 16                           $
*/

if (!window.Lstd) Lstd = {};
if (!Lstd.L10N) Lstd.L10N = { lang: "en" };
if (!Lstd.L10N.strings) Lstd.L10N.strings = {};
if (!Lstd.L10N.arrays) Lstd.L10N.arrays = {};

Lstd.L10N.strings.ja = {
	"PPCNoForm": "このﾌﾞﾗｳｻﾞは document.createElement をｻﾎﾟｰﾄしていません。呼び出しｵﾌﾞｼﾞｪｸﾄの formname ﾌﾟﾛﾊﾟﾃｨに指定されたﾌｫｰﾑが必要です。",
	"BadHidFld": "このﾌﾞﾗｳｻﾞは document.createElement をｻﾎﾟｰﾄしていません。 非表示ﾌｨｰﾙﾄﾞ %1% を事前に定義する必要があります。",
	"BadHidFld1": "document.createElement は実装されていません。",
	"BadHidFld2": "非表示ﾌｨｰﾙﾄﾞをﾌｫｰﾑに使用する必要があります",
	"BadNum": "無効な数。数は整数部分が %1% 以下、小数部分が %2% 以下の桁でなければなりません。",
	"BadNum1": "整数部で許される桁数 = ",
	"BadNum2": "\n小数部で許される桁数 = ",
	"BadNum3": "\nﾃﾞｰﾀの一部が切断されます。",
	"BadInt": "無効な整数です",
	"BadIntWithRange": "無効な整数です! %1% より小さな数、%2% より大きな数は無効です。",
	"BadInt1": " より小さな数は無効 ",
	"BadInt2": ", または大きな数 ",
	"BadFloat": "無効な小数値です。",
	"BadDate": "無効な日付の値です",
	"BadDate1": " 無効な日付です",
	"BlankDate": "日付にﾌﾞﾗﾝｸは認められていません。省略値として今日の日付にします。",
	"BlankDate2": "日付にﾌﾞﾗﾝｸは認められていません。",
	"BadTime": "無効な時刻の値です。",
	"BadTime1": "無効な時刻です。",
	"BlankTime": "時刻にﾌﾞﾗﾝｸは認められていません。省略値として現時刻にします。",
	"BlankTime2": "時刻にﾌﾞﾗﾝｸは認められていません!",
	"BadDateTime": "無効な日付・時間の値です。",
	"BadBool": "値が無効です\n値は\"true\" か \"false\"です。",
	"BadDBCS_TooLong": "変換後の長さが長すぎます： %1 長さが超えています : %2.",
	"BadDBCS_SBCSNotAllowed": "このﾌｨｰﾙﾄﾞはDBCS専用のﾌｨｰﾙﾄﾞです。 %1 SBCSが入力されました。",
	"BadDBCS_DBCSNotAllowed": "このﾌｨｰﾙﾄﾞはSBCS専用のﾌｨｰﾙﾄﾞです。 %1 DBCSが入力されました。",
	"BadDBCS_BothNotAllowed": "すべてDBCSまたは、すべてSBCSであるべきです。 のﾌｨｰﾙﾄﾞは許されています。 %1 SBCSが入力されました。 %2 DBCSが入力されました。",
	"BadDBCS": "変換後の長さが長すぎます：",
	"BadDBCS1": "このﾌｨｰﾙﾄﾞはDBCS専用のﾌｨｰﾙﾄﾞです。\n",
	"BadDBCS2": " SBCSが入力されました。\n",
	"BadDBCS3": "SBCSは削除されました。",
	"BadDBCS4": "すべてDBCSまたは、すべてSBCSであるべきです。",
	"BadDBCS5": " のﾌｨｰﾙﾄﾞは許されています。\n",
	"BadDBCS6": " SBCSが入力されました。\n",
	"BadDBCS7": " DBCSが入力されました。\n",
	"BadDBCS8": "ﾌｨｰﾙﾄﾞのﾃﾞｰﾀを変更してください。",
	"BadDBCS9": "このﾌｨｰﾙﾄﾞはSBCS専用のﾌｨｰﾙﾄﾞです。\n",
	"BadDBCS10": " DBCSが入力されました。\n",
	"BadDBCS11": "DBCSは削除されました。",
	"BadDBCS12": "\n長さが超えています : ",
	"BadDBCS13": "\nﾃﾞｰﾀの一部が切られます。",
	"BadLength1": "最大長を超えてしまいます。",
	"NoXMLHttpRequest": "このﾌﾞﾗｳｻﾞではXMLHttpRequestはｻﾎﾟｰﾄされていません。",
	"Processing1": "処理",
	"Done1": "実行",
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
	"DaysOfWeek": new Array("月", "火", "水", "木", "金", "土", "日"),
	"DaysOfWeekLong": ["Monday", "Tueday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"],
	"Months": new Array("１月", "２月", "３月", "４月", "５月", "６月", "７月", "８月", "９月", "１０月", "１１月", "１２月"),
	"MonthsShort": ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"]
}

