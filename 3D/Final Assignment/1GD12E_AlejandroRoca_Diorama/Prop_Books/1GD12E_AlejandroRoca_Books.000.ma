//Maya ASCII 2022 scene
//Name: 1GD12E_AlejandroRoca_Books.000.ma
//Last modified: Sat, Jul 23, 2022 10:28:31 AM
//Codeset: 1252
requires maya "2022";
requires "stereoCamera" "10.0";
requires -nodeType "aiOptions" -nodeType "aiAOVDriver" -nodeType "aiAOVFilter" -nodeType "aiSkyDomeLight"
		 -nodeType "aiStandardSurface" "mtoa" "5.0.0.1";
requires "stereoCamera" "10.0";
currentUnit -l centimeter -a degree -t film;
fileInfo "application" "maya";
fileInfo "product" "Maya 2022";
fileInfo "version" "2022";
fileInfo "cutIdentifier" "202110272215-ad32f8f1e6";
fileInfo "osv" "Windows 10 Home v2009 (Build: 19044)";
fileInfo "UUID" "4C64F5BF-4EB8-CA48-E508-1EA3077329A0";
fileInfo "license" "education";
createNode transform -s -n "persp";
	rename -uid "CBB20537-40F8-A23F-4B21-26837A14FFF1";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 2.1341535175025022 8.3839854147606001 12.452027279281454 ;
	setAttr ".r" -type "double3" -24.338352728505402 -351.80000000000695 -2.0083798881404517e-16 ;
createNode camera -s -n "perspShape" -p "persp";
	rename -uid "6CB0EF23-4C47-136F-7BC7-2C89212700F0";
	setAttr -k off ".v" no;
	setAttr ".fl" 34.999999999999993;
	setAttr ".coi" 22.543515902370522;
	setAttr ".imn" -type "string" "persp";
	setAttr ".den" -type "string" "persp_depth";
	setAttr ".man" -type "string" "persp_mask";
	setAttr ".hc" -type "string" "viewSet -p %camera";
	setAttr ".dgm" no;
	setAttr ".ai_translator" -type "string" "perspective";
createNode transform -s -n "top";
	rename -uid "45E02EF2-4F56-EF12-FDF5-2895A3A150BC";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 0 1000.1 0 ;
	setAttr ".r" -type "double3" -90 0 0 ;
createNode camera -s -n "topShape" -p "top";
	rename -uid "30CC5B27-4562-DCB1-B432-9BB785A531E9";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".coi" 1000.1;
	setAttr ".ow" 30;
	setAttr ".imn" -type "string" "top";
	setAttr ".den" -type "string" "top_depth";
	setAttr ".man" -type "string" "top_mask";
	setAttr ".hc" -type "string" "viewSet -t %camera";
	setAttr ".o" yes;
	setAttr ".ai_translator" -type "string" "orthographic";
createNode transform -s -n "front";
	rename -uid "E954741A-49E3-D1E2-3A3A-34907A2CA684";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 0 0 1000.1 ;
createNode camera -s -n "frontShape" -p "front";
	rename -uid "1F5AE986-4B50-6B46-DB4F-279C57D4A5C7";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".coi" 1000.1;
	setAttr ".ow" 30;
	setAttr ".imn" -type "string" "front";
	setAttr ".den" -type "string" "front_depth";
	setAttr ".man" -type "string" "front_mask";
	setAttr ".hc" -type "string" "viewSet -f %camera";
	setAttr ".o" yes;
	setAttr ".ai_translator" -type "string" "orthographic";
createNode transform -s -n "side";
	rename -uid "83D0C7A7-414C-8094-4EDC-AA901C3893A1";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 1000.1 0 0 ;
	setAttr ".r" -type "double3" 0 90 0 ;
createNode camera -s -n "sideShape" -p "side";
	rename -uid "8F23D138-46DB-4DF0-85BB-A98A807A7331";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".coi" 1000.1;
	setAttr ".ow" 30;
	setAttr ".imn" -type "string" "side";
	setAttr ".den" -type "string" "side_depth";
	setAttr ".man" -type "string" "side_mask";
	setAttr ".hc" -type "string" "viewSet -s %camera";
	setAttr ".o" yes;
	setAttr ".ai_translator" -type "string" "orthographic";
createNode transform -n "Template";
	rename -uid "1BAE495E-4F3D-2238-9EA6-AAA3D2659F3F";
createNode transform -n "LIGHTS_Grp" -p "Template";
	rename -uid "2B0E0A47-4D01-81E4-401C-E8B09B3A3BC1";
createNode transform -n "Skydome_l" -p "LIGHTS_Grp";
	rename -uid "08A4BEBE-4B26-DA65-7E6A-299CFBE98066";
	setAttr ".v" no;
createNode aiSkyDomeLight -n "Skydome_lShape" -p "Skydome_l";
	rename -uid "649B4E4B-45D4-93CD-C362-65B07757CB3E";
	addAttr -ci true -h true -sn "aal" -ln "attributeAliasList" -dt "attributeAlias";
	setAttr -k off ".v";
	setAttr ".csh" no;
	setAttr ".rcsh" no;
	setAttr ".aal" -type "attributeAlias" {"exposure","aiExposure"} ;
createNode transform -n "groundplane_Geo" -p "Template";
	rename -uid "93A00281-460D-5DA0-1B1B-7B9C26CAACBF";
	setAttr ".v" no;
	setAttr ".s" -type "double3" 1 -0.32127547571129456 1 ;
createNode mesh -n "groundplane_GeoShape" -p "groundplane_Geo";
	rename -uid "628DBC8C-47D7-A44B-8145-C79ADF405DE8";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 12 ".uvst[0].uvsp[0:11]" -type "float2" 0 0 1 0 0 1 1 1 0
		 0 1 0 1 1 0 1 0 0 1 0 1 1 0 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".vt[0:7]"  -100 0 100 100 0 100 -100 0 -100 100 0 -100
		 -100 0 100 100 0 100 100 0 -100 -100 0 -100;
	setAttr -s 12 ".ed[0:11]"  0 1 0 0 2 0 1 3 0 2 3 0 0 4 0 1 5 0 4 5 0
		 3 6 0 5 6 0 2 7 0 7 6 0 4 7 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 6 8 -11 -12
		mu 0 4 8 9 10 11
		f 4 1 3 -3 -1
		mu 0 4 4 7 6 5
		f 4 0 5 -7 -5
		mu 0 4 0 1 9 8
		f 4 2 7 -9 -6
		mu 0 4 1 3 10 9
		f 4 -4 9 10 -8
		mu 0 4 3 2 11 10
		f 4 -2 4 11 -10
		mu 0 4 2 0 8 11;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "book:Book";
	rename -uid "222DC275-48F4-756E-D071-6BBF43DDE1BF";
	setAttr ".t" -type "double3" 0 0 3.1011628450870941 ;
createNode transform -n "book:pCube2" -p "book:Book";
	rename -uid "B05F570B-4D17-EBE2-2CDB-D7903AB917ED";
	setAttr ".t" -type "double3" 0.37667354192084801 0.86413165184599317 4.277749346505467 ;
	setAttr ".s" -type "double3" 6.4929167855246455 0.55352106928805289 5.0224925017220841 ;
createNode mesh -n "book:polySurfaceShape1" -p "book:pCube2";
	rename -uid "DD728671-4FD9-BB9F-3447-6A8086C84885";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.625 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 20 ".uvst[0].uvsp[0:19]" -type "float2" 0.375 0.48885566
		 0.625 0.76114434 0.625 0.60112053 0.375 0.64887941 0.375 0.60112059 0.62499994 0.48885566
		 0.375 0.76114434 0.625 0.64887947 0.375 0.49201748 0.375 0.5 0.375 0.5464564 0.625
		 0.54645634 0.625 0.5 0.62499994 0.49201748 0.375 0.7035436 0.375 0.75 0.375 0.75798249
		 0.625 0.75798249 0.625 0.75 0.625 0.70354366;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 20 ".vt[0:19]"  -0.5 0.095517755 -0.5 -0.5 0.49999988 -0.45542267
		 -0.5 0.46921074 -0.4724817 -0.5 0.38152981 -0.48694363 -0.5 0.25030637 -0.4966068
		 0.49999997 0.095517755 -0.5 0.49999997 0.25030637 -0.4966068 0.49999997 0.38152981 -0.48694363
		 0.49999997 0.46921074 -0.4724817 0.49999997 0.49999988 -0.45542267 -0.5 -0.5 -0.45542267
		 -0.5 -0.095517755 -0.5 -0.5 -0.25030637 -0.4966068 -0.5 -0.38152981 -0.48694363 -0.5 -0.46921074 -0.4724817
		 0.49999997 -0.5 -0.45542267 0.49999997 -0.46921074 -0.4724817 0.49999997 -0.38152981 -0.48694363
		 0.49999997 -0.25030637 -0.4966068 0.49999997 -0.095517755 -0.5;
	setAttr -s 28 ".ed[0:27]"  0 11 0 5 19 0 0 5 1 9 1 0 10 15 0 19 11 1
		 0 4 0 4 6 1 6 5 0 4 3 0 3 7 1 7 6 0 3 2 0 2 8 1 8 7 0 2 1 0 9 8 0 10 14 0 14 16 1
		 16 15 0 14 13 0 13 17 1 17 16 0 13 12 0 12 18 1 18 17 0 12 11 0 19 18 0;
	setAttr -s 9 -ch 36 ".fc[0:8]" -type "polyFaces" 
		f 4 2 1 5 -1
		mu 0 4 4 2 7 3
		f 4 6 7 8 -3
		mu 0 4 4 10 11 2
		f 4 9 10 11 -8
		mu 0 4 10 9 12 11
		f 4 12 13 14 -11
		mu 0 4 9 8 13 12
		f 4 15 -4 16 -14
		mu 0 4 8 0 5 13
		f 4 17 18 19 -5
		mu 0 4 6 16 17 1
		f 4 20 21 22 -19
		mu 0 4 16 15 18 17
		f 4 23 24 25 -22
		mu 0 4 15 14 19 18
		f 4 26 -6 27 -25
		mu 0 4 14 3 7 19;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
