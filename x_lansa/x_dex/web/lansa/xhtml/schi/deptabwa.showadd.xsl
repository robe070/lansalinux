<?xml version="1.0" encoding="UTF-8"?><!--WAM : DeptabWAM - Maintenance of file DEPTAB Webroutine: ShowAdd - Timestamp : 2013-10-29T13:44:57+11:00--><xsl:transform version="1.0" exclude-result-prefixes="lxml wd" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design" xmlns="http://www.w3.org/1999/xhtml" xmlns:xsl="http://www.w3.org/1999/XSL/Transform"><xsl:import href="std_keys.xsl"></xsl:import><xsl:import href="std_variables.xsl"></xsl:import><xsl:import href="std_hidden.xsl"></xsl:import><xsl:import href="deptabwa_layout.xsl"></xsl:import><xsl:import href="std_input.xsl"></xsl:import><xsl:import href="std_integer.xsl"></xsl:import><xsl:output method="xml" omit-xml-declaration="yes" encoding="UTF-8" indent="no"></xsl:output><xsl:template match="/"><xsl:call-template name="layout"></xsl:call-template></xsl:template><xsl:template match="/lxml:data"><table border="0" cellpadding="0" cellspacing="3" summary=""><tbody><tr><td><label class="caption" for="XXSHOWSCH"><xsl:value-of select="key('field-caption', 'XXSHOWSCH')/lxml:description"></xsl:value-of></label></td><td><input type="text" class="utext" name="XXSHOWSCH" id="XXSHOWSCH" size="1" maxlength="1" value="{key('field-value', 'XXSHOWSCH')}" onchange="return isValidText(this, ' ')" /></td></tr><tr><td><label class="caption" for="DEPTMENT"><xsl:value-of select="key('field-caption', 'DEPTMENT')/lxml:description"></xsl:value-of></label></td><td><input type="text" class="utext" name="DEPTMENT" id="DEPTMENT" size="4" maxlength="4" value="{key('field-value', 'DEPTMENT')}" onchange="return isValidText(this, ' ')" /></td></tr><tr><td><label class="caption" for="DEPTDESC"><xsl:value-of select="key('field-caption', 'DEPTDESC')/lxml:description"></xsl:value-of></label></td><td><input type="text" class="text" name="DEPTDESC" id="DEPTDESC" size="20" maxlength="20" value="{key('field-value', 'DEPTDESC')}" onchange="return isValidText(this, 'O')" /></td></tr></tbody></table><br /></xsl:template><xsl:template match="/lxml:data" mode="content.hidden"><xsl:apply-imports></xsl:apply-imports><input type="hidden" class="utext" name="XXKEY0101" id="XXKEY0101" size="4" maxlength="4" value="{key('field-value', 'XXKEY0101')}" /><input type="hidden" class="number" name="XXSRCHTYP" id="XXSRCHTYP" size="14" maxlength="14" value="{key('field-value', 'XXSRCHTYP')}" /></xsl:template></xsl:transform>