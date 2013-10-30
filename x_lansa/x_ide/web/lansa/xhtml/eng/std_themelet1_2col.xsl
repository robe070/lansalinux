<?xml version="1.0" encoding="UTF-8"?><!--(c) 2011, 2012 LANSA--><!--XHTML Theme layout weblet #1 - two column--><!--$Workfile:: std_themelet1_2col.xsl $--><!--$UTCDate:: 2013-01-02 23:47:48Z $--><!--$Revision:: 23 $--><xsl:transform version="1.0" exclude-result-prefixes="lxml wd tsml" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design" xmlns:tsml="http://www.lansa.com/2002/XML/Generation-Metadata" xmlns="http://www.w3.org/1999/xhtml"><xsl:import href="std_variables.xsl"></xsl:import><xsl:import href="std_types.xsl"></xsl:import><xsl:import href="std_hidden.xsl"></xsl:import><xsl:import href="std_style_v2.xsl"></xsl:import><xsl:import href="std_script.xsl"></xsl:import><xsl:import href="std_menubar.xsl"></xsl:import><xsl:import href="std_messages.xsl"></xsl:import><xsl:output method="xml" omit-xml-declaration="yes" encoding="UTF-8" indent="no" doctype-public="-//W3C//DTD XHTML 1.0 Strict//EN" doctype-system="http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd"></xsl:output><lxml:data><lxml:menu id="CCFCDED6FBB84F97B11D5565DCD41926"><lxml:font size="9" bold="true" italic="false"></lxml:font><lxml:item><lxml:caption>Home</lxml:caption><lxml:action></lxml:action><lxml:wam></lxml:wam><lxml:webroutine></lxml:webroutine></lxml:item><lxml:item><lxml:caption>Services</lxml:caption><lxml:action></lxml:action><lxml:wam></lxml:wam><lxml:webroutine></lxml:webroutine></lxml:item><lxml:item><lxml:caption>Contact</lxml:caption><lxml:action></lxml:action><lxml:wam></lxml:wam><lxml:webroutine></lxml:webroutine></lxml:item><lxml:item><lxml:caption>About</lxml:caption><lxml:action></lxml:action><lxml:wam></lxml:wam><lxml:webroutine></lxml:webroutine></lxml:item></lxml:menu></lxml:data><xsl:template name="std_themelet1_2col" wd:role="std:layout"><xsl:param name="window_title" select="$lweb_context/lxml:webapplication-title"></xsl:param><xsl:param name="has_form" select="true()"></xsl:param><xsl:param name="show_title" select="true()"></xsl:param><xsl:param name="title_text" select="$lweb_context/lxml:webroutine-title"></xsl:param><xsl:param name="width_type" select="'fluid'"></xsl:param><xsl:param name="width" select="'1000px'"></xsl:param><xsl:param name="content_width" select="'70%'"></xsl:param><xsl:param name="sidebar_width" select="'29%'"></xsl:param><xsl:param name="content_side" select="'right'"></xsl:param><xsl:param name="javascript_files" select="''"></xsl:param><xsl:param name="jQueryNoConflict" select="false()"></xsl:param><xsl:param name="css_files" select="''"></xsl:param><xsl:param name="extra_files_charset" select="$lweb_extrafiles_charset"></xsl:param><xsl:param name="output_charset" select="/lxml:data/lxml:server-instructions/lxml:client-charset"></xsl:param><xsl:param name="backcompat_theme" select="false()"></xsl:param><xsl:variable name="sidebar_side"><xsl:if test="$content_side = 'left'">right</xsl:if><xsl:if test="$content_side = 'right'">left</xsl:if></xsl:variable><html><xsl:if test="$lweb_ISO_language != ''"><xsl:attribute name="xml:lang"><xsl:value-of select="$lweb_ISO_language"></xsl:value-of></xsl:attribute><xsl:attribute name="lang"><xsl:value-of select="$lweb_ISO_language"></xsl:value-of></xsl:attribute></xsl:if><head><title><xsl:value-of select="$window_title"></xsl:value-of><xsl:text>&#32;</xsl:text></title><meta content="text/html; charset={$output_charset}" http-equiv="Content-Type" /><xsl:choose><xsl:when test="$backcompat_theme"><xsl:call-template name="style"><xsl:with-param name="theme_css_filename" select="''"></xsl:with-param><xsl:with-param name="css_files" select="$css_files"></xsl:with-param><xsl:with-param name="css_files_charset" select="$extra_files_charset"></xsl:with-param></xsl:call-template></xsl:when><xsl:otherwise><xsl:call-template name="style"><xsl:with-param name="theme_css_filename" select="'none'"></xsl:with-param><xsl:with-param name="css_files" select="$css_files"></xsl:with-param><xsl:with-param name="css_files_charset" select="$extra_files_charset"></xsl:with-param></xsl:call-template></xsl:otherwise></xsl:choose><style type="text/css">
#lpage_container, #lpage_headerContent, #lpage_footerContent, #lpage_messagesContainer {<xsl:text></xsl:text><xsl:if test="$width_type = 'fixed'"><xsl:text>margin-left: auto; margin-right: auto;</xsl:text><xsl:if test="$width!=''"> width: <xsl:value-of select="$width"></xsl:value-of>;</xsl:if></xsl:if>}
<xsl:if test="$width_type != 'fluid'">
div.messages {width: 40%;}
</xsl:if>
#lpage_columns_wrapper1 {clear: both;}
#lpage_content_column {<xsl:text></xsl:text><xsl:if test="$content_width!=''">width: <xsl:value-of select="$content_width"></xsl:value-of>;</xsl:if>}
<xsl:if test="$content_side = 'left'">
#lpage_sidebar1 {margin-right: 10px;}
</xsl:if><xsl:if test="$content_side = 'right'"> 
#lpage_sidebar1 {margin-left: 10px;}
</xsl:if>
#lpage_sidebar1 {float: <xsl:value-of select="$sidebar_side"></xsl:value-of>; width: <xsl:value-of select="$sidebar_width"></xsl:value-of>;}
#lpage_footer {clear: both;}
</style><xsl:call-template name="script"><xsl:with-param name="javascript_files" select="$javascript_files"></xsl:with-param><xsl:with-param name="javascript_files_charset" select="$extra_files_charset"></xsl:with-param><xsl:with-param name="trap_script_errors" select="false()"></xsl:with-param><xsl:with-param name="jQueryNoConflict" select="$jQueryNoConflict"></xsl:with-param></xsl:call-template></head><body class="lpage_twocol_layout"><xsl:variable name="containerName"><xsl:choose><xsl:when test="$has_form"><xsl:text>form</xsl:text></xsl:when><xsl:otherwise><xsl:text>div</xsl:text></xsl:otherwise></xsl:choose></xsl:variable><div id="lpage_header_themelet"><xsl:apply-templates select="*" mode="content.header"></xsl:apply-templates><xsl:comment /></div><xsl:element name="{$containerName}"><xsl:if test="not($has_form)"><xsl:attribute name="id">lpage_container</xsl:attribute></xsl:if><xsl:if test="$has_form"><xsl:attribute name="onsubmit">return _HandleDefaultSubmit(this);</xsl:attribute><xsl:attribute name="method">post</xsl:attribute><xsl:attribute name="name">LANSA</xsl:attribute><xsl:attribute name="id">LANSA</xsl:attribute><xsl:attribute name="action"><xsl:value-of select="$lweb_context/lxml:action-request"></xsl:value-of>?</xsl:attribute><xsl:call-template name="hidden_fields"></xsl:call-template></xsl:if><div id="lpage_messagesContainer"><xsl:call-template name="messages"></xsl:call-template><xsl:comment /></div><div id="lpage_noform"><xsl:if test="$has_form"><xsl:attribute name="id">lpage_container</xsl:attribute></xsl:if><div id="lpage_columns_wrapper1"><div id="lpage_sidebar1"><div id="lpage_sidebar1_content"><xsl:attribute name="class">lpage_content_area ui-widget-content ui-corner-all</xsl:attribute><xsl:apply-templates select="*" mode="content.sidebar1"></xsl:apply-templates><xsl:comment /></div></div><div id="lpage_content_column"><div id="lpage_content" class="lpage_content_area"><xsl:if test="$show_title"><h2 class="title"><xsl:value-of select="$title_text"></xsl:value-of><xsl:comment /></h2></xsl:if><div><xsl:apply-templates select="*"></xsl:apply-templates><xsl:comment /></div></div></div></div></div></xsl:element><div id="lpage_footer"><xsl:apply-templates select="*" mode="content.footer"></xsl:apply-templates><xsl:comment /></div></body></html></xsl:template><xsl:template match="/lxml:data"><div class="hidden"><xsl:comment /></div><p>Lorem ipsum dolor sit amet consect etuer adipi scing elit sed diam nonummy nibh euismod tinunt ut laoreet dolore magna aliquam erat volut. Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat. Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis at vero eros et accumsan et iusto odio dignissim qui blandit praesent luptatum zzril delenit augue duis dolore te feugait nulla facilisi. </p><p>Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat. Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis at vero eros et accumsan et iusto odio dignissim qui blandit praesent luptatum zzril delenit augue duis dolore te feugait nulla facilisi. Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. </p><p>Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis at vero eros et accumsan et iusto odio dignissim qui blandit praesent luptatum zzril delenit augue duis dolore te feugait nulla facilisi. Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat. </p></xsl:template><xsl:template match="/lxml:data" mode="content.sidebar1"><h3>Content Heading </h3><p>Lorem ipsum dolor sit amet consect etuer adipi scing elit sed diam nonummy nibh euismod tinunt ut laoreet dolore magna aliquam erat volut.</p><p>Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat.</p><p>Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis at vero eros et accumsan et iusto odio dignissim qui blandit praesent luptatum zzril delenit augue duis dolore te feugait nulla facilisi. </p></xsl:template><xsl:template match="/lxml:data" mode="content.header"><div id="lpage_headerContainer"><div id="lpage_headerContent"><div id="lpage_logoContainer"><div id="lpage_logo"><h3><a href="http://www.lansa.com" tabindex="-1"><span>LANSA</span></a></h3><div id="lpage_tagline">Advanced Software Made Simple</div></div></div><div id="lpage_navBar"><xsl:call-template name="std_menubar"><xsl:with-param name="menu_items" select="document('')/*/lxml:data/lxml:menu[@id='CCFCDED6FBB84F97B11D5565DCD41926']"></xsl:with-param><xsl:with-param name="name" select="concat('o', position(), '_LANSA_3775')"></xsl:with-param></xsl:call-template><xsl:comment /></div></div></div></xsl:template><xsl:template match="/lxml:data" mode="content.navigation"><xsl:call-template name="std_menubar"><xsl:with-param name="menu_items" select="document('')/*/lxml:data/lxml:menu[@id='CCFCDED6FBB84F97B11D5565DCD41926']"></xsl:with-param><xsl:with-param name="name" select="concat('o', position(), '_LANSA_3775')"></xsl:with-param></xsl:call-template></xsl:template><xsl:template match="/lxml:data" mode="content.footer"><xsl:comment>   Footer</xsl:comment><div id="lpage_footerContent"><div id="lpage_footerLogo"><h3><a href="http://www.lansa.com" tabindex="-1"><span>powered by </span>LANSA</a></h3></div><span id="lpage_footerNav"><ul><li><a href="#">Home</a></li><li class="lpage_space">|</li><li><a href="#">Services</a></li><li class="lpage_space">|</li><li><a href="#">Contact</a></li><li class="lpage_space">|</li><li><a href="#">About</a></li></ul></span><p><xsl:text disable-output-escaping="yes">&amp;copy;</xsl:text> Copyright <xsl:value-of select="key('variable', 'YYYYC')"></xsl:value-of> LANSA</p><div style="clear:both;"><xsl:comment /></div></div></xsl:template><xsl:template match="/lxml:data" mode="content.hidden"><xsl:comment>   Hidden Content</xsl:comment></xsl:template></xsl:transform>