createNode transform -n "book:transform1" -p "book:pCube2";
	rename -uid "CF99F443-4D61-2F9A-041F-89A078219663";
	setAttr ".v" no;
createNode mesh -n "book:pCubeShape2" -p "book:transform1";
	rename -uid "C6246079-4646-BF62-66C4-08B522729A11";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.625 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 40 ".pt[0:39]" -type "float3"  0.021950837 -1.8626451e-09 
		0.19254956 0.021950837 -1.4901161e-08 0.18368641 0.021950837 -1.4901161e-08 0.18707787 
		0.021950837 7.4505806e-09 0.1899533 0.021950837 -7.4505806e-09 0.19187437 -0.021950837 
		-1.8626451e-09 0.19254956 -0.021950837 -7.4505806e-09 0.19187437 -0.021950837 7.4505806e-09 
		0.1899533 -0.021950837 -1.4901161e-08 0.18707787 -0.021950837 -1.4901161e-08 0.18368641 
		0.021950837 1.4901161e-08 0.18368641 0.021950837 -1.8626451e-09 0.19254956 0.021950837 
		-3.7252903e-09 0.19187437 0.021950837 -1.4901161e-08 0.1899533 0.021950837 7.4505806e-09 
		0.18707787 -0.021950837 1.4901161e-08 0.18368641 -0.021950837 7.4505806e-09 0.18707787 
		-0.021950837 -1.4901161e-08 0.1899533 -0.021950837 -3.7252903e-09 0.19187437 -0.021950837 
		-1.8626451e-09 0.19254956 0.021950837 0 -0.74162221 -0.021950837 0 -0.74162221 -0.021950837 
		0 -0.74162221 0.021950837 0 -0.74162221 0.021950837 0 -0.74162221 -0.021950837 0 
		-0.74162221 0.021950837 0 -0.74162221 -0.021950837 0 -0.74162221 0.021950837 0 -0.74162221 
		-0.021950837 0 -0.74162221 0.021950837 0 -0.74162221 -0.021950837 0 -0.74162221 0.021950837 
		0 -0.74162221 0.021950837 0 -0.74162221 -0.021950837 0 -0.74162221 -0.021950837 0 
		-0.74162221 0.021950837 0 -0.74162221 -0.021950837 0 -0.74162221 0.021950837 0 -0.74162221 
		-0.021950837 0 -0.74162221;
createNode transform -n "book:pCube1" -p "book:Book";
	rename -uid "FA9E2493-4E69-81F2-75EA-A3AA37921C01";
	setAttr ".t" -type "double3" 0.37667354192084801 0.86413165184599317 0.55355055469309733 ;
	setAttr ".s" -type "double3" 6.4929167855246455 0.55352106928805289 5.0224925017220841 ;
createNode transform -n "book:transform2" -p "book:pCube1";
	rename -uid "7D32C047-4D29-364A-D1CA-AAB3FD638815";
	setAttr ".v" no;
createNode mesh -n "book:pCubeShape1" -p "book:transform2";
	rename -uid "1804ABB4-4142-D567-1A69-579280AC09D7";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.62499998509883881 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "book:Book1";
	rename -uid "A02F3EA2-4FC4-747B-9D1B-EE926B02AC36";
	setAttr ".t" -type "double3" -0.37667344516884782 -0.86413155286871302 -3.6307389181750622 ;
	setAttr ".s" -type "double3" 0.30402735982513068 0.30402735982513068 0.25959687190665476 ;
	setAttr ".rp" -type "double3" 0.37667344516884826 0.86413155286871302 3.6307389181750618 ;
	setAttr ".sp" -type "double3" 0.37667344516884826 0.86413155286871302 3.6307389181750618 ;
createNode mesh -n "book:Book1Shape" -p "book:Book1";
	rename -uid "C41CAB1D-4ECB-3138-B1AA-3BBF572E3FC8";
	setAttr -k off ".v";
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.36942781507968903 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".bw" 3;
	setAttr ".difs" yes;
createNode lightLinker -s -n "lightLinker1";
	rename -uid "7E3E6AFC-477D-A278-D721-11905B81CCED";
	setAttr -s 3 ".lnk";
	setAttr -s 3 ".slnk";
createNode shapeEditorManager -n "shapeEditorManager";
	rename -uid "B2139654-454A-BEB6-88DF-CEA6ADB00993";
createNode poseInterpolatorManager -n "poseInterpolatorManager";
	rename -uid "32E51EB4-4AAA-4A42-4360-3C8671A787CE";
createNode displayLayerManager -n "layerManager";
	rename -uid "4EEF0E39-459D-F03F-C928-E9A5BC06C958";
createNode displayLayer -n "defaultLayer";
	rename -uid "45D86949-4101-3F2D-C3A0-C8B00BB0C9F2";
createNode renderLayerManager -n "renderLayerManager";
	rename -uid "D5992724-4FE1-5D81-BF2E-0C9F29569DBB";
createNode renderLayer -n "defaultRenderLayer";
	rename -uid "2BAB7981-4BD2-8476-69FE-50B8CB25C14A";
	setAttr ".g" yes;
createNode file -n "groundplane";
	rename -uid "E827D49E-4B61-5242-F115-5087B7D2A5A2";
	setAttr ".ftn" -type "string" "C:/Estudios/Howest/DAE/DAE/3D/Final Assignment/1GD12E_AlejandroRoca_Diorama/Prop_ChairAndTable/sourceimages/tex_template.jpg";
	setAttr ".cs" -type "string" "sRGB";
createNode place2dTexture -n "place2dTexture1";
	rename -uid "BFC1C0F0-434E-E4CB-E469-768E4055FC74";
createNode aiOptions -s -n "defaultArnoldRenderOptions";
	rename -uid "E136054B-4DBB-0FA7-6DC0-D4979A9EB378";
	setAttr ".AA_samples" 1;
	setAttr ".GI_specular_samples" 0;
	setAttr ".GI_transmission_samples" 0;
	setAttr ".GI_sss_samples" 0;
	setAttr ".GI_volume_samples" 0;
	setAttr ".version" -type "string" "4.0.0";
createNode aiAOVFilter -s -n "defaultArnoldFilter";
	rename -uid "0262258D-4773-B67A-7D9F-7FB8CB7A5C70";
	setAttr ".ai_translator" -type "string" "gaussian";
createNode aiAOVDriver -s -n "defaultArnoldDriver";
	rename -uid "4532E5BF-4A3F-7D92-2BBA-94BE24C03C04";
	setAttr ".ai_translator" -type "string" "exr";
createNode aiAOVDriver -s -n "defaultArnoldDisplayDriver";
	rename -uid "5422F237-4B26-B17E-8427-4D8AE2C6A708";
	setAttr ".output_mode" 0;
	setAttr ".ai_translator" -type "string" "maya";
createNode aiStandardSurface -n "groundplane_shader";
	rename -uid "CE3CDA3E-4835-C5CF-8075-43B0F4D01388";
	setAttr ".specular" 0.24475523829460144;
	setAttr ".specular_roughness" 1;
createNode shadingEngine -n "aiStandardSurface1SG";
	rename -uid "7C96987F-40DA-3130-61A6-968CC09447C3";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "materialInfo2";
	rename -uid "64784839-49D1-F206-2E37-B28FC8B6B110";
createNode nodeGraphEditorInfo -n "hyperShadePrimaryNodeEditorSavedTabsInfo";
	rename -uid "D5B47428-432E-8712-39CF-9193F3585C26";
	setAttr ".tgi[0].tn" -type "string" "Untitled_1";
	setAttr ".tgi[0].vl" -type "double2" -301.31388888461095 343.18630246380752 ;
	setAttr ".tgi[0].vh" -type "double2" 1084.6154022410221 1488.4719224615171 ;
	setAttr -s 4 ".tgi[0].ni";
	setAttr ".tgi[0].ni[0].x" -15.714285850524902;
	setAttr ".tgi[0].ni[0].y" 1235.7142333984375;
	setAttr ".tgi[0].ni[0].nvs" 1923;
	setAttr ".tgi[0].ni[1].x" 640;
	setAttr ".tgi[0].ni[1].y" 1234.2857666015625;
	setAttr ".tgi[0].ni[1].nvs" 1923;
	setAttr ".tgi[0].ni[2].x" 291.42855834960938;
	setAttr ".tgi[0].ni[2].y" 1257.142822265625;
	setAttr ".tgi[0].ni[2].nvs" 2387;
	setAttr ".tgi[0].ni[3].x" -322.85714721679688;
	setAttr ".tgi[0].ni[3].y" 1212.857177734375;
	setAttr ".tgi[0].ni[3].nvs" 1923;
