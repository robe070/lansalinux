<?xml version="1.0" encoding="UTF-8"?><!--(c) 2002, 2012 LANSA--><!--DHTML Menu Script--><!--$Workfile:: std_dhtml_menuscript.xsl $--><!--$UTCDate:: 2012-01-17 22:49:37Z $--><!--$Revision:: 6 $--><xsl:transform version="1.0" exclude-result-prefixes="lxml wd" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design" xmlns="http://www.w3.org/1999/xhtml"><xsl:output method="xml" omit-xml-declaration="yes" encoding="UTF-8" indent="yes"></xsl:output><xsl:template name="std_dhtml_menuscript.private"><script type="text/javascript"><xsl:text disable-output-escaping="yes">
//&lt;![CDATA[
	var AgntUsr=navigator.userAgent.toLowerCase();
	var DomYes=document.getElementById?1:0;
	var NavYes=AgntUsr.indexOf('mozilla')!=-1&amp;&amp;AgntUsr.indexOf('compatible')==-1?1:0;
	var ExpYes=AgntUsr.indexOf('msie')!=-1?1:0;
	var Opr=AgntUsr.indexOf('opera')!=-1?1:0;
	var DomNav=DomYes&amp;&amp;NavYes?1:0;
	var DomExp=DomYes&amp;&amp;ExpYes?1:0;
	var Nav4=NavYes&amp;&amp;!DomYes&amp;&amp;document.layers?1:0;
	var Exp4=ExpYes&amp;&amp;!DomYes&amp;&amp;document.all?1:0;
	var PosStrt=(NavYes||ExpYes)&amp;&amp;!Opr?1:0;

	var FrstLoc,ScLoc,DcLoc;
	var ScWinWdth,ScWinHght,FrstWinWdth,FrstWinHght;
	var ScLdAgainWin;
	var FirstColPos,SecColPos,DocColPos;
	var RcrsLvl=0;
	var FrstCreat=1,Loadd=0,Creatd=0,IniFlg,AcrssFrms=1;
	var FrstCntnr=null,CurrntOvr=null,CloseTmr=null;
	var CntrTxt,TxtClose,ImgStr;
	var Ztop=100;
	var ShwFlg=0;
	var M_StrtTp=WizStartTop;
	var M_StrtLft=WizStartLeft;
	var StaticPos=0;
	var LftXtra=DomNav?WizLeftPaddng:0;
	var TpXtra=DomNav?WizTopPaddng:0;
	var M_Hide=Nav4?'hide':'hidden';
	var M_Show=Nav4?'show':'visible';
	var Par=parent.frames[0]&amp;&amp;WizFirstLineFrame!=WizSecLineFrame?parent:window;
	var Doc=Par.document;
	var Bod=Doc.body;
	var Trigger=NavYes?Par:Bod;

	WizMenuTextCentered=WizMenuTextCentered==1||WizMenuTextCentered=='center'?'center':WizMenuTextCentered==0||WizMenuTextCentered!='right'?'left':'right';
	WbMstrAlrts=["Item not defined: ","Item needs height: ","Item needs width: "];

	if(Trigger.onload)Dummy=Trigger.onload;
	if(DomNav&amp;&amp;!Opr)Trigger.addEventListener('load',Go,false);
	else Trigger.onload=Go;

function Dummy(){return}

function CnclSlct(){return false}

function RePos(){
	FrstWinWdth=ExpYes?FrstLoc.document.body.clientWidth:FrstLoc.innerWidth;
	FrstWinHght=ExpYes?FrstLoc.document.body.clientHeight:FrstLoc.innerHeight;
	ScWinWdth=ExpYes?ScLoc.document.body.clientWidth:ScLoc.innerWidth;
	ScWinHght=ExpYes?ScLoc.document.body.clientHeight:ScLoc.innerHeight;
	if(WizMenuCentered=='justify'&amp;&amp;WizFirstLineHorizontal){
		FrstCntnr.style.width=FrstWinWdth;
		ClcJus();
		var P=FrstCntnr.FrstMbr,W=Menu1[5],i;
		for(i=0;i&lt;WizNoOffFirstLineMenus;i++){P.style.width=W;P=P.PrvMbr}
	}
	StaticPos=-1;
	if(WizTargetLoc)ClcTrgt();
	if(WizMenuCentered)ClcLft();
	if(WizMenuVerticalCentered)ClcTp();
	PosMenu(FrstCntnr,WizStartTop,WizStartLeft)
}

function UnLoaded(){
	if(CloseTmr)clearTimeout(CloseTmr);
	Loadd=0; Creatd=0;
	if(WizHideTop){
		var FCStyle=Nav4?FrstCntnr:FrstCntnr.style;
		FCStyle.visibility=M_Hide;
	}
}

