<?xml version="1.0" encoding="UTF-8"?><!--(c) 2002, 2012 LANSA--><!--PPC XHTML Standard Scripts--><!--$Workfile:: std_script.xsl $--><!--$UTCDate:: 2013-01-02 05:36:37Z $--><!--$Revision:: 20 $--><xsl:transform version="1.0" exclude-result-prefixes="lxml wd" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design" xmlns="http://www.w3.org/1999/xhtml"><xsl:import href="std_keys.xsl"></xsl:import><xsl:import href="std_variables.xsl"></xsl:import><xsl:template name="script"><xsl:param name="javascript_files" select="''"></xsl:param><xsl:param name="javascript_files_charset" select="$lweb_extrafiles_charset"></xsl:param><xsl:param name="trap_script_errors" select="false()"></xsl:param><xsl:if test="not($lweb_design_mode)"><script language="javascript" type="text/javascript"><xsl:text disable-output-escaping="yes">//&lt;![CDATA[
				</xsl:text>

var g_lxmlServiceName = "<xsl:value-of select="$lweb_context/lxml:service-name"></xsl:value-of>";
var g_lxmlWAMName = "<xsl:value-of select="$lweb_WAMName"></xsl:value-of>";
var g_lxmlWRName = "<xsl:value-of select="$lweb_context/lxml:webroutine"></xsl:value-of>";
var g_lxmlTs = "<xsl:value-of select="$lweb_context/lxml:technology-service"></xsl:value-of>";
var g_lxmlAR = "<xsl:value-of select="$lweb_context/lxml:action-request"></xsl:value-of>";
var g_lxmlPartition = "<xsl:value-of select="$lweb_context/lxml:partition"></xsl:value-of>";
var g_lxmlLang = "<xsl:value-of select="$lweb_part_language"></xsl:value-of>";
var g_lxmlISOLang = "<xsl:value-of select="$lweb_ISO_language"></xsl:value-of>";
var g_lmxlSKMethod = "<xsl:value-of select="$lweb_context/lxml:session-key-method"></xsl:value-of>";
var g_lxmlSK = "<xsl:value-of select="$lweb_context/lxml:session-key"></xsl:value-of>";
var g_debug = "<xsl:value-of select="key('option', 'debug')"></xsl:value-of>";
var g_lw3Trace = "<xsl:value-of select="key('option', 'trace')"></xsl:value-of>";
var g_checkNumeric = <xsl:value-of select="key('option', 'check-numeric')"></xsl:value-of>;
var g_lweb_images_path = "<xsl:value-of select="$lweb_images_path"></xsl:value-of>";
<xsl:text disable-output-escaping="yes">//]]&gt;</xsl:text></script><script language="javascript" src="{$lweb_scripts_path}/i18n/lansa_ppc_xhtml/{$lweb_script_messages_file}" type="text/javascript" charset="utf-8"><xsl:comment></xsl:comment><xsl:text>&#32;</xsl:text></script><script language="javascript" src="{$lweb_scripts_path}/std_script_lansa_ppc_xhtml.min.js" type="text/javascript" charset="utf-8"><xsl:comment></xsl:comment><xsl:text>&#32;</xsl:text></script><script language="javascript" src="{$lweb_scripts_path}/std_script_lansa_ppc_xhtml_v2.min.js" type="text/javascript" charset="utf-8"><xsl:comment></xsl:comment><xsl:text>&#32;</xsl:text></script><xsl:apply-templates select="/lxml:data/lxml:external-resources/lxml:script[@location = 'header']"></xsl:apply-templates><xsl:call-template name="JSIncludes.private"><xsl:with-param name="javascript_files" select="$javascript_files"></xsl:with-param><xsl:with-param name="javascript_files_charset" select="$javascript_files_charset"></xsl:with-param></xsl:call-template><script language="javascript" type="text/javascript"><xsl:text disable-output-escaping="yes">//&lt;![CDATA[
				</xsl:text><xsl:if test="$trap_script_errors">
try { if (trapError) window.onerror=trapError;} catch(e) {}
				</xsl:if>
new StdLocaleMgr(g_lxmlLang<xsl:if test="key('option', 'DBCS')">, <xsl:value-of select="key('option', 'DBCS')"></xsl:value-of></xsl:if>);

function HandleEvent(WAM, WebRoutine, optForm, optTarget, optProtocol) {
	_HandleEvent(WAM, WebRoutine, g_lxmlTs, g_lxmlAR, g_lxmlPartition, g_lxmlLang, optForm, optTarget, optProtocol, g_lxmlSK, g_debug);
}
function HandleServiceEvent(ServiceName, optForm, optTarget, optProtocol) {
	_HandleServiceEvent(ServiceName, g_lxmlTs, g_lxmlAR, g_lxmlPartition, g_lxmlLang, optForm, optTarget, optProtocol, g_lxmlSK, g_debug);
}
function HandleEventTarget(Form, Target, WebApp, WebRoutine, optProtocol) {
_HandleEventTarget(Form, Target, g_lxmlTs, g_lxmlAR, g_lxmlPartition, g_lxmlLang, WebApp, WebRoutine, optProtocol, g_lxmlSK, g_debug);
}
stdQScripts([<xsl:text></xsl:text><xsl:apply-templates select="/lxml:data/lxml:external-resources/lxml:script[not(@location)]"></xsl:apply-templates><xsl:text>null]);
</xsl:text><xsl:text disable-output-escaping="yes">//]]&gt;</xsl:text></script></xsl:if></xsl:template><xsl:template match="/lxml:data/lxml:external-resources/lxml:script[@location = 'header']"><script language="javascript" src="{$lweb_images_path}/{.}" type="text/javascript" charset="{@charset}"><xsl:comment></xsl:comment><xsl:text>&#32;</xsl:text></script></xsl:template><xsl:template match="/lxml:data/lxml:external-resources/lxml:script[not(@location)]"><xsl:text>["</xsl:text><xsl:value-of select="."></xsl:value-of>", "<xsl:value-of select="@charset"></xsl:value-of>"], <xsl:text></xsl:text></xsl:template><xsl:template name="JSIncludes.private"><xsl:param name="javascript_files" select="''"></xsl:param><xsl:param name="javascript_files_charset" select="''"></xsl:param><xsl:choose><xsl:when test="not($javascript_files)"></xsl:when><xsl:when test="contains($javascript_files, ',')"><xsl:if test="not(starts-with($javascript_files, ','))"><script language="javascript" src="{$lweb_scripts_path}/{substring-before($javascript_files, ',')}" type="text/javascript" charset="{$javascript_files_charset}"><xsl:comment></xsl:comment><xsl:text>&#32;</xsl:text></script></xsl:if><xsl:call-template name="JSIncludes.private"><xsl:with-param name="javascript_files" select="substring-after($javascript_files, ',')"></xsl:with-param><xsl:with-param name="javascript_files_charset" select="$javascript_files_charset"></xsl:with-param></xsl:call-template></xsl:when><xsl:otherwise><script language="javascript" src="{$lweb_scripts_path}/{$javascript_files}" type="text/javascript" charset="{$javascript_files_charset}"><xsl:comment></xsl:comment><xsl:text>&#32;</xsl:text></script></xsl:otherwise></xsl:choose></xsl:template></xsl:transform>