<?xml version="1.0" encoding="UTF-8"?><!--(c) 2002, 2012 LANSA--><!--XHTML Dynamic HTML Menu--><!--$Workfile:: std_dhtml_menu.xsl $--><!--$UTCDate:: 2012-12-21 02:13:48Z $--><!--$Revision:: 5 $--><xsl:transform version="1.0" exclude-result-prefixes="lxml wd exslt" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design" xmlns:msxsl="urn:schemas-microsoft-com:xslt" xmlns:exslt="http://exslt.org/common" xmlns="http://www.w3.org/1999/xhtml"><xsl:import href="std_keys.xsl"></xsl:import><xsl:import href="std_util.xsl"></xsl:import><xsl:import href="std_variables.xsl"></xsl:import><xsl:import href="std_dhtml_menuscript.xsl"></xsl:import><xsl:output method="xml" omit-xml-declaration="yes" encoding="UTF-8" indent="yes"></xsl:output><lxml:data><lxml:menu><lxml:font size="9" bold="true" italic="false"></lxml:font><lxml:item><lxml:caption>Sample Item 1</lxml:caption><lxml:action>www.lansa.com</lxml:action><lxml:background></lxml:background><lxml:height>20</lxml:height><lxml:width>150</lxml:width><lxml:item><lxml:caption>Sample SubItem 1</lxml:caption><lxml:action>www.lansa.com</lxml:action><lxml:background></lxml:background><lxml:height>20</lxml:height><lxml:width>150</lxml:width></lxml:item><lxml:item><lxml:caption>Sample SubItem 2</lxml:caption><lxml:action>www.lansa.com</lxml:action><lxml:background></lxml:background><lxml:height>20</lxml:height><lxml:width>150</lxml:width></lxml:item></lxml:item><lxml:item><lxml:caption>Sample Item 2</lxml:caption><lxml:action>www.lansa.com</lxml:action><lxml:background></lxml:background><lxml:height>20</lxml:height><lxml:width>150</lxml:width><lxml:item><lxml:caption>Sample SubItem 2</lxml:caption><lxml:action>www.lansa.com</lxml:action><lxml:background></lxml:background><lxml:height>20</lxml:height><lxml:width>150</lxml:width></lxml:item></lxml:item><lxml:item><lxml:caption>Sample Item 3</lxml:caption><lxml:action>www.lansa.com</lxml:action><lxml:background></lxml:background><lxml:height>20</lxml:height><lxml:width>150</lxml:width><lxml:item><lxml:caption>Sample SubItem 3</lxml:caption><lxml:action>www.lansa.com</lxml:action><lxml:background></lxml:background><lxml:height>20</lxml:height><lxml:width>150</lxml:width></lxml:item></lxml:item></lxml:menu></lxml:data><xsl:template name="menu"><xsl:param name="menu_items" select="document('')/*/lxml:data/lxml:menu"></xsl:param><xsl:param name="orientation" select="'top'"></xsl:param><xsl:param name="height"></xsl:param><xsl:param name="width"></xsl:param><xsl:variable name="menu_items_frag"><xsl:call-template name="expand_mtxt_in_xml_items.private"><xsl:with-param name="items" select="$menu_items"></xsl:with-param></xsl:call-template></xsl:variable><xsl:choose><xsl:when test="$lweb_is_msxsl_nodeset"><xsl:call-template name="std_dhtml_menu.private"><xsl:with-param name="width" select="$width"></xsl:with-param><xsl:with-param name="height" select="$height"></xsl:with-param><xsl:with-param name="orientation" select="$orientation"></xsl:with-param><xsl:with-param name="menu_items" select="$menu_items"></xsl:with-param><xsl:with-param name="items" select="msxsl:node-set($menu_items_frag)/*"></xsl:with-param></xsl:call-template></xsl:when><xsl:when test="$lweb_is_exslt_nodeset"><xsl:call-template name="std_dhtml_menu.private"><xsl:with-param name="width" select="$width"></xsl:with-param><xsl:with-param name="height" select="$height"></xsl:with-param><xsl:with-param name="orientation" select="$orientation"></xsl:with-param><xsl:with-param name="menu_items" select="$menu_items"></xsl:with-param><xsl:with-param name="items" select="exslt:node-set($menu_items_frag)/*"></xsl:with-param></xsl:call-template></xsl:when></xsl:choose></xsl:template><xsl:template name="std_dhtml_menu.private"><xsl:param name="menu_items"></xsl:param><xsl:param name="items"></xsl:param><xsl:param name="orientation"></xsl:param><xsl:param name="height"></xsl:param><xsl:param name="width"></xsl:param><div id="{generate-id($items)}" class="hidden__"><xsl:call-template name="std_dhtml_menu_spantext.private"><xsl:with-param name="items" select="$items"></xsl:with-param></xsl:call-template><xsl:comment /></div><table id="MenuTable"><tbody><tr><td><xsl:variable name="menu-height"><xsl:choose><xsl:when test="string-length($height) != 0"><xsl:value-of select="$height"></xsl:value-of></xsl:when><xsl:otherwise><xsl:choose><xsl:when test="$orientation = 'top'"><xsl:call-template name="max-menu-height.private"><xsl:with-param name="items" select="$items"></xsl:with-param><xsl:with-param name="height">0</xsl:with-param></xsl:call-template></xsl:when><xsl:otherwise><xsl:call-template name="sum-height.private"><xsl:with-param name="this-node" select="$items/lxml:item[1]"></xsl:with-param><xsl:with-param name="height" select="$items/lxml:item[1]/lxml:height"></xsl:with-param></xsl:call-template></xsl:otherwise></xsl:choose></xsl:otherwise></xsl:choose></xsl:variable><xsl:variable name="menu-width"><xsl:choose><xsl:when test="string-length($width) != 0"><xsl:value-of select="$width"></xsl:value-of></xsl:when><xsl:otherwise><xsl:call-template name="max-menu-width.private"><xsl:with-param name="items" select="$items"></xsl:with-param><xsl:with-param name="width">0</xsl:with-param></xsl:call-template></xsl:otherwise></xsl:choose></xsl:variable><div id="MenuPos" style="width: 100%; position: relative; height: 100%"><xsl:choose><xsl:when test="$lweb_design_mode and $orientation != 'top'"><div style="font-weight: bold; font-size: 9pt; z-index: 101; left: 173px; visibility: visible; width: 152px; font-style: normal; top: 138px; height: 64px" bgcolor="black" orgtop="138" orgleft="173"><xsl:attribute name="style"><xsl:if test="$items/lxml:font/@bold = 'true'"><xsl:text>font-weight:bold;</xsl:text></xsl:if><xsl:if test="$items/lxml:font/@italic = 'true'"><xsl:text>font-style:italic;</xsl:text></xsl:if><xsl:if test="$items/lxml:font/@size"><xsl:text>font-size:</xsl:text><xsl:value-of select="$items/lxml:font/@size"></xsl:value-of><xsl:text>pt;</xsl:text></xsl:if><xsl:text>z-index: 101; left: 173px; visibility: visible; width: 152px; top: 138px; height: 64px</xsl:text></xsl:attribute><xsl:for-each select="$items/lxml:item"><div style="padding-left: 3px; left: 1px; visibility: inherit; overflow: hidden; width: 150px; cursor: hand; color: black; padding-top: 2px; top: 1px; height: 20px; background-color: white; text-align: left" value="Sample Item 1" ro="0" hifntclr="white" hibck="black" lwfntclr="black" lobck="white" hilite="0" linktxt="www.lansa.com" level="1" prvmbr="null"><xsl:if test="lxml:item and $orientation != 'left'"><img style="left: 0px; width: 5px; top: 5px; height: 10px" src="{$lweb_images_path}/wiztrileft.gif" /></xsl:if><xsl:value-of select="lxml:caption"></xsl:value-of><xsl:if test="lxml:item and $orientation = 'left'"><img style="left: 143px; width: 5px; top: 5px; height: 10px" src="{$lweb_images_path}/wiztri.gif" /></xsl:if><xsl:comment /></div></xsl:for-each><xsl:comment /></div></xsl:when><xsl:when test="$lweb_design_mode and $orientation = 'top'"><div style="font-weight: bold; font-size: 8pt; z-index: 101; visibility: visible; width: 421px; font-style: normal;" nowrap="-1" bgcolor="black"><xsl:attribute name="style"><xsl:if test="$items/lxml:font/@bold = 'true'"><xsl:text>font-weight:bold;</xsl:text></xsl:if><xsl:if test="$items/lxml:font/@italic = 'true'"><xsl:text>font-style:italic;</xsl:text></xsl:if><xsl:if test="$items/lxml:font/@size"><xsl:text>font-size:</xsl:text><xsl:value-of select="$items/lxml:font/@size"></xsl:value-of><xsl:text>pt;</xsl:text></xsl:if><xsl:text>z-index: 101; visibility: visible;</xsl:text></xsl:attribute><xsl:for-each select="$items/lxml:item"><div style="border-right: 1px solid; border-top: 1px solid; display: inline; padding-left: 3px; left: 0px; visibility: inherit; overflow: hidden; border-left: 1px solid; width: 140px; cursor: hand; color: black; padding-top: 2px; border-bottom: 1px solid; position: relative; top: 0px; height: 20px; background-color: white; text-align: left;" value="Sample Item 1" ro="0" hifntclr="white" hibck="black" lwfntclr="black" lobck="white" hilite="0" linktxt="www.lansa.com" level="1" prvmbr="null"><xsl:value-of select="lxml:caption"></xsl:value-of><xsl:if test="lxml:item"><img style="left: 15px; width: 10px; position: relative; top: 1px; height: 5px" src="{$lweb_images_path}/wiztridown.gif" /></xsl:if><xsl:comment /></div></xsl:for-each><xsl:comment /></div></xsl:when><xsl:otherwise><img height="{$menu-height}" alt="" src="{$lweb_images_path}/clearpixel.gif" width="{$menu-width}" /></xsl:otherwise></xsl:choose><xsl:comment /></div><xsl:call-template name="dhtml_menu_init.private"><xsl:with-param name="items" select="$items"></xsl:with-param><xsl:with-param name="orientation"><xsl:value-of select="$orientation"></xsl:value-of></xsl:with-param><xsl:with-param name="width"><xsl:value-of select="$width"></xsl:value-of></xsl:with-param></xsl:call-template></td></tr></tbody></table></xsl:template><xsl:template name="sum-height.private"><xsl:param name="this-node" select="."></xsl:param><xsl:param name="height"></xsl:param><xsl:value-of select="sum($this-node/../lxml:item/lxml:height)"></xsl:value-of></xsl:template><xsl:template name="max-menu-width.private"><xsl:param name="items" select="."></xsl:param><xsl:param name="width"></xsl:param><xsl:variable name="next-width"><xsl:value-of select="$items/lxml:item/lxml:width[. &gt; $width]"></xsl:value-of></xsl:variable><xsl:variable name="max-width"><xsl:choose><xsl:when test="string-length($next-width) != 0"><xsl:call-template name="max-menu-width.private"><xsl:with-param name="items" select="$items"></xsl:with-param><xsl:with-param name="width" select="$next-width"></xsl:with-param></xsl:call-template></xsl:when><xsl:otherwise><xsl:value-of select="$width"></xsl:value-of></xsl:otherwise></xsl:choose></xsl:variable><xsl:value-of select="$max-width"></xsl:value-of></xsl:template><xsl:template name="max-menu-height.private"><xsl:param name="items" select="."></xsl:param><xsl:param name="height"></xsl:param><xsl:variable name="next-height"><xsl:value-of select="$items/lxml:item/lxml:height[. &gt; $height]"></xsl:value-of></xsl:variable><xsl:variable name="max-height"><xsl:choose><xsl:when test="string-length($next-height) != 0"><xsl:call-template name="max-menu-height.private"><xsl:with-param name="items" select="$items"></xsl:with-param><xsl:with-param name="height" select="$next-height"></xsl:with-param></xsl:call-template></xsl:when><xsl:otherwise><xsl:value-of select="$height"></xsl:value-of></xsl:otherwise></xsl:choose></xsl:variable><xsl:value-of select="$max-height"></xsl:value-of></xsl:template><xsl:template name="dhtml_menu_init.private"><xsl:param name="items" select="document('')/xsl:transform/lxml:data/lxml:menu"></xsl:param><xsl:param name="orientation">left</xsl:param><xsl:param name="width"></xsl:param><script type="text/javascript"><xsl:text disable-output-escaping="yes">
//&lt;![CDATA[
		</xsl:text><xsl:choose><xsl:when test="$orientation = 'left'">
