{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 7,
			"minor" : 3,
			"revision" : 1,
			"architecture" : "x86",
			"modernui" : 1
		}
,
		"rect" : [ 34.0, 78.0, 1212.0, 684.0 ],
		"bglocked" : 0,
		"openinpresentation" : 0,
		"default_fontsize" : 12.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 1,
		"gridsize" : [ 15.0, 15.0 ],
		"gridsnaponopen" : 1,
		"objectsnaponopen" : 1,
		"statusbarvisible" : 2,
		"toolbarvisible" : 1,
		"lefttoolbarpinned" : 0,
		"toptoolbarpinned" : 0,
		"righttoolbarpinned" : 0,
		"bottomtoolbarpinned" : 0,
		"toolbars_unpinned_last_save" : 0,
		"tallnewobj" : 0,
		"boxanimatetime" : 200,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"description" : "",
		"digest" : "",
		"tags" : "",
		"style" : "",
		"subpatcher_template" : "",
		"boxes" : [ 			{
				"box" : 				{
					"id" : "obj-32",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1059.666748, 373.5, 139.0, 20.0 ],
					"presentation_rect" : [ 1059.666748, 373.5, 0.0, 0.0 ],
					"style" : "",
					"text" : "<----------amp envelopes"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-30",
					"maxclass" : "flonum",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 26.0, 160.0, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-27",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 78.0, 160.0, 63.0, 20.0 ],
					"style" : "",
					"text" : "frequency"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-21",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 78.0, 91.0, 65.0, 20.0 ],
					"style" : "",
					"text" : "MIDI pitch"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-19",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 467.166687, 91.0, 63.0, 20.0 ],
					"style" : "",
					"text" : "amplitude"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-17",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 290.0, 93.0, 51.0, 20.0 ],
					"style" : "",
					"text" : "velocity"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-13",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 768.111084, 36.0, 93.0, 20.0 ],
					"style" : "",
					"text" : "env length (ms)"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-8",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 973.666687, 233.5, 110.0, 20.0 ],
					"style" : "",
					"text" : "<----------overtones"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-6",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 948.666687, 36.0, 214.0, 20.0 ],
					"style" : "",
					"text" : "presets (set your own by shift-clicking)"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-3",
					"maxclass" : "preset",
					"numinlets" : 1,
					"numoutlets" : 4,
					"outlettype" : [ "preset", "int", "preset", "int" ],
					"patching_rect" : [ 948.666687, 55.0, 80.333374, 17.0 ],
					"preset_data" : [ 						{
							"number" : 1,
							"data" : [ 4, "obj-95", "function", "clear", 7, "obj-95", "function", "add", 0.0, 0.0, 0, 7, "obj-95", "function", "add", 6.785693, 0.110236, 0, 7, "obj-95", "function", "add", 15.357122, 0.012686, 0, 7, "obj-95", "function", "add", 56.071407, 0.105861, 0, 7, "obj-95", "function", "add", 83.928558, 0.088801, 0, 7, "obj-95", "function", "add", 100.0, 0.0, 0, 5, "obj-95", "function", "domain", 100.0, 6, "obj-95", "function", "range", 0.0, 0.110236, 5, "obj-95", "function", "mode", 0, 5, "obj-108", "flonum", "float", 5.0, 4, "obj-90", "function", "clear", 7, "obj-90", "function", "add", 0.0, 0.0, 0, 7, "obj-90", "function", "add", 13.571385, 0.081802, 0, 7, "obj-90", "function", "add", 41.428532, 0.016186, 0, 7, "obj-90", "function", "add", 64.999962, 0.094925, 0, 7, "obj-90", "function", "add", 100.0, 0.0, 0, 5, "obj-90", "function", "domain", 100.0, 6, "obj-90", "function", "range", 0.0, 0.110236, 5, "obj-90", "function", "mode", 0, 5, "obj-106", "flonum", "float", 4.0, 4, "obj-85", "function", "clear", 7, "obj-85", "function", "add", 0.0, 0.0, 0, 7, "obj-85", "function", "add", 22.500002, 0.110236, 0, 7, "obj-85", "function", "add", 47.142857, 0.020997, 0, 7, "obj-85", "function", "add", 54.64286, 0.069554, 0, 7, "obj-85", "function", "add", 100.0, 0.0, 0, 5, "obj-85", "function", "domain", 100.0, 6, "obj-85", "function", "range", 0.0, 0.110236, 5, "obj-85", "function", "mode", 0, 5, "obj-104", "flonum", "float", 3.0, 4, "obj-80", "function", "clear", 7, "obj-80", "function", "add", 0.0, 0.0, 0, 7, "obj-80", "function", "add", 19.642868, 0.110236, 0, 7, "obj-80", "function", "add", 41.071442, 0.024497, 0, 7, "obj-80", "function", "add", 53.928585, 0.088801, 0, 7, "obj-80", "function", "add", 73.214302, 0.057305, 0, 7, "obj-80", "function", "add", 100.0, 0.0, 0, 5, "obj-80", "function", "domain", 100.0, 6, "obj-80", "function", "range", 0.0, 0.110236, 5, "obj-80", "function", "mode", 0, 5, "obj-102", "flonum", "float", 2.0, 4, "obj-4", "function", "clear", 7, "obj-4", "function", "add", 0.0, 0.0, 0, 7, "obj-4", "function", "add", 20.212767, 0.110236, 0, 7, "obj-4", "function", "add", 76.785728, 0.104112, 0, 7, "obj-4", "function", "add", 100.0, 0.0, 0, 5, "obj-4", "function", "domain", 100.0, 6, "obj-4", "function", "range", 0.0, 0.110236, 5, "obj-4", "function", "mode", 0 ]
						}
, 						{
							"number" : 2,
							"data" : [ 4, "obj-95", "function", "clear", 7, "obj-95", "function", "add", 0.0, 0.0, 0, 7, "obj-95", "function", "add", 15.357122, 0.092738, 0, 7, "obj-95", "function", "add", 38.928551, 0.029746, 0, 7, "obj-95", "function", "add", 61.428555, 0.016623, 0, 7, "obj-95", "function", "add", 61.428555, 0.094051, 0, 7, "obj-95", "function", "add", 100.0, 0.0, 0, 5, "obj-95", "function", "domain", 100.0, 6, "obj-95", "function", "range", 0.0, 0.110236, 5, "obj-95", "function", "mode", 0, 5, "obj-108", "flonum", "float", 9.0, 4, "obj-90", "function", "clear", 7, "obj-90", "function", "add", 0.0, 0.0, 0, 7, "obj-90", "function", "add", 23.214243, 0.060805, 0, 7, "obj-90", "function", "add", 41.428532, 0.016186, 0, 7, "obj-90", "function", "add", 41.428532, 0.108049, 0, 7, "obj-90", "function", "add", 61.785675, 0.02406, 0, 7, "obj-90", "function", "add", 86.428535, 0.109361, 0, 7, "obj-90", "function", "add", 100.0, 0.0, 0, 5, "obj-90", "function", "domain", 100.0, 6, "obj-90", "function", "range", 0.0, 0.110236, 5, "obj-90", "function", "mode", 0, 5, "obj-106", "flonum", "float", 7.0, 4, "obj-85", "function", "clear", 7, "obj-85", "function", "add", 0.0, 0.0, 0, 7, "obj-85", "function", "add", 26.785715, 0.028871, 0, 7, "obj-85", "function", "add", 54.64286, 0.103675, 0, 7, "obj-85", "function", "add", 83.571434, 0.074803, 0, 7, "obj-85", "function", "add", 100.0, 0.0, 0, 5, "obj-85", "function", "domain", 100.0, 6, "obj-85", "function", "range", 0.0, 0.110236, 5, "obj-85", "function", "mode", 0, 5, "obj-104", "flonum", "float", 5.0, 4, "obj-80", "function", "clear", 7, "obj-80", "function", "add", 0.0, 0.0, 0, 7, "obj-80", "function", "add", 41.071442, 0.024497, 0, 7, "obj-80", "function", "add", 58.214298, 0.110236, 0, 7, "obj-80", "function", "add", 73.214302, 0.057305, 0, 7, "obj-80", "function", "add", 100.0, 0.0, 0, 5, "obj-80", "function", "domain", 100.0, 6, "obj-80", "function", "range", 0.0, 0.110236, 5, "obj-80", "function", "mode", 0, 5, "obj-102", "flonum", "float", 3.0, 4, "obj-4", "function", "clear", 7, "obj-4", "function", "add", 0.0, 0.0, 0, 7, "obj-4", "function", "add", 20.212767, 0.110236, 0, 7, "obj-4", "function", "add", 100.0, 0.0, 0, 5, "obj-4", "function", "domain", 100.0, 6, "obj-4", "function", "range", 0.0, 0.110236, 5, "obj-4", "function", "mode", 0 ]
						}
, 						{
							"number" : 3,
							"data" : [ 4, "obj-95", "function", "clear", 7, "obj-95", "function", "add", 0.0, 0.0, 0, 7, "obj-95", "function", "add", 15.357121, 0.109799, 0, 7, "obj-95", "function", "add", 31.428551, 0.013998, 0, 7, "obj-95", "function", "add", 100.0, 0.0, 0, 5, "obj-95", "function", "domain", 100.0, 6, "obj-95", "function", "range", 0.0, 0.110236, 5, "obj-95", "function", "mode", 0, 5, "obj-108", "flonum", "float", 7.1, 4, "obj-90", "function", "clear", 7, "obj-90", "function", "add", 0.0, 0.0, 0, 7, "obj-90", "function", "add", 41.428532, 0.108049, 0, 7, "obj-90", "function", "add", 86.428535, 0.109361, 0, 7, "obj-90", "function", "add", 100.0, 0.0, 0, 5, "obj-90", "function", "domain", 100.0, 6, "obj-90", "function", "range", 0.0, 0.110236, 5, "obj-90", "function", "mode", 0, 5, "obj-106", "flonum", "float", 5.3, 4, "obj-85", "function", "clear", 7, "obj-85", "function", "add", 0.0, 0.0, 0, 7, "obj-85", "function", "add", 15.000001, 0.108924, 0, 7, "obj-85", "function", "add", 83.571434, 0.074803, 0, 7, "obj-85", "function", "add", 100.0, 0.0, 0, 5, "obj-85", "function", "domain", 100.0, 6, "obj-85", "function", "range", 0.0, 0.110236, 5, "obj-85", "function", "mode", 0, 5, "obj-104", "flonum", "float", 3.5, 4, "obj-80", "function", "clear", 7, "obj-80", "function", "add", 0.0, 0.0, 0, 7, "obj-80", "function", "add", 41.071442, 0.024497, 0, 7, "obj-80", "function", "add", 55.000015, 0.104549, 0, 7, "obj-80", "function", "add", 100.0, 0.0, 0, 5, "obj-80", "function", "domain", 100.0, 6, "obj-80", "function", "range", 0.0, 0.110236, 5, "obj-80", "function", "mode", 0, 5, "obj-102", "flonum", "float", 2.7, 4, "obj-4", "function", "clear", 7, "obj-4", "function", "add", 0.0, 0.0, 0, 7, "obj-4", "function", "add", 18.928577, 0.056868, 0, 7, "obj-4", "function", "add", 27.500008, 0.000437, 0, 7, "obj-4", "function", "add", 44.642864, 0.110236, 0, 7, "obj-4", "function", "add", 60.714294, 0.034558, 0, 7, "obj-4", "function", "add", 85.357155, 0.106737, 0, 7, "obj-4", "function", "add", 100.0, 0.0, 0, 5, "obj-4", "function", "domain", 100.0, 6, "obj-4", "function", "range", 0.0, 0.110236, 5, "obj-4", "function", "mode", 0 ]
						}
 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-1",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 712.5, 12.0, 85.0, 22.0 ],
					"style" : "",
					"text" : "loadmess 250"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-108",
					"maxclass" : "flonum",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 873.833313, 220.0, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-106",
					"maxclass" : "flonum",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 664.5, 220.0, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-104",
					"maxclass" : "flonum",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 455.166687, 220.0, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-102",
					"maxclass" : "flonum",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 245.833344, 220.0, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-100",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 863.333313, 248.0, 29.5, 22.0 ],
					"style" : "",
					"text" : "* 5."
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-99",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 654.0, 248.0, 29.5, 22.0 ],
					"style" : "",
					"text" : "* 4."
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-98",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 444.666687, 248.0, 29.5, 22.0 ],
					"style" : "",
					"text" : "* 3."
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-97",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 235.333344, 248.0, 29.5, 22.0 ],
					"style" : "",
					"text" : "* 2."
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-91",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 863.333313, 480.333374, 29.5, 22.0 ],
					"style" : "",
					"text" : "*~"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-92",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "signal", "bang" ],
					"patching_rect" : [ 977.444397, 449.000061, 36.0, 22.0 ],
					"style" : "",
					"text" : "line~"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-93",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 959.666687, 280.333374, 24.0, 24.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-94",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 863.333313, 280.333374, 72.0, 22.0 ],
					"style" : "",
					"text" : "cycle~ 100."
				}

			}
