//Maya ASCII 2022 scene
//Name: 1GD12E_AlejandroRoca_WateringCan.000.ma
//Last modified: Sat, Jul 23, 2022 10:26:18 AM
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
fileInfo "UUID" "C461113F-452D-01E5-3514-8AA2F09F8340";
fileInfo "license" "education";
createNode transform -s -n "persp";
	rename -uid "CBB20537-40F8-A23F-4B21-26837A14FFF1";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 6.9465785535410314 6.4544922526502795 8.8303173697163384 ;
	setAttr ".r" -type "double3" -27.338352729616261 -337.79999999989855 8.5880109316749759e-16 ;
createNode camera -s -n "perspShape" -p "persp";
	rename -uid "6CB0EF23-4C47-136F-7BC7-2C89212700F0";
	setAttr -k off ".v" no;
	setAttr ".fl" 34.999999999999993;
	setAttr ".coi" 15.063996798230754;
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
createNode transform -n "wateringCan:Watering_Can";
	rename -uid "B2FD974B-4F65-C53E-B8EE-51BBCC5E9C49";
	setAttr ".t" -type "double3" 5.7510818507466865e-07 1.58550273805161 -1.7008244146410334e-08 ;
	setAttr ".s" -type "double3" 0.09635524844015908 0.09635524844015908 0.09635524844015908 ;
	setAttr ".rp" -type "double3" -5.751081851803538e-07 -1.5855027380516105 1.7008244093593522e-08 ;
	setAttr ".sp" -type "double3" -4.5160936217314429e-06 -12.450316398566557 1.3355911576695689e-07 ;
	setAttr ".spt" -type "double3" 3.9409854365510891e-06 10.864813660515049 -1.1655099846553419e-07 ;
createNode transform -n "wateringCan:transform9" -p "wateringCan:Watering_Can";
	rename -uid "FF898399-4DFA-FCE6-B07B-1FBF1ACB786C";
	setAttr ".v" no;
createNode mesh -n "wateringCan:Watering_CanShape" -p "wateringCan:transform9";
	rename -uid "852C521B-404A-F042-3989-688207E2EDC4";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.48958338797092438 0.37434034049510956 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 52 ".pt";
	setAttr ".pt[5]" -type "float3" 9.5367432e-07 0 0 ;
	setAttr ".pt[6]" -type "float3" 9.5367432e-07 0 0 ;
	setAttr ".pt[73]" -type "float3" 0.2112087 -0.012094613 -0.12194166 ;
	setAttr ".pt[76]" -type "float3" 0.12194192 -0.012094613 -0.21120918 ;
	setAttr ".pt[79]" -type "float3" -1.0572053e-08 -0.012094613 -0.24388294 ;
	setAttr ".pt[82]" -type "float3" -0.12194157 -0.012094613 -0.21120918 ;
	setAttr ".pt[85]" -type "float3" -0.21120922 -0.012094613 -0.12194166 ;
	setAttr ".pt[88]" -type "float3" -0.24388315 -0.012094613 -6.3432211e-08 ;
	setAttr ".pt[89]" -type "float3" 9.5367432e-07 0 0 ;
	setAttr ".pt[91]" -type "float3" -0.21120922 -0.012094613 0.12194169 ;
	setAttr ".pt[92]" -type "float3" 9.5367432e-07 0 0 ;
	setAttr ".pt[94]" -type "float3" -0.12194157 -0.012094613 0.21120918 ;
	setAttr ".pt[97]" -type "float3" -1.0572053e-08 -0.012094613 0.24388294 ;
	setAttr ".pt[100]" -type "float3" 0.12194192 -0.012094613 0.21120918 ;
	setAttr ".pt[103]" -type "float3" 0.2112087 -0.012094613 0.12194169 ;
	setAttr ".pt[106]" -type "float3" 0.24388315 -0.012094613 -6.3432211e-08 ;
	setAttr ".pt[109]" -type "float3" 0.2112087 0.0120946 -0.12194166 ;
	setAttr ".pt[112]" -type "float3" 0.12194192 0.0120946 -0.21120918 ;
	setAttr ".pt[115]" -type "float3" -1.0572053e-08 0.0120946 -0.24388294 ;
	setAttr ".pt[118]" -type "float3" -0.12194157 0.0120946 -0.21120918 ;
	setAttr ".pt[121]" -type "float3" -0.21120922 0.0120946 -0.12194166 ;
	setAttr ".pt[124]" -type "float3" -0.24388315 0.0120946 -6.3432211e-08 ;
	setAttr ".pt[127]" -type "float3" -0.21120922 0.0120946 0.12194169 ;
	setAttr ".pt[130]" -type "float3" -0.12194157 0.0120946 0.21120918 ;
	setAttr ".pt[133]" -type "float3" -1.0572053e-08 0.0120946 0.24388294 ;
	setAttr ".pt[136]" -type "float3" 0.12194192 0.0120946 0.21120918 ;
	setAttr ".pt[139]" -type "float3" 0.2112087 0.0120946 0.12194169 ;
	setAttr ".pt[142]" -type "float3" 0.24388315 0.0120946 -6.3432211e-08 ;
	setAttr ".pt[144]" -type "float3" -2.4437904e-06 1.8626451e-09 5.9604645e-08 ;
	setAttr ".pt[145]" -type "float3" -2.8312206e-07 1.8626451e-09 -5.9604645e-08 ;
	setAttr ".pt[146]" -type "float3" -2.4437904e-06 1.8626451e-09 5.9604645e-08 ;
	setAttr ".pt[147]" -type "float3" -2.8312206e-07 1.8626451e-09 -5.9604645e-08 ;
	setAttr ".pt[148]" -type "float3" -1.0658141e-14 1.8626451e-09 0 ;
	setAttr ".pt[149]" -type "float3" -4.3213367e-07 1.8626451e-09 -5.9604645e-08 ;
	setAttr ".pt[150]" -type "float3" 5.364418e-07 1.8626451e-09 5.9604645e-08 ;
	setAttr ".pt[151]" -type "float3" -4.7683716e-07 1.8626451e-09 -1.4210855e-14 ;
	setAttr ".pt[152]" -type "float3" 5.364418e-07 1.8626451e-09 -1.7881393e-07 ;
	setAttr ".pt[153]" -type "float3" -4.3213367e-07 1.8626451e-09 1.1920929e-07 ;
	setAttr ".pt[154]" -type "float3" -1.0658141e-14 1.8626451e-09 0 ;
	setAttr ".pt[155]" -type "float3" -2.8312206e-07 1.8626451e-09 1.1920929e-07 ;
	setAttr ".pt[156]" -type "float3" -2.4437904e-06 1.8626451e-09 -1.7881393e-07 ;
	setAttr ".pt[157]" -type "float3" 4.7683716e-07 1.8626451e-09 -1.4210855e-14 ;
	setAttr ".pt[158]" -type "float3" -1.0658141e-14 1.8626451e-09 0 ;
	setAttr ".pt[159]" -type "float3" -4.3213367e-07 1.8626451e-09 -5.9604645e-08 ;
	setAttr ".pt[160]" -type "float3" 5.364418e-07 1.8626451e-09 5.9604645e-08 ;
	setAttr ".pt[161]" -type "float3" -4.7683716e-07 1.8626451e-09 -1.4210855e-14 ;
	setAttr ".pt[162]" -type "float3" 5.364418e-07 1.8626451e-09 -1.7881393e-07 ;
	setAttr ".pt[163]" -type "float3" -4.3213367e-07 1.8626451e-09 1.1920929e-07 ;
	setAttr ".pt[164]" -type "float3" -1.0658141e-14 1.8626451e-09 0 ;
	setAttr ".pt[165]" -type "float3" -2.8312206e-07 1.8626451e-09 1.1920929e-07 ;
	setAttr ".pt[166]" -type "float3" -2.4437904e-06 1.8626451e-09 -1.7881393e-07 ;
	setAttr ".pt[167]" -type "float3" 4.7683716e-07 1.8626451e-09 -1.4210855e-14 ;
	setAttr ".dr" 1;
createNode transform -n "wateringCan:pCube3";
	rename -uid "F5775ED8-4854-85E4-D32F-73964FDB2F63";
	setAttr ".t" -type "double3" 0.24317493112249505 2.3173201672394028 -1.0199010019870325 ;
	setAttr ".r" -type "double3" 0 -13.44686317484242 0 ;
	setAttr ".s" -type "double3" 1.2884750674861092 1 1 ;
	setAttr ".rp" -type "double3" 0.0068962470668727733 -0.54636617004871368 -0.55698785185813904 ;
	setAttr ".rpt" -type "double3" 0.15727547681195733 0 0.024699705813344255 ;
	setAttr ".sp" -type "double3" 0.0053522549569606781 -0.54636617004871368 -0.55698785185813904 ;
	setAttr ".spt" -type "double3" 0.0015439921099120952 0 0 ;
createNode transform -n "wateringCan:transform7" -p "wateringCan:pCube3";
	rename -uid "03C873A0-444D-6BCE-3DBB-34AB612F26F3";
	setAttr ".v" no;
createNode mesh -n "wateringCan:pCubeShape3" -p "wateringCan:transform7";
	rename -uid "4C4DE32A-4667-64C0-0502-3C9187422BA4";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.375 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 60 ".pt[28:87]" -type "float3"  1.1175871e-08 0 0 1.1175871e-08 
		0 0 1.1175871e-08 0 0 1.1175871e-08 0 0 1.1175871e-08 0 0 1.1175871e-08 0 0 1.1175871e-08 
		0 0 1.1175871e-08 0 0 1.1175871e-08 0 0 1.1175871e-08 0 0 1.1175871e-08 0 0 1.1175871e-08 
		0 0 1.1175871e-08 0 0 1.1175871e-08 0 0 1.1175871e-08 0 0 1.1175871e-08 0 0 1.1175871e-08 
		0 0 1.1175871e-08 0 0 1.1175871e-08 0 0 1.1175871e-08 0 0 1.1175871e-08 0 0 1.1175871e-08 
		0 0 1.1175871e-08 0 0 1.1175871e-08 0 0 1.1175871e-08 0 0 1.1175871e-08 0 0 1.1175871e-08 
		0 0 1.1175871e-08 0 0 1.1175871e-08 0 0 1.1175871e-08 0 0 1.1175871e-08 0 0 1.1175871e-08 
		0 0 1.1175871e-08 0 0 1.1175871e-08 0 0 1.1175871e-08 0 0 1.1175871e-08 0 0 1.1175871e-08 
		0 0 1.1175871e-08 0 0 1.1175871e-08 0 0 1.1175871e-08 0 0 1.1175871e-08 0 0 1.1175871e-08 
		0 0 1.1175871e-08 0 0 1.1175871e-08 0 0 1.1175871e-08 0 0 1.1175871e-08 0 0 1.1175871e-08 
		0 0 1.1175871e-08 0 0 1.1175871e-08 0 0 1.1175871e-08 0 0 1.1175871e-08 0 0 1.1175871e-08 
		0 0 1.1175871e-08 0 0 1.1175871e-08 0 0 1.1175871e-08 0 0 1.1175871e-08 0 0 1.1175871e-08 
		-0.21803279 0 1.1175871e-08 -0.21803279 0 1.1175871e-08 -0.21803279 0 1.1175871e-08 
		-0.21803279 0;
createNode transform -n "wateringCan:pCube4";
	rename -uid "B7FDC0F0-4C58-65DE-D626-2CB7A30BB261";
	setAttr ".t" -type "double3" 1.016336118328915 2.324 0.23993364926932581 ;
	setAttr ".r" -type "double3" 0 -14.731624716455526 0 ;
createNode transform -n "wateringCan:transform4" -p "wateringCan:pCube4";
	rename -uid "5E8D97CB-4E7E-5B3A-ACD3-02AB919B2640";
	setAttr ".v" no;
createNode mesh -n "wateringCan:pCubeShape4" -p "wateringCan:transform4";
	rename -uid "588E1776-4B00-9A60-22CC-679FD20D51B3";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.375 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 16 ".pt[44:59]" -type "float3"  0.0076020062 0.033066511 
		-0.0034397542 0.0076020062 0.033066511 -0.0034397542 0.0076020062 0.033066511 -0.0034397542 
		0.0076020062 0.033066511 -0.0034397542 0.052642047 0.0065728426 1.4901161e-08 0.052642047 
		0.0065728426 1.4901161e-08 0.052642047 0.0065728426 1.4901161e-08 0.052642047 0.0065728426 
		1.4901161e-08 0.052642047 0.030677401 1.4901161e-08 0.052642047 0.030677401 1.4901161e-08 
		0.052642047 0.030677401 1.4901161e-08 0.052642047 0.030677401 1.4901161e-08 -0.1811872 
		0.034094457 2.8312206e-07 -0.20114538 0.031916451 2.8312206e-07 -0.20114522 0.031916488 
		2.8312206e-07 -0.18118733 0.034094516 2.8312206e-07;
	setAttr ".dr" 1;
createNode transform -n "wateringCan:pCube5";
	rename -uid "0DE16055-4000-30EE-B8A6-19901E23DCA9";
	setAttr ".t" -type "double3" -0.99172346767163222 2.3221583906416736 -0.31528816172042406 ;
	setAttr ".r" -type "double3" 0 164.60600393033474 0 ;
createNode transform -n "wateringCan:transform3" -p "wateringCan:pCube5";
	rename -uid "3BA457CE-4127-7619-6DF5-00B2960F362A";
	setAttr ".v" no;
createNode mesh -n "wateringCan:pCubeShape5" -p "wateringCan:transform3";
	rename -uid "A5A204A3-4881-17F8-E057-78B3015B6684";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[2].gcl" -type "componentList" 1 "f[0:57]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.375 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 66 ".uvst[0].uvsp[0:65]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25 0.375 0.25 0.625 0.25 0.625 0.5 0.375 0.5 0.375 0.25
		 0.625 0.25 0.625 0.5 0.375 0.5 0.375 0.25 0.625 0.25 0.625 0.5 0.375 0.5 0.375 0.25
		 0.625 0.25 0.625 0.5 0.375 0.5 0.375 0.25 0.625 0.25 0.625 0.5 0.375 0.5 0.375 0.25
		 0.625 0.25 0.625 0.5 0.375 0.5 0.375 0.25 0.625 0.25 0.625 0.5 0.375 0.5 0.375 0.25
		 0.625 0.25 0.625 0.5 0.375 0.5 0.375 0.25 0.625 0.25 0.625 0.5 0.375 0.5 0.375 0.25
		 0.625 0.25 0.625 0.5 0.375 0.5 0.375 0.25 0.625 0.25 0.625 0.5 0.375 0.5 0.375 0.25
		 0.625 0.25 0.625 0.5 0.375 0.5 0.375 0.25 0.625 0.25 0.625 0.5 0.375 0.5;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 16 ".pt[44:59]" -type "float3"  0.0076020062 0.033066511 
		-0.0034397542 0.0076020062 0.033066511 -0.0034397542 0.0076020062 0.033066511 -0.0034397542 
		0.0076020062 0.033066511 -0.0034397542 0.052642047 0.0065728426 1.4901161e-08 0.052642047 
		0.0065728426 1.4901161e-08 0.052642047 0.0065728426 1.4901161e-08 0.052642047 0.0065728426 
		1.4901161e-08 0.052642047 0.030677401 1.4901161e-08 0.052642047 0.030677401 1.4901161e-08 
		0.052642047 0.030677401 1.4901161e-08 0.052642047 0.030677401 1.4901161e-08 -0.18866539 
		0.032799378 2.8125942e-07 -0.19366726 0.03321147 2.8125942e-07 -0.19366717 0.033211432 
		2.8125942e-07 -0.18866536 0.032799512 2.8125942e-07;
	setAttr -s 60 ".vt[0:59]"  -0.019999981 -0.099999905 0.15000004 0.019999981 -0.099999905 0.15000001
		 -0.019999981 0.099999905 0.15000004 0.019999981 0.099999905 0.15000001 -0.019999981 0.099999905 -0.14999986
		 0.019999981 0.099999905 -0.14999998 -0.019999981 -0.099999905 -0.14999986 0.019999981 -0.099999905 -0.14999998
		 -0.0044441223 0.13546395 0.14590986 0.035555959 0.13546395 0.14591014 0.035555959 0.13546395 -0.15408993
		 -0.0044441223 0.13546395 -0.15409017 0.019299626 0.18225503 0.14590999 0.059300184 0.18225503 0.14590985
		 0.059300184 0.18225503 -0.15409012 0.019300103 0.18225503 -0.15409 0.045926571 0.26064134 0.14590997
		 0.085891604 0.26231194 0.14590988 0.085891604 0.26231194 -0.15409009 0.045926452 0.26064134 -0.15409014
		 0.071619034 0.35954928 0.14423832 0.11129928 0.36460209 0.14423808 0.1112994 0.36460209 -0.15576196
		 0.07161963 0.35954928 -0.15576182 0.072847247 0.45471764 0.14423814 0.11252677 0.45977044 0.14423811
		 0.11252689 0.45977044 -0.15576202 0.072846651 0.45471764 -0.15576178 0.046913624 0.61191273 0.14423823
		 0.086592436 0.61696577 0.14423826 0.08659327 0.61696577 -0.15576196 0.046913624 0.61191273 -0.15576175
		 0.028618455 0.67649674 0.14423835 0.06609273 0.69048429 0.1442382 0.066093206 0.69048429 -0.15576196
		 0.028618693 0.67649674 -0.15576181 -0.02525413 0.80914068 0.14423811 0.0085133314 0.83058262 0.14423802
		 0.0085132122 0.83058262 -0.15576205 -0.025254726 0.80914068 -0.15576193 -0.1523037 1.0092225075 0.14423822
		 -0.11853623 1.030664444 0.14423798 -0.11853641 1.030664444 -0.15576208 -0.15230393 1.0092225075 -0.15576193
		 -0.33745337 1.1690774 0.14423846 -0.31522274 1.20233107 0.14423817 -0.31522304 1.20233107 -0.15576184
		 -0.33745337 1.1690774 -0.15576178 -0.61975574 1.35848808 0.14423843 -0.60606241 1.39607143 0.14423826
		 -0.60606241 1.3960712 -0.15576184 -0.61975574 1.35848808 -0.15576178 -0.9175005 1.40670085 0.14423873
		 -0.91172194 1.44628143 0.14423855 -0.91172194 1.44628119 -0.15576154 -0.91750062 1.40670085 -0.15576144
		 -0.9175005 1.40670085 0.14423873 -0.91172194 1.44628143 0.14423855 -0.91172194 1.44628119 -0.15576154
		 -0.91750062 1.40670085 -0.15576144;
	setAttr -s 116 ".ed[0:115]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0 2 8 0 3 9 0 8 9 0 5 10 0 9 10 0 4 11 0 11 10 0 8 11 0
		 8 12 0 9 13 0 12 13 0 10 14 0 13 14 0 11 15 0 15 14 0 12 15 0 12 16 0 13 17 0 16 17 0
		 14 18 0 17 18 0 15 19 0 19 18 0 16 19 0 16 20 0 17 21 0 20 21 0 18 22 0 21 22 0 19 23 0
		 23 22 0 20 23 0 20 24 0 21 25 0 24 25 0 22 26 0 25 26 0 23 27 0 27 26 0 24 27 0 24 28 0
		 25 29 0 28 29 0 26 30 0 29 30 0 27 31 0 31 30 0 28 31 0 28 32 0 29 33 0 32 33 0 30 34 0
		 33 34 0 31 35 0 35 34 0 32 35 0 32 36 0 33 37 0 36 37 0 34 38 0 37 38 0 35 39 0 39 38 0
		 36 39 0 36 40 0 37 41 0 40 41 0 38 42 0 41 42 0 39 43 0 43 42 0 40 43 0 40 44 0 41 45 0
		 44 45 0 42 46 0 45 46 0 43 47 0 47 46 0 44 47 0 44 48 0 45 49 0 48 49 0 46 50 0 49 50 0
		 47 51 0 51 50 0 48 51 0 48 52 0 49 53 0 52 53 0 50 54 0 53 54 0 51 55 0 55 54 0 52 55 0
		 52 56 0 53 57 0 56 57 0 54 58 0 57 58 0 55 59 0 59 58 0 56 59 0;
	setAttr -s 58 -ch 232 ".fc[0:57]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 110 112 -115 -116
		mu 0 4 62 63 64 65
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13
		f 4 1 13 -15 -13
		mu 0 4 2 3 15 14
		f 4 7 15 -17 -14
		mu 0 4 3 5 16 15
		f 4 -3 17 18 -16
		mu 0 4 5 4 17 16
		f 4 -7 12 19 -18
		mu 0 4 4 2 14 17
		f 4 14 21 -23 -21
		mu 0 4 14 15 19 18
		f 4 16 23 -25 -22
		mu 0 4 15 16 20 19
		f 4 -19 25 26 -24
		mu 0 4 16 17 21 20
		f 4 -20 20 27 -26
		mu 0 4 17 14 18 21
		f 4 22 29 -31 -29
		mu 0 4 18 19 23 22
		f 4 24 31 -33 -30
		mu 0 4 19 20 24 23
		f 4 -27 33 34 -32
		mu 0 4 20 21 25 24
		f 4 -28 28 35 -34
		mu 0 4 21 18 22 25
		f 4 30 37 -39 -37
		mu 0 4 22 23 27 26
		f 4 32 39 -41 -38
		mu 0 4 23 24 28 27
		f 4 -35 41 42 -40
		mu 0 4 24 25 29 28
		f 4 -36 36 43 -42
		mu 0 4 25 22 26 29
		f 4 38 45 -47 -45
		mu 0 4 26 27 31 30
		f 4 40 47 -49 -46
		mu 0 4 27 28 32 31
		f 4 -43 49 50 -48
		mu 0 4 28 29 33 32
		f 4 -44 44 51 -50
		mu 0 4 29 26 30 33
		f 4 46 53 -55 -53
		mu 0 4 30 31 35 34
		f 4 48 55 -57 -54
		mu 0 4 31 32 36 35
		f 4 -51 57 58 -56
		mu 0 4 32 33 37 36
		f 4 -52 52 59 -58
		mu 0 4 33 30 34 37
		f 4 54 61 -63 -61
		mu 0 4 34 35 39 38
		f 4 56 63 -65 -62
		mu 0 4 35 36 40 39
		f 4 -59 65 66 -64
		mu 0 4 36 37 41 40
		f 4 -60 60 67 -66
		mu 0 4 37 34 38 41
		f 4 62 69 -71 -69
		mu 0 4 38 39 43 42
		f 4 64 71 -73 -70
		mu 0 4 39 40 44 43
		f 4 -67 73 74 -72
		mu 0 4 40 41 45 44
		f 4 -68 68 75 -74
		mu 0 4 41 38 42 45
		f 4 70 77 -79 -77
		mu 0 4 42 43 47 46
		f 4 72 79 -81 -78
		mu 0 4 43 44 48 47
		f 4 -75 81 82 -80
		mu 0 4 44 45 49 48
		f 4 -76 76 83 -82
		mu 0 4 45 42 46 49
		f 4 78 85 -87 -85
		mu 0 4 46 47 51 50
		f 4 80 87 -89 -86
		mu 0 4 47 48 52 51
		f 4 -83 89 90 -88
		mu 0 4 48 49 53 52
		f 4 -84 84 91 -90
		mu 0 4 49 46 50 53
		f 4 86 93 -95 -93
		mu 0 4 50 51 55 54
		f 4 88 95 -97 -94
		mu 0 4 51 52 56 55
		f 4 -91 97 98 -96
		mu 0 4 52 53 57 56
		f 4 -92 92 99 -98
		mu 0 4 53 50 54 57
		f 4 94 101 -103 -101
		mu 0 4 54 55 59 58
		f 4 96 103 -105 -102
		mu 0 4 55 56 60 59
		f 4 -99 105 106 -104
		mu 0 4 56 57 61 60
		f 4 -100 100 107 -106
		mu 0 4 57 54 58 61
		f 4 102 109 -111 -109
		mu 0 4 58 59 63 62
		f 4 104 111 -113 -110
		mu 0 4 59 60 64 63
		f 4 -107 113 114 -112
		mu 0 4 60 61 65 64
		f 4 -108 108 115 -114
		mu 0 4 61 58 62 65;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".dr" 1;
