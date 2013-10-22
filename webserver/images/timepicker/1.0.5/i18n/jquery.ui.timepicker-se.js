/* Swedish initialization for the jQuery UI timepicker plugin. */
jQuery(function($){
	$.timepicker.regional['se'] = {
		currentText: 'Nu',
		closeText: 'Stäng',
		ampm: false,
		timeFormat: 'hh:mm',
		timeOnlyTitle: 'Välj tid',
		timeText: 'Tid',
		hourText: 'Timme',
		minuteText: 'Minut',
		secondText: 'Sekund'
	};
	$.timepicker.setDefaults($.timepicker.regional['se']);
});