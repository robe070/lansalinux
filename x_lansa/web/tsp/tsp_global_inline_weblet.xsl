<?xml version="1.0" encoding="UTF-8"?>

<!-- (c) 2002, 2011 LANSA                              -->
<!-- Global inline weblet design time resolver         -->
<!-- $Workfile:: tsp_global_inline_weblet.xsl        $ -->
<!-- $Revision:: 5                                   $ -->

<xsl:transform version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:xslt="http://www.lansa.com/2002/XSL/Transform-Alias" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data"
					xmlns:tsml="http://www.lansa.com/2002/XML/Generation-Metadata"
					xmlns:msxsl="urn:schemas-microsoft-com:xslt"
					xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design"
					xmlns="http://www.w3.org/1999/xhtml" exclude-result-prefixes="tsml xslt">

	<!-- TSP stylesheet import. The inliner replaces this import with the actual TSP stylesheet -->
	<xsl:import href="tsp_lansa_xhtml_webroutine.xsl" wd:tsp-stylesheet="true"/>

	<!-- Passed to TSP stylesheet: This is a weblet inliner transformation -->
	<xsl:variable name="g_inliner_call" select="true()"/>

	<!-- XSL import path -->
	<xsl:param name="g_import_path" select="''"/>

	<xsl:output method="xml" omit-xml-declaration="no" encoding="UTF-8" indent="yes"/>

	<xsl:namespace-alias stylesheet-prefix="xslt" result-prefix="xsl"/>

	<xsl:variable name="inline_weblet" select="/tsml:data/tsml:inlined-weblet[1]"/>
	<xsl:variable name="field_node" select="/tsml:data/tsml:fields/tsml:field[1]"/>
	<xsl:variable name="column_node" select="/tsml:data/tsml:lists/tsml:list/tsml:list-entries/tsml:entry/tsml:column[1]"/>
	<xsl:variable name="field_or_column" select="$field_node or $column_node"/>

	<xsl:variable name="weblet_name">
		<xsl:choose>
			<xsl:when test="$inline_weblet"><xsl:value-of select="$inline_weblet/@name"/></xsl:when>
			<xsl:when test="$field_node"><xsl:value-of select="$field_node/tsml:use-weblets/tsml:use-weblet[@technology-service = $tsp_qname]/@name"/></xsl:when>
			<xsl:when test="$column_node"><xsl:value-of select="$column_node/tsml:use-weblets/tsml:use-weblet[@technology-service = $tsp_qname]/@name"/></xsl:when>
		</xsl:choose>
	</xsl:variable>

	<xsl:template match="/">
		<xsl:apply-templates select="*"/>
	</xsl:template>

	<xsl:template match="tsml:data">
		<xsl:call-template name="blank_line"/>
		<xslt:transform version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
			xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data"
			xmlns:msxsl="urn:schemas-microsoft-com:xslt"
			xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design" 
			xmlns="http://www.w3.org/1999/xhtml"
			exclude-result-prefixes="lxml msxsl wd">
		<xsl:call-template name="blank_line"/>

		<!-- Standard imports -->
		<xslt:import href="{$g_import_path}std_keys.xsl"/>
		<xslt:import href="{$g_import_path}std_variables.xsl"/>
		<xsl:if test="tsml:fields/tsml:field[tsml:select-one]">
			<xslt:import href="{$g_import_path}std_select_list.xsl"/>
		</xsl:if>

		<!-- Weblet imports -->
		<xsl:apply-templates select="./tsml:weblets/tsml:weblet[tsml:technology-services/tsml:technology-service/@name = $tsp_qname]" mode="weblet_imports">
			<xsl:sort select="@name" data-type="text" />
		</xsl:apply-templates>

		<!-- Inlined weblet -->
		<xsl:apply-templates select="./tsml:inlined-weblet" mode="weblet_imports"/>

		<xsl:call-template name="blank_line"/>

		<xslt:output method="xml" omit-xml-declaration="yes" encoding="UTF-8" indent="yes"/>
		<xsl:call-template name="blank_line"/>

		<xsl:variable name="generator" select="/tsml:data/tsml:context/tsml:requester = 'generator'"/>

		<xsl:choose>
			<xsl:when test="$generator">
				<xsl:apply-templates select="tsml:lxml-data"/>
			</xsl:when>
			<xsl:otherwise>
				<xsl:apply-templates select="tsml:lxml-data" mode="inlined-weblet"/>
			</xsl:otherwise>
		</xsl:choose>

		<xslt:template match="/">
			<wd:inliner-document-fragment>
				<xsl:choose>
					<xsl:when test="$generator">
						<xsl:variable name="weblet_template_name" select="substring-after($weblet_name, '.')"/>
						<wd:inlined-weblet name="{$weblet_template_name}" mod-id="{key('weblet', $weblet_name)/tsml:technology-services/tsml:technology-service[@name = $tsp_qname]/@mod-id}">
							<xsl:call-template name="wd_with_params">
								<xsl:with-param name="weblet_template_name" select="$weblet_template_name"/>
							</xsl:call-template>
							<wd:content>
								<xsl:choose>
									<xsl:when test="$column_node">
										 <xsl:apply-templates select="$column_node" mode="column_placement">
											  <xsl:with-param name="inline_list" select="true()"/>
										 </xsl:apply-templates>
									</xsl:when>
									<xsl:otherwise>
										<xsl:apply-templates select="$field_node"/>
									</xsl:otherwise>
								</xsl:choose>
							</wd:content>
						</wd:inlined-weblet>
					</xsl:when>
					<xsl:otherwise>
						<xsl:apply-templates select="/tsml:data/tsml:inlined-weblet"/>
					</xsl:otherwise>
				</xsl:choose>
			</wd:inliner-document-fragment>
		</xslt:template>

		<xsl:if test="$field_or_column and $generator">
			<xslt:template match="xsl:with-param">
				<wd:with-param name="{{@name}}" select="{{@select}}"/>
			</xslt:template>
		</xsl:if>
		</xslt:transform>
	</xsl:template>

	 <xsl:template match="tsml:column" mode="column_placement">
		 <xsl:variable name="use_weblet" select="./tsml:use-weblets/tsml:use-weblet[@technology-service = $tsp_qname]"/>
		  <xsl:call-template name="weblet_template_call">
				<xsl:with-param name="field" select="."/>
				<xsl:with-param name="fld_or_col" select="'column'"/>
				<xsl:with-param name="name" select="translate(./@name, $nmtoken_invalid_chars, $nmtoken_replacement_chars)"/>
				<xsl:with-param name="displaymode" select="./tsml:mode/text()"/>
				<xsl:with-param name="use_weblet" select="$use_weblet"/>
				<xsl:with-param name="weblet" select="key('weblet', $use_weblet/@name)"/>
				<xsl:with-param name="inline_param" select="true()"/>
		  </xsl:call-template>
	 </xsl:template>
	 
	 <xsl:template name="wd_with_params">
		<xsl:param name="weblet_template_name"/>
		<xsl:choose>
			<xsl:when test="$field_or_column">
				<xslt:apply-templates select="document('')/xsl:transform/xsl:template[@match = '/']/wd:inliner-document-fragment/wd:inlined-weblet/wd:content/descendant::xsl:call-template[@name = '{$weblet_template_name}']/xsl:with-param"/>
			</xsl:when>
			<xsl:otherwise>
				<xsl:apply-templates select="$inline_weblet/tsml:with-params/tsml:with-param" mode="wd_param"/>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:template>

	<xsl:template match="tsml:inlined-weblet" mode="weblet_imports">
		<xslt:import href="{$g_import_path}{substring-before(@name, '.')}.xsl"/>
	</xsl:template>

	<xsl:template match="tsml:lxml-data" mode="inlined-weblet">
		<xsl:if test="child::node()">
			<lxml:data>
				<xsl:apply-templates select="*" mode="inlined-weblet"/>
			</lxml:data>
		</xsl:if>
	</xsl:template>

	<!-- lxml data island nodes. xsl:copy not used to avoid copying tsml namespace -->
	<xsl:template match="lxml:*" mode="inlined-weblet">
		<xsl:element name="{name()}">
			<xsl:copy-of select="@*"/>
			<xsl:apply-templates/>
		</xsl:element>
	</xsl:template>

	<xsl:template match="tsml:inlined-weblet">
		<xslt:call-template name="{substring-after(@name,'.')}">
			<xsl:apply-templates select="tsml:with-params/tsml:with-param"/>
		</xslt:call-template>
	</xsl:template>

	<xsl:template match="tsml:with-param" mode="wd_param">
		<wd:with-param>
			<xsl:attribute name="name"><xsl:value-of select="tsml:param-name"/></xsl:attribute>
			<xsl:attribute name="select"><xsl:value-of select="tsml:param-value"/></xsl:attribute>
		</wd:with-param>
	</xsl:template>

	<xsl:template match="tsml:with-param">
		<xslt:with-param>
			<xsl:attribute name="name"><xsl:value-of select="tsml:param-name"/></xsl:attribute>
			<xsl:attribute name="select"><xsl:value-of select="tsml:param-value"/></xsl:attribute>
		</xslt:with-param>
	</xsl:template>

</xsl:transform>