function ReDoWhole(){
	if(ScWinWdth!=ScLoc.innerWidth||ScWinHght!=ScLoc.innerHeight||FrstWinWdth!=FrstLoc.innerWidth||FrstWinHght!=FrstLoc.innerHeight)Doc.location.reload();
}

function Check(WMnu,NoOf){
	var i,array,ArrayLoc;
	ArrayLoc=parent.frames[0]?parent.frames[WizFirstLineFrame]:self;
	for(i=0;i&lt;NoOf;i++){
		array=WMnu+eval(i+1);
		if(!ArrayLoc[array]){WbMstrAlrt(0,array); return false}
		if(i==0){
			if(!ArrayLoc[array][4]){WbMstrAlrt(1,array); return false;}
			if(!ArrayLoc[array][5]){WbMstrAlrt(2,array); return false;}
		}
		if(ArrayLoc[array][3])if(!Check(array+'_',ArrayLoc[array][3])) return false;
	}
	return true;
}

function WbMstrAlrt(No,Xtra){
	return confirm(WbMstrAlrts[No]+Xtra+'   ');
}

function Go(){
 Dummy();
 if(Loadd||!PosStrt)return;
 WizBeforeStart();
 Creatd=0; Loadd=1;
 status='Building menu';
 if(FrstCreat){
  if(WizFirstLineFrame =="" || !parent.frames[WizFirstLineFrame]){
   WizFirstLineFrame=WizSecLineFrame;
   if(WizFirstLineFrame =="" || !parent.frames[WizFirstLineFrame]){
    WizFirstLineFrame=WizSecLineFrame=WizDocTargetFrame;
    if(WizFirstLineFrame =="" || !parent.frames[WizFirstLineFrame])WizFirstLineFrame=WizSecLineFrame=WizDocTargetFrame=''}}
  if(WizSecLineFrame =="" || !parent.frames[WizSecLineFrame]){
   WizSecLineFrame=WizDocTargetFrame;
   if(WizSecLineFrame =="" || !parent.frames[WizSecLineFrame])WizSecLineFrame=WizDocTargetFrame=WizFirstLineFrame}
  if(WizDocTargetFrame =="" || !parent.frames[WizDocTargetFrame])WizDocTargetFrame=WizSecLineFrame;
  if(WizWebMasterCheck){ if(!Check('Menu',WizNoOffFirstLineMenus)){status='build aborted';return}}
  FrstLoc=WizFirstLineFrame!=""?parent.frames[WizFirstLineFrame]:window;
  ScLoc=WizSecLineFrame!=""?parent.frames[WizSecLineFrame]:window;
  DcLoc=WizDocTargetFrame!=""?parent.frames[WizDocTargetFrame]:window;
  if (FrstLoc==ScLoc) AcrssFrms=0;
  if (AcrssFrms)WizFirstLineHorizontal=WizMenuFramesVertical?0:1;
  FrstWinWdth=ExpYes?FrstLoc.document.body.clientWidth:FrstLoc.innerWidth;
  FrstWinHght=ExpYes?FrstLoc.document.body.clientHeight:FrstLoc.innerHeight;
  ScWinWdth=ExpYes?ScLoc.document.body.clientWidth:ScLoc.innerWidth;
  ScWinHght=ExpYes?ScLoc.document.body.clientHeight:ScLoc.innerHeight;
  if(Nav4){ CntrTxt=WizMenuTextCentered!='left'?"&lt;div align='"+WizMenuTextCentered+"'&gt;":"";
   TxtClose="&lt;/font&gt;"+WizMenuTextCentered!='left'?"&lt;/div&gt;":""}}
 FirstColPos=Nav4?FrstLoc.document:FrstLoc.document.body;
 SecColPos=Nav4?ScLoc.document:ScLoc.document.body;
 DocColPos=Nav4?DcLoc.document:ScLoc.document.body;
 if (WizTakeOverBgColor)FirstColPos.bgColor=AcrssFrms?SecColPos.bgColor:DocColPos.bgColor;
 if(WizMenuCentered=='justify'&amp;&amp;WizFirstLineHorizontal)ClcJus();
 if(FrstCreat){
  FrstCntnr=CreateMenuStructure('Menu',WizNoOffFirstLineMenus);
  FrstCreat=AcrssFrms?0:1}
 else CreateMenuStructureAgain('Menu',WizNoOffFirstLineMenus);
 if(WizTargetLoc)ClcTrgt();
 if(WizMenuCentered)ClcLft();
 if(WizMenuVerticalCentered)ClcTp();
 PosMenu(FrstCntnr,WizStartTop,WizStartLeft);
 IniFlg=1;
 Initiate();
 Creatd=1;
 ScLdAgainWin=ExpYes?ScLoc.document.body:ScLoc;
 ScLdAgainWin.onunload=UnLoaded;
 Trigger.onresize=Nav4?ReDoWhole:RePos;
 WizAfterBuild();
 if(WizMenuVerticalCentered=='static'&amp;&amp;!AcrssFrms)setInterval('KeepPos()',250);
 status='Menu ready for use'}

