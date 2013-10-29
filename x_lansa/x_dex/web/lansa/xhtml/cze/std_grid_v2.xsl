<?xml version="1.0" encoding="UTF-8"?><!--(c) 2003, 2012 LANSA--><!--XHTML Standard Grid Control--><!--$Workfile:: std_grid_v2.xsl $--><!--$UTCDate:: 2012-12-21 02:54:11Z $--><!--$Revision:: 18 $--><xsl:transform version="1.0" exclude-result-prefixes="lxml wd tsml" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design" xmlns:tsml="http://www.lansa.com/2002/XML/Generation-Metadata" xmlns="http://www.w3.org/1999/xhtml"><xsl:import href="std_types.xsl"></xsl:import><xsl:import href="std_keys.xsl"></xsl:import><xsl:import href="std_char.xsl"></xsl:import><xsl:import href="std_boolean.xsl"></xsl:import><xsl:import href="std_date.xsl"></xsl:import><xsl:import href="std_float.xsl"></xsl:import><xsl:import href="std_integer.xsl"></xsl:import><xsl:import href="std_time.xsl"></xsl:import><xsl:import href="std_varchar.xsl"></xsl:import><xsl:import href="std_util.xsl"></xsl:import><xsl:output method="xml" omit-xml-declaration="yes" encoding="UTF-8" indent="yes"></xsl:output><lxml:data><lxml:list name=""><lxml:list-header><lxml:header name="COLUMN1"><lxml:heading-1>Heading 1</lxml:heading-1><lxml:heading-2></lxml:heading-2><lxml:heading-3></lxml:heading-3></lxml:header><lxml:header name="COLUMN2"><lxml:heading-1>Heading 2</lxml:heading-1><lxml:heading-2></lxml:heading-2><lxml:heading-3></lxml:heading-3></lxml:header><lxml:header name="COLUMN3"><lxml:heading-1>Heading 3</lxml:heading-1><lxml:heading-2></lxml:heading-2><lxml:heading-3></lxml:heading-3></lxml:header><lxml:header name="COLUMN4"><lxml:heading-1>Heading 4</lxml:heading-1><lxml:heading-2></lxml:heading-2><lxml:heading-3></lxml:heading-3></lxml:header><lxml:header name="COLUMN5"><lxml:heading-1>Heading 5</lxml:heading-1><lxml:heading-2></lxml:heading-2><lxml:heading-3></lxml:heading-3></lxml:header></lxml:list-header><lxml:list-entries><lxml:entry><lxml:column name="COLUMN1" id="SAMPLE_LIST.0001.COLUMN1">Value COLUMN1 1</lxml:column><lxml:column name="COLUMN2" id="SAMPLE_LIST.0001.COLUMN2">Value COLUMN2 1</lxml:column><lxml:column name="COLUMN3" id="SAMPLE_LIST.0001.COLUMN3">Value COLUMN3 1</lxml:column><lxml:column name="COLUMN4" id="SAMPLE_LIST.0001.COLUMN4">Value COLUMN4 1</lxml:column><lxml:column name="COLUMN5" id="SAMPLE_LIST.0001.COLUMN5">Value COLUMN5 1</lxml:column></lxml:entry><lxml:entry><lxml:column name="COLUMN1" id="SAMPLE_LIST.0002.COLUMN1">Value COLUMN1 2</lxml:column><lxml:column name="COLUMN2" id="SAMPLE_LIST.0002.COLUMN2">Value COLUMN2 2</lxml:column><lxml:column name="COLUMN3" id="SAMPLE_LIST.0002.COLUMN3">Value COLUMN3 2</lxml:column><lxml:column name="COLUMN4" id="SAMPLE_LIST.0002.COLUMN4">Value COLUMN4 2</lxml:column><lxml:column name="COLUMN5" id="SAMPLE_LIST.0002.COLUMN5">Value COLUMN5 2</lxml:column></lxml:entry><lxml:entry><lxml:column name="COLUMN1" id="SAMPLE_LIST.0003.COLUMN1">Value COLUMN1 3</lxml:column><lxml:column name="COLUMN2" id="SAMPLE_LIST.0003.COLUMN2">Value COLUMN2 3</lxml:column><lxml:column name="COLUMN3" id="SAMPLE_LIST.0003.COLUMN3">Value COLUMN3 3</lxml:column><lxml:column name="COLUMN4" id="SAMPLE_LIST.0003.COLUMN4">Value COLUMN4 3</lxml:column><lxml:column name="COLUMN5" id="SAMPLE_LIST.0003.COLUMN5">Value COLUMN5 3</lxml:column></lxml:entry><lxml:entry><lxml:column name="COLUMN1" id="SAMPLE_LIST.0004.COLUMN1">Value COLUMN1 4</lxml:column><lxml:column name="COLUMN2" id="SAMPLE_LIST.0004.COLUMN2">Value COLUMN2 4</lxml:column><lxml:column name="COLUMN3" id="SAMPLE_LIST.0004.COLUMN3">Value COLUMN3 4</lxml:column><lxml:column name="COLUMN4" id="SAMPLE_LIST.0004.COLUMN4">Value COLUMN4 4</lxml:column><lxml:column name="COLUMN5" id="SAMPLE_LIST.0004.COLUMN5">Value COLUMN5 4</lxml:column></lxml:entry><lxml:entry><lxml:column name="COLUMN1" id="SAMPLE_LIST.0005.COLUMN1">Value COLUMN1 5</lxml:column><lxml:column name="COLUMN2" id="SAMPLE_LIST.0005.COLUMN2">Value COLUMN2 5</lxml:column><lxml:column name="COLUMN3" id="SAMPLE_LIST.0005.COLUMN3">Value COLUMN3 5</lxml:column><lxml:column name="COLUMN4" id="SAMPLE_LIST.0005.COLUMN4">Value COLUMN4 5</lxml:column><lxml:column name="COLUMN5" id="SAMPLE_LIST.0005.COLUMN5">Value COLUMN5 5</lxml:column></lxml:entry></lxml:list-entries></lxml:list><lxml:grid id="std_grid_v2" is_container="false"><lxml:item name="COLUMN1"><lxml:properties><lxml:param name="name" modifier="@id" preferred_child_total="1"></lxml:param><lxml:param name="value" modifier="." preferred_child_total="1"></lxml:param><lxml:param role="std:display_mode" modifier="$tsml_col_mode" preferred_child_total="1"></lxml:param><lxml:param role="std:field_maxlength" modifier="$tsml_col_max_len" preferred_child_total="1"></lxml:param><lxml:param role="std:field_display_length" modifier="$tsml_col_display_len" preferred_child_total="1"></lxml:param><lxml:param role="std:field_input_type" modifier="$tsml_col_input_type" preferred_child_total="1"></lxml:param><lxml:param role="std:field_css_class" modifier="$tsml_col_css_class" preferred_child_total="1"></lxml:param></lxml:properties><lxml:caption>Column</lxml:caption><lxml:value>Column</lxml:value></lxml:item><lxml:item name="COLUMN2"><lxml:properties><lxml:param name="name" modifier="@id" preferred_child_total="1"></lxml:param><lxml:param name="value" modifier="." preferred_child_total="1"></lxml:param></lxml:properties><lxml:caption>Column</lxml:caption><lxml:value>Column</lxml:value></lxml:item><lxml:item name="COLUMN3" custom="true"><lxml:properties><lxml:param name="name" modifier="@id" preferred_child_total="1"></lxml:param><lxml:param name="value" modifier="." preferred_child_total="1"></lxml:param></lxml:properties><lxml:caption>Column</lxml:caption><lxml:value>Column</lxml:value></lxml:item><lxml:item name="COLUMN4"><lxml:properties><lxml:param name="name" modifier="@id" preferred_child_total="1"></lxml:param><lxml:param name="value" modifier="." preferred_child_total="1"></lxml:param></lxml:properties><lxml:caption>Column</lxml:caption><lxml:value>Column</lxml:value></lxml:item><lxml:item name="COLUMN5"><lxml:properties><lxml:param name="name" modifier="@id" preferred_child_total="1"></lxml:param><lxml:param name="value" modifier="." preferred_child_total="1"></lxml:param></lxml:properties><lxml:caption>Column</lxml:caption><lxml:value>Column</lxml:value></lxml:item></lxml:grid><lxml:grid id="std_grid_v2_header" is_container="false"><lxml:item name="COLUMN1"><lxml:properties><lxml:param name="value" modifier="." preferred_child_total="1"></lxml:param></lxml:properties><lxml:caption>Header</lxml:caption></lxml:item><lxml:item name="COLUMN2"><lxml:properties><lxml:param name="value" modifier="." preferred_child_total="1"></lxml:param></lxml:properties><lxml:caption>Header</lxml:caption></lxml:item><lxml:item name="COLUMN3"><lxml:properties><lxml:param name="value" modifier="." preferred_child_total="1"></lxml:param></lxml:properties><lxml:caption>Header</lxml:caption></lxml:item><lxml:item name="COLUMN4"><lxml:properties><lxml:param name="value" modifier="." preferred_child_total="1"></lxml:param></lxml:properties><lxml:caption>Header</lxml:caption></lxml:item><lxml:item name="COLUMN5"><lxml:properties><lxml:param name="value" modifier="." preferred_child_total="1"></lxml:param></lxml:properties><lxml:caption>Header</lxml:caption></lxml:item></lxml:grid></lxml:data><xsl:template name="std_grid_v2"><xsl:param name="name"></xsl:param><xsl:param name="listname"></xsl:param><xsl:param name="listname_fixed_col_field"></xsl:param><xsl:param name="sort_fixed_rows_with_body" select="true()"></xsl:param><xsl:param name="grid_hdr_properties" select="document('')/*/lxml:data/lxml:grid[@id='std_grid_v2_header']"></xsl:param><xsl:param name="grid_col_properties" select="document('')/*/lxml:data/lxml:grid[@id='std_grid_v2']"></xsl:param><xsl:param name="show_header" select="true()"></xsl:param><xsl:param name="hide_header_if_empty" select="true()"></xsl:param><xsl:param name="hide_if" select="false()"></xsl:param><xsl:param name="even_row_class" select="'even_row'"></xsl:param><xsl:param name="odd_row_class" select="'odd_row'"></xsl:param><xsl:param name="formname" select="'LANSA'"></xsl:param><xsl:param name="pos_absolute"></xsl:param><xsl:param name="width"></xsl:param><xsl:param name="height"></xsl:param><xsl:param name="allowSort" select="true()"></xsl:param><xsl:param name="allowColResize" select="true()"></xsl:param><xsl:param name="rowHoverEffect" select="false()"></xsl:param><xsl:param name="selectableRows" select="false()"></xsl:param><xsl:param name="onRowClickJS"></xsl:param><xsl:if test="not($hide_if) or $lweb_design_mode"><xsl:variable name="the_list" select="document('')/*/lxml:data/lxml:list[@name=$listname] | key('list', $listname)"></xsl:variable><xsl:variable name="unique_prefix"><xsl:value-of select="$formname"></xsl:value-of>_<xsl:value-of select="$name"></xsl:value-of></xsl:variable><script type="text/javascript"><xsl:text disable-output-escaping="yes">//&lt;![CDATA[</xsl:text>
	stdGrid_HideCols('.std_grid#<xsl:value-of select="$unique_prefix"></xsl:value-of> ', [<xsl:text></xsl:text><xsl:for-each select="key('tsmllist', $listname)/tsml:list-entries/tsml:entry/tsml:column[tsml:mode = 'hidden']"><xsl:text></xsl:text>'td.<xsl:value-of select="translate(@name, $nmtoken_invalid_chars, $nmtoken_replacement_chars)"></xsl:value-of>', 'th.<xsl:value-of select="translate(@name, $nmtoken_invalid_chars, $nmtoken_replacement_chars)"></xsl:value-of>', <xsl:text></xsl:text></xsl:for-each><xsl:text>null]);</xsl:text><xsl:text disable-output-escaping="yes">//]]&gt;</xsl:text></script><xsl:if test="not($lweb_design_mode)"><input type="hidden" name="{$the_list/@name}.." value="{count($the_list/lxml:list-entries/lxml:entry[1])}" /></xsl:if><div style="padding:3px;" id="{$unique_prefix}_wrap" class="std_grid_wrapper"><xsl:if test="$pos_absolute or $height or $width"><xsl:attribute name="style"><xsl:call-template name="make_size_and_pos_style_v2.private"><xsl:with-param name="caller_name" select="'std_grid_v2.xsl'"></xsl:with-param><xsl:with-param name="pos_absolute" select="$pos_absolute"></xsl:with-param><xsl:with-param name="height" select="$height"></xsl:with-param><xsl:with-param name="width" select="$width"></xsl:with-param></xsl:call-template></xsl:attribute></xsl:if><table id="{$unique_prefix}" class="std_grid ui-widget" cellspacing="0"><xsl:if test="$show_header and (not($hide_header_if_empty) or boolean($the_list/lxml:list-entries/lxml:entry[1]))"><thead><tr class="ui-widget-header"><xsl:for-each select="$the_list/lxml:list-header/lxml:header[@name=$listname_fixed_col_field]"><xsl:variable name="column_tsml" select="key('tsmlcolumn', concat($listname,'_',@name))"></xsl:variable><xsl:variable name="grid_hdr_prop" select="$grid_hdr_properties[@name=$listname]/lxml:item[current()/@name=@name]"></xsl:variable><th class="{translate(@name, $nmtoken_invalid_chars, $nmtoken_replacement_chars)}"><xsl:attribute name="__decimalseparator"><xsl:value-of select="$column_tsml/tsml:format/tsml:decimal-separator"></xsl:value-of></xsl:attribute><xsl:attribute name="__formattype"><xsl:value-of select="$column_tsml/tsml:format/tsml:type"></xsl:value-of></xsl:attribute><xsl:attribute name="__mode"><xsl:value-of select="$column_tsml/tsml:mode"></xsl:value-of></xsl:attribute><xsl:attribute name="__allowsort"><xsl:value-of select="not($grid_hdr_prop/@no_sort='true')"></xsl:value-of></xsl:attribute><div class="std_grid_cell_sizer"><xsl:if test="boolean($lweb_design_mode)"><xsl:attribute name="class">hidden__</xsl:attribute></xsl:if><xsl:comment>.</xsl:comment><xsl:comment /></div></th></xsl:for-each><xsl:for-each select="$the_list/lxml:list-header/lxml:header[@name!=$listname_fixed_col_field]"><xsl:variable name="column_tsml" select="key('tsmlcolumn', concat($listname,'_',@name))"></xsl:variable><xsl:if test="not($column_tsml/tsml:mode = 'private')"><xsl:variable name="grid_hdr_prop" select="$grid_hdr_properties[@name=$listname]/lxml:item[current()/@name=@name]"></xsl:variable><xsl:variable name="tsml_format_class"><xsl:call-template name="css_class_from_tsml_format.private"><xsl:with-param name="format" select="$column_tsml/tsml:format"></xsl:with-param></xsl:call-template></xsl:variable><th><xsl:attribute name="class"><xsl:value-of select="concat($tsml_format_class, ' ', translate(@name, $nmtoken_invalid_chars, $nmtoken_replacement_chars), ' std_grid_sort_indicator')"></xsl:value-of></xsl:attribute><xsl:attribute name="__decimalseparator"><xsl:value-of select="$column_tsml/tsml:format/tsml:decimal-separator"></xsl:value-of></xsl:attribute><xsl:attribute name="__formattype"><xsl:value-of select="$column_tsml/tsml:format/tsml:type"></xsl:value-of></xsl:attribute><xsl:attribute name="__mode"><xsl:value-of select="$column_tsml/tsml:mode"></xsl:value-of></xsl:attribute><xsl:attribute name="__allowsort"><xsl:value-of select="not($grid_hdr_prop/@no_sort='true')"></xsl:value-of></xsl:attribute><xsl:choose><xsl:when test="$grid_hdr_prop/@custom='true'"><xsl:apply-templates select="$grid_hdr_prop" mode="std_grid.private.override"><xsl:with-param name="context" select="."></xsl:with-param><xsl:with-param name="index" select="count(preceding-sibling::lxml:header)+1"></xsl:with-param><xsl:with-param name="tsml_col" select="$column_tsml"></xsl:with-param><xsl:with-param name="tsml_col_mode" select="$column_tsml/tsml:mode"></xsl:with-param><xsl:with-param name="tsml_col_max_len" select="$column_tsml/tsml:format/tsml:max-length"></xsl:with-param><xsl:with-param name="tsml_col_display_len" select="$column_tsml/tsml:format/tsml:display-max-length"></xsl:with-param><xsl:with-param name="tsml_col_input_type"><xsl:if test="$column_tsml/tsml:format/tsml:non-display='true'"><xsl:text>password</xsl:text></xsl:if></xsl:with-param><xsl:with-param name="tsml_col_css_class" select="$tsml_format_class"></xsl:with-param><xsl:with-param name="headers" select="../lxml:header"></xsl:with-param><xsl:with-param name="columns" select="$the_list/lxml:list-entries/lxml:entry"></xsl:with-param></xsl:apply-templates></xsl:when><xsl:otherwise><xsl:for-each select="*"><xsl:value-of select="normalize-space(.)"></xsl:value-of><xsl:if test=". != '' and position() != last() and ./following-sibling::* != ''"><br /></xsl:if></xsl:for-each></xsl:otherwise></xsl:choose><div class="std_grid_cell_sizer"><xsl:if test="boolean($lweb_design_mode)"><xsl:attribute name="class">hidden__</xsl:attribute></xsl:if><xsl:comment>.</xsl:comment><xsl:comment /></div></th></xsl:if></xsl:for-each></tr></thead></xsl:if><tbody class="ui-widget-content"><xsl:for-each select="$the_list/lxml:list-entries/lxml:entry"><tr __oddrc="{$odd_row_class}" __evenrc="{$even_row_class}" data-rowNum="{position()}"><xsl:attribute name="class"><xsl:choose><xsl:when test="position() mod 2 = 0"><xsl:value-of select="$even_row_class"></xsl:value-of></xsl:when><xsl:otherwise><xsl:value-of select="$odd_row_class"></xsl:value-of></xsl:otherwise></xsl:choose></xsl:attribute><xsl:for-each select="lxml:column[@name=$listname_fixed_col_field]"><xsl:variable name="column_tsml" select="key('tsmlcolumn', concat($listname,'_',@name))"></xsl:variable><xsl:variable name="col_prop" select="$grid_col_properties[@name=$listname]/lxml:item[current()/@name=@name]"></xsl:variable><th class="row_header ui-widget-header" lansaval="{.}"><xsl:choose><xsl:when test="$col_prop/@custom='true'"><xsl:apply-templates select="$col_prop" mode="std_grid.private.override"><xsl:with-param name="context" select="."></xsl:with-param><xsl:with-param name="index" select="count(preceding-sibling::lxml:column)+1"></xsl:with-param><xsl:with-param name="tsml_col" select="$column_tsml"></xsl:with-param><xsl:with-param name="tsml_col_mode" select="$column_tsml/tsml:mode"></xsl:with-param><xsl:with-param name="tsml_col_max_len" select="$column_tsml/tsml:format/tsml:max-length"></xsl:with-param><xsl:with-param name="tsml_col_display_len" select="$column_tsml/tsml:format/tsml:display-max-length"></xsl:with-param><xsl:with-param name="tsml_col_input_type"><xsl:if test="$column_tsml/tsml:format/tsml:non-display='true'"><xsl:text>password</xsl:text></xsl:if></xsl:with-param><xsl:with-param name="tsml_col_css_class"><xsl:call-template name="css_class_from_tsml_format.private"><xsl:with-param name="format" select="$column_tsml/tsml:format"></xsl:with-param></xsl:call-template></xsl:with-param></xsl:apply-templates></xsl:when><xsl:otherwise><xsl:value-of select="."></xsl:value-of><xsl:if test="$column_tsml/tsml:mode!='output'"><input type="hidden" name="{@id}" value="{.}" /></xsl:if></xsl:otherwise></xsl:choose><xsl:comment /></th></xsl:for-each><xsl:for-each select="lxml:column[@name!=$listname_fixed_col_field]"><xsl:variable name="column_tsml" select="key('tsmlcolumn', concat($listname,'_',@name))"></xsl:variable><xsl:if test="not($column_tsml/tsml:mode = 'private')"><xsl:variable name="col_prop" select="$grid_col_properties[@name=$listname]/lxml:item[current()/@name=@name]"></xsl:variable><xsl:variable name="tsml_weblet" select="$column_tsml/tsml:use-weblets/tsml:use-weblet[@technology-service='LANSA:XHTML'] | $column_tsml/tsml:use-weblet"></xsl:variable><td class="{translate(@name, $nmtoken_invalid_chars, $nmtoken_replacement_chars)}" __cellvalue="{.}"><xsl:choose><xsl:when test="$col_prop/@custom='true'"><xsl:apply-templates select="$col_prop" mode="std_grid.private.override"><xsl:with-param name="context" select="."></xsl:with-param><xsl:with-param name="index" select="count(preceding-sibling::lxml:column)+1"></xsl:with-param><xsl:with-param name="tsml_col" select="$column_tsml"></xsl:with-param><xsl:with-param name="tsml_col_mode" select="$column_tsml/tsml:mode"></xsl:with-param><xsl:with-param name="tsml_col_max_len" select="$column_tsml/tsml:format/tsml:max-length"></xsl:with-param><xsl:with-param name="tsml_col_display_len" select="$column_tsml/tsml:format/tsml:display-max-length"></xsl:with-param><xsl:with-param name="tsml_col_input_type"><xsl:if test="$column_tsml/tsml:format/tsml:non-display='true'"><xsl:text>password</xsl:text></xsl:if></xsl:with-param><xsl:with-param name="tsml_col_css_class"><xsl:call-template name="css_class_from_tsml_format.private"><xsl:with-param name="format" select="$column_tsml/tsml:format"></xsl:with-param></xsl:call-template></xsl:with-param></xsl:apply-templates></xsl:when><xsl:when test="$tsml_weblet"><xsl:call-template name="std_grid_v2_column_weblet.private"><xsl:with-param name="name" select="$name"></xsl:with-param><xsl:with-param name="column_tsml" select="$column_tsml"></xsl:with-param><xsl:with-param name="weblet_name" select="$tsml_weblet/@name"></xsl:with-param><xsl:with-param name="formname" select="$formname"></xsl:with-param><xsl:with-param name="row_pos" select="position()"></xsl:with-param><xsl:with-param name="listname_fixed_col_field" select="$listname_fixed_col_field"></xsl:with-param><xsl:with-param name="col_prop" select="$col_prop"></xsl:with-param><xsl:with-param name="tsml_col_css_class"><xsl:call-template name="css_class_from_tsml_format.private"><xsl:with-param name="format" select="$column_tsml/tsml:format"></xsl:with-param></xsl:call-template></xsl:with-param></xsl:call-template></xsl:when><xsl:when test="not($column_tsml/tsml:mode!='output')"><div width="100%"><xsl:attribute name="class"><xsl:call-template name="css_class_from_tsml_format.private"><xsl:with-param name="format" select="$column_tsml/tsml:format"></xsl:with-param></xsl:call-template></xsl:attribute><xsl:value-of select="."></xsl:value-of><xsl:comment /></div></xsl:when><xsl:otherwise><xsl:variable name="column_tsmlformat" select="$column_tsml/tsml:format"></xsl:variable><input type="text" name="{@id}" id="{@id}" size="{$column_tsmlformat/tsml:display-max-length}" maxlength="{$column_tsmlformat/tsml:max-length}" value="{.}" onblur="stdOnBlur(event);" onfocus="stdOnFocus(event);"><xsl:attribute name="class"><xsl:call-template name="css_class_from_tsml_format.private"><xsl:with-param name="format" select="$column_tsml/tsml:format"></xsl:with-param></xsl:call-template></xsl:attribute><xsl:if test="tmsl_colformat/tsml:non-display='true'"><xsl:attribute name="type">password</xsl:attribute></xsl:if><xsl:if test="$col_prop/@readonly='true'"><xsl:attribute name="readonly">true</xsl:attribute></xsl:if><xsl:attribute name="__formattype"><xsl:value-of select="$column_tsmlformat/tsml:type"></xsl:value-of></xsl:attribute><xsl:attribute name="__keyboardshift"><xsl:value-of select="normalize-space($column_tsmlformat/tsml:keyboardshift)"></xsl:value-of></xsl:attribute><xsl:attribute name="__maxlength"><xsl:value-of select="$column_tsmlformat/tsml:max-length"></xsl:value-of></xsl:attribute><xsl:attribute name="__totaldigits"><xsl:value-of select="$column_tsmlformat/tsml:total-digits"></xsl:value-of></xsl:attribute><xsl:attribute name="__fractiondigits"><xsl:value-of select="$column_tsmlformat/tsml:fraction-digits"></xsl:value-of></xsl:attribute><xsl:attribute name="__decimalseparator"><xsl:value-of select="$column_tsmlformat/tsml:decimal-separator"></xsl:value-of></xsl:attribute><xsl:attribute name="onchange">return stdFieldOnChangeHandler(this);</xsl:attribute></input></xsl:otherwise></xsl:choose><xsl:comment /></td></xsl:if></xsl:for-each></tr></xsl:for-each></tbody></table></div><script type="text/javascript"><xsl:text disable-output-escaping="yes">//&lt;![CDATA[</xsl:text>
