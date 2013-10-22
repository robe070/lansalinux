<?xml version="1.0" encoding="UTF-8"?>

<!-- (c) 2002, 2011 LANSA                              -->
<!-- LANSA Runtime-Data Input XML Common Templates     -->
<!-- $Workfile:: tsp_global_lxml_common.xsl          $ -->
<!-- $Revision:: 8                                   $ -->

<xsl:transform version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:xslt="http://www.lansa.com/2002/XSL/Transform-Alias" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns:tsml="http://www.lansa.com/2002/XML/Generation-Metadata" exclude-result-prefixes="tsml xslt">

	<xsl:import href="tsp_global_helper.xsl"/>
	<xsl:output method="xml" omit-xml-declaration="no" encoding="UTF-8" indent="yes"/>
	<xsl:namespace-alias stylesheet-prefix="xslt" result-prefix="xsl"/>

	<xsl:template match="tsml:data">
		<lxml:data>
			<xsl:call-template name="blank_line"/>
			<xsl:apply-templates select="*"/>
		</lxml:data>
	</xsl:template>

	<xsl:template match="tsml:imports[tsml:technology-service]">
		<lxml:imports>
			<xsl:apply-templates select="*"/>
		</lxml:imports>
	</xsl:template>

	<xsl:template match="tsml:imports/tsml:technology-service[tsml:import]">
		<lxml:technology-service name="{@name}">
			<xsl:apply-templates select="*"/>
		</lxml:technology-service>
	</xsl:template>

	<xsl:template match="tsml:imports/tsml:technology-service/tsml:import">
		<lxml:import name="{@name}"/>
	</xsl:template>

	<xsl:template match="tsml:context">
		<lxml:context>
			<xsl:apply-templates select="*"/>
		</lxml:context>
		<xsl:call-template name="blank_line"/>
	</xsl:template>

	<xsl:template match="tsml:context/tsml:*[text()]">
		<xsl:element name="lxml:{local-name()}" namespace="http://www.lansa.com/2002/XML/Runtime-Data">
			<xsl:for-each select="@*"><xsl:copy/></xsl:for-each>
			<xsl:value-of select="text()"/>
		</xsl:element>
	</xsl:template>

	<xsl:template match="tsml:context/tsml:*[not(text())]">
		<xsl:element name="lxml:{local-name()}" namespace="http://www.lansa.com/2002/XML/Runtime-Data">
			<xsl:for-each select="@*"><xsl:copy/></xsl:for-each>
		</xsl:element>
	</xsl:template>

	<!-- Skip WAM alternate name -->
	<xsl:template match="tsml:context/tsml:webapplication-alt-name">
	</xsl:template>

	<!-- Skip layout-name -->
	<xsl:template match="tsml:context/tsml:layout-name">
	</xsl:template>

	<!-- Skip timestamp -->
	<xsl:template match="tsml:context/tsml:timestamp">
	</xsl:template>

	<!-- Skip requester -->
	<xsl:template match="tsml:context/tsml:requester">
	</xsl:template>

	<!-- Skip weblet context -->
	<xsl:template match="tsml:context/tsml:weblet">
	</xsl:template>

	<xsl:template match="tsml:replaced-lxml">
		<xsl:apply-templates select="tsml:data"/>
	</xsl:template>

	<xsl:template match="tsml:replaced-lxml/tsml:data">
		<xsl:variable name="tsmlnode" select="."/>
		<xsl:variable name="gentsp" select="/tsml:data/tsml:technology-service-list/tsml:technology-service[@used_by = $tsmlnode/@used_by]"/>

		<!-- If TSP stylesheet is being (re)generated and there's only XSL for the default language, remove the TSML node -->
		<xsl:if test="not($gentsp) or ($gentsp/@lang-count = -1) or ($gentsp/@lang-count > 1)">
			<xsl:copy-of select="."/>
			<xsl:call-template name="blank_line"/>
		</xsl:if>
	</xsl:template>

	<xsl:template match="tsml:variables">
		<lxml:variables/>
		<xsl:call-template name="blank_line"/>
	</xsl:template>

	<!-- Ignore other elements -->
	<xsl:template match="tsml:*">
	</xsl:template>

</xsl:transform>
