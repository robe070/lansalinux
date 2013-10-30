<?xml version="1.0" encoding="UTF-8"?><!--(c) 2009, 2012 LANSA--><!--XHTML Standard Tab Pages--><!--$Workfile:: std_crud_tabs.xsl $--><!--$UTCDate:: 2012-12-20 03:07:16Z $--><!--$Revision:: 8 $--><xsl:transform version="1.0" exclude-result-prefixes="lxml wd msxsl" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design" xmlns:msxsl="urn:schemas-microsoft-com:xslt" xmlns:exslt="http://exslt.org/common" xmlns="http://www.w3.org/1999/xhtml"><xsl:import href="std_crud_types.xsl"></xsl:import><xsl:import href="std_types.xsl"></xsl:import><xsl:import href="std_keys.xsl"></xsl:import><xsl:import href="std_util.xsl"></xsl:import><xsl:import href="std_variables.xsl"></xsl:import><xsl:output method="xml" omit-xml-declaration="yes" encoding="UTF-8" indent="yes"></xsl:output><lxml:data><lxml:tab id="static_tabs"><lxml:item><lxml:properties><lxml:width modifier="100%" child_type="container" preferred_child_total="1"></lxml:width><lxml:height modifier="100%" child_type="container" preferred_child_total="1"></lxml:height></lxml:properties><lxml:caption>Tab Page 1</lxml:caption><lxml:sel_image></lxml:sel_image><lxml:value></lxml:value></lxml:item><lxml:item><lxml:properties><lxml:width modifier="100%" child_type="container" preferred_child_total="1"></lxml:width><lxml:height modifier="100%" child_type="container" preferred_child_total="1"></lxml:height></lxml:properties><lxml:caption>Tab Page 2</lxml:caption><lxml:sel_image></lxml:sel_image><lxml:value></lxml:value></lxml:item><lxml:item><lxml:properties><lxml:width modifier="100%" child_type="container" preferred_child_total="1"></lxml:width><lxml:height modifier="100%" child_type="container" preferred_child_total="1"></lxml:height></lxml:properties><lxml:caption>Tab Page 3</lxml:caption><lxml:sel_image></lxml:sel_image><lxml:value></lxml:value></lxml:item></lxml:tab></lxml:data><xsl:template name="std_crud_tabs"><xsl:param name="name"></xsl:param><xsl:param name="tabs" select="document('')/*/lxml:data/lxml:tab[@id='static_tabs']"></xsl:param><xsl:param name="selected_tab_index" select="1"></xsl:param><xsl:param name="selected_tab_index_field"></xsl:param><xsl:param name="tab_alignment" select="'top'"></xsl:param><xsl:param name="listname"></xsl:param><xsl:param name="caption_field"></xsl:param><xsl:param name="hide_if_true_field"></xsl:param><xsl:param name="disable_if_true_field"></xsl:param><xsl:param name="hide_if" select="false()"></xsl:param><xsl:param name="formname" select="'LANSA'"></xsl:param><xsl:param name="pos_absolute_design"></xsl:param><xsl:param name="content_width" select="'300px'"></xsl:param><xsl:param name="content_height" select="'150px'"></xsl:param><xsl:if test="not($hide_if) or $lweb_design_mode"><xsl:variable name="list_xml"><xsl:choose><xsl:when test="$listname != ''"><lxml:tab id="{$tabs/@id}"><xsl:for-each select="key('list', $listname)/lxml:list-entries/lxml:entry"><xsl:variable name="index" select="position()"></xsl:variable><lxml:item><xsl:if test="$hide_if_true_field!=''"><xsl:variable name="value" select="lxml:column[@name=$hide_if_true_field]"></xsl:variable><xsl:if test="$value!='' and ($value='y' or $value='Y' or $value='true' or $value='1')"><xsl:attribute name="tab_hidden"><xsl:text>true</xsl:text></xsl:attribute></xsl:if></xsl:if><xsl:if test="$disable_if_true_field!=''"><xsl:variable name="value" select="lxml:column[@name=$disable_if_true_field]"></xsl:variable><xsl:if test="$value!='' and ($value='y' or $value='Y' or $value='true' or $value='1')"><xsl:attribute name="tab_disabled"><xsl:text>true</xsl:text></xsl:attribute></xsl:if></xsl:if><lxml:properties><lxml:width modifier="100%" child_type="container" preferred_child_total="1"></lxml:width><lxml:height modifier="100%" child_type="container" preferred_child_total="1"></lxml:height></lxml:properties><lxml:caption><xsl:choose><xsl:when test="$caption_field='' and $index &lt;= count($tabs/lxml:item)"><xsl:value-of select="$tabs/lxml:item[$index]/lxml:caption"></xsl:value-of></xsl:when><xsl:otherwise><xsl:value-of select="lxml:column[@name=$caption_field]"></xsl:value-of></xsl:otherwise></xsl:choose></lxml:caption></lxml:item></xsl:for-each></lxml:tab></xsl:when><xsl:otherwise><xsl:call-template name="expand_mtxt_in_xml_items.private"><xsl:with-param name="items" select="$tabs"></xsl:with-param></xsl:call-template></xsl:otherwise></xsl:choose></xsl:variable><xsl:variable name="var_sel_tab_index"><xsl:choose><xsl:when test="not($lweb_design_mode) and $selected_tab_index_field!=''"><xsl:value-of select="number(key('field-value', $selected_tab_index_field))"></xsl:value-of></xsl:when><xsl:when test="$selected_tab_index!=''"><xsl:value-of select="$selected_tab_index"></xsl:value-of></xsl:when><xsl:otherwise>1</xsl:otherwise></xsl:choose></xsl:variable><table style="width:100%;" cellspacing="0" cellpadding="0" width="100%" border="0"><xsl:if test="$pos_absolute_design"><xsl:attribute name="style"><xsl:call-template name="make_size_and_pos_style_v2.private"><xsl:with-param name="caller_name" select="'std_crud_tabs.xsl'"></xsl:with-param><xsl:with-param name="pos_absolute" select="$pos_absolute_design"></xsl:with-param></xsl:call-template></xsl:attribute></xsl:if><tbody><xsl:if test="$tab_alignment='top'"><tr><td><div id="crud_tab_container"><div id="crud_tab_header"><xsl:choose><xsl:when test="$lweb_is_msxsl_nodeset"><xsl:call-template name="std_crud_tabs.tabs.private"><xsl:with-param name="name" select="$name"></xsl:with-param><xsl:with-param name="var_sel_tab_index" select="$var_sel_tab_index"></xsl:with-param><xsl:with-param name="tabs_xml" select="msxsl:node-set($list_xml)/*"></xsl:with-param></xsl:call-template></xsl:when><xsl:when test="$lweb_is_exslt_nodeset"><xsl:call-template name="std_crud_tabs.tabs.private"><xsl:with-param name="name" select="$name"></xsl:with-param><xsl:with-param name="var_sel_tab_index" select="$var_sel_tab_index"></xsl:with-param><xsl:with-param name="tabs_xml" select="exslt:node-set($list_xml)/*"></xsl:with-param></xsl:call-template></xsl:when></xsl:choose><xsl:comment /></div></div></td></tr><tr><td bgcolor="#ffffff"><xsl:choose><xsl:when test="$lweb_is_msxsl_nodeset"><xsl:call-template name="std_crud_tabs.content.private"><xsl:with-param name="name" select="$name"></xsl:with-param><xsl:with-param name="var_sel_tab_index" select="$var_sel_tab_index"></xsl:with-param><xsl:with-param name="tabs_xml" select="msxsl:node-set($list_xml)/*"></xsl:with-param></xsl:call-template></xsl:when><xsl:when test="$lweb_is_exslt_nodeset"><xsl:call-template name="std_crud_tabs.content.private"><xsl:with-param name="name" select="$name"></xsl:with-param><xsl:with-param name="var_sel_tab_index" select="$var_sel_tab_index"></xsl:with-param><xsl:with-param name="tabs_xml" select="exslt:node-set($list_xml)/*"></xsl:with-param></xsl:call-template></xsl:when></xsl:choose><xsl:comment /></td></tr><tr><td class="crud_linesep"><img style="width: 10px; height: 1px;" height="1" alt="" src="/images/crud/spacer.gif" width="10" /></td></tr></xsl:if><xsl:if test="$tab_alignment='bottom'"><tr><td class="crud_linesep"><img style="width: 10px; height: 1px;" height="1" alt="" src="/images/crud/spacer.gif" width="10" /></td></tr><tr><td><xsl:choose><xsl:when test="$lweb_is_msxsl_nodeset"><xsl:call-template name="std_crud_tabs.content.private"><xsl:with-param name="name" select="$name"></xsl:with-param><xsl:with-param name="var_sel_tab_index" select="$var_sel_tab_index"></xsl:with-param><xsl:with-param name="tabs_xml" select="msxsl:node-set($list_xml)/*"></xsl:with-param></xsl:call-template></xsl:when><xsl:when test="$lweb_is_exslt_nodeset"><xsl:call-template name="std_crud_tabs.content.private"><xsl:with-param name="name" select="$name"></xsl:with-param><xsl:with-param name="var_sel_tab_index" select="$var_sel_tab_index"></xsl:with-param><xsl:with-param name="tabs_xml" select="exslt:node-set($list_xml)/*"></xsl:with-param></xsl:call-template></xsl:when></xsl:choose><xsl:comment /></td></tr><tr><td><div id="crud_tab_container"><div id="crud_tab_header"><xsl:choose><xsl:when test="$lweb_is_msxsl_nodeset"><xsl:call-template name="std_crud_tabs.tabs.private"><xsl:with-param name="name" select="$name"></xsl:with-param><xsl:with-param name="var_sel_tab_index" select="$var_sel_tab_index"></xsl:with-param><xsl:with-param name="tabs_xml" select="msxsl:node-set($list_xml)/*"></xsl:with-param></xsl:call-template></xsl:when><xsl:when test="$lweb_is_exslt_nodeset"><xsl:call-template name="std_crud_tabs.tabs.private"><xsl:with-param name="name" select="$name"></xsl:with-param><xsl:with-param name="var_sel_tab_index" select="$var_sel_tab_index"></xsl:with-param><xsl:with-param name="tabs_xml" select="exslt:node-set($list_xml)/*"></xsl:with-param></xsl:call-template></xsl:when></xsl:choose><xsl:comment /></div></div></td></tr></xsl:if></tbody></table><script type="text/javascript"><xsl:text disable-output-escaping="yes">//&lt;![CDATA[ 
				</xsl:text><xsl:text>currentTab = </xsl:text><xsl:value-of select="$var_sel_tab_index"></xsl:value-of><xsl:text>;</xsl:text><xsl:text>stdTabPagesInit('</xsl:text><xsl:value-of select="$name"></xsl:value-of><xsl:text>', '</xsl:text><xsl:value-of select="$formname"></xsl:value-of><xsl:text>', '</xsl:text><xsl:value-of select="$selected_tab_index_field"></xsl:value-of><xsl:text>', </xsl:text><xsl:value-of select="$var_sel_tab_index"></xsl:value-of><xsl:text>);</xsl:text><xsl:text disable-output-escaping="yes">//]]&gt;</xsl:text><xsl:text>&#32;</xsl:text></script></xsl:if></xsl:template><xsl:template name="std_crud_tabs.tabs.private"><xsl:param name="name"></xsl:param><xsl:param name="var_sel_tab_index"></xsl:param><xsl:param name="tabs_xml"></xsl:param><ul id="coursetabs"><xsl:for-each select="$tabs_xml/lxml:item"><xsl:variable name="hideFlag"><xsl:choose><xsl:when test="boolean(@tab_hidden) and (@tab_hidden = 'true')"><xsl:value-of select="@tab_hidden"></xsl:value-of></xsl:when><xsl:when test="boolean(@hideFlagField)"><xsl:variable name="hideFlagField" select="@hideFlagField"></xsl:variable><xsl:value-of select="$lweb_data_node/lxml:fields/lxml:field[@name=$hideFlagField]/lxml:value"></xsl:value-of></xsl:when></xsl:choose></xsl:variable><xsl:if test="$lweb_design_mode or ($hideFlag = '') or not(contains('trueTRUEyY1', $hideFlag))"><li><xsl:variable name="disableFlag"><xsl:choose><xsl:when test="boolean(@tab_disabled) and (@tab_disabled = 'true')"><xsl:value-of select="@tab_disabled"></xsl:value-of></xsl:when><xsl:when test="boolean(@disableFlagField)"><xsl:variable name="disableFlagField" select="@disableFlagField"></xsl:variable><xsl:value-of select="$lweb_data_node/lxml:fields/lxml:field[@name=$disableFlagField]/lxml:value"></xsl:value-of></xsl:when></xsl:choose></xsl:variable><xsl:attribute name="id"><xsl:if test="position() = $var_sel_tab_index">crud_currentTab</xsl:if><xsl:if test="position() != $var_sel_tab_index"><xsl:value-of select="$name"></xsl:value-of>_tab<xsl:value-of select="position()"></xsl:value-of></xsl:if></xsl:attribute><xsl:choose><xsl:when test="($disableFlag!='') and contains('trueTRUEyY1', $disableFlag)"><xsl:attribute name="class"><xsl:value-of select="'std_tab_disabled'"></xsl:value-of></xsl:attribute></xsl:when></xsl:choose><a title="Click here to activate tab page 1 - Tab Page 1" href="javascript:changeTab('{$name}_tab','{$name}_tab{position()}', {position()}, '{$name}_content_', {count($tabs_xml/lxml:item)});"><xsl:attribute name="title"><xsl:text>Click here to activate tab </xsl:text><xsl:value-of select="position()"></xsl:value-of><xsl:text> - </xsl:text><xsl:value-of select="lxml:caption"></xsl:value-of></xsl:attribute><span><xsl:value-of select="lxml:caption"></xsl:value-of><xsl:comment /></span></a></li></xsl:if></xsl:for-each><xsl:comment /></ul></xsl:template><xsl:template name="std_crud_tabs.content.private"><xsl:param name="name"></xsl:param><xsl:param name="var_sel_tab_index"></xsl:param><xsl:param name="tabs_xml"></xsl:param><xsl:for-each select="$tabs_xml/lxml:item"><xsl:if test="(not($lweb_design_mode) or position()=$var_sel_tab_index)"><xsl:variable name="hideFlag"><xsl:choose><xsl:when test="boolean(@tab_hidden) and (@tab_hidden = 'true')"><xsl:value-of select="@tab_hidden"></xsl:value-of></xsl:when><xsl:when test="boolean(@hideFlagField)"><xsl:variable name="hideFlagField" select="@hideFlagField"></xsl:variable><xsl:value-of select="$lweb_data_node/lxml:fields/lxml:field[@name=$hideFlagField]/lxml:value"></xsl:value-of></xsl:when></xsl:choose></xsl:variable><div id="{$name}_content_{position()}"><xsl:if test="$lweb_design_mode or ($hideFlag = '') or not(contains('trueTRUEyY1', $hideFlag))"><xsl:if test="position()!=$var_sel_tab_index"><xsl:attribute name="style">;display:none</xsl:attribute></xsl:if><xsl:apply-templates select="." mode="tabs_content.private.override"><xsl:with-param name="context" select="$lweb_data_node"></xsl:with-param><xsl:with-param name="index" select="position()"></xsl:with-param><xsl:with-param name="selected_index" select="$var_sel_tab_index"></xsl:with-param></xsl:apply-templates></xsl:if><xsl:comment /></div></xsl:if></xsl:for-each></xsl:template><xsl:template match="lxml:item[../@id='static_tabs']" mode="tabs_content.private.override"><xsl:param name="context"></xsl:param><xsl:param name="index"></xsl:param><xsl:param name="selected_index"></xsl:param><xsl:choose><xsl:when test="$index=1"><xsl:apply-templates select="$context" mode="_static_tabs_1.override"><xsl:with-param name="context" select="."></xsl:with-param><xsl:with-param name="index" select="$index"></xsl:with-param><xsl:with-param name="selected_index" select="$selected_index"></xsl:with-param></xsl:apply-templates></xsl:when><xsl:when test="$index=2"><xsl:apply-templates select="$context" mode="_static_tabs_2.override"><xsl:with-param name="context" select="."></xsl:with-param><xsl:with-param name="index" select="$index"></xsl:with-param><xsl:with-param name="selected_index" select="$selected_index"></xsl:with-param></xsl:apply-templates></xsl:when><xsl:when test="$index=3"><xsl:apply-templates select="$context" mode="_static_tabs_3.override"><xsl:with-param name="context" select="."></xsl:with-param><xsl:with-param name="index" select="$index"></xsl:with-param><xsl:with-param name="selected_index" select="$selected_index"></xsl:with-param></xsl:apply-templates></xsl:when></xsl:choose></xsl:template><xsl:template match="*" mode="_static_tabs_1.override"><xsl:param name="context"></xsl:param><xsl:param name="index"></xsl:param><xsl:param name="selected_index"></xsl:param></xsl:template><xsl:template match="*" mode="_static_tabs_2.override"><xsl:param name="context"></xsl:param><xsl:param name="index"></xsl:param><xsl:param name="selected_index"></xsl:param></xsl:template><xsl:template match="*" mode="_static_tabs_3.override"><xsl:param name="context"></xsl:param><xsl:param name="index"></xsl:param><xsl:param name="selected_index"></xsl:param></xsl:template></xsl:transform>