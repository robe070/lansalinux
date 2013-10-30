<?xml version="1.0" encoding="UTF-8"?><!--(c) 2003, 2012 LANSA--><!--XHTML Standard menu item--><!--$Workfile:: std_menu_item.xsl $--><!--$UTCDate:: 2013-01-02 05:01:45Z $--><!--$Revision:: 14 $--><!--A hyperlink menu item used in menus--><xsl:transform version="1.0" exclude-result-prefixes="lxml wd" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns="http://www.w3.org/1999/xhtml"><xsl:import href="std_variables.xsl"></xsl:import><xsl:import href="std_util.xsl"></xsl:import><xsl:import href="std_types.xsl"></xsl:import><xsl:import href="std_hidden.xsl"></xsl:import><xsl:output method="xml" omit-xml-declaration="yes" encoding="UTF-8" indent="yes"></xsl:output><xsl:template name="std_menu_item"><xsl:param name="name"></xsl:param><xsl:param name="caption" select="'Caption'"></xsl:param><xsl:param name="left_rel_image_path"></xsl:param><xsl:param name="left_abs_image_path"><xsl:if test="$left_rel_image_path != ''"><xsl:value-of select="$lweb_images_path"></xsl:value-of><xsl:text>/</xsl:text><xsl:value-of select="$left_rel_image_path"></xsl:value-of></xsl:if></xsl:param><xsl:param name="selected_left_rel_image_path"></xsl:param><xsl:param name="selected_left_abs_image_path"><xsl:choose><xsl:when test="$selected_left_rel_image_path != ''"><xsl:value-of select="$lweb_images_path"></xsl:value-of><xsl:text>/</xsl:text><xsl:value-of select="$selected_left_rel_image_path"></xsl:value-of></xsl:when><xsl:otherwise><xsl:value-of select="$left_abs_image_path"></xsl:value-of></xsl:otherwise></xsl:choose></xsl:param><xsl:param name="left_image_width" select="5"></xsl:param><xsl:param name="left_image_height" select="10"></xsl:param><xsl:param name="right_rel_image_path"></xsl:param><xsl:param name="right_abs_image_path"><xsl:if test="$right_rel_image_path != ''"><xsl:value-of select="$lweb_images_path"></xsl:value-of><xsl:text>/</xsl:text><xsl:value-of select="$right_rel_image_path"></xsl:value-of></xsl:if></xsl:param><xsl:param name="selected_right_rel_image_path"></xsl:param><xsl:param name="selected_right_abs_image_path"><xsl:choose><xsl:when test="$selected_right_rel_image_path != ''"><xsl:value-of select="$lweb_images_path"></xsl:value-of><xsl:text>/</xsl:text><xsl:value-of select="$selected_right_rel_image_path"></xsl:value-of></xsl:when><xsl:otherwise><xsl:value-of select="$right_abs_image_path"></xsl:value-of></xsl:otherwise></xsl:choose></xsl:param><xsl:param name="right_image_width" select="$left_image_width"></xsl:param><xsl:param name="right_image_height" select="$left_image_height"></xsl:param><xsl:param name="left_mouseover_rel_image_path"></xsl:param><xsl:param name="left_mouseover_abs_image_path"><xsl:if test="$left_mouseover_rel_image_path != ''"><xsl:value-of select="$lweb_images_path"></xsl:value-of><xsl:text>/</xsl:text><xsl:value-of select="$left_mouseover_rel_image_path"></xsl:value-of></xsl:if></xsl:param><xsl:param name="right_mouseover_rel_image_path"></xsl:param><xsl:param name="right_mouseover_abs_image_path"><xsl:if test="$right_mouseover_rel_image_path != ''"><xsl:value-of select="$lweb_images_path"></xsl:value-of><xsl:text>/</xsl:text><xsl:value-of select="$right_mouseover_rel_image_path"></xsl:value-of></xsl:if></xsl:param><xsl:param name="href"></xsl:param><xsl:param name="on_click_wamname" select="$lweb_WAMName"></xsl:param><xsl:param name="on_click_wrname"></xsl:param><xsl:param name="protocol"></xsl:param><xsl:param name="is_selected_if_also" select="true()"></xsl:param><xsl:param name="hide_if" select="false()"></xsl:param><xsl:param name="show_in_new_window" select="false()"></xsl:param><xsl:param name="target_window_name"><xsl:if test="$show_in_new_window">_blank</xsl:if></xsl:param><xsl:param name="reentryfield"></xsl:param><xsl:param name="reentryvalue"></xsl:param><xsl:param name="formname" select="'LANSA'"></xsl:param><xsl:param name="pos_absolute" select="'left:0pt;top:0pt'"></xsl:param><xsl:param name="width_design"></xsl:param><xsl:param name="height_design"></xsl:param><xsl:param name="bg_color"></xsl:param><xsl:param name="selected_bg_color"></xsl:param><xsl:param name="mouseover_bg_color"></xsl:param><xsl:param name="mouseover_fg_color">red</xsl:param><xsl:param name="styleclass" select="'std_menu_item'"></xsl:param><xsl:param name="anchor_class" select="'std_menu'"></xsl:param><xsl:param name="selected_styleclass" select="'std_menu_item'"></xsl:param><xsl:param name="selected_anchor_class" select="'std_menu'"></xsl:param><xsl:param name="methods" select="'get, post'"></xsl:param><xsl:param name="tab_index"></xsl:param><xsl:variable name="temp_formname" select="generate-id(document(''))"></xsl:variable><xsl:variable name="target" select="$target_window_name"></xsl:variable><xsl:if test="not($hide_if) or $lweb_design_mode"><xsl:variable name="is_selected"><xsl:choose><xsl:when test="$lweb_WAMName=$on_click_wamname and $lweb_context/lxml:webroutine=$on_click_wrname and $is_selected_if_also"><xsl:value-of select="1"></xsl:value-of></xsl:when><xsl:otherwise><xsl:value-of select="0"></xsl:value-of></xsl:otherwise></xsl:choose></xsl:variable><xsl:variable name="left-image-name" select="concat('left', generate-id())"></xsl:variable><xsl:variable name="right-image-name" select="concat('right', generate-id())"></xsl:variable><table cellspacing="0" cellpadding="0" border="0"><xsl:attribute name="style"><xsl:if test="$pos_absolute or $height_design or $width_design"><xsl:call-template name="make_size_and_pos_style_v2.private"><xsl:with-param name="caller_name" select="'std_menu_item.xsl'"></xsl:with-param><xsl:with-param name="pos_absolute" select="$pos_absolute"></xsl:with-param><xsl:with-param name="height" select="$height_design"></xsl:with-param><xsl:with-param name="width" select="$width_design"></xsl:with-param></xsl:call-template></xsl:if><xsl:text>;display: inline;</xsl:text></xsl:attribute><tbody><tr><xsl:if test="$left_abs_image_path != '' or ($is_selected=1 and $selected_left_abs_image_path!='')"><td><xsl:value-of select="''"></xsl:value-of><img name="{$left-image-name}" height="{$left_image_height}" width="{$left_image_width}" border="0" src="{$left_abs_image_path}"><xsl:if test="$is_selected=1"><xsl:attribute name="src"><xsl:value-of select="$selected_left_abs_image_path"></xsl:value-of></xsl:attribute></xsl:if></img><xsl:value-of select="''"></xsl:value-of></td></xsl:if><td><xsl:if test="$is_selected=1 and $selected_styleclass!=''"><xsl:attribute name="class"><xsl:value-of select="$selected_styleclass"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$is_selected!=1 and $styleclass!=''"><xsl:attribute name="class"><xsl:value-of select="$styleclass"></xsl:value-of></xsl:attribute></xsl:if><xsl:value-of select="''"></xsl:value-of><a methods="{$methods}"><xsl:choose><xsl:when test="$on_click_wrname!=''"><xsl:attribute name="onclick"><xsl:text></xsl:text>return stdMenuItemClicked(event, this, '<xsl:value-of select="$on_click_wamname"></xsl:value-of>', '<xsl:value-of select="$on_click_wrname"></xsl:value-of>', '<xsl:value-of select="$formname"></xsl:value-of>', '<xsl:value-of select="$protocol"></xsl:value-of>', '<xsl:value-of select="$target_window_name"></xsl:value-of>');<xsl:text></xsl:text></xsl:attribute><xsl:attribute name="href">javascript:void(0);</xsl:attribute></xsl:when><xsl:otherwise><xsl:attribute name="href"><xsl:value-of select="$href"></xsl:value-of></xsl:attribute></xsl:otherwise></xsl:choose><xsl:if test="$name!=''"><xsl:attribute name="id"><xsl:value-of select="$name"></xsl:value-of></xsl:attribute></xsl:if><xsl:variable name="style"><xsl:if test="($is_selected!=1 or $selected_bg_color='') and $bg_color != ''"><xsl:text>background-color: </xsl:text><xsl:value-of select="$bg_color"></xsl:value-of><xsl:text>; </xsl:text></xsl:if><xsl:if test="$is_selected=1 and $selected_bg_color != ''"><xsl:text>background-color: </xsl:text><xsl:value-of select="$selected_bg_color"></xsl:value-of><xsl:text>; </xsl:text></xsl:if><xsl:if test="$width_design!=''"><xsl:text>width:100%;</xsl:text></xsl:if></xsl:variable><xsl:if test="$style!=''"><xsl:attribute name="style"><xsl:value-of select="$style"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$tab_index != ''"><xsl:attribute name="tabindex"><xsl:value-of select="$tab_index"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$on_click_wrname = '' and $target!= ''"><xsl:attribute name="target"><xsl:value-of select="$target"></xsl:value-of></xsl:attribute></xsl:if><xsl:choose><xsl:when test="$is_selected=1 and $selected_anchor_class!=''"><xsl:attribute name="class"><xsl:value-of select="$selected_anchor_class"></xsl:value-of></xsl:attribute></xsl:when><xsl:otherwise><xsl:if test="$anchor_class!=''"><xsl:attribute name="class"><xsl:value-of select="$anchor_class"></xsl:value-of></xsl:attribute></xsl:if></xsl:otherwise></xsl:choose><xsl:if test="$on_click_wrname != ''"><xsl:attribute name="methods">post</xsl:attribute></xsl:if><xsl:variable name="onmouseover"><xsl:if test="($left_abs_image_path != '' and $left_mouseover_abs_image_path != '')"><xsl:text>stdGetDescendantByNameOrId(this.parentNode.parentNode.parentNode, '</xsl:text><xsl:value-of select="$left-image-name"></xsl:value-of><xsl:text>').src='</xsl:text><xsl:value-of select="$left_mouseover_abs_image_path"></xsl:value-of><xsl:text>';</xsl:text></xsl:if><xsl:if test="$right_abs_image_path != '' and $right_mouseover_abs_image_path != ''"><xsl:text>stdGetDescendantByNameOrId(this.parentNode.parentNode.parentNode, '</xsl:text><xsl:value-of select="$right-image-name"></xsl:value-of><xsl:text>').src='</xsl:text><xsl:value-of select="$right_mouseover_abs_image_path"></xsl:value-of><xsl:text>';</xsl:text></xsl:if><xsl:if test="$mouseover_bg_color != ''"><xsl:text>this._prevBgColor = this.style.backgroundColor;this.style.backgroundColor = '</xsl:text><xsl:value-of select="$mouseover_bg_color"></xsl:value-of><xsl:text>';</xsl:text></xsl:if><xsl:if test="$mouseover_fg_color != ''"><xsl:text>this._prevFgColor = this.style.color;this.style.color = '</xsl:text><xsl:value-of select="$mouseover_fg_color"></xsl:value-of><xsl:text>';</xsl:text></xsl:if></xsl:variable><xsl:if test="$onmouseover != ''"><xsl:attribute name="onmouseover"><xsl:value-of select="$onmouseover"></xsl:value-of></xsl:attribute></xsl:if><xsl:variable name="onmouseout"><xsl:if test="$left_abs_image_path != '' and $left_mouseover_abs_image_path != ''"><xsl:text>stdGetDescendantByNameOrId(this.parentNode.parentNode.parentNode, '</xsl:text><xsl:value-of select="$left-image-name"></xsl:value-of><xsl:text>').src='</xsl:text><xsl:choose><xsl:when test="$is_selected=1"><xsl:value-of select="$selected_left_abs_image_path"></xsl:value-of></xsl:when><xsl:otherwise><xsl:value-of select="$left_abs_image_path"></xsl:value-of></xsl:otherwise></xsl:choose><xsl:text>';</xsl:text></xsl:if><xsl:if test="$right_abs_image_path != '' and $right_mouseover_abs_image_path != ''"><xsl:text>stdGetDescendantByNameOrId(this.parentNode.parentNode.parentNode, '</xsl:text><xsl:value-of select="$right-image-name"></xsl:value-of><xsl:text>').src='</xsl:text><xsl:choose><xsl:when test="$is_selected=1"><xsl:value-of select="$selected_right_abs_image_path"></xsl:value-of></xsl:when><xsl:otherwise><xsl:value-of select="$right_abs_image_path"></xsl:value-of></xsl:otherwise></xsl:choose><xsl:text>';</xsl:text></xsl:if><xsl:if test="$mouseover_bg_color != ''"><xsl:text>this.style.backgroundColor = this._prevBgColor; this.removeAttribute('_prevBgColor');</xsl:text></xsl:if><xsl:if test="$mouseover_fg_color != ''"><xsl:text>this.style.color = this._prevFgColor; this.removeAttribute('_prevFgColor');</xsl:text></xsl:if></xsl:variable><xsl:if test="$onmouseout != ''"><xsl:attribute name="onmouseout"><xsl:value-of select="$onmouseout"></xsl:value-of></xsl:attribute></xsl:if><xsl:value-of select="''"></xsl:value-of><xsl:if test="$reentryfield != ''"><span class="hidden__"><span class="reentryfield" style="display:none;"><xsl:value-of select="$reentryfield"></xsl:value-of><xsl:comment /></span><span class="reentryvalue" style="display:none;"><xsl:value-of select="$reentryvalue"></xsl:value-of><xsl:comment /></span></span></xsl:if><span><xsl:value-of select="''"></xsl:value-of><xsl:value-of select="$caption"></xsl:value-of><xsl:value-of select="''"></xsl:value-of><xsl:comment /></span><xsl:value-of select="''"></xsl:value-of></a><xsl:value-of select="''"></xsl:value-of></td><xsl:if test="$right_abs_image_path != '' or($is_selected=1 and $selected_right_abs_image_path!='')"><td><xsl:value-of select="''"></xsl:value-of><img name="{$right-image-name}" height="{$right_image_height}" width="{$right_image_width}" border="0" src="{$right_abs_image_path}"><xsl:if test="$is_selected=1"><xsl:attribute name="src"><xsl:value-of select="$selected_right_abs_image_path"></xsl:value-of></xsl:attribute></xsl:if></img><xsl:value-of select="''"></xsl:value-of></td></xsl:if></tr></tbody></table></xsl:if></xsl:template></xsl:transform>