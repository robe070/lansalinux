<?xml version="1.0" encoding="UTF-8"?><!--(c) 2002, 2013 LANSA--><!--XHTML Standard Cascading Style Sheet--><!--$Workfile:: std_style_v2.xsl $--><!--$UTCDate:: 2013-10-22 23:44:11Z $--><!--$Revision:: 17 $--><xsl:transform version="1.0" exclude-result-prefixes="lxml wd" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design" xmlns="http://www.w3.org/1999/xhtml"><xsl:import href="std_types.xsl"></xsl:import><xsl:import href="std_variables.xsl"></xsl:import><xsl:variable name="expand_css"></xsl:variable><xsl:template name="style"><xsl:param name="theme_css_filename" select="'theme_default.min.css'"></xsl:param><xsl:param name="css_files" select="''"></xsl:param><xsl:param name="css_files_charset" select="$lweb_extrafiles_charset"></xsl:param><link href="{$lweb_style_path}/std_style.min.css{$expand_css}" type="text/css" rel="stylesheet" charset="utf-8" /><xsl:variable name="theme_css_resolved_filename"><xsl:choose><xsl:when test="$theme_css_filename = ''">theme_default.min.css</xsl:when><xsl:otherwise><xsl:value-of select="$theme_css_filename"></xsl:value-of></xsl:otherwise></xsl:choose></xsl:variable><xsl:if test="$theme_css_resolved_filename != 'none'"><xsl:if test="$theme_css_resolved_filename != 'theme_default.min.css'"><link href="{$lweb_style_path}/theme_default.min.css{$expand_css}" type="text/css" rel="stylesheet" charset="utf-8" /></xsl:if><link href="{$lweb_style_path}/{$theme_css_resolved_filename}{$expand_css}" type="text/css" rel="stylesheet" charset="utf-8" /></xsl:if><xsl:if test="boolean($lweb_std_css_language_overlay)"><link href="{$lweb_style_path}/{$lweb_std_css_language_overlay}{$expand_css}" type="text/css" rel="stylesheet" charset="utf-8" /></xsl:if><xsl:apply-templates select="$lweb_styles[@location = 'header' or not(@location)]"></xsl:apply-templates><xsl:call-template name="csslinks.private"><xsl:with-param name="css_files" select="$css_files"></xsl:with-param><xsl:with-param name="css_files_charset" select="$css_files_charset"></xsl:with-param></xsl:call-template><style type="text/css">
	.hidden {display: none;}
</style></xsl:template><xsl:template name="style.body-top"><xsl:apply-templates select="$lweb_styles[@location = 'body-top']"></xsl:apply-templates></xsl:template><xsl:template match="/lxml:data/lxml:external-resources/lxml:style"><link href="{$lweb_images_path}/{.}{$expand_css}" type="text/css" rel="stylesheet" charset="{@charset}" /></xsl:template><xsl:template name="csslinks.private"><xsl:param name="css_files" select="''"></xsl:param><xsl:param name="css_files_charset" select="''"></xsl:param><xsl:choose><xsl:when test="not($css_files)"></xsl:when><xsl:when test="contains($css_files, ',')"><xsl:if test="not(starts-with($css_files, ','))"><link href="{$lweb_style_path}/{substring-before($css_files, ',')}{$expand_css}" type="text/css" rel="stylesheet" charset="{$css_files_charset}" /></xsl:if><xsl:call-template name="csslinks.private"><xsl:with-param name="css_files" select="substring-after($css_files, ',')"></xsl:with-param><xsl:with-param name="css_files_charset" select="$css_files_charset"></xsl:with-param><xsl:with-param name="expand_css" select="$expand_css"></xsl:with-param></xsl:call-template></xsl:when><xsl:otherwise><link href="{$lweb_style_path}/{$css_files}{$expand_css}" type="text/css" rel="stylesheet" charset="{$css_files_charset}" /></xsl:otherwise></xsl:choose></xsl:template></xsl:transform>