createNode script -n "uiConfigurationScriptNode";
	rename -uid "52EA78D6-4078-5B7F-C2A9-19B5A2DD8754";
	setAttr ".b" -type "string" (
		"// Maya Mel UI Configuration File.\n//\n//  This script is machine generated.  Edit at your own risk.\n//\n//\n\nglobal string $gMainPane;\nif (`paneLayout -exists $gMainPane`) {\n\n\tglobal int $gUseScenePanelConfig;\n\tint    $useSceneConfig = $gUseScenePanelConfig;\n\tint    $nodeEditorPanelVisible = stringArrayContains(\"nodeEditorPanel1\", `getPanel -vis`);\n\tint    $nodeEditorWorkspaceControlOpen = (`workspaceControl -exists nodeEditorPanel1Window` && `workspaceControl -q -visible nodeEditorPanel1Window`);\n\tint    $menusOkayInPanels = `optionVar -q allowMenusInPanels`;\n\tint    $nVisPanes = `paneLayout -q -nvp $gMainPane`;\n\tint    $nPanes = 0;\n\tstring $editorName;\n\tstring $panelName;\n\tstring $itemFilterName;\n\tstring $panelConfig;\n\n\t//\n\t//  get current state of the UI\n\t//\n\tsceneUIReplacement -update $gMainPane;\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Top View\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Top View\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"|top\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 32768\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n"
		+ "            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -controllers 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n"
		+ "            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 1\n            -height 1\n            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n"
		+ "\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Side View\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Side View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"|side\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n"
		+ "            -textureDisplay \"modulate\" \n            -textureMaxSize 32768\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n"
		+ "            -sortTransparent 1\n            -controllers 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 1\n            -height 1\n"
		+ "            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Front View\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Front View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"|front\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n"
		+ "            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 32768\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n"
		+ "            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -controllers 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n"
		+ "            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 1\n            -height 1\n            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Persp View\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Persp View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"|persp\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n"
		+ "            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 1\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 32768\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n"
		+ "            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -controllers 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n"
		+ "            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 1317\n            -height 694\n            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"outlinerPanel\" (localizedPanelLabel(\"ToggledOutliner\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\toutlinerPanel -edit -l (localizedPanelLabel(\"ToggledOutliner\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\t$editorName = $panelName;\n        outlinerEditor -e \n            -docTag \"isolOutln_fromSeln\" \n            -showShapes 0\n            -showAssignedMaterials 0\n            -showTimeEditor 1\n            -showReferenceNodes 1\n            -showReferenceMembers 1\n            -showAttributes 0\n            -showConnected 0\n            -showAnimCurvesOnly 0\n            -showMuteInfo 0\n            -organizeByLayer 1\n            -organizeByClip 1\n            -showAnimLayerWeight 1\n            -autoExpandLayers 1\n            -autoExpand 0\n            -showDagOnly 1\n            -showAssets 1\n            -showContainedOnly 1\n            -showPublishedAsConnected 0\n            -showParentContainers 0\n            -showContainerContents 1\n            -ignoreDagHierarchy 0\n            -expandConnections 0\n            -showUpstreamCurves 1\n            -showUnitlessCurves 1\n            -showCompounds 1\n            -showLeafs 1\n            -showNumericAttrsOnly 0\n            -highlightActive 1\n            -autoSelectNewObjects 0\n"
		+ "            -doNotSelectNewObjects 0\n            -dropIsParent 1\n            -transmitFilters 0\n            -setFilter \"defaultSetFilter\" \n            -showSetMembers 1\n            -allowMultiSelection 1\n            -alwaysToggleSelect 0\n            -directSelect 0\n            -isSet 0\n            -isSetMember 0\n            -displayMode \"DAG\" \n            -expandObjects 0\n            -setsIgnoreFilters 1\n            -containersIgnoreFilters 0\n            -editAttrName 0\n            -showAttrValues 0\n            -highlightSecondary 0\n            -showUVAttrsOnly 0\n            -showTextureNodesOnly 0\n            -attrAlphaOrder \"default\" \n            -animLayerFilterOptions \"allAffecting\" \n            -sortOrder \"none\" \n            -longNames 0\n            -niceNames 1\n            -selectCommand \"print(\\\"\\\")\" \n            -showNamespace 1\n            -showPinIcons 0\n            -mapMotionTrails 0\n            -ignoreHiddenAttribute 0\n            -ignoreOutlinerColor 0\n            -renderFilterVisible 0\n            -renderFilterIndex 0\n"
		+ "            -selectionOrder \"chronological\" \n            -expandAttribute 0\n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"outlinerPanel\" (localizedPanelLabel(\"Outliner\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\toutlinerPanel -edit -l (localizedPanelLabel(\"Outliner\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        outlinerEditor -e \n            -showShapes 0\n            -showAssignedMaterials 0\n            -showTimeEditor 1\n            -showReferenceNodes 0\n            -showReferenceMembers 0\n            -showAttributes 0\n            -showConnected 0\n            -showAnimCurvesOnly 0\n            -showMuteInfo 0\n            -organizeByLayer 1\n            -organizeByClip 1\n            -showAnimLayerWeight 1\n            -autoExpandLayers 1\n            -autoExpand 0\n            -showDagOnly 1\n            -showAssets 1\n            -showContainedOnly 1\n            -showPublishedAsConnected 0\n"
		+ "            -showParentContainers 0\n            -showContainerContents 1\n            -ignoreDagHierarchy 0\n            -expandConnections 0\n            -showUpstreamCurves 1\n            -showUnitlessCurves 1\n            -showCompounds 1\n            -showLeafs 1\n            -showNumericAttrsOnly 0\n            -highlightActive 1\n            -autoSelectNewObjects 0\n            -doNotSelectNewObjects 0\n            -dropIsParent 1\n            -transmitFilters 0\n            -setFilter \"defaultSetFilter\" \n            -showSetMembers 1\n            -allowMultiSelection 1\n            -alwaysToggleSelect 0\n            -directSelect 0\n            -displayMode \"DAG\" \n            -expandObjects 0\n            -setsIgnoreFilters 1\n            -containersIgnoreFilters 0\n            -editAttrName 0\n            -showAttrValues 0\n            -highlightSecondary 0\n            -showUVAttrsOnly 0\n            -showTextureNodesOnly 0\n            -attrAlphaOrder \"default\" \n            -animLayerFilterOptions \"allAffecting\" \n            -sortOrder \"none\" \n"
		+ "            -longNames 0\n            -niceNames 1\n            -showNamespace 1\n            -showPinIcons 0\n            -mapMotionTrails 0\n            -ignoreHiddenAttribute 0\n            -ignoreOutlinerColor 0\n            -renderFilterVisible 0\n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"graphEditor\" (localizedPanelLabel(\"Graph Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Graph Editor\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"OutlineEd\");\n            outlinerEditor -e \n                -showShapes 1\n                -showAssignedMaterials 0\n                -showTimeEditor 1\n                -showReferenceNodes 0\n                -showReferenceMembers 0\n                -showAttributes 1\n                -showConnected 1\n                -showAnimCurvesOnly 1\n                -showMuteInfo 0\n                -organizeByLayer 1\n"
		+ "                -organizeByClip 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 1\n                -showDagOnly 0\n                -showAssets 1\n                -showContainedOnly 0\n                -showPublishedAsConnected 0\n                -showParentContainers 0\n                -showContainerContents 0\n                -ignoreDagHierarchy 0\n                -expandConnections 1\n                -showUpstreamCurves 1\n                -showUnitlessCurves 1\n                -showCompounds 0\n                -showLeafs 1\n                -showNumericAttrsOnly 1\n                -highlightActive 0\n                -autoSelectNewObjects 1\n                -doNotSelectNewObjects 0\n                -dropIsParent 1\n                -transmitFilters 1\n                -setFilter \"0\" \n                -showSetMembers 0\n                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n"
		+ "                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                -showPinIcons 1\n                -mapMotionTrails 1\n                -ignoreHiddenAttribute 0\n                -ignoreOutlinerColor 0\n                -renderFilterVisible 0\n                $editorName;\n\n\t\t\t$editorName = ($panelName+\"GraphEd\");\n            animCurveEditor -e \n                -displayValues 0\n                -snapTime \"integer\" \n                -snapValue \"none\" \n                -showPlayRangeShades \"on\" \n                -lockPlayRangeShades \"off\" \n                -smoothness \"fine\" \n                -resultSamples 1\n"
		+ "                -resultScreenSamples 0\n                -resultUpdate \"delayed\" \n                -showUpstreamCurves 1\n                -keyMinScale 1\n                -stackedCurvesMin -1\n                -stackedCurvesMax 1\n                -stackedCurvesSpace 0.2\n                -preSelectionHighlight 0\n                -constrainDrag 0\n                -valueLinesToggle 1\n                -highlightAffectedCurves 0\n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"dopeSheetPanel\" (localizedPanelLabel(\"Dope Sheet\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Dope Sheet\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"OutlineEd\");\n            outlinerEditor -e \n                -showShapes 1\n                -showAssignedMaterials 0\n                -showTimeEditor 1\n                -showReferenceNodes 0\n                -showReferenceMembers 0\n"
		+ "                -showAttributes 1\n                -showConnected 1\n                -showAnimCurvesOnly 1\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -organizeByClip 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 0\n                -showDagOnly 0\n                -showAssets 1\n                -showContainedOnly 0\n                -showPublishedAsConnected 0\n                -showParentContainers 0\n                -showContainerContents 0\n                -ignoreDagHierarchy 0\n                -expandConnections 1\n                -showUpstreamCurves 1\n                -showUnitlessCurves 0\n                -showCompounds 1\n                -showLeafs 1\n                -showNumericAttrsOnly 1\n                -highlightActive 0\n                -autoSelectNewObjects 0\n                -doNotSelectNewObjects 1\n                -dropIsParent 1\n                -transmitFilters 0\n                -setFilter \"0\" \n                -showSetMembers 0\n"
		+ "                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                -showPinIcons 0\n                -mapMotionTrails 1\n                -ignoreHiddenAttribute 0\n                -ignoreOutlinerColor 0\n                -renderFilterVisible 0\n                $editorName;\n\n\t\t\t$editorName = ($panelName+\"DopeSheetEd\");\n            dopeSheetEditor -e \n                -displayValues 0\n                -snapTime \"integer\" \n"
		+ "                -snapValue \"none\" \n                -outliner \"dopeSheetPanel1OutlineEd\" \n                -showSummary 1\n                -showScene 0\n                -hierarchyBelow 0\n                -showTicks 1\n                -selectionWindow 0 0 0 0 \n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"timeEditorPanel\" (localizedPanelLabel(\"Time Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Time Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"clipEditorPanel\" (localizedPanelLabel(\"Trax Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Trax Editor\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = clipEditorNameFromPanel($panelName);\n"
		+ "            clipEditor -e \n                -displayValues 0\n                -snapTime \"none\" \n                -snapValue \"none\" \n                -initialized 0\n                -manageSequencer 0 \n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"sequenceEditorPanel\" (localizedPanelLabel(\"Camera Sequencer\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Camera Sequencer\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = sequenceEditorNameFromPanel($panelName);\n            clipEditor -e \n                -displayValues 0\n                -snapTime \"none\" \n                -snapValue \"none\" \n                -initialized 0\n                -manageSequencer 1 \n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"hyperGraphPanel\" (localizedPanelLabel(\"Hypergraph Hierarchy\")) `;\n"
		+ "\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Hypergraph Hierarchy\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"HyperGraphEd\");\n            hyperGraph -e \n                -graphLayoutStyle \"hierarchicalLayout\" \n                -orientation \"horiz\" \n                -mergeConnections 0\n                -zoom 1\n                -animateTransition 0\n                -showRelationships 1\n                -showShapes 0\n                -showDeformers 0\n                -showExpressions 0\n                -showConstraints 0\n                -showConnectionFromSelected 0\n                -showConnectionToSelected 0\n                -showConstraintLabels 0\n                -showUnderworld 0\n                -showInvisible 0\n                -transitionFrames 1\n                -opaqueContainers 0\n                -freeform 0\n                -imagePosition 0 0 \n                -imageScale 1\n                -imageEnabled 0\n                -graphType \"DAG\" \n"
		+ "                -heatMapDisplay 0\n                -updateSelection 1\n                -updateNodeAdded 1\n                -useDrawOverrideColor 0\n                -limitGraphTraversal -1\n                -range 0 0 \n                -iconSize \"smallIcons\" \n                -showCachedConnections 0\n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"hyperShadePanel\" (localizedPanelLabel(\"Hypershade\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Hypershade\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"visorPanel\" (localizedPanelLabel(\"Visor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Visor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n"
		+ "\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"nodeEditorPanel\" (localizedPanelLabel(\"Node Editor\")) `;\n\tif ($nodeEditorPanelVisible || $nodeEditorWorkspaceControlOpen) {\n\t\tif (\"\" == $panelName) {\n\t\t\tif ($useSceneConfig) {\n\t\t\t\t$panelName = `scriptedPanel -unParent  -type \"nodeEditorPanel\" -l (localizedPanelLabel(\"Node Editor\")) -mbv $menusOkayInPanels `;\n\n\t\t\t$editorName = ($panelName+\"NodeEditorEd\");\n            nodeEditor -e \n                -allAttributes 0\n                -allNodes 0\n                -autoSizeNodes 1\n                -consistentNameSize 1\n                -createNodeCommand \"nodeEdCreateNodeCommand\" \n                -connectNodeOnCreation 0\n                -connectOnDrop 0\n                -copyConnectionsOnPaste 0\n                -connectionStyle \"bezier\" \n                -defaultPinnedState 0\n                -additiveGraphingMode 0\n                -settingsChangedCallback \"nodeEdSyncControls\" \n                -traversalDepthLimit -1\n                -keyPressCommand \"nodeEdKeyPressCommand\" \n"
		+ "                -nodeTitleMode \"name\" \n                -gridSnap 0\n                -gridVisibility 1\n                -crosshairOnEdgeDragging 0\n                -popupMenuScript \"nodeEdBuildPanelMenus\" \n                -showNamespace 1\n                -showShapes 1\n                -showSGShapes 0\n                -showTransforms 1\n                -useAssets 1\n                -syncedSelection 1\n                -extendToShapes 1\n                -editorMode \"default\" \n                -hasWatchpoint 0\n                $editorName;\n\t\t\t}\n\t\t} else {\n\t\t\t$label = `panel -q -label $panelName`;\n\t\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Node Editor\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"NodeEditorEd\");\n            nodeEditor -e \n                -allAttributes 0\n                -allNodes 0\n                -autoSizeNodes 1\n                -consistentNameSize 1\n                -createNodeCommand \"nodeEdCreateNodeCommand\" \n                -connectNodeOnCreation 0\n                -connectOnDrop 0\n"
		+ "                -copyConnectionsOnPaste 0\n                -connectionStyle \"bezier\" \n                -defaultPinnedState 0\n                -additiveGraphingMode 0\n                -settingsChangedCallback \"nodeEdSyncControls\" \n                -traversalDepthLimit -1\n                -keyPressCommand \"nodeEdKeyPressCommand\" \n                -nodeTitleMode \"name\" \n                -gridSnap 0\n                -gridVisibility 1\n                -crosshairOnEdgeDragging 0\n                -popupMenuScript \"nodeEdBuildPanelMenus\" \n                -showNamespace 1\n                -showShapes 1\n                -showSGShapes 0\n                -showTransforms 1\n                -useAssets 1\n                -syncedSelection 1\n                -extendToShapes 1\n                -editorMode \"default\" \n                -hasWatchpoint 0\n                $editorName;\n\t\t\tif (!$useSceneConfig) {\n\t\t\t\tpanel -e -l $label $panelName;\n\t\t\t}\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"createNodePanel\" (localizedPanelLabel(\"Create Node\")) `;\n"
		+ "\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Create Node\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"polyTexturePlacementPanel\" (localizedPanelLabel(\"UV Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"UV Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"renderWindowPanel\" (localizedPanelLabel(\"Render View\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Render View\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"shapePanel\" (localizedPanelLabel(\"Shape Editor\")) `;\n"
		+ "\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tshapePanel -edit -l (localizedPanelLabel(\"Shape Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"posePanel\" (localizedPanelLabel(\"Pose Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tposePanel -edit -l (localizedPanelLabel(\"Pose Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"dynRelEdPanel\" (localizedPanelLabel(\"Dynamic Relationships\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Dynamic Relationships\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"relationshipPanel\" (localizedPanelLabel(\"Relationship Editor\")) `;\n"
		+ "\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Relationship Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"referenceEditorPanel\" (localizedPanelLabel(\"Reference Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Reference Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"componentEditorPanel\" (localizedPanelLabel(\"Component Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Component Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"dynPaintScriptedPanelType\" (localizedPanelLabel(\"Paint Effects\")) `;\n"
		+ "\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Paint Effects\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"scriptEditorPanel\" (localizedPanelLabel(\"Script Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Script Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"profilerPanel\" (localizedPanelLabel(\"Profiler Tool\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Profiler Tool\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"contentBrowserPanel\" (localizedPanelLabel(\"Content Browser\")) `;\n"
		+ "\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Content Browser\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"Stereo\" (localizedPanelLabel(\"Stereo\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Stereo\")) -mbv $menusOkayInPanels  $panelName;\n{ string $editorName = ($panelName+\"Editor\");\n            stereoCameraView -e \n                -camera \"|persp\" \n                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"wireframe\" \n                -activeOnly 0\n                -ignorePanZoom 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n                -holdOuts 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 1\n"
		+ "                -backfaceCulling 0\n                -xray 0\n                -jointXray 0\n                -activeComponentsXray 0\n                -displayTextures 0\n                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 32768\n                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n                -depthOfFieldPreview 1\n                -maxConstantTransparency 1\n                -objectFilterShowInHUD 1\n                -isFiltered 0\n                -colorResolution 4 4 \n                -bumpResolution 4 4 \n                -textureCompression 0\n                -transparencyAlgorithm \"frontAndBackCull\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n"
		+ "                -lowQualityLighting 0\n                -maximumNumHardwareLights 0\n                -occlusionCulling 0\n                -shadingModel 0\n                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -controllers 1\n                -nurbsCurves 1\n                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n                -hulls 1\n                -grid 1\n                -imagePlane 1\n                -joints 1\n                -ikHandles 1\n                -deformers 1\n                -dynamics 1\n                -particleInstancers 1\n                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n"
		+ "                -nParticles 1\n                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n                -pluginShapes 1\n                -dimensions 1\n                -handles 1\n                -pivots 1\n                -textures 1\n                -strokes 1\n                -motionTrails 1\n                -clipGhosts 1\n                -greasePencils 1\n                -shadows 0\n                -captureSequenceNumber -1\n                -width 0\n                -height 0\n                -sceneRenderFilter 0\n                -displayMode \"centerEye\" \n                -viewColor 0 0 0 1 \n                -useCustomBackground 1\n                $editorName;\n            stereoCameraView -e -viewSelected 0 $editorName;\n            stereoCameraView -e \n                -pluginObjects \"gpuCacheDisplayFilter\" 1 \n                $editorName; };\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\tif ($useSceneConfig) {\n        string $configName = `getPanel -cwl (localizedPanelLabel(\"Current Layout\"))`;\n"
		+ "        if (\"\" != $configName) {\n\t\t\tpanelConfiguration -edit -label (localizedPanelLabel(\"Current Layout\")) \n\t\t\t\t-userCreated false\n\t\t\t\t-defaultImage \"vacantCell.xP:/\"\n\t\t\t\t-image \"\"\n\t\t\t\t-sc false\n\t\t\t\t-configString \"global string $gMainPane; paneLayout -e -cn \\\"single\\\" -ps 1 100 100 $gMainPane;\"\n\t\t\t\t-removeAllPanels\n\t\t\t\t-ap false\n\t\t\t\t\t(localizedPanelLabel(\"Persp View\")) \n\t\t\t\t\t\"modelPanel\"\n"
		+ "\t\t\t\t\t\"$panelName = `modelPanel -unParent -l (localizedPanelLabel(\\\"Persp View\\\")) -mbv $menusOkayInPanels `;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -cam `findStartUpCamera persp` \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"smoothShaded\\\" \\n    -activeOnly 0\\n    -ignorePanZoom 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -holdOuts 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 0\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 1\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 32768\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -depthOfFieldPreview 1\\n    -maxConstantTransparency 1\\n    -rendererName \\\"vp2Renderer\\\" \\n    -objectFilterShowInHUD 1\\n    -isFiltered 0\\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -controllers 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -imagePlane 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -particleInstancers 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -pluginShapes 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -motionTrails 1\\n    -clipGhosts 1\\n    -greasePencils 1\\n    -shadows 0\\n    -captureSequenceNumber -1\\n    -width 1317\\n    -height 694\\n    -sceneRenderFilter 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName;\\nmodelEditor -e \\n    -pluginObjects \\\"gpuCacheDisplayFilter\\\" 1 \\n    $editorName\"\n"
		+ "\t\t\t\t\t\"modelPanel -edit -l (localizedPanelLabel(\\\"Persp View\\\")) -mbv $menusOkayInPanels  $panelName;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -cam `findStartUpCamera persp` \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"smoothShaded\\\" \\n    -activeOnly 0\\n    -ignorePanZoom 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -holdOuts 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 0\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 1\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 32768\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -depthOfFieldPreview 1\\n    -maxConstantTransparency 1\\n    -rendererName \\\"vp2Renderer\\\" \\n    -objectFilterShowInHUD 1\\n    -isFiltered 0\\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -controllers 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -imagePlane 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -particleInstancers 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -pluginShapes 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -motionTrails 1\\n    -clipGhosts 1\\n    -greasePencils 1\\n    -shadows 0\\n    -captureSequenceNumber -1\\n    -width 1317\\n    -height 694\\n    -sceneRenderFilter 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName;\\nmodelEditor -e \\n    -pluginObjects \\\"gpuCacheDisplayFilter\\\" 1 \\n    $editorName\"\n"
		+ "\t\t\t\t$configName;\n\n            setNamedPanelLayout (localizedPanelLabel(\"Current Layout\"));\n        }\n\n        panelHistory -e -clear mainPanelHistory;\n        sceneUIReplacement -clear;\n\t}\n\n\ngrid -spacing 5 -size 12 -divisions 5 -displayAxes yes -displayGridLines yes -displayDivisionLines yes -displayPerspectiveLabels no -displayOrthographicLabels no -displayAxesBold yes -perspectiveLabelPosition axis -orthographicLabelPosition edge;\nviewManip -drawCompass 0 -compassAngle 0 -frontParameters \"\" -homeParameters \"\" -selectionLockParameters \"\";\n}\n");
	setAttr ".st" 3;