function KeepPos(){
 var TS=ExpYes?FrstLoc.document.body.scrollTop:FrstLoc.pageYOffset;
 if(TS!=StaticPos){
  var FCStyle=Nav4?FrstCntnr:FrstCntnr.style;
  FCStyle.top=FrstCntnr.OrgTop=WizStartTop+TS;StaticPos=TS}}

function ClcJus(){
 var a=WizBorderBtwnElmnts?1:2,b=WizBorderBtwnElmnts?WizBorderWidth:0;
 var Size=Math.round(((FrstWinWdth-a*WizBorderWidth)/WizNoOffFirstLineMenus)-b),i,j;
 for(i=1;i&lt;WizNoOffFirstLineMenus+1;i++){j=eval('Menu'+i);j[5]=Size}
 WizStartLeft=0}

function ClcTrgt(){
 var TLoc=Nav4?FrstLoc.document.layers[WizTargetLoc]:DomYes?FrstLoc.document.getElementById(WizTargetLoc):FrstLoc.document.all[WizTargetLoc];
 WizStartTop=M_StrtTp;
 WizStartLeft=M_StrtLft;
 if(DomYes){
  while(TLoc){WizStartTop+=TLoc.offsetTop;WizStartLeft+=TLoc.offsetLeft;TLoc=TLoc.offsetParent}}
 else{ WizStartTop+=Nav4?TLoc.pageY:TLoc.offsetTop;WizStartLeft+=Nav4?TLoc.pageX:TLoc.offsetLeft}}

function ClcLft(){
 if(WizMenuCentered!='left'&amp;&amp;WizMenuCentered!='justify'){
  var Size=FrstWinWdth-(!Nav4?parseInt(FrstCntnr.style.width):FrstCntnr.clip.width);
  WizStartLeft=M_StrtLft;
  WizStartLeft+=WizMenuCentered=='right'?Size:Size/2}}

function ClcTp(){
 if(WizMenuVerticalCentered!='top'&amp;&amp;WizMenuVerticalCentered!='static'){
  var Size=FrstWinHght-(!Nav4?parseInt(FrstCntnr.style.height):FrstCntnr.clip.height);
  WizStartTop=M_StrtTp;
  WizStartTop+=WizMenuVerticalCentered=='bottom'?Size:Size/2}}