createNode transform -n "wateringCan:pCube6";
	rename -uid "08D36F21-4CA3-0DFD-09C3-EC85ED24A644";
	setAttr ".rp" -type "double3" 0.011586751308864662 3.0121782091262261 -0.038080017934908755 ;
	setAttr ".sp" -type "double3" 0.011586751308864662 3.0121782091262261 -0.038080017934908755 ;
createNode transform -n "wateringCan:transform8" -p "wateringCan:pCube6";
	rename -uid "A6FAB068-4E1B-9037-ED2A-BEB7C109D70A";
	setAttr ".v" no;
createNode mesh -n "wateringCan:pCube6Shape" -p "wateringCan:transform8";
	rename -uid "AF7E1DEB-4361-DA58-C9D2-77BCBE976A4D";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "wateringCan:pCylinder1";
	rename -uid "B5527790-42E0-8D38-A19D-13A434151CF3";
	setAttr ".t" -type "double3" -0.26765260328674439 0.47581163900773871 0.93300546418808539 ;
	setAttr ".r" -type "double3" 48.264745361562575 -13.723889756133348 0.26987538832643132 ;
createNode transform -n "wateringCan:transform6" -p "wateringCan:pCylinder1";
	rename -uid "DE026DF8-4D1C-F679-7AFA-CABF15E5F80B";
	setAttr ".v" no;
createNode mesh -n "wateringCan:pCylinderShape1" -p "wateringCan:transform6";
	rename -uid "EBA7CD6D-4D48-3096-4D7C-E58EF0B88DA9";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.50471152365207672 0.84375 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 10 ".pt[59:68]" -type "float3"  0.095493287 0.13344336 -0.08012861 
		0.021646276 0.13344336 -0.12276301 -3.4092227e-07 0.13344336 2.1935557e-07 -0.062328942 
		0.13344336 -0.10795623 -0.11713883 0.13344336 -0.042635337 -0.11713883 0.13344336 
		0.042635977 -0.062328838 0.13344336 0.1079556 0.021646064 0.13344336 0.12276307 0.095493287 
		0.13344336 0.080128849 0.1246579 0.13344336 4.6782952e-07;
	setAttr -av ".pt[50].px";
	setAttr -av ".pt[50].py";
	setAttr -av ".pt[50].pz";
	setAttr -av ".pt[59].px";
	setAttr -av ".pt[59].py";
	setAttr -av ".pt[59].pz";
	setAttr -av ".pt[60].px";
	setAttr -av ".pt[60].py";
	setAttr -av ".pt[60].pz";
	setAttr -av ".pt[61].px";
	setAttr -av ".pt[61].py";
	setAttr -av ".pt[61].pz";
	setAttr -av ".pt[62].px";
	setAttr -av ".pt[62].py";
	setAttr -av ".pt[62].pz";
	setAttr -av ".pt[63].px";
	setAttr -av ".pt[63].py";
	setAttr -av ".pt[63].pz";
	setAttr -av ".pt[64].px";
	setAttr -av ".pt[64].py";
	setAttr -av ".pt[64].pz";
	setAttr -av ".pt[65].px";
	setAttr -av ".pt[65].py";
	setAttr -av ".pt[65].pz";
	setAttr -av ".pt[66].px";
	setAttr -av ".pt[66].py";
	setAttr -av ".pt[66].pz";
	setAttr -av ".pt[67].px";
	setAttr -av ".pt[67].py";
	setAttr -av ".pt[67].pz";
	setAttr -av ".pt[68].px";
	setAttr -av ".pt[68].py";
	setAttr -av ".pt[68].pz";
createNode transform -n "wateringCan:pCylinder2";
	rename -uid "76254580-4D22-4117-BAD7-E19D79AB4D33";
	setAttr ".t" -type "double3" -0.31612477903457492 2.1409157753065799 1.2134521065923689 ;
	setAttr ".r" -type "double3" -68.441959272233419 -17.363128539001163 4.7227992212064951 ;
createNode transform -n "wateringCan:transform5" -p "wateringCan:pCylinder2";
	rename -uid "1E5B8308-4795-E3C4-321B-5D992A2ECFCB";
	setAttr ".v" no;
createNode mesh -n "wateringCan:pCylinderShape2" -p "wateringCan:transform5";
	rename -uid "1B91B8FA-4F44-24B9-1063-C6B2455B09D4";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.1562500074505806 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 9 ".pt";
	setAttr ".pt[0]" -type "float3" 0 -0.74064636 0 ;
	setAttr ".pt[1]" -type "float3" 6.2349169e-18 -0.74064636 0 ;
	setAttr ".pt[2]" -type "float3" 0 -0.74064636 0 ;
	setAttr ".pt[3]" -type "float3" 0 -0.74064636 -3.122134e-08 ;
	setAttr ".pt[4]" -type "float3" 0 -0.74064636 0 ;
	setAttr ".pt[5]" -type "float3" 6.2349169e-18 -0.74064636 0 ;
	setAttr ".pt[6]" -type "float3" 0 -0.74064636 0 ;
	setAttr ".pt[7]" -type "float3" 0 -0.74064636 -3.122134e-08 ;
	setAttr ".pt[16]" -type "float3" 6.2349169e-18 -0.74064636 -3.122134e-08 ;
createNode transform -n "wateringCan:Watering_Can1";
	rename -uid "54138614-4146-5C1E-5A12-69A309D66492";
	setAttr ".t" -type "double3" 0 0 -6.4473224916033676 ;
	setAttr ".rp" -type "double3" 0.011605978012084961 1.8746165166087616 0.54460222115917056 ;
	setAttr ".sp" -type "double3" 0.011605978012084961 1.8746165166087616 0.54460222115917056 ;
createNode transform -n "wateringCan:transform10" -p "wateringCan:Watering_Can1";
	rename -uid "690A71D3-45FC-FCFA-0B8B-7D850D894411";
	setAttr ".v" no;
createNode mesh -n "wateringCan:Watering_Can1Shape" -p "wateringCan:transform10";
	rename -uid "7655E715-434D-E321-ACEE-1E9E208F5A08";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 2 ".pt";
	setAttr ".pt[64]" -type "float3" 0 1.4901161e-08 0 ;
	setAttr ".pt[71]" -type "float3" 0 1.4901161e-08 0 ;
createNode transform -n "wateringCan:pTorus1";
	rename -uid "BB063F4C-4452-5DFA-2C41-5DBBA0A30D03";
createNode transform -n "wateringCan:transform11" -p "wateringCan:pTorus1";
	rename -uid "E916BFA4-4CAE-D4E5-2FBC-5C838A3CCFC4";
	setAttr ".v" no;
createNode mesh -n "wateringCan:pTorusShape1" -p "wateringCan:transform11";
	rename -uid "D85867CA-4FC1-5A67-A1C9-D7924FE7259F";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 1 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "wateringCan:Watering_Can2";
	rename -uid "0DBC00A7-42F1-A06F-9E4C-DDA4282BD888";
	setAttr ".t" -type "double3" 0.18536591529846191 9.443055226654451e-10 6.4652593173556259 ;
	setAttr ".rp" -type "double3" -0.18536591529846191 -9.443055226654451e-10 -6.4652593173556259 ;
	setAttr ".sp" -type "double3" -0.18536591529846191 -9.443055226654451e-10 -6.4652593173556259 ;
createNode mesh -n "wateringCan:Watering_Can2Shape" -p "wateringCan:Watering_Can2";
	rename -uid "874F1DE8-4946-C6CB-3B64-23BEFEB214DE";
	setAttr -k off ".v";
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode lightLinker -s -n "lightLinker1";
	rename -uid "AC7B03DE-4AB6-5C13-9D19-72900C92339E";
	setAttr -s 3 ".lnk";
	setAttr -s 3 ".slnk";
createNode shapeEditorManager -n "shapeEditorManager";
	rename -uid "67DD7047-4377-A238-8C0B-79A9C0093907";
createNode poseInterpolatorManager -n "poseInterpolatorManager";
	rename -uid "C991EAA4-4A47-EB02-521F-C395B8EB30E4";
createNode displayLayerManager -n "layerManager";
	rename -uid "5F95E44C-41BA-55BC-CB19-8AAC015BB716";
createNode displayLayer -n "defaultLayer";
	rename -uid "45D86949-4101-3F2D-C3A0-C8B00BB0C9F2";
createNode renderLayerManager -n "renderLayerManager";
	rename -uid "1CDC1542-4B64-A310-11A8-5A96477844C0";
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
createNode groupParts -n "wateringCan:groupParts13";
	rename -uid "81660614-416E-E75C-2EAE-61A826021847";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:249]";
createNode polyUnite -n "wateringCan:polyUnite4";
	rename -uid "2A6D8552-4C0F-0998-2D24-68BB1322C727";
	setAttr -s 2 ".ip";
	setAttr -s 2 ".im";
createNode groupParts -n "wateringCan:groupParts12";
	rename -uid "BAC3F688-4090-F559-1703-46A158904398";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:68]";
createNode polySplit -n "wateringCan:polySplit8";
	rename -uid "6C033EAB-4D77-90ED-1C64-38BD41A44404";
	setAttr -s 2 ".e[0:1]"  1 1;
	setAttr -s 2 ".d[0:1]"  -2147483527 -2147483517;
	setAttr ".sma" 180;
	setAttr ".m2015" yes;
createNode polySplit -n "wateringCan:polySplit7";
	rename -uid "3465FF17-456D-C122-B555-A09C04954287";
	setAttr -s 2 ".e[0:1]"  1 1;
	setAttr -s 2 ".d[0:1]"  -2147483525 -2147483519;
	setAttr ".sma" 180;
	setAttr ".m2015" yes;
createNode polyCloseBorder -n "wateringCan:polyCloseBorder2";
	rename -uid "8363163F-4C3D-EC25-78B9-ED9C005244EB";
	setAttr ".ics" -type "componentList" 6 "e[121]" "e[123]" "e[125]" "e[127]" "e[129]" "e[131:132]";
createNode polySplit -n "wateringCan:polySplit6";
	rename -uid "D0ADADBE-4D18-D65B-8B4E-D89766E36066";
	setAttr -s 2 ".e[0:1]"  1 1;
	setAttr -s 2 ".d[0:1]"  -2147483539 -2147483533;
	setAttr ".sma" 180;
	setAttr ".m2015" yes;
createNode polySplit -n "wateringCan:polySplit5";
	rename -uid "532B7659-4B17-6579-4A0B-639C65BAF71C";
	setAttr -s 2 ".e[0:1]"  1 1;
	setAttr -s 2 ".d[0:1]"  -2147483541 -2147483531;
	setAttr ".sma" 180;
	setAttr ".m2015" yes;
createNode polyCloseBorder -n "wateringCan:polyCloseBorder1";
	rename -uid "99DA2DCF-4BBA-0614-4744-3BB1DD47662C";
	setAttr ".ics" -type "componentList" 6 "e[107]" "e[109]" "e[111]" "e[113]" "e[115]" "e[117:118]";
createNode polyTweak -n "wateringCan:polyTweak48";
	rename -uid "68C58717-45BF-8FF5-3B83-8A9099AA2267";
	setAttr ".uopa" yes;
	setAttr -s 14 ".tk[56:69]" -type "float3"  0 -0.01038937 0 0 -0.0041540656
		 0 0 0.0050945692 0 0 0.01038937 0 0 0.0077464543 0 0 -0.00084746117 0 0 -0.0089176176
		 0 0 -0.33298391 0 0 -0.32538447 0 0 -0.31307402 0 0 -0.30532175 0 0 -0.30796576 0
		 0 -0.3190144 0 0 -0.33014777 0;
createNode polyExtrudeEdge -n "wateringCan:polyExtrudeEdge8";
	rename -uid "8C2C245E-4522-8124-0DE9-788DA90DADC2";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 7 "e[56]" "e[64]" "e[72]" "e[80]" "e[88]" "e[96]" "e[104]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 0.90261656 2.2879467 -6.5005999 ;
	setAttr ".rs" 58318;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" 0.79884922504425049 2.2741153240203857 -6.5980467796325684 ;
	setAttr ".cbx" -type "double3" 1.0063838958740234 2.3017778396606445 -6.4031529426574707 ;
createNode polyTweak -n "wateringCan:polyTweak47";
	rename -uid "47B80E02-4DD2-B6ED-BB46-6F9ADA59066C";
	setAttr ".uopa" yes;
	setAttr -s 7 ".tk[56:62]" -type "float3"  0 -0.38205665 0 0 -0.38205665
		 0 0 -0.38205665 0 0 -0.38205665 0 0 -0.38205665 0 0 -0.38205665 0 0 -0.38205665 0;
createNode polyExtrudeEdge -n "wateringCan:polyExtrudeEdge7";
	rename -uid "AE059513-4BA4-EB85-73D7-97872D2A6612";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 7 "e[55]" "e[63]" "e[71]" "e[79]" "e[87]" "e[95]" "e[103]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" -1.2728913 2.3239784 -6.5081282 ;
	setAttr ".rs" 45905;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" -1.3771157264709473 2.3135890960693359 -6.6055746078491211 ;
	setAttr ".cbx" -type "double3" -1.1686667203903198 2.3343679904937744 -6.4106817245483398 ;
createNode polyTweak -n "wateringCan:polyTweak46";
	rename -uid "7C2EFCC0-43EA-7CBC-9581-9DB5F7E723C3";
	setAttr ".uopa" yes;
	setAttr -s 63 ".tk[0:62]" -type "float3"  -0.046701543 2.73008227 -6.069479465
		 -0.023418231 3.088835716 -5.73712301 -0.036634464 3.29585433 -5.57967043 -0.083322711
		 3.30371118 -5.63319063 -0.15278725 3.11060643 -5.88542509 -0.22911455 2.76077819
		 -6.27858782 -0.29481906 2.33436799 -6.7226119 -0.10115076 2.30177784 -6.50060034
		 -0.0413775 2.66221642 -5.9732976 -0.01712003 3.035979271 -5.62703753 -0.030889083
		 3.25165868 -5.46299791 -0.079530492 3.25984454 -5.51875734 -0.15190114 3.058660269
		 -5.78154325 -0.23142156 2.69419765 -6.191154 -0.29987466 2.24994946 -6.65375376 -0.098104402
		 2.21599507 -6.42245436 -0.028679892 2.67085767 -5.9134717 -0.0022337916 3.078343391
		 -5.53596926 -0.017245248 3.31348228 -5.35712862 -0.070275486 3.32240582 -5.41791964
		 -0.14917579 3.1030705 -5.7044158 -0.23587111 2.70572305 -6.15098429 -0.31050053 2.2213912
		 -6.65532255 -0.09052515 2.18437505 -6.40315294 -0.018170571 2.74949646 -5.93505144
		 0.0100307 3.184026 -5.53249502 -0.0059770201 3.43477082 -5.34178495 -0.062526673
		 3.44428706 -5.40661097 -0.14666346 3.21039486 -5.71212053 -0.2391126 2.78667617 -6.18832731
		 -0.31869501 2.27020073 -6.72613668 -0.084120363 2.23072696 -6.457232 -0.017763047
		 2.83891749 -6.021787167 0.010438262 3.27344775 -5.61923075 -0.0055695721 3.52419186
		 -5.42852068 -0.062119212 3.53370833 -5.49334669 -0.14625594 3.29981637 -5.79885626
		 -0.2387051 2.87609792 -6.27506208 -0.3182877 2.35962033 -6.81287241 -0.08371298 2.32014775
		 -6.54396772 -0.027764317 2.87178493 -6.10836458 -0.0013181141 3.2792716 -5.73086214
		 -0.016329629 3.51441002 -5.5520215 -0.069359832 3.52333379 -5.61281252 -0.14826016
		 3.30399847 -5.89930868 -0.23495539 2.90665126 -6.34587812 -0.30958492 2.4223187 -6.85021544
		 -0.089609653 2.38530087 -6.59804678 -0.040643252 2.82334805 -6.12959051 -0.01638574
		 3.19711089 -5.78332949 -0.030154843 3.41279006 -5.61928988 -0.078796253 3.42097545
		 -5.67505026 -0.15116689 3.21979189 -5.93783617 -0.2306872 2.85532928 -6.34744692
		 -0.29914042 2.41107941 -6.81004572 -0.097370349 2.37712479 -6.57874537 -2.682209e-07
		 1.7881393e-07 -1.6689301e-06 -2.682209e-07 2.3841858e-07 -1.8328428e-06 -2.682209e-07
		 1.3411045e-07 -2.2053719e-06 -2.682209e-07 -5.9604645e-08 -2.4437904e-06 -2.682209e-07
		 -5.9604645e-08 -2.4437904e-06 -2.682209e-07 1.1920929e-07 -1.847744e-06 -2.682209e-07
		 2.682209e-07 -2.4214387e-06;
createNode deleteComponent -n "wateringCan:deleteComponent15";
	rename -uid "169FA4A9-4334-CF32-42D4-1D8CAE850427";
	setAttr ".dc" -type "componentList" 7 "f[6:11]" "f[19:24]" "f[32:37]" "f[45:50]" "f[58:63]" "f[71:76]" "f[84:89]";
createNode polyTorus -n "wateringCan:polyTorus1";
	rename -uid "6B943428-4F99-9482-099F-8486B5D2BA06";
	setAttr ".sr" 0.1;
	setAttr ".sa" 13;
	setAttr ".sh" 7;
createNode groupId -n "wateringCan:groupId20";
	rename -uid "54266C12-4EAE-F3F9-4B75-D0BE19F0056E";
	setAttr ".ihi" 0;
createNode groupId -n "wateringCan:groupId21";
	rename -uid "CFE6F60F-419C-488F-927E-0BAC8CE730C1";
	setAttr ".ihi" 0;
createNode polyMergeVert -n "wateringCan:polyMergeVert1";
	rename -uid "83045ED8-479F-881F-1BBF-20BE8A568128";
	setAttr ".ics" -type "componentList" 1 "vtx[0:194]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 -6.4473224916033676 1;
	setAttr ".am" yes;
createNode polyDelEdge -n "wateringCan:polyDelEdge10";
	rename -uid "A8E17EDA-4D91-68B4-2EA7-77BF0A82F07D";
	setAttr ".ics" -type "componentList" 2 "e[367]" "e[374]";
	setAttr ".cv" yes;
createNode polyTweak -n "wateringCan:polyTweak50";
	rename -uid "474A6510-4373-F551-ADE6-4BB8C3A32A39";
	setAttr ".uopa" yes;
	setAttr -s 6 ".tk[192:197]" -type "float3"  0.0026637209 -0.01399181 0.0004028499
		 0.0026637209 -0.01399181 0.0004028499 0.0026637209 -0.0027187292 0.0004028499 0.0026637209
		 -0.0027187292 0.0004028499 0.0026637209 -0.0027187292 0.0004028499 0.0026637209 -0.0027187292
		 0.0004028499;
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace42";
	rename -uid "26B46E5A-4923-97A6-6F9C-A2ACE23A3F99";
	setAttr ".ics" -type "componentList" 2 "f[176]" "f[178]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 -6.4473224916033676 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" -0.17485392 2.067596 -6.8953214 ;
	setAttr ".rs" 50820;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" -1.1223607063293457 1.7358851432800293 -7.1180554666094711 ;
	setAttr ".cbx" -type "double3" 0.77265286445617676 2.3993067741394043 -6.6725875176958969 ;
	setAttr ".raf" no;
createNode polySplit -n "wateringCan:polySplit9";
	rename -uid "E3A4CAAE-4EA9-789E-F6A7-048FBCC61A0A";
	setAttr -s 2 ".e[0:1]"  0 1;
	setAttr -s 2 ".d[0:1]"  -2147483293 -2147483289;
	setAttr ".sma" 180;
	setAttr ".m2015" yes;
createNode groupParts -n "wateringCan:groupParts11";
	rename -uid "A48CFE9A-4F78-082D-5786-8E879C21CC17";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:179]";
createNode polyCloseBorder -n "wateringCan:polyCloseBorder3";
	rename -uid "8E972A6A-4325-4873-8991-318F80C1A9BB";
	setAttr ".ics" -type "componentList" 5 "e[355]" "e[357]" "e[359]" "e[361]" "e[363:364]";
createNode polyTweak -n "wateringCan:polyTweak49";
	rename -uid "1F47DBB3-42B8-F638-91C1-51BFBD645BFB";
	setAttr ".uopa" yes;
	setAttr -s 6 ".tk[186:191]" -type "float3"  0 -0.66342163 0 0 -0.66342163
		 0 0 -0.66342163 0 0 -0.66342163 0 0 -0.66342163 0 0 -0.66342163 0;
createNode polyExtrudeEdge -n "wateringCan:polyExtrudeEdge9";
	rename -uid "2417DB6B-4377-C838-080F-0C9228C6167E";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 6 "e[98]" "e[100]" "e[102]" "e[104]" "e[119]" "e[121]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 -6.4473224916033676 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" -0.17485392 2.3993068 -7.0329542 ;
	setAttr ".rs" 44392;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" -1.1223607063293457 2.3993067741394043 -7.3933211602740219 ;
	setAttr ".cbx" -type "double3" 0.77265286445617676 2.3993067741394043 -6.6725875176958969 ;
createNode polyDelEdge -n "wateringCan:polyDelEdge9";
	rename -uid "BB50112C-41EC-594E-E9B4-C7BEA57D2A97";
	setAttr ".ics" -type "componentList" 3 "e[161]" "e[163]" "e[165:166]";
	setAttr ".cv" yes;
createNode polyDelEdge -n "wateringCan:polyDelEdge8";
	rename -uid "DBC02D83-4070-C291-E3CA-7F8CE7FDC05F";
	setAttr ".ics" -type "componentList" 9 "e[177]" "e[179]" "e[181:182]" "e[193]" "e[195]" "e[197:198]" "e[209]" "e[211]" "e[213:214]";
	setAttr ".cv" yes;
