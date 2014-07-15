<?xml version="1.0" encoding="UTF-8"?><!--(c) 2014 LANSA--><!--jqMobile Standard image--><!--$Workfile:: std_image.xsl $--><!--$UTCDate:: 2014-05-15 07:21:23Z $--><!--$Revision:: 8 $--><xsl:transform version="1.0" exclude-result-prefixes="lxml wd xslt" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:xslt="http://www.lansa.com/2002/XSL/Transform-Alias" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design" xmlns="http://www.w3.org/1999/xhtml"><xsl:import href="std_variables.xsl"></xsl:import><xsl:import href="std_util.xsl"></xsl:import><xsl:import href="std_types.xsl"></xsl:import><xsl:output method="xml" omit-xml-declaration="yes" encoding="UTF-8" indent="yes"></xsl:output><xsl:namespace-alias stylesheet-prefix="xslt" result-prefix="xsl"></xsl:namespace-alias><xsl:template name="std_image"><xsl:param name="relativeImagePath" select="''"></xsl:param><xsl:param name="lazyLoad" select="true()"></xsl:param><xsl:param name="class"></xsl:param><xsl:param name="width"></xsl:param><xsl:param name="height"></xsl:param><xsl:param name="hideIf" select="false()"></xsl:param><xsl:param name="caption" select="''"></xsl:param><xsl:if test="not($hideIf) or $lweb_design_mode"><xsl:variable name="fullImagePath" select="concat($lweb_images_path, '/', $relativeImagePath)"></xsl:variable><img alt="{$caption}"><xsl:choose><xsl:when test="$lazyLoad"><xsl:attribute name="class"><xsl:choose><xsl:when test="boolean($class)">std_lazy <xsl:value-of select="$class"></xsl:value-of></xsl:when><xsl:otherwise>std_lazy</xsl:otherwise></xsl:choose></xsl:attribute><xsl:attribute name="src"><xsl:value-of select="concat($lweb_images_path, '/icons/misc/gray.gif')"></xsl:value-of></xsl:attribute><xsl:attribute name="data-original"><xsl:value-of select="$fullImagePath"></xsl:value-of></xsl:attribute></xsl:when><xsl:otherwise><xsl:if test="boolean($class)"><xsl:attribute name="class"><xsl:value-of select="$class"></xsl:value-of></xsl:attribute></xsl:if><xsl:attribute name="src"><xsl:value-of select="$fullImagePath"></xsl:value-of></xsl:attribute></xsl:otherwise></xsl:choose><xsl:variable name="style"><xsl:if test="$width">width:<xsl:value-of select="$width"></xsl:value-of>;</xsl:if><xsl:if test="$height">height:<xsl:value-of select="$height"></xsl:value-of>;</xsl:if></xsl:variable><xsl:if test="$style != ''"><xsl:attribute name="style"><xsl:value-of select="$style"></xsl:value-of></xsl:attribute></xsl:if></img></xsl:if></xsl:template></xsl:transform>