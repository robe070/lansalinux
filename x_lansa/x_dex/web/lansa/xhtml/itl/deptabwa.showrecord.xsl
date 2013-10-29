<?xml version="1.0" encoding="UTF-8"?><!--Web application : DEPTABWAM--><!--Web routine : ShowRecord--><!--Created by user : ROBG--><!--Timestamp : 2013-10-29 17:01:06.21--><xsl:transform version="1.0" exclude-result-prefixes="lxml wd" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design" xmlns="http://www.w3.org/1999/xhtml" xmlns:xsl="http://www.w3.org/1999/XSL/Transform"><xsl:import href="std_keys.xsl"></xsl:import><xsl:import href="std_variables.xsl"></xsl:import><xsl:import href="deptabwa_layout.xsl"></xsl:import><xsl:import href="std_integer.xsl"></xsl:import><xsl:import href="std_char.xsl"></xsl:import><xsl:import href="std_datepicker.xsl"></xsl:import><xsl:import href="std_datetimepicker.xsl"></xsl:import><xsl:import href="std_float.xsl"></xsl:import><xsl:import href="std_timepicker.xsl"></xsl:import><xsl:import href="std_varchar.xsl"></xsl:import><xsl:import href="std_button_v2.xsl"></xsl:import><xsl:output method="xml" omit-xml-declaration="yes" encoding="UTF-8" indent="no"></xsl:output><xsl:template match="/"><xsl:call-template name="layout"></xsl:call-template></xsl:template><xsl:template match="/lxml:data"><div class="hidden"><input class="number" type="hidden" maxlength="23" size="23" name="PRIFILRRN" value="{key('field-value', 'PRIFILRRN')}" /><input id="XXCURROW" maxlength="14" size="14" type="hidden" name="XXCURROW" value="{key('field-value', 'XXCURROW')}" /><input type="hidden" name="DEPTMENT" value="{key('field-value', 'DEPTMENT')}" /></div><fieldset title="Review, Update or Delete Department Details."><legend class="std_legend"><span>Department Details for [ <xsl:value-of select="key('field-value','DEPTMENT')"></xsl:value-of> ]  
</span></legend><br /><table border="0" cellspacing="3" summary="" cellpadding="0"><tbody><tr><td><label class="caption" for="DEPTDESC"><xsl:value-of select="key('field-caption', 'DEPTDESC')/lxml:description"></xsl:value-of></label></td><td><input id="DEPTDESC" class="text" onchange="return isValidText( this, '')" maxlength="20" size="20" name="DEPTDESC" value="{key('field-value', 'DEPTDESC')}" /></td></tr></tbody></table></fieldset><br /><table><tbody><tr><td><xsl:call-template name="std_button_v2"><xsl:with-param name="width_design" select="'100%'"></xsl:with-param><xsl:with-param name="on_click_wrname" select="'UpdateRecord'"></xsl:with-param><xsl:with-param name="caption" select="key('variable', 'MTXT_XXSAVE')"></xsl:with-param><xsl:with-param name="name" select="concat('o', position(), '_LANSA_19576')"></xsl:with-param></xsl:call-template><xsl:comment /></td><td><xsl:call-template name="std_button_v2"><xsl:with-param name="width_design" select="'100%'"></xsl:with-param><xsl:with-param name="on_click_wrname" select="'DeleteRecord'"></xsl:with-param><xsl:with-param name="caption" select="key('variable', 'MTXT_XXDELETE')"></xsl:with-param><xsl:with-param name="name" select="concat('o', position(), '_LANSA_17782')"></xsl:with-param><xsl:with-param name="confirm" select="true()"></xsl:with-param><xsl:with-param name="confirmText" select="concat('Are you sure you want to delete the Department: [ ', key('field-value', 'DEPTMENT') , ' ] ?')"></xsl:with-param></xsl:call-template><xsl:comment /></td><td><xsl:call-template name="std_button_v2"><xsl:with-param name="width_design" select="'100%'"></xsl:with-param><xsl:with-param name="on_click_wrname" select="'ShowSearchList'"></xsl:with-param><xsl:with-param name="caption" select="key('variable', 'MTXT_XXRETURNLIST')"></xsl:with-param><xsl:with-param name="name" select="concat('o', position(), '_LANSA_32249')"></xsl:with-param></xsl:call-template><xsl:comment /></td></tr></tbody></table></xsl:template></xsl:transform>