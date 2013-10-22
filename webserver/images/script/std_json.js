/*!
	(c) 2011, 2013 LANSA
	JSON handler scripts
	$Workfile:: std_json.js                 $
	$UTCDate:: 2013-03-08 03:46:26Z         $
	$Revision:: 23                          $
*/

// JSON Webroutine response convenience wrappers

var Lstd = Lstd || {};

/**
 * @namespace JSON convenience functions
 */
Lstd.Json = {

	/**
	* @namespace internal methods. Not for public use.
	* @Internal
	*/
	Internal: {

		/**
		* Find subobject. Finds the object in the parent object (by name or index position)
		* and returns it.
		* @param (string or number) Subjobject name (string) or index position (number)
		* @returns (object) The object
		*/
		findSubobject: function (o, type, parent) {
			var subobj = { id: null, obj: null };
			try {
				switch (typeof o) {
					case "string":
						subobj.id = o;
						subobj.obj = parent[o];
						if (!subobj.obj) throw (type + " " + o + " not found.");
						break;
					case "number":
						subobj.id = Lstd.Utils.getPropertyNameAtIndex(parent, o);
						if (subobj.id == null) throw type + " not found at index " + o + ".";
						subobj.obj = parent[subobj.id];
						break;
					default:
						throw "Argument of type " + (typeof o) + " not valid. Must be a name or index.";
						break;
				}
			}
			catch (e) {
				console.error(e);
			}
			return subobj;
		},

		/**
		* Creates a skeleton webroutine object
		* @returns (object) The webroutine object
		*/
		createWebroutine: function () {
			var obj = {"webroutine":{"fields":{},"lists":{}}};
			var lmxlSKMethod = Lstd.Webroutine.getContext("session-key-method");
			var lxmlSK = Lstd.Webroutine.getContext("session-key");

			if (lmxlSKMethod && lxmlSK && (lmxlSKMethod === "hidden") && (lxmlSK !== "") ) {
				obj.webroutine["context"] = {};
				obj.webroutine.context["session-key"] = lxmlSK;
				obj.webroutine.context["session-key-method"] = "hidden";
				obj.webroutine.context["session-key-name"] = Lstd.Webroutine.getContext("session-key-name");
			}
			return obj;
		}
	},

	/**
	* @class Lstd.Json.Messages
	* @param Array of messages
	*/
	Messages: function (args) {
		this.messages = args ? args : [];

		/**
		* Returns the number of messages
		*/
		this.count = function () {
			return this.messages.length;
		};

		/**
		* Calls the function for each message passing a string message as a parameter
		* @param (function) Callback function to call for each message.
		*/
		this.each = function (func) {
			try {
				if (typeof func == "function") for (var i = 0; i < this.messages.length; i++) func(this.messages[i]);
			}
			catch (e) {
				console.error(e);
				throw e;
			}
		};
	},

	/**
	* @class Lstd.Json.Field
	* @param Map with keys:
	*		id: Field id
	*		obj: JSON response field object
	*/
	Field: function (args) {
		this.id = args.id;
		this.field = args.obj;

		/**
		* Returns the field name
		* @returns (string) The field name
		*/
		this.name = function () {
			return this.id;
		};

		/**
		* Returns the field label
		* @returns (string) The field label
		*/
		this.label = function () {
			return this.field.caption.label;
		};

		/**
		* Returns the field description
		* @returns (string) The field description
		*/
		this.description = function () {
			return this.field.caption.description;
		};

		/**
		* Returns the field column headings in an array of strings
		* @returns (string array) The field column headings in an array of strings
		*/
		this.headings = function () {
			var caption = this.field.caption;
			return [
				caption["heading-1"] ? caption["heading-1"] : "",
				caption["heading-2"] ? caption["heading-2"] : "",
				caption["heading-3"] ? caption["heading-3"] : "",
			];
		};

		/**
		* Returns the field value
		* @returns (string) The field value
		*/
		this.value = function () {
			return this.field.value;
		};
	},

	/**
	* @class Lstd.Json.Fields
	* Fields provides an iterator to go through each field in the webroutine response.
	* @param (object) Webroutine response fields
	*/
	Fields: function (fields) {
		this.fields = fields;

		/**
		* Calls the function for each field passing an instance of Lstd.Json.Field as a parameter
		* @param (function) Callback function to call for each field.
		*/
		this.each = function (func) {
			try {
				if (typeof func == "function") for (var fld in this.fields) func(new Lstd.Json.Field({ id: fld, obj: this.fields[fld] }));
			}
			catch (e) {
				console.error(e);
				throw e;
			}
		};
	},

	/**
	* @class Lstd.Json.ListHeader
	* Wrapper for a webroutine list column header
	* @param (object) Webroutine response list column header
	*/
	ListHeader: function (header) {
		this.header = header;

		/**
		* Returns the column name
		* @returns (string) The column value
		*/
		this.name = function () {
			return this.header.name;
		};

		/**
		* Returns the column headings in an array of strings (if included in the response)
		* @returns The column headings in an array of strings (if included in the response)
		*/
		this.headings = function () {
			var h = this.header;
			return [
				h["heading-1"] ? h["heading-1"] : "",
				h["heading-2"] ? h["heading-2"] : "",
				h["heading-3"] ? h["heading-3"] : "",
			];
		};
	},

	/**
	* @class Lstd.Json.ListHeaders
	* Wrapper for a webroutine list headers
	* @param (object) Map with list name (id) and Webroutine response list column headers (obj)
	*/
	ListHeaders: function (args) {
		this.id = args.id;
		this.headers = args.obj;

		this.findByName = {};
		for (var i = 0, hdr; hdr = this.headers[i]; i++) this.findByName[hdr.name] = i;

		/**
		* Returns the index position of the column name
		* @param (string) Column name
		* @returns (number) The index position of the column name
		*/
		this.indexOf = function (name) {
			var index = this.findByName[name];
			return index >= 0 ? index : -1;
		};

		/**
		* Returns a Lstd.Json.ListHeader for the requested column name
		* @param (string) Column name
		* @returns (object) a Lstd.Json.ListHeader for the requested column name
		*/
		this.col = function (name) {
			var index = this.indexOf(name);
			return index >= 0 ? new Lstd.Json.ListHeader(this.headers[index]) : null;
		};

		/**
		* Calls the function for each list passing it a Lstd.Json.ListHeader instance
		* @param (function) Callback function to call for each list.
		*/
		this.each = function (func) {
			try {
				if (typeof func == "function") for (var i = 0, hdr; hdr = this.headers[i]; i++) func(new Lstd.Json.ListHeader(hdr));
			}
			catch (e) {
				console.error(e);
				throw e;
			}
			return this;
		};
	},

	/**
	* @class Lstd.Json.ListEntry
	* Wrapper for a webroutine list entry
	* @param (object) Map with row number (rowNumber), this list's header wrapper (header) and webroutine response list entry (obj)
	*/
	ListEntry: function (args) {
		this.rowNumber = args.rowNumber;
		this.listHeader = args.header;
		this.entry = args.obj;

		/**
		* Returns the row number for this list entry
		* @returns (number) The row number for this list entry
		*/
		this.row = function () {
			return this.rowNumber;
		};

		/**
		* Returns the value of the column
		* @param (string) column name
		*/
		this.col = function (name) {
			var index = this.listHeader.indexOf(name);
			return index >= 0 ? this.entry[index] : null;
		};

		/**
		* Returns the column id (list.row.colname)
		* @param (string) column name
		*/
		this.columnId = function (name) {
			var index = this.listHeader.indexOf(name);
			return index >= 0 ? (this.listHeader.id + "." + this.rowNumber.zeropad(4) + "." + name) : null;
		};

		/**
		* Calls the function for each column passing it the column value (native type)
		* @param (function) Callback function to call for each column in the list entry.
		*/
		this.each = function (func) {
			try {
				if (typeof func == "function") for (var i = 0, col; col = this.entry[i]; i++) func(col);
			}
			catch (e) {
				console.error(e);
				throw e;
			}
		};
		return this;
	},

	/**
	* @class Lstd.Json.ListEntries
	* Provides an interator to go through each entry in the list.
	* @param (object) Map with this list's header wrapper (header) and webroutine response list entries (obj)
	*/
	ListEntries: function (args) {
		this.listHeader = args.header;
		this.entries = args.obj;

		/**
		* Returns the row count
		* @return [number] the row count
		*/
		this.rowCount = function () {
			return this.entries ? this.entries.length : 0;
		};

		/**
		* Returns the column count
		* @return [number] the column count
		*/
		this.columnCount = function () {
			return this.entries ? (this.entries.length > 0 ? this.entries[0].length : 0) : 0;
		};

		/**
		* Calls the function for each entry passing it a Lstd.Json.ListEntry instance
		* @param (function) Callback function to call for each list entry.
		*/
		this.each = function (func) {
			try {
				if (typeof func == "function") for (var i = 0, entry; entry = this.entries[i]; i++) func(new Lstd.Json.ListEntry({ rowNumber: i + 1, header: this.listHeader, obj: entry }));
			}
			catch (e) {
				console.error(e);
				throw e;
			}
		};

		/**
		* Calls the function for each entry passing it the raw entry (array of values)
		* @param (function) Callback function to call for each list entry.
		*/
		this.rawEach = function (func) {
			try {
				if (typeof func == "function") for (var i = 0, entry; entry = this.entries[i]; i++) func(i, entry);
			}
			catch (e) {
				console.error(e);
				throw e;
			}
		};

		/**
		* Creates a new ListEntries with rows and columns transposed
		* @return (Object) ListEntries with rows and columns transposed. Note: header of returned ListEntries is null.
		*/
		this.transpose = function () {
			var entries = [];
			var nCols = this.entries.length;
			var nRows = nCols > 0 ? this.entries[0].length : 0;
			if (nCols && nRows) {
				entries = new Array(nRows);
				for (var i = 0; i < nRows; i++) {
					entries[i] = new Array(nCols);
					for (var j = 0; j < nCols; j++) entries[i][j] = this.entries[j][i];
				}
			}
			return new Lstd.Json.ListEntries({ header: null, obj: entries });
		};

		/**
		* Adds a row to the list entries
		* @param (array) The row
		*/
		this.add = function (row) {
			this.entries.push(row);
		};
	},

	/**
	* @class Lstd.Json.List
	* Wrapper for a webroutine list
	* @param (object) Map with this list's name (id) and webroutine response list (obj)
	*/
	List: function (args) {
		this.id = args.id;
		this.list = args.obj;
		this.listHeader = new Lstd.Json.ListHeaders({ id: this.id, obj: this.list.header });
		this.listEntries = new Lstd.Json.ListEntries({ header: this.listHeader, obj: this.list.entries });

		/**
		* Returns the list name
		* @returns (string) The list name
		*/
		this.name = function () {
			return this.id;
		};

		/**
		* If no argument passed, returns the headers in an instance of Lstd.Json.ListHeaders. If array of names
		* passed, it sets the headers of the list.
		* IMPORTANT: If the headers are set, the list column entries are cleared.
		* @param (array) Optional array of column names
		* @returns (object) The list headers in a Lstd.Json.ListHeaders
		*/
		this.headers = function (cols) {
			if (cols == null) {
				return this.listHeader;
			}
			else {
				if (cols instanceof Array) {
					this.list.header = [];
					for (var i = 0; i < cols.length; i++) {
						this.list.header.push({ "name": cols[i] });
					}
					this.list.entries = [];
					this.listHeader = new Lstd.Json.ListHeaders({ id: this.id, obj: this.list.header });
					this.listEntries = new Lstd.Json.ListEntries({ header: this.listHeader, obj: this.list.entries });
				}
				else {
					throw "Argument is not array of column names.";
				}
			}
		};

		/**
		* Returns the entries in an instance of Lstd.Json.ListEntries
		* @returns (object) The list entries in a Lstd.Json.ListEntries
		*/
		this.entries = function () {
			return this.listEntries;
		};

		/**
		 * Returns the object to serialize
		 * @returns (string) The JSON string representation of this object
		 */
		this.toJSON = function () {
			var tmp = {"list": {}};
			tmp.list[this.id] = this.list;
			return tmp;
		}

		/**
		* Posts the list in JSON format.
		* It calls the supplied callback function passing it the Lstd.Json.Wr object
		* @param (map) {wam: "wam_name", webroutine: "webrtn_name", callback: function()}
		*/
		this.post = function (args) {
			var wr = Lstd.Json.Internal.createWebroutine();
			wr.webroutine.lists[this.id] = this.list;
			Lstd.Json.post(args, wr);
		}
	},

	/**
	* @class Lstd.Json.Lists
	* Lists provides an interator to go through each list in the webroutine response.
	* @param (object) Webroutine response lists object
	*/
	Lists: function (lists) {
		this.lists = lists;

		/**
		* Calls the function for each list passing it a Lstd.Json.List instance
		* @param (function) Callback function to call for each list.
		*/
		this.each = function (func) {
			try {
				if (typeof func == "function") for (var list in this.lists) func(new Lstd.Json.List({ id: list, obj: this.lists[list] }));
			}
			catch (e) {
				console.error(e);
				throw e;
			}
		};
	},

	/**
	* @class Lstd.Json.Wr
	* Wraps the webroutine response sent by the server.
	* @param (object) The JSON webroutine response
	*/
	Wr: function (wr) {
		this.webroutine = wr;

		/**
		* Returns the value of the context item
		* @param (string) The name of the context item
		*/
		this.context = function (item) {
			return this.webroutine.context[item];
		};

		/**
		* Returns a wrapper for the messages in the webroutine
		* @returns (object) The messages in a Lstd.Json.Messages
		*/
		this.messages = function () {
			return new Lstd.Json.Messages(this.webroutine.messages);
		};

		/**
		* Returns a wrapper for the fields in the webroutine
		* @returns (object) The fields in a Lstd.Json.Fields
		*/
		this.fields = function () {
			return new Lstd.Json.Fields(this.webroutine.fields);
		};

		/**
		* Returns a wrapper for the lists in the webroutine
		* @returns (object) The fields in a Lstd.Json.Lists
		*/
		this.lists = function () {
			return new Lstd.Json.Lists(this.webroutine.lists);
		};

		/**
		* Returns the field
		* @param (string or number)  Name (string) or index position (number - zero based index). Only use string if value is provided
		* @param (string or number)  Value (optional)
		* @returns (object) Field in a Lstd.Json.Field (only for getter)
		*/
		this.field = function (o, v) {
			if (v == null) {
				var fld = Lstd.Json.Internal.findSubobject(o, "field", this.webroutine.fields);
				return fld.obj ? new Lstd.Json.Field(fld) : null;
			}
			else {
				if (typeof o != "string") throw "Field name required!";
				this.webroutine.fields[o] = {"value": v};
			}
		};

		/**
		* Returns the list
		* @param (string or number)  Name (string) or index position (number - zero based index)
		* @returns (object) List in a Lstd.Json.List
		*/
		this.list = function (o) {
			var lst = Lstd.Json.Internal.findSubobject(o, "list", this.webroutine.lists);
			return lst.obj ? new Lstd.Json.List(lst) : null;
		};
		/**
		* Adds a list to the webroutine
		* @param (string)  Name (string)
		* @returns (object) List in a Lstd.Json.List. If list exists, it is returned
		* exists
		*/
		this.addList = function (name) {
			var lst = Lstd.Json.Internal.findSubobject(name, "list", this.webroutine.lists);

			if (lst.obj) {
				return new Lstd.Json.List(lst);
			}
			else {
				this.webroutine.lists[name] = { "header": [], "entries": [] };
				return this.list(name);
			}
		};

		/**
		* Posts the webroutine in JSON format.
		* It calls the supplied callback function passing it the Lstd.Json.List object
		* @param (map) {wam: "wam_name", webroutine: "webrtn_name", callback: function()}
		*/
		this.post = function (args) {
			Lstd.Json.post(args, this);
		}
	},

	/**
	* Wrapper factory. It creates and returns a wrapper for the JSON object
	* It returns null if the object is not a valid JSON response object
	* @param (object) Can be: 1. Webroutine object from JSON response  2. JSON List 3. Empty
	* If null, it returns an empty webroutine wrapper.
	* @returns A Lstd.Json.Wr or Lstd.Json.List or null.
	*/
	factory: function (obj) {

		if (obj == null) obj = Lstd.Json.Internal.createWebroutine();
		var otype = Lstd.Utils.getPropertyNameAtIndex(obj, 0);

		switch (otype) {
			case "webroutine":
				return new Lstd.Json.Wr(obj[otype]);
				break;

			case "list":
				var lst = Lstd.Json.Internal.findSubobject(0, "list", obj[otype]);
				return lst ? new Lstd.Json.List(lst) : null;
				break;
		}
		return null;
	},

	/**
	* Request JSON response Webroutine.
	* It calls the supplied callback function passing it the Lstd.Json.Wr object
	* @param (map) {wam: "wam_name", webroutine: "webrtn_name", fields: {}, callback: function()}
	*/
	getWebroutine: function (args) {
		var request = new Lstd.HTTP.Request();
		if (args.wam) request.wam = args.wam;
		if (args.webroutine) request.webroutine = args.webroutine;
		if (args.fields) request.addFields(args.fields);
		if (args.lists) {
			for (listName in args.lists) {
				request.addList(listName, args.lists[listName]);
			}
		}
		try {
			Lstd.HTTP.getWebroutine(request, args.callback);
		}
		catch (e) {
			console("Lstd.Json.getWebroutine(): " + e);
		}
	},

	/**
	* Returns the object to serialize
	* @returns (string) The JSON string representation of this object
	*/
	toJSON: function () {
		return this.webroutine;
	},

	/**
	* Posts the object in JSON format.
	* It calls the supplied callback function passing it the object
	* @param (map) {wam: "wam_name", webroutine: "webrtn_name", callback: function()}
	* @param (object) The webroutine or list to post
	*/
	post: function(args, o) {
		var request = new Lstd.HTTP.Request();
		request.method = "POST";
		if (args.wam) request.wam = args.wam;
		if (args.webroutine) request.webroutine = args.webroutine;

		jQuery.ajax({
			url: request.getURL(),
			type: request.method,
			cache: request.cache,
			dataType: "json",
			contentType: "application/json",
			data: JSON.stringify(o),
			scriptCharset: "utf-8",
			success: function(data) {
				var wr = (Lstd.Json) ? Lstd.Json.factory(data) : data;
				if (jQuery.isFunction(args.callback)) args.callback(wr);
			},
			error: function(xhr, s, e) {
				console.error("JSON response: " + s);
			}
		});
	}
};