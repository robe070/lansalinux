<?xml version="1.0" encoding="UTF-8"?><!--(c) 2003, 2012 LANSA--><!--XHTML Standard float--><!--$Workfile:: std_float.xsl $--><!--$UTCDate:: 2012-12-21 02:41:01Z $--><!--$Revision:: 14 $--><xsl:transform version="1.0" exclude-result-prefixes="lxml wd" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design" xmlns="http://www.w3.org/1999/xhtml"><xsl:import href="std_types.xsl"></xsl:import><xsl:import href="std_util.xsl"></xsl:import><xsl:import href="std_keys.xsl"></xsl:import><xsl:import href="std_input.xsl"></xsl:import><xsl:output method="xml" omit-xml-declaration="yes" encoding="UTF-8" indent="yes"></xsl:output><xsl:template name="std_float"><xsl:param name="name"></xsl:param><xsl:param name="value"></xsl:param><xsl:param name="display_mode"></xsl:param><xsl:param name="maxlength"></xsl:param><xsl:param name="size"></xsl:param><xsl:param name="type" select="'text'"></xsl:param><xsl:param name="hide_if" select="false()"></xsl:param><xsl:param name="class" select="'number'"></xsl:param><xsl:param name="tab_index"></xsl:param><xsl:param name="title"></xsl:param><xsl:param name="read_only" select="false()"></xsl:param><xsl:param name="disabled" select="false()"></xsl:param><xsl:param name="pos_absolute"></xsl:param><xsl:param name="width"></xsl:param><xsl:param name="height"></xsl:param><xsl:if test="not($hide_if) or $lweb_design_mode"><span class="ui-widget"><xsl:choose><xsl:when test="$display_mode!='output'"><input name="{$name}" id="{$name}" class="{$class}" value="{$value}" size="{$maxlength}" maxlength="{$maxlength}" onblur="stdOnBlur(event);" onfocus="stdOnFocus(event);"><xsl:attribute name="type"><xsl:choose><xsl:when test="$display_mode='hidden'"><xsl:text>hidden</xsl:text></xsl:when><xsl:otherwise><xsl:value-of select="$type"></xsl:value-of></xsl:otherwise></xsl:choose></xsl:attribute><xsl:if test="$pos_absolute or $height or $width"><xsl:attribute name="style"><xsl:call-template name="make_size_and_pos_style_v2.private"><xsl:with-param name="caller_name" select="'std_float.xsl'"></xsl:with-param><xsl:with-param name="pos_absolute" select="$pos_absolute"></xsl:with-param><xsl:with-param name="height" select="$height"></xsl:with-param><xsl:with-param name="width" select="$width"></xsl:with-param></xsl:call-template></xsl:attribute></xsl:if><xsl:if test="$tab_index != ''"><xsl:attribute name="tabindex"><xsl:value-of select="$tab_index"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$title != ''"><xsl:attribute name="title"><xsl:value-of select="$title"></xsl:value-of></xsl:attribute></xsl:if><xsl:attribute name="onchange"><xsl:text>return isValidFloat(this, </xsl:text><xsl:choose><xsl:when test="$size!=''"><xsl:value-of select="$size"></xsl:value-of></xsl:when><xsl:otherwise><xsl:text>8</xsl:text></xsl:otherwise></xsl:choose><xsl:text>);</xsl:text></xsl:attribute><xsl:if test="boolean($read_only)"><xsl:attribute name="readonly">readonly</xsl:attribute></xsl:if><xsl:if test="boolean($disabled)"><xsl:attribute name="disabled">disabled</xsl:attribute></xsl:if></input><script type="text/javascript"><xsl:text disable-output-escaping="yes">//&lt;![CDATA[
</xsl:text><xsl:text></xsl:text>stdFloatFixValues('<xsl:value-of select="$name"></xsl:value-of>', true);
<xsl:text disable-output-escaping="yes">//]]&gt;</xsl:text></script></xsl:when><xsl:otherwise><span><xsl:if test="$title != ''"><xsl:attribute name="title"><xsl:value-of select="$title"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$class!=''"><xsl:attribute name="class"><xsl:value-of select="$class"></xsl:value-of></xsl:attribute></xsl:if><xsl:value-of select="$value"></xsl:value-of><xsl:comment /></span></xsl:otherwise></xsl:choose><xsl:comment /></span></xsl:if></xsl:template></xsl:transform>