/* Portuguese initialization for the jQuery UI timepicker plugin. */
jQuery(function($){
	$.timepicker.regional['pt'] = {
		currentText: 'Actualmente',
		closeText: 'Concluido',
		ampm: false,
		timeFormat: 'hh:mm tt',
		timeOnlyTitle: 'Escolha a Hora',
		timeText: 'Hora',
		hourText: 'Horas',
		minuteText: 'Minutos',
		secondText: 'Segundos'
	};
	$.timepicker.setDefaults($.timepicker.regional['pt']);
});