createNode polyDelEdge -n "wateringCan:polyDelEdge7";
	rename -uid "5DE26D78-4C66-10C0-AA51-3EB4E4438831";
	setAttr ".ics" -type "componentList" 12 "e[225]" "e[227]" "e[229:230]" "e[241]" "e[243]" "e[245:246]" "e[257]" "e[259]" "e[261:262]" "e[273]" "e[275]" "e[277:278]";
	setAttr ".cv" yes;
createNode polySoftEdge -n "wateringCan:polySoftEdge8";
	rename -uid "722CA52B-4A6B-71BB-0DF0-75AE8D93E8D1";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 12 "e[50]" "e[52]" "e[54]" "e[56]" "e[58]" "e[60]" "e[62]" "e[64]" "e[66]" "e[68]" "e[70:71]" "e[96:119]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 -6.4473224916033676 1;
	setAttr ".a" 0;
createNode polySoftEdge -n "wateringCan:polySoftEdge7";
	rename -uid "6259F1C6-4656-3F94-520E-9B851D8431F8";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 2 "e[12:23]" "e[48:71]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 -6.4473224916033676 1;
	setAttr ".a" 0;
createNode polySoftEdge -n "wateringCan:polySoftEdge6";
	rename -uid "2068CFE8-4B3E-0E8C-870A-0A9A6C0FAE14";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 8 "e[323]" "e[325]" "e[327]" "e[329]" "e[331]" "e[333]" "e[335]" "e[337:356]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 -6.4473224916033676 1;
	setAttr ".a" 0;
createNode deleteComponent -n "wateringCan:deleteComponent14";
	rename -uid "1C3B1F97-4A9A-B971-6E96-FD9233810187";
	setAttr ".dc" -type "componentList" 2 "f[68:124]" "f[262:320]";
createNode polyMirror -n "wateringCan:polyMirror2";
	rename -uid "0887D9EF-412C-75F9-80DA-14953552399E";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "f[68:125]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 -6.4473224916033676 1;
	setAttr ".ws" yes;
	setAttr ".p" -type "double3" -0.11940730363130569 0 0 ;
	setAttr ".mps" -0.11940730363130569;
	setAttr ".mtt" 1;
	setAttr ".mt" 0.89881789684295654;
	setAttr ".sp" -type "double3" 0.011605978012084961 1.8746165166087616 0.54460222115917056 ;
	setAttr ".cm" yes;
	setAttr ".fnf" 263;
	setAttr ".lnf" 320;
	setAttr ".pc" -type "double3" -0.11940730363130569 0 0 ;
createNode polyTweak -n "wateringCan:polyTweak45";
	rename -uid "08EF5D11-4432-7A86-1858-6488A623B5E4";
	setAttr ".uopa" yes;
	setAttr -s 338 ".tk";
	setAttr ".tk[0:165]" -type "float3"  -0.35466316 0 -0.22899476 -0.44792169
		 0 -0.10457657 -0.46647674 0 0.049802061 -0.40535668 0 0.19277523 -0.28093854 0 0.28603369
		 -0.12655991 0 0.30458906 0.016413344 0 0.24346869 0.10967199 0 0.11905052 0.12822707
		 0 -0.035327896 0.067106999 0 -0.17830132 -0.057311341 0 -0.27155977 -0.21168986 0
		 -0.29011491 -0.35466316 0 -0.22899476 -0.44792169 0 -0.10457657 -0.46647674 0 0.049802061
		 -0.40535668 0 0.19277523 -0.28093854 0 0.28603369 -0.12655991 0 0.30458906 0.016413346
		 0 0.24346872 0.10967199 0 0.11905052 0.12822707 0 -0.035327896 0.067106999 0 -0.17830132
		 -0.057311341 0 -0.27155977 -0.21168986 0 -0.29011491 -0.34088194 0 -0.21144809 -0.42721334
		 0 -0.096271433 -0.44439021 0 0.046640445 -0.38780987 0 0.17899404 -0.27263331 0 0.26532549
		 -0.12972152 0 0.28250256 0.0026321237 0 0.22592212 0.088963583 0 0.11074542 0.10614054
		 0 -0.032166284 0.049560215 0 -0.16452004 -0.065616503 0 -0.25085142 -0.20852827 0
		 -0.26802838 -0.34088194 0 -0.21144809 -0.42721334 0 -0.096271433 -0.44439021 0 0.046640445
		 -0.38780987 0 0.17899404 -0.27263331 0 0.26532549 -0.12972152 0 0.28250256 0.0026321237
		 0 0.22592212 0.088963583 0 0.11074542 0.10614054 0 -0.032166284 0.049560215 0 -0.16452004
		 -0.065616503 0 -0.25085142 -0.20852827 0 -0.26802838 -0.34088194 0 -0.21144809 -0.42721334
		 0 -0.096271433 -0.44439021 0 0.046640445 -0.38780987 0 0.17899404 -0.27263331 0 0.26532549
		 -0.12972152 0 0.28250256 0.0026321237 0 0.22592212 0.088963583 0 0.11074542 0.10614054
		 0 -0.032166284 0.049560215 0 -0.16452004 -0.065616503 0 -0.25085142 -0.20852827 0
		 -0.26802838 -0.34088194 0 -0.21144809 -0.42721334 0 -0.096271433 -0.44439021 0 0.046640445
		 -0.38780987 0 0.17899404 -0.27263331 0 0.26532549 -0.12972152 0 0.28250256 0.0026321237
		 0 0.22592212 0.088963583 0 0.11074542 0.10614054 0 -0.032166284 0.049560215 0 -0.16452004
		 -0.065616503 0 -0.25085142 -0.20852827 0 -0.26802838 -0.10104762 0 -0.2770206 -0.099747635
		 0 -0.28828195 -0.10104762 0 -0.2770206 -0.099747635 0 -0.28828195 -0.18550806 0 -0.28677097
		 -0.1842081 0 -0.29803228 -0.18550806 0 -0.28677097 -0.1842081 0 -0.29803228 -0.10169354
		 0 -0.28153294 -0.10039344 0 -0.29279438 -0.18485387 0 -0.30254477 -0.18615402 0 -0.2912834
		 -0.1009219 0 -0.28821763 -0.09962181 0 -0.29947928 -0.18408225 0 -0.30922964 -0.18538238
		 0 -0.29796821 -0.10005645 0 -0.29571411 -0.098757543 0 -0.30696568 -0.18321802 0
		 -0.31671602 -0.18451691 0 -0.30546448 -0.099692054 0 -0.30300173 -0.098402411 0 -0.31417313
		 -0.18286288 0 -0.32392362 -0.18415257 0 -0.31275237 -0.099652141 0 -0.30334753 -0.098362572
		 0 -0.31451869 -0.18282303 0 -0.32426915 -0.18411271 0 -0.31309772 -0.10049501 0 -0.29604629
		 -0.099205419 0 -0.3072173 -0.1836659 0 -0.3169679 -0.18495546 0 -0.30579665 -0.10108966
		 0 -0.29089552 -0.099871635 0 -0.3014459 -0.18433213 0 -0.31119648 -0.18555018 0 -0.30064601
		 -0.10284064 0 -0.27572855 -0.10174312 0 -0.28523526 -0.18620358 0 -0.29498568 -0.1873011
		 0 -0.28547883 -0.10696991 0 -0.23995972 -0.10587241 0 -0.24946642 -0.19033298 0 -0.25921673
		 -0.19143042 0 -0.24971001 -0.11370875 0 -0.1900856 -0.11298627 0 -0.19634433 -0.19744676
		 0 -0.20609465 -0.1981692 0 -0.19983602 -0.12045171 0 -0.12317616 -0.1200066 0 -0.12703136
		 -0.20446719 0 -0.13678172 -0.20491216 0 -0.13292658 -0.1301287 0 -0.039350614 -0.12994096
		 0 -0.040977485 -0.21440141 0 -0.050727885 -0.21458918 0 -0.049100976 -0.1318098 0
		 -0.063809745 -0.12087729 0 -0.064988658 -0.20533773 0 -0.074739136 -0.21627022 0
		 -0.073560104 -0.46167448 0 0.008704369 -0.45492768 0 -0.064015292 -0.4620398 0 0.0071467906
		 -0.455293 0 -0.065572888 -0.47332752 0 0.006099578 -0.46658078 0 -0.066620097 -0.47296214
		 0 0.0076571996 -0.4662154 0 -0.065062523 -0.46881366 0 0.0065183705 -0.46206689 0
		 -0.066201329 -0.47087619 0 -0.067018628 -0.47762299 0 0.0057010814 -0.48615542 0
		 0.0049094576 -0.47940889 0 -0.067810327 -0.48821828 0 -0.068627544 -0.49496484 0
		 0.0040920372 -0.53713703 0 0.00053038099 -0.53039038 0 -0.072189271 -0.53242165 0
		 -0.072377674 -0.5391683 0 0.00034191704 -0.59599507 0 -0.0049302271 -0.58924812 0
		 -0.077649817 -0.58651012 0 -0.077395871 -0.59325689 0 -0.0046762261 -0.63311529 0
		 -0.0083740437 -0.6263684 0 -0.081093721 -0.62007493 0 -0.080509834 -0.62682152 0
		 -0.007790098 -0.67549282 0 -0.015058401 -0.66874623 0 -0.087778017 -0.65982026 0
		 -0.086949937 -0.66656685 0 -0.014230358 -0.70091116 0 -0.017416583 -0.69416475 0
		 -0.090136237;
	setAttr ".tk[166:331]" -0.68523866 0 -0.089308143 -0.69198543 0 -0.016588544
		 -0.72220266 0 -0.01939196 -0.71545565 0 -0.09211164 -0.70518535 0 -0.091158718 -0.71193194
		 0 -0.018439015 -0.74976152 0 -0.0201816 -0.74301469 0 -0.092901282 -0.73274398 0
		 -0.09194839 -0.73949051 0 -0.019228715 -0.7788496 0 -0.024647389 -0.77210289 0 -0.097367093
		 -0.7614783 0 -0.096381411 -0.76822501 0 -0.023661658 -0.78593367 0 -0.022552075 -0.77918708
		 0 -0.095271692 -0.76793379 0 -0.094227627 -0.77468008 0 -0.021507896 -0.78262395
		 0 -0.023739243 -0.7758773 0 -0.096458942 -0.76551026 0 -0.095497139 -0.77225679 0
		 -0.022777418 -0.77134395 0 -0.02119853 -0.7645973 0 -0.093918212 -0.75551385 0 -0.093075499
		 -0.76226008 0 -0.020355772 -0.73845959 0 -0.018147679 -0.73171294 0 -0.090867348
		 -0.72490078 0 -0.090235412 -0.73164713 0 -0.017515618 -0.68936217 0 -0.013592662
		 -0.68261552 0 -0.086312383 -0.67844665 0 -0.085925646 -0.68519318 0 -0.013205869
		 -0.61539263 0 -0.0067302817 -0.60864609 0 -0.079449989 -0.60698527 0 -0.079295859
		 -0.61373138 0 -0.0065761483 -0.55116957 0 -0.00077203033 -0.54442292 0 -0.073491745
		 -0.54443723 0 -0.073493041 -0.55118364 0 -0.00077333732 -0.47262511 0 0.0091291312
		 -0.46587852 0 -0.063590564 -0.46589258 0 -0.063591935 -0.47263911 0 0.0091278264
		 -0.46136218 0 0.0075168866 -0.45461568 0 -0.065202802 -0.45462984 0 -0.065204151
		 -0.46137625 0 0.0075155701 -0.47262511 0 0.0091291312 -0.46587852 0 -0.063590564
		 -0.45461568 0 -0.065202802 -0.46136218 0 0.0075168866 0.0886105 0 0.087286539 0.10677451
		 0 0.068382457 0.1134924 0 0.037467685 0.1056212 0 0.0090074539 0.086843632 0 -0.0036812327
		 0.10806811 0 0.0096254731 0.09482868 0 0.036133561 0.095442362 0 0.067726366 0.10962189
		 0 0.089621231 0.13073248 0 0.091573395 0.12896562 0 0.00060549751 0.63491356 0 0.073947988
		 0.62574989 0 0.0922959 0.62617451 0 0.11416297 0.63598871 0 0.12931748 0.65060085
		 0 0.13066855 0.66317296 0 0.11758417 0.66782278 0 0.096186407 0.66237462 0 0.076487355
		 0.64937764 0 0.067704804 0.61527765 0 0.029141303 0.59021342 0 0.079325683 0.59137529
		 0 0.13913545 0.61821884 0 0.18058529 0.65818483 0 0.18428069 0.69257152 0 0.14849301
		 0.70528978 0 0.089966826 0.69038802 0 0.036086764 0.65483963 0 0.012065336 0.64259654
		 0 -0.01516705 0.60007435 0 0.069972828 0.6020453 0 0.17144291 0.64758718 0 0.24176405
		 0.71539068 0 0.24803382 0.77372897 0 0.18731833 0.79530585 0 0.088026129 0.77002537
		 0 -0.0033836968 0.70971555 0 -0.044137456 0.46468121 0 0.070357256 0.46088967 0 0.081518501
		 0.46081847 0 0.094017349 0.46450925 0 0.10053214 0.46980029 0 0.097246662 0.47359169
		 0 0.086085431 0.47366288 0 0.073586583 0.46997201 0 0.067071781 0.089967236 0 0.02192582
		 0.086175695 0 0.033087052 0.086104468 0 0.045585901 0.089795336 0 0.052100711 0.095086239
		 0 0.048815206 0.098877788 0 0.037653975 0.098949023 0 0.025155125 0.095258147 0 0.018640311
		 0.46724057 0 0.083801962 0.092526726 0 0.035370506 0.091859564 0 0.088260032 0.11297014
		 0 0.090212196 -8.9406967e-08 0 0 -1.0430813e-07 0 -1.4901161e-08 -1.0430813e-07 0
		 -1.4901161e-08 -8.9406967e-08 0 0 -5.5879354e-09 0 -2.2351742e-07 3.3527613e-08 0
		 4.4703484e-08 3.7252903e-08 0 -3.1292439e-07 1.1175871e-07 0 -2.3841858e-07 -7.4505806e-09
		 0 4.4703484e-08 -3.7252903e-09 0 -1.0430813e-07 -3.7252903e-09 0 -1.0430813e-07 -7.4505806e-09
		 0 4.4703484e-08 -5.2154064e-08 0 1.4901161e-08 -6.7055225e-08 0 0 1.8626451e-08 0
		 2.9802322e-08 2.2351742e-08 0 -4.4703484e-08 -3.7252903e-08 0 -5.9604645e-08 -8.1956387e-08
		 0 4.4703484e-08 3.7252903e-09 0 0 1.4901161e-08 0 1.0430813e-07 -8.1956387e-08 0
		 7.4505806e-08 -6.7055225e-08 0 0 7.6368451e-08 0 1.3411045e-07 -2.2351742e-08 0 -2.9802322e-08
		 -5.9604645e-08 0 -1.4901161e-08 -9.6857548e-08 0 4.4703484e-08 5.2154064e-08 0 1.0430813e-07
		 -1.8626451e-08 0 1.4901161e-08 0 0 1.3411045e-07 -5.2154064e-08 0 4.4703484e-08 7.4505806e-09
		 0 -1.3411045e-07 5.5879354e-08 0 1.0430813e-07 -9.6857548e-08 0 1.1920929e-07 -9.6857548e-08
		 0 5.9604645e-08 8.9406967e-08 0 5.9604645e-08 3.7252903e-08 0 -2.9802322e-08 -8.9406967e-08
		 0 -1.0430813e-07 -3.7252903e-08 0 8.9406967e-08 2.9802322e-08 0 1.1920929e-07 0 0
		 1.4901161e-08 -7.4505806e-08 0 4.4703484e-08 -7.4505806e-08 0 1.4901161e-08 7.0780516e-08
		 0 1.4901161e-08 5.9604645e-08 0 -7.4505806e-08 -8.1956387e-08 0 -1.6391277e-07 -5.9604645e-08
		 0 -7.4505806e-09 1.0430813e-07 0 -4.4703484e-08 1.2665987e-07 0 -1.1920929e-07 -1.4901161e-08
		 0 1.4901161e-08 2.2351742e-08 0 -1.4901161e-07 1.0803342e-07 0 -1.4156103e-07 1.4528632e-07
		 0 -1.5646219e-07 -2.2351742e-08 0 6.3329935e-08 -6.3329935e-08 0 -1.4901161e-07;
	setAttr ".tk[332:337]" 3.7252903e-08 0 -4.4703484e-08 1.1175871e-07 0 1.4901161e-08
		 2.6077032e-08 0 -4.4703484e-08 -1.4901161e-08 0 -1.7881393e-07 -1.4901161e-08 0 -5.9604645e-08
		 2.2351742e-08 0 -5.9604645e-08;
createNode deleteComponent -n "wateringCan:deleteComponent13";
	rename -uid "402CDD84-43F3-44BE-398D-8C96BEB81A0E";
	setAttr ".dc" -type "componentList" 1 "f[126:182]";
createNode deleteComponent -n "wateringCan:deleteComponent12";
	rename -uid "FBD46306-4CEB-7202-A18A-13AAC246723F";
	setAttr ".dc" -type "componentList" 1 "f[320:377]";
createNode polyMirror -n "wateringCan:polyMirror1";
	rename -uid "F746E81B-471E-9F02-46A5-88B43799A532";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "f[68:125]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 -6.4473224916033676 1;
	setAttr ".ws" yes;
	setAttr ".mtt" 1;
	setAttr ".mt" 1.0352520942687988;
	setAttr ".sp" -type "double3" 0.011605978012084961 1.8746165166087616 0.54460222115917056 ;
	setAttr ".cm" yes;
	setAttr ".fnf" 320;
	setAttr ".lnf" 377;
createNode polyTweak -n "wateringCan:polyTweak44";
	rename -uid "9E95A1D0-438A-F51E-CDAE-4D8FD2C2BC06";
	setAttr ".uopa" yes;
	setAttr -s 6 ".tk";
	setAttr ".tk[128]" -type "float3" 0.087325297 -0.012386083 0.033597052 ;
	setAttr ".tk[129]" -type "float3" 0.099690452 0.01402982 0.075978696 ;
	setAttr ".tk[130]" -type "float3" 0.099690452 0.01402982 0.075978696 ;
	setAttr ".tk[131]" -type "float3" 0.087325297 -0.012386083 0.033597052 ;
	setAttr ".tk[186]" -type "float3" -0.07944116 0.078230202 -0.090810776 ;
	setAttr ".tk[189]" -type "float3" -0.07944116 0.078230202 -0.090810776 ;
createNode polyDelEdge -n "wateringCan:polyDelEdge6";
	rename -uid "F1843DA8-4B73-9230-22E2-87BC5E5C6B61";
	setAttr ".ics" -type "componentList" 1 "e[367]";
	setAttr ".cv" yes;
createNode polyTweak -n "wateringCan:polyTweak43";
	rename -uid "4F71A185-43E5-B20E-F3C2-45B4FE9ACBB3";
	setAttr ".uopa" yes;
	setAttr -s 27 ".tk[291:317]" -type "float3"  0.009305642 -0.07040979 -0.064800911
		 0.01434252 -0.072845638 -0.061315108 0.020825632 -0.071960926 -0.060515203 0.025721537
		 -0.068169534 -0.062775396 0.026739407 -0.063245662 -0.067038305 0.023402996 -0.059492972
		 -0.071309201 0.017273435 -0.058667637 -0.073589519 0.011218653 -0.061155718 -0.07281249
		 0.0080719674 -0.065793157 -0.069341555 0.1288372 -0.0017795197 -0.098005235 0.059619416
		 0.031694502 -0.14590873 -0.029473314 0.019536348 -0.15690072 -0.096753895 -0.032565534
		 -0.12583928 -0.11074178 -0.1002318 -0.067256607 -0.064892143 -0.15180069 -0.0085663209
		 0.019342367 -0.16314265 0.022771366 0.10254839 -0.12895043 0.012092367 0.14579055
		 -0.065223381 -0.035605941 0.18884692 0.10848499 -0.048002098 0.071415938 0.16527466
		 -0.12927181 -0.079733983 0.1446479 -0.14792065 -0.1938781 0.056254823 -0.095222816
		 -0.21760938 -0.05854414 0.0041645197 -0.13982347 -0.14603232 0.10373496 0.0030841725
		 -0.16527465 0.15690072 0.14424655 -0.10726669 0.13878424 0.21760938 0.00084905105
		 0.057861626;
createNode polyDelEdge -n "wateringCan:polyDelEdge5";
	rename -uid "5E707E81-439A-6574-7494-D3B4219C85B2";
	setAttr ".ics" -type "componentList" 4 "e[624]" "e[626]" "e[628]" "e[630]";
	setAttr ".cv" yes;
createNode polySplit -n "wateringCan:polySplit4";
	rename -uid "BDB7CAB7-4E3A-4A42-F2AD-738F2CCEEA6C";
	setAttr -s 2 ".e[0:1]"  1 1;
	setAttr -s 2 ".d[0:1]"  -2147483057 -2147483043;
	setAttr ".sma" 180;
	setAttr ".m2015" yes;
createNode polySplit -n "wateringCan:polySplit3";
	rename -uid "07C82FD3-490C-003E-345E-8E9147BD3F65";
	setAttr -s 2 ".e[0:1]"  1 1;
	setAttr -s 2 ".d[0:1]"  -2147483055 -2147483045;
	setAttr ".sma" 180;
	setAttr ".m2015" yes;
createNode polyConnectComponents -n "wateringCan:polyConnectComponents1";
	rename -uid "9D8472CE-493E-4E87-DCFF-DDA2D0769787";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 2 "vtx[312]" "vtx[315]";
createNode deleteComponent -n "wateringCan:deleteComponent11";
	rename -uid "C781F361-47A6-031F-2D18-1F8B5ECF4A59";
	setAttr ".dc" -type "componentList" 8 "e[592:593]" "e[596]" "e[599]" "e[602]" "e[605]" "e[608]" "e[611]" "e[614]";
createNode deleteComponent -n "wateringCan:deleteComponent10";
	rename -uid "52499C64-40D0-2E5D-9B44-F481A17E0879";
	setAttr ".dc" -type "componentList" 1 "vtx[311]";
createNode polySoftEdge -n "wateringCan:polySoftEdge5";
	rename -uid "FEDBFF37-49B2-19DF-AA57-A488222564AC";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 8 "e[591:593]" "e[595:596]" "e[598:599]" "e[601:602]" "e[604:605]" "e[607:608]" "e[610:611]" "e[613:615]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 -6.4473224916033676 1;
	setAttr ".a" 0;
createNode polyDelEdge -n "wateringCan:polyDelEdge4";
	rename -uid "D9879F43-4B89-5D9B-682A-E3A070158EFF";
	setAttr ".ics" -type "componentList" 1 "e[550:553]";
	setAttr ".cv" yes;
createNode polyDelEdge -n "wateringCan:polyDelEdge3";
	rename -uid "97FCBAD5-4C82-B232-9E00-43A13A29902D";
	setAttr ".ics" -type "componentList" 1 "e[550]";
	setAttr ".cv" yes;
