<?xml version="1.0" encoding="UTF-8"?><!--(c) 2003, 2012 LANSA--><!--PPC XHTML Standard Layout Schema #5--><!--$Workfile:: std_layout5_v2.xsl $--><!--$UTCDate:: 2013-01-02 04:17:09Z $--><!--$Revision:: 7 $--><xsl:transform version="1.0" exclude-result-prefixes="lxml wd" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns="http://www.w3.org/1999/xhtml"><xsl:import href="std_variables.xsl"></xsl:import><xsl:import href="std_types.xsl"></xsl:import><xsl:import href="std_style_v2.xsl"></xsl:import><xsl:import href="std_script.xsl"></xsl:import><xsl:import href="std_hidden.xsl"></xsl:import><xsl:import href="std_menu_item_v2.xsl"></xsl:import><xsl:import href="std_messages.xsl"></xsl:import><xsl:output method="xml" omit-xml-declaration="yes" encoding="UTF-8" indent="yes"></xsl:output><xsl:template name="std_layout5_v2" wd:role="std:layout"><xsl:param name="show_left_menu" select="false()"></xsl:param><xsl:param name="show_top_menu" select="true()"></xsl:param><xsl:param name="show_right_menu" select="false()"></xsl:param><xsl:param name="company_logo_image" select="$lweb_company_logo"></xsl:param><xsl:param name="body_class"></xsl:param><xsl:param name="form_class"></xsl:param><xsl:param name="has_form" select="true()"></xsl:param><xsl:param name="no_layout" select="false()"></xsl:param><xsl:param name="show_title" select="true()"></xsl:param><xsl:param name="title_text" select="$lweb_context/lxml:webroutine-title"></xsl:param><xsl:param name="show_messages" select="true()"></xsl:param><xsl:param name="onload_script" select="'SetFocus()'"></xsl:param><xsl:param name="onunload_script" select="''"></xsl:param><xsl:param name="javascript_files" select="''"></xsl:param><xsl:param name="theme_css_filename" select="''"></xsl:param><xsl:param name="css_files" select="''"></xsl:param><xsl:param name="extra_files_charset" select="$lweb_extrafiles_charset"></xsl:param><xsl:param name="output_charset" select="/lxml:data/lxml:server-instructions/lxml:client-charset"></xsl:param><xsl:param name="trap_script_errors" select="true()"></xsl:param><html><head><title><xsl:value-of select="$title_text"></xsl:value-of><xsl:text>&#32;</xsl:text></title><meta http-equiv="Content-Type" content="text/html; charset={$output_charset}" /><xsl:call-template name="style"><xsl:with-param name="theme_css_filename" select="$theme_css_filename"></xsl:with-param><xsl:with-param name="css_files" select="$css_files"></xsl:with-param><xsl:with-param name="css_files_charset" select="$extra_files_charset"></xsl:with-param></xsl:call-template><xsl:call-template name="script"><xsl:with-param name="javascript_files" select="$javascript_files"></xsl:with-param><xsl:with-param name="javascript_files_charset" select="$extra_files_charset"></xsl:with-param><xsl:with-param name="trap_script_errors" select="$trap_script_errors"></xsl:with-param></xsl:call-template></head><body bottommargin="0" rightmargin="0" marginheight="0" marginwidth="0" topmargin="0" leftmargin="0"><xsl:if test="$body_class!=''"><xsl:attribute name="class"><xsl:value-of select="$body_class"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="boolean($onload_script)"><xsl:attribute name="onload"><xsl:value-of select="$onload_script"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="boolean($onunload_script)"><xsl:attribute name="onunload"><xsl:value-of select="$onunload_script"></xsl:value-of></xsl:attribute></xsl:if><xsl:choose><xsl:when test="$no_layout"><xsl:call-template name="layout-form.private"><xsl:with-param name="show_messages" select="$show_messages"></xsl:with-param><xsl:with-param name="show_title" select="$show_title"></xsl:with-param><xsl:with-param name="title_text" select="$title_text"></xsl:with-param><xsl:with-param name="has_form" select="$has_form"></xsl:with-param><xsl:with-param name="form_class" select="$form_class"></xsl:with-param></xsl:call-template></xsl:when><xsl:otherwise><table height="100%" cellspacing="0" cellpadding="0" width="100%" border="0"><tbody><tr><td class="std_layout_outline" align="center" colspan="4"><table cellspacing="0" cellpadding="0" width="100%" border="0"><tbody><tr><td class="std_headerl" valign="middle" align="left" width="50%" height="80"><xsl:choose><xsl:when test="$company_logo_image != ''"><img alt="" src="{$lweb_images_path}/{$company_logo_image}" /></xsl:when><xsl:otherwise><span style="width:100%"><xsl:comment></xsl:comment><xsl:comment /></span></xsl:otherwise></xsl:choose><xsl:comment /></td></tr></tbody></table></td></tr><tr><xsl:if test="not($show_right_menu) and not(key('design_doc_name', 'std_layout5.xsl'))"><td class="std_menutop_bg"><xsl:comment /></td></xsl:if><td class="std_menutop_bg" align="center" colspan="4" height="20"><xsl:if test="not($show_right_menu) and not(key('design_doc_name', 'std_layout5.xsl'))"><xsl:attribute name="align">left</xsl:attribute></xsl:if><xsl:if test="$show_top_menu or key('design_doc_name', 'std_layout5.xsl')"><xsl:call-template name="layout-top-menu.override"></xsl:call-template></xsl:if><xsl:comment /></td></tr><tr><td class="std_layout_outline" valign="top"><xsl:if test="$show_left_menu or key('design_doc_name', 'std_layout5.xsl')"><xsl:call-template name="layout-left-menu.override"></xsl:call-template></xsl:if><xsl:comment /></td><td width="10"><span style="width:100%"><xsl:comment></xsl:comment><xsl:comment /></span></td><td class="std_layout5_content" height="100%"><xsl:call-template name="layout-form.private"><xsl:with-param name="show_messages" select="$show_messages"></xsl:with-param><xsl:with-param name="show_title" select="$show_title"></xsl:with-param><xsl:with-param name="title_text" select="$title_text"></xsl:with-param><xsl:with-param name="has_form" select="$has_form"></xsl:with-param><xsl:with-param name="form_class" select="$form_class"></xsl:with-param></xsl:call-template><xsl:comment /></td><td class="std_layout_outline" valign="top" align="right"><xsl:choose><xsl:when test="$show_right_menu or key('design_doc_name', 'std_layout5.xsl')"><xsl:call-template name="layout-right-menu.override"></xsl:call-template></xsl:when></xsl:choose><xsl:comment /></td></tr><tr><td class="std_layout_outline" height="100%"><span style="width:100%"><xsl:comment></xsl:comment><xsl:comment /></span></td><td width="10"><xsl:comment /></td><td><xsl:comment /></td><td class="std_layout_outline" height="100%"><span style="width:100%"><xsl:comment></xsl:comment><xsl:comment /></span></td></tr><tr><td colspan="4"><xsl:comment /></td></tr></tbody></table></xsl:otherwise></xsl:choose></body></html></xsl:template><xsl:template name="get-curve2-image.private"><xsl:param name="layout_bg_color"></xsl:param><xsl:choose><xsl:when test="$layout_bg_color = '#3333cc'"><xsl:value-of select="concat($lweb_images_path, '/curve2_3333cc.gif')"></xsl:value-of></xsl:when><xsl:when test="$layout_bg_color = '#ff0033'"><xsl:value-of select="concat($lweb_images_path, '/curve2_ff0033.gif')"></xsl:value-of></xsl:when><xsl:when test="$layout_bg_color = '#709e6d'"><xsl:value-of select="concat($lweb_images_path, '/curve2_709e6d.gif')"></xsl:value-of></xsl:when><xsl:when test="$layout_bg_color = '#993399'"><xsl:value-of select="concat($lweb_images_path, '/curve2_993399.gif')"></xsl:value-of></xsl:when><xsl:when test="$layout_bg_color = '#ff6c0c'"><xsl:value-of select="concat($lweb_images_path, '/curve2_ff6c0c.gif')"></xsl:value-of></xsl:when><xsl:when test="$layout_bg_color = '#cccccc'"><xsl:value-of select="concat($lweb_images_path, '/curve2_cccccc.gif')"></xsl:value-of></xsl:when><xsl:when test="$layout_bg_color = '#666666'"><xsl:value-of select="concat($lweb_images_path, '/curve2_666666.gif')"></xsl:value-of></xsl:when><xsl:when test="$layout_bg_color = '#d3d3d3'"><xsl:value-of select="concat($lweb_images_path, '/curve2_lightgrey.gif')"></xsl:value-of></xsl:when><xsl:when test="$layout_bg_color = 'lightgrey'"><xsl:value-of select="concat($lweb_images_path, '/curve2_lightgrey.gif')"></xsl:value-of></xsl:when></xsl:choose></xsl:template><xsl:template name="layout-left-menu.override"><table><tbody><tr><td><xsl:call-template name="std_menu_item_v2"></xsl:call-template><xsl:comment /></td></tr><tr><td><xsl:call-template name="std_menu_item_v2"></xsl:call-template><xsl:comment /></td></tr><tr><td><xsl:call-template name="std_menu_item_v2"></xsl:call-template><xsl:comment /></td></tr><tr><td><xsl:comment /></td></tr><tr><td><xsl:comment /></td></tr><tr><td><xsl:comment /></td></tr><tr><td><xsl:comment /></td></tr><tr><td><xsl:comment /></td></tr><tr><td><xsl:comment /></td></tr><tr><td><xsl:comment /></td></tr><tr><td><xsl:comment /></td></tr><tr><td><xsl:comment /></td></tr><tr><td><xsl:comment /></td></tr></tbody></table></xsl:template><xsl:template name="layout-top-menu.override"><table><tbody><tr><td><xsl:call-template name="std_menu_item_v2"></xsl:call-template><xsl:value-of select="''"></xsl:value-of><xsl:comment /></td><td><xsl:call-template name="std_menu_item_v2"></xsl:call-template><xsl:comment /></td><td><xsl:call-template name="std_menu_item_v2"></xsl:call-template><xsl:comment /></td><td><xsl:call-template name="std_menu_item_v2"></xsl:call-template><xsl:comment /></td><td><xsl:comment /></td><td><xsl:comment /></td></tr></tbody></table></xsl:template><xsl:template name="layout-right-menu.override"><table><tbody><tr><td><xsl:call-template name="std_menu_item_v2"></xsl:call-template><xsl:comment /></td></tr><tr><td><xsl:call-template name="std_menu_item_v2"></xsl:call-template><xsl:comment /></td></tr><tr><td><xsl:call-template name="std_menu_item_v2"></xsl:call-template><xsl:comment /></td></tr><tr><td><xsl:comment /></td></tr><tr><td><xsl:comment /></td></tr></tbody></table></xsl:template><xsl:template name="layout-form.private"><xsl:param name="has_form" select="true()"></xsl:param><xsl:param name="form_class"></xsl:param><xsl:param name="show_title"></xsl:param><xsl:param name="title_text"></xsl:param><xsl:param name="show_messages"></xsl:param><xsl:if test="$show_title"><h1 class="title"><xsl:value-of select="$title_text"></xsl:value-of><xsl:comment /></h1></xsl:if><xsl:if test="$show_messages"><xsl:call-template name="messages"></xsl:call-template></xsl:if><xsl:choose><xsl:when test="$has_form"><form name="LANSA" onsubmit="return _HandleDefaultSubmit(this)" action="{$lweb_context/lxml:action-request}?" method="post"><xsl:if test="$form_class!=''"><xsl:attribute name="class"><xsl:value-of select="$form_class"></xsl:value-of></xsl:attribute></xsl:if><xsl:apply-templates select="*"></xsl:apply-templates><xsl:call-template name="hidden_fields"></xsl:call-template><xsl:comment /></form></xsl:when><xsl:otherwise><xsl:apply-templates select="*"></xsl:apply-templates></xsl:otherwise></xsl:choose></xsl:template></xsl:transform>