var WizFirstLineHorizontal=0;
			</xsl:when><xsl:when test="$orientation = 'right'">
var WizFirstLineHorizontal=0;
			</xsl:when><xsl:otherwise>
var WizFirstLineHorizontal=1;
			</xsl:otherwise></xsl:choose>
var WizNoOffFirstLineMenus=<xsl:value-of select="count($items/lxml:item)"></xsl:value-of>;
	<xsl:text disable-output-escaping="yes">
var WizLowBgColor='white';
var WizLowSubBgColor='white';
var WizHighBgColor='black';
var WizHighSubBgColor='black';
var WizFontLowColor='black';
var WizFontSubLowColor='black';
var WizFontHighColor='white';
var WizFontSubHighColor='white';
var WizBorderColor='black';
var WizBorderSubColor='black';
var WizBorderWidth=1;
var WizBorderBtwnElmnts=1;
var WizFontFamily="arial,verdana,helvetica";
var WizFontSize=</xsl:text><xsl:value-of select="$items/lxml:font/@size"></xsl:value-of><xsl:text disable-output-escaping="yes">;
var WizFontBold=</xsl:text><xsl:value-of select="$items/lxml:font/@bold"></xsl:value-of><xsl:text disable-output-escaping="yes">;
var WizFontItalic=</xsl:text><xsl:value-of select="$items/lxml:font/@italic"></xsl:value-of><xsl:text disable-output-escaping="yes">;
var WizMenuTextCentered='left';
var WizMenuCentered='left';
var WizMenuVerticalCentered='top';
var WizChildOverlap=.2;
var WizChildVerticalOverlap=.2;
var WizStartTop=0;
		</xsl:text><xsl:choose><xsl:when test="$orientation = 'right'">
