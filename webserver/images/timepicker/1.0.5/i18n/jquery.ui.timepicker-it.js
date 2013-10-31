/* Italian initialization for the jQuery UI timepicker plugin. */
jQuery(function($){
	$.timepicker.regional['it'] = {
		currentText: 'Ora',
		closeText: 'Fatto',
		ampm: falso,
		timeFormat: 'hh:mm:ss tt',
		timeOnlyTitle: 'Scegliere Time',
		timeText: 'Time',
		hourText: 'Ora',
		minuteText: 'Minuti',
		secondText: 'Secondi'
	};
	$.timepicker.setDefaults($.timepicker.regional['it']);
});