, 			{
				"box" : 				{
					"addpoints" : [ 0.0, 0.0, 0, 15.357121, 0.164698, 0, 31.428551, 0.020997, 0, 100.0, 0.0, 0 ],
					"domain" : 100.0,
					"id" : "obj-95",
					"maxclass" : "function",
					"numinlets" : 1,
					"numoutlets" : 4,
					"outlettype" : [ "float", "", "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 948.666687, 332.666718, 105.333328, 109.0 ],
					"range" : [ 0.0, 0.165354 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-86",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 654.0, 482.000031, 29.5, 22.0 ],
					"style" : "",
					"text" : "*~"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-87",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "signal", "bang" ],
					"patching_rect" : [ 768.111084, 450.666718, 36.0, 22.0 ],
					"style" : "",
					"text" : "line~"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-88",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 751.333374, 282.000031, 24.0, 24.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-89",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 654.0, 282.000031, 72.0, 22.0 ],
					"style" : "",
					"text" : "cycle~ 100."
				}

			}
, 			{
				"box" : 				{
					"addpoints" : [ 0.0, 0.0, 0, 41.428532, 0.162074, 0, 86.428535, 0.164042, 0, 100.0, 0.0, 0 ],
					"domain" : 100.0,
					"id" : "obj-90",
					"maxclass" : "function",
					"numinlets" : 1,
					"numoutlets" : 4,
					"outlettype" : [ "float", "", "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 739.333374, 334.333374, 105.333328, 109.0 ],
					"range" : [ 0.0, 0.165354 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-81",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 444.666687, 483.666687, 29.5, 22.0 ],
					"style" : "",
					"text" : "*~"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-82",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "signal", "bang" ],
					"patching_rect" : [ 558.777771, 452.333374, 36.0, 22.0 ],
					"style" : "",
					"text" : "line~"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-83",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 539.0, 283.666687, 24.0, 24.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-84",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 444.666687, 283.666687, 72.0, 22.0 ],
					"style" : "",
					"text" : "cycle~ 100."
				}

			}
, 			{
				"box" : 				{
					"addpoints" : [ 0.0, 0.0, 0, 15.000001, 0.163386, 0, 83.571434, 0.112205, 0, 100.0, 0.0, 0 ],
					"domain" : 100.0,
					"id" : "obj-85",
					"maxclass" : "function",
					"numinlets" : 1,
					"numoutlets" : 4,
					"outlettype" : [ "float", "", "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 530.0, 336.000031, 105.333328, 109.0 ],
					"range" : [ 0.0, 0.165354 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-76",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 235.333344, 485.333344, 29.5, 22.0 ],
					"style" : "",
					"text" : "*~"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-77",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "signal", "bang" ],
					"patching_rect" : [ 349.444427, 454.000031, 36.0, 22.0 ],
					"style" : "",
					"text" : "line~"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-78",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 332.666656, 285.333344, 24.0, 24.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-79",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 235.333344, 285.333344, 72.0, 22.0 ],
					"style" : "",
					"text" : "cycle~ 100."
				}

			}
, 			{
				"box" : 				{
					"addpoints" : [ 0.0, 0.0, 0, 41.071442, 0.036745, 0, 55.000015, 0.156824, 0, 100.0, 0.0, 0 ],
					"domain" : 100.0,
					"id" : "obj-80",
					"maxclass" : "function",
					"numinlets" : 1,
					"numoutlets" : 4,
					"outlettype" : [ "float", "", "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 320.666656, 337.666687, 105.333328, 109.0 ],
					"range" : [ 0.0, 0.165354 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-40",
					"maxclass" : "flonum",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 415.166687, 91.0, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-36",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 712.5, 36.0, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-34",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 415.166687, 127.0, 84.0, 22.0 ],
					"style" : "",
					"text" : "setrange 0 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-31",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 712.5, 72.0, 83.0, 22.0 ],
					"style" : "",
					"text" : "setdomain $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-28",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 26.0, 673.0, 37.0, 22.0 ],
					"style" : "",
					"text" : "dac~"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-25",
					"maxclass" : "gain~",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "signal", "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 26.0, 525.0, 22.0, 140.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-24",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 26.0, 487.0, 29.5, 22.0 ],
					"style" : "",
					"text" : "*~"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-23",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "signal", "bang" ],
					"patching_rect" : [ 140.111099, 455.666687, 36.0, 22.0 ],
					"style" : "",
					"text" : "line~"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-22",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 120.333328, 287.0, 24.0, 24.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-15",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 26.0, 287.0, 72.0, 22.0 ],
					"style" : "",
					"text" : "cycle~ 100."
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-14",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 343.0, 127.0, 41.0, 22.0 ],
					"style" : "",
					"text" : "/ 127."
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-12",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 26.0, 127.0, 34.0, 22.0 ],
					"style" : "",
					"text" : "mtof"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-11",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 343.0, 91.0, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-9",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 26.0, 91.0, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"addpoints" : [ 0.0, 0.0, 0, 18.928577, 0.085302, 0, 27.500008, 0.000656, 0, 44.642864, 0.165354, 0, 60.714294, 0.051837, 0, 85.357155, 0.160105, 0, 100.0, 0.0, 0 ],
					"domain" : 100.0,
					"id" : "obj-4",
					"maxclass" : "function",
					"numinlets" : 1,
					"numoutlets" : 4,
					"outlettype" : [ "float", "", "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 111.333328, 339.333344, 105.333328, 109.0 ],
					"range" : [ 0.0, 0.165354 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-2",
					"maxclass" : "kslider",
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "int", "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 26.0, 25.0, 336.0, 53.0 ],
					"presentation_rect" : [ 0.0, 0.0, 336.0, 53.0 ],
					"style" : ""
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-36", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-94", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-100", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-97", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-102", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-98", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-104", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-99", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-106", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-100", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-108", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-14", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-11", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-30", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-12", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-40", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 352.5, 159.0, 403.583344, 159.0, 403.583344, 80.0, 424.666687, 80.0 ],
					"source" : [ "obj-14", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-24", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-15", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-11", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-9", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 129.833328, 324.666687, 120.833328, 324.666687 ],
					"source" : [ "obj-22", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-24", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 149.611099, 481.833344, 46.0, 481.833344 ],
					"source" : [ "obj-23", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-25", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-24", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-28", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-25", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-28", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-25", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-102", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 958.166687, 199.5, 255.333344, 199.5 ],
					"source" : [ "obj-3", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-104", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 958.166687, 199.5, 464.666687, 199.5 ],
					"source" : [ "obj-3", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-106", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 958.166687, 204.5, 674.0, 204.5 ],
					"source" : [ "obj-3", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-108", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 958.166687, 199.5, 883.333313, 199.5 ],
					"source" : [ "obj-3", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 958.166687, 198.166672, 120.833328, 198.166672 ],
					"source" : [ "obj-3", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-80", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 958.166687, 200.333344, 330.166656, 200.333344 ],
					"source" : [ "obj-3", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-85", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 958.166687, 203.500015, 539.5, 203.500015 ],
					"source" : [ "obj-3", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-90", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 958.166687, 202.666687, 748.833374, 202.666687 ],
					"source" : [ "obj-3", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-95", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 958.166687, 201.833359, 958.166687, 201.833359 ],
					"source" : [ "obj-3", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-100", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 35.5, 198.0, 872.833313, 198.0 ],
					"source" : [ "obj-30", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-15", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-30", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-97", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 35.5, 198.0, 244.833344, 198.0 ],
					"source" : [ "obj-30", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-98", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 35.5, 198.0, 454.166687, 198.0 ],
					"source" : [ "obj-30", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-99", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 35.5, 198.0, 663.5, 198.0 ],
					"source" : [ "obj-30", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 722.0, 198.166672, 120.833328, 198.166672 ],
					"source" : [ "obj-31", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-80", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 722.0, 200.333344, 330.166656, 200.333344 ],
					"source" : [ "obj-31", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-85", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 722.0, 200.500015, 539.5, 200.500015 ],
					"source" : [ "obj-31", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-90", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 722.0, 199.666687, 748.833374, 199.666687 ],
					"source" : [ "obj-31", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-95", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 722.0, 198.833359, 958.166687, 198.833359 ],
					"source" : [ "obj-31", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 424.666687, 198.166672, 120.833328, 198.166672 ],
					"source" : [ "obj-34", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-80", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 424.666687, 199.333344, 330.166656, 199.333344 ],
					"source" : [ "obj-34", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-85", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 424.666687, 200.500015, 539.5, 200.500015 ],
					"source" : [ "obj-34", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-90", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 424.666687, 200.666687, 748.833374, 200.666687 ],
					"source" : [ "obj-34", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-95", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 424.666687, 198.833359, 958.166687, 198.833359 ],
					"source" : [ "obj-34", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-31", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-36", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-23", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-4", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-34", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-40", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-25", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 244.833344, 515.666687, 35.5, 515.666687 ],
					"source" : [ "obj-76", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-76", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 358.944427, 480.166687, 255.333344, 480.166687 ],
					"source" : [ "obj-77", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-80", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 342.166656, 323.0, 330.166656, 323.0 ],
					"source" : [ "obj-78", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-76", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 244.833344, 395.833344, 244.833344, 395.833344 ],
					"source" : [ "obj-79", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-77", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-80", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-25", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 454.166687, 514.833374, 35.5, 514.833374 ],
					"source" : [ "obj-81", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-81", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 568.277771, 478.500031, 464.666687, 478.500031 ],
					"source" : [ "obj-82", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-85", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 548.5, 321.333374, 539.5, 321.333374 ],
					"source" : [ "obj-83", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-81", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 454.166687, 394.166687, 454.166687, 394.166687 ],
					"source" : [ "obj-84", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-82", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-85", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-25", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 663.5, 514.0, 35.5, 514.0 ],
					"source" : [ "obj-86", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-86", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 777.611084, 476.833374, 674.0, 476.833374 ],
					"source" : [ "obj-87", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-90", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 760.833374, 319.666687, 748.833374, 319.666687 ],
					"source" : [ "obj-88", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-86", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 663.5, 392.500031, 663.5, 392.500031 ],
					"source" : [ "obj-89", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-12", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-9", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 35.5, 120.666672, 129.833328, 120.666672 ],
					"source" : [ "obj-9", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-78", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 35.5, 120.666672, 342.166656, 120.666672 ],
					"source" : [ "obj-9", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-83", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 35.5, 120.833344, 548.5, 120.833344 ],
					"source" : [ "obj-9", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-88", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 35.5, 121.166687, 760.833374, 121.166687 ],
					"source" : [ "obj-9", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-93", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 35.5, 121.333359, 969.166687, 121.333359 ],
					"source" : [ "obj-9", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-87", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-90", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-25", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 872.833313, 513.166687, 35.5, 513.166687 ],
					"source" : [ "obj-91", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-91", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 986.944397, 475.166718, 883.333313, 475.166718 ],
					"source" : [ "obj-92", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-95", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 969.166687, 318.000061, 958.166687, 318.000061 ],
					"source" : [ "obj-93", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-91", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 872.833313, 390.833374, 872.833313, 390.833374 ],
					"source" : [ "obj-94", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-92", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-95", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-79", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-97", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-84", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-98", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-89", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-99", 0 ]
				}

			}
 ],
		"dependency_cache" : [  ],
		"autosave" : 0
	}

}
