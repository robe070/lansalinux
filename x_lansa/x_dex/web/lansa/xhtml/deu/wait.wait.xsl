<?xml version="1.0" encoding="UTF-8"?><!--WAM : Wait - Wait for 5 minutes Webroutine: wait - Wait Timestamp : 2014-07-11T10:56:54+10:00--><xsl:transform version="1.0" exclude-result-prefixes="lxml wd" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design" xmlns="http://www.w3.org/1999/xhtml" xmlns:xsl="http://www.w3.org/1999/XSL/Transform"><xsl:import href="std_keys.xsl"></xsl:import><xsl:import href="std_variables.xsl"></xsl:import><xsl:import href="std_hidden.xsl"></xsl:import><xsl:import href="wait_layout.xsl"></xsl:import><xsl:output method="xml" omit-xml-declaration="yes" encoding="UTF-8" indent="no"></xsl:output><xsl:template match="/"><xsl:call-template name="layout"></xsl:call-template></xsl:template><xsl:template match="/lxml:data"></xsl:template><xsl:template match="/lxml:data" mode="content.hidden"><xsl:apply-imports></xsl:apply-imports></xsl:template></xsl:transform>