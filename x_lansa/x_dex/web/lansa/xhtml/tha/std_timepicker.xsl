<?xml version="1.0" encoding="UTF-8"?><!--(c) 2011, 2013 LANSA--><!--XHTML jQuery UI timepicker--><!--$Workfile:: std_timepicker.xsl $--><!--$UTCDate:: 2013-10-23 03:49:39Z $--><!--$Revision:: 27 $--><xsl:transform version="1.0" exclude-result-prefixes="lxml wd xslt" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:xslt="http://www.lansa.com/2002/XSL/Transform-Alias" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design" xmlns="http://www.w3.org/1999/xhtml"><xsl:import href="std_variables.xsl"></xsl:import><xsl:import href="std_types.xsl"></xsl:import><xsl:import href="std_util.xsl"></xsl:import><xsl:output method="xml" omit-xml-declaration="yes" encoding="UTF-8" indent="yes"></xsl:output><xsl:namespace-alias stylesheet-prefix="xslt" result-prefix="xsl"></xsl:namespace-alias><xsl:template name="std_timepicker"><xsl:param name="name" select="concat('o', generate-id())"></xsl:param><xsl:param name="value" select="'00:00:00'"></xsl:param><xsl:param name="display_mode" select="'input'"></xsl:param><xsl:param name="size" select="10"></xsl:param><xsl:param name="hide_if" select="false()"></xsl:param><xsl:param name="allow_sqlnull" select="false()"></xsl:param><xsl:param name="timeFormat" select="''"></xsl:param><xsl:param name="hourMin" select="0"></xsl:param><xsl:param name="hourMax" select="23"></xsl:param><xsl:param name="minuteMin" select="0"></xsl:param><xsl:param name="minuteMax" select="59"></xsl:param><xsl:param name="stepHour" select="1"></xsl:param><xsl:param name="stepMinute" select="1"></xsl:param><xsl:param name="stepSecond" select="1"></xsl:param><xsl:param name="tab_index"></xsl:param><xsl:param name="title"></xsl:param><xsl:param name="showOn" select="'focus'"></xsl:param><xsl:param name="buttonImage" select="'icons/normal/16/calendar_16.png'"></xsl:param><xsl:param name="buttonText" select="$title"></xsl:param><xsl:param name="disabled" select="false()"></xsl:param><xsl:param name="pos_absolute"></xsl:param><xsl:param name="width"></xsl:param><xsl:param name="autoSize" select="false()"></xsl:param><xsl:param name="showAnim" select="'show'"></xsl:param><xsl:param name="duration" select="'normal'"></xsl:param><xsl:param name="onchange_script"></xsl:param><xsl:if test="not($hide_if) or $lweb_design_mode"><div class="std_datetime"><xsl:attribute name="style"><xsl:if test="$pos_absolute or $width"><xsl:call-template name="make_size_and_pos_style_v2.private"><xsl:with-param name="caller_name" select="'std_date.xsl'"></xsl:with-param><xsl:with-param name="pos_absolute" select="$pos_absolute"></xsl:with-param><xsl:with-param name="width" select="$width"></xsl:with-param></xsl:call-template></xsl:if><xsl:choose><xsl:when test="$display_mode = 'hidden'">display: none;</xsl:when><xsl:otherwise>display: inline;</xsl:otherwise></xsl:choose></xsl:attribute><xsl:comment></xsl:comment><xsl:choose><xsl:when test="$display_mode != 'output'"><xsl:if test="not($lweb_design_mode) or key('design_doc_name', 'std_datepicker.xsl')"><input type="hidden" name="{$name}" id="{$name}" value="{$value}" /></xsl:if><xsl:if test="$display_mode != 'hidden'"><xsl:variable name="proxy" select="concat('__', $name, '_PROXY')"></xsl:variable><input size="{$size}" name="{$proxy}" id="{$proxy}" class="text" value="{$value}"><xsl:if test="$width"><xsl:attribute name="style">width:100%;</xsl:attribute></xsl:if><xsl:if test="$tab_index != ''"><xsl:attribute name="tabindex"><xsl:value-of select="$tab_index"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$title != ''"><xsl:attribute name="title"><xsl:value-of select="$title"></xsl:value-of></xsl:attribute></xsl:if></input><script type="text/javascript"><xsl:text disable-output-escaping="yes">//&lt;![CDATA[</xsl:text><xsl:text></xsl:text>
(function() {<xsl:text></xsl:text><xsl:if test="$onchange_script != ''">
	var onchangeFunc = function() { <xsl:value-of select="$onchange_script"></xsl:value-of>; };<xsl:text></xsl:text></xsl:if>
	Lstd.Weblets.stdTimePicker.input({timeId: "<xsl:value-of select="$name"></xsl:value-of>"<xsl:text></xsl:text><xsl:if test="$timeFormat != ''">, timeFormat: "<xsl:value-of select="$timeFormat"></xsl:value-of>"</xsl:if><xsl:if test="$hourMin != 0">, hourMin: <xsl:value-of select="$hourMin"></xsl:value-of></xsl:if><xsl:if test="$hourMax != 23">, hourMax: <xsl:value-of select="$hourMax"></xsl:value-of></xsl:if><xsl:if test="$minuteMin != 0">, minuteMin: <xsl:value-of select="$minuteMin"></xsl:value-of></xsl:if><xsl:if test="$minuteMax != 59">, minuteMax: <xsl:value-of select="$minuteMax"></xsl:value-of></xsl:if><xsl:if test="$stepHour &gt; 1">, stepHour: <xsl:value-of select="$stepHour"></xsl:value-of></xsl:if><xsl:if test="$stepMinute &gt; 1">, stepMinute: <xsl:value-of select="$stepMinute"></xsl:value-of></xsl:if><xsl:if test="$stepSecond &gt; 1">, stepSecond: <xsl:value-of select="$stepSecond"></xsl:value-of></xsl:if><xsl:if test="$showOn != 'focus'">, showOn: "<xsl:value-of select="$showOn"></xsl:value-of>"<xsl:text></xsl:text><xsl:if test="$buttonImage !='icons/normal/16/calendar_16.png'">, buttonImage: "<xsl:value-of select="$buttonImage"></xsl:value-of>"</xsl:if><xsl:if test="$buttonText !=''">, buttonText: "<xsl:value-of select="$buttonText"></xsl:value-of>"</xsl:if></xsl:if><xsl:if test="$disabled">, disabled: <xsl:value-of select="$disabled"></xsl:value-of></xsl:if><xsl:if test="$allow_sqlnull">, allowSQLNull: <xsl:value-of select="$allow_sqlnull"></xsl:value-of></xsl:if><xsl:if test="$autoSize">, autoSize: <xsl:value-of select="$autoSize"></xsl:value-of></xsl:if><xsl:if test="$showAnim != 'show'">, showAnim: "<xsl:value-of select="$showAnim"></xsl:value-of>"</xsl:if><xsl:if test="$duration != 'normal'">, duration: "<xsl:value-of select="$duration"></xsl:value-of>"</xsl:if><xsl:if test="$onchange_script != ''">, onchangeScript: onchangeFunc</xsl:if>});<xsl:text></xsl:text>
})(); <xsl:text></xsl:text><xsl:text disable-output-escaping="yes">//]]&gt;</xsl:text></script></xsl:if></xsl:when><xsl:otherwise><span id="{$name}" __isovalue="{$value}"><br /></span><script type="text/javascript"><xsl:text disable-output-escaping="yes">//&lt;![CDATA[</xsl:text>
	Lstd.Weblets.stdTimePicker.output({timeId: "<xsl:value-of select="$name"></xsl:value-of>"<xsl:text></xsl:text><xsl:if test="$timeFormat != ''">, timeFormat: "<xsl:value-of select="$timeFormat"></xsl:value-of>"</xsl:if>});<xsl:text></xsl:text><xsl:text disable-output-escaping="yes">//]]&gt;</xsl:text></script></xsl:otherwise></xsl:choose><xsl:comment /></div></xsl:if></xsl:template></xsl:transform>