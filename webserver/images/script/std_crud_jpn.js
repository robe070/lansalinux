﻿/////////////////////////////////////////////////////////////////////////////////////////
//
// Assorted CRUD Wizard - Javascript functions
//
//////////////////////////////////////////////////////////////////////////////////////////

// Confirm Delete Action
function ConfirmDelete(Object)
{
  if (confirm(Object + "を削除しますか？") == true)
    return true;
  else
    return false;
}

// Export Grid Data to Excel
function ExportToExcel(tableElement, startColumn, noOfCols)
{
   var tableRows;
   tableRows = document.getElementById(tableElement).rows;
   
   var xlObject = new ActiveXObject("Excel.Application");
   var xlWorkbook = xlObject.Workbooks.Add;
   var xlSheet = xlWorkbook.ActiveSheet;
    
   for (i = 0; i < tableRows.length; i++)
   {
       var tableRow = tableRows[i].cells;
       var k = noOfCols + 1; 
       
       // alert(tableRow[i].cells.style.display);
       {
	       for (j = 1; j < k; j++)
	       {
		  xlObject.Cells(i+1,j).Value = tableRow[j].innerText;
		  xlObject.Cells(i+1,j).EntireColumn.AutoFit();
	       }
	       if (i == 0)
	       {
		  xlObject.ActiveCell.EntireRow.Font.Bold = true;
		  xlObject.ActiveCell.HorizontalAlignment = -4108;            
	       }
	}
   }
     
   xlObject.Visible = true;
   xlObject.UserControl = true;

   return true;
}

function printPage()
{
   self.print();   
}

var currentTab;
function changeTab(objID, tabIDToShow, tabNumber, contentIDToShow, totalTabs) 
{
    if (currentTab == tabNumber) return;

    for (i = 1; i <= totalTabs; i++)
    {
       var currTabObj = (i == currentTab) ? document.getElementById("crud_currentTab") : document.getElementById(objID + i) ;
       currTabObj.id = objID + i;
    }
    
    for (i = 1; i <= totalTabs; i++)
    {
       var currTabObj = document.getElementById(objID + i);
       if (i == tabNumber)
       { currTabObj.id = "crud_currentTab"; document.getElementById(contentIDToShow + i).style.display = "block"; }
       else
       { document.getElementById(contentIDToShow + i).style.display = "none"; }
       
    }
    currentTab = tabNumber;    
}