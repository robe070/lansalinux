<?xml version="1.0" encoding="UTF-8"?><!--WAM : KM_flip_empno2 - Flip Empno 2 Webroutine: km_Flip01 - Toggle value Timestamp : 2013-06-04T16:16:27+10:00--><xsl:transform version="1.0" exclude-result-prefixes="lxml wd" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design" xmlns="http://www.w3.org/1999/xhtml" xmlns:xsl="http://www.w3.org/1999/XSL/Transform"><xsl:import href="std_keys.xsl"></xsl:import><xsl:import href="std_variables.xsl"></xsl:import><xsl:import href="std_hidden.xsl"></xsl:import><xsl:import href="km@flip_layout.xsl"></xsl:import><xsl:output method="xml" omit-xml-declaration="yes" encoding="UTF-8" indent="no"></xsl:output><xsl:template match="/"><xsl:call-template name="layout"></xsl:call-template></xsl:template><xsl:template match="/lxml:data"><table border="0" cellpadding="0" cellspacing="3" summary=""><tbody><tr><td><label class="caption" for="LEMLSTR"><xsl:value-of select="key('field-caption', 'LEMLSTR')/lxml:description"></xsl:value-of></label></td><td><input type="text" class="text" name="LEMLSTR" id="LEMLSTR" size="60" maxlength="256" value="{key('field-value', 'LEMLSTR')}" onchange="return isValidText(this, 'O')" /></td></tr></tbody></table><br /></xsl:template><xsl:template match="/lxml:data" mode="content.hidden"><xsl:apply-imports></xsl:apply-imports></xsl:template></xsl:transform>