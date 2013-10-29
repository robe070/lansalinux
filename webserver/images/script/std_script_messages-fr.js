/*!
	(c) 2002, 2012 LANSA
	Standard Scripts messages
	$Workfile:: std_script_messages-fr.js   $
	$UTCDate:: 2012-02-20 04:27:51Z         $
	$Revision:: 15                          $
*/

if (!window.Lstd) Lstd = {};
if (!Lstd.L10N) Lstd.L10N = { lang: "en" };
if (!Lstd.L10N.strings) Lstd.L10N.strings = {};
if (!Lstd.L10N.arrays) Lstd.L10N.arrays = {};

Lstd.L10N.strings.fr = {
	"PPCNoForm": "Ce navigateur ne supporte pas document.createElement. Vous devez avoir un FORM qui doit être précisé dans la propriété formname de l'objet appelant.",
	"BadHidFld": "Ce navigateur ne supporte pas document.createElement. Vous devez prédéfichir la zone cachée %1%.",
	"BadHidFld1": "document.createElement non implémenté, ",
	"BadHidFld2": " la zone cachée doit être présente dans le formulaire!",
	"BadNum": "Nombre incorrect. Le nombre doit ne contenie que des chiffres (pas plus de %1% avant le séparateur décimal et pas plus de %2% après).",
	"BadNum1": "Chiffres autorisés avant le signe décimal = ",
	"BadNum2": "\nChiffres autorisés après le signe décimal = ",
	"BadNum3": "\nLes données seront tronquées suivant ces valeurs.",
	"BadInt": "Nombre entier incorrect!",
	"BadIntWithRange": "Nombre entier incorrect! Ne peut pas être inférieur à %1%, ou supérieur à %2%.",
	"BadInt1": " Ne peut pas être inférieur à ",
	"BadInt2": ", ou supérieur à ",
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
	"BadDBCS": "La longueur totale des caractères saisis convertis ",
	"BadDBCS1": "Seuls sont admis dans cette zone des caractères DBCS.\n",
	"BadDBCS2": " caractères SBCS ont été saisis..\n",
	"BadDBCS3": "Les caractères SBCS seront supprimés.",
	"BadDBCS4": "Vous pouvez saisir soit des caractères DBCS ",
	"BadDBCS5": "soit des caractères SBCS dans cette zone.\n",
	"BadDBCS6": " caractères SBCS ont été saisis.\n",
	"BadDBCS7": " caractères DBCS ont été saisis.\n",
	"BadDBCS8": "Modifiez les données saisies.",
	"BadDBCS9": "Seuls sont admis dans cette zone des caractères SBCS.\n",
	"BadDBCS10": " caractères DBCS ont été saisis.\n",
	"BadDBCS11": "Les caractères DBCS seront supprimés.",
	"BadDBCS12": "\n dépasse la longueur maximum autorisée ",
	"BadDBCS13": "\nLes données seront tronquées selon cette longueur.",
	"BadLength1": "Les caractères maximum ont atteint.",
	"NoXMLHttpRequest": "XMLHttpRequest non supporté par ce navigateur.",
	"Processing1": "En cours",
	"Done1": "Terminé",
	"mobiscroll-cancelText": "Cancel",
	"mobiscroll-setText": "Set",
	"mobiscroll-dayText": "Day",
	"mobiscroll-monthText": "Month",
	"mobiscroll-yearText": "Year",
	"mobiscroll-hourText": "Hours",
	"mobiscroll-minuteText": "Minutes",
	"mobiscroll-secText": "Seconds"
}

Lstd.L10N.arrays.en = {
	"DaysOfWeek": new Array("Lun", "Mar", "Mer", "Jeu", "Ven", "Sam", "Dim"),
	"DaysOfWeekLong": ["Monday", "Tueday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"],
	"Months": new Array("Janvier", "Février", "Mars", "Avril", "Mai", "Juin", "Juillet", "Août", "Septembre", "Octobre", "Novembre", "Décembre"),
	"MonthsShort": ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"]
}
