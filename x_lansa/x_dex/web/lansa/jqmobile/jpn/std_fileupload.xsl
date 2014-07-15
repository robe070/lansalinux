<?xml version="1.0" encoding="UTF-8"?><!--(c) 2014 LANSA--><!--jqMobile File upload--><!--$Workfile:: std_fileupload.xsl $--><!--$UTCDate:: 2014-05-15 07:21:23Z $--><!--$Revision:: 10 $--><xsl:transform version="1.0" exclude-result-prefixes="msxsl lxml wd wds" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design" xmlns:wds="http://www.lansa.com/2002/XSL/Weblet-Design/Extension" xmlns:msxsl="urn:schemas-microsoft-com:xslt" xmlns="http://www.w3.org/1999/xhtml"><xsl:import href="std_variables.xsl"></xsl:import><xsl:import href="std_keys.xsl"></xsl:import><xsl:import href="std_types.xsl"></xsl:import><xsl:import href="std_util.xsl"></xsl:import><xsl:output method="xml" omit-xml-declaration="yes" encoding="UTF-8" indent="yes"></xsl:output><xsl:template name="std_fileupload"><xsl:param name="name" select="generate-id()"></xsl:param><xsl:param name="id" select="$name"></xsl:param><xsl:param name="caption" select="'Default'"></xsl:param><xsl:param name="class" select="''"></xsl:param><xsl:param name="hideIf" select="false()"></xsl:param><xsl:param name="inline" select="false()"></xsl:param><xsl:param name="uploadWamName" select="$lweb_WAMName"></xsl:param><xsl:param name="uploadWrName"></xsl:param><xsl:param name="submitExtraFields" select="document('')/*/lxml:data/lxml:json[not(@id)]"></xsl:param><xsl:param name="maxFileSize" select="5"></xsl:param><xsl:param name="maxNumberOfFiles" select="1"></xsl:param><xsl:param name="successCallback" select="''"></xsl:param><xsl:param name="failCallback" select="''"></xsl:param><xsl:param name="disabled" select="false()"></xsl:param><xsl:param name="tabindex"></xsl:param><xsl:if test="not($hideIf) or $lweb_design_mode"><div class="std_fileupload" data-lstdfileupload-id="{$id}"><span><xsl:attribute name="class"><xsl:text>ui-btn ui-icon-plus ui-btn-icon-left ui-corner-all </xsl:text><xsl:if test="$inline">ui-btn-inline </xsl:if><xsl:text>fileinput-button std_fileinput-button</xsl:text></xsl:attribute><span><xsl:value-of select="$caption"></xsl:value-of><xsl:comment /></span><input id="{$id}" type="file" name="{$id}" data-enhanced="true" data-lstdmaxfilesize="{$maxFileSize}" data-lstdmaxnumberoffiles="{$maxNumberOfFiles}"><xsl:if test="$maxNumberOfFiles &gt; 1"><xsl:attribute name="multiple">multiple</xsl:attribute></xsl:if><xsl:if test="$uploadWamName != ''"><xsl:attribute name="data-lansawam"><xsl:value-of select="$uploadWamName"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$uploadWrName != ''"><xsl:attribute name="data-lansawr"><xsl:value-of select="$uploadWrName"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$successCallback != ''"><xsl:attribute name="data-lstdsuccesscallback"><xsl:value-of select="$successCallback"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$failCallback != ''"><xsl:attribute name="data-lstdfailcallback"><xsl:value-of select="$failCallback"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$tabindex != ''"><xsl:attribute name="tabindex"><xsl:value-of select="$tabindex"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$class != ''"><xsl:attribute name="data-lstdclass"><xsl:value-of select="$class"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$disabled"><xsl:attribute name="disabled">disabled</xsl:attribute></xsl:if><xsl:if test="$submitExtraFields"><xsl:attribute name="data-lansaextrafields"><xsl:value-of select="$submitExtraFields"></xsl:value-of></xsl:attribute></xsl:if></input></span></div><br /><div><table id="__{$id}_FILES"><tbody></tbody></table><div class="std_fileupload_pb"><div id="__{$id}_PROGRESS" class="ui-slider-track ui-shadow-inset ui-bar-inherit ui-corner-all lstd-progressbar"></div></div></div></xsl:if></xsl:template></xsl:transform>