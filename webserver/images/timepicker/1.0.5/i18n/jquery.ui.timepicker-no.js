/* Norwegian initialization for the jQuery UI timepicker plugin. */
jQuery(function($){
	$.timepicker.regional['no'] = {
		currentText: 'Straks',
		closeText: 'Lukk',
		ampm: false,
		timeFormat: 'hh:mm:ss',
		timeOnlyTitle: 'Velg tid',
		timeText: 'Tid',
		hourText: 'Time',
		minuteText: 'Minutt',
		secondText: 'Sekunder'
	};
	$.timepicker.setDefaults($.timepicker.regional['no']);
});