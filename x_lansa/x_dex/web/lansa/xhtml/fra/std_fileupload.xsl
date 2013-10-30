<?xml version="1.0" encoding="UTF-8"?><!--(c) 2013 LANSA--><!--XHTML File upload--><!--$Workfile:: std_fileupload.xsl $--><!--$UTCDate:: 2013-10-11 04:50:47Z $--><!--$Revision:: 2 $--><xsl:transform version="1.0" exclude-result-prefixes="lxml wd" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design" xmlns="http://www.w3.org/1999/xhtml"><xsl:import href="std_variables.xsl"></xsl:import><xsl:import href="std_keys.xsl"></xsl:import><xsl:import href="std_types.xsl"></xsl:import><xsl:import href="std_util.xsl"></xsl:import><xsl:output method="xml" omit-xml-declaration="yes" encoding="UTF-8" indent="yes"></xsl:output><xsl:template name="std_fileupload"><xsl:param name="id"></xsl:param><xsl:param name="caption" select="'Upload'"></xsl:param><xsl:param name="hide_if" select="false()"></xsl:param><xsl:param name="class" select="'text'"></xsl:param><xsl:param name="multiple" select="false()"></xsl:param><xsl:param name="autoUpload" select="false()"></xsl:param><xsl:param name="sendCaption" select="'Send'"></xsl:param><xsl:param name="uploadWamname" select="$lweb_WAMName"></xsl:param><xsl:param name="uploadWrname"></xsl:param><xsl:param name="submitExtraFields" select="document('')/*/lxml:data/lxml:json[not(@id)]"></xsl:param><xsl:param name="disabled" select="false()"></xsl:param><xsl:param name="title"></xsl:param><xsl:param name="text_class" select="''"></xsl:param><xsl:param name="protocol"></xsl:param><xsl:param name="tab_index"></xsl:param><xsl:param name="vf_wamevent" select="''"></xsl:param><xsl:if test="not($hide_if) or $lweb_design_mode"><div id="{$id}_grp" class="ui-widget-content"><div class="std_fileupload_hidden"><input name="{$id}" id="{$id}" type="file"><xsl:if test="$multiple"><xsl:attribute name="multiple">multiple</xsl:attribute></xsl:if></input></div><button id="__{$id}_PROXY" class="{$class}"><xsl:if test="$disabled"><xsl:attribute name="disabled">disabled</xsl:attribute></xsl:if><xsl:if test="$tab_index != ''"><xsl:attribute name="tabindex"><xsl:value-of select="$tab_index"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$title != ''"><xsl:attribute name="title"><xsl:value-of select="$title"></xsl:value-of></xsl:attribute></xsl:if><span><xsl:if test="$text_class != ''"><xsl:attribute name="class"><xsl:value-of select="$text_class"></xsl:value-of></xsl:attribute></xsl:if><xsl:value-of select="$caption"></xsl:value-of><xsl:comment /></span></button><xsl:if test="not($autoUpload)"><button id="__{$id}_SEND" class="{$class}"><xsl:if test="$disabled"><xsl:attribute name="disabled">disabled</xsl:attribute></xsl:if><xsl:if test="$tab_index != ''"><xsl:attribute name="tabindex"><xsl:value-of select="$tab_index"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$title != ''"><xsl:attribute name="title"><xsl:value-of select="$title"></xsl:value-of></xsl:attribute></xsl:if><span><xsl:if test="$text_class != ''"><xsl:attribute name="class"><xsl:value-of select="$text_class"></xsl:value-of></xsl:attribute></xsl:if><xsl:value-of select="$sendCaption"></xsl:value-of><xsl:comment /></span></button></xsl:if><div id="{$id}_files"><xsl:comment /></div></div><script type="text/javascript"><xsl:text disable-output-escaping="yes">//&lt;![CDATA[</xsl:text><xsl:text></xsl:text>
	Lstd.Weblets.registerWeblet("<xsl:value-of select="$id"></xsl:value-of>", {init: Lstd.Weblets.stdFileUpload.init}, {<xsl:text></xsl:text><xsl:text></xsl:text>autoUpload: <xsl:value-of select="$autoUpload"></xsl:value-of>, <xsl:text></xsl:text><xsl:text></xsl:text>target: {wam: "<xsl:value-of select="$uploadWamname"></xsl:value-of>", webroutine: "<xsl:value-of select="$uploadWrname"></xsl:value-of>"}<xsl:text></xsl:text><xsl:if test="$protocol != ''">, protocol: "<xsl:value-of select="$protocol"></xsl:value-of>"</xsl:if><xsl:if test="$submitExtraFields">, extraFields: <xsl:value-of select="$submitExtraFields" disable-output-escaping="yes"></xsl:value-of></xsl:if><xsl:if test="$disabled">, disabled: true</xsl:if>});<xsl:text></xsl:text><xsl:text disable-output-escaping="yes">//]]&gt;</xsl:text></script></xsl:if></xsl:template></xsl:transform>