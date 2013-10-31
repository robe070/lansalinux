/* Inicialización en español para la extensión 'timepicker' para jQuery. */
jQuery(function($){
	$.timepicker.regional['es'] = {
		currentText: 'Ahora',
		closeText: 'Cerrar',
		ampm: false,
		timeFormat: 'hh:mm tt',
		timeOnlyTitle: 'Escoger la hora',
		timeText: 'Hora',
		hourText: 'Hora',
		minuteText: 'Minuto',
		secondText: 'Segundo'
	};
	$.timepicker.setDefaults($.timepicker.regional['es']);
});