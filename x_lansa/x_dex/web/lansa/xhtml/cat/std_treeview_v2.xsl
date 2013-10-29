<?xml version="1.0" encoding="UTF-8"?><!--(c) 2011, 2013 LANSA--><!--Standard jQuery UI based tree--><!--$Workfile:: std_treeview_v2.xsl $--><!--$UTCDate:: 2013-01-03 00:26:31Z $--><!--$Revision:: 11 $--><xsl:transform version="1.0" exclude-result-prefixes="lxml wd" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design" xmlns="http://www.w3.org/1999/xhtml"><xsl:import href="std_types.xsl"></xsl:import><xsl:import href="std_util.xsl"></xsl:import><xsl:import href="std_keys.xsl"></xsl:import><xsl:output method="xml" omit-xml-declaration="yes" encoding="UTF-8" indent="yes"></xsl:output><xsl:template name="std_treeview_v2"><xsl:param name="name" select="concat('std_treeview', generate-id())"></xsl:param><xsl:param name="listname"></xsl:param><xsl:param name="listtype" select="'unlevelled'"></xsl:param><xsl:param name="use_jQueryUI_theme" select="true()"></xsl:param><xsl:param name="jQueryUI_node_icon" select="'triangle'"></xsl:param><xsl:param name="folder_closed_image"></xsl:param><xsl:param name="folder_open_image"></xsl:param><xsl:param name="item_image"></xsl:param><xsl:param name="node_text_click" select="'both'"></xsl:param><xsl:param name="key_fields"></xsl:param><xsl:param name="display_fields"></xsl:param><xsl:param name="list_caption_field"></xsl:param><xsl:param name="list_image_field"></xsl:param><xsl:param name="list_open_image_field"></xsl:param><xsl:param name="list_id_field" select="$list_caption_field"></xsl:param><xsl:param name="list_onselect_wamname_field"></xsl:param><xsl:param name="list_onselect_wrname_field"></xsl:param><xsl:param name="list_haschildren_field"></xsl:param><xsl:param name="list_is_selected_field"></xsl:param><xsl:param name="list_is_expanded_field"></xsl:param><xsl:param name="list_parent_id_field"></xsl:param><xsl:param name="onselect_wamname" select="$lweb_WAMName"></xsl:param><xsl:param name="onselect_wrname"></xsl:param><xsl:param name="onexpand_wamname" select="$lweb_WAMName"></xsl:param><xsl:param name="onexpand_wrname"></xsl:param><xsl:param name="onsubmit_id_field"></xsl:param><xsl:param name="onsubmit_level_field"></xsl:param><xsl:param name="onsubmit_ancestor_list"></xsl:param><xsl:param name="target_window_name"></xsl:param><xsl:param name="pos_absolute"></xsl:param><xsl:param name="width"></xsl:param><xsl:param name="height"></xsl:param><ul id="{$name}" style="white-space: nowrap;"><xsl:attribute name="style"><xsl:text>white-space:nowrap;overflow:auto;</xsl:text><xsl:call-template name="make_size_and_pos_style_v2.private"><xsl:with-param name="caller_name" select="'std_treeview_v2.xsl'"></xsl:with-param><xsl:with-param name="pos_absolute" select="$pos_absolute"></xsl:with-param><xsl:with-param name="width" select="$width"></xsl:with-param><xsl:with-param name="height" select="$height"></xsl:with-param></xsl:call-template></xsl:attribute><xsl:comment /></ul><xsl:variable name="headers" select="key('list',$listname)/lxml:list-header[1]/lxml:header"></xsl:variable><script type="text/javascript"><xsl:text disable-output-escaping="yes">//&lt;![CDATA[
</xsl:text>Lstd.Weblets.registerWeblet('<xsl:value-of select="$name"></xsl:value-of>', {
	init: function(id, data) {Lstd.Weblets.stdTreeview.init(id, data);}
	}, {
		useJQueryUITheme: <xsl:value-of select="$use_jQueryUI_theme"></xsl:value-of>,
		jQueryUINodeIcon: "<xsl:value-of select="$jQueryUI_node_icon"></xsl:value-of>".toLowerCase(),
		nodeTextOnClick: "<xsl:value-of select="$node_text_click"></xsl:value-of>".toLowerCase(),
		listName: "<xsl:value-of select="$listname"></xsl:value-of>",
		listType: "<xsl:value-of select="$listtype"></xsl:value-of>",
		displayFields: "<xsl:value-of select="$display_fields"></xsl:value-of>",
		keyFields: "<xsl:value-of select="$key_fields"></xsl:value-of>",
		target: "<xsl:value-of select="$target_window_name"></xsl:value-of>",
		onExpandWAMName: "<xsl:value-of select="$onexpand_wamname"></xsl:value-of>",
		onExpandWRName: "<xsl:value-of select="$onexpand_wrname"></xsl:value-of>",
		onSelectWAMName: "<xsl:value-of select="$onselect_wamname"></xsl:value-of>",
		onSelectWRName: "<xsl:value-of select="$onselect_wrname"></xsl:value-of>",
		onSubmitAncestorList: "<xsl:value-of select="$onsubmit_ancestor_list"></xsl:value-of>",
		onSubmitIdField: "<xsl:value-of select="$onsubmit_id_field"></xsl:value-of>",
		onSubmitLevelField: "<xsl:value-of select="$onsubmit_level_field"></xsl:value-of>",
		list_caption_field: "<xsl:value-of select="$list_caption_field"></xsl:value-of>",
		list_image_field: "<xsl:value-of select="$list_image_field"></xsl:value-of>",
		list_open_image_field: "<xsl:value-of select="$list_open_image_field"></xsl:value-of>",
		list_id_field: "<xsl:value-of select="$list_id_field"></xsl:value-of>",
		list_onselect_wamname_field: "<xsl:value-of select="$list_onselect_wamname_field"></xsl:value-of>",
		list_onselect_wrname_field: "<xsl:value-of select="$list_onselect_wrname_field"></xsl:value-of>",
		list_haschildren_field: "<xsl:value-of select="$list_haschildren_field"></xsl:value-of>",
		list_is_selected_field: "<xsl:value-of select="$list_is_selected_field"></xsl:value-of>",
		list_is_expanded_field: "<xsl:value-of select="$list_is_expanded_field"></xsl:value-of>",
		list_parent_id_field: "<xsl:value-of select="$list_parent_id_field"></xsl:value-of>",
		nodeClosedImage: "<xsl:value-of select="$folder_closed_image"></xsl:value-of>",
		nodeOpenImage: "<xsl:value-of select="$folder_open_image"></xsl:value-of>",
		itemImage: "<xsl:value-of select="$item_image"></xsl:value-of>",
<xsl:choose><xsl:when test="key('jsonlist',$listname)">
		list: Lstd.Json.factory(<xsl:value-of select="key('jsonlist',$listname)"></xsl:value-of>)
	</xsl:when><xsl:otherwise>
		list: Lstd.Json.factory(<xsl:call-template name="std_list_to_json.private"><xsl:with-param name="listname" select="$listname"></xsl:with-param></xsl:call-template>)
	</xsl:otherwise></xsl:choose>
	});
	<xsl:text disable-output-escaping="yes">//]]&gt;</xsl:text></script></xsl:template></xsl:transform>