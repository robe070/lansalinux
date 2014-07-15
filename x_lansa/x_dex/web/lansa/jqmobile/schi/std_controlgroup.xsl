<?xml version="1.0" encoding="UTF-8"?><!--(c) 2012, 2014 LANSA--><!--jQuery Mobile control group--><!--$UTCDate:: 2014-04-02 04:02:49Z $--><!--$Revision:: 18 $--><xsl:transform version="1.0" exclude-result-prefixes="lxml wd msxsl exslt" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design" xmlns:msxsl="urn:schemas-microsoft-com:xslt" xmlns:exslt="http://exslt.org/common" xmlns="http://www.w3.org/1999/xhtml"><xsl:import href="std_types.xsl"></xsl:import><xsl:output method="xml" omit-xml-declaration="yes" encoding="UTF-8" indent="no"></xsl:output><lxml:data><lxml:internal_id id="std_controlgroup"></lxml:internal_id></lxml:data><xsl:template name="std_controlgroup"><xsl:param name="id"></xsl:param><xsl:param name="class" select="''"></xsl:param><xsl:param name="fieldContainWrapper" select="true()"></xsl:param><xsl:param name="hideIf" select="false()"></xsl:param><xsl:param name="hideLabel" select="false()"></xsl:param><xsl:param name="label"></xsl:param><xsl:param name="mini" select="false()"></xsl:param><xsl:param name="orientation" select="'vertical'"></xsl:param><xsl:param name="style" select="''"></xsl:param><xsl:param name="swatch" select="''"></xsl:param><xsl:param name="internal_id" select="document('')/*/lxml:data/lxml:internal_id[@id='std_controlgroup']"></xsl:param><xsl:if test="not($hideIf) or $lweb_design_mode"><xsl:variable name="theFieldElement"><div data-role="controlgroup" data-enhanced="true"><xsl:attribute name="class"><xsl:text>ui-controlgroup ui-corner-all ui-controlgroup-</xsl:text><xsl:value-of select="$orientation"></xsl:value-of><xsl:if test="$mini"> ui-mini</xsl:if><xsl:if test="$swatch"> ui-group-theme-<xsl:value-of select="$swatch"></xsl:value-of></xsl:if><xsl:if test="$class != ''"><xsl:value-of select="concat(' ', $class)"></xsl:value-of></xsl:if></xsl:attribute><xsl:if test="$style != ''"><xsl:attribute name="style"><xsl:value-of select="$style"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$orientation = 'horizontal'"><xsl:attribute name="data-type">horizontal</xsl:attribute></xsl:if><xsl:if test="$swatch!= ''"><xsl:attribute name="data-theme"><xsl:value-of select="$swatch"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$mini"><xsl:attribute name="data-mini">true</xsl:attribute></xsl:if><xsl:if test="not($hideLabel) and $label != ''"><div role="heading" class="ui-controlgroup-label"><legend><xsl:value-of select="$label"></xsl:value-of></legend></div></xsl:if><div class="ui-controlgroup-controls"><xsl:apply-templates select="$internal_id" mode="std_controlgroup.private.override"><xsl:with-param name="context" select="."></xsl:with-param><xsl:with-param name="index" select="1"></xsl:with-param></xsl:apply-templates><xsl:comment /></div></div></xsl:variable><xsl:choose><xsl:when test="$fieldContainWrapper = false()"><xsl:choose><xsl:when test="$lweb_is_msxsl_nodeset"><xsl:copy-of select="msxsl:node-set($theFieldElement)"></xsl:copy-of></xsl:when><xsl:when test="$lweb_is_exslt_nodeset"><xsl:copy-of select="exslt:node-set($theFieldElement)"></xsl:copy-of></xsl:when></xsl:choose></xsl:when><xsl:otherwise><div class="ui-field-contain"><xsl:choose><xsl:when test="$lweb_is_msxsl_nodeset"><xsl:copy-of select="msxsl:node-set($theFieldElement)"></xsl:copy-of></xsl:when><xsl:when test="$lweb_is_exslt_nodeset"><xsl:copy-of select="exslt:node-set($theFieldElement)"></xsl:copy-of></xsl:when></xsl:choose><xsl:comment /></div></xsl:otherwise></xsl:choose></xsl:if></xsl:template><xsl:template match="lxml:internal_id[@id='std_controlgroup']" mode="std_controlgroup.private.override"><xsl:param name="context"></xsl:param><xsl:param name="index"></xsl:param><xsl:choose><xsl:when test="$index=1"><xsl:apply-templates select="$context" mode="_std_controlgroup_content_1.override"></xsl:apply-templates></xsl:when></xsl:choose></xsl:template><xsl:template match="*" mode="_std_controlgroup_content_1.override"></xsl:template></xsl:transform>