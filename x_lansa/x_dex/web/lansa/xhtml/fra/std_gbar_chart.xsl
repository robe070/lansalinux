<?xml version="1.0" encoding="UTF-8"?><!--(c) 2011, 2012 LANSA--><!--XHTML Google Image Bar Chart--><!--$Workfile:: std_gbar_chart.xsl $--><!--$UTCDate:: 2012-12-21 02:41:01Z $--><!--$Revision:: 16 $--><xsl:transform version="1.0" exclude-result-prefixes="lxml wd msxsl exslt" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design" xmlns:msxsl="urn:schemas-microsoft-com:xslt" xmlns:exslt="http://exslt.org/common" xmlns="http://www.w3.org/1999/xhtml"><xsl:import href="std_variables.xsl"></xsl:import><xsl:import href="std_keys.xsl"></xsl:import><xsl:import href="std_util.xsl"></xsl:import><xsl:import href="std_types.xsl"></xsl:import><xsl:output method="xml" omit-xml-declaration="yes" encoding="UTF-8" indent="yes"></xsl:output><xsl:template name="std_gbar_chart"><xsl:param name="name"></xsl:param><xsl:param name="chartType" select="'bvg'"></xsl:param><xsl:param name="listName"></xsl:param><xsl:param name="transpose" select="false()"></xsl:param><xsl:param name="labels"></xsl:param><xsl:param name="labelsColor" select="'Theme'"></xsl:param><xsl:param name="labelsFontSize"></xsl:param><xsl:param name="rangeLabels"></xsl:param><xsl:param name="rangeLabelsColor" select="'Theme'"></xsl:param><xsl:param name="rangeLabelsFontSize"></xsl:param><xsl:param name="barWidth" select="'a'"></xsl:param><xsl:param name="spaceBetweenBars" select="''"></xsl:param><xsl:param name="spaceBetweenGroups" select="''"></xsl:param><xsl:param name="seriesColors" select="'Theme'"></xsl:param><xsl:param name="bgColor" select="'Theme'"></xsl:param><xsl:param name="hide_if" select="false()"></xsl:param><xsl:param name="pos_absolute"></xsl:param><xsl:param name="width" select="400"></xsl:param><xsl:param name="height" select="250"></xsl:param><xsl:param name="titleText"></xsl:param><xsl:param name="titleColor" select="'Theme'"></xsl:param><xsl:param name="titleFontSize"></xsl:param><xsl:param name="axesColor" select="'Theme'"></xsl:param><xsl:param name="margins"></xsl:param><xsl:param name="legendText"></xsl:param><xsl:param name="legendPos" select="'r'"></xsl:param><xsl:param name="legendOrder" select="''"></xsl:param><xsl:param name="legendColor" select="'Theme'"></xsl:param><xsl:param name="legendFontSize"></xsl:param><xsl:param name="legendMargins"></xsl:param><xsl:if test="not($hide_if) or $lweb_design_mode"><xsl:variable name="labelsSourceIsXml" select="boolean($labels) and (local-name($labels) = 'caption_value_pairs')"></xsl:variable><xsl:variable name="labelsSourceIsList" select="boolean($labels) and (local-name($labels) = 'source_list')"></xsl:variable><xsl:variable name="labelsXml"><xsl:if test="$labelsSourceIsXml"><xsl:call-template name="expand_mtxt_in_xml_items.private"><xsl:with-param name="items" select="$labels"></xsl:with-param></xsl:call-template></xsl:if></xsl:variable><xsl:variable name="labelsArray"><xsl:choose><xsl:when test="not($labelsSourceIsXml)"></xsl:when><xsl:when test="$lweb_is_msxsl_nodeset"><xsl:call-template name="xml_to_string_array.private"><xsl:with-param name="list_xml" select="msxsl:node-set($labelsXml)/*"></xsl:with-param></xsl:call-template></xsl:when><xsl:when test="$lweb_is_exslt_nodeset"><xsl:call-template name="xml_to_string_array.private"><xsl:with-param name="list_xml" select="exslt:node-set($labelsXml)/*"></xsl:with-param></xsl:call-template></xsl:when></xsl:choose></xsl:variable><xsl:variable name="rangeLabelsSourceIsXml" select="boolean($rangeLabels) and (local-name($rangeLabels) = 'caption_value_pairs')"></xsl:variable><xsl:variable name="rangeLabelsSourceIsList" select="boolean($rangeLabels) and (local-name($rangeLabels) = 'source_list')"></xsl:variable><xsl:variable name="rangeLabelsXml"><xsl:if test="$rangeLabelsSourceIsXml"><xsl:call-template name="expand_mtxt_in_xml_items.private"><xsl:with-param name="items" select="$rangeLabels"></xsl:with-param></xsl:call-template></xsl:if></xsl:variable><xsl:variable name="rangeLabelsArray"><xsl:choose><xsl:when test="not($rangeLabelsSourceIsXml)"></xsl:when><xsl:when test="$lweb_is_msxsl_nodeset"><xsl:call-template name="xml_to_string_array.private"><xsl:with-param name="list_xml" select="msxsl:node-set($rangeLabelsXml)/*"></xsl:with-param></xsl:call-template></xsl:when><xsl:when test="$lweb_is_exslt_nodeset"><xsl:call-template name="xml_to_string_array.private"><xsl:with-param name="list_xml" select="exslt:node-set($rangeLabelsXml)/*"></xsl:with-param></xsl:call-template></xsl:when></xsl:choose></xsl:variable><xsl:variable name="legendTextSourceIsXml" select="boolean($legendText) and (local-name($legendText) = 'caption_value_pairs')"></xsl:variable><xsl:variable name="legendTextSourceIsList" select="boolean($legendText) and (local-name($legendText) = 'source_list')"></xsl:variable><xsl:variable name="legendTextXml"><xsl:if test="$legendTextSourceIsXml"><xsl:call-template name="expand_mtxt_in_xml_items.private"><xsl:with-param name="items" select="$legendText"></xsl:with-param></xsl:call-template></xsl:if></xsl:variable><xsl:variable name="legendTextArray"><xsl:choose><xsl:when test="not($legendTextSourceIsXml)"></xsl:when><xsl:when test="$lweb_is_msxsl_nodeset"><xsl:call-template name="xml_to_string_array.private"><xsl:with-param name="list_xml" select="msxsl:node-set($legendTextXml)/*"></xsl:with-param></xsl:call-template></xsl:when><xsl:when test="$lweb_is_exslt_nodeset"><xsl:call-template name="xml_to_string_array.private"><xsl:with-param name="list_xml" select="exslt:node-set($legendTextXml)/*"></xsl:with-param></xsl:call-template></xsl:when></xsl:choose></xsl:variable><span id="{$name}" class="ui-widget"><xsl:if test="$pos_absolute != ''"><xsl:attribute name="style"><xsl:value-of select="$pos_absolute"></xsl:value-of></xsl:attribute></xsl:if><xsl:comment /></span><script type="text/javascript"><xsl:text disable-output-escaping="yes">//&lt;![CDATA[</xsl:text><xsl:text></xsl:text>
	Lstd.Weblets.Google.Charts.Bar({id: "<xsl:value-of select="$name"></xsl:value-of>", chartType: "<xsl:value-of select="$chartType"></xsl:value-of>"<xsl:text></xsl:text><xsl:text></xsl:text>, listName: "<xsl:value-of select="$listName"></xsl:value-of>", width: <xsl:value-of select="$width"></xsl:value-of>, height: <xsl:value-of select="$height"></xsl:value-of><xsl:if test="$transpose">, transpose: <xsl:value-of select="$transpose"></xsl:value-of></xsl:if><xsl:if test="$labelsSourceIsXml or $labelsSourceIsList or ($labelsColor != 'Theme') or ($labelsFontSize)"><xsl:text>, labels: {</xsl:text><xsl:choose><xsl:when test="$labelsSourceIsList">list: "<xsl:value-of select="$labels/@name"></xsl:value-of>", column: "<xsl:value-of select="$labels/@caption"></xsl:value-of>"</xsl:when><xsl:otherwise>text: "<xsl:value-of select="$labelsArray"></xsl:value-of>"</xsl:otherwise></xsl:choose><xsl:if test="$labelsColor != 'Theme'">, color: "<xsl:value-of select="$labelsColor"></xsl:value-of>"</xsl:if><xsl:if test="$labelsFontSize">, fontSize: <xsl:value-of select="$labelsFontSize"></xsl:value-of></xsl:if><xsl:text>}</xsl:text></xsl:if><xsl:if test="$rangeLabelsSourceIsXml or $rangeLabelsSourceIsList or ($rangeLabelsColor != 'Theme') or ($rangeLabelsFontSize)"><xsl:text>, rangeLabels: {</xsl:text><xsl:choose><xsl:when test="$rangeLabelsSourceIsList">list: "<xsl:value-of select="$rangeLabels/@name"></xsl:value-of>", column: "<xsl:value-of select="$rangeLabels/@caption"></xsl:value-of>"</xsl:when><xsl:otherwise>text: "<xsl:value-of select="$rangeLabelsArray"></xsl:value-of>"</xsl:otherwise></xsl:choose><xsl:if test="$rangeLabelsColor != 'Theme'">, color: "<xsl:value-of select="$rangeLabelsColor"></xsl:value-of>"</xsl:if><xsl:if test="$rangeLabelsFontSize">, fontSize: <xsl:value-of select="$rangeLabelsFontSize"></xsl:value-of></xsl:if><xsl:text>}</xsl:text></xsl:if><xsl:if test="$barWidth != 'a'">, barWidth: "<xsl:value-of select="$barWidth"></xsl:value-of>"</xsl:if><xsl:if test="$spaceBetweenBars">, spaceBetweenBars: <xsl:value-of select="$spaceBetweenBars"></xsl:value-of></xsl:if><xsl:if test="$spaceBetweenGroups">, spaceBetweenGroups: "<xsl:value-of select="$spaceBetweenGroups"></xsl:value-of>"</xsl:if><xsl:if test="$seriesColors != 'Theme'">, colors: "<xsl:value-of select="$seriesColors"></xsl:value-of>"</xsl:if><xsl:if test="$bgColor != 'Theme'">, bgColor: "<xsl:value-of select="$bgColor"></xsl:value-of>"</xsl:if><xsl:if test="$titleText"><xsl:text></xsl:text>, title: {text: "<xsl:value-of select="$titleText"></xsl:value-of>"<xsl:text></xsl:text><xsl:if test="$titleColor != 'Theme'">, color: "<xsl:value-of select="$titleColor"></xsl:value-of>"</xsl:if><xsl:if test="$titleFontSize">, fontSize: <xsl:value-of select="$titleFontSize"></xsl:value-of></xsl:if><xsl:text>}</xsl:text></xsl:if><xsl:if test="$axesColor != 'Theme'">, axesColor: "<xsl:value-of select="$axesColor"></xsl:value-of>"</xsl:if><xsl:if test="$margins">, margins: "<xsl:value-of select="$margins"></xsl:value-of>"</xsl:if><xsl:if test="$legendTextSourceIsXml or $legendTextSourceIsList"><xsl:text>, legend: {</xsl:text><xsl:choose><xsl:when test="$legendTextSourceIsList">list: "<xsl:value-of select="$legendText/@name"></xsl:value-of>", column: "<xsl:value-of select="$legendText/@caption"></xsl:value-of>"</xsl:when><xsl:otherwise>text: "<xsl:value-of select="$legendTextArray"></xsl:value-of>"</xsl:otherwise></xsl:choose><xsl:if test="$legendPos != 'r'">, pos: "<xsl:value-of select="$legendPos"></xsl:value-of>"</xsl:if><xsl:if test="$legendOrder != ''">, order: "<xsl:value-of select="$legendOrder"></xsl:value-of>"</xsl:if><xsl:if test="$legendColor != 'Theme'">, color: "<xsl:value-of select="$legendColor"></xsl:value-of>"</xsl:if><xsl:if test="$legendFontSize">, fontSize: <xsl:value-of select="$legendFontSize"></xsl:value-of></xsl:if><xsl:if test="$legendMargins">, margins: "<xsl:value-of select="$legendMargins"></xsl:value-of>"</xsl:if><xsl:text>}</xsl:text></xsl:if>});<xsl:text></xsl:text><xsl:text disable-output-escaping="yes">//]]&gt;</xsl:text></script></xsl:if></xsl:template><xsl:template name="xml_to_string_array.private"><xsl:param name="list_xml"></xsl:param><xsl:for-each select="$list_xml/lxml:item"><xsl:value-of select="lxml:caption"></xsl:value-of><xsl:if test="position() != last()">,</xsl:if></xsl:for-each></xsl:template></xsl:transform>