function PosMenu(CntnrPntr,Tp,Lt){
 var Topi,Lefti,Hori;
 var Cntnr=CntnrPntr;
 var Mmbr=Cntnr.FrstMbr;
 var CntnrStyle=!Nav4?Cntnr.style:Cntnr;
 var MmbrStyle=!Nav4?Mmbr.style:Mmbr;
 var PadL=Mmbr.value.indexOf('&lt;')==-1?LftXtra:0;
 var PadT=Mmbr.value.indexOf('&lt;')==-1?TpXtra:0;
 var MmbrWt=!Nav4?parseInt(MmbrStyle.width)+PadL:MmbrStyle.clip.width;
 var MmbrHt=!Nav4?parseInt(MmbrStyle.height)+PadT:MmbrStyle.clip.height;
 var CntnrWt=!Nav4?parseInt(CntnrStyle.width):CntnrStyle.clip.width;
 var CntnrHt=!Nav4?parseInt(CntnrStyle.height):CntnrStyle.clip.height;
 var SubTp,SubLt;
 RcrsLvl++;
 if (RcrsLvl==1 &amp;&amp; AcrssFrms)!WizMenuFramesVertical?Tp=FrstWinHght-CntnrHt+(Nav4?4:0):Lt=WizRightToLeft?0:FrstWinWdth-CntnrWt+(Nav4?4:0);
 if (RcrsLvl==2 &amp;&amp; AcrssFrms)!WizMenuFramesVertical?Tp=0:Lt=WizRightToLeft?ScWinWdth-CntnrWt:0;
 if (RcrsLvl==2 &amp;&amp; AcrssFrms){Tp+=WizVerCorrect;Lt+=WizHorCorrect}
 CntnrStyle.top=RcrsLvl==1?Tp:0;
 Cntnr.OrgTop=Tp;
 CntnrStyle.left=RcrsLvl==1?Lt:0;
 Cntnr.OrgLeft=Lt;
 if (RcrsLvl==1 &amp;&amp; WizFirstLineHorizontal){
  Hori=1;Lefti=CntnrWt-MmbrWt-2*WizBorderWidth;Topi=0}
 else{ Hori=Lefti=0;Topi=CntnrHt-MmbrHt-2*WizBorderWidth}
 while(Mmbr!=null){
  MmbrStyle.left=Lefti+WizBorderWidth;
  MmbrStyle.top=Topi+WizBorderWidth;
  if(Nav4)Mmbr.CmdLyr.moveTo(Lefti+WizBorderWidth,Topi+WizBorderWidth);
  if(Mmbr.ChildCntnr){
   if(WizRightToLeft)ChldCntnrWdth=Nav4?Mmbr.ChildCntnr.clip.width:parseInt(Mmbr.ChildCntnr.style.width);
   if(Hori){ SubTp=Topi+MmbrHt+2*WizBorderWidth;
    SubLt=WizRightToLeft?Lefti+MmbrWt-ChldCntnrWdth:Lefti}
   else{ SubLt=WizRightToLeft?Lefti-ChldCntnrWdth+WizChildOverlap*MmbrWt+WizBorderWidth:Lefti+(1-WizChildOverlap)*MmbrWt+WizBorderWidth;
    SubTp=RcrsLvl==1&amp;&amp;AcrssFrms?Topi:Topi+WizChildVerticalOverlap*MmbrHt}
   PosMenu(Mmbr.ChildCntnr,SubTp,SubLt)}
  Mmbr=Mmbr.PrvMbr;
  if(Mmbr){ MmbrStyle=!Nav4?Mmbr.style:Mmbr;
   PadL=Mmbr.value.indexOf('&lt;')==-1?LftXtra:0;
   PadT=Mmbr.value.indexOf('&lt;')==-1?TpXtra:0;
   MmbrWt=!Nav4?parseInt(MmbrStyle.width)+PadL:MmbrStyle.clip.width;
   MmbrHt=!Nav4?parseInt(MmbrStyle.height)+PadT:MmbrStyle.clip.height;
   Hori?Lefti-=WizBorderBtwnElmnts?(MmbrWt+WizBorderWidth):(MmbrWt):Topi-=WizBorderBtwnElmnts?(MmbrHt+WizBorderWidth):(MmbrHt)}}
 RcrsLvl--}

function Initiate(){
 if(IniFlg){ Init(FrstCntnr);IniFlg=0;
  if(ShwFlg)WizAfterCloseAll();ShwFlg=0}}

function Init(CntnrPntr){
 var Mmbr=CntnrPntr.FrstMbr;
 var MCStyle=Nav4?CntnrPntr:CntnrPntr.style;
 RcrsLvl++;
 MCStyle.visibility=RcrsLvl==1?M_Show:M_Hide;
 while(Mmbr!=null){
  if(Mmbr.Hilite){Mmbr.Hilite=0;if(WizKeepHilite)LowItem(Mmbr)}
  if(Mmbr.ChildCntnr) Init(Mmbr.ChildCntnr);
  Mmbr=Mmbr.PrvMbr}
 RcrsLvl--}

function ClearAllChilds(Pntr){
	var CPCCStyle;
	while (Pntr){
		if(Pntr.Hilite){
			Pntr.Hilite=0;
			if(WizKeepHilite)LowItem(Pntr);
			if(Pntr.ChildCntnr){
				CPCCStyle=Nav4?Pntr.ChildCntnr:Pntr.ChildCntnr.style;
				CPCCStyle.visibility=M_Hide;
				ClearAllChilds(Pntr.ChildCntnr.FrstMbr)
			}
			break;
		}
		Pntr=Pntr.PrvMbr;
	}
}

function GoTo(){
 if(this.LinkTxt){
  status='';
  var HP=Nav4?this.LowLyr:this;
  LowItem(HP);
  this.LinkTxt.indexOf('javascript:')!=-1?eval(this.LinkTxt):DcLoc.location.href=this.LinkTxt}}

function HiliteItem(P){
 if(Nav4){
  if(P.ro)P.document.images[P.rid].src=P.ri2;
  else{ if(P.HiBck)P.bgColor=P.HiBck;
   if(P.value.indexOf('&lt;img')==-1){
    P.document.write(P.Ovalue);
    P.document.close()}}}
 else{ if(P.ro){ var Lc=P.Level==1?FrstLoc:ScLoc;
   Lc.document.images[P.rid].src=P.ri2}
  else{ if(P.HiBck)P.style.backgroundColor=P.HiBck;
   if(P.HiFntClr)P.style.color=P.HiFntClr}}
 P.Hilite=1}

