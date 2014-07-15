<?xml version="1.0" encoding="UTF-8"?><!--(c) 2011, 2014 LANSA--><!--jqMobile Standard Scripts--><!--$Workfile:: std_script.xsl $--><!--$UTCDate:: 2014-02-06 08:49:02Z $--><!--$Revision:: 15 $--><xsl:transform version="1.0" exclude-result-prefixes="lxml wd" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design" xmlns="http://www.w3.org/1999/xhtml"><xsl:import href="std_keys.xsl"></xsl:import><xsl:import href="std_variables.xsl"></xsl:import><xsl:template name="script"><xsl:if test="not($lweb_design_mode)"><xsl:apply-templates select="$lweb_scripts[@location = 'header']"></xsl:apply-templates><script type="text/javascript"><xsl:text disable-output-escaping="yes">//&lt;![CDATA[
</xsl:text>Lstd.bootstrap();
<xsl:text disable-output-escaping="yes">//]]&gt;</xsl:text></script></xsl:if></xsl:template><xsl:template name="script.body-top"><xsl:if test="not($lweb_design_mode)"><xsl:apply-templates select="$lweb_scripts[@location = 'body-top']"></xsl:apply-templates></xsl:if></xsl:template><xsl:template name="scriptAtEnd"><script type="text/javascript"><xsl:text disable-output-escaping="yes">//&lt;![CDATA[
</xsl:text><xsl:text>Lstd.wrContext = {</xsl:text><xsl:for-each select="$lweb_context/node()"><xsl:text>"</xsl:text><xsl:value-of select="local-name()"></xsl:value-of><xsl:text>": "</xsl:text><xsl:value-of select="./text()"></xsl:value-of><xsl:text>", </xsl:text></xsl:for-each><xsl:text>"language-iso": "</xsl:text><xsl:value-of select="$lweb_ISO_language"></xsl:value-of><xsl:text>"};
Lstd.wrOptions = {</xsl:text><xsl:for-each select="/lxml:data/lxml:options/lxml:option"><xsl:text>"</xsl:text><xsl:value-of select="@name"></xsl:value-of><xsl:text>": "</xsl:text><xsl:value-of select="."></xsl:value-of><xsl:text>", </xsl:text></xsl:for-each><xsl:text>};</xsl:text><xsl:text disable-output-escaping="yes">//]]&gt;</xsl:text><xsl:text>&#32;</xsl:text></script><xsl:apply-templates select="$lweb_scripts[@location = 'body-bottom']"></xsl:apply-templates><xsl:apply-templates select="$lweb_scripts[@location = 'async' or not(@location)]"></xsl:apply-templates></xsl:template><xsl:template match="/lxml:data/lxml:external-resources/lxml:script"><script src="{$lweb_images_path}/{.}" type="text/javascript" charset="{@charset}"><xsl:comment></xsl:comment><xsl:text>&#32;</xsl:text></script></xsl:template></xsl:transform>