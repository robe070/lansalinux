/* English initialization for the jQuery UI timepicker plugin. */
jQuery(function($){
	$.timepicker.regional['en'] = {
		currentText: 'Now',
		closeText: 'Done',
		ampm: false,
		timeFormat: 'hh:mm tt',
		timeOnlyTitle: 'Choose Time',
		timeText: 'Time',
		hourText: 'Hour',
		minuteText: 'Minute',
		secondText: 'Second'
	};
	$.timepicker.setDefaults($.timepicker.regional['en']);
});