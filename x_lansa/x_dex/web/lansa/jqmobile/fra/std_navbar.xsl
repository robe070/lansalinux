<?xml version="1.0" encoding="UTF-8"?><!--(c) 2011, 2014 LANSA--><!--jqMobile Navigation bar--><!--$UTCDate:: 2014-04-02 23:27:46Z $--><!--$Revision:: 11 $--><xsl:transform version="1.0" exclude-result-prefixes="lxml wd tsml" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design" xmlns:tsml="http://www.lansa.com/2002/XML/Generation-Metadata" xmlns="http://www.w3.org/1999/xhtml"><xsl:import href="std_types.xsl"></xsl:import><xsl:output method="xml" omit-xml-declaration="yes" encoding="UTF-8" indent="no"></xsl:output><lxml:data><lxml:internal_id id="std_navbar"></lxml:internal_id></lxml:data><xsl:template name="std_navbar"><xsl:param name="id"></xsl:param><xsl:param name="class" select="''"></xsl:param><xsl:param name="hideIf" select="false()"></xsl:param><xsl:param name="iconPosition" select="''"></xsl:param><xsl:param name="swatch" select="''"></xsl:param><xsl:param name="internal_id" select="document('')/*/lxml:data/lxml:internal_id[@id='std_navbar']"></xsl:param><xsl:if test="not($hideIf) or $lweb_design_mode"><div><xsl:if test="$swatch != ''"><xsl:attribute name="class">ui-body-<xsl:value-of select="$swatch"></xsl:value-of></xsl:attribute></xsl:if><div data-role="navbar"><ul><xsl:if test="$id != ''"><xsl:attribute name="id"><xsl:value-of select="$id"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$iconPosition != ''"><xsl:attribute name="data-iconpos"><xsl:value-of select="$iconPosition"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$class != ''"><xsl:attribute name="class"><xsl:value-of select="concat('std_anchor ',$class)"></xsl:value-of></xsl:attribute></xsl:if><xsl:apply-templates select="$internal_id" mode="std_navbar.private.override"><xsl:with-param name="context" select="."></xsl:with-param><xsl:with-param name="index" select="1"></xsl:with-param></xsl:apply-templates><xsl:comment /></ul></div></div></xsl:if></xsl:template><xsl:template match="lxml:internal_id[@id='std_navbar']" mode="std_navbar.private.override"><xsl:param name="context"></xsl:param><xsl:param name="index"></xsl:param><xsl:choose><xsl:when test="$index=1"><xsl:apply-templates select="$context" mode="_std_navbar_content_1.override"></xsl:apply-templates></xsl:when></xsl:choose></xsl:template><xsl:template match="*" mode="_std_navbar_content_1.override"></xsl:template></xsl:transform>