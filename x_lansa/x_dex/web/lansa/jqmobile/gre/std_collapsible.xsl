<?xml version="1.0" encoding="UTF-8"?><!--(c) 2011, 2012 LANSA--><!--jqMobile Standard Collapsible--><!--$Workfile:: std_collapsible.xsl $--><!--$UTCDate:: 2012-12-20 21:36:01Z $--><!--$Revision:: 9 $--><xsl:transform version="1.0" exclude-result-prefixes="lxml wd" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design" xmlns="http://www.w3.org/1999/xhtml"><xsl:import href="std_types.xsl"></xsl:import><xsl:output method="xml" omit-xml-declaration="yes" encoding="UTF-8" indent="yes"></xsl:output><lxml:data><lxml:internal_id id="std_collapsible"><lxml:item>Header</lxml:item><lxml:item>Content</lxml:item></lxml:internal_id></lxml:data><xsl:template name="std_collapsible"><xsl:param name="id"></xsl:param><xsl:param name="collapsed" select="true()"></xsl:param><xsl:param name="contentSwatch" select="''"></xsl:param><xsl:param name="headerLevel" select="3"></xsl:param><xsl:param name="headerSwatch" select="''"></xsl:param><xsl:param name="headerText" select="'Collapsible Block'"></xsl:param><xsl:param name="hideIf" select="false()"></xsl:param><xsl:param name="inset" select="true()"></xsl:param><xsl:param name="internal_id" select="document('')/*/lxml:data/lxml:internal_id[@id='std_collapsible']"></xsl:param><xsl:if test="not($hideIf) or $lweb_design_mode"><div data-role="collapsible"><xsl:if test="$id != ''"><xsl:attribute name="id"><xsl:value-of select="$id"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$collapsed = false()"><xsl:attribute name="data-collapsed">false</xsl:attribute></xsl:if><xsl:if test="$headerSwatch != ''"><xsl:attribute name="data-theme"><xsl:value-of select="$headerSwatch"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$contentSwatch != ''"><xsl:attribute name="data-content-theme"><xsl:value-of select="$contentSwatch"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$inset != true()"><xsl:attribute name="data-inset">false</xsl:attribute></xsl:if><xsl:element name="{concat('h',$headerLevel)}"><xsl:apply-templates select="$internal_id/lxml:item[1]" mode="std_collapsible.private.override"><xsl:with-param name="context" select="."></xsl:with-param><xsl:with-param name="index" select="1"></xsl:with-param><xsl:with-param name="headerText" select="$headerText"></xsl:with-param></xsl:apply-templates></xsl:element><xsl:apply-templates select="$internal_id/lxml:item[2]" mode="std_collapsible.private.override"><xsl:with-param name="context" select="."></xsl:with-param><xsl:with-param name="index" select="2"></xsl:with-param></xsl:apply-templates><xsl:comment /></div></xsl:if></xsl:template><xsl:template match="lxml:internal_id[@id='std_collapsible']/lxml:item" mode="std_collapsible.private.override"><xsl:param name="context"></xsl:param><xsl:param name="index"></xsl:param><xsl:param name="headerText"></xsl:param><xsl:choose><xsl:when test="$index=1"><xsl:apply-templates select="$context" mode="_std_collapsible_1.override"><xsl:with-param name="headerText" select="$headerText"></xsl:with-param></xsl:apply-templates></xsl:when><xsl:when test="$index=2"><xsl:apply-templates select="$context" mode="_std_collapsible_2.override"></xsl:apply-templates></xsl:when></xsl:choose></xsl:template><xsl:template match="*" mode="_std_collapsible_1.override"><xsl:param name="headerText"></xsl:param><xsl:value-of select="$headerText"></xsl:value-of></xsl:template><xsl:template match="*" mode="_std_collapsible_2.override">
		Collapsible block content
	</xsl:template></xsl:transform>