var WizStartLeft=MenuTable.parentElement.clientWidth;
			</xsl:when><xsl:otherwise>
var WizStartLeft=0;
			</xsl:otherwise></xsl:choose><xsl:text disable-output-escaping="yes">
var WizLeftPaddng=3;
var WizTopPaddng=2;
var WizDisappearDelay=1000;
var WizTargetLoc='MenuPos';
var WizMenuWrap=1;</xsl:text><xsl:choose><xsl:when test="$orientation = 'right'">
var WizRightToLeft=1;
			</xsl:when><xsl:otherwise>
var WizRightToLeft=0;
			</xsl:otherwise></xsl:choose><xsl:text disable-output-escaping="yes">
var WizUnfoldsOnClick=0;
var WizWebMasterCheck=0;
var WizShowArrow=1;
var WizKeepHilite=0;
var WizArrws=['/images/wiztri.gif',5,10,'/images/wiztridown.gif',10,5,'/images/wiztrileft.gif',5,10];
var WizVerCorrect=0;
var WizHorCorrect=0;
var WizMenuFramesVertical=1;
var WizTakeOverBgColor=1;
var WizFirstLineFrame='navig';
var WizSecLineFrame='space';
var WizDocTargetFrame='space';
var WizHideTop=0;

function WizBeforeStart(){return}
function WizAfterBuild(){return}
function WizBeforeFirstOpen(){return}
function WizAfterCloseAll(){return}

