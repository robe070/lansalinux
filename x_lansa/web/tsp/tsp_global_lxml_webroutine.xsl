<?xml version="1.0" encoding="UTF-8"?>

<!-- (c) 2002, 2011 LANSA                              -->
<!-- LANSA Runtime-Data Input XML Webroutine Builder   -->
<!-- $Workfile:: tsp_global_lxml_webroutine.xsl      $ -->
<!-- $Revision:: 10                                  $ -->
 
<xsl:transform version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:xslt="http://www.lansa.com/2002/XSL/Transform-Alias" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns:tsml="http://www.lansa.com/2002/XML/Generation-Metadata" exclude-result-prefixes="tsml xslt">

	<xsl:import href="tsp_global_lxml_common.xsl"/>
	<xsl:output method="xml" omit-xml-declaration="no" encoding="UTF-8" indent="yes" cdata-section-elements="lxml:json-list"/>
	<xsl:namespace-alias stylesheet-prefix="xslt" result-prefix="xsl"/>

	<xsl:key name="replaced_field" match="/tsml:data/tsml:replaced-lxml/lxml:fields/lxml:field" use="@name"/>
	<xsl:key name="replaced_list" match="/tsml:data/tsml:replaced-lxml/lxml:lists/lxml:list" use="@name"/>

	<!-- Web application name in lower-case, for Web application specific pages -->
	<xsl:variable name="web_app" select="translate(/tsml:data/tsml:context/tsml:webapplication, 'ABCDEFGHIJKLMNOPQRSTUVWXYZ', 'abcdefghijklmnopqrstuvwxyz' )"/>

	<!-- WAM Inlining option -->
	<xsl:variable name="g_inline_all" select="/tsml:data/@inline = 'all'"/>
	<xsl:variable name="g_inline_lists" select="$g_inline_all or (/tsml:data/@inline = 'lists')"/>

	<xsl:template match="/">
		<xsl:call-template name="blank_line"/>
		<xsl:comment>
			<xsl:text> WAM       : </xsl:text><xsl:value-of select="/tsml:data/tsml:context/tsml:webapplication-alt-name"/> - <xsl:value-of select="/tsml:data/tsml:context/tsml:webapplication-title"/><xsl:call-template name="comment_new_line"/>
			<xsl:text> Webroutine: </xsl:text><xsl:value-of select="/tsml:data/tsml:context/tsml:webroutine"/> - <xsl:value-of select="/tsml:data/tsml:context/tsml:webroutine-title"/><xsl:call-template name="comment_new_line"/>
			<xsl:text> Timestamp : </xsl:text><xsl:value-of select="/tsml:data/tsml:context/tsml:timestamp"/><xsl:text> </xsl:text>
		</xsl:comment>
		<xsl:call-template name="blank_line"/>
			<xsl:apply-templates select="*"/>
		<xsl:call-template name="blank_line"/>
	</xsl:template>

	<xsl:template match="tsml:server-instructions">
		<lxml:server-instructions>
			<xsl:apply-templates select="*"/>
		</lxml:server-instructions>
		<xsl:call-template name="blank_line"/>
	</xsl:template>

	<xsl:template match="tsml:server-instructions/tsml:ssi">
		<lxml:ssi><xsl:value-of select="."/></lxml:ssi>
	</xsl:template>

	<xsl:template match="tsml:server-instructions/tsml:client-charset">
		<lxml:client-charset><xsl:value-of select="."/></lxml:client-charset>
	</xsl:template>

	<xsl:template match="tsml:server-instructions/tsml:cookies">
		<xsl:apply-templates select="/tsml:data/tsml:replaced-lxml/lxml:cookies"/>
	</xsl:template>

	<xsl:template match="tsml:options">
		<lxml:options>
			<xsl:apply-templates select="*"/>
		</lxml:options>
		<xsl:call-template name="blank_line"/>
	</xsl:template>

	<xsl:template match="tsml:option[text()]">
		<lxml:option name="{@name}"><xsl:value-of select="."/></lxml:option>
	</xsl:template>

	<xsl:template match="tsml:option[not(text())]">
		<lxml:option name="{@name}"/>
	</xsl:template>

	<xsl:template match="tsml:messages">
		<lxml:messages>
			<xsl:apply-templates select="/tsml:data/tsml:replaced-lxml/lxml:messages/lxml:message"/>
		</lxml:messages>
		<xsl:call-template name="blank_line"/>
	</xsl:template>

	<xsl:template match="tsml:weblets">
	</xsl:template>

	<xsl:template match="tsml:lxml-data">
	</xsl:template>

	<xsl:template match="tsml:external-resources">
		<lxml:external-resources/>
		<xsl:call-template name="blank_line"/>
	</xsl:template>

	<xsl:template match="tsml:fields">
		<lxml:fields>
			<xsl:apply-templates select="*"/>
		</lxml:fields>
		<xsl:call-template name="blank_line"/>
	</xsl:template>

	<xsl:template match="tsml:field">
		<xsl:variable name="fldname" select="@name"/>
		<lxml:field name="{$fldname}">
			<xsl:apply-templates select="tsml:caption"/>
			<xsl:variable name="replaced_value" select="key('replaced_field', $fldname)/lxml:value"/>
			<xsl:choose>
				<xsl:when test="string-length($replaced_value)">
					<lxml:value><xsl:value-of select="$replaced_value"/></lxml:value>
				</xsl:when>
				<xsl:when test="tsml:mode = 'output'">
					<lxml:value><xsl:value-of select="tsml:sample-value"/></lxml:value>
				</xsl:when>
				<xsl:otherwise>
					<lxml:value/>
				</xsl:otherwise>
			</xsl:choose>
		</lxml:field>
	</xsl:template>

	<xsl:template match="tsml:field/tsml:caption">
		<lxml:caption>
			<xsl:apply-templates select="*"/>
		</lxml:caption>
	</xsl:template>

	<xsl:template match="tsml:field/tsml:caption/tsml:label">
		<lxml:label><xsl:value-of select="."/></lxml:label>
	</xsl:template>

	<xsl:template match="tsml:field/tsml:caption/tsml:description">
		<lxml:description><xsl:value-of select="."/></lxml:description>
	</xsl:template>

	<xsl:template match="tsml:field/tsml:caption/tsml:heading-1">
		<lxml:heading-1><xsl:value-of select="."/></lxml:heading-1>
	</xsl:template>

	<xsl:template match="tsml:field/tsml:caption/tsml:heading-2">
		<lxml:heading-2><xsl:value-of select="."/></lxml:heading-2>
	</xsl:template>

	<xsl:template match="tsml:field/tsml:caption/tsml:heading-3">
		<lxml:heading-3><xsl:value-of select="."/></lxml:heading-3>
	</xsl:template>

	<xsl:template match="tsml:lists">
		<lxml:lists>
			<xsl:apply-templates select="*"/>
		</lxml:lists>
		<xsl:call-template name="blank_line"/>
	</xsl:template>

	<xsl:template match="tsml:list">
		<lxml:list name="{@name}" row-count="{../@default-sample-size}">
			<xsl:if test="(@inline = 'true') or ((@inline = 'default') and $g_inline_lists)">
				<xsl:attribute name="inline">true</xsl:attribute>
			</xsl:if>
			<xsl:apply-templates select="*"/>
		</lxml:list>
		<xsl:call-template name="blank_line"/>
	</xsl:template>

	<xsl:template match="tsml:json-list">
		<lxml:json-list name="{@name}">
			<xsl:value-of select="." />
		</lxml:json-list>
	</xsl:template>

	<xsl:template match="tsml:list-header">
		<lxml:list-header>
			<xsl:apply-templates select="*"/>
		</lxml:list-header>
	</xsl:template>

	<xsl:template match="tsml:list-header/tsml:header">
		<lxml:header name="{@name}">
			<xsl:apply-templates select="*"/>
		</lxml:header>
	</xsl:template>

	<xsl:template match="tsml:list-header/tsml:header/tsml:heading-1">
		<lxml:heading-1><xsl:value-of select="."/></lxml:heading-1>
	</xsl:template>

	<xsl:template match="tsml:list-header/tsml:header/tsml:heading-2">
		<lxml:heading-2><xsl:value-of select="."/></lxml:heading-2>
	</xsl:template>

	<xsl:template match="tsml:list-header/tsml:header/tsml:heading-3">
		<lxml:heading-3><xsl:value-of select="."/></lxml:heading-3>
	</xsl:template>

	<xsl:template match="tsml:list-entries">
		<lxml:list-entries>
			<xsl:apply-templates select="*"/>
		</lxml:list-entries>
	</xsl:template>

	<xsl:template match="tsml:entry">
		<xsl:variable name="name" select="../../@name"/>
		<xsl:variable name="list_entry" select="."/>
		<xsl:variable name="replaced_list_node" select="key('replaced_list', $name)"/>
		<xsl:choose>
			<!-- List defined in tsml:replaced-lxml: Add existing number of sample list entry nodes -->
			<xsl:when test="$replaced_list_node">
				<xsl:for-each select="$replaced_list_node/lxml:list-entries/lxml:entry">
					<xsl:call-template name="replaced_list">
						<xsl:with-param name="list_entry" select="$list_entry"/>
						<xsl:with-param name="replaced_list_entry" select="."/>
						<xsl:with-param name="entry_count" select="position()"/>
					</xsl:call-template>
				</xsl:for-each>
			</xsl:when>
			<!-- New list: Add default number of sample list entry nodes -->
			<xsl:otherwise>
				<xsl:call-template name="new_list">
					<xsl:with-param name="list_entry" select="$list_entry"/>
					<xsl:with-param name="sample_size" select="/tsml:data/tsml:lists/@default-sample-size"/>
					<xsl:with-param name="entry_count" select="1"/>
				</xsl:call-template>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:template>

	<xsl:template name="replaced_list">
		<xsl:param name="list_entry"/>
		<xsl:param name="replaced_list_entry"/>
		<xsl:param name="entry_count"/>
		<lxml:entry>
			<xsl:for-each select="$list_entry/tsml:column">
				<xsl:variable name="column_name" select="@name"/>
				<xsl:variable name="replaced_list_match_column" select="$replaced_list_entry/lxml:column[@name=$column_name]"/>
				<xsl:call-template name="list_column">
					<xsl:with-param name="column" select="current()"/>
					<xsl:with-param name="entry_count" select="$entry_count"/>
					<xsl:with-param name="column_value">
						<xsl:choose>
							<xsl:when test="string-length($replaced_list_match_column/text())"><xsl:value-of select="$replaced_list_match_column/text()"/></xsl:when>
							<xsl:otherwise><xsl:value-of select="tsml:sample-value"/></xsl:otherwise>
						</xsl:choose>
					</xsl:with-param>
				</xsl:call-template>
			</xsl:for-each>
		</lxml:entry>
	</xsl:template>

	<xsl:template name="new_list">
		<xsl:param name="list_entry"/>
		<xsl:param name="sample_size"/>
		<xsl:param name="entry_count"/>
		<xsl:if test="$entry_count &lt;= $sample_size">
			<lxml:entry>
				<xsl:for-each select="$list_entry/tsml:column">
					<xsl:variable name="column_name" select="@name"/>
					<xsl:call-template name="list_column">
						<xsl:with-param name="column" select="current()"/>
						<xsl:with-param name="entry_count" select="$entry_count"/>
						<xsl:with-param name="column_value">
							<xsl:if test="tsml:mode = 'output'"><xsl:value-of select="tsml:sample-value"/></xsl:if>
						</xsl:with-param>
					</xsl:call-template>
				</xsl:for-each>
			</lxml:entry>
			<!-- Recursive call to get sample size entries -->
			<xsl:call-template name="new_list">
				<xsl:with-param name="list_entry" select="$list_entry"/>
				<xsl:with-param name="sample_size" select="$sample_size"/>
				<xsl:with-param name="entry_count" select="$entry_count + 1"/>
			</xsl:call-template>
		</xsl:if>
	</xsl:template>

	<xsl:template name="list_column">
		<xsl:param name="column"/>
		<xsl:param name="entry_count"/>
		<xsl:param name="column_value" select="''"/>
		<lxml:column name="{$column/@name}" id="{$column/../../../@name}.{format-number($entry_count,'0000')}.{$column/@name}">
			<xsl:value-of select="$column_value"/><xsl:text/>
		</lxml:column>
	</xsl:template>

	<!-- Existing lxml nodes to keep between regenerations. Recreate elements (Can't use xsl:copy 
		  because it includes tsml namespace in result document) -->
	<xsl:template match="lxml:*">
		<xsl:element name="{name(.)}">
			<xsl:for-each select="@*">
				<xsl:attribute name="{local-name(.)}"><xsl:value-of select="."/></xsl:attribute>
			</xsl:for-each>
			<xsl:value-of select="text()"/>
			<xsl:apply-templates select="*"/>
		</xsl:element>
	</xsl:template>

</xsl:transform>