createNode script -n "sceneConfigurationScriptNode";
	rename -uid "B974DBF3-4293-F109-E37E-96A1B02E6C8A";
	setAttr ".b" -type "string" "playbackOptions -min 1 -max 120 -ast 1 -aet 200 ";
	setAttr ".st" 6;
createNode deleteComponent -n "book:deleteComponent44";
	rename -uid "D0751535-445C-27ED-056D-C697774385C8";
	setAttr ".dc" -type "componentList" 1 "f[0]";
createNode deleteComponent -n "book:deleteComponent43";
	rename -uid "21727C3E-4164-D61B-D65B-1897671FC6AE";
	setAttr ".dc" -type "componentList" 1 "f[1]";
createNode deleteComponent -n "book:deleteComponent42";
	rename -uid "C90B061B-4A34-C450-126E-65BF9DF3BFEC";
	setAttr ".dc" -type "componentList" 1 "f[0]";
createNode deleteComponent -n "book:deleteComponent41";
	rename -uid "516A53B8-417E-EC05-E273-81976525CE0B";
	setAttr ".dc" -type "componentList" 1 "f[1]";
createNode deleteComponent -n "book:deleteComponent40";
	rename -uid "AA744C5D-4782-CA45-41F1-0EB4B4936C0C";
	setAttr ".dc" -type "componentList" 1 "f[4]";
