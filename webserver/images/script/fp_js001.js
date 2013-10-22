/*!
	$Workfile:: fp_js001.js                 $
	$UTCDate:: 2011-10-21 05:42:41Z         $
	$Revision:: 9                           $
*/

/*************************************************************************
 * FP_JS001_PUBLIC_Create - The Calendar Constructor
 **************************************************************************/

function FP_JS001_Object(argobjDate)
{
	this._selectedDate = argobjDate;

	this._matrix = [[],[],[],[],[],[],[]];
	this._showNone = true;
	this._showToday = true;
	this._firstWeekDay = 0; // start week with monday according to standards
	this._redWeekDay = 6; // sunday is the default red day.
	this._dontChangeNone = false;
}

/* Publish methods */

FP_JS001_Object.prototype.create = FP_JS001_PUBLIC_Create;
FP_JS001_Object.prototype._createTable = FP_JS001_PUBLIC_CreateTable;
FP_JS001_Object.prototype.setDate = FP_JS001_PUBLIC_SetDate;
FP_JS001_Object.prototype.getDate = FP_JS001_PUBLIC_GetDate;
FP_JS001_Object.prototype._updateTable = FP_JS001_PUBLIC_UpdateTable;
FP_JS001_Object.prototype._setTopLabel = FP_JS001_PUBLIC_SetTopLabel;
FP_JS001_Object.prototype.goToNextMonth = FP_JS001_PUBLIC_GoToNextMonth;
FP_JS001_Object.prototype.goToPreviousMonth = FP_JS001_PUBLIC_GoToPreviousMonth;

/* --------------------------------------------------------------------- */
/*                          Public Methods                               */
/* --------------------------------------------------------------------- */

/*************************************************************************
 * FP_JS001_PUBLIC_Create - Object Creator
 *************************************************************************/

function FP_JS001_PUBLIC_Create(doc)
{
	// create elements
	this._el = document.createElement("div");
	this._el.className = "datePicker";

	// header
	var div = document.createElement("div");
	div.className = "header";
	this._el.appendChild(div);
	
	var headerTable = document.createElement("table");
	headerTable.className = "headerTable";
	headerTable.cellSpacing = 0;
	div.appendChild(headerTable);

	var tBody = document.createElement("tbody");
	headerTable.appendChild( tBody );

	var tr = document.createElement("tr");
	tBody.appendChild(tr);

	var td = document.createElement("td");
	this._previousMonth = document.createElement("span");
	this._previousMonth.className = "previousButton";

	td.appendChild(this._previousMonth);
	this._previousMonthIMG = document.createElement("img");
	this._previousMonthIMG.src = "fp_im004.gif";
	this._previousMonthIMG.id = "VF_HT003_PreviousButton";
	this._previousMonth.appendChild(this._previousMonthIMG);
	tr.appendChild(td);

	td = document.createElement("td");
	td.className = "labelContainer";
	tr.appendChild(td);

	this._topLabel = document.createElement("span");
	this._topLabel.className = "topLabel";
	this._topLabel.href = "#";
	this._topLabel.appendChild( document.createTextNode(String.fromCharCode(160)));
	td.appendChild(this._topLabel);

	// no insertion

	td = document.createElement("td");
	this._nextMonth = document.createElement("span");
	this._nextMonth.className = "nextButton";
	td.appendChild(this._nextMonth);
	this._nextMonthIMG = document.createElement("img");
	this._nextMonthIMG.src = "fp_im005.gif";
	this._nextMonthIMG.id = "VF_HT003_NextButton";
	this._nextMonth.appendChild(this._nextMonthIMG);
	tr.appendChild( td );

	// grid
	div = document.createElement("div");
	div.className = "grid";
	this._el.appendChild(div);
	this._table = div;

	this._createTable(doc);
	this._updateTable();
	this._setTopLabel();

	if (!this._showNone) this._noneButton.style.visibility = "hidden";
	if (!this._showToday) this._todayButton.style.visibility = "hidden";

	// IE55+ extension
	this._previousMonth.hideFocus = true;
	this._nextMonth.hideFocus = true;

	// end IE55+ extension

	// hook up events
	var dp = this;

	// buttons
	this._previousMonth.onclick = function()
	{
		dp._dontChangeNone = true;
		dp.goToPreviousMonth();
		dp._dontChangeNone = false;
	};
	
	this._nextMonth.onclick = function()
	{
		dp._dontChangeNone = true;
		dp.goToNextMonth();
		dp._dontChangeNone = false;
	};

	this._el.onselectstart = function() 
	{
		return false;
	};

	this._table.onclick = function(e)
	{
		// find event
		if (e == null) e = document.parentWindow.event;

		// find td
		var el = e.target != null ? e.target : e.srcElement;
		while (el.nodeType != 1) el = el.parentNode;
		while (el != null && el.tagName && el.tagName.toLowerCase() != "td") el = el.parentNode;

		// if no td found, return
		if (el == null || el.tagName == null || el.tagName.toLowerCase() != "td") return;

		var d = new Date(dp._selectedDate);
		var n = Number(el.firstChild.data);
		if (isNaN(n) || n <= 0 || n == null) return;

		d.setDate(n);
		dp.setDate(d);
		if (typeof dp.ondateselected == "function") dp.ondateselected();
	};

	this._el.onkeydown = function(e) 
	{
		if (e == null) e = document.parentWindow.event;
		var kc = e.keyCode != null ? e.keyCode : e.charCode;

		if (kc < 37 || kc > 40) return true;

		var d = new Date(dp._selectedDate).valueOf();
		if (kc == 37) d -= 24 * 60 * 60 * 1000;  // left
		else if (kc == 39) d += 24 * 60 * 60 * 1000;  // right
		else if (kc == 38) d -= 7 * 24 * 60 * 60 * 1000;  // up
		else if (kc == 40) d += 7 * 24 * 60 * 60 * 1000;  // down

		dp.setDate(new Date(d));
		return false;
	}
	return this._el;
};