//]]&gt;
		</xsl:text><xsl:text disable-output-escaping="yes">
//&lt;![CDATA[
		</xsl:text><xsl:variable name="items_id" select="translate(generate-id($items), '.', '_')"></xsl:variable>
			var <xsl:value-of select="$items_id"></xsl:value-of> = stdGetFromDocumentByNameOrId(document, "<xsl:value-of select="$items_id"></xsl:value-of>");
			<xsl:call-template name="define-menu.private"><xsl:with-param name="mitem" select="$items"></xsl:with-param><xsl:with-param name="items_id" select="$items_id"></xsl:with-param><xsl:with-param name="var-name">Menu</xsl:with-param><xsl:with-param name="width"><xsl:value-of select="$width"></xsl:value-of></xsl:with-param></xsl:call-template><xsl:text disable-output-escaping="yes">
//]]&gt;
		</xsl:text></script><xsl:call-template name="std_dhtml_menuscript.private"></xsl:call-template></xsl:template><xsl:template name="define-menu.private"><xsl:param name="mitem" select="document('')"></xsl:param><xsl:param name="items_id"></xsl:param><xsl:param name="var-name"></xsl:param><xsl:param name="width"></xsl:param><xsl:for-each select="$mitem/lxml:item"><xsl:variable name="item-name"><xsl:value-of select="$var-name"></xsl:value-of><xsl:text></xsl:text><xsl:value-of select="position()"></xsl:value-of></xsl:variable><xsl:variable name="item_id" select="generate-id(.)"></xsl:variable><xsl:value-of select="$item-name"></xsl:value-of>=new Array(
			stdGetSpanText(<xsl:value-of select="$items_id"></xsl:value-of>, "<xsl:value-of select="$item_id"></xsl:value-of>_cap"),
			stdGetSpanText(<xsl:value-of select="$items_id"></xsl:value-of>, "<xsl:value-of select="$item_id"></xsl:value-of>_act"),
			stdGetSpanText(<xsl:value-of select="$items_id"></xsl:value-of>, "<xsl:value-of select="$item_id"></xsl:value-of>_bkg"),
			<xsl:value-of select="count(lxml:item)"></xsl:value-of>,<xsl:value-of select="lxml:height"></xsl:value-of>,
			<xsl:choose><xsl:when test="number($width) &gt; 0"><xsl:value-of select="$width"></xsl:value-of></xsl:when><xsl:otherwise><xsl:value-of select="lxml:width"></xsl:value-of></xsl:otherwise></xsl:choose>);

			<xsl:call-template name="define-menu.private"><xsl:with-param name="mitem" select="."></xsl:with-param><xsl:with-param name="items_id" select="$items_id"></xsl:with-param><xsl:with-param name="var-name"><xsl:value-of select="$item-name"></xsl:value-of>_<xsl:text></xsl:text></xsl:with-param></xsl:call-template></xsl:for-each></xsl:template><xsl:template name="std_dhtml_menu_spantext.private"><xsl:param name="items"></xsl:param><xsl:for-each select="$items/lxml:item"><xsl:variable name="item_id" select="generate-id(.)"></xsl:variable><span id="{$item_id}_cap"><xsl:value-of select="lxml:caption"></xsl:value-of><xsl:comment /></span><span id="{$item_id}_act"><xsl:value-of select="lxml:action"></xsl:value-of><xsl:comment /></span><span id="{$item_id}_bkg"><xsl:value-of select="lxml:background"></xsl:value-of><xsl:comment /></span><xsl:call-template name="std_dhtml_menu_spantext.private"><xsl:with-param name="items" select="."></xsl:with-param></xsl:call-template></xsl:for-each></xsl:template></xsl:transform>