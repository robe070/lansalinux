<?xml version="1.0" encoding="UTF-8"?><!--(c) 2002, 2012 LANSA--><!--XHTML Standard Messages--><!--$Workfile:: std_messages.xsl $--><!--$UTCDate:: 2013-01-02 05:01:45Z $--><!--$Revision:: 16 $--><xsl:transform version="1.0" exclude-result-prefixes="lxml wd" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design" xmlns="http://www.w3.org/1999/xhtml"><xsl:import href="std_types.xsl"></xsl:import><xsl:import href="std_util.xsl"></xsl:import><xsl:template name="messages"><xsl:param name="target_window_name"></xsl:param><div class="messages_wrapper ui-widget" id="__std_x_message_elem"><xsl:if test="not($lweb_design_mode)"><xsl:if test="not(/lxml:data/lxml:messages[lxml:message]) or ($target_window_name!='' and $target_window_name!='_self')"><xsl:attribute name="style">display:none;</xsl:attribute></xsl:if></xsl:if><div class="messages ui-state-highlight ui-corner-all"><div class="messages_label" id="__std_x_message_label">Messages:</div><div class="messages_list"><ul><xsl:for-each select="/lxml:data/lxml:messages/lxml:message"><li><xsl:value-of select="."></xsl:value-of></li></xsl:for-each><xsl:comment /></ul></div></div></div><xsl:if test="boolean(/lxml:data/lxml:messages[lxml:message]) and not($lweb_design_mode)"><script type="text/javascript"><xsl:text disable-output-escaping="yes">//&lt;![CDATA[
	</xsl:text>	stdTransferMessages("<xsl:value-of select="$target_window_name"></xsl:value-of>", "__std_x_message_elem");
<xsl:text disable-output-escaping="yes">//]]&gt;</xsl:text></script></xsl:if></xsl:template></xsl:transform>