/*************************************************************************
 * FP_JS001_PUBLIC_SetDate - Set the value of date
 *************************************************************************/

function FP_JS001_PUBLIC_SetDate(argobjDate)
{
	// if string or number create a Date object
	if (typeof argobjDate == "string" || typeof argobjDate == "number")
	{
		argobjDate = new Date(argobjDate);
	}

	// do not update if not really changed
	if (this._selectedDate.getDate() != argobjDate.getDate() || 
		this._selectedDate.getMonth() != argobjDate.getMonth() || 
		this._selectedDate.getFullYear() != argobjDate.getFullYear() ||
		this._none)
	{
		/* if (!this._dontChangeNone) this._none = false; */

		this._selectedDate = new Date(argobjDate);

		this._setTopLabel();
		this._updateTable();

		if (typeof this.onchange == "function") this.onchange();
	}

	/* if (!this._dontChangeNone) this._none = false; */
}

/*************************************************************************
 * FP_JS001_PUBLIC_GetDate - Get the value of date
 *************************************************************************/

function FP_JS001_PUBLIC_GetDate()
{
	if (this._none) return null;
	return new Date(this._selectedDate); // create a new instance
}

/*************************************************************************
 * FP_JS001_PUBLIC_CreateTable - Create calendar table
 *************************************************************************/

function FP_JS001_PUBLIC_CreateTable(doc)
{
	var str, i;
	var rows = 6;
	var cols = 7;
	var currentWeek = 0;

	var table = document.createElement("table");
	table.className = "gridTable";
	table.cellSpacing = 0;

	var tBody = document.createElement("tbody");
	table.appendChild(tBody);

	// days row
	var tr = document.createElement("tr");
	tr.className = "daysRow";

	var td, tn;

	var nbsp = String.fromCharCode(160);

	for (i = 0; i < cols; i++)
	{
		td = document.createElement("td");
		td.appendChild(document.createTextNode(nbsp));
		tr.appendChild(td);
	}

	tBody.appendChild(tr);

	// upper line
	tr = document.createElement("tr");
	td = document.createElement("td");
	td.className = "upperLine";
	td.colSpan = 7;
	tr.appendChild(td);
	tBody.appendChild(tr);

	// rest
	for (i = 0; i < rows; i++) 
	{
		tr = document.createElement("tr");
		for (var j = 0; j < cols; j++) 
		{
			td = document.createElement("td");
			td.appendChild( document.createTextNode(nbsp));
			tr.appendChild(td);
		}

		tBody.appendChild(tr);
	}

	str += "</table>";

	if (this._table != null) this._table.appendChild(table);
}

// this method updates all the text nodes inside the table as well
// as all the classNames on the tds

/*************************************************************************
 * FP_JS001_PUBLIC_UpdateTable - Update Calendar table
 *************************************************************************/