createNode deleteComponent -n "book:deleteComponent39";
	rename -uid "D5F4CDEB-4FFE-2207-4439-9C993FF7A681";
	setAttr ".dc" -type "componentList" 1 "f[3]";
createNode deleteComponent -n "book:deleteComponent38";
	rename -uid "2317C769-4E2B-5EAC-F3E7-FBB08495F0AC";
	setAttr ".dc" -type "componentList" 1 "f[0]";
createNode deleteComponent -n "book:deleteComponent37";
	rename -uid "EF29D054-49F7-9172-59E6-8EB6A43EB9F1";
	setAttr ".dc" -type "componentList" 1 "f[1]";
createNode deleteComponent -n "book:deleteComponent36";
	rename -uid "96C718EF-40AD-1DB9-B28B-9F9E583CA053";
	setAttr ".dc" -type "componentList" 5 "f[0]" "f[2]" "f[5]" "f[7]" "f[12]";
createNode deleteComponent -n "book:deleteComponent35";
	rename -uid "C7E6E291-4628-9947-7410-8CB290F310B0";
	setAttr ".dc" -type "componentList" 1 "f[1]";
createNode deleteComponent -n "book:deleteComponent34";
	rename -uid "03BE4235-4401-FA40-A6B3-7687A54B559B";
	setAttr ".dc" -type "componentList" 1 "f[4]";
createNode deleteComponent -n "book:deleteComponent33";
	rename -uid "ADD528B1-4753-9D28-5A9A-D28C2A3B8148";
	setAttr ".dc" -type "componentList" 1 "f[6]";
createNode deleteComponent -n "book:deleteComponent32";
	rename -uid "603467D1-41B2-8194-3A56-3BA5D6E76594";
	setAttr ".dc" -type "componentList" 1 "f[1]";
createNode deleteComponent -n "book:deleteComponent31";
	rename -uid "78018DB2-4DEE-FCCF-9BFB-F5AE7F985E85";
	setAttr ".dc" -type "componentList" 1 "f[9]";
createNode deleteComponent -n "book:deleteComponent30";
	rename -uid "766CF45E-419B-4860-6DBA-C99F61FC6B0B";
	setAttr ".dc" -type "componentList" 1 "f[9]";
createNode deleteComponent -n "book:deleteComponent29";
	rename -uid "A779CC20-424C-FB4F-F4AF-12AD03B5FEF9";
	setAttr ".dc" -type "componentList" 1 "f[1]";
createNode deleteComponent -n "book:deleteComponent28";
	rename -uid "17468D75-4AEA-C9A6-366B-D599B4117261";
	setAttr ".dc" -type "componentList" 1 "f[11]";
createNode deleteComponent -n "book:deleteComponent27";
	rename -uid "F8D6A446-4A25-4A9C-B67B-598C6195645E";
	setAttr ".dc" -type "componentList" 1 "f[5]";
createNode deleteComponent -n "book:deleteComponent26";
	rename -uid "AD20B800-4DCE-475A-D1E8-AF8E3C76D586";
	setAttr ".dc" -type "componentList" 1 "f[22]";
createNode deleteComponent -n "book:deleteComponent25";
	rename -uid "380B6403-4192-401F-D418-AD8979DC97F2";
	setAttr ".dc" -type "componentList" 1 "f[10]";
createNode deleteComponent -n "book:deleteComponent24";
	rename -uid "69F05A64-4CC9-A49C-646E-83923F87D633";
	setAttr ".dc" -type "componentList" 1 "f[11]";
createNode deleteComponent -n "book:deleteComponent23";
	rename -uid "1A7E388A-489B-7872-777D-3BB5FD7424E3";
	setAttr ".dc" -type "componentList" 1 "f[24]";
