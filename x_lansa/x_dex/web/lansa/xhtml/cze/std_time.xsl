<?xml version="1.0" encoding="UTF-8"?><!--(c) 2004, 2012 LANSA--><!--XHTML Standard time visualization--><!--$Workfile:: std_time.xsl $--><!--$UTCDate:: 2013-01-03 00:26:31Z $--><!--$Revision:: 17 $--><xsl:transform version="1.0" exclude-result-prefixes="lxml wd xslt" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:xslt="http://www.lansa.com/2002/XSL/Transform-Alias" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design" xmlns="http://www.w3.org/1999/xhtml"><xsl:import href="std_variables.xsl"></xsl:import><xsl:import href="std_types.xsl"></xsl:import><xsl:import href="std_datetime.xsl"></xsl:import><xsl:output method="xml" omit-xml-declaration="yes" encoding="UTF-8" indent="yes"></xsl:output><xsl:namespace-alias stylesheet-prefix="xslt" result-prefix="xsl"></xsl:namespace-alias><xsl:template name="std_time"><xsl:param name="name" select="concat('o', generate-id())"></xsl:param><xsl:param name="value"></xsl:param><xsl:param name="time_mask" select="'HH:mm:ss'"></xsl:param><xsl:param name="display_mode"></xsl:param><xsl:param name="size" select="11"></xsl:param><xsl:param name="hide_if" select="false()"></xsl:param><xsl:param name="allow_sqlnull" select="false()"></xsl:param><xsl:param name="tab_index"></xsl:param><xsl:param name="title"></xsl:param><xsl:param name="read_only" select="false()"></xsl:param><xsl:param name="disabled" select="false()"></xsl:param><xsl:param name="class" select="'text'"></xsl:param><xsl:param name="pos_absolute"></xsl:param><xsl:param name="width"></xsl:param><xsl:param name="onchange_script"></xsl:param><xsl:if test="not($hide_if) or $lweb_design_mode"><div class="std_datetime ui-widget"><xsl:attribute name="style"><xsl:if test="$pos_absolute"><xsl:call-template name="make_size_and_pos_style_v2.private"><xsl:with-param name="caller_name" select="'std_time.xsl'"></xsl:with-param><xsl:with-param name="pos_absolute" select="$pos_absolute"></xsl:with-param></xsl:call-template></xsl:if><xsl:choose><xsl:when test="$display_mode = 'hidden'">display: none;</xsl:when><xsl:otherwise>display: inline;</xsl:otherwise></xsl:choose></xsl:attribute><xsl:comment></xsl:comment><xsl:choose><xsl:when test="$display_mode != 'output'"><xsl:if test="not($lweb_design_mode) or key('design_doc_name', 'std_datetime.xsl')"><input type="hidden" name="{$name}" value="{$value}" /></xsl:if><xsl:if test="$display_mode != 'hidden'"><input class="{$class}" size="{$size}" name="__{$name}_PROXY" value="{$value}" onblur="stdDateTimeOnBlur(event);" onfocus="stdDateTimeOnFocus(event);"><xsl:if test="$width"><xsl:attribute name="style"><xsl:call-template name="make_size_and_pos_style_v2.private"><xsl:with-param name="caller_name" select="'std_datetime.xsl'"></xsl:with-param><xsl:with-param name="width" select="$width"></xsl:with-param></xsl:call-template></xsl:attribute></xsl:if><xsl:if test="$tab_index != ''"><xsl:attribute name="tabindex"><xsl:value-of select="$tab_index"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$title != ''"><xsl:attribute name="title"><xsl:value-of select="$title"></xsl:value-of></xsl:attribute></xsl:if><xsl:attribute name="onchange"><xsl:if test="$onchange_script!=''"><xsl:value-of select="$onchange_script"></xsl:value-of><xsl:text>;</xsl:text></xsl:if><xsl:text></xsl:text>return stdDateTimeProxyChanged(this);<xsl:text></xsl:text></xsl:attribute><xsl:if test="boolean($read_only)"><xsl:attribute name="readonly">readonly</xsl:attribute></xsl:if><xsl:if test="boolean($disabled)"><xsl:attribute name="disabled">disabled</xsl:attribute></xsl:if></input></xsl:if></xsl:when><xsl:otherwise><span id="{$name}" __isovalue="{$value}"><br /></span></xsl:otherwise></xsl:choose><xsl:comment /></div><xsl:if test="$display_mode != 'hidden'"><script type="text/javascript"><xsl:text disable-output-escaping="yes">//&lt;![CDATA[
					</xsl:text><xsl:text>stdDateTimeInitDiv('</xsl:text><xsl:value-of select="$name"></xsl:value-of><xsl:text>', '</xsl:text><xsl:value-of select="$display_mode"></xsl:value-of><xsl:text>', 'timeonly', '', '</xsl:text><xsl:value-of select="$time_mask"></xsl:value-of><xsl:text>', false, </xsl:text><xsl:value-of select="boolean($allow_sqlnull)"></xsl:value-of><xsl:text>);</xsl:text><xsl:text disable-output-escaping="yes">//]]&gt;</xsl:text><xsl:text>&#32;</xsl:text></script></xsl:if></xsl:if></xsl:template></xsl:transform>