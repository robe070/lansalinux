<?xml version="1.0" encoding="UTF-8"?><!--(c) 2002, 2012 LANSA--><!--XHTML Standard Cascading Style Sheet--><!--$Workfile:: std_style.xsl $--><!--$UTCDate:: 2013-01-02 22:57:09Z $--><!--$Revision:: 19 $--><xsl:transform version="1.0" exclude-result-prefixes="lxml wd" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design" xmlns="http://www.w3.org/1999/xhtml"><xsl:import href="std_types.xsl"></xsl:import><xsl:import href="std_variables.xsl"></xsl:import><xsl:template name="style"><xsl:param name="theme_css_filename" select="'theme_default.min.css'"></xsl:param><xsl:param name="body_bgimage" select="''"></xsl:param><xsl:param name="company_logo_image" select="$lweb_company_logo"></xsl:param><xsl:param name="company_logo_image_right" select="$lweb_company_logo_right"></xsl:param><xsl:param name="relative_css_link_filename" select="''"></xsl:param><xsl:variable name="expand_css"></xsl:variable><link href="{$lweb_style_path}/std_style.min.css{$expand_css}" type="text/css" rel="stylesheet" charset="utf-8" /><xsl:variable name="theme_css_resolved_filename"><xsl:choose><xsl:when test="$theme_css_filename = ''">theme_default.min.css</xsl:when><xsl:otherwise><xsl:value-of select="$theme_css_filename"></xsl:value-of></xsl:otherwise></xsl:choose></xsl:variable><xsl:if test="$theme_css_resolved_filename != 'none'"><xsl:if test="$theme_css_resolved_filename != 'theme_default.min.css'"><link href="{$lweb_style_path}/theme_default.min.css{$expand_css}" type="text/css" rel="stylesheet" charset="utf-8" /></xsl:if><link href="{$lweb_style_path}/{$theme_css_resolved_filename}{$expand_css}" type="text/css" rel="stylesheet" charset="utf-8" /></xsl:if><xsl:if test="boolean($relative_css_link_filename)"><xsl:choose><xsl:when test="$relative_css_link_filename = 'std_style_royal.css'"><link href="{$lweb_style_path}/theme_royal.min.css{$expand_css}" type="text/css" rel="stylesheet" charset="utf-8" /></xsl:when><xsl:when test="$relative_css_link_filename = 'std_style_grass.css'"><link href="{$lweb_style_path}/theme_grass.min.css{$expand_css}" type="text/css" rel="stylesheet" charset="utf-8" /></xsl:when><xsl:otherwise><link href="{$lweb_style_path}/{$relative_css_link_filename}{$expand_css}" type="text/css" rel="stylesheet" charset="utf-8" /></xsl:otherwise></xsl:choose></xsl:if><xsl:if test="boolean($lweb_std_css_language_overlay)"><link href="{$lweb_style_path}/{$lweb_std_css_language_overlay}{$expand_css}" type="text/css" rel="stylesheet" /></xsl:if><xsl:apply-templates select="/lxml:data/lxml:external-resources/lxml:style"><xsl:with-param name="expand_css" select="$expand_css"></xsl:with-param></xsl:apply-templates><style type="text/css"><xsl:if test="boolean($body_bgimage)">
				body
				{
				background-image: url("<xsl:value-of select="$lweb_images_path"></xsl:value-of>/<xsl:value-of select="$body_bgimage"></xsl:value-of>");
				}
			</xsl:if><xsl:if test="$company_logo_image!=''">
				.std_headerl
				{
				background-image: url("<xsl:value-of select="$lweb_images_path"></xsl:value-of>/<xsl:value-of select="$company_logo_image"></xsl:value-of>");
				}
			</xsl:if><xsl:if test="$company_logo_image_right!=''">
				.std_headerr
				{
				background-image: url("<xsl:value-of select="$lweb_images_path"></xsl:value-of>/<xsl:value-of select="$company_logo_image_right"></xsl:value-of>");
				}
			</xsl:if>
			.hidden
			{
			display: none;
			}
		</style></xsl:template><xsl:template match="/lxml:data/lxml:external-resources/lxml:style"><xsl:param name="expand_css" select="''"></xsl:param><link href="{$lweb_images_path}/{.}{$expand_css}" type="text/css" rel="stylesheet" charset="{@charset}" /></xsl:template></xsl:transform>