function LowItem(P){
 if(P.ro){ if(Nav4)P.document.images[P.rid].src=P.ri1;
  else{ var Lc=P.Level==1?FrstLoc:ScLoc;
   Lc.document.images[P.rid].src=P.ri1}}
 else{ if(Nav4){ if(P.LoBck)P.bgColor=P.LoBck;
   if(P.value.indexOf('&lt;img')==-1){
    P.document.write(P.value);
    P.document.close()}}
  else{ if(P.LoBck)P.style.backgroundColor=P.LoBck;
   if(P.LwFntClr)P.style.color=P.LwFntClr}}}

function OpenMenu(){ 
 if(!Loadd||!Creatd) return;
 var TpScrlld=ExpYes?ScLoc.document.body.scrollTop:ScLoc.pageYOffset;
 var LScrlld=ExpYes?ScLoc.document.body.scrollLeft:ScLoc.pageXOffset;
 var CCnt=Nav4?this.LowLyr.ChildCntnr:this.ChildCntnr;
 var ThisHt=Nav4?this.clip.height:parseInt(this.style.height);
 var ThisWt=Nav4?this.clip.width:parseInt(this.style.width);
 var ThisLft=AcrssFrms&amp;&amp;this.Level==1&amp;&amp;!WizFirstLineHorizontal?0:Nav4?this.Container.left:parseInt(this.Container.style.left);
 var ThisTp=AcrssFrms&amp;&amp;this.Level==1&amp;&amp;WizFirstLineHorizontal?0:Nav4?this.Container.top:parseInt(this.Container.style.top);
 var HP=Nav4?this.LowLyr:this;
 CurrntOvr=this;
 IniFlg=0;
 ClearAllChilds(this.Container.FrstMbr);
 HiliteItem(HP);
 if(CCnt!=null){
  if(!ShwFlg){ShwFlg=1; WizBeforeFirstOpen()}
  var CCW=Nav4?this.LowLyr.ChildCntnr.clip.width:parseInt(this.ChildCntnr.style.width);
  var CCH=Nav4?this.LowLyr.ChildCntnr.clip.height:parseInt(this.ChildCntnr.style.height);
  var ChCntTL=Nav4?this.LowLyr.ChildCntnr:this.ChildCntnr.style;
  var SubLt=AcrssFrms&amp;&amp;this.Level==1?CCnt.OrgLeft+ThisLft+LScrlld:CCnt.OrgLeft+ThisLft;
  var SubTp=AcrssFrms&amp;&amp;this.Level==1?CCnt.OrgTop+ThisTp+TpScrlld:CCnt.OrgTop+ThisTp;
  if(WizMenuWrap){
   if(WizRightToLeft){
    if(SubLt&lt;LScrlld)SubLt=this.Level==1?LScrlld:SubLt+(CCW+(1-2*WizChildOverlap)*ThisWt);
    if(SubLt+CCW&gt;ScWinWdth+LScrlld)SubLt=ScWinWdth+LScrlld-CCW}
   else{ if(SubLt+CCW&gt;ScWinWdth+LScrlld)SubLt=this.Level==1?ScWinWdth+LScrlld-CCW:SubLt-(CCW+(1-2*WizChildOverlap)*ThisWt);
    if(SubLt&lt;LScrlld)SubLt=LScrlld}
   if(SubTp+CCH&gt;TpScrlld+ScWinHght)SubTp=this.Level==1?SubTp=TpScrlld+ScWinHght-CCH:SubTp-CCH+(1-2*WizChildVerticalOverlap)*ThisHt;
   if(SubTp&lt;TpScrlld)SubTp=TpScrlld}
  ChCntTL.top=SubTp;ChCntTL.left=SubLt;ChCntTL.visibility=M_Show}
 status=this.LinkTxt}

function OpenMenuClick(){
 if(!Loadd||!Creatd) return;
 var HP=Nav4?this.LowLyr:this;
 CurrntOvr=this;
 IniFlg=0;
 ClearAllChilds(this.Container.FrstMbr);
 HiliteItem(HP);
 status=this.LinkTxt}

function CloseMenu(){
 if(!Loadd||!Creatd) return;
 if(!WizKeepHilite){
  var HP=Nav4?this.LowLyr:this;
  LowItem(HP)}
 status='';
 if(this==CurrntOvr){
  IniFlg=1;
  if(CloseTmr)clearTimeout(CloseTmr);
  CloseTmr=setTimeout('Initiate(CurrntOvr)',WizDisappearDelay)}}

