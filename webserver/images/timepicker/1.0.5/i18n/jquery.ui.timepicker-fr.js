/* French initialisation for the jQuery UI timepicker plugin. */
jQuery(function($){
	$.timepicker.regional['fr'] = {
		currentText: 'Maintenant',
		closeText: 'Fermer',
		ampm: false,
		timeFormat: 'hh:mm',
		timeOnlyTitle: 'Choisissez l\'heure',
		timeText: 'Heure',
		hourText: 'Heure',
		minuteText: 'Minute',
		secondText: 'Seconde'
	};
	$.timepicker.setDefaults($.timepicker.regional['fr']);
});