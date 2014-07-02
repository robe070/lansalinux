<?xml version="1.0" encoding="UTF-8"?>

<!-- (c) 2002, 2014 LANSA                              -->
<!-- TSP Global Helper Templates                       -->
<!-- $Workfile:: tsp_global_helper.xsl               $ -->
<!-- $Revision:: 5                                   $ -->

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

	<!--	Purpose    : Computes input number step value
			Parameter 1: Number of decimals
	 -->
	<xsl:template name="make_step">
		<xsl:param name="decimals"/>
		<xsl:param name="step" select="'0.'" />
		<xsl:choose>
			<xsl:when test="$decimals > 1">
				<xsl:call-template name="make_step">
					<xsl:with-param name="decimals" select="$decimals - 1" />
					<xsl:with-param name="step" select="concat($step, '0')" />
				</xsl:call-template>
			</xsl:when>
			<xsl:otherwise><xsl:value-of select="concat($step, '1')"/></xsl:otherwise>
		</xsl:choose>
	</xsl:template>

	<!--	Purpose    : Creates the field type info attribute value
			Parameter 1: Field/column node
	 -->
	<xsl:template name="fieldTypeInfoString">
		<xsl:param name="field"/>
		<xsl:variable name="format" select="$field/tsml:format"/>
		<xsl:variable name="formatType" select="$format/tsml:type/text()"/>
		<xsl:value-of select="$formatType"/>
		<xsl:choose>
			<xsl:when test="($formatType = 'integer') or ($formatType = 'float')">
				<xsl:text>|</xsl:text>
				<xsl:value-of select="$format/tsml:max-length"/>
			</xsl:when>
			<xsl:when test="($formatType = 'packed') or ($formatType = 'signed') or ($formatType = 'dec')">
				<xsl:text>|</xsl:text>
				<xsl:value-of select="$format/tsml:total-digits"/>
				<xsl:text>|</xsl:text>
				<xsl:value-of select="$format/tsml:fraction-digits"/>
				<xsl:text>|</xsl:text>
				<xsl:value-of select="$format/tsml:decimal-separator"/>
			</xsl:when>
			<xsl:when test="($formatType = 'alpha') or ($formatType = 'char') or ($formatType = 'varchar') or ($formatType = 'nchar') or ($formatType = 'nvarchar')">
				<xsl:text>|</xsl:text>
				<xsl:value-of select="$format/tsml:keyboardshift"/>
				<xsl:text>|</xsl:text>
				<xsl:value-of select="$format/tsml:max-length"/>
			</xsl:when>
		</xsl:choose>
	</xsl:template>
</xsl:transform>