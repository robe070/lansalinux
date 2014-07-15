<?xml version="1.0" encoding="UTF-8"?><!--(c) 2011, 2014 LANSA--><!--jqMobile Standard Header--><!--$Workfile:: std_header.xsl $--><!--$UTCDate:: 2014-03-12 03:46:11Z $--><!--$Revision:: 8 $--><xsl:transform version="1.0" exclude-result-prefixes="lxml wd" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design" xmlns="http://www.w3.org/1999/xhtml"><xsl:import href="std_types.xsl"></xsl:import><xsl:output method="xml" omit-xml-declaration="yes" encoding="UTF-8" indent="yes"></xsl:output><lxml:data><lxml:internal_id id="std_header"></lxml:internal_id></lxml:data><xsl:template name="std_header"><xsl:param name="id"></xsl:param><xsl:param name="fullscreenMode" select="false()"></xsl:param><xsl:param name="hideIf" select="false()"></xsl:param><xsl:param name="position" select="''"></xsl:param><xsl:param name="swatch" select="''"></xsl:param><xsl:param name="internal_id" select="document('')/*/lxml:data/lxml:internal_id[@id='std_header']"></xsl:param><xsl:if test="not($hideIf) or $lweb_design_mode"><div data-role="header"><xsl:if test="$id != ''"><xsl:attribute name="id"><xsl:value-of select="$id"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$swatch != ''"><xsl:attribute name="data-theme"><xsl:value-of select="$swatch"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$position = 'fixed'"><xsl:attribute name="data-position">fixed</xsl:attribute><xsl:if test="$fullscreenMode"><xsl:attribute name="data-fullscreen">true</xsl:attribute></xsl:if></xsl:if><xsl:apply-templates select="$internal_id" mode="std_header.private.override"><xsl:with-param name="context" select="."></xsl:with-param><xsl:with-param name="index" select="1"></xsl:with-param></xsl:apply-templates><xsl:comment /></div></xsl:if></xsl:template><xsl:template match="lxml:internal_id[@id='std_header']" mode="std_header.private.override"><xsl:param name="context"></xsl:param><xsl:param name="index"></xsl:param><xsl:choose><xsl:when test="$index=1"><xsl:apply-templates select="$context" mode="_std_header_1.override"></xsl:apply-templates></xsl:when></xsl:choose></xsl:template><xsl:template match="*" mode="_std_header_1.override"></xsl:template></xsl:transform>