function FP_JS001_PUBLIC_UpdateTable()
{
	// if no element no need to continue
	if (this._table == null) return;

	var i;
	var str = "";
	var rows = 6;
	var cols = 7;
	var currentWeek = 0;

	var cells = new Array( rows );
	this._matrix = new Array( rows )
	for (i = 0; i < rows; i++)
	{
		cells[i] = new Array(cols);
		this._matrix[i] = new Array(cols);
	}

	// Set the tmpDate to this month
	var tmpDate = new Date(this._selectedDate.getFullYear(), this._selectedDate.getMonth(), 1);
	var today = new Date();
	// go thorugh all days this month and store the text
	// and the class name in the cells matrix
	for (i = 1; i < 32; i++)
	{
		tmpDate.setDate(i);
		// convert to ISO, Monday is 0 and 6 is Sunday
		var weekDay = (tmpDate.getDay() + 6) % 7;
		var colIndex = (weekDay - this._firstWeekDay + 7) % 7;
		if (tmpDate.getMonth() == this._selectedDate.getMonth())
		{
			var isToday = tmpDate.getDate() == today.getDate() && tmpDate.getMonth() == today.getMonth() && tmpDate.getFullYear() == today.getFullYear();

			cells[currentWeek][colIndex] = {text: "", className: ""};

			if (this._selectedDate.getDate() == tmpDate.getDate() && !this._none) cells[currentWeek][colIndex].className += "selected ";
			if (isToday) cells[currentWeek][colIndex].className += "today ";
			if ((tmpDate.getDay() + 6) % 7 == this._redWeekDay) cells[currentWeek][colIndex].className += "red"; // ISO

			cells[currentWeek][colIndex].text = this._matrix[currentWeek][colIndex] = tmpDate.getDate();

			if ( colIndex == 6 ) currentWeek++;
		}
	}

	// fix day letter order if not standard

	var weekDays = FP_JS001_Object.days;
	if (this._firstWeekDay != 0)
	{
		weekDays = new Array(7);
		for (i = 0; i < 7; i++) weekDays[i] = FP_JS001_Object.days[ (i + this._firstWeekDay) % 7];
	}

	// update text in days row
	var tds = this._table.firstChild.tBodies[0].rows[0].cells;
	for (i = 0; i < cols; i++) tds[i].firstChild.data = weekDays[i];

	// update the text nodes and class names
	var trs = this._table.firstChild.tBodies[0].rows;
	var tmpCell;
	var nbsp = String.fromCharCode(160);
	for (var y = 0; y < rows; y++)
	{
		for (var x = 0; x < cols; x++)
		{
			tmpCell = trs[y + 2].cells[x];
			if ( typeof cells[y][x] != "undefined" )
			{
				tmpCell.className = cells[y][x].className;
				tmpCell.firstChild.data = cells[y][x].text;
			}
			else
			{
				tmpCell.className = "";
				tmpCell.firstChild.data = nbsp;
			}
		}
	}
}

/*************************************************************************
 * FP_JS001_PUBLIC_UpdateTable - Set the label showing the year and
 * selected month
 *************************************************************************/

function FP_JS001_PUBLIC_SetTopLabel()
{
	var str = this._selectedDate.getFullYear() + " " + FP_JS001_Object.months[this._selectedDate.getMonth()];
	if (this._topLabel != null) this._topLabel.lastChild.data = str;
}

/*************************************************************************
 * FP_JS001_PUBLIC_GoToNextMonth - Show next Calendar month
 *************************************************************************/

function FP_JS001_PUBLIC_GoToNextMonth()
{
	var objDate = new Date(this._selectedDate);
	var newMonth = objDate.getMonth() + 1;
	objDate.setMonth(newMonth);
	if (newMonth > 11) newMonth = 0;
	if (objDate.getMonth() != newMonth)
	{
		// The day value was greater than the days in the new month forcing a roll-over
		objDate.setDate(0);
	}
	this.setDate(objDate);
}

/*************************************************************************
 * FP_JS001_PUBLIC_GoToPreviousMonth - Show previous Calendar month
 *************************************************************************/

function FP_JS001_PUBLIC_GoToPreviousMonth()
{
	var objDate = new Date(this._selectedDate);
	var newMonth = objDate.getMonth() - 1;
	objDate.setMonth(newMonth);
	if (newMonth < 0) newMonth = 11;
	if (objDate.getMonth() != newMonth)
	{
		// The day value was greater than the days in the new month forcing a roll-over
		objDate.setDate(0);
	}
	this.setDate(objDate);
}
// End of file