function CntnrSetUp(Wdth,Hght,NoOff){
 var x=RcrsLvl==1?WizBorderColor:WizBorderSubColor;
 this.FrstMbr=null;
 this.OrgLeft=this.OrgTop=0;
 if(x)this.bgColor=x;
 if(Nav4){ this.visibility='hide';
  this.resizeTo(Wdth,Hght)}
 else{ if(x)this.style.backgroundColor=x;
  this.style.width=Wdth;
  this.style.height=Hght;
  this.style.fontFamily=WizFontFamily;
  this.style.fontWeight=WizFontBold?'bold':'normal';
  this.style.fontStyle=WizFontItalic?'italic':'normal';
  this.style.fontSize=WizFontSize+'pt';
  this.style.zIndex=RcrsLvl+Ztop}}

function MbrSetUp(MmbrCntnr,PrMmbr,WhatMenu,Wdth,Hght){
 var Location=RcrsLvl==1?FrstLoc:ScLoc;
 var MemVal=eval(WhatMenu+'[0]');
 var t,T,L,W,H,S;
 var a,b,c,d;
 this.PrvMbr=PrMmbr;
 this.Level=RcrsLvl;
 this.LinkTxt=eval(WhatMenu+'[1]');
 this.Container=MmbrCntnr;
 this.ChildCntnr=null;
 this.Hilite=0;
 this.style.overflow='hidden';
 this.style.cursor=ExpYes&amp;&amp;(this.LinkTxt||(RcrsLvl==1&amp;&amp;WizUnfoldsOnClick))?'hand':'default';
 this.ro=0;
 if(MemVal.indexOf('rollover')!=-1){
  this.ro=1;
  this.ri1=MemVal.substring(MemVal.indexOf(':')+1,MemVal.lastIndexOf(':'));
  this.ri2=MemVal.substring(MemVal.lastIndexOf(':')+1,MemVal.length);
  this.rid=WhatMenu+'i';MemVal="&lt;img src='"+this.ri1+"' name='"+this.rid+"'&gt;"}
 this.value=MemVal;
 if(RcrsLvl==1){
  a=WizLowBgColor;
  b=WizHighBgColor;
  c=WizFontLowColor;
  d=WizFontHighColor}
 else{ a=WizLowSubBgColor;
  b=WizHighSubBgColor;
  c=WizFontSubLowColor;
  d=WizFontSubHighColor}
 this.LoBck=a;
 this.LwFntClr=c;
 this.HiBck=b;
 this.HiFntClr=d;
 this.style.color=this.LwFntClr;
 if(this.LoBck)this.style.backgroundColor=this.LoBck;
 this.style.textAlign=WizMenuTextCentered;
 if(eval(WhatMenu+'[2]'))this.style.backgroundImage="url('"+eval(WhatMenu+'[2]')+"')";
 if(MemVal.indexOf('&lt;')==-1){
  this.style.width=Wdth-LftXtra;
  this.style.height=Hght-TpXtra;
  this.style.paddingLeft=WizLeftPaddng;
  this.style.paddingTop=WizTopPaddng}
 else{ this.style.width=Wdth;
  this.style.height=Hght}
 if(MemVal.indexOf('&lt;')==-1&amp;&amp;DomYes){
  t=Location.document.createTextNode(MemVal);
  this.appendChild(t)}
 else this.innerHTML=MemVal;
 if(eval(WhatMenu+'[3]')&amp;&amp;WizShowArrow){
  a=RcrsLvl==1&amp;&amp;WizFirstLineHorizontal?3:WizRightToLeft?6:0;
  S=WizArrws[a];
  W=WizArrws[a+1];
  H=WizArrws[a+2];
  T=RcrsLvl==1&amp;&amp;WizFirstLineHorizontal?Hght-H-2:(Hght-H)/2;
  L=WizRightToLeft?2:Wdth-W-2;
  if(DomYes){
   t=Location.document.createElement('img');
   this.appendChild(t);
   t.style.position='absolute';
   t.src=S;
   t.style.width=W;
   t.style.height=H;
   t.style.top=T;
   t.style.left=L}
  else{ MemVal+="&lt;div style='position:absolute; top:"+T+"; left:"+L+"; width:"+W+"; height:"+H+";visibility:inherit'&gt;&lt;img src='"+S+"'&gt;&lt;/div&gt;";
   this.innerHTML=MemVal}}
 if(ExpYes){this.onselectstart=CnclSlct;
  this.onmouseover=RcrsLvl==1&amp;&amp;WizUnfoldsOnClick?OpenMenuClick:OpenMenu;
  this.onmouseout=CloseMenu;
  this.onclick=RcrsLvl==1&amp;&amp;WizUnfoldsOnClick&amp;&amp;eval(WhatMenu+'[3]')?OpenMenu:GoTo }
 else{ RcrsLvl==1&amp;&amp;WizUnfoldsOnClick?this.addEventListener('mouseover',OpenMenuClick,false):this.addEventListener('mouseover',OpenMenu,false);
  this.addEventListener('mouseout',CloseMenu,false);
  RcrsLvl==1&amp;&amp;WizUnfoldsOnClick&amp;&amp;eval(WhatMenu+'[3]')?this.addEventListener('click',OpenMenu,false):this.addEventListener('click',GoTo,false)}}