createNode polyDelEdge -n "wateringCan:polyDelEdge2";
	rename -uid "5EDC2B45-4CBE-6557-AF6C-159DB6C11DD6";
	setAttr ".ics" -type "componentList" 24 "e[563]" "e[565]" "e[567]" "e[569]" "e[571]" "e[573]" "e[575]" "e[577:578]" "e[581]" "e[583]" "e[585]" "e[587]" "e[589]" "e[591]" "e[593]" "e[595:596]" "e[599]" "e[601]" "e[603]" "e[605]" "e[607]" "e[609]" "e[611]" "e[613:614]";
	setAttr ".cv" yes;
createNode polyDelEdge -n "wateringCan:polyDelEdge1";
	rename -uid "829D8361-426D-A4E5-D02F-B9B2F84DCF1C";
	setAttr ".ics" -type "componentList" 29 "e[127:128]" "e[130]" "e[132]" "e[134]" "e[137:138]" "e[141:142]" "e[145:146]" "e[149:150]" "e[153:154]" "e[157:158]" "e[161:162]" "e[165:166]" "e[169:170]" "e[173:174]" "e[176:177]" "e[179]" "e[181]" "e[183]" "e[186:187]" "e[190:191]" "e[194:195]" "e[198:199]" "e[202:203]" "e[206:207]" "e[210:211]" "e[214:215]" "e[218:219]" "e[222:223]" "e[261:282]";
	setAttr ".cv" yes;
createNode polySoftEdge -n "wateringCan:polySoftEdge4";
	rename -uid "E11B0109-4E73-A7A2-35CD-FAA5FE69AA9A";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 2 "e[694]" "e[862:863]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 -6.4473224916033676 1;
	setAttr ".a" 180;
createNode polyTweak -n "wateringCan:polyTweak42";
	rename -uid "6BFFFD6F-4FA0-37DF-B72E-DAA3DC0F4DC5";
	setAttr ".uopa" yes;
	setAttr -s 2 ".tk[439:440]" -type "float3"  0.013635695 -0.055942833 -0.06136173
		 0.013635695 -0.055943042 -0.061361969;
createNode polyExtrudeEdge -n "wateringCan:polyExtrudeEdge6";
	rename -uid "95FD58E9-46DC-6FF4-7D1F-49B522FF4182";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[694]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 -6.4473224916033676 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" -0.43582147 0.54158938 -5.4784942 ;
	setAttr ".rs" 54445;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" -0.44450846314430237 0.49956706166267395 -5.5148751773409774 ;
	setAttr ".cbx" -type "double3" -0.42713445425033569 0.58361166715621948 -5.4421135224871566 ;
createNode polySoftEdge -n "wateringCan:polySoftEdge3";
	rename -uid "05901A0F-4486-98CB-7F5A-D184084DAB5C";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 82 "e[283]" "e[286:288]" "e[291:296]" "e[298]" "e[300]" "e[303:304]" "e[306]" "e[308]" "e[311:312]" "e[314]" "e[316]" "e[319:320]" "e[322]" "e[324]" "e[327:328]" "e[330]" "e[332]" "e[335:336]" "e[338]" "e[340]" "e[343:344]" "e[346]" "e[348]" "e[351:352]" "e[354]" "e[356]" "e[359:360]" "e[362]" "e[364]" "e[367:368]" "e[370]" "e[372]" "e[375:376]" "e[378]" "e[380]" "e[383:384]" "e[386]" "e[388]" "e[391:392]" "e[394]" "e[396]" "e[399]" "e[402:404]" "e[407:412]" "e[414]" "e[416]" "e[419:420]" "e[422]" "e[424]" "e[427:428]" "e[430]" "e[432]" "e[435:436]" "e[438]" "e[440]" "e[443:444]" "e[446]" "e[448]" "e[451:452]" "e[454]" "e[456]" "e[459:460]" "e[462]" "e[464]" "e[467:468]" "e[470]" "e[472]" "e[475:476]" "e[478]" "e[480]" "e[483:484]" "e[486]" "e[488]" "e[491:492]" "e[494]" "e[496]" "e[499:500]" "e[502]" "e[504]" "e[507:508]" "e[510]" "e[512]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".a" 180;
createNode polySoftEdge -n "wateringCan:polySoftEdge2";
	rename -uid "5A4831E8-47D0-F552-EE15-25BD8E74C1D1";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 82 "e[283]" "e[286:288]" "e[291:296]" "e[298]" "e[300]" "e[303:304]" "e[306]" "e[308]" "e[311:312]" "e[314]" "e[316]" "e[319:320]" "e[322]" "e[324]" "e[327:328]" "e[330]" "e[332]" "e[335:336]" "e[338]" "e[340]" "e[343:344]" "e[346]" "e[348]" "e[351:352]" "e[354]" "e[356]" "e[359:360]" "e[362]" "e[364]" "e[367:368]" "e[370]" "e[372]" "e[375:376]" "e[378]" "e[380]" "e[383:384]" "e[386]" "e[388]" "e[391:392]" "e[394]" "e[396]" "e[399]" "e[402:404]" "e[407:412]" "e[414]" "e[416]" "e[419:420]" "e[422]" "e[424]" "e[427:428]" "e[430]" "e[432]" "e[435:436]" "e[438]" "e[440]" "e[443:444]" "e[446]" "e[448]" "e[451:452]" "e[454]" "e[456]" "e[459:460]" "e[462]" "e[464]" "e[467:468]" "e[470]" "e[472]" "e[475:476]" "e[478]" "e[480]" "e[483:484]" "e[486]" "e[488]" "e[491:492]" "e[494]" "e[496]" "e[499:500]" "e[502]" "e[504]" "e[507:508]" "e[510]" "e[512]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".a" 180;
createNode polySoftEdge -n "wateringCan:polySoftEdge1";
	rename -uid "F1ED1DEA-4E5E-9907-9205-52A88A5A5AA4";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[*]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".a" 180;
createNode groupParts -n "wateringCan:groupParts10";
	rename -uid "FCDBBB6C-4C26-F1C4-F20D-8CADC4C20CDB";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:432]";
	setAttr ".gi" 19;
createNode polyUnite -n "wateringCan:polyUnite3";
	rename -uid "ADB2DECB-488E-3B8A-98C7-5991F99603D7";
	setAttr -s 5 ".ip";
	setAttr -s 5 ".im";
createNode groupId -n "wateringCan:groupId11";
	rename -uid "BED92480-4257-CA48-8B8C-A7B256CE22C0";
	setAttr ".ihi" 0;
createNode groupParts -n "wateringCan:groupParts6";
	rename -uid "685F4CCD-46A3-C163-5205-4D987B4DD345";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:139]";
createNode polyBevel3 -n "wateringCan:polyBevel2";
	rename -uid "88C09EC7-47E6-FDEC-8B75-E9BF8C4B60C5";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 2 "e[151:162]" "e[175:186]";
	setAttr ".ix" -type "matrix" 0.09635524844015908 0 0 0 0 0.09635524844015908 0 0
		 0 0 0.09635524844015908 0 4.3514932279526584e-07 1.1996533297425698 -1.2869248626160728e-08 1;
	setAttr ".ws" yes;
	setAttr ".oaf" yes;
	setAttr ".sg" 2;
	setAttr ".at" 180;
	setAttr ".sn" yes;
	setAttr ".mv" yes;
	setAttr ".mvt" 0.0001;
	setAttr ".sa" 30;
createNode polyTweak -n "wateringCan:polyTweak5";
	rename -uid "D79D31CE-43AF-A4D7-E1C9-14B5A097C470";
	setAttr ".uopa" yes;
	setAttr -s 24 ".tk[72:95]" -type "float3"  0 12.2684269 0 0 12.2684269
		 0 5.0821977e-21 12.2684269 0 0 12.2684269 0 0 12.2684269 0 0 12.2684269 0 0 12.2684269
		 0 0 12.2684269 0 5.0821977e-21 12.2684269 0 0 12.2684269 0 0 12.2684269 0 0 12.2684269
		 0 0 4.69277573 0 0 4.69277573 0 5.0821977e-21 4.69277573 0 0 4.69277573 0 0 4.69277573
		 0 0 4.69277573 0 0 4.69277573 0 0 4.69277573 0 5.0821977e-21 4.69277573 0 0 4.69277573
		 0 0 4.69277573 0 0 4.69277573 0;
createNode polySplit -n "wateringCan:polySplit2";
	rename -uid "2B7EE423-422A-DAE9-D3EC-3089A4D48FC3";
	setAttr -s 13 ".e[0:12]"  0.5 0.5 0.5 0.5 0.5 0.5 0.5 0.5 0.5 0.5 0.5
		 0.5 0.5;
	setAttr -s 13 ".d[0:12]"  -2147483509 -2147483508 -2147483507 -2147483506 -2147483505 -2147483504 
		-2147483503 -2147483502 -2147483501 -2147483500 -2147483499 -2147483498 -2147483509;
	setAttr ".sma" 180;
	setAttr ".m2015" yes;
createNode polySplit -n "wateringCan:polySplit1";
	rename -uid "0C94761C-4876-190F-C542-E68824BC6239";
	setAttr -s 13 ".e[0:12]"  0.33333299 0.33333299 0.33333299 0.33333299
		 0.33333299 0.33333299 0.33333299 0.33333299 0.33333299 0.33333299 0.33333299 0.33333299
		 0.33333299;
	setAttr -s 13 ".d[0:12]"  -2147483624 -2147483623 -2147483622 -2147483621 -2147483620 -2147483619 
		-2147483618 -2147483617 -2147483616 -2147483615 -2147483614 -2147483613 -2147483624;
	setAttr ".sma" 180;
	setAttr ".m2015" yes;
createNode polyBridgeEdge -n "wateringCan:polyBridgeEdge16";
	rename -uid "A9680C61-47FE-36A9-A283-82B5892A6540";
	setAttr ".ics" -type "componentList" 2 "e[100]" "e[104]";
	setAttr ".ix" -type "matrix" 0.09635524844015908 0 0 0 0 0.09635524844015908 0 0
		 0 0 0.09635524844015908 0 4.3514932279526584e-07 1.1996533297425698 -1.2869248626160728e-08 1;
	setAttr ".c[0]"  0 1 1;
	setAttr ".dv" 0;
	setAttr ".sv1" 56;
	setAttr ".sv2" 58;
	setAttr ".d" 1;
createNode polyBridgeEdge -n "wateringCan:polyBridgeEdge15";
	rename -uid "20A9E900-48CB-0DF5-7A70-AEA4C0D18D6A";
	setAttr ".ics" -type "componentList" 2 "e[98]" "e[106]";
	setAttr ".ix" -type "matrix" 0.09635524844015908 0 0 0 0 0.09635524844015908 0 0
		 0 0 0.09635524844015908 0 4.3514932279526584e-07 1.1996533297425698 -1.2869248626160728e-08 1;
	setAttr ".c[0]"  0 1 1;
	setAttr ".dv" 0;
	setAttr ".sv1" 55;
	setAttr ".sv2" 59;
	setAttr ".d" 1;
createNode polyBridgeEdge -n "wateringCan:polyBridgeEdge14";
	rename -uid "D0F25E45-44F1-CD0B-91C3-E78AB4C3DB1F";
	setAttr ".ics" -type "componentList" 2 "e[88]" "e[92]";
	setAttr ".ix" -type "matrix" 0.09635524844015908 0 0 0 0 0.09635524844015908 0 0
		 0 0 0.09635524844015908 0 4.3514932279526584e-07 1.1996533297425698 -1.2869248626160728e-08 1;
	setAttr ".c[0]"  0 1 1;
	setAttr ".dv" 0;
	setAttr ".sv1" 50;
	setAttr ".sv2" 52;
	setAttr ".d" 1;
createNode polyBridgeEdge -n "wateringCan:polyBridgeEdge13";
	rename -uid "04120A3E-4370-BC61-0405-9A8466CD48D9";
	setAttr ".ics" -type "componentList" 2 "e[86]" "e[94]";
	setAttr ".ix" -type "matrix" 0.09635524844015908 0 0 0 0 0.09635524844015908 0 0
		 0 0 0.09635524844015908 0 4.3514932279526584e-07 1.1996533297425698 -1.2869248626160728e-08 1;
	setAttr ".c[0]"  0 1 1;
	setAttr ".dv" 0;
	setAttr ".sv1" 49;
	setAttr ".sv2" 53;
	setAttr ".d" 1;
createNode polyBridgeEdge -n "wateringCan:polyBridgeEdge12";
	rename -uid "42380D1B-48F5-A74C-419B-8EBAD01A3AC5";
	setAttr ".ics" -type "componentList" 2 "e[96]" "e[107]";
	setAttr ".ix" -type "matrix" 0.09635524844015908 0 0 0 0 0.09635524844015908 0 0
		 0 0 0.09635524844015908 0 4.3514932279526584e-07 1.1996533297425698 -1.2869248626160728e-08 1;
	setAttr ".c[0]"  0 1 1;
	setAttr ".dv" 0;
	setAttr ".sv1" 54;
	setAttr ".sv2" 48;
	setAttr ".d" 1;
createNode polyBridgeEdge -n "wateringCan:polyBridgeEdge11";
	rename -uid "FFEB79F1-4511-E249-8DE2-11B6B2435300";
	setAttr ".ics" -type "componentList" 2 "e[122]" "e[126]";
	setAttr ".ix" -type "matrix" 0.12734638119189173 0 0 0 0 0.12734638119189173 0 0
		 0 0 0.12734638119189173 0 -1.9169544190934751 1.1224836054373728 -1.9544334581703726 1;
	setAttr ".c[0]"  0 1 1;
	setAttr ".dv" 0;
	setAttr ".sv1" 66;
	setAttr ".sv2" 68;
	setAttr ".d" 1;
createNode polyBridgeEdge -n "wateringCan:polyBridgeEdge10";
	rename -uid "62582F7E-4B28-BB4F-3954-14A602620D99";
	setAttr ".ics" -type "componentList" 2 "e[120]" "e[128]";
	setAttr ".ix" -type "matrix" 0.12734638119189173 0 0 0 0 0.12734638119189173 0 0
		 0 0 0.12734638119189173 0 -1.9169544190934751 1.1224836054373728 -1.9544334581703726 1;
	setAttr ".c[0]"  0 1 1;
	setAttr ".dv" 0;
	setAttr ".sv1" 65;
	setAttr ".sv2" 69;
	setAttr ".d" 1;
createNode polyBridgeEdge -n "wateringCan:polyBridgeEdge9";
	rename -uid "E053AFE4-4C87-737B-FC43-D8B98F8C7C1A";
	setAttr ".ics" -type "componentList" 2 "e[118]" "e[130]";
	setAttr ".ix" -type "matrix" 0.12734638119189173 0 0 0 0 0.12734638119189173 0 0
		 0 0 0.12734638119189173 0 -1.9169544190934751 1.1224836054373728 -1.9544334581703726 1;
	setAttr ".c[0]"  0 1 1;
	setAttr ".dv" 0;
	setAttr ".sv1" 64;
	setAttr ".sv2" 70;
	setAttr ".d" 1;
createNode polyTweak -n "wateringCan:polyTweak4";
	rename -uid "72F44BA6-4E68-8D63-07B6-32A51BEBFAF2";
	setAttr ".uopa" yes;
	setAttr -s 24 ".tk[48:71]" -type "float3"  0 0.54968399 0 0 0.54968399
		 0 0 0.54968399 0 0 0.54968399 0 0 0.54968399 0 0 0.54968399 0 0 0.54968399 0 0 0.54968399
		 0 0 0.54968399 0 0 0.54968399 0 0 0.54968399 0 0 0.54968399 0 0 -0.54968399 0 0 -0.54968399
		 0 0 -0.54968399 0 0 -0.54968399 0 0 -0.54968399 0 0 -0.54968399 0 0 -0.54968399 0
		 0 -0.54968399 0 0 -0.54968399 0 0 -0.54968399 0 0 -0.54968399 0 0 -0.54968399 0;
createNode polyExtrudeEdge -n "wateringCan:polyExtrudeEdge5";
	rename -uid "83960E05-4220-41C3-B870-AA8151405DF9";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 22 "e[38]" "e[40]" "e[42]" "e[44]" "e[46]" "e[48]" "e[50]" "e[52]" "e[54]" "e[56]" "e[58:59]" "e[62]" "e[64]" "e[66]" "e[68]" "e[70]" "e[72]" "e[74]" "e[76]" "e[78]" "e[80]" "e[82:83]";
	setAttr ".ix" -type "matrix" 0.12734638119189173 0 0 0 0 0.12734638119189173 0 0
		 0 0 0.12734638119189173 0 -1.9169544190934751 1.1224836054373728 -1.9544334581703726 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" -1.9169546 1.1224836 -1.9544334 ;
	setAttr ".rs" 49719;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" -3.213716739765438 -0.53301935005721979 -3.2511955359483897 ;
	setAttr ".cbx" -type "double3" -0.62019246276243112 2.7779865609319652 -0.65767125894538259 ;
createNode polyTweak -n "wateringCan:polyTweak3";
	rename -uid "7527AE29-483A-EE29-5F3B-05967968055D";
	setAttr ".uopa" yes;
	setAttr -s 24 ".tk[24:47]" -type "float3"  -0.70758581 0 0.40852416 -0.40852451
		 0 0.70758545 7.0836251e-08 0 0.81704831 0.40852463 0 0.70758545 0.70758611 0 0.40852416
		 0.81704926 0 -1.3194268e-16 0.70758611 0 -0.40852416 0.40852463 0 -0.70758563 7.0836251e-08
		 0 -0.81704855 -0.40852451 0 -0.70758563 -0.70758581 0 -0.40852416 -0.81704903 0 -1.3194268e-16
		 -0.70758581 0 0.40852416 -0.40852451 0 0.70758545 7.0836251e-08 0 0.81704831 0.40852463
		 0 0.70758545 0.70758611 0 0.40852416 0.81704926 0 -1.3194268e-16 0.70758611 0 -0.40852416
		 0.40852463 0 -0.70758563 7.0836251e-08 0 -0.81704855 -0.40852451 0 -0.70758563 -0.70758581
		 0 -0.40852416 -0.81704903 0 -1.3194268e-16;
createNode polyExtrudeEdge -n "wateringCan:polyExtrudeEdge4";
	rename -uid "C0EFD66C-4618-FFB5-07B4-899680167C9B";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[0:23]";
	setAttr ".ix" -type "matrix" 0.12734638119189173 0 0 0 0 0.12734638119189173 0 0
		 0 0 0.12734638119189173 0 -1.9169544190934751 1.1224836054373728 -1.9544334581703726 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" -1.9169544 1.1224836 -1.9544334 ;
	setAttr ".rs" 53301;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" -3.3177646122042841 -0.53301935005721979 -3.3552436512811816 ;
	setAttr ".cbx" -type "double3" -0.51614422598266607 2.7779865609319652 -0.55362326505956361 ;
createNode deleteComponent -n "wateringCan:deleteComponent5";
	rename -uid "0C51FA3E-45E7-68DF-B036-E9A6BB03C340";
	setAttr ".dc" -type "componentList" 1 "f[12:35]";
createNode polyCylinder -n "wateringCan:polyCylinder2";
	rename -uid "D1CCB566-4B38-C6B4-5DD0-A3BCA3B7E106";
	setAttr ".r" 11;
	setAttr ".h" 26;
	setAttr ".sa" 12;
	setAttr ".sc" 1;
	setAttr ".cuv" 3;
createNode groupId -n "wateringCan:groupId12";
	rename -uid "51C4EF6A-4C61-A694-0AB6-2E9F89292B0D";
	setAttr ".ihi" 0;
createNode groupParts -n "wateringCan:groupParts5";
	rename -uid "3CED7661-4B9C-9EC1-3E32-2B8B87EB7884";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:115]";
createNode polyUnite -n "wateringCan:polyUnite2";
	rename -uid "E379601A-4FFA-2077-6719-338441640F70";
	setAttr -s 2 ".ip";
	setAttr -s 2 ".im";
createNode groupId -n "wateringCan:groupId6";
	rename -uid "66AF9AD4-4365-6E37-7D80-C18008F0730A";
	setAttr ".ihi" 0;
createNode groupParts -n "wateringCan:groupParts4";
	rename -uid "B2EB6D5F-4061-E89A-4251-9488ADE0697B";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:57]";
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace35";
	rename -uid "041099DA-4071-2000-519A-38AB7853FBE8";
	setAttr ".ics" -type "componentList" 1 "f[1]";
	setAttr ".ix" -type "matrix" 0.96712754236691534 0 0.25429179458907103 0 0 1 0 0
		 -0.25429179458907103 0 0.96712754236691534 0 1.016336118328915 2.3213605393860619 0.23993364926932581 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 0.13325556 3.7478516 0.0017834621 ;
	setAttr ".rs" 63530;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" 0.09231745572601624 3.728061388919143 -0.14402038721786747 ;
	setAttr ".cbx" -type "double3" 0.17419365368743422 3.7676419724915307 0.14758731148536311 ;
	setAttr ".raf" no;
createNode polyTweak -n "wateringCan:polyTweak36";
	rename -uid "10F39727-43F2-96D0-BB38-7E8F36C4FA97";
	setAttr ".uopa" yes;
	setAttr -s 4 ".tk[52:55]" -type "float3"  -0.29774481 0.04821277 2.9802322e-07
		 -0.30565959 0.050210018 2.9802322e-07 -0.30565953 0.050210014 2.9802322e-07 -0.29774481
		 0.048212744 2.9802322e-07;
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace34";
	rename -uid "F27A0C27-4534-8C11-6C15-40840488341D";
	setAttr ".ics" -type "componentList" 1 "f[1]";
	setAttr ".ix" -type "matrix" 0.96712754236691534 0 0.25429179458907103 0 0 1 0 0
		 -0.25429179458907103 0 0.96712754236691534 0 1.016336118328915 2.3213605393860619 0.23993364926932581 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 0.42504019 3.6986403 0.078503579 ;
	setAttr ".rs" 53962;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" 0.38027485750061274 3.6798486222718041 -0.068306598075085323 ;
	setAttr ".cbx" -type "double3" 0.46980553963078564 3.7174318541977684 0.22531375097179693 ;
	setAttr ".raf" no;
createNode polyTweak -n "wateringCan:polyTweak35";
	rename -uid "D9E9D396-4C2C-D722-F287-0F854EE5E957";
	setAttr ".uopa" yes;
	setAttr -s 4 ".tk[48:51]" -type "float3"  -0.28230235 0.18941069 0 -0.2908394
		 0.19374022 0 -0.2908394 0.19374013 0 -0.28230235 0.18941064 0;
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace33";
	rename -uid "9529CFE3-49BD-BD31-76D6-A8A442A31946";
	setAttr ".ics" -type "componentList" 1 "f[1]";
	setAttr ".ix" -type "matrix" 0.96712754236691534 0 0.25429179458907103 0 0 1 0 0
		 -0.25429179458907103 0 0.96712754236691534 0 1.016336118328915 2.3213605393860619 0.23993364926932581 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 0.70219088 3.5070648 0.15137622 ;
	setAttr ".rs" 55802;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" 0.65329736193104848 3.4904379357788842 0.0034806033876955689 ;
	setAttr ".cbx" -type "double3" 0.75108433372759098 3.5236917247269433 0.29927184007550756 ;
	setAttr ".raf" no;
