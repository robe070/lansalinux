<?xml version="1.0" encoding="UTF-8"?><!--(c) 2003, 2014 LANSA--><!--XHTML Selectable Image--><!--$Workfile:: std_click_image.xsl $--><!--$UTCDate:: 2014-05-20 03:23:30Z $--><!--$Revision:: 23 $--><xsl:transform version="1.0" exclude-result-prefixes="lxml wd xslt" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:xslt="http://www.lansa.com/2002/XSL/Transform-Alias" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design" xmlns="http://www.w3.org/1999/xhtml"><xsl:import href="std_variables.xsl"></xsl:import><xsl:import href="std_keys.xsl"></xsl:import><xsl:import href="std_util.xsl"></xsl:import><xsl:import href="std_types.xsl"></xsl:import><xsl:output method="xml" omit-xml-declaration="yes" encoding="UTF-8" indent="yes"></xsl:output><xsl:namespace-alias stylesheet-prefix="xslt" result-prefix="xsl"></xsl:namespace-alias><xsl:template name="std_click_image"><xsl:param name="name"></xsl:param><xsl:param name="currentrowhfield" select="'STDROWNUM'"></xsl:param><xsl:param name="currentrownumval" select="position()"></xsl:param><xsl:param name="reentryfield" select="'STDRENTRY'"></xsl:param><xsl:param name="reentryvalue" select="'D'"></xsl:param><xsl:param name="tooltip" select="''"></xsl:param><xsl:param name="hide_if" select="false()"></xsl:param><xsl:param name="formname" select="'LANSA'"></xsl:param><xsl:param name="url">javascript:void(0);</xsl:param><xsl:param name="on_click_wamname" select="$lweb_WAMName"></xsl:param><xsl:param name="on_click_wrname"></xsl:param><xsl:param name="protocol"></xsl:param><xsl:param name="show_in_new_window" select="false()"></xsl:param><xsl:param name="target_window_name"><xsl:if test="$show_in_new_window">_blank</xsl:if></xsl:param><xsl:param name="disabled" select="false()"></xsl:param><xsl:param name="hide_focus" select="true()"></xsl:param><xsl:param name="relative_image_path" select="'icons/normal/16/ball_blue_16.png'"></xsl:param><xsl:param name="absolute_image_path" select="concat($lweb_images_path, '/', $relative_image_path)"></xsl:param><xsl:param name="mouseover_relative_image_path"></xsl:param><xsl:param name="mouseover_absolute_image_path"><xsl:if test="$mouseover_relative_image_path != ''"><xsl:value-of select="concat($lweb_images_path, '/', $mouseover_relative_image_path)"></xsl:value-of></xsl:if></xsl:param><xsl:param name="pos_absolute"></xsl:param><xsl:param name="width_design"></xsl:param><xsl:param name="height_design"></xsl:param><xsl:param name="class" select="'std_click_image'"></xsl:param><xsl:param name="disabled_class" select="'std_click_image_disabled'"></xsl:param><xsl:param name="presubmit_js"></xsl:param><xsl:param name="tab_index"></xsl:param><xsl:param name="vf_wamevent" select="''"></xsl:param><xsl:if test="not($hide_if) or $lweb_design_mode"><span class="ui-widget"><a><xsl:if test="$name != ''"><xsl:attribute name="id"><xsl:value-of select="$name"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$tooltip != ''"><xsl:attribute name="title"><xsl:value-of select="$tooltip"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="boolean($hide_focus)"><xsl:attribute name="hidefocus">true</xsl:attribute><xsl:attribute name="class">hidefocus</xsl:attribute></xsl:if><xsl:attribute name="style"><xsl:if test="$pos_absolute != ''"><xsl:value-of select="$pos_absolute"></xsl:value-of>;</xsl:if><xsl:text>display: inline-block;</xsl:text></xsl:attribute><xsl:if test="$url!='' and $on_click_wrname='' and $target_window_name != ''"><xsl:attribute name="target"><xsl:value-of select="$target_window_name"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$tab_index != ''"><xsl:attribute name="tabindex"><xsl:value-of select="$tab_index"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$vf_wamevent != ''"><xsl:attribute name="data-vf-wamevent"><xsl:value-of select="$vf_wamevent"></xsl:value-of></xsl:attribute></xsl:if><xsl:choose><xsl:when test="not($disabled)"><xsl:attribute name="onclick"><xsl:value-of select="$presubmit_js"></xsl:value-of><xsl:if test="$on_click_wrname != ''"><xsl:text></xsl:text>return stdAnchorClicked(event, this, '<xsl:value-of select="$on_click_wamname"></xsl:value-of>', '<xsl:value-of select="$on_click_wrname"></xsl:value-of>', '<xsl:value-of select="$formname"></xsl:value-of>', '<xsl:value-of select="$protocol"></xsl:value-of>', '<xsl:value-of select="$target_window_name"></xsl:value-of>', '<xsl:value-of select="$currentrowhfield"></xsl:value-of>', '<xsl:value-of select="$currentrownumval"></xsl:value-of>');<xsl:text></xsl:text></xsl:if></xsl:attribute><xsl:attribute name="href"><xsl:value-of select="$url"></xsl:value-of></xsl:attribute></xsl:when><xsl:otherwise><xsl:attribute name="href">javascript:void(0);</xsl:attribute></xsl:otherwise></xsl:choose><xsl:if test="$reentryfield != ''"><span class="hidden__"><span class="reentryfield" style="display:none;"><xsl:value-of select="$reentryfield"></xsl:value-of><xsl:comment /></span><span class="reentryvalue" style="display:none;"><xsl:value-of select="$reentryvalue"></xsl:value-of><xsl:comment /></span></span></xsl:if><img src="{$absolute_image_path}" __moImage="{$mouseover_absolute_image_path}" onmouseover="stdImageMouseOver(this);" onmouseout="stdImageMouseOut(this);"><xsl:attribute name="style"><xsl:text>border-style:none;</xsl:text><xsl:if test="$height_design or $width_design"><xsl:call-template name="make_size_and_pos_style_v2.private"><xsl:with-param name="caller_name" select="'std_click_image.xsl'"></xsl:with-param><xsl:with-param name="pos_absolute" select="''"></xsl:with-param><xsl:with-param name="height" select="$height_design"></xsl:with-param><xsl:with-param name="width" select="$width_design"></xsl:with-param></xsl:call-template></xsl:if></xsl:attribute><xsl:choose><xsl:when test="$class and not($disabled)"><xsl:attribute name="class"><xsl:value-of select="$class"></xsl:value-of></xsl:attribute></xsl:when><xsl:when test="$disabled_class and boolean($disabled)"><xsl:attribute name="class"><xsl:value-of select="$disabled_class"></xsl:value-of></xsl:attribute></xsl:when></xsl:choose></img></a></span><xsl:if test="boolean($mouseover_absolute_image_path)"><script type="text/javascript"><xsl:text disable-output-escaping="yes">//&lt;![CDATA[
	</xsl:text><xsl:text></xsl:text>setStdImagePreload();
	<xsl:text disable-output-escaping="yes">//]]&gt;</xsl:text></script></xsl:if></xsl:if></xsl:template></xsl:transform>