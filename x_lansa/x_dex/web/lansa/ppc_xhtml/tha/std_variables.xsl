<?xml version="1.0" encoding="UTF-8"?><!--(c) 2002, 2012 LANSA--><!--PPC XHTML Standard Variables--><!--$Workfile:: std_variables.xsl $--><!--$UTCDate:: 2012-08-03 06:15:15Z $--><!--$Revision:: 7 $--><xsl:transform version="1.0" exclude-result-prefixes="lxml wd msxsl" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design" xmlns:msxsl="urn:schemas-microsoft-com:xslt" xmlns:exslt="http://exslt.org/common" xmlns="http://www.w3.org/1999/xhtml"><xsl:import href="std_locale.xsl"></xsl:import><xsl:variable name="lweb_data_node" select="/lxml:data"></xsl:variable><xsl:variable name="lweb_context" select="/lxml:data/lxml:context"></xsl:variable><xsl:variable name="lweb_variables" select="/lxml:data/lxml:variables/lxml:variable"></xsl:variable><xsl:variable name="lweb_WAMName" select="$lweb_context/lxml:webapplication"></xsl:variable><xsl:variable name="lweb_part_language" select="$lweb_context/lxml:language"></xsl:variable><xsl:variable name="lweb_ISO_language" select="$lweb_part_language/@iso-lang"></xsl:variable><xsl:variable name="lweb_design_mode" select="boolean($lweb_context[@design])"></xsl:variable><xsl:variable name="lweb_weblet_preview_mode" select="false()"></xsl:variable><xsl:variable name="lweb_weblet_preview" select="''"></xsl:variable><xsl:variable name="lweb_preview_mode" select="false()"></xsl:variable><xsl:variable name="lweb_design_or_preview" select="$lweb_design_mode"></xsl:variable><xsl:variable name="lweb_hidden_delayload_navs_attr_name" select="'__hidden_delayload_navs'"></xsl:variable><xsl:variable name="lweb_reload_navs_on_click_attr_name" select="'__reload_navs_on_click'"></xsl:variable><xsl:variable name="lweb_reload_navs_arr_attr_name" select="'__on_click_reload_navs_arr'"></xsl:variable><xsl:variable name="lweb_delayload_navs_arr_attr_name" select="'__hidden_delayload_navs_arr'"></xsl:variable><xsl:variable name="lweb_is_msxsl_nodeset" select="function-available('msxsl:node-set')"></xsl:variable><xsl:variable name="lweb_is_exslt_nodeset" select="function-available('exslt:node-set')"></xsl:variable><xsl:variable name="lweb_emulate_device" select="true()"></xsl:variable><xsl:key name="design_doc_name" match="/lxml:data/lxml:context" use="@design"></xsl:key><xsl:variable name="lweb_images_path" select="$lweb_context/lxml:images-path"></xsl:variable><xsl:variable name="lweb_scripts_path" select="concat($lweb_images_path, '/script')"></xsl:variable><xsl:variable name="lweb_style_path" select="concat($lweb_images_path, '/style')"></xsl:variable><xsl:variable name="lweb_stdfooter_border" select="'gradient.gif'"></xsl:variable><xsl:variable name="lweb_company_logo" select="'lanlogo.gif'"></xsl:variable><xsl:variable name="lweb_lansa_logo" select="'pbltran.gif'"></xsl:variable><xsl:variable name="lweb_inline_wdbool">{wd:boolean('</xsl:variable><xsl:variable name="lweb_std_css_link_filename" select="''"></xsl:variable></xsl:transform>