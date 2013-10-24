<?xml version="1.0" encoding="UTF-8"?><!--(c) 2003, 2013 LANSA--><!--XHTML Standard List Paging Buttons--><!--A set of buttons for paging through--><!--a list--><!--$Workfile:: std_list_buttons.xsl $--><!--$UTCDate:: 2013-05-01 05:19:38Z $--><!--$Revision:: 13 $--><xsl:transform version="1.0" exclude-result-prefixes="lxml wd" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns="http://www.w3.org/1999/xhtml"><xsl:import href="std_keys.xsl"></xsl:import><xsl:import href="std_util.xsl"></xsl:import><xsl:import href="std_button.xsl"></xsl:import><xsl:import href="std_types.xsl"></xsl:import><xsl:output method="xml" omit-xml-declaration="yes" encoding="UTF-8" indent="yes"></xsl:output><xsl:template name="std_list_buttons"><xsl:param name="name"></xsl:param><xsl:param name="prevcondfield" select="'STDPREV'"></xsl:param><xsl:param name="nextcondfield" select="'STDMORE'"></xsl:param><xsl:param name="show_first_last" select="false()"></xsl:param><xsl:param name="reentryfield" select="'STDRENTRY'"></xsl:param><xsl:param name="hide_if" select="false()"></xsl:param><xsl:param name="formname" select="'LANSA'"></xsl:param><xsl:param name="pos_absolute_design"></xsl:param><xsl:param name="width_design" select="'100%'"></xsl:param><xsl:param name="height_design"></xsl:param><xsl:param name="on_click_wamname" select="$lweb_WAMName"></xsl:param><xsl:param name="on_page_wrname"></xsl:param><xsl:param name="on_search_wrname"></xsl:param><xsl:param name="protocol"></xsl:param><xsl:param name="page_count_fieldname"></xsl:param><xsl:param name="class" select="'std_button'"></xsl:param><xsl:param name="mouseover_class" select="'std_button_mouseover'"></xsl:param><xsl:param name="tab_index"></xsl:param><xsl:param name="vf_wamevents" select="''"></xsl:param><xsl:if test="not($hide_if) or $lweb_design_mode"><xsl:variable name="onmouseover"><xsl:text>this.className='</xsl:text><xsl:value-of select="$mouseover_class"></xsl:value-of><xsl:text>';</xsl:text></xsl:variable><xsl:variable name="onmouseout"><xsl:text>this.className='</xsl:text><xsl:value-of select="$class"></xsl:value-of><xsl:text>';</xsl:text></xsl:variable><xsl:variable name="clickFuncEnd"><xsl:text>', '</xsl:text><xsl:value-of select="$formname"></xsl:value-of><xsl:text>', '</xsl:text><xsl:value-of select="$protocol"></xsl:value-of><xsl:text>','</xsl:text><xsl:value-of select="$reentryfield"></xsl:value-of><xsl:text>','</xsl:text><xsl:value-of select="$prevcondfield"></xsl:value-of><xsl:text>','</xsl:text><xsl:value-of select="key('field-value', $prevcondfield)"></xsl:value-of><xsl:text>','</xsl:text><xsl:value-of select="$nextcondfield"></xsl:value-of><xsl:text>','</xsl:text><xsl:value-of select="key('field-value', $nextcondfield)"></xsl:value-of><xsl:text>','</xsl:text><xsl:value-of select="$page_count_fieldname"></xsl:value-of><xsl:text>','</xsl:text><xsl:value-of select="key('field-value', $page_count_fieldname)"></xsl:value-of><xsl:text>');</xsl:text></xsl:variable><xsl:variable name="vf_wamevent_prev" select="substring-before($vf_wamevents, ',')"></xsl:variable><xsl:variable name="vf_wamevent_rem" select="substring-after($vf_wamevents, ',')"></xsl:variable><xsl:variable name="vf_wamevent_next" select="substring-before($vf_wamevent_rem, ',')"></xsl:variable><xsl:variable name="vf_wamevent_rem2" select="substring-after($vf_wamevent_rem, ',')"></xsl:variable><xsl:variable name="vf_wamevent_search" select="substring-before($vf_wamevent_rem2, ',')"></xsl:variable><xsl:variable name="vf_wamevent_rem3" select="substring-after($vf_wamevent_rem2, ',')"></xsl:variable><xsl:variable name="vf_wamevent_first" select="substring-before($vf_wamevent_rem3, ',')"></xsl:variable><xsl:variable name="vf_wamevent_last" select="substring-after($vf_wamevent_rem3, ',')"></xsl:variable><table style="width: 100%" class="stdListPagingButtons ui-widget"><xsl:attribute name="style"><xsl:call-template name="make_size_and_pos_style_v2.private"><xsl:with-param name="caller_name" select="'std_list_buttons.xsl'"></xsl:with-param><xsl:with-param name="pos_absolute" select="$pos_absolute_design"></xsl:with-param><xsl:with-param name="height" select="$height_design"></xsl:with-param><xsl:with-param name="width" select="$width_design"></xsl:with-param></xsl:call-template></xsl:attribute><xsl:if test="$name!=''"><xsl:attribute name="id"><xsl:value-of select="$name"></xsl:value-of></xsl:attribute></xsl:if><tbody><tr><td style="width:33.33%;white-space:nowrap;" align="left"><xsl:if test="$lweb_design_mode or key('field-value', $prevcondfield) != ''"><xsl:if test="$show_first_last or key('design_doc_name', 'std_list_buttons.xsl')"><input type="button" class="{$class}" value="First"><xsl:if test="$on_page_wrname != ''"><xsl:attribute name="onclick"><xsl:text>return stdListPageBtnClick(event, 'F', '</xsl:text><xsl:value-of select="$on_click_wamname"></xsl:value-of><xsl:text>', '</xsl:text><xsl:value-of select="$on_page_wrname"></xsl:value-of><xsl:value-of select="$clickFuncEnd"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$mouseover_class != ''"><xsl:attribute name="onmouseover"><xsl:value-of select="$onmouseover"></xsl:value-of></xsl:attribute><xsl:attribute name="onmouseout"><xsl:value-of select="$onmouseout"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$tab_index != ''"><xsl:attribute name="tabindex"><xsl:value-of select="$tab_index"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$vf_wamevent_first != ''"><xsl:attribute name="data-vf-wamevent"><xsl:value-of select="$vf_wamevent_first"></xsl:value-of></xsl:attribute></xsl:if></input></xsl:if><input type="button" class="{$class}" value="Previous"><xsl:if test="$on_page_wrname != ''"><xsl:attribute name="onclick"><xsl:text>return stdListPageBtnClick(event, 'P', '</xsl:text><xsl:value-of select="$on_click_wamname"></xsl:value-of><xsl:text>', '</xsl:text><xsl:value-of select="$on_page_wrname"></xsl:value-of><xsl:value-of select="$clickFuncEnd"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$mouseover_class != ''"><xsl:attribute name="onmouseover"><xsl:value-of select="$onmouseover"></xsl:value-of></xsl:attribute><xsl:attribute name="onmouseout"><xsl:value-of select="$onmouseout"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$tab_index != ''"><xsl:attribute name="tabindex"><xsl:value-of select="$tab_index"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$vf_wamevent_prev != ''"><xsl:attribute name="data-vf-wamevent"><xsl:value-of select="$vf_wamevent_prev"></xsl:value-of></xsl:attribute></xsl:if></input></xsl:if><xsl:comment /></td><td style="width:33.34%" align="center"><xsl:if test="$lweb_design_mode or $on_search_wrname != ''"><input type="button" class="{$class}" value="New Search"><xsl:if test="$on_search_wrname != ''"><xsl:attribute name="onclick"><xsl:text>return stdListPageBtnClick(event, '', '</xsl:text><xsl:value-of select="$on_click_wamname"></xsl:value-of><xsl:text>', '</xsl:text><xsl:value-of select="$on_search_wrname"></xsl:value-of><xsl:value-of select="$clickFuncEnd"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$mouseover_class != ''"><xsl:attribute name="onmouseover"><xsl:value-of select="$onmouseover"></xsl:value-of></xsl:attribute><xsl:attribute name="onmouseout"><xsl:value-of select="$onmouseout"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$tab_index != ''"><xsl:attribute name="tabindex"><xsl:value-of select="$tab_index"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$vf_wamevent_search != ''"><xsl:attribute name="data-vf-wamevent"><xsl:value-of select="$vf_wamevent_search"></xsl:value-of></xsl:attribute></xsl:if></input></xsl:if><xsl:comment /></td><td style="width:33.33%;white-space:nowrap;" align="right"><xsl:if test="$lweb_design_mode or key('field-value', $nextcondfield) != ''"><input type="button" class="{$class}" value="Next"><xsl:if test="$on_page_wrname != ''"><xsl:attribute name="onclick"><xsl:text>return stdListPageBtnClick(event, 'M', '</xsl:text><xsl:value-of select="$on_click_wamname"></xsl:value-of><xsl:text>', '</xsl:text><xsl:value-of select="$on_page_wrname"></xsl:value-of><xsl:value-of select="$clickFuncEnd"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$mouseover_class != ''"><xsl:attribute name="onmouseover"><xsl:value-of select="$onmouseover"></xsl:value-of></xsl:attribute><xsl:attribute name="onmouseout"><xsl:value-of select="$onmouseout"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$tab_index != ''"><xsl:attribute name="tabindex"><xsl:value-of select="$tab_index"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$vf_wamevent_next != ''"><xsl:attribute name="data-vf-wamevent"><xsl:value-of select="$vf_wamevent_next"></xsl:value-of></xsl:attribute></xsl:if></input><xsl:if test="$show_first_last or key('design_doc_name', 'std_list_buttons.xsl')"><input type="button" class="{$class}" value="Last"><xsl:if test="$on_page_wrname != ''"><xsl:attribute name="onclick"><xsl:text>return stdListPageBtnClick(event, 'L', '</xsl:text><xsl:value-of select="$on_click_wamname"></xsl:value-of><xsl:text>', '</xsl:text><xsl:value-of select="$on_page_wrname"></xsl:value-of><xsl:value-of select="$clickFuncEnd"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$mouseover_class != ''"><xsl:attribute name="onmouseover"><xsl:value-of select="$onmouseover"></xsl:value-of></xsl:attribute><xsl:attribute name="onmouseout"><xsl:value-of select="$onmouseout"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$tab_index != ''"><xsl:attribute name="tabindex"><xsl:value-of select="$tab_index"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$vf_wamevent_last != ''"><xsl:attribute name="data-vf-wamevent"><xsl:value-of select="$vf_wamevent_last"></xsl:value-of></xsl:attribute></xsl:if></input></xsl:if></xsl:if><xsl:comment /></td></tr></tbody></table></xsl:if></xsl:template></xsl:transform>