createNode polyTweak -n "wateringCan:polyTweak34";
	rename -uid "0988BA67-4249-F0F9-69D9-FA964BF55FE6";
	setAttr ".uopa" yes;
	setAttr -s 4 ".tk[44:47]" -type "float3"  -0.18514928 0.15985487 2.2351742e-07
		 -0.19668648 0.17166671 2.2351742e-07 -0.19668648 0.17166664 2.2351742e-07 -0.18514928
		 0.15985487 2.2351742e-07;
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace32";
	rename -uid "3B0DC35A-4427-8D51-9F99-A8840A016A9D";
	setAttr ".ics" -type "componentList" 1 "f[1]";
	setAttr ".ix" -type "matrix" 0.96712754236691534 0 0.25429179458907103 0 0 1 0 0
		 -0.25429179458907103 0 0.96712754236691534 0 1.016336118328915 2.3213605393860619 0.23993364926932581 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 0.88683289 3.3413041 0.19992486 ;
	setAttr ".rs" 34423;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" 0.83236043607445753 3.3305831660721581 0.050562327416096037 ;
	setAttr ".cbx" -type "double3" 0.94130532799319377 3.352025102565078 0.34928738781120705 ;
	setAttr ".raf" no;
createNode polyTweak -n "wateringCan:polyTweak33";
	rename -uid "3832EF73-4CB5-4950-FB85-32AE5D6ADBFA";
	setAttr ".uopa" yes;
	setAttr -s 4 ".tk[40:43]" -type "float3"  -0.12704958 0.20008194 0 -0.1270496
		 0.20008194 0 -0.1270496 0.20008194 0 -0.12704958 0.20008194 0;
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace31";
	rename -uid "E780B257-4C2A-936E-89FE-519728766B74";
	setAttr ".ics" -type "componentList" 1 "f[1]";
	setAttr ".ix" -type "matrix" 0.96712754236691534 0 0.25429179458907103 0 0 1 0 0
		 -0.25429179458907103 0 0.96712754236691534 0 1.016336118328915 2.3213605393860619 0.23993364926932581 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 1.0097061 3.1412222 0.23223253 ;
	setAttr ".rs" 41453;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" 0.95523358093148159 3.1305012216065209 0.082870007179113747 ;
	setAttr ".cbx" -type "double3" 1.0641785953464666 3.1519431580994408 0.38159503915490217 ;
	setAttr ".raf" no;
createNode polyTweak -n "wateringCan:polyTweak32";
	rename -uid "8931A017-41FC-B68F-89CD-B3B501B09500";
	setAttr ".uopa" yes;
	setAttr -s 8 ".tk[32:39]" -type "float3"  0.0050337575 0.0031911731
		 0 0.0050337613 0.0031911731 0 0.0050337613 0.0031911731 0 0.0050337575 0.0031911731
		 0 -0.048838861 0.13583516 -1.0430813e-07 -0.052546158 0.14328957 -1.0430813e-07 -0.052546158
		 0.14328957 -1.0430813e-07 -0.048838861 0.13583516 -1.0430813e-07;
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace30";
	rename -uid "902F1C4E-49B5-A3C0-5146-16A853AF5F65";
	setAttr ".ics" -type "componentList" 1 "f[1]";
	setAttr ".ix" -type "matrix" 0.96712754236691534 0 0.25429179458907103 0 0 1 0 0
		 -0.25429179458907103 0 0.96712754236691534 0 1.016336118328915 2.3213605393860619 0.23993364926932581 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 1.0587323 3.0016599 0.24512331 ;
	setAttr ".rs" 48396;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" 1.0024671139866475 2.9946659316513817 0.09528943731913006 ;
	setAttr ".cbx" -type "double3" 1.1149974671359817 3.0086536516640465 0.3949571827511838 ;
	setAttr ".raf" no;
createNode polyTweak -n "wateringCan:polyTweak31";
	rename -uid "DB8AEE12-425D-3608-19B9-FB92614152B7";
	setAttr ".uopa" yes;
	setAttr -s 4 ".tk[32:35]" -type "float3"  -0.023328751 0.061392725 0
		 -0.025533732 0.070327342 0 -0.025533732 0.070327342 0 -0.023328751 0.061392695 0;
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace29";
	rename -uid "2D8B7FF4-410F-9808-985C-05A46EB4FDA8";
	setAttr ".ics" -type "componentList" 1 "f[1]";
	setAttr ".ix" -type "matrix" 0.96712754236691534 0 0.25429179458907103 0 0 1 0 0
		 -0.25429179458907103 0 0.96712754236691534 0 1.016336118328915 2.3213605393860619 0.23993364926932581 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 1.0823605 2.9357998 0.25133595 ;
	setAttr ".rs" 33922;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" 1.0250290607492816 2.9332733859513085 0.10122170432693278 ;
	setAttr ".cbx" -type "double3" 1.139691893078163 2.9383261908982079 0.40145021455318974 ;
	setAttr ".raf" no;
createNode polyTweak -n "wateringCan:polyTweak30";
	rename -uid "E1D768C4-4BB6-514B-C5F2-A0BDB687BDDB";
	setAttr ".uopa" yes;
	setAttr -s 4 ".tk[28:31]" -type "float3"  -0.02593356 0.15719521 0 -0.025933571
		 0.15719521 0 -0.025933571 0.15719521 0 -0.02593356 0.15719521 0;
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace28";
	rename -uid "997D378B-4C3D-DE68-F1C9-8C90935828DA";
	setAttr ".ics" -type "componentList" 1 "f[1]";
	setAttr ".ix" -type "matrix" 0.96712754236691534 0 0.25429179458907103 0 0 1 0 0
		 -0.25429179458907103 0 0.96712754236691534 0 1.016336118328915 2.3213605393860619 0.23993364926932581 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 1.1074415 2.7786045 0.25793067 ;
	setAttr ".rs" 54813;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" 1.0501101178378078 2.7760781754944603 0.10781640794871725 ;
	setAttr ".cbx" -type "double3" 1.1647729746408566 2.781130920836715 0.40804489828144835 ;
	setAttr ".raf" no;
createNode polyTweak -n "wateringCan:polyTweak29";
	rename -uid "9372AFC7-4454-C732-A150-B49952B653E0";
	setAttr ".uopa" yes;
	setAttr -s 12 ".tk[16:27]" -type "float3"  0.0050084554 0.0043241284
		 0 0.005410553 9.831741e-05 0 0.005410553 9.831741e-05 0 0.0050084563 0.004324141
		 0 0.032326229 0.0057487674 -0.0016718358 0.032442827 0.0049049361 -0.0016718358 0.032442823
		 0.0049049333 -0.0016718358 0.032326229 0.0057487697 -0.0016718358 0.033553705 0.10091709
		 -0.0016718358 0.033670317 0.10007327 -0.0016718358 0.033670321 0.10007328 -0.0016718358
		 0.033553705 0.10091709 -0.0016718358;
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace27";
	rename -uid "7C98FF2F-4D2E-2BCE-AF46-27B242719EBB";
	setAttr ".ics" -type "componentList" 1 "f[1]";
	setAttr ".ix" -type "matrix" 0.96712754236691534 0 0.25429179458907103 0 0 1 0 0
		 -0.25429179458907103 0 0.96712754236691534 0 1.016336118328915 2.3213605393860619 0.23993364926932581 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 1.0745094 2.6781094 0.25100029 ;
	setAttr ".rs" 33701;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" 1.0172343550690777 2.6751611043904107 0.10090086009743041 ;
	setAttr ".cbx" -type "double3" 1.1317843023832639 2.6810576726887505 0.40109968045564154 ;
	setAttr ".raf" no;
createNode polyTweak -n "wateringCan:polyTweak28";
	rename -uid "A2FA6FA5-4C88-71DC-DFE8-F7AA757669DC";
	setAttr ".uopa" yes;
	setAttr -s 4 ".tk[20:23]" -type "float3"  -0.001624506 0.097483426 0
		 -0.0016245097 0.097483426 0 -0.0016245097 0.097483426 0 -0.001624506 0.097483426
		 0;
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace26";
	rename -uid "5B706A0E-4AF7-FCA2-17EF-96A2ADD09415";
	setAttr ".ics" -type "componentList" 1 "f[1]";
	setAttr ".ix" -type "matrix" 0.96712754236691534 0 0.25429179458907103 0 0 1 0 0
		 -0.25429179458907103 0 0.96712754236691534 0 1.016336118328915 2.3213605393860619 0.23993364926932581 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 1.0760804 2.580626 0.25141335 ;
	setAttr ".rs" 37604;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" 1.0188053950542768 2.5776776482556145 0.10131395559148018 ;
	setAttr ".cbx" -type "double3" 1.1333554612618812 2.5835743357632439 0.40151276248567863 ;
	setAttr ".raf" no;
createNode polyTweak -n "wateringCan:polyTweak27";
	rename -uid "0B60B113-43F8-4934-3973-EFABA4133E8A";
	setAttr ".uopa" yes;
	setAttr -s 4 ".tk[16:19]" -type "float3"  0.021617936 0.074062087 0
		 0.021180915 0.079958759 0 0.021180915 0.079958759 0 0.021617936 0.074062087 0;
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace25";
	rename -uid "87639835-446C-0881-6E4A-06ADFFB53C83";
	setAttr ".ics" -type "componentList" 1 "f[1]";
	setAttr ".ix" -type "matrix" 0.96712754236691534 0 0.25429179458907103 0 0 1 0 0
		 -0.25429179458907103 0 0.96712754236691534 0 1.016336118328915 2.3213605393860619 0.23993364926932581 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 1.0553845 2.5036156 0.24597165 ;
	setAttr ".rs" 45694;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" 0.99789814998485626 2.5036156584713738 0.095816675824297398 ;
	setAttr ".cbx" -type "double3" 1.1128708712988358 2.5036156584713738 0.39612661458513954 ;
	setAttr ".raf" no;
createNode polyTweak -n "wateringCan:polyTweak26";
	rename -uid "750F17E2-4519-AE6E-C486-8386E875E486";
	setAttr ".uopa" yes;
	setAttr -s 4 ".tk[12:15]" -type "float3"  0.023744274 0.046791174 -4.6566129e-10
		 0.023744276 0.046791166 -4.6566129e-10 0.023744276 0.046791166 -4.6566129e-10 0.023744274
		 0.046791174 -4.6566129e-10;
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace24";
	rename -uid "84F84441-4E60-B196-EC1B-16917D5AEA75";
	setAttr ".ics" -type "componentList" 1 "f[1]";
	setAttr ".ix" -type "matrix" 0.96712754236691534 0 0.25429179458907103 0 0 1 0 0
		 -0.25429179458907103 0 0.96712754236691534 0 1.016336118328915 2.3213605393860619 0.23993364926932581 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 1.0324208 2.4568245 0.23993365 ;
	setAttr ".rs" 42146;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" 0.97493445733110284 2.4568244327996056 0.08977868576127121 ;
	setAttr ".cbx" -type "double3" 1.0899070653423226 2.4568244327996056 0.39008862255716059 ;
	setAttr ".raf" no;
createNode polyTweak -n "wateringCan:polyTweak25";
	rename -uid "C131E9EA-4A29-485C-E50D-E49D996F9046";
	setAttr ".uopa" yes;
	setAttr -s 4 ".tk[8:11]" -type "float3"  0.015555909 0.035463996 -0.0040901951
		 0.015555909 0.035463996 -0.0040901951 0.015555909 0.035463996 -0.0040901951 0.015555909
		 0.035463996 -0.0040901951;
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace23";
	rename -uid "66399D36-4204-2D9C-625E-91B10A306876";
	setAttr ".ics" -type "componentList" 1 "f[1]";
	setAttr ".ix" -type "matrix" 0.96712754236691534 0 0.25429179458907103 0 0 1 0 0
		 -0.25429179458907103 0 0.96712754236691534 0 1.016336118328915 2.3213605393860619 0.23993364926932581 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 1.0163361 2.4213605 0.23993365 ;
	setAttr ".rs" 64584;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" 0.95884979720985852 2.421360540876178 0.089778676371655042 ;
	setAttr ".cbx" -type "double3" 1.0738224394479714 2.421360540876178 0.39008862216699658 ;
	setAttr ".raf" no;
createNode polyCube -n "wateringCan:polyCube3";
	rename -uid "C7AA6C9E-4466-DF47-0900-EB94B4896D9A";
	setAttr ".w" 0.04;
	setAttr ".h" 0.2;
	setAttr ".d" 0.3;
	setAttr ".cuv" 4;
createNode groupId -n "wateringCan:groupId7";
	rename -uid "0A53AC39-4792-D700-4771-DCB094F39AAB";
	setAttr ".ihi" 0;
createNode groupId -n "wateringCan:groupId8";
	rename -uid "BECF23BC-4195-0DD9-E6DA-59B80A343FC0";
	setAttr ".ihi" 0;
createNode groupId -n "wateringCan:groupId9";
	rename -uid "6D6A2CC6-46DF-A767-8F8A-A2A0DCE86ABA";
	setAttr ".ihi" 0;
createNode groupId -n "wateringCan:groupId10";
	rename -uid "904FB744-4C09-1D34-52AA-69B2DE44DE59";
	setAttr ".ihi" 0;
createNode groupId -n "wateringCan:groupId13";
	rename -uid "325F71E0-4FF7-EF91-542C-B39850995D73";
	setAttr ".ihi" 0;
createNode groupParts -n "wateringCan:groupParts7";
	rename -uid "C41BE9BD-470B-3D26-1967-14BF5AEBEB53";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:85]";
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace22";
	rename -uid "0570B078-4E5A-6A6F-458C-CC8C609CC3BD";
	setAttr ".ics" -type "componentList" 1 "f[78]";
	setAttr ".ix" -type "matrix" 1.2531528150304228 0 0.29962647031706074 0 0 1 0 0 -0.23254347552230845 0 0.97258600236277593 0
		 0.26976958751036151 2.3173201672394028 -1.0064448189943838 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 0.26911068 0.92334133 -1.0053821 ;
	setAttr ".rs" 42692;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" 0.14379534744433758 0.92334121387789159 -1.0554177896542363 ;
	setAttr ".cbx" -type "double3" 0.39442600829489971 0.92334145229647069 -0.955346223324399 ;
	setAttr ".raf" no;
createNode polyTweak -n "wateringCan:polyTweak24";
	rename -uid "8F9A9395-4806-3DEA-8549-DE807A8B8810";
	setAttr ".uopa" yes;
	setAttr -s 4 ".tk[80:83]" -type "float3"  0.0072456221 0 0.039045919
		 0.0072456221 0 0.039045919 0.0072456221 0 0.039045919 0.0072456221 0 0.039045919;
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace21";
	rename -uid "A9CE0646-4E8A-2DC3-88B8-A089374BBD28";
	setAttr ".ics" -type "componentList" 1 "f[1]";
	setAttr ".ix" -type "matrix" 1.2531528150304228 0 0.29962647031706074 0 0 1 0 0 -0.23254347552230845 0 0.97258600236277593 0
		 0.26976958751036151 2.3173201672394028 -1.0064448189943838 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 0.26911655 0.94334084 -1.0254796 ;
	setAttr ".rs" 37655;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" 0.14379537302075421 0.92334121387789159 -1.055466354560564 ;
	setAttr ".cbx" -type "double3" 0.39443773095761225 0.96334046047518163 -0.99549281909950138 ;
	setAttr ".raf" no;
createNode polyTweak -n "wateringCan:polyTweak23";
	rename -uid "80BC0D2F-4097-6C89-621F-C19D4E7C0C08";
	setAttr ".uopa" yes;
	setAttr -s 65 ".tk[16:80]" -type "float3"  -0.00095673651 0.015802115
		 -0.08637929 -0.00095673651 0.015802115 -0.08637929 -0.00095673651 0.015802115 -0.086379319
		 -0.00095673651 0.015802115 -0.086379319 -0.00095673651 0.015802115 -0.086379379 -0.00095673651
		 0.015802115 -0.086379379 -0.00095673651 0.015802115 -0.086379379 -0.00095673651 0.015802115
		 -0.086379379 -0.00095673651 0.015802115 -0.086379409 -0.00095673651 0.015802115 -0.086379409
		 -0.00095673651 0.015802056 -0.086379409 -0.00095673651 0.015802056 -0.086379409 0.0065493956
		 0.020494804 -0.10861343 0.0065493956 0.020494804 -0.10861343 0.0065493956 0.020494804
		 -0.10861343 0.0065493956 0.020494804 -0.10861343 0.0065493956 0.032629721 -0.10861343
		 0.0065493956 0.032629721 -0.10861343 0.0065493956 0.032629736 -0.10861343 0.0065493956
		 0.032629736 -0.10861343 0.0065493956 0.032629743 -0.10861343 0.0065493956 0.032629743
		 -0.10861343 0.0065493956 0.032629743 -0.10861343 0.0065493956 0.032629743 -0.10861343
		 0.001730693 0.028523233 -0.13344941 0.001730693 0.028523233 -0.13344941 0.001730693
		 0.028523233 -0.13344941 0.001730693 0.028523233 -0.13344941 0.0065493956 0.032629848
		 -0.10861361 0.0065493956 0.032629848 -0.10861361 0.0065493956 0.032629877 -0.10861337
		 0.0065493956 0.032629877 -0.10861337 -0.00095673651 0.015802085 -0.086379409 -0.00095673651
		 0.015802085 -0.086379409 -0.00095673651 0.015802085 -0.086379409 -0.00095673651 0.015802085
		 -0.086379409 0.0031178445 0.015802085 -0.065378703 0.0031178445 0.015802085 -0.065378703
		 0.0031178445 0.015802085 -0.065378703 0.0031178445 0.015802085 -0.065378703 -0.00095673651
		 0.015802085 -0.086379409 -0.00095673651 0.015802085 -0.086379409 -0.00095673651 0.015802085
		 -0.08637929 -0.00095673651 0.015802085 -0.08637929 -0.00095673651 0.015802026 -0.086379409
		 -0.00095673651 0.015802026 -0.086379409 -0.00095673651 0.015802026 -0.086379409 -0.00095673651
		 0.015802026 -0.086379409 -0.00095673651 0.015802026 -0.086379409 -0.00095673651 0.015802026
		 -0.086379409 -0.00095673651 0.015802026 -0.086379409 -0.00095673651 0.015802026 -0.086379409
		 -0.00095673651 0.015802026 -0.086379349 -0.00095673651 0.015802026 -0.086379349 -0.00095673651
		 0.015802026 -0.086379349 -0.00095673651 0.015802026 -0.086379349 -0.00095673651 0.015802026
		 -0.086379349 -0.00095673651 0.015802026 -0.086379349 -0.00095673651 0.015802026 -0.086379349
		 -0.00095673651 0.015802026 -0.086379349 -0.0080849277 0.00029623508 0.192809 -0.0080849277
		 0.00029623508 0.192809 -0.0080849277 0.00029623508 0.192809 -0.0080849277 0.00029623508
		 0.192809 0 0 0;
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace20";
	rename -uid "9485F2DD-404C-912C-B2E6-34853A12F246";
	setAttr ".ics" -type "componentList" 1 "f[1]";
	setAttr ".ix" -type "matrix" 1.2358501463487839 0 0.36447553457402743 0 0 1 0 0 -0.28287356408466691 0 0.95915720647975 0
		 0.25804789449151511 2.3173201672394028 -1.0142715838919354 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 0.32291925 0.9430446 -1.2153019 ;
	setAttr ".rs" 41832;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" 0.19932709470036403 0.9230449787933579 -1.2517731693723628 ;
	setAttr ".cbx" -type "double3" 0.44651142853369058 0.96304422539064793 -1.1788305849301639 ;
	setAttr ".raf" no;
createNode polyTweak -n "wateringCan:polyTweak22";
	rename -uid "F75D5027-48F4-B428-0D79-E6ACF9D736DB";
	setAttr ".uopa" yes;
	setAttr -s 4 ".tk[72:75]" -type "float3"  3.4272671e-07 -0.081515945
		 0.227586 3.4272671e-07 -0.081515983 0.22758602 3.4272671e-07 -0.081080511 0.22164962
		 3.4272671e-07 -0.081080407 0.2216495;
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace19";
	rename -uid "28062DE9-4911-01E3-55A2-45BCE4F097CE";
	setAttr ".ics" -type "componentList" 1 "f[1]";
	setAttr ".ix" -type "matrix" 1.2358501463487839 0 0.36447553457402743 0 0 1 0 0 -0.28287356408466691 0 0.95915720647975 0
		 0.25804789449151511 2.3173201672394028 -1.0142715838919354 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 0.38645718 1.0243428 -1.430746 ;
	setAttr ".rs" 52154;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" 0.26203952547700821 1.0045610062439194 -1.4700162666622636 ;
	setAttr ".cbx" -type "double3" 0.51087481873690943 1.0441246620971909 -1.3914755826910323 ;
	setAttr ".raf" no;
createNode polyTweak -n "wateringCan:polyTweak21";
	rename -uid "2F74C412-4C5E-F86C-2919-0CA4E6F7E6C6";
	setAttr ".uopa" yes;
	setAttr -s 4 ".tk[68:71]" -type "float3"  4.8428774e-07 -0.10361359
		 0.2621237 4.8428774e-07 -0.10361365 0.26212379 4.8428774e-07 -0.10122087 0.25323665
		 4.8428774e-07 -0.10122067 0.25323641;
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace18";
	rename -uid "3EC3D418-4012-7060-A121-EBBFFA50866D";
	setAttr ".ics" -type "componentList" 1 "f[1]";
	setAttr ".ix" -type "matrix" 1.2358501463487839 0 0.36447553457402743 0 0 1 0 0 -0.28287356408466691 0 0.95915720647975 0
		 0.25804789449151511 2.3173201672394028 -1.0142715838919354 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 0.4593474 1.12676 -1.6779019 ;
	setAttr ".rs" 32840;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" 0.33367277684062729 1.1081746212799302 -1.7214342882435463 ;
	setAttr ".cbx" -type "double3" 0.58502202292201932 1.1453453890640488 -1.6343693985853693 ;
	setAttr ".raf" no;
createNode polyTweak -n "wateringCan:polyTweak20";
	rename -uid "9FF912C7-458C-6E62-749A-4B91366855B8";
	setAttr ".uopa" yes;
	setAttr -s 4 ".tk[64:67]" -type "float3"  1.6391277e-07 -0.13078833
		 0.17398524 1.6391277e-07 -0.1307884 0.17398526 1.6391277e-07 -0.12551069 0.16461846
		 1.6391277e-07 -0.12551044 0.16461834;
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace17";
	rename -uid "FBF0116E-4F60-3550-FB65-1FA4F7521F79";
	setAttr ".ics" -type "componentList" 1 "f[1]";
	setAttr ".ix" -type "matrix" 1.2358501463487839 0 0.36447553457402743 0 0 1 0 0 -0.28287356408466691 0 0.95915720647975 0
		 0.25804789449151511 2.3173201672394028 -1.0142715838919354 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 0.50723821 1.2549094 -1.840289 ;
	setAttr ".rs" 65066;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" 0.38023872485372223 1.2389630667526474 -1.8883135529114456 ;
	setAttr ".cbx" -type "double3" 0.63423766450731023 1.2708558432419053 -1.7922643624611534 ;
	setAttr ".raf" no;
