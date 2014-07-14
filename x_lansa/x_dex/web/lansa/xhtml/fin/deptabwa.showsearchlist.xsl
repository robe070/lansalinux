<?xml version="1.0" encoding="UTF-8"?><!--Web application : DEPTABWAM--><!--Web routine : ShowSearchList--><!--Created by user : ROBG--><!--Timestamp : 2013-10-30 14:53:03.662--><xsl:transform version="1.0" exclude-result-prefixes="lxml wd" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design" xmlns="http://www.w3.org/1999/xhtml" xmlns:xsl="http://www.w3.org/1999/XSL/Transform"><xsl:import href="std_keys.xsl"></xsl:import><xsl:import href="std_variables.xsl"></xsl:import><xsl:import href="deptabwa_layout.xsl"></xsl:import><xsl:import href="std_integer.xsl"></xsl:import><xsl:import href="std_printpage.xsl"></xsl:import><xsl:import href="std_tab_pages_v2.xsl"></xsl:import><xsl:import href="std_button_v2.xsl"></xsl:import><xsl:import href="std_click_image.xsl"></xsl:import><xsl:import href="std_toexcel.xsl"></xsl:import><xsl:output method="xml" omit-xml-declaration="yes" encoding="UTF-8" indent="no"></xsl:output><lxml:data><lxml:tab id="674F215219F9474195ED5166AA3FFF77"><lxml:item><lxml:properties><lxml:width preferred_child_total="1" child_type="container" modifier="100%"></lxml:width><lxml:height preferred_child_total="1" child_type="container" modifier="100%"></lxml:height></lxml:properties><lxml:caption>by Department Code</lxml:caption><lxml:image></lxml:image><lxml:sel_image></lxml:sel_image><lxml:value>srve:</lxml:value></lxml:item></lxml:tab></lxml:data><xsl:template match="/"><xsl:call-template name="layout"></xsl:call-template></xsl:template><xsl:template match="/lxml:data"><div class="hidden"><xsl:comment /></div><div align="right"><xsl:call-template name="std_printpage"></xsl:call-template><xsl:comment /></div><xsl:if test="key('field-value','XXSHOWSCH') = 'Y' or $lweb_design_mode"><fieldset title="Enter Department search criteria"><legend class="std_legend"><span>Department Searches Cloud Compile 7</span></legend><xsl:call-template name="std_tab_pages_v2"><xsl:with-param name="tab_image" select="''"></xsl:with-param><xsl:with-param name="selected_tab_index" select="1"></xsl:with-param><xsl:with-param name="content_height" select="'100%'"></xsl:with-param><xsl:with-param name="content_width" select="'100%'"></xsl:with-param><xsl:with-param name="selected_tab_index_field" select="'XXSRCHTYP'"></xsl:with-param><xsl:with-param name="hide_if_true_field" select="key('field-value', 'XXSHOWSCH') = 'N'"></xsl:with-param><xsl:with-param name="name" select="concat('o', position(), '_LANSA_1858')"></xsl:with-param><xsl:with-param name="tabs" select="document('')/*/lxml:data/lxml:tab[@id='674F215219F9474195ED5166AA3FFF77']"></xsl:with-param></xsl:call-template></fieldset></xsl:if><br /><xsl:apply-templates select="/lxml:data/lxml:lists/lxml:list[@name='XXCRUDLST']"><xsl:with-param name="allowSort" select="true()"></xsl:with-param><xsl:with-param name="allowColResize" select="true()"></xsl:with-param><xsl:with-param name="hoverEffect" select="true()"></xsl:with-param><xsl:with-param name="selectableRows" select="true()"></xsl:with-param><xsl:with-param name="hide_header_if_empty" select="true()"></xsl:with-param></xsl:apply-templates><table><tbody><tr><td><xsl:call-template name="std_button_v2"><xsl:with-param name="width_design" select="'100%'"></xsl:with-param><xsl:with-param name="on_click_wrname" select="'SetupAdd'"></xsl:with-param><xsl:with-param name="caption" select="key('variable', 'MTXT_XXNEW')"></xsl:with-param><xsl:with-param name="name" select="concat('o', position(), '_LANSA_16791')"></xsl:with-param></xsl:call-template><xsl:comment /></td><td><xsl:call-template name="std_toexcel"><xsl:with-param name="width_design" select="'100%'"></xsl:with-param><xsl:with-param name="listname" select="'XXCRUDLST'"></xsl:with-param><xsl:with-param name="hide_if" select="key('field-value', 'XXENTRIES') = 0"></xsl:with-param><xsl:with-param name="name" select="concat('o', position(), '_LANSA_24008')"></xsl:with-param><xsl:with-param name="startingColumnIndex" select="1"></xsl:with-param><xsl:with-param name="numberOfColumns" select="2"></xsl:with-param></xsl:call-template><xsl:comment /></td></tr></tbody></table></xsl:template><xsl:template match="/lxml:data/lxml:lists/lxml:list[@name='XXCRUDLST']"><xsl:param name="allowSort" select="true()"></xsl:param><xsl:param name="allowColResize" select="true()"></xsl:param><xsl:param name="hoverEffect" select="false()"></xsl:param><xsl:param name="selectableRows" select="false()"></xsl:param><xsl:param name="hide_header_if_empty" select="true()"></xsl:param><xsl:text>&#xA;</xsl:text><wd:inlined-list name="XXCRUDLST"><xsl:text>&#xA;</xsl:text><xsl:variable name="thelist" select="/lxml:data/lxml:lists/lxml:list[@name='XXCRUDLST']"></xsl:variable><script type="text/javascript"><xsl:text disable-output-escaping="yes">//&lt;![CDATA[</xsl:text>stdGrid_HideCols('.std_grid#XXCRUDLST ', ['td.PRIFILRRN', 'th.PRIFILRRN', null]);<xsl:text disable-output-escaping="yes">//]]&gt;</xsl:text></script><input type="hidden" name="XXCRUDLST.." value="$(has_entry:XXCRUDLST)" /><div id="XXCRUDLST_wrap" class="std_grid_wrapper"><table id="XXCRUDLST" class="std_grid ui-widget"><xsl:if test="not($hide_header_if_empty) or ($thelist/@row-count != 0)"><thead><tr class="list-h ui-widget-header"><th class="utext STDSELECT std_grid_sort_indicator" __decimalseparator="" __formattype="alpha" __mode="output" __allowsort="true">$(fc:STDSELECT,%3Cbr /%3E)<div class="std_grid_cell_sizer"><xsl:comment>.</xsl:comment><xsl:comment /></div></th><th class="utext DEPTMENT std_grid_sort_indicator" __decimalseparator="" __formattype="alpha" __mode="output" __allowsort="true">$(fc:DEPTMENT,%3Cbr /%3E)<div class="std_grid_cell_sizer"><xsl:comment>.</xsl:comment><xsl:comment /></div></th><th class="utext DEPTDESC std_grid_sort_indicator" __decimalseparator="" __formattype="alpha" __mode="output" __allowsort="true">$(fc:DEPTDESC,%3Cbr /%3E)<div class="std_grid_cell_sizer"><xsl:comment>.</xsl:comment><xsl:comment /></div></th></tr></thead></xsl:if><tbody class="ui-widget-content"><xsl:text>&#xA;</xsl:text><wd:for-each-row><xsl:text>&#xA;</xsl:text><xsl:variable name="STDSELECT">$(fv:STDSELECT)</xsl:variable><xsl:variable name="DEPTMENT">$(fv:DEPTMENT)</xsl:variable><xsl:variable name="DEPTDESC">$(fv:DEPTDESC)</xsl:variable><xsl:variable name="PRIFILRRN">$(fv:PRIFILRRN)</xsl:variable><tr onclick="if (this.getAttribute('_disabled') == 'disabled') return false;return stdAnchorClicked(event, this, '$(application_name)', 'GetRecord', 'LANSA', '', '', 'XXCURROW', '$(row_index)');" class="$(row_class:list-o,list-e)" __oddrc="list-o" __evenrc="list-e"><td class="STDSELECT" __cellvalue="$(fv:STDSELECT)"><div class="utext"><span class="ui-widget"><a onclick="if (this.getAttribute('_disabled') == 'disabled') return false;return stdAnchorClicked(event, this, '$(application_name)', 'GetRecord', 'LANSA', '', '', 'XXCURROW', '$(row_index)');" id="XXCRUDLST.$(row_index).STDSELECT" class="hidefocus" hidefocus="-1" style="display: inline-block;" href="javascript:void(0);"><span class="hidden__"><span class="reentryfield" style="display:none;">PRIFILRRN</span><span class="reentryvalue" style="display:none;">$(fv:PRIFILRRN)</span></span><img onmouseover="stdImageMouseOver(this);" onmouseout="stdImageMouseOut(this);" style="border-style:none;" src="$(images_path)/icons/normal/16/ball_blue_16.png" __moimage="" class="std_click_image"></img></a></span><script type="text/javascript"><xsl:text disable-output-escaping="yes">//&lt;![CDATA[
 </xsl:text>setStdImagePreload();
 <xsl:text disable-output-escaping="yes">//]]&gt;</xsl:text></script></div></td><td class="DEPTMENT" __cellvalue="$(fv:DEPTMENT)"><div class="utext">$(fv:DEPTMENT)</div></td><td class="DEPTDESC" __cellvalue="$(fv:DEPTDESC)"><div class="utext">$(fv:DEPTDESC)</div></td></tr><xsl:text>&#xA;</xsl:text></wd:for-each-row><xsl:text>&#xA;</xsl:text></tbody></table></div><script type="text/javascript"><xsl:text disable-output-escaping="yes">//&lt;![CDATA[</xsl:text>