createNode deleteComponent -n "book:deleteComponent22";
	rename -uid "149F3347-455C-25F1-CE61-9BAFAA14DA98";
	setAttr ".dc" -type "componentList" 1 "f[24]";
createNode deleteComponent -n "book:deleteComponent21";
	rename -uid "91D05973-4CBC-55A2-7B75-76B5AD956BED";
	setAttr ".dc" -type "componentList" 1 "f[5]";
createNode deleteComponent -n "book:deleteComponent20";
	rename -uid "7DE37353-4E96-1D0D-DB6E-288E5CAA70B8";
	setAttr ".dc" -type "componentList" 1 "f[26]";
createNode deleteComponent -n "book:deleteComponent19";
	rename -uid "5BA83893-4F61-A3DB-FB24-86BEB64E5290";
	setAttr ".dc" -type "componentList" 1 "f[13]";
createNode deleteComponent -n "book:deleteComponent18";
	rename -uid "7C787AD1-4501-4B4D-953D-81B3E55A7F23";
	setAttr ".dc" -type "componentList" 1 "f[29]";
createNode deleteComponent -n "book:deleteComponent17";
	rename -uid "5325A099-4B48-2EEC-0EFC-58A696B420D8";
	setAttr ".dc" -type "componentList" 1 "f[0]";
createNode polyTweak -n "book:polyTweak51";
	rename -uid "6F448BE1-4897-6E23-5C43-D19F6D1F5F2C";
	setAttr ".uopa" yes;
	setAttr -s 40 ".tk";
	setAttr ".tk[9]" -type "float3" 0 0 -5.9604645e-08 ;
	setAttr ".tk[13]" -type "float3" 0 0 -5.9604645e-08 ;
	setAttr ".tk[18]" -type "float3" 0 0 -5.9604645e-08 ;
	setAttr ".tk[19]" -type "float3" 0 0 -5.9604645e-08 ;
	setAttr ".tk[36]" -type "float3" -0.30709827 0.39870754 -0.20061541 ;
	setAttr ".tk[37]" -type "float3" -3.2608597 0.39870727 2.0434499 ;
	setAttr ".tk[38]" -type "float3" -2.0505099 0.39888388 4.228581 ;
	setAttr ".tk[39]" -type "float3" 0.90325338 0.39888385 1.9845166 ;
	setAttr ".tk[40]" -type "float3" -1.9832022 0.54422075 4.3500962 ;
	setAttr ".tk[41]" -type "float3" 0.97056109 0.54422081 2.1060326 ;
	setAttr ".tk[42]" -type "float3" 0.96523887 0.46274617 2.0964241 ;
	setAttr ".tk[43]" -type "float3" -1.9885242 0.46274608 4.3404865 ;
	setAttr ".tk[44]" -type "float3" 0.90325338 0.64576733 1.9845164 ;
	setAttr ".tk[45]" -type "float3" -2.0505099 0.64576727 4.2285805 ;
	setAttr ".tk[46]" -type "float3" -3.2608597 0.6459437 2.0434501 ;
	setAttr ".tk[47]" -type "float3" -0.30709827 0.64594364 -0.20061684 ;
	setAttr ".tk[48]" -type "float3" 0.95041567 0.61537397 2.0696626 ;
	setAttr ".tk[49]" -type "float3" -2.0033474 0.61537385 4.3137264 ;
	setAttr ".tk[50]" -type "float3" -0.30709827 0.4171119 -0.20061636 ;
	setAttr ".tk[51]" -type "float3" 0.90206343 0.41711184 1.9823685 ;
	setAttr ".tk[52]" -type "float3" -2.0516999 0.41711196 4.2264323 ;
	setAttr ".tk[53]" -type "float3" -3.2608597 0.41711205 2.0434484 ;
	setAttr ".tk[54]" -type "float3" 0.90206343 0.62753916 1.9823682 ;
	setAttr ".tk[55]" -type "float3" -0.30709827 0.62753922 -0.20061588 ;
	setAttr ".tk[56]" -type "float3" -3.2608597 0.62753898 2.0434499 ;
	setAttr ".tk[57]" -type "float3" -2.0516999 0.62753904 4.2264328 ;
	setAttr ".tk[58]" -type "float3" 0.95418459 0.46965441 2.076467 ;
	setAttr ".tk[59]" -type "float3" -1.9995782 0.46965429 4.3205299 ;
	setAttr ".tk[60]" -type "float3" 0.95847946 0.54242539 2.0842199 ;
	setAttr ".tk[61]" -type "float3" -1.9952841 0.54242545 4.3282833 ;
	setAttr ".tk[62]" -type "float3" 0.94195491 0.60261023 2.0543888 ;
	setAttr ".tk[63]" -type "float3" -2.0118079 0.60261023 4.2984514 ;
	setAttr ".tk[64]" -type "float3" -1.986712 0.41711187 4.1774435 ;
	setAttr ".tk[65]" -type "float3" -1.986712 0.62753904 4.1774435 ;
	setAttr ".tk[66]" -type "float3" 0.83737379 0.62753904 2.0318973 ;
	setAttr ".tk[67]" -type "float3" 0.83737379 0.41711187 2.0318973 ;
	setAttr ".tk[68]" -type "float3" -3.1577604 0.41711187 2.0632672 ;
	setAttr ".tk[69]" -type "float3" -0.3336758 0.41711187 -0.082281098 ;
	setAttr ".tk[70]" -type "float3" -0.3336758 0.62753904 -0.082281098 ;
	setAttr ".tk[71]" -type "float3" -3.1577604 0.62753904 2.0632672 ;
createNode polyExtrudeFace -n "book:polyExtrudeFace43";
	rename -uid "23E39877-42A1-5892-EBA0-1E8B898D2C12";
	setAttr ".ics" -type "componentList" 1 "f[0:31]";
	setAttr ".ix" -type "matrix" 0.30402735982513068 0 0 0 0 0.30402735982513068 0 0
		 0 0 0.25959687190665476 0 0.26215441211792723 -0.13652628885408502 2.688210452307064 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 0.3766734 0.12619333 3.630739 ;
	setAttr ".rs" 48849;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" -0.61033869362146165 0.027331529819463407 2.9726037749176246 ;
	setAttr ".cbx" -type "double3" 1.3636855204956215 0.225055135683082 4.2888740902178943 ;
	setAttr ".raf" no;
createNode polyDelEdge -n "book:polyDelEdge19";
	rename -uid "B9AC290D-43A7-E48B-67D7-C98015FA9C6C";
	setAttr ".ics" -type "componentList" 6 "e[55]" "e[60]" "e[62]" "e[64:65]" "e[75]" "e[77:78]";
	setAttr ".cv" yes;
createNode polyDelEdge -n "book:polyDelEdge18";
	rename -uid "5B7C610B-4189-51BA-E890-A8B15C8B05C9";
	setAttr ".ics" -type "componentList" 5 "e[62]" "e[64]" "e[67]" "e[81]" "e[91]";
	setAttr ".cv" yes;
createNode polyNormal -n "book:polyNormal1";
	rename -uid "14ADC815-4441-DE79-2765-39AB75096342";
	setAttr ".ics" -type "componentList" 1 "f[34:36]";
	setAttr ".unm" no;
createNode deleteComponent -n "book:deleteComponent16";
	rename -uid "4F46CE76-43B8-91EA-30CE-4BA4D6A1B99D";
	setAttr ".dc" -type "componentList" 1 "vtx[31]";
createNode polyDelEdge -n "book:polyDelEdge17";
	rename -uid "62CEB9B2-49E7-BC65-7357-7693F449BC3C";
	setAttr ".ics" -type "componentList" 5 "e[68]" "e[70]" "e[75]" "e[90]" "e[101]";
	setAttr ".cv" yes;
createNode polyDelEdge -n "book:polyDelEdge16";
	rename -uid "DE38E8AB-4A41-9052-1495-7692E3075CF6";
	setAttr ".ics" -type "componentList" 1 "e[90]";
	setAttr ".cv" yes;
createNode polyDelEdge -n "book:polyDelEdge15";
	rename -uid "FDD1EFE6-4AFE-2AF2-0D11-F18AD7B6F3FE";
	setAttr ".ics" -type "componentList" 4 "e[73]" "e[78]" "e[81]" "e[109]";
	setAttr ".cv" yes;
createNode polyDelEdge -n "book:polyDelEdge14";
	rename -uid "8D1C2F3B-4395-44CA-BEBA-F4968BF4A467";
	setAttr ".ics" -type "componentList" 8 "e[54]" "e[57]" "e[59]" "e[65]" "e[70]" "e[76]" "e[98]" "e[100:101]";
	setAttr ".cv" yes;
createNode polyDelEdge -n "book:polyDelEdge13";
	rename -uid "6248F25E-4491-16A7-6D16-B9B3717A19A1";
	setAttr ".ics" -type "componentList" 3 "e[14]" "e[46]" "e[48:49]";
	setAttr ".cv" yes;
createNode polyDelEdge -n "book:polyDelEdge12";
	rename -uid "3E9B86D1-4189-A4A4-3A71-8A9ED5E6B07D";
	setAttr ".ics" -type "componentList" 11 "e[8]" "e[16]" "e[24]" "e[30]" "e[42:44]" "e[63]" "e[65:66]" "e[75]" "e[77:78]" "e[85]" "e[87:88]";
	setAttr ".cv" yes;
