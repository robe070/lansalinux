﻿/*!
	(c) 2002, 2012 LANSA
	Standard Scripts messages
	$Workfile:: std_messages-fr.js          $
	$UTCDate:: 2012-09-28 05:47:14Z         $
	$Revision:: 20                          $
*/

if (!window.Lstd) Lstd = {};
if (!Lstd.L10N) Lstd.L10N = { lang: "fr" };
if (!Lstd.L10N.strings) Lstd.L10N.strings = {};
if (!Lstd.L10N.arrays) Lstd.L10N.arrays = {};

Lstd.L10N.strings.fr = {
	"PPCNoForm": "Ce navigateur ne supporte pas document.createElement. Vous devez avoir un FORM qui doit être précisé dans la propriété formname de l"objet appelant.",
	"BadHidFld": "Ce navigateur ne supporte pas document.createElement. Vous devez prédéfichir la zone cachée %1%.",
	"BadNum": "Nombre incorrect. Le nombre doit ne contenie que des chiffres (pas plus de %1% avant le séparateur décimal et pas plus de %2% après).",
	"BadInt": "Nombre entier incorrect!",
	"BadIntWithRange": "Nombre entier incorrect! Ne peut pas être inférieur à %1%, ou supérieur à %2%.",
	"BadFloat": "Nombre à décimale flottante incorrect!",
	"BadDate": "Date incorrecte !",
	"BadDate1": " est une date incorrecte !",
	"BlankDate": "Une valeur à blanc est une date incorrecte! Date du jour utilisée par défaut!",
	"BlankDate2": "Une valeur à blanc est une date incorrecte!",
	"BadTime": "Heure incorrecte!",
	"BadTime1": " est une heure incorrecte !",
	"BlankTime": "Une valeur à blanc est une heure incorrecte! Heure actuelle utilisée par défaut!",
	"BlankTime2": "Une valeur à blanc est une heure incorrecte!",
	"BadDateTime": "Date-heure incorrecte!",
	"BadBool": "Valeur incorrecte.\nLa valeur doit être  \"true\" or \"false\"",
	"BadDBCS_TooLong": "La longueur totale des caractères saisis convertis %1 dépasse la longueur maximum autorisée %2.",
	"BadDBCS_SBCSNotAllowed": "Seuls sont admis dans cette zone des caractères DBCS. %1 caractères SBCS ont été saisis.",
	"BadDBCS_DBCSNotAllowed": "Seuls sont admis dans cette zone des caractères SBCS. %1 caractères DBCS ont été saisis.",
	"BadDBCS_BothNotAllowed": "Vous pouvez saisir soit des caractères DBCS soit des caractères SBCS dans cette zone. %1 caractères SBCS ont été saisis. %2 caractères DBCS ont été saisis.",
	"BadLength1": "Les caractères maximum ont atteint.",
	"NoXMLHttpRequest": "XMLHttpRequest non supporté par ce navigateur.",
	"Processing1": "En cours",
	"Done1": "Terminé",
	"Messages": "Messages:"
}

Lstd.L10N.arrays.en = {
	"DaysOfWeek": ["Lun", "Mar", "Mer", "Jeu", "Ven", "Sam", "Dim"],
	"DaysOfWeekLong": ["Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi", "Dimanche"],
	"Months": ["Janvier", "Février", "Mars", "Avril", "Mai", "Juin", "Juillet", "Août", "Septembre", "Octobre", "Novembre", "Décembre"],
	"MonthsShort": ["Janv", "Févr", "Mars", "Avril", "Mai", "Juin", "Juil", "Août", "Sept", "Oct", "Nov", "Déc"]
}
