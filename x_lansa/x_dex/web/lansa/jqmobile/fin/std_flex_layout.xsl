<?xml version="1.0" encoding="UTF-8"?><!--(c) 2012 LANSA--><!--JQMOBILE Standard WAM Layout--><!--$Workfile:: std_flex_layout.xsl $--><!--$UTCDate:: 2012-12-21 02:41:01Z $--><!--$Revision:: 13 $--><xsl:transform version="1.0" exclude-result-prefixes="lxml wd" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns="http://www.w3.org/1999/xhtml" xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design"><xsl:import href="std_variables.xsl"></xsl:import><xsl:import href="std_types.xsl"></xsl:import><xsl:import href="std_style_v2.xsl"></xsl:import><xsl:import href="std_script.xsl"></xsl:import><xsl:import href="std_hidden.xsl"></xsl:import><xsl:import href="std_messages.xsl"></xsl:import><xsl:output method="xml" omit-xml-declaration="yes" encoding="UTF-8" indent="no" doctype-system="about:legacy-compat"></xsl:output><xsl:template name="std_flex_layout" wd:role="std:layout"><xsl:param name="addBackButton" select="false()"></xsl:param><xsl:param name="backButtonSwatch"></xsl:param><xsl:param name="backButtonText" select="''"></xsl:param><xsl:param name="contentSwatch" select="''"></xsl:param><xsl:param name="footerFullscreenMode" select="false()"></xsl:param><xsl:param name="footerPosition" select="''"></xsl:param><xsl:param name="footerSwatch" select="''"></xsl:param><xsl:param name="headerFullscreenMode" select="false()"></xsl:param><xsl:param name="headerPosition" select="''"></xsl:param><xsl:param name="headerSwatch" select="''"></xsl:param><xsl:param name="pageSwatch" select="''"></xsl:param><xsl:param name="persistentFooterId"></xsl:param><xsl:param name="showFooter" select="true()"></xsl:param><xsl:param name="showHeader" select="true()"></xsl:param><xsl:param name="showMessages" select="true()"></xsl:param><xsl:param name="sidebarPositionSmallScreen" select="'top'"></xsl:param><xsl:param name="validationErrorDisplay" select="''"></xsl:param><xsl:param name="validationTime" select="''"></xsl:param><xsl:param name="windowTitle" select="$lweb_context/lxml:webroutine-title"></xsl:param><html><head><xsl:if test="not($lweb_design_mode)"><title><xsl:value-of select="$windowTitle"></xsl:value-of><xsl:text>&#32;</xsl:text></title></xsl:if><meta name="viewport" content="width:device-width, initial-scale=1" /><xsl:call-template name="style"></xsl:call-template><xsl:call-template name="script"></xsl:call-template><style type="text/css"><xsl:text disable-output-escaping="yes">/* &lt;![CDATA[ */
</xsl:text><xsl:apply-templates select="*" mode="content.style"></xsl:apply-templates><xsl:text disable-output-escaping="yes">
/* ]]&gt; */</xsl:text></style><script type="text/javascript"><xsl:text disable-output-escaping="yes">//&lt;![CDATA[
</xsl:text><xsl:apply-templates select="*" mode="content.script"></xsl:apply-templates><xsl:text disable-output-escaping="yes">
//]]&gt;</xsl:text><xsl:text>&#32;</xsl:text></script></head><body><div data-role="page"><xsl:attribute name="class"><xsl:text>lstd-stdFlexLayout</xsl:text><xsl:value-of select="concat(' lstd-sidebarOnSmall',$sidebarPositionSmallScreen)"></xsl:value-of><xsl:if test="$validationErrorDisplay"><xsl:value-of select="concat(' ',$validationErrorDisplay)"></xsl:value-of></xsl:if><xsl:if test="$validationTime"><xsl:value-of select="concat(' ',$validationTime)"></xsl:value-of></xsl:if></xsl:attribute><xsl:if test="$pageSwatch"><xsl:attribute name="data-theme"><xsl:value-of select="$pageSwatch"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$addBackButton"><xsl:attribute name="data-add-back-btn">true</xsl:attribute><xsl:if test="$backButtonText != ''"><xsl:attribute name="data-back-btn-text"><xsl:value-of select="$backButtonText"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$backButtonSwatch != ''"><xsl:attribute name="data-back-btn-theme"><xsl:value-of select="$backButtonSwatch"></xsl:value-of></xsl:attribute></xsl:if></xsl:if><xsl:call-template name="style.body-top"></xsl:call-template><xsl:call-template name="script.body-top"></xsl:call-template><form method="post" name="LANSA" id="{$lweb_WRName}_form" action="{$lweb_context/lxml:action-request}?wam={$lweb_WAMName}&amp;webrtn={$lweb_WRName}&amp;ml={$lweb_context/lxml:technology-service}&amp;part={$lweb_context/lxml:partition}&amp;lang={$lweb_context/lxml:language}"><xsl:if test="$showHeader"><div data-role="header" role="banner"><xsl:if test="$headerSwatch"><xsl:attribute name="data-theme"><xsl:value-of select="$headerSwatch"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$headerPosition = 'fixed'"><xsl:attribute name="data-position">fixed</xsl:attribute><xsl:if test="$headerFullscreenMode"><xsl:attribute name="data-fullscreen">true</xsl:attribute></xsl:if></xsl:if><xsl:apply-templates select="*" mode="content.header"></xsl:apply-templates><xsl:comment /></div></xsl:if><div data-theme="{$contentSwatch}" data-role="content" role="main"><xsl:if test="$sidebarPositionSmallScreen = 'Top'"><div class="content-secondary"><xsl:apply-templates select="*" mode="content.secondary"></xsl:apply-templates><xsl:comment /></div></xsl:if><div class="content-primary"><xsl:if test="$showMessages"><xsl:call-template name="messages"></xsl:call-template></xsl:if><xsl:apply-templates select="*"></xsl:apply-templates><xsl:comment /></div><xsl:if test="$sidebarPositionSmallScreen != 'Top'"><div class="content-secondary"><xsl:apply-templates select="*" mode="content.secondary"></xsl:apply-templates><xsl:comment /></div></xsl:if></div><xsl:call-template name="hidden_fields"></xsl:call-template><xsl:if test="$showFooter"><div data-role="footer"><xsl:if test="$footerSwatch"><xsl:attribute name="data-theme"><xsl:value-of select="$footerSwatch"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$footerPosition = 'fixed'"><xsl:attribute name="data-position">fixed</xsl:attribute><xsl:if test="$footerFullscreenMode"><xsl:attribute name="data-fullscreen">true</xsl:attribute></xsl:if></xsl:if><xsl:if test="$persistentFooterId"><xsl:attribute name="data-id"><xsl:value-of select="$persistentFooterId"></xsl:value-of></xsl:attribute></xsl:if><xsl:apply-templates select="*" mode="content.footer"></xsl:apply-templates><xsl:comment /></div></xsl:if></form><xsl:call-template name="scriptAtEnd"></xsl:call-template></div></body></html></xsl:template><xsl:template match="/lxml:data" mode="content.header"><h1><xsl:value-of select="/lxml:data/lxml:context/lxml:webroutine-title"></xsl:value-of><xsl:comment /></h1></xsl:template><xsl:template match="/lxml:data" mode="content.secondary">
		Sidebar
	</xsl:template><xsl:template match="/lxml:data" mode="content.footer">
		Footer
	</xsl:template><xsl:template match="/lxml:data" mode="content.hidden"><xsl:comment> Hidden Content </xsl:comment></xsl:template><xsl:template match="/lxml:data" mode="content.style">
.lstd-stdFlexLayout .content-secondary {
	margin: -15px;
	padding: 15px;
}
.lstd-stdFlexLayout .content-primary {
	margin: -15px;
	padding: 15px;
}

@media all and (max-width: 650px) {
	.lstd-sidebarOnSmallHidden .content-secondary {
	display: none;
}
}

@media all and (min-width: 650px) {
		.lstd-stdFlexLayout .content-secondary {
		float: left;
		width: 45%;
	}
	.lstd-stdFlexLayout .content-primary {
		width: 45%;
		float: right;
	}
}
@media all and (min-width: 750px) {
	.lstd-stdFlexLayout .content-secondary {
		width: 34%;
	}
	.lstd-stdFlexLayout .content-primary {
		width: 56%;
	}
}
@media all and (min-width: 1200px) {
	.lstd-stdFlexLayout .content-secondary {
		width: 30%;
	}
	.lstd-stdFlexLayout .content-primary {
		width: 60%;
	}
}
		</xsl:template><xsl:template match="/lxml:data" mode="content.script"></xsl:template></xsl:transform>