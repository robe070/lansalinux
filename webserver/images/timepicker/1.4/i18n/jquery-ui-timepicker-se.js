/* Swedish initialization for the jQuery UI timepicker plugin. */
(function($) {
	$.timepicker.regional['se'] = {
		timeOnlyTitle: 'Välj tid',
		timeText: 'Tid',
		hourText: 'Timme',
		minuteText: 'Minut',
		secondText: 'Sekund',
		millisecText: 'Millisekund',
		microsecText: 'Mikrosekund',
		timezoneText: 'Tidszon',
		currentText: 'Nu',
		closeText: 'Stäng',
		timeFormat: 'HH:mm',
		amNames: ['AM', 'A'],
		pmNames: ['PM', 'P'],
		isRTL: false
	};
	$.timepicker.setDefaults($.timepicker.regional['se']);
})(jQuery);