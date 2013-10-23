<?xml version="1.0" encoding="UTF-8"?>

<!-- (c) 2002, 2013 LANSA                              -->
<!-- TSP Global Helper Templates                       -->
<!-- $Workfile:: tsp_global_helper.xsl               $ -->
<!-- $Revision:: 4                                   $ -->

<xsl:transform version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:xslt="http://www.lansa.com/2002/XSL/Transform-Alias" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data"
					xmlns:tsml="http://www.lansa.com/2002/XML/Generation-Metadata" xmlns="http://www.w3.org/1999/xhtml" exclude-result-prefixes="tsml">

	<xsl:variable name="apos">'</xsl:variable>

	<!-- Helper templates -->

	<!--	Purpose    : Pad text to a fixed length
			Parameter 1: Text value to pad
			Parameter 2: Length of padded value
	 -->
	<xsl:template name="pad">
		<xsl:param name="text"/>
		<xsl:param name="padded-length"/>
		<!-- 61 spaces -->
		<xsl:variable name="spaces" select="'                                                             '"/>
		<xsl:value-of select="substring(concat($text, $spaces), 1, $padded-length)"/>
	</xsl:template>

	<!--	Purpose    : Inserts a new line in the output result tree
			Parameters : None
	 -->
	<xsl:template name="new_line">
		<xsl:text>&#xA;</xsl:text>
	</xsl:template>

	<!--	Purpose    : Inserts a comment continuation line
			Parameters : None
	 -->
	<xsl:template name="comment_new_line">
		<xsl:text>&#xA;    </xsl:text>
	</xsl:template>

	<!--	Purpose    : Inserts a blank line in the output result tree
			Parameters : None
	 -->
	<xsl:template name="blank_line">
		<xsl:text>&#xA;&#xA;</xsl:text>
	</xsl:template>

	<!--	Purpose    : Translates text to lowercase
			Parameter 1: Text value to translate
	 -->
	<xsl:template name="to_lowercase">
		<xsl:param name="text"/>
		<xsl:value-of select="translate($text, 'ABCDEFGHIJKLMNOPQRSTUVWXYZ', 'abcdefghijklmnopqrstuvwxyz' )"/>
	</xsl:template>

</xsl:transform>