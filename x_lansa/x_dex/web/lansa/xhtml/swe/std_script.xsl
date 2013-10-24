<?xml version="1.0" encoding="UTF-8"?><!--(c) 2002, 2012 LANSA--><!--XHTML Standard Scripts--><!--$Workfile:: std_script.xsl $--><!--$UTCDate:: 2013-01-02 05:36:37Z $--><!--$Revision:: 32 $--><xsl:transform version="1.0" exclude-result-prefixes="lxml wd" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design" xmlns="http://www.w3.org/1999/xhtml"><xsl:import href="std_keys.xsl"></xsl:import><xsl:import href="std_variables.xsl"></xsl:import><xsl:template name="script"><xsl:param name="javascript_files" select="''"></xsl:param><xsl:param name="javascript_files_charset" select="$lweb_extrafiles_charset"></xsl:param><xsl:param name="trap_script_errors" select="false()"></xsl:param><xsl:param name="jQueryNoConflict" select="false()"></xsl:param><xsl:if test="not($lweb_design_mode)"><script type="text/javascript"><xsl:text disable-output-escaping="yes">//&lt;![CDATA[
</xsl:text>
var g_lxmlServiceName = "<xsl:value-of select="$lweb_context/lxml:service-name"></xsl:value-of>";
var g_lxmlWAMName = "<xsl:value-of select="$lweb_WAMName"></xsl:value-of>";
var g_lxmlWRName = "<xsl:value-of select="$lweb_context/lxml:webroutine"></xsl:value-of>";
var g_lxmlTs = "<xsl:value-of select="$lweb_context/lxml:technology-service"></xsl:value-of>";
var g_lxmlAR = "<xsl:value-of select="$lweb_context/lxml:action-request"></xsl:value-of>";
var g_lxmlPartition = "<xsl:value-of select="$lweb_context/lxml:partition"></xsl:value-of>";
var g_lxmlLang = "<xsl:value-of select="$lweb_part_language"></xsl:value-of>";
var g_lxmlISOLang = "<xsl:value-of select="$lweb_ISO_language"></xsl:value-of>";
<xsl:if test="key('option', 'DBCS') = 'true'">var g_lxmlDBCS = true;</xsl:if>
var g_lmxlSKMethod = "<xsl:value-of select="$lweb_context/lxml:session-key-method"></xsl:value-of>";
var g_lxmlSK = "<xsl:value-of select="$lweb_context/lxml:session-key"></xsl:value-of>";
var g_debug = "<xsl:value-of select="key('option', 'debug')"></xsl:value-of>";
var g_lw3Trace = "<xsl:value-of select="key('option', 'trace')"></xsl:value-of>";
var g_checkNumeric = <xsl:value-of select="key('option', 'check-numeric')"></xsl:value-of>;
var g_lweb_images_path = "<xsl:value-of select="$lweb_images_path"></xsl:value-of>";
var g_lweb_navPanelReloadArrayName = "<xsl:value-of select="$lweb_reload_navs_arr_attr_name"></xsl:value-of>";
var g_lweb_navPanelReloadAttrName = "<xsl:value-of select="$lweb_reload_navs_on_click_attr_name"></xsl:value-of>";
var g_lweb_navPanelDelayLoadArrayName = "<xsl:value-of select="$lweb_delayload_navs_arr_attr_name"></xsl:value-of>";
var g_lweb_navPanelDelayLoadAttrName = "<xsl:value-of select="$lweb_hidden_delayload_navs_attr_name"></xsl:value-of>";
<xsl:if test="$jQueryNoConflict">var g_lweb_jQueryNoConflict = true;</xsl:if><xsl:text disable-output-escaping="yes">//]]&gt;</xsl:text></script><script src="{$lweb_scripts_path}/std_script.min.js" type="text/javascript" charset="utf-8"><xsl:comment></xsl:comment><xsl:text>&#32;</xsl:text></script><script src="{$lweb_scripts_path}/std_script_v2.min.js" type="text/javascript" charset="utf-8"><xsl:comment></xsl:comment><xsl:text>&#32;</xsl:text></script><xsl:apply-templates select="/lxml:data/lxml:external-resources/lxml:script[@location = 'header']"></xsl:apply-templates><xsl:call-template name="JSIncludes.private"><xsl:with-param name="javascript_files" select="$javascript_files"></xsl:with-param><xsl:with-param name="javascript_files_charset" select="$javascript_files_charset"></xsl:with-param></xsl:call-template><script type="text/javascript"><xsl:text disable-output-escaping="yes">//&lt;![CDATA[
</xsl:text><xsl:if test="$trap_script_errors">
try { if (trapError) window.onerror=trapError;} catch(e) {}
</xsl:if>
Lstd.bootstrap();
Lstd.registerLists([<xsl:text></xsl:text><xsl:for-each select="/lxml:data/lxml:lists/lxml:json-list"><xsl:value-of select="."></xsl:value-of>,</xsl:for-each><xsl:text>null]);
</xsl:text>
function HandleEvent(WAM, WebRoutine, optForm, optTarget, optProtocol) {
	_HandleEvent(WAM, WebRoutine, g_lxmlTs, g_lxmlAR, g_lxmlPartition, g_lxmlLang, optForm, optTarget, optProtocol, g_lxmlSK, g_debug);
}
function HandleWebEvent(Process, Webevent, optForm, optTarget) {
	var stdAnchorVal = "<xsl:value-of select="key('field-value', 'STDANCHOR')"></xsl:value-of>";
	_HandleWebEventEx(Process, Webevent, optForm, optTarget, g_lxmlAR, g_lxmlPartition, g_lxmlLang, g_debug, stdAnchorVal, arguments, 4);
}
function HandleServiceEvent(ServiceName, optForm, optTarget, optProtocol) {
	_HandleServiceEvent(ServiceName, g_lxmlTs, g_lxmlAR, g_lxmlPartition, g_lxmlLang, optForm, optTarget, optProtocol, g_lxmlSK, g_debug);
}
function HandleEventTarget(Form, Target, WebApp, WebRoutine, optProtocol) {
	_HandleEventTarget(Form, Target, g_lxmlTs, g_lxmlAR, g_lxmlPartition, g_lxmlLang, WebApp, WebRoutine, optProtocol, g_lxmlSK, g_debug);
}
Lstd.Utils.qScripts([<xsl:text></xsl:text><xsl:apply-templates select="/lxml:data/lxml:external-resources/lxml:script[not(@location)]"></xsl:apply-templates><xsl:text>null]);
</xsl:text><xsl:text disable-output-escaping="yes">//]]&gt;</xsl:text></script></xsl:if></xsl:template><xsl:template match="/lxml:data/lxml:external-resources/lxml:script[@location = 'header']"><script src="{$lweb_images_path}/{.}" type="text/javascript" charset="{@charset}"><xsl:comment></xsl:comment><xsl:text>&#32;</xsl:text></script></xsl:template><xsl:template match="/lxml:data/lxml:external-resources/lxml:script[not(@location)]"><xsl:text>["</xsl:text><xsl:value-of select="."></xsl:value-of>", "<xsl:value-of select="@charset"></xsl:value-of>"], <xsl:text></xsl:text></xsl:template><xsl:template name="JSIncludes.private"><xsl:param name="javascript_files" select="''"></xsl:param><xsl:param name="javascript_files_charset" select="''"></xsl:param><xsl:choose><xsl:when test="not($javascript_files)"></xsl:when><xsl:when test="contains($javascript_files, ',')"><xsl:if test="not(starts-with($javascript_files, ','))"><script src="{$lweb_scripts_path}/{substring-before($javascript_files, ',')}" type="text/javascript" charset="{$javascript_files_charset}"><xsl:comment></xsl:comment><xsl:text>&#32;</xsl:text></script></xsl:if><xsl:call-template name="JSIncludes.private"><xsl:with-param name="javascript_files" select="substring-after($javascript_files, ',')"></xsl:with-param><xsl:with-param name="javascript_files_charset" select="$javascript_files_charset"></xsl:with-param></xsl:call-template></xsl:when><xsl:otherwise><script src="{$lweb_scripts_path}/{$javascript_files}" type="text/javascript" charset="{$javascript_files_charset}"><xsl:comment></xsl:comment><xsl:text>&#32;</xsl:text></script></xsl:otherwise></xsl:choose></xsl:template></xsl:transform>