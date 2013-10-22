/*!
	(c) 2011, 2012 LANSA
	Google Charts
	$Workfile:: std_gcharts.js     $
	$UTCDate:: 2012-09-28 01:08:49Z   $
	$Revision:: 22        $
*/

var Lstd = Lstd || {};
Lstd.Weblets = Lstd.Weblets || {};
Lstd.Weblets.Google = Lstd.Weblets.Google || {};

/**
 * @namespace Google Image Charts related APIs
 */
Lstd.Weblets.Google.Charts = {

	/**
	* Returns the Google image charts' url
	* @returns (string) Google image charts' url
	*/
	url: function() {
		// Note: [0-9].chart.googleapis.com not working.
		return "https://chart.googleapis.com/chart?";
	},

	/**
	* Min/Max value finder
	* @param (array of numeric values) Data array
	* @returns (object) The minimum and maximum values
	*/
	minmax: function(ar) {
		var nMin = ar[0];
		var nMax = ar[0];
		var nLen = ar.length;
		var nCur;
		if (nLen > 1) {
			for (var i = 1; i < nLen; i++) {
				nCur = ar[i];
				if (nCur < nMin) nMin = nCur;
				if (nCur > nMax) nMax = nCur;
			}
		}
		return { min: nMin, max: nMax };
	},

	/**
	* Shifts array values up by the given value
	* @param (array of numeric values) Data array
	* @param (number)
	* @returns (array of numeric values) Data array shifted upward by given value
	*/
	shiftUp: function(ar, val) {
		var len = ar.length;
		for (var i = 0; i < len; i++) ar[i] += val;
	},

	/**
	* Google Image Charts extended encoding encoder
	* @param (array of numeric values) Data array
	* @param Maximum value found in array
	* @returns (string) The values array encoded in Google image charts' extended encoding format
	*/
	extendedEncode: function(arrVals, maxVal) {
		var EXTENDED_MAP = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-.";
		var EXTENDED_MAP_LENGTH = EXTENDED_MAP.length;
		var chartData = "";

		for (var i = 0, len = arrVals.length; i < len; i++) {
			// In case the array vals were translated to strings.
			var numericVal = new Number(arrVals[i]);
			// Scale the value to maxVal.
			var scaledVal = Math.floor(EXTENDED_MAP_LENGTH * EXTENDED_MAP_LENGTH * numericVal / maxVal);

			if (scaledVal > (EXTENDED_MAP_LENGTH * EXTENDED_MAP_LENGTH) - 1) {
				chartData += "..";
			}
			else if (scaledVal < 0) {
				chartData += '__';
			}
			else {
				// Calculate first and second digits and add them to the output.
				var quotient = Math.floor(scaledVal / EXTENDED_MAP_LENGTH);
				var remainder = scaledVal - EXTENDED_MAP_LENGTH * quotient;
				chartData += EXTENDED_MAP.charAt(quotient) + EXTENDED_MAP.charAt(remainder);
			}
		}
		return chartData;
	},

	/**
	* Returns the Lstd.Json.ListEntries for building the chart data parameter
	* @param (String) Name of the JSON list
	* @param (Boolean) Transpose list rows and columns?
	* @returns (object) The values array encoded in Google image charts' extended encoding format,
	*				the 0 level offset, the data range, series count and number of data values per series
	*/
	getListEntries: function(listName, transpose) {
		var lw = Lstd.Lists[listName];
		return transpose ? lw.entries().transpose() : lw.entries();
	},

	/**
	* Builds the chart data parameter from a JSON list
	* @param (String) Chart type
	* @param (Object) Lstd.Json.ListEntries
	* @returns (object) The values array encoded in Google image charts' extended encoding format,
	*				the 0 level offset, the data range, series count and number of data values per series
	*/
	buildData: function(cht, entries) {
		var data = [];
		var range = { min: 0, max: 0 };
		var atop = (cht === "bvs" || cht === "bhs");

		entries.rawEach(function(index, entry) {
			var ar = entry.slice(0, entry.length);

			if (!atop) {
				var nMinMax = Lstd.Weblets.Google.Charts.minmax(ar);

				// Keep min, max across all data series
				if (nMinMax.min < range.min) range.min = nMinMax.min;
				if (nMinMax.max > range.max) range.max = nMinMax.max;
			}
			data.push(ar);
		});

		if (atop) {
			var rangemax = new Array(entries.columnCount());

			for (var i = 0; i < rangemax.length; i++) {
				rangemax[i] = 0;
			}

			// Compute "sum of absolute column values" for each series
			entries.rawEach(function(index, entry) {
				var nLen = entry.length;
				for (var j = 0; j < nLen; j++) {
					rangemax[j] += entry[j];
				}
			});

			// atop charts only work with positive column values
			range.min = 0;

			// Compute the maximum range needed for atop chart
			for (i = 0; i < rangemax.length; i++) {
				if (rangemax[i] > range.max) {
					range.max = rangemax[i];
				}
			}
		}

		var nLen = data.length;
		var chd = "e:";
		var chp = 0;

		if (range.min < 0) {
			var newMax = range.max - range.min;
			for (var i = 0; i < nLen; i++) {
				Lstd.Weblets.Google.Charts.shiftUp(data[i], -range.min);
				if (i > 0) chd += ",";
				chd += Lstd.Weblets.Google.Charts.extendedEncode(data[i], newMax);
			}
			chp = -range.min / newMax;
		}
		else {
			for (var i = 0; i < nLen; i++) {
				if (i > 0) chd += ",";
				chd += Lstd.Weblets.Google.Charts.extendedEncode(data[i], range.max);
			}
		}
		return { chd: chd, chp: chp, range: range, seriesCount: entries.rowCount(), valueCount: entries.columnCount() };
	},

	/**
	* Encodes text to place in url
	* @param (String) string to encode
	* @return (String) encoded string
	*/
	encode: function(s) {
		return encodeURIComponent(s);
	},

	/**
	* Encodes comma separated string labels separating entries with pipe (|) character
	* @param (Array) Array of labels to encode
	* @return (String) encoded string
	*/
	encodelabels: function(a) {
		for (var i = 0; i < a.length; i++) a[i] = Lstd.Weblets.Google.Charts.encode(a[i]);
		return a.join("|");
	},

	/**
	* Coverts the list entries into an array (the named column from each row)
	* The array has one entry for each row in the list.
	* @param (String) List name
	* @param (String) Column name
	* @return (String) Array of converted entries
	*/
	listEntriesToArray: function(l, col) {
		var list = Lstd.Lists[l];
		var a = [];
		try {
			if (list) {
				var col_i = list.headers().indexOf(col);
				list.entries().rawEach(function(i, entry) {
					a[i] = entry[col_i];
				});			
			}
		}
		catch (e) {
			console.error("Lstd.Weblets.Google.Charts.listEntriesToArray(): " + e);
		}
		return a;
	},

	/**
	* Handles chart standard features such as labels, chart title and legends
	* @param (Object) Chart options (argument list)
	* @param (Object) Chart parameters
	* @param (Object) POST extensions
	* @return None
	*/
	StandardFeatures: function(args, chart, post_ext) {
		args.work = args.work || {};
		var isPie = args.chartType.charAt(0) == 'p';

		// Chart size
		chart.chs = args.width + "x" + args.height;

		// Determine axis
		chart.chxt = "x,y";
		args.work.labelAxis = ((args.chartType == "bhs") || (args.chartType == "bhg")) ? 1 : 0;
		args.work.rangeAxis = args.work.labelAxis == 1 ? 0 : 1;

		/* Build labels map with specified values or defaults. Note: Axes color needs all preceding options,
		otherwise, they are ignored */
		var labels = args.labels || {};
		if (args.labels) {
			labels.color = args.labels.color ? args.labels.color : Lstd.Weblets.Google.Charts.textColor();
			labels.fontSize = args.labels.fontSize ? args.labels.fontSize : 10;
		}
		else {
			labels = { text: null, color: Lstd.Weblets.Google.Charts.textColor(), fontSize: 10 };
		}

		var labelsArray = (labels.text && (labels.text != "")) ? labels.text.split(",") : (labels.list && (labels.list != "")) ?
			Lstd.Weblets.Google.Charts.listEntriesToArray(labels.list, labels.column) : [];

		if (labelsArray && labelsArray.length > 0) {
			chart.chxl = args.work.labelAxis + ":|" + Lstd.Weblets.Google.Charts.encodelabels(labelsArray);
			post_ext.chxl = args.work.labelAxis + ":|" + labelsArray.join("|");
		}
		chart.chxs = args.work.labelAxis + "," + labels.color + "," + labels.fontSize;
		if (!isPie) {
			var tickAxesColor = args.axesColor ? args.axesColor : Lstd.Weblets.Google.Charts.axesColor();
			chart.chxs += ",0,lt," + tickAxesColor + "," + tickAxesColor;
		}

		// Range labels - skip pie charts
		if (!isPie) {
			var rangeLabels = args.rangeLabels || {};
			if (args.rangeLabels) {
				rangeLabels.color = args.rangeLabels.color ? args.rangeLabels.color : Lstd.Weblets.Google.Charts.textColor();
				rangeLabels.fontSize = args.rangeLabels.fontSize ? args.rangeLabels.fontSize : 10;
			}
			else {
				rangeLabels = { text: null, color: Lstd.Weblets.Google.Charts.textColor(), fontSize: 10 };
			}

			var rangeLabelsArray = (rangeLabels.text && (rangeLabels.text != "")) ? rangeLabels.text.split(",") : (rangeLabels.list && (rangeLabels.list != "")) ?
				Lstd.Weblets.Google.Charts.listEntriesToArray(rangeLabels.list, rangeLabels.column) : [];

			if (rangeLabelsArray && rangeLabelsArray.length > 0) {
				if (!chart.chxl) {
					chart.chxl = "";
					post_ext.chxl = "";
				}
				else {
					chart.chxl += "|";
					post_ext.chxl += "|";
				}
				chart.chxl += args.work.rangeAxis + ":|" + Lstd.Weblets.Google.Charts.encodelabels(rangeLabelsArray);
				post_ext.chxl += args.work.rangeAxis + ":|" + rangeLabelsArray.join("|");
			}
			if (!chart.chxs) {
				chart.chxs = "";
			}
			else {
				chart.chxs += "|";
			}
			chart.chxs += args.work.rangeAxis + "," + rangeLabels.color + "," + rangeLabels.fontSize;
			var tickAxesColor = args.axesColor ? args.axesColor : Lstd.Weblets.Google.Charts.axesColor();
			chart.chxs += ",0,lt," + tickAxesColor + "," + tickAxesColor;
		}

		// Background color
		chart.chf = "bg,s," + (args.bgColor ? args.bgColor : Lstd.Weblets.Google.Charts.bgColor());

		// Chart title
		if (args.title) {
			chart.chtt = Lstd.Weblets.Google.Charts.encode(new String(args.title.text));
			post_ext.chtt = args.title.text;

			if (args.title.color) chart.chts = args.title.color;
			if (args.title.fontSize) {
				if (args.title.color == null) chart.chts = Lstd.Weblets.Google.Charts.textColor();
				chart.chts += "," + args.title.fontSize;
			}
		}

		// Chart legend
		if (args.legend) {
			var legend = args.legend; 
			var legendArray = (legend.text && (legend.text != "")) ? legend.text.split(",") : (legend.list && (legend.list != "")) ?
				Lstd.Weblets.Google.Charts.listEntriesToArray(legend.list, legend.column) : [];

			chart.chdl = Lstd.Weblets.Google.Charts.encodelabels(legendArray);
			post_ext.chdl = legendArray.join("|");
			if (legend.pos) chart.chdlp = legend.pos;
			if (legend.order) {
				if (legend.pos) chart.chdlp = "r";
				chart.chdlp += "|" + legend.order;
			}
			if (legend.color) chart.chdls = legend.color;
			if (legend.fontSize) {
				if (legend.color == null) chart.chdls = Lstd.Weblets.Google.Charts.textColor();
				chart.chdls += "," + legend.fontSize;
			}
		}

		// Chart margins
		if (args.margins) {
			chart.chma = args.margins;
			if (args.legend && args.legend.margins) chart.chma += "|" + args.legend.margins;
		}
		else if (args.legend && args.legend.margins) {
			chart.chma = "0,0,0,0|" + args.legend.margins;
		}
	},

	/**
	* Gets the chart color sampler node. If not found, it creates it
	* @return (Object) the chart color sampler node
	*/
	chartSampler: function() {
		var lweb_palette = jQuery("#lweb_palette");
		if (lweb_palette.length == 0) {
			var html = "<div id=\"lweb_palette\"><div id=\"lweb_color_palette\" class=\"lpc-color-palette-main\">";
			for (var i = 1; i <= 5; i++) for (var j = 1; j <= 2; j++) html += "<span class=\"lpc-color-palette-" + j + "-" + i + "\"></span>";
			html += "</div><div id=\"lweb_color_theme_darker\" class=\"lpc-color-palette-theme-darker\"></div><div class=\"ui-widget\"><div id=\"lweb_widget_content\" class=\"ui-widget-content\"></div></div></div>";
			lweb_palette = jQuery(html).appendTo("#lweb_hidden");
		}
		return lweb_palette;
	},

	cachedColors: null,
	cachedPieColor: null,
	cachedBgColor: null,
	cachedTextColor: null,
	cachedAxesColor: null,

	/**
	* Gets the default theme colors for charts
	* @param (number) Number of colors to return (up to 10)
	* @return (String) Default theme colors
	*/
	colors: function(count) {
		if (Lstd.Weblets.Google.Charts.cachedColors == null) {
			var cols = [];
			var lweb_palette = Lstd.Weblets.Google.Charts.chartSampler();
			lweb_palette.find("#lweb_color_palette span").each(function() {
				cols.push(Lstd.Utils.getHexColor(jQuery(this).css("background-color")));
			});
			Lstd.Weblets.Google.Charts.cachedColors = cols;
		}
		if (count > Lstd.Weblets.Google.Charts.cachedColors.length) count = Lstd.Weblets.Google.Charts.cachedColors.length;
		return Lstd.Weblets.Google.Charts.cachedColors.slice(0, count);
	},

	/**
	* Gets the default theme color for pie charts
	* @return (String) Default theme color for pie charts
	*/
	pieColor: function() {
		if (Lstd.Weblets.Google.Charts.cachedPieColor == null) {
			Lstd.Weblets.Google.Charts.chartSampler();
			Lstd.Weblets.Google.Charts.cachedPieColor = Lstd.Utils.getHexColor(jQuery("#lweb_color_theme_darker").css("background-color"));
		}
		return Lstd.Weblets.Google.Charts.cachedPieColor;
	},

	/**
	* Gets the default chart background color
	* @return (String) Default background color
	*/
	bgColor: function() {
		if (Lstd.Weblets.Google.Charts.cachedBgColor == null) {
			Lstd.Weblets.Google.Charts.chartSampler();
			Lstd.Weblets.Google.Charts.cachedBgColor = Lstd.Utils.getHexColor(jQuery("#lweb_widget_content").css("background-color"));
		}
		return Lstd.Weblets.Google.Charts.cachedBgColor;
	},

	/**
	* Gets the default chart color for title/legends
	* @return (String) Default font color
	*/
	textColor: function() {
		if (Lstd.Weblets.Google.Charts.cachedTextColor == null) {
			Lstd.Weblets.Google.Charts.chartSampler();
			Lstd.Weblets.Google.Charts.cachedTextColor = Lstd.Utils.getHexColor(jQuery("#lweb_color_palette").css("color"));
		}
		return Lstd.Weblets.Google.Charts.cachedTextColor;
	},

	/**
	* Gets the default color for chart axes
	* @return (String) Default axes color
	*/
	axesColor: function() {
		if (Lstd.Weblets.Google.Charts.cachedAxesColor == null) {
			Lstd.Weblets.Google.Charts.chartSampler();
			Lstd.Weblets.Google.Charts.cachedAxesColor = Lstd.Utils.getHexColor(jQuery("#lweb_color_palette").css("border-left-color"));
		}
		return Lstd.Weblets.Google.Charts.cachedAxesColor;
	},

	/**
	* Makes a query string from the chart map
	* @return (String) Chart query string
	*/
	makeQueryString: function(chart) {
		var q = [];
		for (x in chart) q.push(x + "=" + chart[x]);
		return q.join("&");
	},

	/**
	* Handles the Google chart request
	* @param (Object) Chart options (argument list)
	* @param (Object) Chart parameters
	* @param (Object) POST extensions
	* @return (String) Chart query string
	*/
	makeRequest: function(args, chart, post_ext) {
		var httpGet = Lstd.Weblets.Google.Charts.url() + Lstd.Weblets.Google.Charts.makeQueryString(chart);
		var span = jQuery(Lstd.Utils.makeSafeId(args.id));
		//if (log) log(httpGet);
		if (httpGet.length < 2048) {
			span.append("<img src=\"" + httpGet + "\" />");
		}
		else {
			var iframe = jQuery("<iframe style=\"width:" + args.width + "px; height:" + args.height + "px; border-style:none\"></iframe>");
			span.append(iframe);
			setTimeout(function() {
				var doc = iframe[0].contentWindow.document;
				var body = jQuery("body", doc);
				var s = "<form name=\"" + args.id + "_form\" action=\"" + Lstd.Weblets.Google.Charts.url() + "chid=" + (new Date()).getMilliseconds() + "\" method=\"post\">";
				jQuery.extend(chart, post_ext); // Replace escaped values for POST
				for (x in chart) s += "<input type=\"hidden\" name=\"" + x + "\" value=\"" + chart[x] + "\" />";
				s += "<input type=\"submit\" style=\"display:none\"/></form>";
				body.append(s);
				doc.forms[args.id + "_form"].submit();
			}, 1);

		}
	},

	/**
	* Bar chart (input mode) weblet
	* @param (Map)
	* Options
	* id: id of the span container for the chart
	* chartType
	* seriesColors
	* labels
	* barWidth
	* spaceBetweenBars
	* spaceBetweenGroups
	* width
	* height
	* background color
	* title
	* legend
	* margins
	*/
	Bar: function(args) {
		jQuery(function() {
			var chart = {};
			var post_ext = {};
			chart.cht = args.chartType ? args.chartType : "bhs";

			try {
				var enc = Lstd.Weblets.Google.Charts.buildData(chart.cht, Lstd.Weblets.Google.Charts.getListEntries(args.listName, args.transpose ? args.transpose : false));
				chart.chd = enc.chd;
				if (enc.chp > 0) chart.chp = enc.chp;

				// Colors
				if (args.colors) {
					chart.chco = enc.seriesCount > 1 ? args.colors : args.colors.slice(0).replace(/,/g, "|");
				}
				else {
					if (enc.seriesCount == 1) {
						// If legends passed, use a different colors for each bar
						chart.chco = args.legend ? Lstd.Weblets.Google.Charts.colors(enc.valueCount).join("|") : Lstd.Weblets.Google.Charts.colors(1)[0];
					}
					else {
						chart.chco = Lstd.Weblets.Google.Charts.colors(enc.seriesCount).join();
					}
				}

				// Bar width and spacing
				var barWidth = args.barWidth ? args.barWidth : "a";
				chart.chbh = barWidth;
				if (args.spaceBetweenBars != null) {
					chart.chbh += "," + args.spaceBetweenBars;
				}
				else if (args.spaceBetweenGroups != null) {
					chart.chbh += "," + (((barWidth == "a") || (barWidth != "r")) ? 4 : (4 / 23));
				}
				if (args.spaceBetweenGroups != null) chart.chbh += "," + args.spaceBetweenGroups;

				Lstd.Weblets.Google.Charts.StandardFeatures(args, chart, post_ext);

				var rangeStart = enc.range.min > 0 ? 0 : enc.range.min;
				chart.chxr = args.work.rangeAxis + "," + rangeStart + "," + enc.range.max;
				Lstd.Weblets.Google.Charts.makeRequest(args, chart, post_ext);
			}
			catch (e) {
				console.error("Lstd.Weblets.Google.Charts.Bar(): " + e);
			}
		});
	},

	/**
	* Pie chart (input mode) weblet
	* @param (Map)
	* Options
	* id: id of the span container for the chart
	* chartType
	* seriesColors
	* labels
	* rotation
	* width
	* height
	* background color
	* title
	* legend
	* margins
	*/
	Pie: function(args) {
		jQuery(function() {
			var chart = {};
			var post_ext = {};
			chart.cht = args.chartType ? args.chartType : "p";

			try {
				var enc = Lstd.Weblets.Google.Charts.buildData(chart.cht, Lstd.Weblets.Google.Charts.getListEntries(args.listName, args.transpose ? args.transpose : false));
				chart.chd = enc.chd;

				// Colors
				if (args.colors) {
					chart.chco = enc.seriesCount > 1 ? args.colors : args.colors.slice(0).replace(/,/g, "|");
				}
				else {
					chart.chco = Lstd.Weblets.Google.Charts.pieColor();
				}

				// Chart rotation
				if (args.rotation) chart.chp = args.rotation;

				Lstd.Weblets.Google.Charts.StandardFeatures(args, chart, post_ext);
				Lstd.Weblets.Google.Charts.makeRequest(args, chart, post_ext);
			}
			catch (e) {
				console.error("Lstd.Weblets.Google.Charts.Pie(): " + e);
			}
		});
	},

	/**
	* Line chart (input mode) weblet
	* @param (Map)
	* Options
	* id: id of the span container for the chart
	* chartType
	* seriesColors
	* labels
	* width
	* height
	* background color
	* title
	* legend
	* margins
	*/
	Line: function(args) {
		jQuery(function() {
			var chart = {};
			var post_ext = {};
			chart.cht = args.chartType ? args.chartType : "lc";

			try {
				var entries = Lstd.Weblets.Google.Charts.getListEntries(args.listName, args.transpose ? args.transpose : false);
				var enc = Lstd.Weblets.Google.Charts.buildData(chart.cht, entries);
				chart.chd = enc.chd;
				if (enc.chp > 0) chart.chp = enc.chp;

				// Colors
				chart.chco = args.colors != null ? args.colors : Lstd.Weblets.Google.Charts.colors(enc.seriesCount).join();

				// Line style
				var lineThickness = args.lineThickness ? args.lineThickness : 2;
				chart.chls = lineThickness;
				if (enc.seriesCount > 1) {
					var rep = "|" + lineThickness;
					for (var i = 1; i < enc.seriesCount; i++) chart.chls += rep;
				}

				// Shape markers
				if (args.markers) {
					var nRows = entries.rowCount();
					var ar = entries.entries;
					var chm = [];
					var incr = chart.cht == "lxy" ? 2 : 1;
					var pfx = args.markers.type + "," + (args.markers.color ? args.markers.color : Lstd.Weblets.Google.Charts.textColor()) + ",";
					var fsiz = "," + (args.markers.fontSize ? args.markers.fontSize : (lineThickness + 4));
					for (var i = 0; i < nRows; i += incr) chm.push(pfx + i + ",-1" + fsiz);
					chart.chm = chm.join("|");
				}

				Lstd.Weblets.Google.Charts.StandardFeatures(args, chart, post_ext);

				var rangeStart = enc.range.min > 0 ? 0 : enc.range.min;
				chart.chxr = args.work.rangeAxis + "," + rangeStart + "," + enc.range.max;

				// Base axis range
				if ((chart.cht == "lxy") && (!args.labels || args.labels.text)) {
					var baseStart = 0;
					var baseEnd = 0;
					entries.rawEach(function(index, entry) {
						if (!(index % 2)) {
							var nCols = entry.length;
							for (var i = 0; i < nCols; i++) {
								if (entry[i] < baseStart) baseStart = entry[i];
								if (entry[i] > baseEnd) baseEnd = entry[i];
							}
						}
					});
					chart.chxr += "|" + args.work.labelAxis + "," + baseStart + "," + baseEnd;
				}
				Lstd.Weblets.Google.Charts.makeRequest(args, chart, post_ext);
			}
			catch (e) {
				console.error("Lstd.Weblets.Google.Charts.Line(): " + e);
			}
		});
	}
};
