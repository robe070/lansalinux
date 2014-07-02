﻿/* English initialization for the jQuery UI timepicker plugin. */
(function($) {
	$.timepicker.regional['en'] = {
		timeOnlyTitle: 'Choose Time',
		timeText: 'Time',
		hourText: 'Hour',
		minuteText: 'Minute',
		secondText: 'Second',
		millisecText: 'Millisecond',
		microsecText: 'Microsecond',
		timezoneText: 'Time Zone',
		currentText: 'Now',
		closeText: 'Done',
		timeFormat: 'hh:mm tt',
		amNames: ['AM', 'A'],
		pmNames: ['PM', 'P'],
		isRTL: false
	};
	$.timepicker.setDefaults($.timepicker.regional['en']);
})(jQuery);