createNode polyDelEdge -n "book:polyDelEdge11";
	rename -uid "E4F35D0A-422D-86F8-0C66-D4B1641D1847";
	setAttr ".ics" -type "componentList" 24 "e[54:62]" "e[74:82]" "e[95:103]" "e[136:144]" "e[157:165]" "e[198:206]" "e[218:226]" "e[228:236]" "e[248:256]" "e[269:277]" "e[289:297]" "e[310:318]" "e[330:338]" "e[351:359]" "e[361:369]" "e[371:379]" "e[391:399]" "e[412:420]" "e[432:440]" "e[453:461]" "e[473:481]" "e[494:502]" "e[504:512]" "e[514:522]";
	setAttr ".cv" yes;
createNode groupParts -n "book:groupParts3";
	rename -uid "174A5272-41BB-EF75-4953-F8959983FC4A";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:299]";
createNode polyUnite -n "book:polyUnite1";
	rename -uid "9B340F5F-4D5B-544F-178A-EB85035DEDDB";
	setAttr -s 2 ".ip";
	setAttr -s 2 ".im";
createNode groupId -n "book:groupId1";
	rename -uid "1972F177-4775-9B81-A617-949B63BEBDF4";
	setAttr ".ihi" 0;
createNode groupParts -n "book:groupParts1";
	rename -uid "58619771-4261-8B47-E0A9-8F9B98F32421";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:261]";
createNode polyExtrudeFace -n "book:polyExtrudeFace1";
	rename -uid "6BECFBBE-45B7-9713-C445-339FFD28D915";
	setAttr ".ics" -type "componentList" 1 "f[0:10]";
	setAttr ".ix" -type "matrix" 6.4929167855246455 0 0 0 0 0.55352106928805289 0 0 0 0 5.0224925017220841 0
		 0.37667354192084801 0.86413165184599317 0.55355055469309733 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 0.37667346 0.86413163 0.5535503 ;
	setAttr ".rs" 37704;
	setAttr ".lt" -type "double3" 0 0 0.048413596944092419 ;
	setAttr ".d" 10;
	setAttr ".tp" 11.1724;
	setAttr ".c[0]"  0 1 1;
	setAttr ".sma" 3.0822;
	setAttr ".cbn" -type "double3" -2.8697848508414747 0.58737111720196666 -1.9576956961679448 ;
	setAttr ".cbx" -type "double3" 3.6231317411791713 1.1408921205051663 3.0647963565083169 ;
createNode deleteComponent -n "book:deleteComponent3";
	rename -uid "16EC9423-4846-5051-F5B1-BC878D4908CA";
	setAttr ".dc" -type "componentList" 1 "f[11]";
createNode deleteComponent -n "book:deleteComponent2";
	rename -uid "55AB8D98-4B88-952B-BA7A-5794411EA459";
	setAttr ".dc" -type "componentList" 1 "f[0]";
createNode deleteComponent -n "book:deleteComponent1";
	rename -uid "56B4956D-402E-EEB8-0ACF-B580CBE14CC6";
	setAttr ".dc" -type "componentList" 1 "f[12]";
createNode polyBevel3 -n "book:polyBevel1";
	rename -uid "34016E48-4E82-E00D-05CF-548FA49AA939";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[2:3]";
	setAttr ".ix" -type "matrix" 6.4929167855246455 0 0 0 0 0.55352106928805289 0 0 0 0 5.0224925017220841 0
		 0.37667354192084801 0.86413165184599317 0.55355055469309733 1;
	setAttr ".ws" yes;
	setAttr ".oaf" yes;
	setAttr ".f" 0.80904522595749284;
	setAttr ".sg" 4;
	setAttr ".at" 180;
	setAttr ".sn" yes;
	setAttr ".mv" yes;
	setAttr ".mvt" 0.0001;
	setAttr ".sa" 30;
createNode polyCube -n "book:polyCube1";
	rename -uid "1CEA06D4-4B94-C824-FFAD-FA97C4B2F862";
	setAttr ".cuv" 4;
createNode groupId -n "book:groupId2";
	rename -uid "D1FFEC84-4EE2-A7BA-9E9D-D4AA1C6E3F3B";
	setAttr ".ihi" 0;
createNode groupId -n "book:groupId3";
	rename -uid "50DEEE48-47E7-24A7-89C4-DC9196A714F2";
	setAttr ".ihi" 0;
createNode groupParts -n "book:groupParts2";
	rename -uid "E49BA18B-4E45-BBE6-4EE3-028D56B5DC75";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:37]";
createNode polyExtrudeFace -n "book:polyExtrudeFace2";
	rename -uid "8BA93627-4567-30E1-ADD8-CB890C017AF5";
	setAttr ".ics" -type "componentList" 1 "f[0:8]";
	setAttr ".ix" -type "matrix" 6.4929167855246455 0 0 0 0 0.55352106928805289 0 0 0 0 5.0224925017220841 0
		 0.37667354192084801 0.86413165184599317 6.7593330918643657 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 0.37667346 0.86413163 4.3600316 ;
	setAttr ".rs" 39993;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" -2.8697848508414747 0.58737111720196666 4.2480868410033237 ;
	setAttr ".cbx" -type "double3" 3.6231317411791713 1.1408921205051663 4.4719761484373866 ;
	setAttr ".raf" no;
createNode groupId -n "book:groupId4";
	rename -uid "06A78A9B-4F07-1595-9F5E-9DB54957BE7B";
	setAttr ".ihi" 0;
createNode groupId -n "book:groupId5";
	rename -uid "8A679FE4-4313-6E35-4117-358C857737A9";
	setAttr ".ihi" 0;
select -ne :time1;
	setAttr ".o" 1;
	setAttr ".unw" 1;
select -ne :hardwareRenderingGlobals;
	setAttr ".otfna" -type "stringArray" 22 "NURBS Curves" "NURBS Surfaces" "Polygons" "Subdiv Surface" "Particles" "Particle Instance" "Fluids" "Strokes" "Image Planes" "UI" "Lights" "Cameras" "Locators" "Joints" "IK Handles" "Deformers" "Motion Trails" "Components" "Hair Systems" "Follicles" "Misc. UI" "Ornaments"  ;
	setAttr ".otfva" -type "Int32Array" 22 0 1 1 1 1 1
		 1 1 1 0 0 0 0 0 0 0 0 0
		 0 0 0 0 ;
	setAttr ".fprt" yes;
select -ne :renderPartition;
	setAttr -s 3 ".st";
select -ne :renderGlobalsList1;
select -ne :defaultShaderList1;
	setAttr -s 6 ".s";
select -ne :postProcessList1;
	setAttr -s 2 ".p";
select -ne :defaultRenderUtilityList1;
select -ne :defaultRenderingList1;
select -ne :lightList1;
select -ne :defaultTextureList1;
select -ne :standardSurface1;
	setAttr ".s" 0;
select -ne :initialShadingGroup;
	setAttr -s 5 ".dsm";
	setAttr ".ro" yes;
	setAttr -s 5 ".gn";
select -ne :initialParticleSE;
	setAttr ".ro" yes;
select -ne :defaultRenderGlobals;
	addAttr -ci true -h true -sn "dss" -ln "defaultSurfaceShader" -dt "string";
	setAttr ".ren" -type "string" "arnold";
	setAttr ".outf" 51;
	setAttr ".imfkey" -type "string" "exr";
	setAttr ".dss" -type "string" "lambert1";
select -ne :defaultResolution;
	setAttr ".w" 1024;
	setAttr ".h" 1024;
	setAttr ".pa" 1;
	setAttr ".dar" 1;
select -ne :defaultLightSet;
select -ne :defaultColorMgtGlobals;
	setAttr ".cfe" yes;
	setAttr ".cfp" -type "string" "<MAYA_RESOURCES>/OCIO-configs/Maya-legacy/config.ocio";
	setAttr ".vtn" -type "string" "sRGB gamma (legacy)";
	setAttr ".vn" -type "string" "sRGB gamma";
	setAttr ".dn" -type "string" "legacy";
	setAttr ".wsn" -type "string" "scene-linear Rec 709/sRGB";
	setAttr ".ovt" no;
	setAttr ".povt" no;
	setAttr ".otn" -type "string" "sRGB gamma (legacy)";
	setAttr ".potn" -type "string" "sRGB gamma (legacy)";
select -ne :hardwareRenderGlobals;
	setAttr ".ctrs" 256;
	setAttr ".btrs" 512;
select -ne :ikSystem;
	setAttr -s 4 ".sol";
