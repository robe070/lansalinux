<?xml version="1.0" encoding="UTF-8"?>

<!-- (c) 2003, 2011 LANSA                              -->
<!-- LANSA XSLT Stylesheet Publisher                   -->
<!-- $Workfile:: tsp_global_publisher.xsl            $ -->
<!-- $Revision:: 10                                  $ -->

<xsl:transform version="1.0"
					xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
					xmlns:xslt="http://www.lansa.com/2002/XSL/Transform-Alias"
					xmlns:msxsl="urn:schemas-microsoft-com:xslt"
					xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data"
					xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design"
					xmlns:xhtml="http://www.w3.org/1999/xhtml"
					exclude-result-prefixes="msxsl wd xslt xhtml" extension-element-prefixes="wd">

	<xsl:output method="xml" omit-xml-declaration="no" encoding="UTF-8" indent="no"/>
	<xsl:namespace-alias stylesheet-prefix="xslt" result-prefix="xsl"/>
	<xsl:strip-space elements="*"/>
	<xsl:variable name="wd_ns" select="'http://www.lansa.com/2002/XSL/Weblet-Design'"/>
	<xsl:variable name="xsl_ns" select="'http://www.w3.org/1999/XSL/Transform'"/>

	<msxsl:script language="JScript" implements-prefix="wd">
	//<![CDATA[

		// Attribute value template
		var regExp = new RegExp(/\{wd:[a-zA-Z]([\w\-])*\(.*\)\}/);

		// Reserved characters
		var reservedChars = new RegExp(/([%<>'"&#\+\:\^\|\$\(\[,:\)\]])/g);

		// Inline weblet
		var inlineTemplate = new RegExp(/.+(?:\.inline)$/);

		// Trimmers
		var trimlExp = new RegExp(/^\s*'/g);
		var trimrExp = new RegExp(/'\s*$/g);

		// Extension functions hashtable
		var fn = {
			"action-request" : "action_request",
			"align-right" : "align_right",
			"boolean" : "boolean",
			"check-numeric" : "check_numeric",
			"column-value" : "fv:",
			"column-value-unescaped" : "fvn:",
			"dbcs" : "dbcs",
			"debug" : "debug",
			"field-value" : "fv:",
			"has-entry" : "has_entry:",
			"images-path" : "images_path",
			"language" : "language",
			"layout-name" : "layout_name",
			"list-name" : "list_name",
			"parent-row-index" : "row_index_parent",
			"partition" : "partition",
			"row-class" : "row_class:",
			"row-index" : "row_index",
			"service-name" : "service_name",
			"session-key" : "session_key",
			"session-key-method" : "session_key_method",
			"session-key-name" : "session_key_name",
			"task" : "task",
			"trace" : "trace",
			"variable" : "sv:",
			"variable-unescaped" : "svn:",
			"web-user" : "web_user",
			"webapplication" : "application_name",
			"webapplication-title" : "application_title",
			"webroutine" : "routine_name",
			"webroutine-title" : "routine_title"
		};

		// Translates wd functions into its runtime notation
		function translate(attr, urlenc)
		{
			var attrValue = null;

			if (attr != null)
			{
				if (typeof attr == 'object')
				{
					try
					{
						attrValue = attr.item(0).text;
					}
					catch (e) {}
				}
				else attrValue = "" + attr;
			}

			if (attrValue == null) return "null";
			if (urlenc == null) urlenc = true;

			var pos = attrValue.search(regExp);

			if (pos != -1)
			{
				var retValue = !urlenc ? attrValue.substring(0, pos) : urlencode(attrValue.substring(0, pos));
				pos += 1;

				var keywordArgStart = attrValue.indexOf('(', pos) + 1;
				var keywordArgEnd = attrValue.indexOf(')', keywordArgStart) -1;
				var keyword = attrValue.substring(pos + 3, keywordArgStart - 1);

				retValue += "$(";
				retValue += fn[keyword];

				var argstr = keywordArgEnd > keywordArgStart ? attrValue.substring(keywordArgStart, keywordArgEnd) : "";

				if (argstr.length > 0)
				{
					argarr = argstr.split(',');
					argcnt = argarr.length;
					arglst = argcnt - 1;

					for (var i = 0; i < argcnt; ++i)
					{
						var arg = argarr[i].replace(trimlExp, '');
						arg = arg.replace(trimrExp, '');
						retValue += arg;
						if (i != arglst) retValue += ',';
					}
				}

				retValue += ")";

				var rem = attrValue.indexOf('}', keywordArgEnd + 1) + 1;
				if (rem < (attrValue.length - 1)) retValue += translate(attrValue.substring(rem), urlenc);
				return retValue;
			}
			return !urlenc ? attrValue : urlencode(attrValue);
		}

		// Encode reserved characters using percent encoding
		function urlencode(str)
		{
			return str.replace(reservedChars, function ($1){
				return escape($1);
			});
		}

		// Determines if template is for inlined weblet (based on naming convention)
		function notinlinetemplate(nameAttr)
		{
			return nameAttr.item(0).text.search(inlineTemplate) == -1;
		}
	//]]>
	</msxsl:script>

	<!-- Preserve root level comments -->
	<xsl:template match="/comment()">
		<xsl:comment><xsl:value-of select="normalize-space(.)"/></xsl:comment>
	</xsl:template>

	<xsl:template match="*/comment()">
	</xsl:template>

	<xsl:template match="processing-instruction()">
		<xsl:copy/>
	</xsl:template>

	<!-- Only output comment if there are no child nodes, only xsl child nodes or wd:attribute nodes -->
	<!-- In all other cases we can be sure that the presence of child nodes will close the HTML element -->
	<xsl:template name="close_element">
	<xsl:param name="closing_fragment"><xslt:comment /></xsl:param><!-- The fragment to output to ensure closing can be specified here -->
		<xsl:choose>
		<xsl:when test="node() and node()[not(self::xsl:*) and not(self::wd:attribute)]"></xsl:when>
		<xsl:otherwise><xsl:copy-of select="$closing_fragment" /></xsl:otherwise>
		</xsl:choose>
	</xsl:template>

	<!-- Variant of close_element that skips closing fragment if child node is xsl:value-of -->
	<xsl:template name="close_element2">
	<xsl:param name="closing_fragment"><xslt:comment /></xsl:param>
		<xsl:choose>
		<xsl:when test="node() and (node()[not(self::xsl:*) and not(self::wd:attribute)] or node()[self::xsl:value-of])"></xsl:when>
		<xsl:otherwise><xsl:copy-of select="$closing_fragment" /></xsl:otherwise>
		</xsl:choose>
	</xsl:template>

	<!-- Special handling of xhtml non-empty elements to ensure the XSLT processor doesn't self-close them -->
	<xsl:template match="xhtml:form | xhtml:span | xhtml:div | xhtml:button | xhtml:iframe | xhtml:u | xhtml:i | xhtml:b | xhtml:h1 | xhtml:h2 | xhtml:h3 | xhtml:h4 | xhtml:h5 | xhtml:h6 | xhtml:p | xhtml:ul | xhtml:ol | xhtml:sub | xhtml:sup | xhtml:td | xhtml:th | xhtml:object | xhtml:strong | xhtml:select">
		<xsl:copy>
			<xsl:apply-templates select="@*[not(namespace-uri() = $wd_ns)]" />
				<xsl:apply-templates select="node()"/>
			<xsl:call-template name="close_element" />
		</xsl:copy>
	</xsl:template>

	<!-- Special handling of xhtml:label to ensure the XSLT processor doesn't self-close it -->
	<xsl:template match="xhtml:label">
		<xsl:copy>
			<xsl:apply-templates select="@*[not(namespace-uri() = $wd_ns)]" />
				<xsl:apply-templates select="node()"/>
			<xsl:call-template name="close_element2" />
		</xsl:copy>
	</xsl:template>

	<xsl:template match="xhtml:textarea">
		<xsl:copy>
			<xsl:apply-templates select="@*[not(namespace-uri() = $wd_ns)]" />
			<xsl:apply-templates select="node()"/>
			<xsl:call-template name="close_element">
				<xsl:with-param name="closing_fragment">
					<xslt:text><xsl:text disable-output-escaping="yes">&amp;#13;</xsl:text></xslt:text>
				</xsl:with-param>
			</xsl:call-template>
		</xsl:copy>
	</xsl:template>

	<xsl:template match="xhtml:title">
		<xsl:copy>
			<xsl:apply-templates select="@*[not(namespace-uri() = $wd_ns)]" />
			<xsl:apply-templates select="node()"/>
			<xsl:call-template name="close_element">
				<xsl:with-param name="closing_fragment">
					<xslt:text><xsl:text disable-output-escaping="yes">&amp;#32;</xsl:text></xslt:text>
				</xsl:with-param>
			</xsl:call-template>
		</xsl:copy>
	</xsl:template>

	<xsl:template match="xhtml:script">
		<xsl:copy>
			<xsl:apply-templates select="@*[not(namespace-uri() = $wd_ns)]" />
				<xsl:apply-templates select="node()"/>
			<xsl:call-template name="close_element">
				<xsl:with-param name="closing_fragment">
					<xslt:text><xsl:text disable-output-escaping="yes">&amp;#32;</xsl:text></xslt:text>
				</xsl:with-param>
			</xsl:call-template>
		</xsl:copy>
	</xsl:template>

	<xsl:template match="xhtml:area | xhtml:base | xhtml:basefont | xhtml:br | xhtml:col | xhtml:frame | xhtml:hr | xhtml:input | xhtml:isindex  | xhtml:link | xhtml:meta | xhtml:param | xhtml:img">
		<xsl:choose>
			<xsl:when test="node()"><!-- Match any elements, in case there is something other than xsl (as a safety copy bad format too) -->
				<xsl:copy>
					<xsl:apply-templates select="@*[not(namespace-uri() = $wd_ns)]" />
					<xsl:apply-templates select="node()"/>
				</xsl:copy>
			</xsl:when>
			<xsl:otherwise>
				<xsl:copy>
					<xsl:apply-templates select="@*[not(namespace-uri() = $wd_ns)]" />
				</xsl:copy>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:template>

	<!-- Exclude as much as possble of design time nodes -->
	<xsl:template match="xsl:choose">
		<xsl:variable name="first_test" select="xsl:when[1]/@test"/>
		<xsl:choose>
			<xsl:when test="($first_test = '$lweb_design_mode') or ($first_test = '$lweb_preview_mode') or ($first_test = 'boolean(/lxml:data/lxml:context[@design])')">
				<xsl:choose>
					<xsl:when test="count(xsl:when) > 1">
						<xsl:copy>
							<xsl:for-each select="@*">
								<xsl:copy/>
							</xsl:for-each>
							<xsl:apply-templates select="node()"/>
						</xsl:copy>
					</xsl:when>
					<xsl:otherwise>
						<xsl:apply-templates select="xsl:otherwise/child::node()"/>
					</xsl:otherwise>
				</xsl:choose>
			</xsl:when>
			<xsl:otherwise>
				<xsl:copy>
					<xsl:for-each select="@*">
						<xsl:copy/>
					</xsl:for-each>
					<xsl:apply-templates select="node()"/>
				</xsl:copy>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:template>

	<!-- Exclude inlined weblet templates -->
	<xsl:template match="xsl:template[@name]">
		<xsl:if test="wd:notinlinetemplate(@name) and not(@wd:design-only)">
			<xsl:copy>
				<xsl:for-each select="@*">
					<xsl:copy/>
				</xsl:for-each>
				<xsl:apply-templates select="node()"/>
			</xsl:copy>
		</xsl:if>
	</xsl:template>

	<xsl:template match="xsl:when[(@test = '$lweb_design_mode') or (@test = 'boolean(/lxml:data/lxml:context[@design])')]">
	</xsl:template>

	<xsl:template match="xsl:if[(@test = '$lweb_design_mode') or (@test = 'boolean(/lxml:data/lxml:context[@design])')]">
	</xsl:template>

	<xsl:template match="xsl:if[@test = '$lweb_weblet_preview_mode']">
	</xsl:template>

	<xsl:template match="xsl:if[@test = '$lweb_preview_mode']">
	</xsl:template>

	<xsl:template match="xsl:if[@test = '$lweb_design_or_preview']">
	</xsl:template>

	<xsl:template match="wd:inlined-list | wd:for-each-row | wd:if">
		<!-- Must be in a line by itself (after runtime XSLT) -->
		<xsl:call-template name="runtime_newline"/>
		<xsl:copy>
			<!-- Omit XSL Editor only "select" attribute -->
			<xsl:apply-templates select="@*[not(name() = 'select')]" />
			<xsl:call-template name="runtime_newline"/>
			<xsl:apply-templates select="node()"/>
			<xsl:call-template name="runtime_newline"/>
		</xsl:copy>
		<xsl:call-template name="runtime_newline"/>
	</xsl:template>

	<xsl:template match="wd:inlined-weblet">
		<xsl:apply-templates select="child::node()"/>
	</xsl:template>

	<xsl:template match="wd:content">
		<xsl:apply-templates select="child::node()"/>
	</xsl:template>

	<xsl:template match="wd:column-heading">
		<xsl:text>$(fc:</xsl:text>
		<xsl:value-of select="@name"/>
		<xsl:text>,</xsl:text>
		<xsl:apply-templates select="wd:separator"/>
		<xsl:text>)</xsl:text>
	</xsl:template>

	<xsl:template match="wd:column-value[@disable-output-escaping = 'yes']">
		<xsl:text>$(fvn:</xsl:text>
		<xsl:value-of select="@name"/>
		<xsl:text>)</xsl:text>
	</xsl:template>

	<xsl:template match="wd:column-value">
		<xsl:text>$(fv:</xsl:text>
		<xsl:value-of select="@name"/>
		<xsl:text>)</xsl:text>
	</xsl:template>

	<xsl:template match="wd:separator">
		<xsl:apply-templates select="node()" mode="escaped_element"/>
	</xsl:template>

	<xsl:template match="wd:attribute">
		<xsl:variable name="condition" select="@condition"/>
		<xsl:attribute name="{@name}">
			<xsl:choose>
				<xsl:when test="$condition">
					<!-- Build attribute="$(aif:[op:arg1,arg2],truevalue,falsevalue)" -->
					<xsl:value-of select="concat('$(aif:[', $condition, '],')"/>
					<xsl:value-of select="wd:translate(@select, true())"/>
					<xsl:if test="@notselect">
						<xsl:text>,</xsl:text>
						<xsl:value-of select="wd:translate(@notselect, true())"/>
					</xsl:if>
					<xsl:text>)</xsl:text>
				</xsl:when>
				<xsl:otherwise>
					<xsl:value-of select="wd:translate(@select, false())"/>
				</xsl:otherwise>
			</xsl:choose>
		</xsl:attribute>
	</xsl:template>

	<xsl:template match="wd:field-value">
		<xsl:text>$(fv:</xsl:text>
		<xsl:value-of select="@name"/>
		<xsl:text>)</xsl:text>
	</xsl:template>

	<xsl:template match="wd:row-class">
		<xsl:text>$(row_class:</xsl:text><xsl:value-of select="@odd"/>,<xsl:value-of select="@even"/>)<xsl:text/>
	</xsl:template>

	<xsl:template match="wd:list-name">
		<xsl:text>$(list_name)</xsl:text>
	</xsl:template>

	<xsl:template match="wd:row-index">
		<xsl:text>$(row_index)</xsl:text>
	</xsl:template>

	<xsl:template match="wd:parent-row-index">
		<xsl:text>$(row_index_parent)</xsl:text>
	</xsl:template>

	<!-- wd:value-of: Translate and output its content -->
	<xsl:template match="wd:value-of">
		<xsl:value-of select="wd:translate(@select, false())"/>
	</xsl:template>

	<xsl:template match="wd:variable[@disable-output-escaping = 'yes']">
		<xsl:text>$(svn:</xsl:text>
		<xsl:value-of select="@name"/>
		<xsl:text>)</xsl:text>
	</xsl:template>

	<xsl:template match="wd:variable">
		<xsl:text>$(sv:</xsl:text>
		<xsl:value-of select="@name"/>
		<xsl:text>)</xsl:text>
	</xsl:template>

	<!-- wd:separator elements (escaped) -->
	<xsl:template match="node()" mode="escaped_element">
		<xsl:text>%3C</xsl:text>
		<xsl:value-of select="name()"/>
		<xsl:choose>
			<xsl:when test="not(node())">
				<xsl:text> /%3E</xsl:text>
			</xsl:when>
			<xsl:otherwise>
				<xsl:text>%3E</xsl:text>
				<xsl:apply-templates select="node()" mode="escaped_element"/>
				<xsl:text>%3C/</xsl:text>
				<xsl:value-of select="name()"/>
				<xsl:text>%3E</xsl:text>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:template>

	<!-- wd:separator text content -->
	<xsl:template match="text()" mode="escaped_element">
		<xsl:value-of select="."/>
		<xsl:apply-templates select="node()" mode="escaped_element"/>
	</xsl:template>

	<!-- Identity transformation excluding wd namespace and non root level comments -->
	<xsl:template match="node()">
		<xsl:if test="not(namespace-uri() = $wd_ns)">
			<xsl:copy>
				<xsl:apply-templates select="@*[not(namespace-uri() = $wd_ns)]" />
				<xsl:apply-templates select="node()"/>
			</xsl:copy>
		</xsl:if>
	</xsl:template>

	<xsl:template match="@*">
		<xsl:attribute name="{name()}"><xsl:value-of select="wd:translate(., false())"/></xsl:attribute>
	</xsl:template>

	<xsl:template name="runtime_newline">
		<xslt:text><xsl:text disable-output-escaping="yes">&amp;#xA;</xsl:text></xslt:text>
	</xsl:template>
</xsl:transform>
