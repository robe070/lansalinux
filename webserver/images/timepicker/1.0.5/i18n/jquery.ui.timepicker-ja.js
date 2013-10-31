/* Japanese initialisation for the jQuery UI timepicker plugin. */
jQuery(function($){
	$.timepicker.regional['ja'] = {
		currentText: '現在時刻',
		closeText: '閉じる',
		ampm: false,
		timeFormat: 'hh:mm:ss',
		timeOnlyTitle: '時刻の指定',
		timeText: '時刻',
		hourText: '時',
		minuteText: '分',
		secondText: '秒'
	};
	$.timepicker.setDefaults($.timepicker.regional['ja']);
});