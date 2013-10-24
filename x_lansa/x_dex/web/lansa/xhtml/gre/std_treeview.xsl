<?xml version="1.0" encoding="UTF-8"?><!--(c) 2003, 2012 LANSA--><!--XHTML Standard treeview control IE only--><!--$Workfile:: std_treeview.xsl $--><!--$UTCDate:: 2013-01-03 00:26:31Z $--><!--$Revision:: 19 $--><xsl:transform version="1.0" exclude-result-prefixes="lxml wd" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:lxml="http://www.lansa.com/2002/XML/Runtime-Data" xmlns:mytree="uri:std_treeview" xmlns:wd="http://www.lansa.com/2002/XSL/Weblet-Design" xmlns="http://www.w3.org/1999/xhtml"><xsl:import href="std_types.xsl"></xsl:import><xsl:import href="std_variables.xsl"></xsl:import><xsl:import href="std_util.xsl"></xsl:import><xsl:import href="std_keys.xsl"></xsl:import><xsl:output method="xml" omit-xml-declaration="yes" encoding="UTF-8" indent="yes"></xsl:output><xsl:template name="std_treeview"><xsl:param name="name" select="concat('oTree', ancestor-or-self::lxml:list/@name, position())"></xsl:param><xsl:param name="formname" select="'LANSA'"></xsl:param><xsl:param name="xmlid" select="concat('xmlTree_', $name)"></xsl:param><xsl:param name="xmltypeid" select="concat('xmlTreeType_', $name)"></xsl:param><xsl:param name="folder_closed_image" select="'folder.gif'"></xsl:param><xsl:param name="folder_open_image" select="'folderopen.gif'"></xsl:param><xsl:param name="item_image" select="'ball_grn.gif'"></xsl:param><xsl:param name="listname"></xsl:param><xsl:param name="list_caption_field"></xsl:param><xsl:param name="list_type_field"></xsl:param><xsl:param name="list_image_field"></xsl:param><xsl:param name="list_open_image_field"></xsl:param><xsl:param name="list_tag_field" select="$list_caption_field"></xsl:param><xsl:param name="list_onselect_wrname_field"></xsl:param><xsl:param name="list_haschildren_field" select="'STD_CODES'"></xsl:param><xsl:param name="list_subitem_group_field" select="'STD_LEVEL'"></xsl:param><xsl:param name="list_is_selected_field"></xsl:param><xsl:param name="list_is_expanded_field"></xsl:param><xsl:param name="list_parent_id_field"></xsl:param><xsl:param name="list_style_field"></xsl:param><xsl:param name="list_selected_style_field"></xsl:param><xsl:param name="onexpand_wamname" select="$lweb_WAMName"></xsl:param><xsl:param name="onexpand_wrname" select="$lweb_context/lxml:webroutine"></xsl:param><xsl:param name="listname_of_parents_of_selected"></xsl:param><xsl:param name="pos_absolute_design"></xsl:param><xsl:param name="width_design"></xsl:param><xsl:param name="height_design"></xsl:param><xsl:param name="class" select="'std_treeview'"></xsl:param><xsl:param name="bg_color"></xsl:param><xsl:param name="default_style"></xsl:param><xsl:param name="selected_style"></xsl:param><xml id="{$xmlid}"><xsl:call-template name="std_treeview-xml.private"><xsl:with-param name="listname" select="$listname"></xsl:with-param><xsl:with-param name="list_caption_field" select="$list_caption_field"></xsl:with-param><xsl:with-param name="list_image_field" select="$list_image_field"></xsl:with-param><xsl:with-param name="list_open_image_field" select="$list_open_image_field"></xsl:with-param><xsl:with-param name="list_tag_field" select="$list_tag_field"></xsl:with-param><xsl:with-param name="list_haschildren_field" select="$list_haschildren_field"></xsl:with-param><xsl:with-param name="list_subitem_group_field" select="$list_subitem_group_field"></xsl:with-param><xsl:with-param name="list_onselect_wrname_field" select="$list_onselect_wrname_field"></xsl:with-param><xsl:with-param name="list_is_selected_field" select="$list_is_selected_field"></xsl:with-param><xsl:with-param name="list_is_expanded_field" select="$list_is_expanded_field"></xsl:with-param><xsl:with-param name="list_parent_id_field" select="$list_parent_id_field"></xsl:with-param><xsl:with-param name="list_style_field" select="$list_style_field"></xsl:with-param><xsl:with-param name="list_selected_style_field" select="$list_selected_style_field"></xsl:with-param><xsl:with-param name="folder_closed_image" select="$folder_closed_image"></xsl:with-param><xsl:with-param name="folder_open_image" select="$folder_open_image"></xsl:with-param><xsl:with-param name="item_image" select="$item_image"></xsl:with-param></xsl:call-template></xml><script type="text/javascript"><xsl:text disable-output-escaping="yes">//&lt;![CDATA[
			</xsl:text>
{
var oXML = document.all.<xsl:value-of select="$xmlid"></xsl:value-of>;
if( oXML != null )
{
var xmlList = oXML.XMLDocument.selectNodes("/TREENODES//TREENODE[@_IS_SELECTED='true' or @_IS_SELECTED='freeze']");
if( xmlList != null )
{
var length = xmlList.length;
<xsl:text disable-output-escaping="yes">for(var index = 0; index &lt; length; index++) </xsl:text>
{
var elem = xmlList[index];
if( elem != null )
{
var parentNode = elem.parentNode;
<xsl:text disable-output-escaping="yes">while(parentNode != null &amp;&amp; parentNode.nodeName!="TREENODES") </xsl:text>
{
parentNode.setAttribute("EXPANDED", "true");
var imageUrl = parentNode.getAttribute("IMAGEURL");
if( imageUrl == null || imageUrl == "" )
{
parentNode.setAttribute("IMAGEURL", "<xsl:value-of select="$lweb_images_path"></xsl:value-of>/<xsl:value-of select="$folder_open_image"></xsl:value-of>");
}
else
{
parentNode.setAttribute("_PREV_IMAGEURL", imageUrl);
parentNode.setAttribute("IMAGEURL", parentNode.getAttribute("OPEN_IMAGEURL"));
}
parentNode = parentNode.parentNode;
}
}
}
}
}
}
			<xsl:text disable-output-escaping="yes">//]]&gt;</xsl:text></script><xsl:if test="$listname_of_parents_of_selected != ''"><xml id="{$xmlid}_ancestors"><ancestors><xsl:for-each select="/lxml:data/lxml:lists/lxml:list[@name=$listname_of_parents_of_selected]/lxml:list-entries/lxml:entry"><ancestor level="{lxml:column[@name=$list_subitem_group_field]}" imageurl="{$lweb_images_path}/{lxml:column[@name=$list_image_field]}"><xsl:if test="$list_image_field = ''"><xsl:attribute name="IMAGEURL"><xsl:value-of select="$lweb_images_path"></xsl:value-of><xsl:text>/</xsl:text><xsl:value-of select="$folder_open_image"></xsl:value-of></xsl:attribute></xsl:if></ancestor></xsl:for-each></ancestors></xml></xsl:if><xml id="{$xmltypeid}"><xsl:call-template name="std_treeview-xml-type.private"></xsl:call-template></xml><xsl:if test="not($lweb_design_mode) and (not(/lxml:data/lxml:fields/lxml:field[@name=$list_subitem_group_field]) or key('field-value', $list_subitem_group_field) &lt;= 1)"><xsl:element name="html"><xsl:attribute name="mytree:_" namespace="uri:std_treeview"></xsl:attribute><xsl:processing-instruction name="import">namespace="mytree" implementation="<xsl:value-of select="$lweb_images_path"></xsl:value-of>/htc/treeview.htc"</xsl:processing-instruction><script type="text/javascript"><xsl:text disable-output-escaping="yes">
		//&lt;![CDATA[
		</xsl:text>
		function <xsl:value-of select="$name"></xsl:value-of>_insertTagsHidden(Form, node, tagFieldNameAlias)
		{
			if( node != null )
			{
				var tagValue;
				<xsl:for-each select="/lxml:data/lxml:lists/lxml:list[@name=$listname]/lxml:list-header/lxml:header[starts-with(@name, $list_tag_field)]">
				tagValue = node.getAttribute("_TAG_VALUE<xsl:value-of select="position()"></xsl:value-of>");
				if( tagValue != null )
				{
					<xsl:if test="position() = 1">
					if( tagFieldNameAlias != null <xsl:text disable-output-escaping="yes">&amp;&amp;</xsl:text> tagFieldNameAlias != "" )
					{
						InsertHidden(Form, tagFieldNameAlias, tagValue);
					}
					</xsl:if>
					InsertHidden(Form, "<xsl:value-of select="@name"></xsl:value-of>", tagValue);
				}
				</xsl:for-each>
				var groupValue = node.getAttribute("_GROUP_VALUE");
				if( groupValue != null )
				{
				InsertHidden(Form, "<xsl:value-of select="$list_subitem_group_field"></xsl:value-of>", groupValue);
				}
			}
		}
		function <xsl:value-of select="$name"></xsl:value-of>_insertHiddenList(Form, node, parentArr)
		{<xsl:text></xsl:text><xsl:if test="$listname_of_parents_of_selected != ''"><xsl:text></xsl:text>
			var listColumnNameArr = new Array();
			var listValueArrOfArr = new Array();<xsl:text></xsl:text>
			if( node != null <xsl:text disable-output-escaping="yes">&amp;&amp;</xsl:text> parentArr != null )
			{
			<xsl:for-each select="/lxml:data/lxml:lists/lxml:list[@name=$listname_of_parents_of_selected]/lxml:list-header/lxml:header[starts-with(@name, $list_tag_field)]"><xsl:text></xsl:text>listColumnNameArr.push("<xsl:value-of select="@name"></xsl:value-of>");<xsl:text></xsl:text></xsl:for-each>
				for(index = 0; index <xsl:text disable-output-escaping="yes">&lt;</xsl:text> parentArr.length; index++)
				{
				var rowArr = new Array();
				var item = parentArr[index];<xsl:text></xsl:text><xsl:for-each select="/lxml:data/lxml:lists/lxml:list[@name=$listname_of_parents_of_selected]/lxml:list-header/lxml:header[starts-with(@name, $list_tag_field)]">
				rowArr.push(item.<xsl:value-of select="@name"></xsl:value-of>);<xsl:text></xsl:text></xsl:for-each>
				listValueArrOfArr.push(rowArr);
				}
			}
			stdInsertHiddenList(Form, "<xsl:value-of select="$listname_of_parents_of_selected"></xsl:value-of>", listColumnNameArr, listValueArrOfArr);<xsl:text></xsl:text></xsl:if>
		}
		function <xsl:value-of select="$name"></xsl:value-of>_onexpand()
		{
			if( document.all.<xsl:value-of select="$name"></xsl:value-of> == null || document.all.<xsl:value-of select="$name"></xsl:value-of>.disabled )
			{
				return;
			}
			<xsl:call-template name="std_treeview_onexpand.private"><xsl:with-param name="formname" select="$formname"></xsl:with-param><xsl:with-param name="name" select="$name"></xsl:with-param><xsl:with-param name="onexpand_wamname" select="$onexpand_wamname"></xsl:with-param><xsl:with-param name="onexpand_wrname" select="$onexpand_wrname"></xsl:with-param></xsl:call-template>
		}
		function <xsl:value-of select="$name"></xsl:value-of>_oncollapse()
		{
			var node = <xsl:value-of select="$name"></xsl:value-of>.getTreeNode(window.event.treeNodeIndex);
			if( node == null )
			{
				return;
			}
			var imageUrl = node.getAttribute("_PREV_IMAGEURL");
			if( imageUrl != null )
			{
				var prevImageUrl = node.getAttribute("IMAGEURL");
				node.setAttribute("IMAGEURL", imageUrl);
				node.setAttribute("_PREV_IMAGEURL", prevImageUrl);
			}
		}
		function <xsl:value-of select="$name"></xsl:value-of>_fillParentArray(treeNode)
		{
			var parentArr = null;
			<xsl:if test="$listname_of_parents_of_selected != ''">
			parentArr = new Array();
			var parentNode = treeNode.getParent();
			while( parentNode != null )
			{
				var listItem = new Object;
				<xsl:for-each select="/lxml:data/lxml:lists/lxml:list[@name=$listname_of_parents_of_selected]/lxml:list-header/lxml:header[starts-with(@name, $list_tag_field)]">
				var tagValue = parentNode.getAttribute("_TAG_VALUE<xsl:value-of select="position()"></xsl:value-of>");
				if( tagValue != null )
				{
				listItem.<xsl:value-of select="@name"></xsl:value-of> = tagValue;
				}
				</xsl:for-each>
				parentArr.push(listItem);
				parentNode = parentNode.getParent();
			}
			</xsl:if>
			return parentArr.reverse();
		}
		function <xsl:value-of select="$name"></xsl:value-of>_removeAllNodes(oTreeview)
		{
				<xsl:call-template name="std_treeview_removeChildren.private"><xsl:with-param name="name" select="$name"></xsl:with-param><xsl:with-param name="parent" select="'oTreeview'"></xsl:with-param></xsl:call-template>
		}
		function <xsl:value-of select="$name"></xsl:value-of>_freezeSelectEvent(bFreeze)
		{
			document.all.<xsl:value-of select="$name"></xsl:value-of>.setAttribute("__x_freezeSelect", bFreeze);
		}
		function <xsl:value-of select="$name"></xsl:value-of>_selectNode(oChildArr)
		{
			if( oChildArr == null )
			{
				return false;
			}
			var length = oChildArr.length;
			for(var index = 0; index <xsl:text disable-output-escaping="yes">&lt;</xsl:text> length; index++)
			{
				var node = oChildArr[index];
				var isSelected = node.getAttribute("_IS_SELECTED");
				if( isSelected != null <xsl:text disable-output-escaping="yes">&amp;&amp;</xsl:text> isSelected == 'true'
					|| isSelected == 'freeze' )
				{
					if( isSelected == 'freeze' )
					{
						<xsl:value-of select="$name"></xsl:value-of>_freezeSelectEvent(true);
					}
					document.all.<xsl:value-of select="$name"></xsl:value-of>.selectedNodeIndex = node.getNodeIndex();
					if( isSelected == 'freeze' )
					{
						<xsl:value-of select="$name"></xsl:value-of>_freezeSelectEvent(false);
					}
					return true;
				}
				else
				{
					if( node.getAttribute("EXPANDED") == true )
					{
						if( <xsl:value-of select="$name"></xsl:value-of>_selectNode(node.getChildren()) )
						{
							return true;
						}
					}
				}
			}
			return false;
		}
		function <xsl:value-of select="$name"></xsl:value-of>_expand_onload(oFrame)
		{
			oFrame.releaseCapture();
			if( window.name == "<xsl:value-of select="$name"></xsl:value-of>_hidden" )
			{
				return;
			}
			var parentNode = oFrame.getAttribute("_parentNode");
			if( parentNode == null )
			{
				var prevVisibility = "inherit";//document.all.<xsl:value-of select="$name"></xsl:value-of>.style.visibility;
				document.all.<xsl:value-of select="$name"></xsl:value-of>.style.visibility = "hidden";
				<xsl:value-of select="$name"></xsl:value-of>_selectNode(document.all.<xsl:value-of select="$name"></xsl:value-of>.getChildren());
				setTimeout("document.all.<xsl:value-of select="$name"></xsl:value-of>.style.visibility = '" + prevVisibility + "'", 0);
				return;
			}
			else
			{
				oFrame.removeAttribute("_parentNode");
			}
			var doc = document.frames("<xsl:value-of select="$name"></xsl:value-of>_hidden").document;
			var oXML = doc.all.<xsl:value-of select="$xmlid"></xsl:value-of>;
			if( oXML == null )
			{
				return;
			}
			var xmlList = oXML.XMLDocument.selectNodes("/TREENODES/TREENODE");
			if( xmlList != null )
			{
				<xsl:call-template name="std_treeview_removeChildren.private"><xsl:with-param name="name" select="$name"></xsl:with-param><xsl:with-param name="parent" select="'parentNode'"></xsl:with-param></xsl:call-template>
				for(index = 0; index <xsl:text disable-output-escaping="yes">&lt;</xsl:text> xmlList.length; index++)
				{
				var xmlElem = xmlList.item(index);
				var attrArr = xmlElem.attributes;
				var node = document.all.<xsl:value-of select="$name"></xsl:value-of>.createTreeNode();
				for(count = 0; count <xsl:text disable-output-escaping="yes">&lt;</xsl:text> attrArr.length; count++)
				{
					var attrNode = attrArr.item(count);
					node.setAttribute(attrNode.nodeName, attrNode.nodeValue);
				}
				// node.setAttribute("EXPANDABLE", "checkOnce");
				parentNode.add(node);
				}
				if( !parentNode.getAttribute("expanded") )
				{
				parentNode.setAttribute("expanded", true);
				}
				var prevVisibility = "inherit";//document.all.<xsl:value-of select="$name"></xsl:value-of>.style.visibility;
				document.all.<xsl:value-of select="$name"></xsl:value-of>.style.visibility = "hidden";
				setTimeout("<xsl:value-of select="$name"></xsl:value-of>_selectNode(document.all.<xsl:value-of select="$name"></xsl:value-of>.getChildren());document.all.<xsl:value-of select="$name"></xsl:value-of>.style.visibility = '" + prevVisibility + "'", 0);
				if( xmlList.length <xsl:text disable-output-escaping="yes">&gt;</xsl:text> 0 )
				{
					var oAncestorXML = doc.all.<xsl:value-of select="$xmlid"></xsl:value-of>_ancestors;
					if( oAncestorXML != null )
					{
						xmlList = oAncestorXML.XMLDocument.selectNodes("/ancestors/ancestor");
						if( xmlList != null )
						{
							for(index = xmlList.length-1; index <xsl:text disable-output-escaping="yes">&gt;=</xsl:text> 0; index--)
							{
							var xmlElem = xmlList.item(index);
							var image = xmlElem.getAttribute("IMAGEURL");
							if( parentNode != null )
							{
								<xsl:value-of select="$name"></xsl:value-of>_replace_image(parentNode, image)
								parentNode = parentNode.getParent();
							}
							}
						}
					}
					<xsl:if test="$listname_of_parents_of_selected = '' or $list_image_field = ''">
					if( oAncestorXML == null || xmlList == null || xmlList.length <xsl:text disable-output-escaping="yes">&lt;=</xsl:text> 0 )
					{
						<xsl:value-of select="$name"></xsl:value-of>_replace_image(parentNode, "<xsl:value-of select="$lweb_images_path"></xsl:value-of>/<xsl:value-of select="$folder_open_image"></xsl:value-of>");
					}
					</xsl:if>
				}
			}
doc.body.removeNode(true);
		}
		function <xsl:value-of select="$name"></xsl:value-of>_replace_image(node, image)

		{
			if( node != null <xsl:text disable-output-escaping="yes">&amp;&amp;</xsl:text> image != null <xsl:text disable-output-escaping="yes">&amp;&amp;</xsl:text> image != "" )
			{
				var prevAttr = node.getAttribute("IMAGEURL");
				if( prevAttr != null <xsl:text disable-output-escaping="yes">&amp;&amp;</xsl:text> node.getAttribute("_PREV_IMAGEURL") == null )
				{
					node.setAttribute("_PREV_IMAGEURL", prevAttr);
				}
				node.setAttribute("IMAGEURL", image);
			}
		}
		function <xsl:value-of select="$name"></xsl:value-of>_onselchange()
		{
			if( document.all.<xsl:value-of select="$name"></xsl:value-of> == null
				|| document.all.<xsl:value-of select="$name"></xsl:value-of>.disabled )
			{
				return;
			}
			var doc = <xsl:value-of select="$name"></xsl:value-of>_getTargetDoc();
			if( doc == null )
			{
				return;
			}
			if( doc.Script.<xsl:value-of select="$name"></xsl:value-of>_onselchangeAction != null )
			{
				doc.Script.<xsl:value-of select="$name"></xsl:value-of>_onselchangeAction(document.all.<xsl:value-of select="$name"></xsl:value-of>, window.event.oldTreeNodeIndex, window.event.newTreeNodeIndex);
			}
		}
		function <xsl:value-of select="$name"></xsl:value-of>_getTargetDoc()
		{
			var doc = document;
			while( doc != null <xsl:text disable-output-escaping="yes">&amp;&amp;</xsl:text> doc.all.<xsl:value-of select="$name"></xsl:value-of>_target == null )
			{
				var oWnd = doc.parentWindow;
				doc = null;
				if( oWnd != null <xsl:text disable-output-escaping="yes">&amp;&amp;</xsl:text> oWnd != window.top <xsl:text disable-output-escaping="yes">&amp;&amp;</xsl:text> oWnd.parent != null )
				{
					doc = oWnd.parent.document;
				}
			}
			return doc;
		}
		<xsl:variable name="safe_name" select="translate($name, '.', '_')"></xsl:variable>
		function <xsl:value-of select="$name"></xsl:value-of>_handleReadyState(oTreeview)
		{
			if( oTreeview == null )
			{
				oTreeview = document.all.<xsl:value-of select="$name"></xsl:value-of>;
			}
			if( oTreeview == null )
			{
				return;
			}
			var parentFrame = window.frameElement;
			if( oTreeview.readyState == "complete" )
			{
				if( oTreeview.document.parentWindow.name == "<xsl:value-of select="$name"></xsl:value-of>_hidden" )
				{
					return;
				}
				if( parentFrame != null )
				{
					if( parentFrame.getAttribute("__x_std_treeview_<xsl:value-of select="$safe_name"></xsl:value-of>_selected") == true )
					{
						return;
					}
				}
				var doc = <xsl:value-of select="$name"></xsl:value-of>_getTargetDoc();
				if( doc != null <xsl:text disable-output-escaping="yes">&amp;&amp;</xsl:text> doc.Script != null )
				{
					if( doc.Script.<xsl:value-of select="$name"></xsl:value-of>_onselchangeAction != null )
					{
						var selIndex = oTreeview.selectedNodeIndex;
						if( parentFrame != null )
						{
							parentFrame.setAttribute("__x_std_treeview_<xsl:value-of select="$safe_name"></xsl:value-of>_selected", true);
						}
						doc.Script.<xsl:value-of select="$name"></xsl:value-of>_onselchangeAction(oTreeview, selIndex, selIndex);
					}
					return;
				}
				setTimeout("<xsl:value-of select="$name"></xsl:value-of>_handleReadyState(null)", 100);
			}
		}
		<xsl:text disable-output-escaping="yes">
		//]]&gt;
		</xsl:text></script><xsl:choose><xsl:when test="not($lweb_design_mode)"><mytree:treeview id="{$name}" class="{$class}" style="height:100%;width:100%;" onexpand="{$name}_onexpand()" oncollapse="{$name}_oncollapse()" systemimagespath="{$lweb_images_path}/treeimages" treenodesrc="{$xmlid}" onselectedindexchange="{$name}_onselchange()" onreadystatechange="{$name}_handleReadyState(this)" defaultstyle="{$default_style}" selectedstyle="{$selected_style}"><xsl:attribute name="style"><xsl:call-template name="make_size_and_pos_style_v2.private"><xsl:with-param name="caller_name" select="'std_treeview.xsl'"></xsl:with-param><xsl:with-param name="pos_absolute" select="$pos_absolute_design"></xsl:with-param><xsl:with-param name="width"><xsl:choose><xsl:when test="$width_design = '0pt'">100%</xsl:when><xsl:otherwise><xsl:value-of select="$width_design"></xsl:value-of></xsl:otherwise></xsl:choose></xsl:with-param><xsl:with-param name="height"><xsl:choose><xsl:when test="$height_design = '0pt'">100%</xsl:when><xsl:otherwise><xsl:value-of select="$height_design"></xsl:value-of></xsl:otherwise></xsl:choose></xsl:with-param></xsl:call-template><xsl:if test="$bg_color!=''"><xsl:text>background-color:</xsl:text><xsl:value-of select="$bg_color"></xsl:value-of></xsl:if><xsl:text>;visibility:hidden</xsl:text></xsl:attribute></mytree:treeview><script type="text/javascript"><xsl:text disable-output-escaping="yes">
		//&lt;![CDATA[
		</xsl:text>
{
var oTree = document.getElementById("<xsl:value-of select="$name"></xsl:value-of>");
if( oTree != null )
{
var bResetStyle = false;
var dftStyle = oTree.defaultStyle;
if( dftStyle != null )
{
dftStyle = dftStyle.toLowerCase();
}
if( dftStyle.search("font-family:") <xsl:text disable-output-escaping="yes">&lt;</xsl:text> 0 )
{
dftStyle += ";font-family:" + oTree.currentStyle.fontFamily;
bResetStyle = true;
}
if( dftStyle.search("font-size:") <xsl:text disable-output-escaping="yes">&lt;</xsl:text> 0 )
{
dftStyle += ";font-size:" + oTree.currentStyle.fontSize;
bResetStyle = true;
}
if( dftStyle.search("font-style:") <xsl:text disable-output-escaping="yes">&lt;</xsl:text> 0 )
{
dftStyle += ";font-style:" + oTree.currentStyle.fontStyle;
bResetStyle = true;
}
if( dftStyle.search("font-variant:") <xsl:text disable-output-escaping="yes">&lt;</xsl:text> 0 )
{
dftStyle += ";font-variant:" + oTree.currentStyle.fontVariant;
bResetStyle = true;
}
if( dftStyle.search("font-weight:") <xsl:text disable-output-escaping="yes">&lt;</xsl:text> 0 )
{
dftStyle += ";font-weight:" + oTree.currentStyle.fontWeight;
bResetStyle = true;
}
if( bResetStyle )
{
oTree.defaultStyle = dftStyle;
}
}
}
		<xsl:text disable-output-escaping="yes">
		//]]&gt; 
		</xsl:text></script><iframe class="hidden" name="{$name}_hidden" onload="{$name}_expand_onload(this)" src="javascript:''"><xsl:comment /></iframe></xsl:when></xsl:choose></xsl:element></xsl:if></xsl:template><xsl:template name="std_treeview_target"><xsl:param name="treeview_name" select="concat('oTree', ancestor-or-self::lxml:list/@name, position())"></xsl:param><xsl:param name="formname" select="'LANSA'"></xsl:param><xsl:param name="pos_absolute_design"></xsl:param><xsl:param name="width_design" select="'100%'"></xsl:param><xsl:param name="height_design" select="'0pt'"></xsl:param><xsl:param name="wamname" select="$lweb_WAMName"></xsl:param><xsl:param name="wrname"></xsl:param><xsl:param name="reentryfield" select="'STDRENTRY'"></xsl:param><xsl:param name="reentryvalue" select="'D'"></xsl:param><xsl:param name="tag_fieldname_alias"></xsl:param><xsl:param name="resize_to_content" select="true()"></xsl:param><xsl:param name="class" select="'std_treeview_target'"></xsl:param><xsl:param name="bg_color"></xsl:param><xsl:variable name="reentryfield_value_id" select="concat(generate-id(), 'a')"></xsl:variable><xsl:variable name="reentryvalue_id" select="concat(generate-id(), 'b')"></xsl:variable><script type="text/javascript"><xsl:text disable-output-escaping="yes">
		//&lt;![CDATA[
		</xsl:text>
		window.attachEvent("onload", <xsl:value-of select="$treeview_name"></xsl:value-of>_onwindowload);
		function <xsl:value-of select="$treeview_name"></xsl:value-of>_resize(oFrame)
		{
		<xsl:if test="$resize_to_content">
			if( window.name == "<xsl:value-of select="$treeview_name"></xsl:value-of>_hidden" )
			{
				return;
			}
			var doc = document.frames("<xsl:value-of select="$treeview_name"></xsl:value-of>_target").document;
			var oBody = doc.body;
			oFrame.style.height = oBody.scrollHeight + (oBody.offsetHeight - oBody.clientHeight);
			oFrame.style.width = oBody.scrollWidth + (oBody.offsetWidth - oBody.clientWidth);
		</xsl:if>
		}
		function <xsl:value-of select="$treeview_name"></xsl:value-of>_disableTarget(bDisable)
		{
			var doc = document.frames("<xsl:value-of select="$treeview_name"></xsl:value-of>_target").document;
			if( bDisable )
			{
				var forms = doc.forms;
				for(index = 0; index <xsl:text disable-output-escaping="yes">&lt;</xsl:text> forms.length; index++)
				{
					var form = forms.item(index);
					var elems = form.elements;
					for(elemIndex = 0; elemIndex <xsl:text disable-output-escaping="yes">&lt;</xsl:text> elems.length; elemIndex++)
					{
					var elem = elems.item(elemIndex);
					elem.disabled = bDisable;
					}
				}
			}
			if( !bDisable <xsl:text disable-output-escaping="yes">&amp;&amp;</xsl:text> doc != null <xsl:text disable-output-escaping="yes">&amp;&amp;</xsl:text> doc.body != null <xsl:text disable-output-escaping="yes">&amp;&amp;</xsl:text> doc.body.disabled != true )
			{
				doc.body.disabled = bDisable;
			}
		}
		function <xsl:value-of select="$treeview_name"></xsl:value-of>_onload(oFrame)
		{
			if( window.name == "<xsl:value-of select="$treeview_name"></xsl:value-of>_hidden" )
			{
				return;
			}
			var doc = document.frames("<xsl:value-of select="$treeview_name"></xsl:value-of>_target").document;
			if( doc.URL != "about:blank" <xsl:text disable-output-escaping="yes">&amp;&amp;</xsl:text> doc.URL != "javascript:''" )
			{
				oFrame.style.visibility = "";
			}
			<xsl:value-of select="$treeview_name"></xsl:value-of>_disableTarget(false);
			<xsl:value-of select="$treeview_name"></xsl:value-of>_resize(oFrame);
		}
		function <xsl:value-of select="$treeview_name"></xsl:value-of>_onwindowload()
		{
			if( window.name == "<xsl:value-of select="$treeview_name"></xsl:value-of>_hidden" )
			{
				
				var oTarget = document.all.<xsl:value-of select="$treeview_name"></xsl:value-of>_target;
				if( oTarget != null )
				{
					oTarget.removeNode(true);
				}
				return;
			}
/*			var doc = document;
			while( doc != null <xsl:text disable-output-escaping="yes">&amp;&amp;</xsl:text> doc.all.<xsl:value-of select="$treeview_name"></xsl:value-of>_hidden == null )
			{
				var oWnd = doc.parentWindow;
				doc = null;
				if( oWnd != null <xsl:text disable-output-escaping="yes">&amp;&amp;</xsl:text> oWnd != window.top <xsl:text disable-output-escaping="yes">&amp;&amp;</xsl:text> oWnd.parent != null )
				{
					doc = oWnd.parent.document;
				}
			}
			if( doc == null )
			{
				return;
			}
			if( doc.all.<xsl:value-of select="$treeview_name"></xsl:value-of> == null )
			{
				return;
			}
			var selIndex = doc.all.<xsl:value-of select="$treeview_name"></xsl:value-of>.selectedNodeIndex;
			<xsl:value-of select="$treeview_name"></xsl:value-of>_onselchangeAction(doc.all.<xsl:value-of select="$treeview_name"></xsl:value-of>, selIndex, selIndex);
*/
		}
		function <xsl:value-of select="$treeview_name"></xsl:value-of>_onselchangeAction(oTreeview, oldTreeNodeIndex, newTreeNodeIndex)
		{
			if( oTreeview != null )
			{
				oTreeview.style.visibility = "";
			}
			if( oTreeview == null || oTreeview.getAttribute("__x_freezeSelect") == true )
			{
				return;
			}
			var oldNode = oTreeview.getTreeNode(oldTreeNodeIndex);
			var newNode = oTreeview.getTreeNode(newTreeNodeIndex);
			var oFrame = document.getElementById("<xsl:value-of select="$treeview_name"></xsl:value-of>_target");
			var oDiv = oFrame != null ? oFrame.previousSibling : null;
			<xsl:if test="$reentryfield != ''"><xsl:text>InsertHidden(document.</xsl:text><xsl:value-of select="$formname"></xsl:value-of><xsl:text>, '</xsl:text><xsl:value-of select="$reentryfield"></xsl:value-of><xsl:text>', stdGetSpanText(oDiv, '</xsl:text><xsl:value-of select="$reentryfield_value_id"></xsl:value-of><xsl:text>'));if( document.</xsl:text><xsl:value-of select="$formname"></xsl:value-of><xsl:text> != null ) {</xsl:text><xsl:text>document.</xsl:text><xsl:value-of select="$formname"></xsl:value-of><xsl:text>.</xsl:text><xsl:value-of select="$reentryfield"></xsl:value-of><xsl:text>.value = stdGetSpanText(oDiv, '</xsl:text><xsl:value-of select="$reentryvalue_id"></xsl:value-of><xsl:text>')};</xsl:text></xsl:if><xsl:call-template name="std_treeview_onselchange.private"><xsl:with-param name="name" select="$treeview_name"></xsl:with-param><xsl:with-param name="oldnode">oldNode</xsl:with-param><xsl:with-param name="newnode">newNode</xsl:with-param><xsl:with-param name="formname" select="$formname"></xsl:with-param><xsl:with-param name="wamname" select="$wamname"></xsl:with-param><xsl:with-param name="wrname" select="$wrname"></xsl:with-param><xsl:with-param name="tag_fieldname_alias" select="$tag_fieldname_alias"></xsl:with-param></xsl:call-template>
		}
		<xsl:text disable-output-escaping="yes">
		//]]&gt; 
		</xsl:text></script><xsl:if test="$reentryfield != ''"><div class="hidden__"><span id="{$reentryfield_value_id}"><xsl:value-of select="key('field-value', $reentryfield)"></xsl:value-of><xsl:comment /></span><span id="{$reentryvalue_id}"><xsl:value-of select="$reentryvalue"></xsl:value-of><xsl:comment /></span></div></xsl:if><iframe class="{$class}" id="{$treeview_name}_target" style="width:100%;height:100%;visibility:hidden;background-color:{$bg_color}" name="{$treeview_name}_target" src="javascript:''" scrolling="no" onload="{$treeview_name}_onload(this)" allowtransparency="-1"><xsl:attribute name="style"><xsl:call-template name="make_size_and_pos_style.private"><xsl:with-param name="caller_name" select="'std_treeview.xsl'"></xsl:with-param><xsl:with-param name="pos_absolute" select="$pos_absolute_design"></xsl:with-param><xsl:with-param name="width"><xsl:choose><xsl:when test="$width_design = '0pt'">100%</xsl:when><xsl:otherwise><xsl:value-of select="$width_design"></xsl:value-of></xsl:otherwise></xsl:choose></xsl:with-param><xsl:with-param name="height"><xsl:choose><xsl:when test="$height_design = '0pt'">100%</xsl:when><xsl:otherwise><xsl:value-of select="$height_design"></xsl:value-of></xsl:otherwise></xsl:choose></xsl:with-param></xsl:call-template><xsl:text>visibility:hidden;</xsl:text><xsl:if test="$bg_color!=''"><xsl:text>background-color:</xsl:text><xsl:value-of select="$bg_color"></xsl:value-of></xsl:if></xsl:attribute><xsl:comment></xsl:comment></iframe></xsl:template><xsl:template name="std_treeview_onexpand.private"><xsl:param name="formname"></xsl:param><xsl:param name="name"></xsl:param><xsl:param name="onexpand_wamname"></xsl:param><xsl:param name="onexpand_wrname"></xsl:param>
		if( document.all.<xsl:value-of select="$name"></xsl:value-of> != null )
		{
				var index = window.event.treeNodeIndex;
				var node = document.all.<xsl:value-of select="$name"></xsl:value-of>.getTreeNode(index);
				if( !node.getAttribute("expanded") )
				{
				var child = document.all.<xsl:value-of select="$name"></xsl:value-of>.createTreeNode();
				child.setAttribute("text", "Loading...");
				node.add(child);
				node.setAttribute("expanded", true);
				<xsl:call-template name="std_treeview_ongetitems.private"><xsl:with-param name="formname" select="$formname"></xsl:with-param><xsl:with-param name="name" select="$name"></xsl:with-param><xsl:with-param name="node">node</xsl:with-param><xsl:with-param name="onexpand_wamname" select="$onexpand_wamname"></xsl:with-param><xsl:with-param name="onexpand_wrname" select="$onexpand_wrname"></xsl:with-param></xsl:call-template>
				var openImageUrl = node.getAttribute("OPEN_IMAGEURL");
				if( openImageUrl != null )
				{
					<xsl:value-of select="$name"></xsl:value-of>_replace_image(parentNode, "<xsl:value-of select="$lweb_images_path"></xsl:value-of>/" + openImageUrl);
				}
				}
				else
				{
					var imageUrl = node.getAttribute("_PREV_IMAGEURL");
					if( imageUrl != null )
					{
						var prevImageUrl = node.getAttribute("IMAGEURL");
						node.setAttribute("IMAGEURL", imageUrl);
						node.setAttribute("_PREV_IMAGEURL", prevImageUrl);
					}
				}
		}
	</xsl:template><xsl:template name="std_treeview_onselchange.private"><xsl:param name="name"></xsl:param><xsl:param name="oldnode"></xsl:param><xsl:param name="newnode"></xsl:param><xsl:param name="formname"></xsl:param><xsl:param name="wamname"></xsl:param><xsl:param name="wrname"></xsl:param><xsl:param name="tag_fieldname_alias"></xsl:param>
		var wrName = null;
		if( <xsl:value-of select="$newnode"></xsl:value-of> != null )
		{
			wrName = <xsl:value-of select="$newnode"></xsl:value-of>.getAttribute("_ACTION_VALUE");
		}
		if( wrName == null || wrName == "" )
		{
		wrName = "<xsl:value-of select="$wrname"></xsl:value-of>";
		}
		<xsl:value-of select="$name"></xsl:value-of>_disableTarget(true);
		if( wrName != null <xsl:text disable-output-escaping="yes">&amp;&amp;</xsl:text> wrName != "" )
		{
		oTreeview.document.Script.<xsl:value-of select="$name"></xsl:value-of>_insertTagsHidden(document.<xsl:value-of select="$formname"></xsl:value-of>, <xsl:value-of select="$newnode"></xsl:value-of>, "<xsl:value-of select="$tag_fieldname_alias"></xsl:value-of>");
		oTreeview.document.Script.<xsl:value-of select="$name"></xsl:value-of>_insertHiddenList(document.<xsl:value-of select="$formname"></xsl:value-of>, <xsl:value-of select="$newnode"></xsl:value-of>, oTreeview.document.Script.<xsl:value-of select="$name"></xsl:value-of>_fillParentArray(<xsl:value-of select="$newnode"></xsl:value-of>));
		var oHiddenFrame = oTreeview.document.all.<xsl:value-of select="$name"></xsl:value-of>_hidden;
		if( oHiddenFrame != null <xsl:text disable-output-escaping="yes">&amp;&amp;</xsl:text> window.name != "<xsl:value-of select="$name"></xsl:value-of>_hidden" )
		{
//			oHiddenFrame.removeNode(true);
		}
		HandleEventTarget(document.<xsl:value-of select="$formname"></xsl:value-of>, "<xsl:value-of select="$name"></xsl:value-of>_target", "<xsl:value-of select="$wamname"></xsl:value-of>", wrName);
		}
	</xsl:template><xsl:template name="std_treeview_ongetitems.private"><xsl:param name="formname"></xsl:param><xsl:param name="name"></xsl:param><xsl:param name="node"></xsl:param><xsl:param name="onexpand_wamname"></xsl:param><xsl:param name="onexpand_wrname"></xsl:param>
		var oHiddenFrame = document.all.<xsl:value-of select="$name"></xsl:value-of>_hidden;
		if( oHiddenFrame == null <xsl:text disable-output-escaping="yes">&amp;&amp;</xsl:text> window.name != "<xsl:value-of select="$name"></xsl:value-of>_hidden" )
		{
//			oHiddenFrame = document.createElement("<xsl:text disable-output-escaping="yes">&lt;</xsl:text>iframe class='hidden' name='<xsl:value-of select="$name"></xsl:value-of>_hidden' onload='<xsl:value-of select="$name"></xsl:value-of>_expand_onload(this)'<xsl:text disable-output-escaping="yes">&gt;</xsl:text><xsl:text disable-output-escaping="yes">&lt;</xsl:text>/iframe<xsl:text disable-output-escaping="yes">&gt;</xsl:text>");
//			document.all.appendChild(oHiddenFrame);
		}
		<xsl:value-of select="$name"></xsl:value-of>_insertTagsHidden(document.<xsl:value-of select="$formname"></xsl:value-of>, <xsl:value-of select="$node"></xsl:value-of>, null);
		var parentArr = <xsl:value-of select="$name"></xsl:value-of>_fillParentArray(<xsl:value-of select="$node"></xsl:value-of>);
		<xsl:value-of select="$name"></xsl:value-of>_insertHiddenList(document.<xsl:value-of select="$formname"></xsl:value-of>, <xsl:value-of select="$node"></xsl:value-of>, parentArr);
		document.all.<xsl:value-of select="$name"></xsl:value-of>_hidden.setAttribute("_parentNode", <xsl:value-of select="$node"></xsl:value-of>);
		document.all.<xsl:value-of select="$name"></xsl:value-of>_hidden.setCapture(true);
		HandleEventTarget(document.<xsl:value-of select="$formname"></xsl:value-of>, "<xsl:value-of select="$name"></xsl:value-of>_hidden", "<xsl:value-of select="$onexpand_wamname"></xsl:value-of>", "<xsl:value-of select="$onexpand_wrname"></xsl:value-of>");
		</xsl:template><xsl:template name="std_treeview_replaceChildren.private"><xsl:param name="name"></xsl:param><xsl:param name="parent">parentNode</xsl:param><xsl:param name="array"></xsl:param><xsl:param name="array_item">text</xsl:param><xsl:param name="array_id_item">id</xsl:param><xsl:param name="array_id_items"></xsl:param><xsl:param name="array_groupid_item">groupid</xsl:param><xsl:param name="array_onselect_wrname_item"></xsl:param><xsl:param name="array_image_item">image</xsl:param><xsl:call-template name="std_treeview_removeChildren.private"><xsl:with-param name="name" select="$name"></xsl:with-param><xsl:with-param name="parent" select="$parent"></xsl:with-param></xsl:call-template><xsl:call-template name="std_treeview_addChildren.private"><xsl:with-param name="name" select="$name"></xsl:with-param><xsl:with-param name="parent" select="$parent"></xsl:with-param><xsl:with-param name="array" select="$array"></xsl:with-param><xsl:with-param name="array_item" select="$array_item"></xsl:with-param><xsl:with-param name="array_id_item" select="$array_id_item"></xsl:with-param><xsl:with-param name="array_id_items" select="$array_id_items"></xsl:with-param><xsl:with-param name="array_groupid_item" select="$array_groupid_item"></xsl:with-param><xsl:with-param name="array_onselect_wrname_item" select="$array_onselect_wrname_item"></xsl:with-param><xsl:with-param name="array_image_item" select="$array_image_item"></xsl:with-param></xsl:call-template></xsl:template><xsl:template name="std_treeview_removeChildren.private"><xsl:param name="name"></xsl:param><xsl:param name="parent">parentNode</xsl:param><xsl:text>var children = </xsl:text><xsl:value-of select="$parent"></xsl:value-of>.getChildren(); <xsl:text disable-output-escaping="yes">for(count = 0; count &lt; children.length; count++)
		{
			var child = children[count];
			child.remove();
		}</xsl:text></xsl:template><xsl:template name="std_treeview_addChildren.private"><xsl:param name="name"></xsl:param><xsl:param name="parent">parentNode</xsl:param><xsl:param name="array"></xsl:param><xsl:param name="array_item">text</xsl:param><xsl:param name="array_id_item">id</xsl:param><xsl:param name="array_id_items"></xsl:param><xsl:param name="array_groupid_item">groupid</xsl:param><xsl:param name="array_onselect_wrname_item"></xsl:param><xsl:param name="array_image_item">image</xsl:param>
		var groupLevel = 2;
		var _parentNode = <xsl:value-of select="$parent"></xsl:value-of>.getParent();
		while( _parentNode != null )
		{
		_parentNode = _parentNode.getParent();
		groupLevel++;
		}
		<xsl:text disable-output-escaping="yes">    for(count = 0; count &lt; </xsl:text><xsl:value-of select="$array"></xsl:value-of><xsl:text>.length; count++) { </xsl:text><xsl:if test="$array_item != ''"><xsl:call-template name="std_treeview_additem.private"><xsl:with-param name="name" select="$name"></xsl:with-param><xsl:with-param name="parent" select="$parent"></xsl:with-param><xsl:with-param name="text"><xsl:value-of select="$array"></xsl:value-of>[count].<xsl:value-of select="$array_item"></xsl:value-of></xsl:with-param><xsl:with-param name="item_id"><xsl:choose><xsl:when test="$array_id_item !=''"><xsl:value-of select="$array"></xsl:value-of>[count].<xsl:value-of select="$array_id_item"></xsl:value-of></xsl:when><xsl:otherwise></xsl:otherwise></xsl:choose></xsl:with-param><xsl:with-param name="id_items" select="$array_id_items"></xsl:with-param><xsl:with-param name="group_id"><xsl:choose><xsl:when test="$array_groupid_item !=''"><xsl:text>groupLevel</xsl:text></xsl:when><xsl:otherwise></xsl:otherwise></xsl:choose></xsl:with-param><xsl:with-param name="onselect_wrname"><xsl:choose><xsl:when test="$array_onselect_wrname_item !=''"><xsl:value-of select="$array"></xsl:value-of>[count].<xsl:value-of select="$array_onselect_wrname_item"></xsl:value-of></xsl:when><xsl:otherwise></xsl:otherwise></xsl:choose></xsl:with-param><xsl:with-param name="imageurl"><xsl:choose><xsl:when test="$array_image_item !=''"><xsl:value-of select="$array"></xsl:value-of>[count].<xsl:value-of select="$array_image_item"></xsl:value-of></xsl:when><xsl:otherwise></xsl:otherwise></xsl:choose></xsl:with-param></xsl:call-template></xsl:if><xsl:text> }</xsl:text></xsl:template><xsl:template name="std_treeview_additem.private"><xsl:param name="name"></xsl:param><xsl:param name="parent">parentNode</xsl:param><xsl:param name="child">childNode</xsl:param><xsl:param name="text"></xsl:param><xsl:param name="item_id"></xsl:param><xsl:param name="id_items"></xsl:param><xsl:param name="group_id"></xsl:param><xsl:param name="onselect_wrname"></xsl:param><xsl:param name="imageurl"></xsl:param><xsl:text></xsl:text>var <xsl:value-of select="$child"></xsl:value-of> = document.all.<xsl:value-of select="$name"></xsl:value-of>.createTreeNode();<xsl:text></xsl:text><xsl:value-of select="$child"></xsl:value-of>.setAttribute("text", <xsl:value-of select="$text"></xsl:value-of>);<xsl:text></xsl:text><xsl:if test="$imageurl != ''">
		if( <xsl:value-of select="$imageurl"></xsl:value-of> != null <xsl:text disable-output-escaping="yes">&amp;&amp;</xsl:text><xsl:value-of select="$imageurl"></xsl:value-of> != "" )
		{
			<xsl:value-of select="$child"></xsl:value-of>.setAttribute("IMAGEURL", "<xsl:value-of select="$lweb_images_path"></xsl:value-of>/" + <xsl:value-of select="$imageurl"></xsl:value-of>);<xsl:text></xsl:text>
		}
		</xsl:if><xsl:if test="$item_id != ''"><xsl:for-each select="$id_items"><xsl:value-of select="$child"></xsl:value-of>.setAttribute("_TAG_VALUE<xsl:value-of select="position()"></xsl:value-of>", <xsl:value-of select="$item_id"></xsl:value-of>);<xsl:text></xsl:text></xsl:for-each></xsl:if><xsl:if test="$group_id != ''"><xsl:value-of select="$child"></xsl:value-of>.setAttribute("_GROUP_VALUE", <xsl:value-of select="$group_id"></xsl:value-of>);<xsl:text></xsl:text></xsl:if><xsl:if test="$onselect_wrname != ''"><xsl:value-of select="$child"></xsl:value-of>.setAttribute("_ACTION_VALUE", <xsl:value-of select="$onselect_wrname"></xsl:value-of>);<xsl:text></xsl:text></xsl:if><xsl:value-of select="$child"></xsl:value-of>.setAttribute("EXPANDABLE", "checkOnce");
		<xsl:value-of select="$parent"></xsl:value-of>.add(<xsl:value-of select="$child"></xsl:value-of>);<xsl:text></xsl:text> if( !<xsl:value-of select="$parent"></xsl:value-of>.getAttribute("expanded") )<xsl:text></xsl:text> {<xsl:text></xsl:text><xsl:value-of select="$parent"></xsl:value-of>.setAttribute("expanded", true);<xsl:text></xsl:text> }<xsl:text></xsl:text></xsl:template><xsl:template name="std_treeview-xml.private"><xsl:param name="listname"></xsl:param><xsl:param name="list_caption_field"></xsl:param><xsl:param name="list_image_field"></xsl:param><xsl:param name="list_open_image_field"></xsl:param><xsl:param name="list_tag_field"></xsl:param><xsl:param name="list_haschildren_field"></xsl:param><xsl:param name="list_subitem_group_field"></xsl:param><xsl:param name="list_onselect_wrname_field"></xsl:param><xsl:param name="list_is_selected_field"></xsl:param><xsl:param name="list_is_expanded_field"></xsl:param><xsl:param name="list_parent_id_field"></xsl:param><xsl:param name="list_style_field"></xsl:param><xsl:param name="list_selected_style_field"></xsl:param><xsl:param name="folder_closed_image"></xsl:param><xsl:param name="folder_open_image"></xsl:param><xsl:param name="item_image"></xsl:param><xsl:if test="not($lweb_design_mode)"><TREENODES><xsl:variable name="list_nodes" select="/lxml:data/lxml:lists/lxml:list[@name=$listname]/lxml:list-entries/lxml:entry"></xsl:variable><xsl:variable name="max_level"><xsl:call-template name="std_treeview_max_level.private"><xsl:with-param name="node_set" select="$list_nodes/lxml:column[@name=$list_subitem_group_field]"></xsl:with-param></xsl:call-template></xsl:variable><xsl:attribute name="max_level"><xsl:value-of select="$max_level"></xsl:value-of></xsl:attribute><xsl:apply-templates mode="std_treeview" select="$list_nodes[not(lxml:column[@name=$list_parent_id_field]) or lxml:column[@name=$list_parent_id_field]='']"><xsl:with-param name="listname" select="$listname"></xsl:with-param><xsl:with-param name="list_caption_field" select="$list_caption_field"></xsl:with-param><xsl:with-param name="list_image_field" select="$list_image_field"></xsl:with-param><xsl:with-param name="list_open_image_field" select="$list_open_image_field"></xsl:with-param><xsl:with-param name="list_tag_field" select="$list_tag_field"></xsl:with-param><xsl:with-param name="list_haschildren_field" select="$list_haschildren_field"></xsl:with-param><xsl:with-param name="list_subitem_group_field" select="$list_subitem_group_field"></xsl:with-param><xsl:with-param name="list_onselect_wrname_field" select="$list_onselect_wrname_field"></xsl:with-param><xsl:with-param name="list_is_selected_field" select="$list_is_selected_field"></xsl:with-param><xsl:with-param name="list_is_expanded_field" select="$list_is_expanded_field"></xsl:with-param><xsl:with-param name="list_parent_id_field" select="$list_parent_id_field"></xsl:with-param><xsl:with-param name="list_style_field" select="$list_style_field"></xsl:with-param><xsl:with-param name="list_selected_style_field" select="$list_selected_style_field"></xsl:with-param><xsl:with-param name="folder_closed_image" select="$folder_closed_image"></xsl:with-param><xsl:with-param name="folder_open_image" select="$folder_open_image"></xsl:with-param><xsl:with-param name="item_image" select="$item_image"></xsl:with-param><xsl:with-param name="max_level" select="$max_level"></xsl:with-param></xsl:apply-templates></TREENODES></xsl:if></xsl:template><xsl:template mode="std_treeview" match="lxml:entry"><xsl:param name="listname"></xsl:param><xsl:param name="list_caption_field"></xsl:param><xsl:param name="list_image_field"></xsl:param><xsl:param name="list_open_image_field"></xsl:param><xsl:param name="list_tag_field"></xsl:param><xsl:param name="list_haschildren_field"></xsl:param><xsl:param name="list_subitem_group_field"></xsl:param><xsl:param name="list_onselect_wrname_field"></xsl:param><xsl:param name="list_is_selected_field"></xsl:param><xsl:param name="list_is_expanded_field"></xsl:param><xsl:param name="list_parent_id_field"></xsl:param><xsl:param name="list_style_field"></xsl:param><xsl:param name="list_selected_style_field"></xsl:param><xsl:param name="folder_closed_image"></xsl:param><xsl:param name="folder_open_image"></xsl:param><xsl:param name="item_image"></xsl:param><xsl:param name="max_level"></xsl:param><TREENODE text="{lxml:column[@name=$list_caption_field]}"><xsl:variable name="has_children" select="$list_haschildren_field != '' and lxml:column[@name=$list_haschildren_field] != '' and lxml:column[@name=$list_haschildren_field] != 'N'"></xsl:variable><xsl:variable name="tag_id"><xsl:value-of select="lxml:column[@name=$list_tag_field]"></xsl:value-of></xsl:variable><xsl:variable name="child_level" select="lxml:column[@name=$list_subitem_group_field] + 1"></xsl:variable><xsl:variable name="child_nodeset" select="/lxml:data/lxml:lists/lxml:list[@name=$listname]/lxml:list-entries/lxml:entry[lxml:column[@name=$list_parent_id_field]!='' and lxml:column[@name=$list_parent_id_field]=$tag_id and lxml:column[@name=$list_subitem_group_field] = $child_level]"></xsl:variable><xsl:if test="$list_haschildren_field != '' and lxml:column[@name=$list_haschildren_field] != ''"><xsl:attribute name="EXPANDABLE"><xsl:choose><xsl:when test="lxml:column[@name=$list_haschildren_field] != 'N'"><xsl:text>checkOnce</xsl:text></xsl:when><xsl:otherwise><xsl:text>auto</xsl:text></xsl:otherwise></xsl:choose></xsl:attribute></xsl:if><xsl:variable name="open_imageurl"><xsl:choose><xsl:when test="$list_open_image_field!='' and boolean(lxml:column[@name=$list_open_image_field])"><xsl:value-of select="$lweb_images_path"></xsl:value-of><xsl:text>/</xsl:text><xsl:value-of select="lxml:column[@name=$list_open_image_field]"></xsl:value-of></xsl:when><xsl:otherwise><xsl:choose><xsl:when test="$has_children or $child_nodeset or ($list_subitem_group_field!='' and $max_level &gt; lxml:column[@name=$list_subitem_group_field])"><xsl:if test="$folder_open_image!=''"><xsl:value-of select="$lweb_images_path"></xsl:value-of><xsl:text>/</xsl:text><xsl:value-of select="$folder_open_image"></xsl:value-of></xsl:if></xsl:when><xsl:otherwise><xsl:if test="$item_image!=''"><xsl:value-of select="$lweb_images_path"></xsl:value-of><xsl:text>/</xsl:text><xsl:value-of select="$item_image"></xsl:value-of></xsl:if></xsl:otherwise></xsl:choose></xsl:otherwise></xsl:choose></xsl:variable><xsl:variable name="closed_imageurl"><xsl:choose><xsl:when test="$list_image_field!='' and boolean(lxml:column[@name=$list_image_field])"><xsl:value-of select="$lweb_images_path"></xsl:value-of><xsl:text>/</xsl:text><xsl:value-of select="lxml:column[@name=$list_image_field]"></xsl:value-of></xsl:when><xsl:otherwise><xsl:choose><xsl:when test="$has_children or $child_nodeset or ($list_subitem_group_field!='' and $max_level &gt; lxml:column[@name=$list_subitem_group_field])"><xsl:if test="$folder_closed_image!=''"><xsl:value-of select="$lweb_images_path"></xsl:value-of><xsl:text>/</xsl:text><xsl:value-of select="$folder_closed_image"></xsl:value-of></xsl:if></xsl:when><xsl:otherwise><xsl:if test="$item_image!=''"><xsl:value-of select="$lweb_images_path"></xsl:value-of><xsl:text>/</xsl:text><xsl:value-of select="$item_image"></xsl:value-of></xsl:if></xsl:otherwise></xsl:choose></xsl:otherwise></xsl:choose></xsl:variable><xsl:if test="$closed_imageurl != ''"><xsl:attribute name="IMAGEURL"><xsl:value-of select="$closed_imageurl"></xsl:value-of></xsl:attribute><xsl:if test="$open_imageurl!=''"><xsl:attribute name="_PREV_IMAGEURL"><xsl:value-of select="$open_imageurl"></xsl:value-of></xsl:attribute></xsl:if></xsl:if><xsl:if test="$open_imageurl != ''"><xsl:attribute name="OPEN_IMAGEURL"><xsl:value-of select="$open_imageurl"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$list_is_selected_field != ''"><xsl:if test="lxml:column[@name=$list_is_selected_field]!=''"><xsl:attribute name="_IS_SELECTED"><xsl:value-of select="lxml:column[@name=$list_is_selected_field]"></xsl:value-of></xsl:attribute></xsl:if></xsl:if><xsl:if test="$list_subitem_group_field != ''"><xsl:attribute name="_GROUP_VALUE"><xsl:value-of select="lxml:column[@name=$list_subitem_group_field]"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$list_onselect_wrname_field != ''"><xsl:attribute name="_ACTION_VALUE"><xsl:value-of select="lxml:column[@name=$list_onselect_wrname_field]"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$list_tag_field != ''"><xsl:for-each select="lxml:column[starts-with(@name,$list_tag_field)]"><xsl:attribute name="_TAG_VALUE{position()}"><xsl:value-of select="."></xsl:value-of></xsl:attribute></xsl:for-each><xsl:if test="$list_parent_id_field != ''"><xsl:choose><xsl:when test="$child_nodeset"><xsl:attribute name="EXPANDABLE">auto</xsl:attribute><xsl:if test="$list_is_expanded_field!=''"><xsl:variable name="expanded" select="lxml:column[@name=$list_is_expanded_field]"></xsl:variable><xsl:if test="$expanded='true' or $expanded='Y' or $expanded='y' or $expanded='1'"><xsl:attribute name="EXPANDED"><xsl:text>true</xsl:text></xsl:attribute><xsl:if test="$open_imageurl!=''"><xsl:attribute name="IMAGEURL"><xsl:value-of select="$open_imageurl"></xsl:value-of></xsl:attribute></xsl:if><xsl:if test="$closed_imageurl!=''"><xsl:attribute name="_PREV_IMAGEURL"><xsl:value-of select="$closed_imageurl"></xsl:value-of></xsl:attribute></xsl:if></xsl:if></xsl:if><xsl:apply-templates mode="std_treeview" select="$child_nodeset"><xsl:with-param name="listname" select="$listname"></xsl:with-param><xsl:with-param name="list_caption_field" select="$list_caption_field"></xsl:with-param><xsl:with-param name="list_image_field" select="$list_image_field"></xsl:with-param><xsl:with-param name="list_open_image_field" select="$list_open_image_field"></xsl:with-param><xsl:with-param name="list_tag_field" select="$list_tag_field"></xsl:with-param><xsl:with-param name="list_haschildren_field" select="$list_haschildren_field"></xsl:with-param><xsl:with-param name="list_subitem_group_field" select="$list_subitem_group_field"></xsl:with-param><xsl:with-param name="list_onselect_wrname_field" select="$list_onselect_wrname_field"></xsl:with-param><xsl:with-param name="list_is_selected_field" select="$list_is_selected_field"></xsl:with-param><xsl:with-param name="list_parent_id_field" select="$list_parent_id_field"></xsl:with-param><xsl:with-param name="folder_closed_image" select="$folder_closed_image"></xsl:with-param><xsl:with-param name="folder_open_image" select="$folder_open_image"></xsl:with-param><xsl:with-param name="item_image" select="$item_image"></xsl:with-param><xsl:with-param name="max_level" select="$max_level"></xsl:with-param></xsl:apply-templates></xsl:when><xsl:otherwise><xsl:if test="not($has_children)"><xsl:attribute name="EXPANDABLE">false</xsl:attribute></xsl:if></xsl:otherwise></xsl:choose></xsl:if></xsl:if><xsl:if test="$list_style_field!=''"><xsl:if test="lxml:column[@name=$list_style_field]!=''"><xsl:attribute name="DEFAULTSTYLE"><xsl:value-of select="lxml:column[@name=$list_style_field]"></xsl:value-of></xsl:attribute></xsl:if></xsl:if><xsl:if test="$list_selected_style_field!=''"><xsl:if test="lxml:column[@name=$list_selected_style_field]!=''"><xsl:attribute name="SELECTEDSTYLE"><xsl:value-of select="lxml:column[@name=$list_selected_style_field]"></xsl:value-of></xsl:attribute></xsl:if></xsl:if></TREENODE></xsl:template><xsl:template name="std_treeview_max_level.private"><xsl:param name="node_set" select="/.."></xsl:param><xsl:param name="node_count" select="count($node_set)"></xsl:param><xsl:param name="pos" select="1"></xsl:param><xsl:param name="max" select="0"></xsl:param><xsl:variable name="cur_node" select="$node_set[position()=$pos]"></xsl:variable><xsl:variable name="new_max"><xsl:choose><xsl:when test="number($cur_node) &gt; $max"><xsl:value-of select="$cur_node"></xsl:value-of></xsl:when><xsl:otherwise><xsl:value-of select="$max"></xsl:value-of></xsl:otherwise></xsl:choose></xsl:variable><xsl:choose><xsl:when test="$pos &gt;= $node_count"><xsl:value-of select="$new_max"></xsl:value-of></xsl:when><xsl:otherwise><xsl:call-template name="std_treeview_max_level.private"><xsl:with-param name="node_set" select="$node_set"></xsl:with-param><xsl:with-param name="node_count" select="$node_count"></xsl:with-param><xsl:with-param name="pos" select="$pos + 1"></xsl:with-param><xsl:with-param name="max" select="$new_max"></xsl:with-param></xsl:call-template></xsl:otherwise></xsl:choose></xsl:template><xsl:template name="std_treeview-xml-type.private"><TREENODETYPES><TREENODETYPE type="file" imageurl="images/html.gif"></TREENODETYPE><TREENODETYPE type="folder" imageurl="images/folder.gif"></TREENODETYPE><TREENODETYPE type="root" imageurl="images/root.gif"></TREENODETYPE></TREENODETYPES></xsl:template></xsl:transform>