function NavMbrSetUp(MmbrCntnr,PrMmbr,WhatMenu,Wdth,Hght){
 var a,b,c,d;
 if(RcrsLvl==1){
  a=WizLowBgColor;
  b=WizHighBgColor;
  c=WizFontLowColor;
  d=WizFontHighColor}
 else { a=WizLowSubBgColor;
  b=WizHighSubBgColor;
  c=WizFontSubLowColor;
  d=WizFontSubHighColor }
 this.value=eval(WhatMenu+'[0]');
 this.ro=0;
 if(this.value.indexOf('rollover')!=-1){
  this.ro=1;
  this.ri1=this.value.substring(this.value.indexOf(':')+1,this.value.lastIndexOf(':'));
  this.ri2=this.value.substring(this.value.lastIndexOf(':')+1,this.value.length);
  this.rid=WhatMenu+'i';this.value="&lt;img src='"+this.ri1+"' name='"+this.rid+"'&gt;"}
 if(WizLeftPaddng&amp;&amp;this.value.indexOf('&lt;')==-1&amp;&amp;WizMenuTextCentered=='left')this.value=' ;'+this.value;
 if(WizFontBold)this.value=this.value.bold();
 if(WizFontItalic)this.value=this.value.italics();
 this.Ovalue=this.value;
 this.value=this.value.fontcolor(c);
 this.Ovalue=this.Ovalue.fontcolor(d);
 this.value=CntrTxt+"&lt;font face='"+WizFontFamily+"' point-size='"+WizFontSize+"'&gt;"+this.value+TxtClose;
 this.Ovalue=CntrTxt+"&lt;font face='"+WizFontFamily+"' point-size='"+WizFontSize+"'&gt;"+this.Ovalue+TxtClose;
 this.LoBck=a;
 this.HiBck=b;
 this.ChildCntnr=null;
 this.PrvMbr=PrMmbr;
 this.Hilite=0;
 this.visibility='inherit';
 if(this.LoBck)this.bgColor=this.LoBck;
 this.resizeTo(Wdth,Hght);
 if(!AcrssFrms&amp;&amp;eval(WhatMenu+'[2]'))this.background.src=eval(WhatMenu+'[2]');
 this.document.write(this.value);
 this.document.close();
 this.CmdLyr=new Layer(Wdth,MmbrCntnr);
 this.CmdLyr.Level=RcrsLvl;
 this.CmdLyr.LinkTxt=eval(WhatMenu+'[1]');
 this.CmdLyr.visibility='inherit';
 this.CmdLyr.onmouseover=RcrsLvl==1&amp;&amp;WizUnfoldsOnClick?OpenMenuClick:OpenMenu;
 this.CmdLyr.onmouseout=CloseMenu;
 this.CmdLyr.captureEvents(Event.MOUSEUP);
 this.CmdLyr.onmouseup=RcrsLvl==1&amp;&amp;WizUnfoldsOnClick&amp;&amp;eval(WhatMenu+'[3]')?OpenMenu:GoTo;
 this.CmdLyr.LowLyr=this;
 this.CmdLyr.resizeTo(Wdth,Hght);
 this.CmdLyr.Container=MmbrCntnr;
 if(eval(WhatMenu+'[3]')&amp;&amp;WizShowArrow){
  a=RcrsLvl==1&amp;&amp;WizFirstLineHorizontal?3:WizRightToLeft?6:0;
  this.CmdLyr.ImgLyr=new Layer(WizArrws[a+1],this.CmdLyr);
  this.CmdLyr.ImgLyr.visibility='inherit';
  this.CmdLyr.ImgLyr.top=RcrsLvl==1&amp;&amp;WizFirstLineHorizontal?Hght-WizArrws[a+2]-2:(Hght-WizArrws[a+2])/2;
  this.CmdLyr.ImgLyr.left=WizRightToLeft?2:Wdth-WizArrws[a+1]-2;
  this.CmdLyr.ImgLyr.width=WizArrws[a+1];
  this.CmdLyr.ImgLyr.height=WizArrws[a+2];
  ImgStr="&lt;img src='"+WizArrws[a]+"' width='"+WizArrws[a+1]+"' height='"+WizArrws[a+2]+"'&gt;";
  this.CmdLyr.ImgLyr.document.write(ImgStr);
  this.CmdLyr.ImgLyr.document.close()}}

