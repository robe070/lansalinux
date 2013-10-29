<?xml version="1.0" encoding="UTF-8"?><!--(c) 2003, 2012 LANSA--><!--XHTML Standard boolean--><!--$Workfile:: std_boolean.xsl $--><!--$UTCDate:: 2012-12-20 05:38:03Z $--><!--$Revision:: 17 $--><xsl:transform version="1.0" exclude-result-prefixes="lxml wd" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design" xmlns="http://www.w3.org/1999/xhtml"><xsl:import href="std_types.xsl"></xsl:import><xsl:import href="std_util.xsl"></xsl:import><xsl:import href="std_checkbox.xsl"></xsl:import><xsl:output method="xml" omit-xml-declaration="yes" encoding="UTF-8" indent="yes"></xsl:output><xsl:template name="std_boolean"><xsl:param name="name" select="''"></xsl:param><xsl:param name="value" select="''"></xsl:param><xsl:param name="display_mode"></xsl:param><xsl:param name="hide_if" select="false()"></xsl:param><xsl:param name="pos_absolute"></xsl:param><xsl:param name="class" select="'std_checkbox'"></xsl:param><xsl:param name="mouseover_class"></xsl:param><xsl:param name="tab_index"></xsl:param><xsl:if test="not($hide_if) or $lweb_design_mode"><span class="ui-widget"><xsl:attribute name="style"><xsl:text>white-space:nowrap;</xsl:text><xsl:value-of select="$pos_absolute"></xsl:value-of></xsl:attribute><xsl:if test="$display_mode != 'output' and (not($lweb_design_mode) or key('design_doc_name', 'std_boolean.xsl'))"><input type="hidden" name="{$name}" value="{$value}" /></xsl:if><xsl:if test="$display_mode != 'hidden' or $lweb_design_mode"><input class="{$class}" id="__{$name}_PROXY" type="checkbox" name="__{$name}_PROXY" value="{$value}"><xsl:attribute name="onclick"><xsl:text></xsl:text>stdCheckboxClicked(this, '', '', '', '', '', '<xsl:value-of select="$name"></xsl:value-of>', 'true', 'false');<xsl:text></xsl:text></xsl:attribute><xsl:if test="$mouseover_class"><xsl:attribute name="onmouseenter"><xsl:text></xsl:text>this.className='<xsl:value-of select="$mouseover_class"></xsl:value-of>';
							</xsl:attribute><xsl:attribute name="onmouseleave"><xsl:text></xsl:text>this.className='<xsl:value-of select="$class"></xsl:value-of>';
							</xsl:attribute></xsl:if><xsl:if test="$display_mode = 'output'"><xsl:attribute name="disabled">disabled</xsl:attribute></xsl:if><xsl:if test="$tab_index != ''"><xsl:attribute name="tabindex"><xsl:value-of select="$tab_index"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$value = 'true'"><xsl:attribute name="checked">checked</xsl:attribute></xsl:if></input></xsl:if><xsl:comment /></span></xsl:if></xsl:template></xsl:transform>