register_std_grid('<xsl:value-of select="$unique_prefix"></xsl:value-of>',{
	columns: <xsl:value-of select="count($the_list/lxml:list-header/lxml:header)"></xsl:value-of>,
	allowSort: <xsl:value-of select="$allowSort"></xsl:value-of>,
	allowColResize: <xsl:value-of select="$allowColResize"></xsl:value-of>,
	rowHeaderCol: '<xsl:value-of select="$listname_fixed_col_field"></xsl:value-of>',
	sortFixedRows: <xsl:value-of select="$sort_fixed_rows_with_body"></xsl:value-of>,
	hoverEffect: <xsl:value-of select="$rowHoverEffect"></xsl:value-of>,
	selectableRows: <xsl:value-of select="$selectableRows"></xsl:value-of><xsl:if test="$onRowClickJS != ''">, onRowClickJS: function(event, rowNum) {<xsl:value-of disable-output-escaping="yes" select="$onRowClickJS"></xsl:value-of>}</xsl:if>
	});
<xsl:text disable-output-escaping="yes">//]]&gt;</xsl:text></script></xsl:if></xsl:template><xsl:template name="std_grid_v2_column_weblet.private"><xsl:param name="name"></xsl:param><xsl:param name="column_tsml"></xsl:param><xsl:param name="weblet_name"></xsl:param><xsl:param name="tsml_col_css_class"></xsl:param><xsl:param name="formname"></xsl:param><xsl:param name="row_pos"></xsl:param><xsl:param name="listname_fixed_col_field"></xsl:param><xsl:param name="col_prop"></xsl:param><xsl:variable name="unique_prefix"><xsl:value-of select="$formname"></xsl:value-of><xsl:text>_</xsl:text><xsl:value-of select="$name"></xsl:value-of></xsl:variable><xsl:variable name="design_css_class"></xsl:variable><xsl:variable name="column_format" select="$column_tsml/tsml:format"></xsl:variable><xsl:variable name="tsml_col_input_type"><xsl:if test="$column_format/tsml:non-display='true'"><xsl:text>password</xsl:text></xsl:if></xsl:variable><xsl:variable name="read_only" select="$col_prop/@readonly='true'"></xsl:variable><xsl:choose><xsl:when test="$weblet_name='std_varchar.std_varchar'"><xsl:call-template name="std_varchar"><xsl:with-param name="name" select="@id"></xsl:with-param><xsl:with-param name="value" select="."></xsl:with-param><xsl:with-param name="display_mode" select="$column_tsml/tsml:mode"></xsl:with-param><xsl:with-param name="maxlength" select="$column_format/tsml:max-length"></xsl:with-param><xsl:with-param name="display_length" select="$column_format/tsml:display-max-length"></xsl:with-param><xsl:with-param name="type" select="$tsml_col_input_type"></xsl:with-param><xsl:with-param name="keyboard_shift" select="normalize-space($column_format/tsml:keyboardshift)"></xsl:with-param><xsl:with-param name="class" select="concat($tsml_col_css_class, $design_css_class)"></xsl:with-param><xsl:with-param name="read_only" select="$read_only"></xsl:with-param></xsl:call-template></xsl:when><xsl:when test="$weblet_name='std_char.std_char'"><xsl:call-template name="std_char"><xsl:with-param name="name" select="@id"></xsl:with-param><xsl:with-param name="value" select="."></xsl:with-param><xsl:with-param name="display_mode" select="$column_tsml/tsml:mode"></xsl:with-param><xsl:with-param name="maxlength" select="$column_format/tsml:max-length"></xsl:with-param><xsl:with-param name="display_length" select="$column_format/tsml:display-max-length"></xsl:with-param><xsl:with-param name="type" select="$tsml_col_input_type"></xsl:with-param><xsl:with-param name="keyboard_shift" select="normalize-space($column_format/tsml:keyboardshift)"></xsl:with-param><xsl:with-param name="class" select="concat($tsml_col_css_class, $design_css_class)"></xsl:with-param><xsl:with-param name="read_only" select="$read_only"></xsl:with-param></xsl:call-template></xsl:when><xsl:when test="$weblet_name='std_integer.std_integer'"><xsl:call-template name="std_integer"><xsl:with-param name="name" select="@id"></xsl:with-param><xsl:with-param name="value" select="."></xsl:with-param><xsl:with-param name="display_mode" select="$column_tsml/tsml:mode"></xsl:with-param><xsl:with-param name="size" select="$column_format/tsml:max-length"></xsl:with-param><xsl:with-param name="maxlength" select="$column_format/tsml:display-max-length"></xsl:with-param><xsl:with-param name="type" select="$tsml_col_input_type"></xsl:with-param><xsl:with-param name="class" select="concat($tsml_col_css_class, $design_css_class)"></xsl:with-param><xsl:with-param name="read_only" select="$read_only"></xsl:with-param></xsl:call-template></xsl:when><xsl:when test="$weblet_name='std_float.std_float'"><xsl:call-template name="std_float"><xsl:with-param name="name" select="@id"></xsl:with-param><xsl:with-param name="value" select="."></xsl:with-param><xsl:with-param name="display_mode" select="$column_tsml/tsml:mode"></xsl:with-param><xsl:with-param name="size" select="$column_format/tsml:max-length"></xsl:with-param><xsl:with-param name="maxlength" select="$column_format/tsml:display-max-length"></xsl:with-param><xsl:with-param name="type" select="$tsml_col_input_type"></xsl:with-param><xsl:with-param name="class" select="concat($tsml_col_css_class, $design_css_class)"></xsl:with-param><xsl:with-param name="read_only" select="$read_only"></xsl:with-param></xsl:call-template></xsl:when><xsl:when test="$weblet_name='std_date.std_date'"><xsl:call-template name="std_date"><xsl:with-param name="name" select="@id"></xsl:with-param><xsl:with-param name="value" select="."></xsl:with-param><xsl:with-param name="display_mode" select="$column_tsml/tsml:mode"></xsl:with-param><xsl:with-param name="formname" select="$formname"></xsl:with-param><xsl:with-param name="allow_sqlnull" select="$column_format/tsml:sql-nullable = 'true'"></xsl:with-param><xsl:with-param name="class" select="concat($tsml_col_css_class, $design_css_class)"></xsl:with-param><xsl:with-param name="read_only" select="$read_only"></xsl:with-param></xsl:call-template></xsl:when><xsl:when test="$weblet_name='std_datetime.std_datetime'"><xsl:call-template name="std_datetime"><xsl:with-param name="name" select="@id"></xsl:with-param><xsl:with-param name="value" select="."></xsl:with-param><xsl:with-param name="display_mode" select="$column_tsml/tsml:mode"></xsl:with-param><xsl:with-param name="size" select="$column_format/tsml:max-length"></xsl:with-param><xsl:with-param name="formname" select="$formname"></xsl:with-param><xsl:with-param name="display_in_utc" select="$column_format/tsml:display-utc = 'true'"></xsl:with-param><xsl:with-param name="allow_sqlnull" select="$column_format/tsml:sql-nullable = 'true'"></xsl:with-param><xsl:with-param name="class" select="concat($tsml_col_css_class, $design_css_class)"></xsl:with-param><xsl:with-param name="read_only" select="$read_only"></xsl:with-param></xsl:call-template></xsl:when><xsl:when test="$weblet_name='std_boolean.std_boolean'"><xsl:call-template name="std_boolean"><xsl:with-param name="name" select="@id"></xsl:with-param><xsl:with-param name="value" select="."></xsl:with-param><xsl:with-param name="display_mode" select="$column_tsml/tsml:mode"></xsl:with-param><xsl:with-param name="formname" select="$formname"></xsl:with-param><xsl:with-param name="class" select="concat($tsml_col_css_class, $design_css_class)"></xsl:with-param></xsl:call-template></xsl:when><xsl:when test="$weblet_name='std_time.std_time'"><xsl:call-template name="std_time"><xsl:with-param name="name" select="@id"></xsl:with-param><xsl:with-param name="value" select="."></xsl:with-param><xsl:with-param name="display_mode" select="$column_tsml/tsml:mode"></xsl:with-param><xsl:with-param name="formname" select="$formname"></xsl:with-param><xsl:with-param name="allow_sqlnull" select="$column_format/tsml:sql-nullable = 'true'"></xsl:with-param><xsl:with-param name="class" select="concat($tsml_col_css_class, $design_css_class)"></xsl:with-param><xsl:with-param name="read_only" select="$read_only"></xsl:with-param></xsl:call-template></xsl:when><xsl:when test="$weblet_name='std_datepicker.std_datepicker'"><xsl:call-template name="std_date"><xsl:with-param name="name" select="@id"></xsl:with-param><xsl:with-param name="value" select="."></xsl:with-param><xsl:with-param name="display_mode" select="$column_tsml/tsml:mode"></xsl:with-param><xsl:with-param name="formname" select="$formname"></xsl:with-param><xsl:with-param name="allow_sqlnull" select="$column_format/tsml:sql-nullable = 'true'"></xsl:with-param><xsl:with-param name="class" select="concat($tsml_col_css_class, $design_css_class)"></xsl:with-param><xsl:with-param name="read_only" select="$read_only"></xsl:with-param></xsl:call-template></xsl:when><xsl:when test="$weblet_name='std_datetimepicker.std_datetimepicker'"><xsl:call-template name="std_datetime"><xsl:with-param name="name" select="@id"></xsl:with-param><xsl:with-param name="value" select="."></xsl:with-param><xsl:with-param name="display_mode" select="$column_tsml/tsml:mode"></xsl:with-param><xsl:with-param name="size" select="$column_format/tsml:max-length"></xsl:with-param><xsl:with-param name="formname" select="$formname"></xsl:with-param><xsl:with-param name="display_in_utc" select="$column_format/tsml:display-utc = 'true'"></xsl:with-param><xsl:with-param name="allow_sqlnull" select="$column_format/tsml:sql-nullable = 'true'"></xsl:with-param><xsl:with-param name="class" select="concat($tsml_col_css_class, $design_css_class)"></xsl:with-param><xsl:with-param name="read_only" select="$read_only"></xsl:with-param></xsl:call-template></xsl:when><xsl:when test="$weblet_name='std_timepicker.std_timepicker'"><xsl:call-template name="std_time"><xsl:with-param name="name" select="@id"></xsl:with-param><xsl:with-param name="value" select="."></xsl:with-param><xsl:with-param name="display_mode" select="$column_tsml/tsml:mode"></xsl:with-param><xsl:with-param name="formname" select="$formname"></xsl:with-param><xsl:with-param name="allow_sqlnull" select="$column_format/tsml:sql-nullable = 'true'"></xsl:with-param><xsl:with-param name="class" select="concat($tsml_col_css_class, $design_css_class)"></xsl:with-param><xsl:with-param name="read_only" select="$read_only"></xsl:with-param></xsl:call-template></xsl:when></xsl:choose></xsl:template><xsl:template match="lxml:item[../@id='std_grid_v2']" mode="std_grid.private.override"><xsl:param name="context"></xsl:param><xsl:param name="index"></xsl:param><xsl:param name="tsml_col"></xsl:param><xsl:param name="tsml_col_mode"></xsl:param><xsl:param name="tsml_col_max_len"></xsl:param><xsl:param name="tsml_col_display_len"></xsl:param><xsl:param name="tsml_col_input_type"></xsl:param><xsl:param name="tsml_col_css_class"></xsl:param><xsl:param name="formname"></xsl:param><xsl:choose><xsl:when test="$index=1"><xsl:apply-templates select="$context" mode="_std_grid_v2_1.override"><xsl:with-param name="context" select="."></xsl:with-param><xsl:with-param name="index" select="$index"></xsl:with-param><xsl:with-param name="tsml_col" select="$tsml_col"></xsl:with-param><xsl:with-param name="tsml_col_mode" select="$tsml_col_mode"></xsl:with-param><xsl:with-param name="tsml_col_max_len" select="$tsml_col_max_len"></xsl:with-param><xsl:with-param name="tsml_col_display_len" select="$tsml_col_display_len"></xsl:with-param><xsl:with-param name="tsml_col_input_type" select="$tsml_col_input_type"></xsl:with-param><xsl:with-param name="tsml_col_css_class" select="$tsml_col_css_class"></xsl:with-param><xsl:with-param name="formname" select="$formname"></xsl:with-param><xsl:with-param name="cells" select="$context/../."></xsl:with-param></xsl:apply-templates></xsl:when></xsl:choose></xsl:template><xsl:template match="*" mode="_std_grid_v2_1.override"><xsl:param name="context"></xsl:param><xsl:param name="index"></xsl:param><xsl:param name="tsml_col"></xsl:param><xsl:param name="tsml_col_mode"></xsl:param><xsl:param name="tsml_col_max_len"></xsl:param><xsl:param name="tsml_col_display_len"></xsl:param><xsl:param name="tsml_col_input_type"></xsl:param><xsl:param name="tsml_col_css_class"></xsl:param><xsl:param name="formname"></xsl:param><xsl:param name="cells"></xsl:param></xsl:template><xsl:template match="lxml:item[../@id='std_grid_v2_header']" mode="std_grid.private.override"><xsl:param name="context"></xsl:param><xsl:param name="index"></xsl:param><xsl:param name="tsml_col"></xsl:param><xsl:param name="tsml_col_mode"></xsl:param><xsl:param name="tsml_col_max_len"></xsl:param><xsl:param name="tsml_col_display_len"></xsl:param><xsl:param name="tsml_col_input_type"></xsl:param><xsl:param name="tsml_col_css_class"></xsl:param><xsl:param name="formname"></xsl:param><xsl:param name="headers"></xsl:param><xsl:param name="columns"></xsl:param><xsl:choose><xsl:when test="$index=1"><xsl:apply-templates select="$context" mode="_std_grid_v2_header_1.override"><xsl:with-param name="context" select="."></xsl:with-param><xsl:with-param name="index" select="$index"></xsl:with-param><xsl:with-param name="tsml_col" select="$tsml_col"></xsl:with-param><xsl:with-param name="tsml_col_mode" select="$tsml_col_mode"></xsl:with-param><xsl:with-param name="tsml_col_max_len" select="$tsml_col_max_len"></xsl:with-param><xsl:with-param name="tsml_col_display_len" select="$tsml_col_display_len"></xsl:with-param><xsl:with-param name="tsml_col_input_type" select="$tsml_col_input_type"></xsl:with-param><xsl:with-param name="tsml_col_css_class" select="$tsml_col_css_class"></xsl:with-param><xsl:with-param name="formname" select="$formname"></xsl:with-param><xsl:with-param name="headers" select="$headers"></xsl:with-param><xsl:with-param name="columns" select="$columns"></xsl:with-param></xsl:apply-templates></xsl:when></xsl:choose></xsl:template><xsl:template match="*" mode="_std_grid_v2_header_1.override"><xsl:param name="context"></xsl:param><xsl:param name="index"></xsl:param><xsl:param name="tsml_col"></xsl:param><xsl:param name="tsml_col_mode"></xsl:param><xsl:param name="tsml_col_max_len"></xsl:param><xsl:param name="tsml_col_display_len"></xsl:param><xsl:param name="tsml_col_input_type"></xsl:param><xsl:param name="tsml_col_css_class"></xsl:param><xsl:param name="formname"></xsl:param><xsl:param name="headers"></xsl:param><xsl:param name="columns"></xsl:param></xsl:template></xsl:transform>