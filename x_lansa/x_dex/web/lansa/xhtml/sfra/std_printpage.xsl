<?xml version="1.0" encoding="UTF-8"?><!--(c) 2011, 2012 LANSA--><!--XHTML Print page--><!--$Workfile:: std_printpage.xsl $--><!--$UTCDate:: 2013-01-02 05:01:45Z $--><!--$Revision:: 7 $--><xsl:transform version="1.0" exclude-result-prefixes="lxml wd" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design" xmlns="http://www.w3.org/1999/xhtml"><xsl:import href="std_variables.xsl"></xsl:import><xsl:import href="std_keys.xsl"></xsl:import><xsl:import href="std_util.xsl"></xsl:import><xsl:import href="std_types.xsl"></xsl:import><xsl:output method="xml" omit-xml-declaration="yes" encoding="UTF-8" indent="yes"></xsl:output><xsl:template name="std_printpage"><xsl:param name="caption" select="key('variable', 'MTXT_XXPRINT')"></xsl:param><xsl:param name="hide_if" select="false()"></xsl:param><xsl:param name="disabled" select="false()"></xsl:param><xsl:param name="hide_focus" select="true()"></xsl:param><xsl:param name="relative_image_path" select="'icons/normal/16/printer_16.png'"></xsl:param><xsl:param name="absolute_image_path" select="concat($lweb_images_path, '/', $relative_image_path)"></xsl:param><xsl:param name="pos_absolute"></xsl:param><xsl:param name="width_design"></xsl:param><xsl:param name="height_design"></xsl:param><xsl:param name="class" select="'std_printpage'"></xsl:param><xsl:param name="disabled_class" select="'std_printpage_disabled'"></xsl:param><xsl:param name="tab_index"></xsl:param><xsl:if test="not($hide_if) or $lweb_design_mode"><span class="ui-widget {$class}"><xsl:if test="$disabled_class and boolean($disabled)"><xsl:attribute name="class">ui-widget <xsl:value-of select="$disabled_class"></xsl:value-of></xsl:attribute></xsl:if><a href="javascript:Lstd.Utils.printPage();"><xsl:if test="boolean($hide_focus)"><xsl:attribute name="class">hidefocus</xsl:attribute></xsl:if><xsl:if test="$pos_absolute != ''"><xsl:attribute name="style"><xsl:value-of select="$pos_absolute"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$tab_index != ''"><xsl:attribute name="tabindex"><xsl:value-of select="$tab_index"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$disabled"><xsl:attribute name="href">javascript:void(0);</xsl:attribute></xsl:if><img src="{$absolute_image_path}"><xsl:if test="$height_design or $width_design"><xsl:attribute name="style"><xsl:call-template name="make_size_and_pos_style_v2.private"><xsl:with-param name="caller_name" select="'std_printpage.xsl'"></xsl:with-param><xsl:with-param name="pos_absolute" select="''"></xsl:with-param><xsl:with-param name="height" select="$height_design"></xsl:with-param><xsl:with-param name="width" select="$width_design"></xsl:with-param></xsl:call-template></xsl:attribute></xsl:if></img><xsl:value-of select="$caption"></xsl:value-of></a></span></xsl:if></xsl:template></xsl:transform>