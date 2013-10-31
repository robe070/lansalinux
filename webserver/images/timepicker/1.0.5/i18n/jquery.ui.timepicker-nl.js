/* Dutch initialisation for the jQuery UI timepicker plugin. */
jQuery(function($){
	$.timepicker.regional['nl'] = {
		currentText: 'Nu',
		closeText: 'Sluiten',
		ampm: false,
		timeFormat: 'hh:mm:ss',
		timeOnlyTitle: 'Kies Tijd',
		timeText: 'Tijd',
		hourText: 'Uur',
		minuteText: 'Minuut',
		secondText: 'Seconde'
	};
	$.timepicker.setDefaults($.timepicker.regional['nl']);
});