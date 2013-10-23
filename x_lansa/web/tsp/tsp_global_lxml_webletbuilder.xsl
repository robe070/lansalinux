<?xml version="1.0" encoding="UTF-8"?>

<!-- (c) 2002, 2011 LANSA                              -->
<!-- LANSA Runtime-Data Input XML Weblet Builder       -->
<!-- $Workfile:: tsp_global_lxml_webletbuilder.xsl   $ -->
<!-- $Revision:: 4                                   $ -->
 
<xsl:transform version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:xslt="http://www.lansa.com/2002/XSL/Transform-Alias" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns:tsml="http://www.lansa.com/2002/XML/Generation-Metadata" exclude-result-prefixes="tsml xslt">

	<xsl:import href="tsp_global_lxml_common.xsl"/>
	<xsl:output method="xml" omit-xml-declaration="no" encoding="UTF-8" indent="yes"/>
	<xsl:namespace-alias stylesheet-prefix="xslt" result-prefix="xsl"/>

	<xsl:variable name="weblet_name" select="/tsml:data/tsml:context/tsml:weblet/tsml:name"/>

	<xsl:template match="/">
		<xsl:call-template name="blank_line"/>
		<xsl:comment>
			<xsl:text> Name       : </xsl:text><xsl:value-of select="$weblet_name"/><xsl:call-template name="comment_new_line"/>
			<xsl:text> Description: </xsl:text><xsl:value-of select="/tsml:data/tsml:context/tsml:weblet/tsml:title"/><xsl:call-template name="comment_new_line"/>
			<xsl:text> Timestamp  : </xsl:text><xsl:value-of select="/tsml:data/tsml:context/tsml:timestamp"/><xsl:call-template name="comment_new_line"/>
		</xsl:comment>
		<xsl:call-template name="blank_line"/>
			<xsl:apply-templates select="*"/>
		<xsl:call-template name="blank_line"/>
	</xsl:template>

</xsl:transform>
