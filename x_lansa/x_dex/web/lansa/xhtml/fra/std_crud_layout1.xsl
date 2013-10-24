<?xml version="1.0" encoding="UTF-8"?><!--(c) 2009, 2012 LANSA--><!--XHTML Layout--><!--$Workfile:: std_crud_layout1.xsl $--><!--$Revision:: 7 $--><xsl:transform version="1.0" exclude-result-prefixes="lxml wd" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design" xmlns="http://www.w3.org/1999/xhtml"><xsl:import href="std_variables.xsl"></xsl:import><xsl:import href="std_types.xsl"></xsl:import><xsl:import href="std_style_v2.xsl"></xsl:import><xsl:import href="std_script.xsl"></xsl:import><xsl:import href="std_hidden.xsl"></xsl:import><xsl:import href="std_messages.xsl"></xsl:import><xsl:output method="xml" omit-xml-declaration="yes" encoding="UTF-8" indent="yes"></xsl:output><xsl:template name="std_crud_layout1" wd:role="std:layout"><xsl:param name="show_top_menu"></xsl:param><xsl:param name="show_footer_menu"></xsl:param><xsl:param name="show_footer_links"></xsl:param><xsl:param name="body_class"></xsl:param><xsl:param name="form_class"></xsl:param><xsl:param name="has_form" select="true()"></xsl:param><xsl:param name="show_title" select="true()"></xsl:param><xsl:param name="title_text" select="$lweb_context/lxml:webroutine-title"></xsl:param><xsl:param name="show_messages" select="true()"></xsl:param><xsl:param name="onload_script" select="'SetFocus()'"></xsl:param><xsl:param name="onunload_script" select="''"></xsl:param><xsl:param name="javascript_files" select="''"></xsl:param><xsl:param name="theme_css_filename" select="''"></xsl:param><xsl:param name="css_files" select="''"></xsl:param><xsl:param name="extra_files_charset" select="$lweb_extrafiles_charset"></xsl:param><xsl:param name="output_charset" select="/lxml:data/lxml:server-instructions/lxml:client-charset"></xsl:param><xsl:param name="trap_script_errors" select="true()"></xsl:param><xsl:param name="jQueryNoConflict" select="false()"></xsl:param><html><head><title><xsl:value-of select="$title_text"></xsl:value-of><xsl:text>&#32;</xsl:text></title><meta http-equiv="Content-Type" content="text/html; charset={$output_charset}" /><xsl:call-template name="style"><xsl:with-param name="theme_css_filename" select="$theme_css_filename"></xsl:with-param><xsl:with-param name="css_files" select="$css_files"></xsl:with-param><xsl:with-param name="css_files_charset" select="$extra_files_charset"></xsl:with-param></xsl:call-template><xsl:if test="$theme_css_filename = '' or not(contains($theme_css_filename, 'std_style_crud_'))"><link href="{$lweb_style_path}/std_style_crud.min.css" type="text/css" rel="stylesheet" charset="utf-8" /></xsl:if><script src="{$lweb_scripts_path}/std_crud_fra.min.js" type="text/javascript" charset="utf-8"><xsl:comment></xsl:comment><xsl:text>&#32;</xsl:text></script><xsl:call-template name="script"><xsl:with-param name="javascript_files" select="$javascript_files"></xsl:with-param><xsl:with-param name="javascript_files_charset" select="$extra_files_charset"></xsl:with-param><xsl:with-param name="trap_script_errors" select="$trap_script_errors"></xsl:with-param><xsl:with-param name="jQueryNoConflict" select="$jQueryNoConflict"></xsl:with-param></xsl:call-template></head><body onload="SetFocus()"><xsl:if test="boolean($onload_script)"><xsl:attribute name="onload"><xsl:value-of select="$onload_script"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="boolean($onunload_script)"><xsl:attribute name="onunload"><xsl:value-of select="$onunload_script"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$body_class!=''"><xsl:attribute name="class"><xsl:value-of select="$body_class"></xsl:value-of></xsl:attribute></xsl:if><form name="LANSA" onsubmit="return _HandleDefaultSubmit(this)" action="{$lweb_context/lxml:action-request}?" method="post"><xsl:if test="$form_class!=''"><xsl:attribute name="class"><xsl:value-of select="$form_class"></xsl:value-of></xsl:attribute></xsl:if><div align="center"><table style="width:1024px;" cellspacing="0" cellpadding="0" width="1024" border="0"><tbody><tr><td style="width:1024px" width="1024"><table style="width:100%" cellspacing="0" cellpadding="0" width="100%" border="0"><tbody><tr><td class="crud_wam_header_left" width="647"><img style="width:647px;height:62px;" height="62" alt="" src="/images/crud/crud_spacer.gif" width="647" border="0" /></td><td class="crud_header_spacer" width="46" bgcolor="#5cc151"><img style="width:46px;height:62px;" height="62" alt="" src="/images/crud/crud_spacer.gif" width="46" border="0" /></td><td class="crud_header_right" width="331"><xsl:value-of select="key('field-value','XXMONTHDS')"></xsl:value-of><xsl:comment /></td></tr></tbody></table></td></tr><tr><td style="width:1024px;height:1px;" width="1024"><table style="width:100%;height:1px;" cellspacing="0" cellpadding="0" width="100%" border="0"><tbody><tr><td class="crud_menu_left" width="4"><img height="1" alt="" src="/images/crud/crud_spacer.gif" width="4" /></td><td class="crud_menu_linesep" width="1016"><img height="1" alt="" src="/images/crud/crud_spacer.gif" width="1" /></td><td class="crud_menu_right" width="4"><img height="1" alt="" src="/images/crud/crud_spacer.gif" width="4" /></td></tr></tbody></table></td></tr><xsl:if test="$show_top_menu"><tr><td style="width:1024px;height:26px;" width="1024" height="26"><table style="width:100%;height:26px" cellspacing="0" cellpadding="0" width="100%" border="0"><tbody><tr><td class="crud_menu_left" width="4"><img height="26" alt="" src="/images/crud/crud_spacer.gif" width="4" /></td><td class="crud_menu_bg" width="1016" bgcolor="#e4f6e2"><div id="crud_menu_container"><div id="crud_menu_header"><ul><li><a href="http://www.lansa.com/fr"><span>Page d'accueil</span></a></li><xsl:call-template name="layout-header-menu.override"></xsl:call-template><li><a href="javascript:void(0);"><span>Nous contacter</span></a></li><li><a href="javascript:void(0);"><span>A propos</span></a></li></ul></div></div></td><td class="crud_menu_right" width="4"><img height="26" alt="" src="/images/crud/crud_spacer.gif" width="4" /></td></tr></tbody></table></td></tr></xsl:if><tr><td style="width:1024px;" width="1024"><table style="width:100%;" cellspacing="0" cellpadding="0" width="100%" border="0"><tbody><tr><td class="crud_content_left_bg"><img height="1" alt="" src="/images/crud/crud_spacer.gif" width="1" /></td><td class="crud_content_bg" id="crud_content" width="1016"><xsl:if test="$show_title"><h1 class="crud_title"><xsl:value-of select="$title_text"></xsl:value-of><xsl:comment /></h1></xsl:if><xsl:if test="$show_messages"><xsl:call-template name="messages"></xsl:call-template></xsl:if><xsl:call-template name="hidden_fields"></xsl:call-template><xsl:apply-templates select="*"></xsl:apply-templates><xsl:comment /></td><td class="crud_content_right_bg"><img height="1" alt="" src="/images/crud/crud_spacer.gif" width="1" /></td></tr></tbody></table></td></tr><tr><td style="width:1024px;height:5px;" width="1024" height="5"><table style="width:100%" cellspacing="0" cellpadding="0" width="100%" border="0"><tbody><tr><td class="crud_menu_left" width="4" height="5"><img height="5" alt="" src="/images/crud/crud_spacer.gif" width="4" /></td><td class="crud_linesep" width="1016" height="5"><img height="5" alt="" src="/images/crud/crud_spacer.gif" width="1" /></td><td class="crud_menu_right" width="4" height="5"><img height="5" alt="" src="/images/crud/crud_spacer.gif" width="4" /></td></tr></tbody></table></td></tr><xsl:if test="$show_footer_links"><xsl:call-template name="layout-footer-links.override"></xsl:call-template></xsl:if><xsl:if test="$show_footer_menu"><tr><td style="width:1024px;height:41px" width="1024"><table style="width:100%;height:46px" cellspacing="0" cellpadding="0" width="100%" border="0"><tbody><tr><td class="crud_footer_menu_left" width="21"><img height="46" alt="" src="/images/crud/crud_spacer.gif" width="21" /></td><td class="crud_footer_content_bg" width="728" bgcolor="#ffffff"><table style="height:25px;" height="25" cellspacing="0" cellpadding="0" border="0"><tbody><tr><xsl:call-template name="layout-footer-menu.override"></xsl:call-template></tr></tbody></table></td><td class="crud_footer_menu_right" width="275"><img height="46" alt="" src="/images/crud/crud_spacer.gif" width="275" /></td></tr></tbody></table></td></tr></xsl:if><tr><td style="width:1024px" width="1024"><table style="width:100%" cellspacing="0" cellpadding="0" width="100%" border="0"><tbody><tr><td class="crud_footer_left" width="647"><img style="width:647px;height:13px;" height="13" alt="" src="/images/crud/crud_spacer.gif" width="647" border="0" /></td><td class="crud_footer_spacer" width="48" bgcolor="#ebf8ea"><img style="width:48px;height:13px;" height="13" alt="" src="/images/crud/crud_spacer.gif" width="48" border="0" /></td><td class="crud_footer_right" width="329"><img style="width:329px;height:13px;" height="13" alt="" src="/images/crud/crud_spacer.gif" width="329" border="0" /></td></tr></tbody></table></td></tr></tbody></table></div></form></body></html></xsl:template><xsl:template name="layout-header-menu.override"><li><a href="javascript:void(0)"><span>Menu Item</span></a></li><li><a href="javascript:void(0);"><span>Menu Item</span></a></li></xsl:template><xsl:template name="layout-footer-menu.override"><td class="crud_footer_menu_text">Copyright <xsl:value-of select="key('variable', 'YYYYC')"></xsl:value-of> LANSA</td><td class="crud_footer_menu_text">|</td><td class="crud_footer_menu_text"><a href="">A propos</a></td><td class="crud_footer_menu_text">|</td><td class="crud_footer_menu_text"><a href="">Nous contacter</a></td></xsl:template><xsl:template name="layout-footer-links.override"><tr><td style="width:1024px;height:25px" width="1024"><table style="width:100%;" cellspacing="0" cellpadding="0" width="100%" border="0"><tbody><tr><td class="crud_footer_left_bg"><img height="1" alt="" src="/images/crud/crud_spacer.gif" width="1" /></td><td class="crud_footer_bgcolor" width="1016"><div id="crud_footer"><div class="crud_footer_div"><table cellspacing="0" cellpadding="0"><tbody><tr valign="top"><td class="crud_related" width="155">Liens associés</td><td class="crud_links"><ul class="crud_leftnavlist" style="margin-top:-2px;"><li> <a href="http://www.lansa.com/support/index.htm">Ressources techniques</a><br /></li></ul></td><td class="crud_links"><ul class="crud_leftnavlist" style="margin-top:-2px;"><li> <a href="http://www.lansa.com/fr/products/index.htm">Présentation produit</a><br /></li></ul></td><td class="crud_links"><ul class="crud_leftnavlist" style="margin-top:-2px;"><li> <a href="http://www.lansa.com/fr/education/index.htm">Education LANSA</a><br /></li></ul></td></tr></tbody></table></div></div></td><td class="crud_footer_right_bg"><img height="1" alt="" src="/images/crud/crud_spacer.gif" width="1" /></td></tr></tbody></table></td></tr></xsl:template></xsl:transform>