createNode polyTweak -n "wateringCan:polyTweak19";
	rename -uid "E246C128-452A-60DA-E0F9-83AC608ED74B";
	setAttr ".uopa" yes;
	setAttr -s 4 ".tk[60:63]" -type "float3"  1.6406082e-07 -0.15661713
		 0.11653208 1.6406084e-07 -0.15661718 0.11653209 1.6376472e-07 -0.14846677 0.10848226
		 1.6376471e-07 -0.14846651 0.10848219;
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace16";
	rename -uid "A670EED6-42C7-56AB-F121-1F9612F0EBE4";
	setAttr ".ics" -type "componentList" 1 "f[1]";
	setAttr ".ix" -type "matrix" 1.2358501463487839 0 0.36447553457402743 0 0 1 0 0 -0.28287356408466691 0 0.95915720647975 0
		 0.25804789449151511 2.3173201672394028 -1.0142715838919354 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 0.53906327 1.4074513 -1.9482011 ;
	setAttr ".rs" 65139;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" 0.41092524378082201 1.3955802313644639 -2.0000863292012161 ;
	setAttr ".cbx" -type "double3" 0.66720127508667437 1.4193223707039109 -1.8963157962521335 ;
	setAttr ".raf" no;
createNode polyTweak -n "wateringCan:polyTweak18";
	rename -uid "98E7A191-48C1-1B90-58FB-4B89E3BEAE45";
	setAttr ".uopa" yes;
	setAttr -s 4 ".tk[56:59]" -type "float3"  -1.7069679e-15 -0.14139424
		 0.061459683 -1.8041124e-16 -0.14139424 0.061459683 -1.9428903e-16 -0.13347329 0.056912579
		 -1.7208457e-15 -0.13347311 0.056912586;
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace15";
	rename -uid "45A88277-4EC5-B708-845C-98B0B4E72A9F";
	setAttr ".ics" -type "componentList" 1 "f[1]";
	setAttr ".ix" -type "matrix" 1.2358501463487839 0 0.36447553457402743 0 0 1 0 0 -0.28287356408466691 0 0.95915720647975 0
		 0.25804789449151511 2.3173201672394028 -1.0142715838919354 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 0.55580539 1.544885 -2.0049698 ;
	setAttr ".rs" 65145;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" 0.42702426491630102 1.5369744293052903 -2.0590358190842228 ;
	setAttr ".cbx" -type "double3" 0.68458650543804467 1.5527955881912461 -1.9509039412129126 ;
	setAttr ".raf" no;
createNode polyTweak -n "wateringCan:polyTweak17";
	rename -uid "A453D048-408D-6812-6D4C-D384DFE25B91";
	setAttr ".uopa" yes;
	setAttr -s 4 ".tk[52:55]" -type "float3"  1.7154287e-07 -0.15518685
		 -0.0097584296 1.7154287e-07 -0.15518683 -0.0097584277 1.7118384e-07 -0.1362655 -0.01290008
		 1.7118383e-07 -0.1362652 -0.012899984;
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace14";
	rename -uid "0E571E8E-4379-690E-A00D-22881D8C9492";
	setAttr ".ics" -type "componentList" 1 "f[1]";
	setAttr ".ix" -type "matrix" 1.2358501463487839 0 0.36447553457402743 0 0 1 0 0 -0.28287356408466691 0 0.95915720647975 0
		 0.25804789449151511 2.3173201672394028 -1.0142715838919354 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 0.55260038 1.690611 -1.9941034 ;
	setAttr ".rs" 61598;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" 0.42337494878573245 1.6890607468445054 -2.0496759832366105 ;
	setAttr ".cbx" -type "double3" 0.68182580611634203 1.6921612612564316 -1.9385307771683493 ;
	setAttr ".raf" no;
createNode polyTweak -n "wateringCan:polyTweak16";
	rename -uid "25BC3760-4A7B-AF61-07FA-84B147B6A340";
	setAttr ".uopa" yes;
	setAttr -s 4 ".tk[48:51]" -type "float3"  -5.5511151e-16 -0.13155958
		 -0.046441261 8.6042284e-16 -0.13155958 -0.046441261 8.6042284e-16 -0.12115408 -0.044212632
		 -5.5511151e-16 -0.12115392 -0.044212531;
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace13";
	rename -uid "B7E05ECC-4E23-8A7E-F1E3-A292DA8E5480";
	setAttr ".ics" -type "componentList" 1 "f[1]";
	setAttr ".ix" -type "matrix" 1.2358501463487839 0 0.36447553457402743 0 0 1 0 0 -0.28287356408466691 0 0.95915720647975 0
		 0.25804789449151511 2.3173201672394028 -1.0142715838919354 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 0.53977859 1.8169677 -1.9506276 ;
	setAttr ".rs" 63292;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" 0.41086838033595358 1.8102146975357285 -2.0051313971355538 ;
	setAttr ".cbx" -type "double3" 0.66868878692263434 1.8237208418209305 -1.896123796626406 ;
	setAttr ".raf" no;
createNode polyTweak -n "wateringCan:polyTweak15";
	rename -uid "5A5A70E4-4D24-410C-BFC4-A0A1B9A91066";
	setAttr ".uopa" yes;
	setAttr -s 4 ".tk[44:47]" -type "float3"  7.4505806e-08 -0.28202453
		 -0.12849136 7.4505806e-08 -0.28202453 -0.12849136 7.4505806e-08 -0.27893844 -0.12723704
		 7.4505806e-08 -0.27893844 -0.12723701;
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace12";
	rename -uid "F51AB48C-494D-B721-AAAE-4686E2148598";
	setAttr ".ics" -type "componentList" 1 "f[1]";
	setAttr ".ix" -type "matrix" 1.2358501463487839 0 0.36447553457402743 0 0 1 0 0 -0.28287356408466691 0 0.95915720647975 0
		 0.25804789449151511 2.3173201672394028 -1.0142715838919354 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 0.50360906 2.0974493 -1.8279858 ;
	setAttr ".rs" 56383;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" 0.37487628152246766 2.0891532145101777 -1.8818879812685831 ;
	setAttr ".cbx" -type "double3" 0.63234183726812265 2.1057454786855927 -1.774083460103195 ;
	setAttr ".raf" no;
createNode polyTweak -n "wateringCan:polyTweak14";
	rename -uid "D1EE0EF0-4B72-2FAC-C5B7-558B1848BFEA";
	setAttr ".uopa" yes;
	setAttr -s 4 ".tk[40:43]" -type "float3"  0 -0.15848054 -0.072246969
		 0 -0.15848054 -0.072246969 0 -0.15848054 -0.072246969 0 -0.15848054 -0.072246969;
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace11";
	rename -uid "3B1C3AED-4A8A-CEBC-2F2D-69A100C66BF9";
	setAttr ".ics" -type "componentList" 1 "f[1]";
	setAttr ".ix" -type "matrix" 1.2358501463487839 0 0.36447553457402743 0 0 1 0 0 -0.28287356408466691 0 0.95915720647975 0
		 0.25804789449151511 2.3173201672394028 -1.0142715838919354 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 0.48317227 2.2559299 -1.7586894 ;
	setAttr ".rs" 64440;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" 0.35443950711834238 2.2476336948234787 -1.8125916716400219 ;
	setAttr ".cbx" -type "double3" 0.61190502758781684 2.2642260558564415 -1.7047872076448582 ;
	setAttr ".raf" no;
createNode polyTweak -n "wateringCan:polyTweak13";
	rename -uid "3D688278-44D9-5250-6A71-59957A1697DA";
	setAttr ".uopa" yes;
	setAttr -s 4 ".tk[36:39]" -type "float3"  1.5127707e-08 -0.098340712
		 -0.075449333 1.5127707e-08 -0.098340712 -0.075449325 1.4674616e-08 -0.090448938 -0.070684128
		 1.4674612e-08 -0.090448916 -0.070684001;
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace10";
	rename -uid "625DBCCD-4DA7-492A-FC80-A4A6CC681CEF";
	setAttr ".ics" -type "componentList" 1 "f[1]";
	setAttr ".ix" -type "matrix" 1.2358501463487839 0 0.36447553457402743 0 0 1 0 0 -0.28287356408466691 0 0.95915720647975 0
		 0.25804789449151511 2.3173201672394028 -1.0142715838919354 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 0.46250355 2.3503246 -1.688607 ;
	setAttr ".rs" 35663;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" 0.33444479555168782 2.3380826480347863 -1.7402238453881087 ;
	setAttr ".cbx" -type "double3" 0.59056233275641434 2.3625668055970421 -1.6369900728153528 ;
	setAttr ".raf" no;
createNode polyTweak -n "wateringCan:polyTweak12";
	rename -uid "BDD1AB64-48D9-A6E0-3C3C-DCB2901182C6";
	setAttr ".uopa" yes;
	setAttr -s 4 ".tk[32:35]" -type "float3"  0 -0.11636706 -0.090074837
		 0 -0.11636706 -0.090074837 0 -0.11636706 -0.090074837 0 -0.11636706 -0.090074837;
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace9";
	rename -uid "E0AF3478-4797-95FA-E42A-AAA0F66D20ED";
	setAttr ".ics" -type "componentList" 1 "f[1]";
	setAttr ".ix" -type "matrix" 1.2358501463487839 0 0.36447553457402743 0 0 1 0 0 -0.28287356408466691 0 0.95915720647975 0
		 0.25804789449151511 2.3173201672394028 -1.0142715838919354 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 0.43702376 2.4666917 -1.602211 ;
	setAttr ".rs" 39353;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" 0.30896498845579456 2.4544497720558396 -1.6538279215888714 ;
	setAttr ".cbx" -type "double3" 0.56508250568989493 2.4789338402111283 -1.5505939829365503 ;
	setAttr ".raf" no;
createNode polyTweak -n "wateringCan:polyTweak11";
	rename -uid "C2CD6028-4FFE-27AC-9E7C-508684253BE6";
	setAttr ".uopa" yes;
	setAttr -s 4 ".tk[28:31]" -type "float3"  2.3282982e-10 -0.087760769
		 -0.12883607 7.2767764e-12 -0.087760717 -0.12883602 8.0491169e-16 -0.079039603 -0.11950759
		 3.6378955e-11 -0.079039522 -0.11950748;
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace8";
	rename -uid "ECD44E0D-4A75-AAB5-2441-7D9BDE3CF7D1";
	setAttr ".ics" -type "componentList" 1 "f[1]";
	setAttr ".ix" -type "matrix" 1.2358501463487839 0 0.36447553457402743 0 0 1 0 0 -0.28287356408466691 0 0.95915720647975 0
		 0.25804789449151511 2.3173201672394028 -1.0142715838919354 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 0.4018988 2.550092 -1.4831105 ;
	setAttr ".rs" 61242;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" 0.27515945152941967 2.5334891818125 -1.5302537951251924 ;
	setAttr ".cbx" -type "double3" 0.52863816335969094 2.5666946611959687 -1.4359673396403601 ;
	setAttr ".raf" no;
createNode polyTweak -n "wateringCan:polyTweak10";
	rename -uid "9E94C61E-4E5D-8525-16F6-EE8A3A0507F9";
	setAttr ".uopa" yes;
	setAttr -s 4 ".tk[24:27]" -type "float3"  -3.2751579e-15 -0.034116659
		 -0.13154183 1.637579e-15 -0.034116637 -0.13154183 1.637579e-15 -0.028516861 -0.11894292
		 -3.2751579e-15 -0.028516874 -0.1189427;
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace7";
	rename -uid "46B59C48-465E-E4A4-3419-E4A83107E0EC";
	setAttr ".ics" -type "componentList" 1 "f[1]";
	setAttr ".ix" -type "matrix" 1.2358501463487839 0 0.36447553457402743 0 0 1 0 0 -0.28287356408466691 0 0.95915720647975 0
		 0.25804789449151511 2.3173201672394028 -1.0142715838919354 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 0.36647105 2.5814087 -1.3629833 ;
	setAttr ".rs" 45532;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" 0.24151365172189321 2.5620061300356141 -1.40408434056155 ;
	setAttr ".cbx" -type "double3" 0.49142846192328565 2.6008112422783127 -1.3218823487762372 ;
	setAttr ".raf" no;
createNode polyTweak -n "wateringCan:polyTweak9";
	rename -uid "8873BF5D-4CF6-7C1B-B09F-9FBA9F485641";
	setAttr ".uopa" yes;
	setAttr -s 20 ".tk";
	setAttr ".tk[2]" -type "float3" 0.0041548684 0.025291532 -0.0017910171 ;
	setAttr ".tk[3]" -type "float3" 0.0041548684 0.025291532 -0.0017910171 ;
	setAttr ".tk[4]" -type "float3" 0.0041548684 0.025291532 -0.001791019 ;
	setAttr ".tk[5]" -type "float3" 0.0041548684 0.025291532 -0.001791019 ;
	setAttr ".tk[8]" -type "float3" 0.004154861 0.025751725 0.0015115933 ;
	setAttr ".tk[9]" -type "float3" 0.004154861 0.025751723 0.0015115938 ;
	setAttr ".tk[10]" -type "float3" 0.004154861 0.025751729 0.0015115896 ;
	setAttr ".tk[11]" -type "float3" 0.004154861 0.025751725 0.0015115887 ;
	setAttr ".tk[12]" -type "float3" 0.004154861 0.025751742 0.001511611 ;
	setAttr ".tk[13]" -type "float3" 0.004154861 0.025751742 0.001511611 ;
	setAttr ".tk[14]" -type "float3" 0.004154861 0.025751725 0.0015116041 ;
	setAttr ".tk[15]" -type "float3" 0.004154861 0.025751725 0.0015116034 ;
	setAttr ".tk[16]" -type "float3" 0.004154861 0.046586961 -0.00030636054 ;
	setAttr ".tk[17]" -type "float3" 0.004154861 0.046586961 -0.00030636054 ;
	setAttr ".tk[18]" -type "float3" 0.004154861 0.044323038 0.007490431 ;
	setAttr ".tk[19]" -type "float3" 0.004154861 0.044323001 0.0074904822 ;
	setAttr ".tk[20]" -type "float3" 0.004154861 0.044633552 -0.20887992 ;
	setAttr ".tk[21]" -type "float3" 0.004154861 0.044633552 -0.20887992 ;
	setAttr ".tk[22]" -type "float3" 0.004154861 0.042911462 -0.18418176 ;
	setAttr ".tk[23]" -type "float3" 0.004154861 0.042911366 -0.18418159 ;
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace6";
	rename -uid "AAA5DF73-41FE-442E-AA13-918B1BF2A80F";
	setAttr ".ics" -type "componentList" 1 "f[1]";
	setAttr ".ix" -type "matrix" 1.2358501463487839 0 0.36447553457402743 0 0 1 0 0 -0.28287356408466691 0 0.95915720647975 0
		 0.25804789449151511 2.3173201672394028 -1.0142715838919354 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 0.30574286 2.5376363 -1.1759938 ;
	setAttr ".rs" 44149;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" 0.18003696293523647 2.519094794209694 -1.2196327548359209 ;
	setAttr ".cbx" -type "double3" 0.43144874846153181 2.5561777643520585 -1.1323548903690737 ;
	setAttr ".raf" no;
createNode polyTweak -n "wateringCan:polyTweak8";
	rename -uid "A7759AB4-4453-E92A-2F84-A995A938A295";
	setAttr ".uopa" yes;
	setAttr -s 4 ".tk[16:19]" -type "float3"  -1.6157603e-10 0.038989864
		 -0.092349641 -1.6157248e-10 0.038989868 -0.092349634 1.6157257e-10 0.026916388 -0.076127276
		 1.6157299e-10 0.026916292 -0.076127268;
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace5";
	rename -uid "2AE19B8E-41C8-7CF8-EB3C-F48086E8E378";
	setAttr ".ics" -type "componentList" 1 "f[1]";
	setAttr ".ix" -type "matrix" 1.2358501463487839 0 0.36447553457402743 0 0 1 0 0 -0.28287356408466691 0 0.95915720647975 0
		 0.25804789449151511 2.3173201672394028 -1.0142715838919354 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 0.281914 2.5046833 -1.0951958 ;
	setAttr ".rs" 52384;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" 0.15391368639642816 2.4921785883266678 -1.1466146162790709 ;
	setAttr ".cbx" -type "double3" 0.40991432067886552 2.5171879820186844 -1.0437770425096746 ;
	setAttr ".raf" no;
createNode polyTweak -n "wateringCan:polyTweak7";
	rename -uid "E6B1E8B8-4474-C4CB-435F-67BA8973FA61";
	setAttr ".uopa" yes;
	setAttr -s 8 ".tk";
	setAttr ".tk[0]" -type "float3" 0 0.033775143 0 ;
	setAttr ".tk[1]" -type "float3" 0 0.033775143 0 ;
	setAttr ".tk[6]" -type "float3" 0 0.033775143 0 ;
	setAttr ".tk[7]" -type "float3" 0 0.033775143 0 ;
	setAttr ".tk[12]" -type "float3" 0 0.052434772 -0.061454028 ;
	setAttr ".tk[13]" -type "float3" 0 0.052434772 -0.061454028 ;
	setAttr ".tk[14]" -type "float3" 0 0.052434772 -0.061454035 ;
	setAttr ".tk[15]" -type "float3" 0 0.052434772 -0.061454035 ;
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace4";
	rename -uid "121F76CC-4004-2CEE-EDFC-B292602F1648";
	setAttr ".ics" -type "componentList" 1 "f[1]";
	setAttr ".ix" -type "matrix" 0.95915720647975 0 0.28287356408466691 0 0 1 0 0 -0.28287356408466691 0 0.95915720647975 0
		 0.25668918094335441 2.3173201672394028 -1.0096645083050841 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 0.26317152 2.4522486 -1.0316446 ;
	setAttr ".rs" 40696;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" 0.16284052302136498 2.4397437415678254 -1.0749032323561147 ;
	setAttr ".cbx" -type "double3" 0.36350254555759864 2.4647532097656479 -0.9883860256300353 ;
	setAttr ".raf" no;
createNode polyTweak -n "wateringCan:polyTweak6";
	rename -uid "51B1AED3-40F9-1821-BD0A-2FBB910FECDB";
	setAttr ".uopa" yes;
	setAttr -s 4 ".tk[8:11]" -type "float3"  0 0.047433071 -0.027307291
		 0 0.047433145 -0.027307311 0 0.022423746 -0.018524753 0 0.022423672 -0.018524731;
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace3";
	rename -uid "430EC65D-4C1E-EB67-8D41-A2AB5D7BA9B6";
	setAttr ".ics" -type "componentList" 1 "f[1]";
	setAttr ".ix" -type "matrix" 0.95915720647975 0 0.28287356408466691 0 0 1 0 0 -0.28287356408466691 0 0.95915720647975 0
		 0.25668918094335441 2.3173201672394028 -1.0096645083050841 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 0.25668919 2.4173203 -1.0096645 ;
	setAttr ".rs" 45457;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" 0.15511598771088481 2.4173201687295189 -1.0571350088358835 ;
	setAttr ".cbx" -type "double3" 0.35826237417582402 2.4173201687295189 -0.96219400777428465 ;
	setAttr ".raf" no;
createNode polyCube -n "wateringCan:polyCube2";
	rename -uid "1FBA6DBB-4CFF-AF85-6291-7E829AE3E34B";
	setAttr ".w" 0.2;
	setAttr ".h" 0.2;
	setAttr ".d" 0.04;
	setAttr ".cuv" 4;
createNode groupId -n "wateringCan:groupId14";
	rename -uid "67F0D212-4F66-22EF-B3F3-EC80C75E43DB";
	setAttr ".ihi" 0;
createNode groupId -n "wateringCan:groupId15";
	rename -uid "17E7C67B-429F-9AD2-CBCD-91A809BE4926";
	setAttr ".ihi" 0;
createNode groupParts -n "wateringCan:groupParts8";
	rename -uid "7A2E641A-4329-445A-05B2-1087420C831A";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:66]";
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace41";
	rename -uid "CBB4803F-4B9C-0518-97FE-ADA68A23B1C9";
	setAttr ".ics" -type "componentList" 1 "f[4:12]";
	setAttr ".ix" -type "matrix" 0.98069233116912879 -0.036382743576720881 0.19214277908859945 0
		 -0.119995648565457 0.66386790509550797 0.73816017835525172 0 -0.15441371672042317 -0.74696432348133757 0.64668439252440035 0
		 -0.26765260328674439 0.47581163900773871 0.93300546418808539 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" -0.58725095 2.2470787 2.905365 ;
	setAttr ".rs" 49089;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" -0.76219415158581194 2.115428379494249 2.7866803853395616 ;
	setAttr ".cbx" -type "double3" -0.41230771603667982 2.3787287406763786 3.0240496161832437 ;
	setAttr ".raf" no;
createNode polyTweak -n "wateringCan:polyTweak41";
	rename -uid "2E95B1A8-449C-76E4-B2FD-A5A3FCBF5C2E";
	setAttr ".uopa" yes;
	setAttr -s 10 ".tk[50:59]" -type "float3"  0.042499714 0 -0.035661459
		 0.0096338131 0 -0.054636523 -3.1956006e-08 0 -1.3613317e-07 -0.027739652 0 -0.048046276
		 -0.052132942 0 -0.018975087 -0.052132614 0 0.018975005 -0.027739534 0 0.048046231
		 0.0096336827 0 0.054636505 0.042499803 0 0.035661284 0.055479091 -1.0913936e-11 7.8871381e-08;
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace40";
	rename -uid "EE2EA7E3-4575-3BC5-0E24-1C8900FE7A98";
	setAttr ".ics" -type "componentList" 1 "f[4:12]";
	setAttr ".ix" -type "matrix" 0.98069233116912879 -0.036382743576720881 0.19214277908859945 0
		 -0.119995648565457 0.66386790509550797 0.73816017835525172 0 -0.15441371672042317 -0.74696432348133757 0.64668439252440035 0
		 -0.26765260328674439 0.47581163900773871 0.93300546418808539 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" -0.5874269 2.2474291 2.9049737 ;
	setAttr ".rs" 36143;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" -0.70813809395698457 2.1565904713451429 2.8230810391078625 ;
	setAttr ".cbx" -type "double3" -0.46671568650214279 2.3382676450328512 2.986866247425001 ;
	setAttr ".raf" no;
createNode deleteComponent -n "wateringCan:deleteComponent9";
	rename -uid "91615F61-46B1-DA8B-B0B8-F98E4D8B579B";
	setAttr ".dc" -type "componentList" 1 "f[0]";
createNode deleteComponent -n "wateringCan:deleteComponent8";
	rename -uid "514E95EC-4E12-DA5C-128F-2A9D3E82FB86";
	setAttr ".dc" -type "componentList" 1 "f[5]";