connectAttr "book:groupId3.id" "book:pCubeShape2.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "book:pCubeShape2.iog.og[0].gco";
connectAttr "book:groupParts2.og" "book:pCubeShape2.i";
connectAttr "book:groupId4.id" "book:pCubeShape2.ciog.cog[0].cgid";
connectAttr "book:groupId1.id" "book:pCubeShape1.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "book:pCubeShape1.iog.og[0].gco";
connectAttr "book:groupParts1.og" "book:pCubeShape1.i";
connectAttr "book:groupId2.id" "book:pCubeShape1.ciog.cog[0].cgid";
connectAttr "book:deleteComponent44.og" "book:Book1Shape.i";
connectAttr "book:groupId5.id" "book:Book1Shape.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "book:Book1Shape.iog.og[0].gco";
relationship "link" ":lightLinker1" ":initialShadingGroup.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" ":initialParticleSE.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "aiStandardSurface1SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" ":initialShadingGroup.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" ":initialParticleSE.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "aiStandardSurface1SG.message" ":defaultLightSet.message";
connectAttr "layerManager.dli[0]" "defaultLayer.id";
connectAttr "renderLayerManager.rlmi[0]" "defaultRenderLayer.rlid";
connectAttr ":defaultColorMgtGlobals.cme" "groundplane.cme";
connectAttr ":defaultColorMgtGlobals.cfe" "groundplane.cmcf";
connectAttr ":defaultColorMgtGlobals.cfp" "groundplane.cmcp";
connectAttr ":defaultColorMgtGlobals.wsn" "groundplane.ws";
connectAttr "place2dTexture1.c" "groundplane.c";
connectAttr "place2dTexture1.tf" "groundplane.tf";
connectAttr "place2dTexture1.rf" "groundplane.rf";
connectAttr "place2dTexture1.mu" "groundplane.mu";
connectAttr "place2dTexture1.mv" "groundplane.mv";
connectAttr "place2dTexture1.s" "groundplane.s";
connectAttr "place2dTexture1.wu" "groundplane.wu";
connectAttr "place2dTexture1.wv" "groundplane.wv";
connectAttr "place2dTexture1.re" "groundplane.re";
connectAttr "place2dTexture1.of" "groundplane.of";
connectAttr "place2dTexture1.r" "groundplane.ro";
connectAttr "place2dTexture1.n" "groundplane.n";
connectAttr "place2dTexture1.vt1" "groundplane.vt1";
connectAttr "place2dTexture1.vt2" "groundplane.vt2";
connectAttr "place2dTexture1.vt3" "groundplane.vt3";
connectAttr "place2dTexture1.vc1" "groundplane.vc1";
connectAttr "place2dTexture1.o" "groundplane.uv";
connectAttr "place2dTexture1.ofs" "groundplane.fs";
connectAttr ":defaultArnoldDisplayDriver.msg" ":defaultArnoldRenderOptions.drivers"
		 -na;
connectAttr ":defaultArnoldFilter.msg" ":defaultArnoldRenderOptions.filt";
connectAttr ":defaultArnoldDriver.msg" ":defaultArnoldRenderOptions.drvr";
connectAttr "groundplane.oc" "groundplane_shader.base_color";
connectAttr "groundplane_shader.out" "aiStandardSurface1SG.ss";
connectAttr "groundplane_GeoShape.iog" "aiStandardSurface1SG.dsm" -na;
connectAttr "aiStandardSurface1SG.msg" "materialInfo2.sg";
connectAttr "groundplane_shader.msg" "materialInfo2.m";
connectAttr "groundplane_shader.msg" "materialInfo2.t" -na;
connectAttr "groundplane.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[0].dn"
		;
connectAttr "aiStandardSurface1SG.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[1].dn"
		;
connectAttr "groundplane_shader.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[2].dn"
		;
connectAttr "place2dTexture1.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[3].dn"
		;
connectAttr "book:deleteComponent43.og" "book:deleteComponent44.ig";
connectAttr "book:deleteComponent42.og" "book:deleteComponent43.ig";
connectAttr "book:deleteComponent41.og" "book:deleteComponent42.ig";
connectAttr "book:deleteComponent40.og" "book:deleteComponent41.ig";
connectAttr "book:deleteComponent39.og" "book:deleteComponent40.ig";
connectAttr "book:deleteComponent38.og" "book:deleteComponent39.ig";
connectAttr "book:deleteComponent37.og" "book:deleteComponent38.ig";
connectAttr "book:deleteComponent36.og" "book:deleteComponent37.ig";
connectAttr "book:deleteComponent35.og" "book:deleteComponent36.ig";
connectAttr "book:deleteComponent34.og" "book:deleteComponent35.ig";
connectAttr "book:deleteComponent33.og" "book:deleteComponent34.ig";
connectAttr "book:deleteComponent32.og" "book:deleteComponent33.ig";
connectAttr "book:deleteComponent31.og" "book:deleteComponent32.ig";
connectAttr "book:deleteComponent30.og" "book:deleteComponent31.ig";
connectAttr "book:deleteComponent29.og" "book:deleteComponent30.ig";
connectAttr "book:deleteComponent28.og" "book:deleteComponent29.ig";
connectAttr "book:deleteComponent27.og" "book:deleteComponent28.ig";
connectAttr "book:deleteComponent26.og" "book:deleteComponent27.ig";
connectAttr "book:deleteComponent25.og" "book:deleteComponent26.ig";
connectAttr "book:deleteComponent24.og" "book:deleteComponent25.ig";
connectAttr "book:deleteComponent23.og" "book:deleteComponent24.ig";
connectAttr "book:deleteComponent22.og" "book:deleteComponent23.ig";
connectAttr "book:deleteComponent21.og" "book:deleteComponent22.ig";
connectAttr "book:deleteComponent20.og" "book:deleteComponent21.ig";
connectAttr "book:deleteComponent19.og" "book:deleteComponent20.ig";
connectAttr "book:deleteComponent18.og" "book:deleteComponent19.ig";
connectAttr "book:deleteComponent17.og" "book:deleteComponent18.ig";
connectAttr "book:polyTweak51.out" "book:deleteComponent17.ig";
connectAttr "book:polyExtrudeFace43.out" "book:polyTweak51.ip";
connectAttr "book:polyDelEdge19.out" "book:polyExtrudeFace43.ip";
connectAttr "book:Book1Shape.wm" "book:polyExtrudeFace43.mp";
connectAttr "book:polyDelEdge18.out" "book:polyDelEdge19.ip";
connectAttr "book:polyNormal1.out" "book:polyDelEdge18.ip";
connectAttr "book:deleteComponent16.og" "book:polyNormal1.ip";
connectAttr "book:polyDelEdge17.out" "book:deleteComponent16.ig";
connectAttr "book:polyDelEdge16.out" "book:polyDelEdge17.ip";
connectAttr "book:polyDelEdge15.out" "book:polyDelEdge16.ip";
connectAttr "book:polyDelEdge14.out" "book:polyDelEdge15.ip";
connectAttr "book:polyDelEdge13.out" "book:polyDelEdge14.ip";
connectAttr "book:polyDelEdge12.out" "book:polyDelEdge13.ip";
connectAttr "book:polyDelEdge11.out" "book:polyDelEdge12.ip";
connectAttr "book:groupParts3.og" "book:polyDelEdge11.ip";
connectAttr "book:polyUnite1.out" "book:groupParts3.ig";
connectAttr "book:groupId5.id" "book:groupParts3.gi";
connectAttr "book:pCubeShape1.o" "book:polyUnite1.ip[0]";
connectAttr "book:pCubeShape2.o" "book:polyUnite1.ip[1]";
connectAttr "book:pCubeShape1.wm" "book:polyUnite1.im[0]";
connectAttr "book:pCubeShape2.wm" "book:polyUnite1.im[1]";
connectAttr "book:polyExtrudeFace1.out" "book:groupParts1.ig";
connectAttr "book:groupId1.id" "book:groupParts1.gi";
connectAttr "book:deleteComponent3.og" "book:polyExtrudeFace1.ip";
connectAttr "book:pCubeShape1.wm" "book:polyExtrudeFace1.mp";
connectAttr "book:deleteComponent2.og" "book:deleteComponent3.ig";
connectAttr "book:deleteComponent1.og" "book:deleteComponent2.ig";
connectAttr "book:polyBevel1.out" "book:deleteComponent1.ig";
connectAttr "book:polyCube1.out" "book:polyBevel1.ip";
connectAttr "book:pCubeShape1.wm" "book:polyBevel1.mp";
connectAttr "book:polyExtrudeFace2.out" "book:groupParts2.ig";
connectAttr "book:groupId3.id" "book:groupParts2.gi";
connectAttr "book:polySurfaceShape1.o" "book:polyExtrudeFace2.ip";
connectAttr "book:pCubeShape2.wm" "book:polyExtrudeFace2.mp";
connectAttr "aiStandardSurface1SG.pa" ":renderPartition.st" -na;
connectAttr "groundplane_shader.msg" ":defaultShaderList1.s" -na;
connectAttr "place2dTexture1.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "defaultRenderLayer.msg" ":defaultRenderingList1.r" -na;
connectAttr "Skydome_lShape.ltd" ":lightList1.l" -na;
connectAttr "groundplane.msg" ":defaultTextureList1.tx" -na;
connectAttr "book:pCubeShape1.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "book:pCubeShape1.ciog.cog[0]" ":initialShadingGroup.dsm" -na;
connectAttr "book:pCubeShape2.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "book:pCubeShape2.ciog.cog[0]" ":initialShadingGroup.dsm" -na;
connectAttr "book:Book1Shape.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "book:groupId1.msg" ":initialShadingGroup.gn" -na;
connectAttr "book:groupId2.msg" ":initialShadingGroup.gn" -na;
connectAttr "book:groupId3.msg" ":initialShadingGroup.gn" -na;
connectAttr "book:groupId4.msg" ":initialShadingGroup.gn" -na;
connectAttr "book:groupId5.msg" ":initialShadingGroup.gn" -na;
connectAttr "Skydome_l.iog" ":defaultLightSet.dsm" -na;
// End of 1GD12E_AlejandroRoca_Books.000.ma