function CreateMenuStructure(MName,NumberOf){
 RcrsLvl++;
 var i,NoOffSubs,Mbr,Wdth=0,Hght=0;
 var PrvMmbr=null;
 var WMnu=MName+'1';
 var MenuWidth=eval(WMnu+'[5]');
 var MenuHeight=eval(WMnu+'[4]');
 var Location=RcrsLvl==1?FrstLoc:ScLoc;
 if (RcrsLvl==1&amp;&amp;WizFirstLineHorizontal){
  for(i=1;i&lt;NumberOf+1;i++){
   WMnu=MName+eval(i);
   Wdth=eval(WMnu+'[5]')?Wdth+eval(WMnu+'[5]'):Wdth+MenuWidth}
  Wdth=WizBorderBtwnElmnts?Wdth+(NumberOf+1)*WizBorderWidth:Wdth+2*WizBorderWidth;Hght=MenuHeight+2*WizBorderWidth}
 else{ for(i=1;i&lt;NumberOf+1;i++){
   WMnu=MName+eval(i);
   Hght=eval(WMnu+'[4]')?Hght+eval(WMnu+'[4]'):Hght+MenuHeight}
  Hght=WizBorderBtwnElmnts?Hght+(NumberOf+1)*WizBorderWidth:Hght+2*WizBorderWidth;Wdth=MenuWidth+2*WizBorderWidth}
 if(DomYes){
  var MmbrCntnr=Location.document.createElement("div");
  MmbrCntnr.style.position='absolute';
  MmbrCntnr.style.visibility='hidden';
  Location.document.body.appendChild(MmbrCntnr)}
 else{ if(Nav4) var MmbrCntnr=new Layer(Wdth,Location)
  else{ WMnu+='c';
   Location.document.body.insertAdjacentHTML("AfterBegin","&lt;div id='"+WMnu+"' style='visibility:hidden; position:absolute;'&gt;&lt;/div&gt;");
   var MmbrCntnr=Location.document.all[WMnu]}}
 MmbrCntnr.SetUp=CntnrSetUp;
 MmbrCntnr.SetUp(Wdth,Hght,NumberOf);
 if(Exp4){ MmbrCntnr.InnerString='';
  for(i=1;i&lt;NumberOf+1;i++){
   WMnu=MName+eval(i);
   MmbrCntnr.InnerString+="&lt;div id='"+WMnu+"' style='position:absolute;'&gt;&lt;/div&gt;"}
  MmbrCntnr.innerHTML=MmbrCntnr.InnerString}
 for(i=1;i&lt;NumberOf+1;i++){
  WMnu=MName+eval(i);
  NoOffSubs=eval(WMnu+'[3]');
  Wdth=RcrsLvl==1&amp;&amp;WizFirstLineHorizontal?eval(WMnu+'[5]')?eval(WMnu+'[5]'):MenuWidth:MenuWidth;
  Hght=RcrsLvl==1&amp;&amp;WizFirstLineHorizontal?MenuHeight:eval(WMnu+'[4]')?eval(WMnu+'[4]'):MenuHeight;
  if(DomYes){
   Mbr=Location.document.createElement("div");
   Mbr.style.position='absolute';
   Mbr.style.visibility='inherit';
   MmbrCntnr.appendChild(Mbr)}
  else Mbr=Nav4?new Layer(Wdth,MmbrCntnr):Location.document.all[WMnu];
  Mbr.SetUp=Nav4?NavMbrSetUp:MbrSetUp;
  Mbr.SetUp(MmbrCntnr,PrvMmbr,WMnu,Wdth,Hght);
  if(NoOffSubs) Mbr.ChildCntnr=CreateMenuStructure(WMnu+'_',NoOffSubs);
  PrvMmbr=Mbr}
 MmbrCntnr.FrstMbr=Mbr;
 RcrsLvl--;
 return(MmbrCntnr)}

function CreateMenuStructureAgain(MName,NumberOf){
 var i,WMnu,NoOffSubs,PrvMmbr,Mbr=FrstCntnr.FrstMbr;
 RcrsLvl++;
 for(i=NumberOf;i&gt;0;i--){
  WMnu=MName+eval(i);
  NoOffSubs=eval(WMnu+'[3]');
  PrvMmbr=Mbr;
  if(NoOffSubs)Mbr.ChildCntnr=CreateMenuStructure(WMnu+'_',NoOffSubs);
  Mbr=Mbr.PrvMbr}
 RcrsLvl--}
//]]&gt;
</xsl:text><xsl:text>&#32;</xsl:text></script></xsl:template></xsl:transform>