createNode deleteComponent -n "wateringCan:deleteComponent7";
	rename -uid "EAD18019-4F6D-BC4B-CDAE-5687DACD0D29";
	setAttr ".dc" -type "componentList" 1 "f[0:2]";
createNode deleteComponent -n "wateringCan:deleteComponent6";
	rename -uid "6E7C8468-4373-221A-CFAC-07BD3E2CB8B4";
	setAttr ".dc" -type "componentList" 1 "f[9:17]";
createNode polyTweak -n "wateringCan:polyTweak40";
	rename -uid "8AA97565-4298-1BB4-4844-E8A7DC377385";
	setAttr ".uopa" yes;
	setAttr -s 10 ".tk[46:55]" -type "float3"  -3.7252903e-08 0.3854959 2.3841858e-07
		 -3.0919909e-07 0.3854959 2.3841858e-07 -2.8251088e-07 0.3854959 2.3850589e-08 -3.1664968e-07
		 0.3854959 2.3841858e-07 -3.7252903e-08 0.3854959 1.8253922e-07 -3.7252903e-08 0.3854959
		 1.8253922e-07 -3.1664968e-07 0.3854959 2.3841858e-07 -3.0919909e-07 0.3854959 2.3841858e-07
		 -3.7252903e-08 0.3854959 2.3841858e-07 -3.7252903e-08 0.3854959 2.3850589e-08;
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace39";
	rename -uid "3F23219D-4FB4-ECDA-2863-7599C930AE66";
	setAttr ".ics" -type "componentList" 1 "f[18:26]";
	setAttr ".ix" -type "matrix" 0.98069233116912879 -0.036382743576720881 0.19214277908859945 0
		 -0.119995648565457 0.66386790509550797 0.73816017835525172 0 -0.15441371672042317 -0.74696432348133757 0.64668439252440035 0
		 -0.26765260328674439 0.47581163900773871 0.93300546418808539 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" -0.54116899 1.991511 2.6204157 ;
	setAttr ".rs" 52717;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" -0.66188022629779164 1.9006723879743523 2.5385232067651962 ;
	setAttr ".cbx" -type "double3" -0.42045773731959207 2.0823495672273786 2.7023083362020786 ;
	setAttr ".raf" no;
createNode polyTweak -n "wateringCan:polyTweak39";
	rename -uid "01720079-4555-9BA5-36AF-678120E4E7A0";
	setAttr ".uopa" yes;
	setAttr -s 26 ".tk";
	setAttr ".tk[9]" -type "float3" 0 0 7.4505806e-09 ;
	setAttr ".tk[12]" -type "float3" 0 -1.1641532e-10 0 ;
	setAttr ".tk[13]" -type "float3" 0 0 -1.4901161e-08 ;
	setAttr ".tk[16]" -type "float3" 0 -9.3132257e-10 -7.4505806e-09 ;
	setAttr ".tk[17]" -type "float3" 0 2.3283064e-10 0 ;
	setAttr ".tk[19]" -type "float3" 0 -9.3132257e-10 0 ;
	setAttr ".tk[22]" -type "float3" 0 0 2.3283064e-10 ;
	setAttr ".tk[23]" -type "float3" 0 0 2.3283064e-10 ;
	setAttr ".tk[25]" -type "float3" 0 -9.3132257e-10 0 ;
	setAttr ".tk[26]" -type "float3" 0 4.6566129e-10 -2.3283064e-10 ;
	setAttr ".tk[27]" -type "float3" 0 0 -2.3283064e-10 ;
	setAttr ".tk[28]" -type "float3" 0 9.3132257e-10 0 ;
	setAttr ".tk[30]" -type "float3" 0 0 3.7252903e-09 ;
	setAttr ".tk[32]" -type "float3" 0 5.8207661e-11 3.7252903e-09 ;
	setAttr ".tk[34]" -type "float3" 0 0 -3.7252903e-09 ;
	setAttr ".tk[36]" -type "float3" 0 0 -3.7252903e-09 ;
	setAttr ".tk[37]" -type "float3" -1.4901161e-08 0.4830673 1.3411045e-07 ;
	setAttr ".tk[38]" -type "float3" -1.5832484e-07 0.48306727 1.1920929e-07 ;
	setAttr ".tk[39]" -type "float3" -1.5884871e-07 0.48306721 1.937151e-07 ;
	setAttr ".tk[40]" -type "float3" -1.2665987e-07 0.4830673 1.2665987e-07 ;
	setAttr ".tk[41]" -type "float3" -1.4901161e-08 0.48306724 1.6391277e-07 ;
	setAttr ".tk[42]" -type "float3" -1.4901161e-08 0.48306733 1.6391277e-07 ;
	setAttr ".tk[43]" -type "float3" -1.2665987e-07 0.4830673 1.3411045e-07 ;
	setAttr ".tk[44]" -type "float3" -1.5832484e-07 0.48306727 1.2665987e-07 ;
	setAttr ".tk[45]" -type "float3" -1.4901161e-08 0.48306727 1.2665987e-07 ;
	setAttr ".tk[46]" -type "float3" -1.4901161e-08 0.48306721 2.0116568e-07 ;
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace38";
	rename -uid "0648C79A-4797-E236-776D-15BF86657E54";
	setAttr ".ics" -type "componentList" 1 "f[18:26]";
	setAttr ".ix" -type "matrix" 0.98069233116912891 -0.036382743576720875 0.19214277908859931 0
		 -0.13976640999466583 0.55680846961708064 0.8187977032209407 0 -0.13677683364979126 -0.82984373476728457 0.54097271062801511 0
		 -0.27457383413914377 0.51410288607873866 0.97558181642687614 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" -0.52536488 1.5162277 2.4508815 ;
	setAttr ".rs" 43177;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" -0.64570369622490764 1.4153101741683496 2.3810692783209402 ;
	setAttr ".cbx" -type "double3" -0.40502608683326191 1.6171452736428289 2.5206939067624559 ;
	setAttr ".raf" no;
createNode polyTweak -n "wateringCan:polyTweak38";
	rename -uid "855430BC-433D-6EF1-3BA2-BF802D016AB2";
	setAttr ".uopa" yes;
	setAttr -s 10 ".tk[28:37]" -type "float3"  -0.014646528 0.59865046 0.012486962
		 -0.0032242243 0.59865046 0.019081719 0.000123986 0.59865046 9.2695882e-05 0.009765109
		 0.59865046 0.016791413 0.018243143 0.59865046 0.0066876365 0.018243143 0.59865046
		 -0.0065019028 0.009765109 0.59865046 -0.016605662 -0.0032242166 0.59865046 -0.018895993
		 -0.014646516 0.59865046 -0.012301243 -0.019157598 0.59865046 9.2720031e-05;
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace37";
	rename -uid "8AA2FAE7-4DF3-384C-5288-0E891F03D065";
	setAttr ".ics" -type "componentList" 1 "f[18:26]";
	setAttr ".ix" -type "matrix" 0.98069233116912891 -0.036382743576720875 0.19214277908859931 0
		 -0.13976640999466583 0.55680846961708064 0.8187977032209407 0 -0.13677683364979126 -0.82984373476728457 0.54097271062801511 0
		 -0.27457383413914377 0.51410288607873866 0.97558181642687614 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" -0.44168359 1.1828538 1.9606489 ;
	setAttr ".rs" 49104;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" -0.5808127184311217 1.0661784935057865 1.8799357518548541 ;
	setAttr ".cbx" -type "double3" -0.30255445380594054 1.2995292322500842 2.041362015141063 ;
	setAttr ".raf" no;
createNode polyTweak -n "wateringCan:polyTweak37";
	rename -uid "B8F3802D-4524-513B-323A-1AA62B195F23";
	setAttr ".uopa" yes;
	setAttr -s 31 ".tk[9:39]" -type "float3"  -3.7252903e-09 1.2759119e-07
		 -2.910383e-11 1.8626451e-09 1.2107193e-07 0 3.7252903e-09 1.1362135e-07 -5.8207661e-11
		 -7.4505806e-09 1.3457611e-07 0 0 1.3364479e-07 -5.8207661e-11 3.7252903e-09 1.1920929e-07
		 1.1641532e-10 -9.3132257e-10 1.2107193e-07 0 -3.7252903e-09 9.778887e-08 -1.1641532e-10
		 7.4505806e-09 1.1921293e-07 0 0 0 0 -0.016496921 1.10282826 0.014064558 -0.0036317867
		 1.10282815 0.021492407 0.0001394126 1.10282815 0.00010465363 0.010998391 1.10282791
		 0.018912762 0.020547705 1.10282815 0.007532631 0.020547716 1.10282815 -0.0073231491
		 0.010998344 1.10282815 -0.018703314 -0.0036317788 1.10282815 -0.02128296 -0.01649694
		 1.10282815 -0.01385509 -0.0215779 1.10282815 0.00010462382 5.9604645e-08 0 -2.9802322e-08
		 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 2.9802322e-08 0 0 -2.9802322e-08 0 0 2.9802322e-08
		 0 0 -2.9802322e-08;
createNode polyExtrudeFace -n "wateringCan:polyExtrudeFace36";
	rename -uid "FA2279A3-42D9-4875-2DF1-FFBEE4334709";
	setAttr ".ics" -type "componentList" 1 "f[18:26]";
	setAttr ".ix" -type "matrix" 0.98069233116912891 -0.036382743576720875 0.19214277908859931 0
		 -0.13976640999466583 0.55680846961708064 0.8187977032209407 0 -0.13677683364979126 -0.82984373476728457 0.54097271062801511 0
		 -0.27457383413914377 0.51410288607873866 0.97558181642687614 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" -0.28753376 0.5687446 1.0575893 ;
	setAttr ".rs" 59430;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" -0.44782699214622179 0.43432082150519996 0.96459834401580458 ;
	setAttr ".cbx" -type "double3" -0.12724054663713438 0.70316841498661331 1.1505802693585467 ;
	setAttr ".raf" no;
createNode polyCylinder -n "wateringCan:polyCylinder3";
	rename -uid "1B445315-494D-550A-2688-20B5A7BDECE3";
	setAttr ".r" 0.16448578734069491;
	setAttr ".h" 0.2;
	setAttr ".sa" 9;
	setAttr ".sc" 1;
	setAttr ".cuv" 3;
createNode groupId -n "wateringCan:groupId16";
	rename -uid "5B175871-448F-C77F-5C67-2CA35F8B7FDE";
	setAttr ".ihi" 0;
createNode groupId -n "wateringCan:groupId17";
	rename -uid "F726D588-4604-2F14-8CE2-8DAD0EAE5825";
	setAttr ".ihi" 0;
createNode groupParts -n "wateringCan:groupParts9";
	rename -uid "93DD4BC2-495B-BB56-E247-99A3CDE3AA67";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:23]";
createNode polyCylinder -n "wateringCan:polyCylinder4";
	rename -uid "A7C745FA-4EA3-99D8-7050-B88F27602A89";
	setAttr ".r" 0.06;
	setAttr ".h" 0.70655232649546018;
	setAttr ".sa" 8;
	setAttr ".sc" 1;
	setAttr ".cuv" 3;
createNode groupId -n "wateringCan:groupId18";
	rename -uid "268E5096-4251-D1E4-2D33-04A4891110C8";
	setAttr ".ihi" 0;
createNode groupId -n "wateringCan:groupId19";
	rename -uid "BED2CD4E-4F0C-262C-1074-67BE16EF37AF";
	setAttr ".ihi" 0;
createNode groupId -n "wateringCan:groupId22";
	rename -uid "1D44037A-4528-B5A2-3104-FB8161A4EFE9";
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
	setAttr -s 17 ".dsm";
	setAttr ".ro" yes;
	setAttr -s 17 ".gn";
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
connectAttr "wateringCan:groupId11.id" "wateringCan:Watering_CanShape.iog.og[4].gid"
		;
connectAttr ":initialShadingGroup.mwc" "wateringCan:Watering_CanShape.iog.og[4].gco"
		;
connectAttr "wateringCan:groupParts6.og" "wateringCan:Watering_CanShape.i";
connectAttr "wateringCan:groupId12.id" "wateringCan:Watering_CanShape.ciog.cog[2].cgid"
		;
connectAttr "wateringCan:groupId13.id" "wateringCan:pCubeShape3.iog.og[2].gid";
connectAttr ":initialShadingGroup.mwc" "wateringCan:pCubeShape3.iog.og[2].gco";
connectAttr "wateringCan:groupParts7.og" "wateringCan:pCubeShape3.i";
connectAttr "wateringCan:groupId14.id" "wateringCan:pCubeShape3.ciog.cog[2].cgid"
		;
connectAttr "wateringCan:groupId6.id" "wateringCan:pCubeShape4.iog.og[1].gid";
connectAttr ":initialShadingGroup.mwc" "wateringCan:pCubeShape4.iog.og[1].gco";
connectAttr "wateringCan:groupParts4.og" "wateringCan:pCubeShape4.i";
connectAttr "wateringCan:groupId7.id" "wateringCan:pCubeShape4.ciog.cog[1].cgid"
		;
connectAttr "wateringCan:groupId8.id" "wateringCan:pCubeShape5.iog.og[2].gid";
connectAttr ":initialShadingGroup.mwc" "wateringCan:pCubeShape5.iog.og[2].gco";
connectAttr "wateringCan:groupId9.id" "wateringCan:pCubeShape5.ciog.cog[1].cgid"
		;
connectAttr "wateringCan:groupParts5.og" "wateringCan:pCube6Shape.i";
connectAttr "wateringCan:groupId10.id" "wateringCan:pCube6Shape.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "wateringCan:pCube6Shape.iog.og[0].gco";
connectAttr "wateringCan:groupId15.id" "wateringCan:pCylinderShape1.iog.og[1].gid"
		;
connectAttr ":initialShadingGroup.mwc" "wateringCan:pCylinderShape1.iog.og[1].gco"
		;
connectAttr "wateringCan:groupParts8.og" "wateringCan:pCylinderShape1.i";
connectAttr "wateringCan:groupId16.id" "wateringCan:pCylinderShape1.ciog.cog[1].cgid"
		;
connectAttr "wateringCan:groupId17.id" "wateringCan:pCylinderShape2.iog.og[0].gid"
		;
connectAttr ":initialShadingGroup.mwc" "wateringCan:pCylinderShape2.iog.og[0].gco"
		;
connectAttr "wateringCan:groupParts9.og" "wateringCan:pCylinderShape2.i";
connectAttr "wateringCan:groupId18.id" "wateringCan:pCylinderShape2.ciog.cog[0].cgid"
		;
connectAttr "wateringCan:polyMergeVert1.out" "wateringCan:Watering_Can1Shape.i";
connectAttr "wateringCan:groupId19.id" "wateringCan:Watering_Can1Shape.iog.og[0].gid"
		;
connectAttr ":initialShadingGroup.mwc" "wateringCan:Watering_Can1Shape.iog.og[0].gco"
		;
connectAttr "wateringCan:groupParts12.og" "wateringCan:pTorusShape1.i";
connectAttr "wateringCan:groupId20.id" "wateringCan:pTorusShape1.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "wateringCan:pTorusShape1.iog.og[0].gco";
connectAttr "wateringCan:groupId21.id" "wateringCan:pTorusShape1.ciog.cog[0].cgid"
		;
connectAttr "wateringCan:groupParts13.og" "wateringCan:Watering_Can2Shape.i";
connectAttr "wateringCan:groupId22.id" "wateringCan:Watering_Can2Shape.iog.og[0].gid"
		;
connectAttr ":initialShadingGroup.mwc" "wateringCan:Watering_Can2Shape.iog.og[0].gco"
		;
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
connectAttr "wateringCan:polyUnite4.out" "wateringCan:groupParts13.ig";
connectAttr "wateringCan:groupId22.id" "wateringCan:groupParts13.gi";
connectAttr "wateringCan:pTorusShape1.o" "wateringCan:polyUnite4.ip[0]";
connectAttr "wateringCan:Watering_Can1Shape.o" "wateringCan:polyUnite4.ip[1]";
connectAttr "wateringCan:pTorusShape1.wm" "wateringCan:polyUnite4.im[0]";
connectAttr "wateringCan:Watering_Can1Shape.wm" "wateringCan:polyUnite4.im[1]";
connectAttr "wateringCan:polySplit8.out" "wateringCan:groupParts12.ig";
connectAttr "wateringCan:groupId20.id" "wateringCan:groupParts12.gi";
connectAttr "wateringCan:polySplit7.out" "wateringCan:polySplit8.ip";
connectAttr "wateringCan:polyCloseBorder2.out" "wateringCan:polySplit7.ip";
connectAttr "wateringCan:polySplit6.out" "wateringCan:polyCloseBorder2.ip";
connectAttr "wateringCan:polySplit5.out" "wateringCan:polySplit6.ip";
connectAttr "wateringCan:polyCloseBorder1.out" "wateringCan:polySplit5.ip";
connectAttr "wateringCan:polyTweak48.out" "wateringCan:polyCloseBorder1.ip";
connectAttr "wateringCan:polyExtrudeEdge8.out" "wateringCan:polyTweak48.ip";
connectAttr "wateringCan:polyTweak47.out" "wateringCan:polyExtrudeEdge8.ip";
connectAttr "wateringCan:pTorusShape1.wm" "wateringCan:polyExtrudeEdge8.mp";
connectAttr "wateringCan:polyExtrudeEdge7.out" "wateringCan:polyTweak47.ip";
connectAttr "wateringCan:polyTweak46.out" "wateringCan:polyExtrudeEdge7.ip";
connectAttr "wateringCan:pTorusShape1.wm" "wateringCan:polyExtrudeEdge7.mp";
connectAttr "wateringCan:deleteComponent15.og" "wateringCan:polyTweak46.ip";
connectAttr "wateringCan:polyTorus1.out" "wateringCan:deleteComponent15.ig";
connectAttr "wateringCan:polyDelEdge10.out" "wateringCan:polyMergeVert1.ip";
connectAttr "wateringCan:Watering_Can1Shape.wm" "wateringCan:polyMergeVert1.mp";
connectAttr "wateringCan:polyTweak50.out" "wateringCan:polyDelEdge10.ip";
connectAttr "wateringCan:polyExtrudeFace42.out" "wateringCan:polyTweak50.ip";
connectAttr "wateringCan:polySplit9.out" "wateringCan:polyExtrudeFace42.ip";
connectAttr "wateringCan:Watering_Can1Shape.wm" "wateringCan:polyExtrudeFace42.mp"
		;
connectAttr "wateringCan:groupParts11.og" "wateringCan:polySplit9.ip";
connectAttr "wateringCan:polyCloseBorder3.out" "wateringCan:groupParts11.ig";
connectAttr "wateringCan:groupId19.id" "wateringCan:groupParts11.gi";
connectAttr "wateringCan:polyTweak49.out" "wateringCan:polyCloseBorder3.ip";
connectAttr "wateringCan:polyExtrudeEdge9.out" "wateringCan:polyTweak49.ip";
connectAttr "wateringCan:polyDelEdge9.out" "wateringCan:polyExtrudeEdge9.ip";
connectAttr "wateringCan:Watering_Can1Shape.wm" "wateringCan:polyExtrudeEdge9.mp"
		;
connectAttr "wateringCan:polyDelEdge8.out" "wateringCan:polyDelEdge9.ip";
connectAttr "wateringCan:polyDelEdge7.out" "wateringCan:polyDelEdge8.ip";
connectAttr "wateringCan:polySoftEdge8.out" "wateringCan:polyDelEdge7.ip";
connectAttr "wateringCan:polySoftEdge7.out" "wateringCan:polySoftEdge8.ip";
connectAttr "wateringCan:Watering_Can1Shape.wm" "wateringCan:polySoftEdge8.mp";
connectAttr "wateringCan:polySoftEdge6.out" "wateringCan:polySoftEdge7.ip";
connectAttr "wateringCan:Watering_Can1Shape.wm" "wateringCan:polySoftEdge7.mp";
connectAttr "wateringCan:deleteComponent14.og" "wateringCan:polySoftEdge6.ip";
connectAttr "wateringCan:Watering_Can1Shape.wm" "wateringCan:polySoftEdge6.mp";
connectAttr "wateringCan:polyMirror2.out" "wateringCan:deleteComponent14.ig";
connectAttr "wateringCan:polyTweak45.out" "wateringCan:polyMirror2.ip";
connectAttr "wateringCan:Watering_Can1Shape.wm" "wateringCan:polyMirror2.mp";
connectAttr "wateringCan:deleteComponent13.og" "wateringCan:polyTweak45.ip";
connectAttr "wateringCan:deleteComponent12.og" "wateringCan:deleteComponent13.ig"
		;
connectAttr "wateringCan:polyMirror1.out" "wateringCan:deleteComponent12.ig";
connectAttr "wateringCan:polyTweak44.out" "wateringCan:polyMirror1.ip";
connectAttr "wateringCan:Watering_Can1Shape.wm" "wateringCan:polyMirror1.mp";
connectAttr "wateringCan:polyDelEdge6.out" "wateringCan:polyTweak44.ip";
connectAttr "wateringCan:polyTweak43.out" "wateringCan:polyDelEdge6.ip";
connectAttr "wateringCan:polyDelEdge5.out" "wateringCan:polyTweak43.ip";
connectAttr "wateringCan:polySplit4.out" "wateringCan:polyDelEdge5.ip";
connectAttr "wateringCan:polySplit3.out" "wateringCan:polySplit4.ip";
connectAttr "wateringCan:polyConnectComponents1.out" "wateringCan:polySplit3.ip"
		;
connectAttr "wateringCan:deleteComponent11.og" "wateringCan:polyConnectComponents1.ip"
		;
connectAttr "wateringCan:deleteComponent10.og" "wateringCan:deleteComponent11.ig"
		;
connectAttr "wateringCan:polySoftEdge5.out" "wateringCan:deleteComponent10.ig";
connectAttr "wateringCan:polyDelEdge4.out" "wateringCan:polySoftEdge5.ip";
connectAttr "wateringCan:Watering_Can1Shape.wm" "wateringCan:polySoftEdge5.mp";
connectAttr "wateringCan:polyDelEdge3.out" "wateringCan:polyDelEdge4.ip";
connectAttr "wateringCan:polyDelEdge2.out" "wateringCan:polyDelEdge3.ip";
connectAttr "wateringCan:polyDelEdge1.out" "wateringCan:polyDelEdge2.ip";
connectAttr "wateringCan:polySoftEdge4.out" "wateringCan:polyDelEdge1.ip";
connectAttr "wateringCan:polyTweak42.out" "wateringCan:polySoftEdge4.ip";
connectAttr "wateringCan:Watering_Can1Shape.wm" "wateringCan:polySoftEdge4.mp";
connectAttr "wateringCan:polyExtrudeEdge6.out" "wateringCan:polyTweak42.ip";
connectAttr "wateringCan:polySoftEdge3.out" "wateringCan:polyExtrudeEdge6.ip";
connectAttr "wateringCan:Watering_Can1Shape.wm" "wateringCan:polyExtrudeEdge6.mp"
		;
