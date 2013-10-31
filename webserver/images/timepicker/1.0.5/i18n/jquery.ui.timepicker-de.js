/* German initialisation for the jQuery UI timepicker plugin. */
jQuery(function($){
	$.timepicker.regional['de'] = {
		currentText: 'Jetzt',
		closeText: 'Schließen',
		ampm: false,
		timeFormat: 'hh:mm',
		timeOnlyTitle: 'Zeit wählen',
		timeText: 'Stunde',
		hourText: 'Stunde',
		minuteText: 'Minute',
		secondText: 'Sekunde'
	};
	$.timepicker.setDefaults($.timepicker.regional['de']);
});