register_std_grid('XXCRUDLST',{
 columns: 7,
  allowSort: <xsl:value-of select="$allowSort"></xsl:value-of>,
  allowColResize: <xsl:value-of select="$allowColResize"></xsl:value-of>,
  hoverEffect: <xsl:value-of select="$hoverEffect"></xsl:value-of>,
  selectableRows: <xsl:value-of select="$selectableRows"></xsl:value-of>
  });
<xsl:text disable-output-escaping="yes">//]]&gt;</xsl:text></script><xsl:text>&#xA;</xsl:text></wd:inlined-list><xsl:text>&#xA;</xsl:text></xsl:template><xsl:template match="*" mode="_674F215219F9474195ED5166AA3FFF77_1.override"><xsl:param name="context"></xsl:param><xsl:param name="index"></xsl:param><xsl:param name="selected_index"></xsl:param><table><tbody><tr><td><label class="caption" for="XXKEY0101"><xsl:value-of select="key('field-caption', 'XXKEY0101')/lxml:description"></xsl:value-of></label></td><td><input onchange="return isValidText( this, '')" id="XXKEY0101" class="utext" maxlength="4" size="4" name="XXKEY0101" value="{key('field-value', 'XXKEY0101')}" /></td><td><xsl:call-template name="std_button_v2"><xsl:with-param name="width_design" select="'100%'"></xsl:with-param><xsl:with-param name="on_click_wrname" select="'BuildFirst'"></xsl:with-param><xsl:with-param name="currentrownumval" select="'1'"></xsl:with-param><xsl:with-param name="currentrowhfield" select="'XXSRCHTYP'"></xsl:with-param><xsl:with-param name="caption" select="key('variable', 'MTXT_XXSEARCH')"></xsl:with-param><xsl:with-param name="name" select="concat('o', position(), '_BUTTON_0001')"></xsl:with-param></xsl:call-template><xsl:comment /></td></tr></tbody></table></xsl:template><xsl:template match="lxml:item[../@id='674F215219F9474195ED5166AA3FFF77']" mode="tabs_content.private.override"><xsl:param name="context"></xsl:param><xsl:param name="index"></xsl:param><xsl:param name="selected_index"></xsl:param><xsl:choose><xsl:when test="$index=1"><xsl:apply-templates select="$context" mode="_674F215219F9474195ED5166AA3FFF77_1.override"><xsl:with-param name="context" select="."></xsl:with-param><xsl:with-param name="index" select="$index"></xsl:with-param><xsl:with-param name="selected_index" select="$selected_index"></xsl:with-param></xsl:apply-templates></xsl:when></xsl:choose></xsl:template></xsl:transform>