connectAttr "wateringCan:polySoftEdge2.out" "wateringCan:polySoftEdge3.ip";
connectAttr "wateringCan:Watering_Can1Shape.wm" "wateringCan:polySoftEdge3.mp";
connectAttr "wateringCan:polySoftEdge1.out" "wateringCan:polySoftEdge2.ip";
connectAttr "wateringCan:Watering_Can1Shape.wm" "wateringCan:polySoftEdge2.mp";
connectAttr "wateringCan:groupParts10.og" "wateringCan:polySoftEdge1.ip";
connectAttr "wateringCan:Watering_Can1Shape.wm" "wateringCan:polySoftEdge1.mp";
connectAttr "wateringCan:polyUnite3.out" "wateringCan:groupParts10.ig";
connectAttr "wateringCan:Watering_CanShape.o" "wateringCan:polyUnite3.ip[0]";
connectAttr "wateringCan:pCube6Shape.o" "wateringCan:polyUnite3.ip[1]";
connectAttr "wateringCan:pCubeShape3.o" "wateringCan:polyUnite3.ip[2]";
connectAttr "wateringCan:pCylinderShape1.o" "wateringCan:polyUnite3.ip[3]";
connectAttr "wateringCan:pCylinderShape2.o" "wateringCan:polyUnite3.ip[4]";
connectAttr "wateringCan:Watering_CanShape.wm" "wateringCan:polyUnite3.im[0]";
connectAttr "wateringCan:pCube6Shape.wm" "wateringCan:polyUnite3.im[1]";
connectAttr "wateringCan:pCubeShape3.wm" "wateringCan:polyUnite3.im[2]";
connectAttr "wateringCan:pCylinderShape1.wm" "wateringCan:polyUnite3.im[3]";
connectAttr "wateringCan:pCylinderShape2.wm" "wateringCan:polyUnite3.im[4]";
connectAttr "wateringCan:polyBevel2.out" "wateringCan:groupParts6.ig";
connectAttr "wateringCan:groupId11.id" "wateringCan:groupParts6.gi";
connectAttr "wateringCan:polyTweak5.out" "wateringCan:polyBevel2.ip";
connectAttr "wateringCan:Watering_CanShape.wm" "wateringCan:polyBevel2.mp";
connectAttr "wateringCan:polySplit2.out" "wateringCan:polyTweak5.ip";
connectAttr "wateringCan:polySplit1.out" "wateringCan:polySplit2.ip";
connectAttr "wateringCan:polyBridgeEdge16.out" "wateringCan:polySplit1.ip";
connectAttr "wateringCan:polyBridgeEdge15.out" "wateringCan:polyBridgeEdge16.ip"
		;
connectAttr "wateringCan:Watering_CanShape.wm" "wateringCan:polyBridgeEdge16.mp"
		;
connectAttr "wateringCan:polyBridgeEdge14.out" "wateringCan:polyBridgeEdge15.ip"
		;
connectAttr "wateringCan:Watering_CanShape.wm" "wateringCan:polyBridgeEdge15.mp"
		;
connectAttr "wateringCan:polyBridgeEdge13.out" "wateringCan:polyBridgeEdge14.ip"
		;
connectAttr "wateringCan:Watering_CanShape.wm" "wateringCan:polyBridgeEdge14.mp"
		;
connectAttr "wateringCan:polyBridgeEdge12.out" "wateringCan:polyBridgeEdge13.ip"
		;
connectAttr "wateringCan:Watering_CanShape.wm" "wateringCan:polyBridgeEdge13.mp"
		;
connectAttr "wateringCan:polyBridgeEdge11.out" "wateringCan:polyBridgeEdge12.ip"
		;
connectAttr "wateringCan:Watering_CanShape.wm" "wateringCan:polyBridgeEdge12.mp"
		;
connectAttr "wateringCan:polyBridgeEdge10.out" "wateringCan:polyBridgeEdge11.ip"
		;
connectAttr "wateringCan:Watering_CanShape.wm" "wateringCan:polyBridgeEdge11.mp"
		;
connectAttr "wateringCan:polyBridgeEdge9.out" "wateringCan:polyBridgeEdge10.ip";
connectAttr "wateringCan:Watering_CanShape.wm" "wateringCan:polyBridgeEdge10.mp"
		;
connectAttr "wateringCan:polyTweak4.out" "wateringCan:polyBridgeEdge9.ip";
connectAttr "wateringCan:Watering_CanShape.wm" "wateringCan:polyBridgeEdge9.mp";
connectAttr "wateringCan:polyExtrudeEdge5.out" "wateringCan:polyTweak4.ip";
connectAttr "wateringCan:polyTweak3.out" "wateringCan:polyExtrudeEdge5.ip";
connectAttr "wateringCan:Watering_CanShape.wm" "wateringCan:polyExtrudeEdge5.mp"
		;
connectAttr "wateringCan:polyExtrudeEdge4.out" "wateringCan:polyTweak3.ip";
connectAttr "wateringCan:deleteComponent5.og" "wateringCan:polyExtrudeEdge4.ip";
connectAttr "wateringCan:Watering_CanShape.wm" "wateringCan:polyExtrudeEdge4.mp"
		;
connectAttr "wateringCan:polyCylinder2.out" "wateringCan:deleteComponent5.ig";
connectAttr "wateringCan:polyUnite2.out" "wateringCan:groupParts5.ig";
connectAttr "wateringCan:groupId10.id" "wateringCan:groupParts5.gi";
connectAttr "wateringCan:pCubeShape4.o" "wateringCan:polyUnite2.ip[0]";
connectAttr "wateringCan:pCubeShape5.o" "wateringCan:polyUnite2.ip[1]";
connectAttr "wateringCan:pCubeShape4.wm" "wateringCan:polyUnite2.im[0]";
connectAttr "wateringCan:pCubeShape5.wm" "wateringCan:polyUnite2.im[1]";
connectAttr "wateringCan:polyExtrudeFace35.out" "wateringCan:groupParts4.ig";
connectAttr "wateringCan:groupId6.id" "wateringCan:groupParts4.gi";
connectAttr "wateringCan:polyTweak36.out" "wateringCan:polyExtrudeFace35.ip";
connectAttr "wateringCan:pCubeShape4.wm" "wateringCan:polyExtrudeFace35.mp";
connectAttr "wateringCan:polyExtrudeFace34.out" "wateringCan:polyTweak36.ip";
connectAttr "wateringCan:polyTweak35.out" "wateringCan:polyExtrudeFace34.ip";
connectAttr "wateringCan:pCubeShape4.wm" "wateringCan:polyExtrudeFace34.mp";
connectAttr "wateringCan:polyExtrudeFace33.out" "wateringCan:polyTweak35.ip";
connectAttr "wateringCan:polyTweak34.out" "wateringCan:polyExtrudeFace33.ip";
connectAttr "wateringCan:pCubeShape4.wm" "wateringCan:polyExtrudeFace33.mp";
connectAttr "wateringCan:polyExtrudeFace32.out" "wateringCan:polyTweak34.ip";
connectAttr "wateringCan:polyTweak33.out" "wateringCan:polyExtrudeFace32.ip";
connectAttr "wateringCan:pCubeShape4.wm" "wateringCan:polyExtrudeFace32.mp";
connectAttr "wateringCan:polyExtrudeFace31.out" "wateringCan:polyTweak33.ip";
connectAttr "wateringCan:polyTweak32.out" "wateringCan:polyExtrudeFace31.ip";
connectAttr "wateringCan:pCubeShape4.wm" "wateringCan:polyExtrudeFace31.mp";
connectAttr "wateringCan:polyExtrudeFace30.out" "wateringCan:polyTweak32.ip";
connectAttr "wateringCan:polyTweak31.out" "wateringCan:polyExtrudeFace30.ip";
connectAttr "wateringCan:pCubeShape4.wm" "wateringCan:polyExtrudeFace30.mp";
connectAttr "wateringCan:polyExtrudeFace29.out" "wateringCan:polyTweak31.ip";
connectAttr "wateringCan:polyTweak30.out" "wateringCan:polyExtrudeFace29.ip";
connectAttr "wateringCan:pCubeShape4.wm" "wateringCan:polyExtrudeFace29.mp";
connectAttr "wateringCan:polyExtrudeFace28.out" "wateringCan:polyTweak30.ip";
connectAttr "wateringCan:polyTweak29.out" "wateringCan:polyExtrudeFace28.ip";
connectAttr "wateringCan:pCubeShape4.wm" "wateringCan:polyExtrudeFace28.mp";
connectAttr "wateringCan:polyExtrudeFace27.out" "wateringCan:polyTweak29.ip";
connectAttr "wateringCan:polyTweak28.out" "wateringCan:polyExtrudeFace27.ip";
connectAttr "wateringCan:pCubeShape4.wm" "wateringCan:polyExtrudeFace27.mp";
connectAttr "wateringCan:polyExtrudeFace26.out" "wateringCan:polyTweak28.ip";
connectAttr "wateringCan:polyTweak27.out" "wateringCan:polyExtrudeFace26.ip";
connectAttr "wateringCan:pCubeShape4.wm" "wateringCan:polyExtrudeFace26.mp";
connectAttr "wateringCan:polyExtrudeFace25.out" "wateringCan:polyTweak27.ip";
connectAttr "wateringCan:polyTweak26.out" "wateringCan:polyExtrudeFace25.ip";
connectAttr "wateringCan:pCubeShape4.wm" "wateringCan:polyExtrudeFace25.mp";
connectAttr "wateringCan:polyExtrudeFace24.out" "wateringCan:polyTweak26.ip";
connectAttr "wateringCan:polyTweak25.out" "wateringCan:polyExtrudeFace24.ip";
connectAttr "wateringCan:pCubeShape4.wm" "wateringCan:polyExtrudeFace24.mp";
connectAttr "wateringCan:polyExtrudeFace23.out" "wateringCan:polyTweak25.ip";
connectAttr "wateringCan:polyCube3.out" "wateringCan:polyExtrudeFace23.ip";
connectAttr "wateringCan:pCubeShape4.wm" "wateringCan:polyExtrudeFace23.mp";
connectAttr "wateringCan:polyExtrudeFace22.out" "wateringCan:groupParts7.ig";
connectAttr "wateringCan:groupId13.id" "wateringCan:groupParts7.gi";
connectAttr "wateringCan:polyTweak24.out" "wateringCan:polyExtrudeFace22.ip";
connectAttr "wateringCan:pCubeShape3.wm" "wateringCan:polyExtrudeFace22.mp";
connectAttr "wateringCan:polyExtrudeFace21.out" "wateringCan:polyTweak24.ip";
connectAttr "wateringCan:polyTweak23.out" "wateringCan:polyExtrudeFace21.ip";
connectAttr "wateringCan:pCubeShape3.wm" "wateringCan:polyExtrudeFace21.mp";
connectAttr "wateringCan:polyExtrudeFace20.out" "wateringCan:polyTweak23.ip";
connectAttr "wateringCan:polyTweak22.out" "wateringCan:polyExtrudeFace20.ip";
connectAttr "wateringCan:pCubeShape3.wm" "wateringCan:polyExtrudeFace20.mp";
connectAttr "wateringCan:polyExtrudeFace19.out" "wateringCan:polyTweak22.ip";
connectAttr "wateringCan:polyTweak21.out" "wateringCan:polyExtrudeFace19.ip";
connectAttr "wateringCan:pCubeShape3.wm" "wateringCan:polyExtrudeFace19.mp";
connectAttr "wateringCan:polyExtrudeFace18.out" "wateringCan:polyTweak21.ip";
connectAttr "wateringCan:polyTweak20.out" "wateringCan:polyExtrudeFace18.ip";
connectAttr "wateringCan:pCubeShape3.wm" "wateringCan:polyExtrudeFace18.mp";
connectAttr "wateringCan:polyExtrudeFace17.out" "wateringCan:polyTweak20.ip";
connectAttr "wateringCan:polyTweak19.out" "wateringCan:polyExtrudeFace17.ip";
connectAttr "wateringCan:pCubeShape3.wm" "wateringCan:polyExtrudeFace17.mp";
connectAttr "wateringCan:polyExtrudeFace16.out" "wateringCan:polyTweak19.ip";
connectAttr "wateringCan:polyTweak18.out" "wateringCan:polyExtrudeFace16.ip";
connectAttr "wateringCan:pCubeShape3.wm" "wateringCan:polyExtrudeFace16.mp";
connectAttr "wateringCan:polyExtrudeFace15.out" "wateringCan:polyTweak18.ip";
connectAttr "wateringCan:polyTweak17.out" "wateringCan:polyExtrudeFace15.ip";
connectAttr "wateringCan:pCubeShape3.wm" "wateringCan:polyExtrudeFace15.mp";
connectAttr "wateringCan:polyExtrudeFace14.out" "wateringCan:polyTweak17.ip";
connectAttr "wateringCan:polyTweak16.out" "wateringCan:polyExtrudeFace14.ip";
connectAttr "wateringCan:pCubeShape3.wm" "wateringCan:polyExtrudeFace14.mp";
connectAttr "wateringCan:polyExtrudeFace13.out" "wateringCan:polyTweak16.ip";
connectAttr "wateringCan:polyTweak15.out" "wateringCan:polyExtrudeFace13.ip";
connectAttr "wateringCan:pCubeShape3.wm" "wateringCan:polyExtrudeFace13.mp";
connectAttr "wateringCan:polyExtrudeFace12.out" "wateringCan:polyTweak15.ip";
connectAttr "wateringCan:polyTweak14.out" "wateringCan:polyExtrudeFace12.ip";
connectAttr "wateringCan:pCubeShape3.wm" "wateringCan:polyExtrudeFace12.mp";
connectAttr "wateringCan:polyExtrudeFace11.out" "wateringCan:polyTweak14.ip";
connectAttr "wateringCan:polyTweak13.out" "wateringCan:polyExtrudeFace11.ip";
connectAttr "wateringCan:pCubeShape3.wm" "wateringCan:polyExtrudeFace11.mp";
connectAttr "wateringCan:polyExtrudeFace10.out" "wateringCan:polyTweak13.ip";
connectAttr "wateringCan:polyTweak12.out" "wateringCan:polyExtrudeFace10.ip";
connectAttr "wateringCan:pCubeShape3.wm" "wateringCan:polyExtrudeFace10.mp";
connectAttr "wateringCan:polyExtrudeFace9.out" "wateringCan:polyTweak12.ip";
connectAttr "wateringCan:polyTweak11.out" "wateringCan:polyExtrudeFace9.ip";
connectAttr "wateringCan:pCubeShape3.wm" "wateringCan:polyExtrudeFace9.mp";
connectAttr "wateringCan:polyExtrudeFace8.out" "wateringCan:polyTweak11.ip";
connectAttr "wateringCan:polyTweak10.out" "wateringCan:polyExtrudeFace8.ip";
connectAttr "wateringCan:pCubeShape3.wm" "wateringCan:polyExtrudeFace8.mp";
connectAttr "wateringCan:polyExtrudeFace7.out" "wateringCan:polyTweak10.ip";
connectAttr "wateringCan:polyTweak9.out" "wateringCan:polyExtrudeFace7.ip";
connectAttr "wateringCan:pCubeShape3.wm" "wateringCan:polyExtrudeFace7.mp";
connectAttr "wateringCan:polyExtrudeFace6.out" "wateringCan:polyTweak9.ip";
connectAttr "wateringCan:polyTweak8.out" "wateringCan:polyExtrudeFace6.ip";
connectAttr "wateringCan:pCubeShape3.wm" "wateringCan:polyExtrudeFace6.mp";
connectAttr "wateringCan:polyExtrudeFace5.out" "wateringCan:polyTweak8.ip";
connectAttr "wateringCan:polyTweak7.out" "wateringCan:polyExtrudeFace5.ip";
connectAttr "wateringCan:pCubeShape3.wm" "wateringCan:polyExtrudeFace5.mp";
connectAttr "wateringCan:polyExtrudeFace4.out" "wateringCan:polyTweak7.ip";
connectAttr "wateringCan:polyTweak6.out" "wateringCan:polyExtrudeFace4.ip";
connectAttr "wateringCan:pCubeShape3.wm" "wateringCan:polyExtrudeFace4.mp";
connectAttr "wateringCan:polyExtrudeFace3.out" "wateringCan:polyTweak6.ip";
connectAttr "wateringCan:polyCube2.out" "wateringCan:polyExtrudeFace3.ip";
connectAttr "wateringCan:pCubeShape3.wm" "wateringCan:polyExtrudeFace3.mp";
connectAttr "wateringCan:polyExtrudeFace41.out" "wateringCan:groupParts8.ig";
connectAttr "wateringCan:groupId15.id" "wateringCan:groupParts8.gi";
connectAttr "wateringCan:polyTweak41.out" "wateringCan:polyExtrudeFace41.ip";
connectAttr "wateringCan:pCylinderShape1.wm" "wateringCan:polyExtrudeFace41.mp";
connectAttr "wateringCan:polyExtrudeFace40.out" "wateringCan:polyTweak41.ip";
connectAttr "wateringCan:deleteComponent9.og" "wateringCan:polyExtrudeFace40.ip"
		;
connectAttr "wateringCan:pCylinderShape1.wm" "wateringCan:polyExtrudeFace40.mp";
connectAttr "wateringCan:deleteComponent8.og" "wateringCan:deleteComponent9.ig";
connectAttr "wateringCan:deleteComponent7.og" "wateringCan:deleteComponent8.ig";
connectAttr "wateringCan:deleteComponent6.og" "wateringCan:deleteComponent7.ig";
connectAttr "wateringCan:polyTweak40.out" "wateringCan:deleteComponent6.ig";
connectAttr "wateringCan:polyExtrudeFace39.out" "wateringCan:polyTweak40.ip";
connectAttr "wateringCan:polyTweak39.out" "wateringCan:polyExtrudeFace39.ip";
connectAttr "wateringCan:pCylinderShape1.wm" "wateringCan:polyExtrudeFace39.mp";
connectAttr "wateringCan:polyExtrudeFace38.out" "wateringCan:polyTweak39.ip";
connectAttr "wateringCan:polyTweak38.out" "wateringCan:polyExtrudeFace38.ip";
connectAttr "wateringCan:pCylinderShape1.wm" "wateringCan:polyExtrudeFace38.mp";
connectAttr "wateringCan:polyExtrudeFace37.out" "wateringCan:polyTweak38.ip";
connectAttr "wateringCan:polyTweak37.out" "wateringCan:polyExtrudeFace37.ip";
connectAttr "wateringCan:pCylinderShape1.wm" "wateringCan:polyExtrudeFace37.mp";
connectAttr "wateringCan:polyExtrudeFace36.out" "wateringCan:polyTweak37.ip";
connectAttr "wateringCan:polyCylinder3.out" "wateringCan:polyExtrudeFace36.ip";
connectAttr "wateringCan:pCylinderShape1.wm" "wateringCan:polyExtrudeFace36.mp";
connectAttr "wateringCan:polyCylinder4.out" "wateringCan:groupParts9.ig";
connectAttr "wateringCan:groupId17.id" "wateringCan:groupParts9.gi";
connectAttr "aiStandardSurface1SG.pa" ":renderPartition.st" -na;
connectAttr "groundplane_shader.msg" ":defaultShaderList1.s" -na;
connectAttr "place2dTexture1.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "defaultRenderLayer.msg" ":defaultRenderingList1.r" -na;
connectAttr "Skydome_lShape.ltd" ":lightList1.l" -na;
connectAttr "groundplane.msg" ":defaultTextureList1.tx" -na;
connectAttr "wateringCan:pCubeShape4.iog.og[1]" ":initialShadingGroup.dsm" -na;
connectAttr "wateringCan:pCubeShape4.ciog.cog[1]" ":initialShadingGroup.dsm" -na
		;
connectAttr "wateringCan:pCubeShape5.iog.og[2]" ":initialShadingGroup.dsm" -na;
connectAttr "wateringCan:pCubeShape5.ciog.cog[1]" ":initialShadingGroup.dsm" -na
		;
connectAttr "wateringCan:pCube6Shape.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "wateringCan:Watering_CanShape.iog.og[4]" ":initialShadingGroup.dsm"
		 -na;
connectAttr "wateringCan:Watering_CanShape.ciog.cog[2]" ":initialShadingGroup.dsm"
		 -na;
connectAttr "wateringCan:pCubeShape3.iog.og[2]" ":initialShadingGroup.dsm" -na;
connectAttr "wateringCan:pCubeShape3.ciog.cog[2]" ":initialShadingGroup.dsm" -na
		;
connectAttr "wateringCan:pCylinderShape1.iog.og[1]" ":initialShadingGroup.dsm" -na
		;
connectAttr "wateringCan:pCylinderShape1.ciog.cog[1]" ":initialShadingGroup.dsm"
		 -na;
connectAttr "wateringCan:pCylinderShape2.iog.og[0]" ":initialShadingGroup.dsm" -na
		;
connectAttr "wateringCan:pCylinderShape2.ciog.cog[0]" ":initialShadingGroup.dsm"
		 -na;
connectAttr "wateringCan:Watering_Can1Shape.iog.og[0]" ":initialShadingGroup.dsm"
		 -na;
connectAttr "wateringCan:pTorusShape1.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "wateringCan:pTorusShape1.ciog.cog[0]" ":initialShadingGroup.dsm" -na
		;
connectAttr "wateringCan:Watering_Can2Shape.iog.og[0]" ":initialShadingGroup.dsm"
		 -na;
connectAttr "wateringCan:groupId6.msg" ":initialShadingGroup.gn" -na;
connectAttr "wateringCan:groupId7.msg" ":initialShadingGroup.gn" -na;
connectAttr "wateringCan:groupId8.msg" ":initialShadingGroup.gn" -na;
connectAttr "wateringCan:groupId9.msg" ":initialShadingGroup.gn" -na;
connectAttr "wateringCan:groupId10.msg" ":initialShadingGroup.gn" -na;
connectAttr "wateringCan:groupId11.msg" ":initialShadingGroup.gn" -na;
connectAttr "wateringCan:groupId12.msg" ":initialShadingGroup.gn" -na;
connectAttr "wateringCan:groupId13.msg" ":initialShadingGroup.gn" -na;
connectAttr "wateringCan:groupId14.msg" ":initialShadingGroup.gn" -na;
connectAttr "wateringCan:groupId15.msg" ":initialShadingGroup.gn" -na;
connectAttr "wateringCan:groupId16.msg" ":initialShadingGroup.gn" -na;
connectAttr "wateringCan:groupId17.msg" ":initialShadingGroup.gn" -na;
connectAttr "wateringCan:groupId18.msg" ":initialShadingGroup.gn" -na;
connectAttr "wateringCan:groupId19.msg" ":initialShadingGroup.gn" -na;
connectAttr "wateringCan:groupId20.msg" ":initialShadingGroup.gn" -na;
connectAttr "wateringCan:groupId21.msg" ":initialShadingGroup.gn" -na;
connectAttr "wateringCan:groupId22.msg" ":initialShadingGroup.gn" -na;
connectAttr "Skydome_l.iog" ":defaultLightSet.dsm" -na;
// End of 1GD12E_AlejandroRoca_WateringCan.000.ma
