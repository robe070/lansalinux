<?xml version="1.0" encoding="UTF-8"?><!--(c) 2003, 2012 LANSA--><!--XHTML Standard image button--><!--$Workfile:: std_image_button.xsl $--><!--$UTCDate:: 2013-01-02 02:40:34Z $--><!--$Revision:: 18 $--><xsl:transform version="1.0" exclude-result-prefixes="lxml wd xslt" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:xslt="http://www.lansa.com/2002/XSL/Transform-Alias" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design" xmlns="http://www.w3.org/1999/xhtml"><xsl:import href="std_variables.xsl"></xsl:import><xsl:import href="std_keys.xsl"></xsl:import><xsl:import href="std_types.xsl"></xsl:import><xsl:import href="std_util.xsl"></xsl:import><xsl:output method="xml" omit-xml-declaration="yes" encoding="UTF-8" indent="yes"></xsl:output><xsl:namespace-alias stylesheet-prefix="xslt" result-prefix="xsl"></xsl:namespace-alias><xsl:template name="std_image_button"><xsl:param name="name" select="generate-id()"></xsl:param><xsl:param name="caption" select="'Caption'"></xsl:param><xsl:param name="currentrowhfield" select="'STDROWNUM'"></xsl:param><xsl:param name="currentrownumval" select="position()"></xsl:param><xsl:param name="left_relative_image_path" select="'icons/normal/16/ball_red_16.png'"></xsl:param><xsl:param name="left_absolute_image_path"><xsl:if test="$left_relative_image_path != ''"><xsl:value-of select="$lweb_images_path"></xsl:value-of><xsl:text>/</xsl:text><xsl:value-of select="$left_relative_image_path"></xsl:value-of></xsl:if></xsl:param><xsl:param name="left_image_height" select="'12pt'"></xsl:param><xsl:param name="right_relative_image_path" select="''"></xsl:param><xsl:param name="right_absolute_image_path"><xsl:if test="$right_relative_image_path != ''"><xsl:value-of select="$lweb_images_path"></xsl:value-of><xsl:text>/</xsl:text><xsl:value-of select="$right_relative_image_path"></xsl:value-of></xsl:if></xsl:param><xsl:param name="right_image_height" select="'12pt'"></xsl:param><xsl:param name="reentryfield" select="'STDRENTRY'"></xsl:param><xsl:param name="reentryvalue" select="'M'"></xsl:param><xsl:param name="hide_if" select="false()"></xsl:param><xsl:param name="formname" select="'LANSA'"></xsl:param><xsl:param name="on_click_wamname" select="$lweb_WAMName"></xsl:param><xsl:param name="on_click_wrname"></xsl:param><xsl:param name="protocol"></xsl:param><xsl:param name="show_in_new_window" select="false()"></xsl:param><xsl:param name="target_window_name"><xsl:if test="$show_in_new_window">_blank</xsl:if></xsl:param><xsl:param name="disabled" select="false()"></xsl:param><xsl:param name="title"></xsl:param><xsl:param name="pos_absolute_design"></xsl:param><xsl:param name="width_design"></xsl:param><xsl:param name="height_design"></xsl:param><xsl:param name="class" select="'std_image_button'"></xsl:param><xsl:param name="mouseover_class" select="'std_image_button_mouseover'"></xsl:param><xsl:param name="left_image_class"></xsl:param><xsl:param name="right_image_class"></xsl:param><xsl:param name="text_class" select="'std_image_button_text'"></xsl:param><xsl:param name="presubmit_js"></xsl:param><xsl:param name="tab_index"></xsl:param><xsl:param name="default_button"></xsl:param><xsl:if test="not($hide_if) or $lweb_design_mode"><span class="ui-widget"><xsl:if test="$reentryfield != ''"><span class="hidden__"><span class="reentryfield" style="display:none;"><xsl:value-of select="$reentryfield"></xsl:value-of><xsl:comment /></span><span class="reentryvalue" style="display:none;"><xsl:value-of select="$reentryvalue"></xsl:value-of><xsl:comment /></span></span></xsl:if><button class="{$class}"><xsl:if test="$pos_absolute_design or $height_design or $width_design"><xsl:attribute name="style"><xsl:call-template name="make_size_and_pos_style_v2.private"><xsl:with-param name="caller_name" select="'std_image_button.xsl'"></xsl:with-param><xsl:with-param name="pos_absolute" select="$pos_absolute_design"></xsl:with-param><xsl:with-param name="height" select="$height_design"></xsl:with-param><xsl:with-param name="width" select="$width_design"></xsl:with-param></xsl:call-template></xsl:attribute></xsl:if><xsl:if test="$name!=''"><xsl:if test="boolean($default_button)"><xsl:attribute name="name"><xsl:value-of select="$name"></xsl:value-of></xsl:attribute></xsl:if><xsl:attribute name="id"><xsl:value-of select="$name"></xsl:value-of></xsl:attribute></xsl:if><xsl:choose><xsl:when test="boolean($default_button)"><xsl:attribute name="type">submit</xsl:attribute></xsl:when><xsl:otherwise><xsl:attribute name="type">button</xsl:attribute><xsl:attribute name="onclick"><xsl:text>if(isDblClick(this)){{return false;}};</xsl:text><xsl:value-of select="$presubmit_js"></xsl:value-of><xsl:if test="$on_click_wrname != ''"><xsl:text>return stdButton_clicked(event, this, '</xsl:text><xsl:value-of select="$on_click_wamname"></xsl:value-of><xsl:text>', '</xsl:text><xsl:value-of select="$on_click_wrname"></xsl:value-of><xsl:text>', '</xsl:text><xsl:value-of select="$formname"></xsl:value-of><xsl:text>', '</xsl:text><xsl:value-of select="$protocol"></xsl:value-of><xsl:text>', '</xsl:text><xsl:value-of select="$target_window_name"></xsl:value-of><xsl:text>', '</xsl:text><xsl:value-of select="$currentrowhfield"></xsl:value-of><xsl:text>', '</xsl:text><xsl:value-of select="$currentrownumval"></xsl:value-of><xsl:text>');</xsl:text></xsl:if></xsl:attribute></xsl:otherwise></xsl:choose><xsl:if test="$mouseover_class != ''"><xsl:attribute name="onmouseover"><xsl:text>this.className='</xsl:text><xsl:value-of select="$mouseover_class"></xsl:value-of><xsl:text>'</xsl:text></xsl:attribute><xsl:attribute name="onmouseout"><xsl:text>this.className='</xsl:text><xsl:value-of select="$class"></xsl:value-of><xsl:text>'</xsl:text></xsl:attribute></xsl:if><xsl:if test="$tab_index != ''"><xsl:attribute name="tabindex"><xsl:value-of select="$tab_index"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$title != ''"><xsl:attribute name="title"><xsl:value-of select="$title"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="boolean($disabled)"><xsl:attribute name="disabled">disabled</xsl:attribute></xsl:if><xsl:if test="$left_absolute_image_path != ''"><img src="{$left_absolute_image_path}" align="middle"><xsl:if test="$left_image_class!=''"><xsl:attribute name="class"><xsl:value-of select="$left_image_class"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$left_image_height != ''"><xsl:attribute name="style"><xsl:text>height:</xsl:text><xsl:value-of select="$left_image_height"></xsl:value-of><xsl:text>;</xsl:text></xsl:attribute></xsl:if></img></xsl:if><span><xsl:if test="$text_class != ''"><xsl:attribute name="class"><xsl:value-of select="$text_class"></xsl:value-of></xsl:attribute></xsl:if><xsl:value-of select="$caption"></xsl:value-of><xsl:comment /></span><xsl:if test="$right_absolute_image_path != ''"><img src="{$right_absolute_image_path}" align="middle"><xsl:if test="$right_image_class!=''"><xsl:attribute name="class"><xsl:value-of select="$right_image_class"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$right_image_height != ''"><xsl:attribute name="style"><xsl:text>height:</xsl:text><xsl:value-of select="$right_image_height"></xsl:value-of><xsl:text>;</xsl:text></xsl:attribute></xsl:if></img></xsl:if></button></span><xsl:if test="boolean($default_button)"><script type="text/javascript"><xsl:text disable-output-escaping="yes">//&lt;![CDATA[
					</xsl:text><xsl:text>stdButton_setDefault('button', '</xsl:text><xsl:value-of select="$formname"></xsl:value-of><xsl:text>', null, function(e) {if(isDblClick(this)){return false;};</xsl:text><xsl:value-of disable-output-escaping="yes" select="$presubmit_js"></xsl:value-of><xsl:if test="$on_click_wrname != ''"><xsl:text>return stdForm_Submit(this, '</xsl:text><xsl:value-of select="$on_click_wamname"></xsl:value-of><xsl:text>', '</xsl:text><xsl:value-of select="$on_click_wrname"></xsl:value-of><xsl:text>', '</xsl:text><xsl:value-of select="$protocol"></xsl:value-of><xsl:text>', '</xsl:text><xsl:value-of select="$target_window_name"></xsl:value-of><xsl:text>');</xsl:text></xsl:if><xsl:text>});</xsl:text><xsl:text disable-output-escaping="yes">//]]&gt;</xsl:text><xsl:text>&#32;</xsl:text></script></xsl:if></xsl:if></xsl:template></xsl:transform>