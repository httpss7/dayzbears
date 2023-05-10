class CfgPatches
{
	class DZ_Animals_canis_lupus
	{
		units[]=
		{
			"Animal_CanisLupus_Grey",
			"Animal_CanisLupus_White",
			"Animal_UrsusArctos",
			"Food_CanBakedBeans",
			"Food_CanFrankBeans",
			"Food_CanPasta",
			"Food_CanSardines",
			"Food_BoxCerealCrunchin"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Animals",
			"DZ_Data_Bliss",
			"DZ_AI_Bliss",
			"DZ_Weapons_Melee",
			"DZ_Gear_Medical"
		};
	};
};
class CfgVehicles
{
	class AnimalBase;
	class Animal_UrsusArctos;
	class BearPelt;
	class BearSteakMeat;
	class WolfSteakMeat;
	class WolfPelt;
	class Animal_CanisLupusSanta: AnimalBase
	{
		simulation="dayzanimal";
		scope=0;
		model="\DZ\animals\canis_lupus\canis_lupus.p3d";
		displayName="Раненый волк";
		descriptionShort="$STR_CfgVehicles_Animal_CanisLupus1";
		hiddenSelections[]=
		{
			"Camo",
			"CamoHair"
		};
		DamageSphereAmmos[]=
		{
			"MeleeWolf"
		};
		aiAgentTemplate="Predators_Wolf";
		injuryLevels[]={1,0.5,0.2,0};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=5000;
					healthLabels[]={1,0.69999999,0.5,0.30000001,0};
				};
				class Blood
				{
					hitpoints=5000;
				};
				class Shock
				{
					hitpoints=100;
				};
			};
			class DamageZones
			{
				class Zone_Head
				{
					componentNames[]=
					{
						"Zone_Head"
					};
					transferToZonesNames[]={};
					transferToZonesCoefs[]={};
					fatalInjuryCoef=0.15000001;
					canBleed=0;
					class Health
					{
						hitpoints=120;
						transferToGlobalCoef=1;
					};
					class Blood: Health
					{
						hitpoints=0;
					};
					class Shock: Health
					{
						hitpoints=0;
					};
				};
				class Zone_Neck: Zone_Head
				{
					componentNames[]=
					{
						"Zone_Neck"
					};
					transferToZonesNames[]={};
					transferToZonesCoefs[]={};
					fatalInjuryCoef=0.050000001;
					class Health: Health
					{
						hitpoints=100;
					};
				};
				class Zone_Chest: Zone_Head
				{
					componentNames[]=
					{
						"Zone_Chest"
					};
					transferToZonesNames[]={};
					transferToZonesCoefs[]={};
					fatalInjuryCoef=0.050000001;
					class Health: Health
					{
						hitpoints=150;
					};
				};
				class Zone_Belly: Zone_Head
				{
					componentNames[]=
					{
						"Zone_Belly"
					};
					transferToZonesNames[]={};
					transferToZonesCoefs[]={};
					fatalInjuryCoef=0.050000001;
					class Health: Health
					{
						hitpoints=150;
					};
				};
				class Zone_Spine: Zone_Head
				{
					componentNames[]=
					{
						"Zone_Spine_Front",
						"Zone_Spine_Back"
					};
					transferToZonesNames[]={};
					transferToZonesCoefs[]={};
					fatalInjuryCoef=0.050000001;
					class Health: Health
					{
						hitpoints=150;
					};
				};
				class Zone_Pelvis: Zone_Head
				{
					componentNames[]=
					{
						"Zone_Pelvis"
					};
					transferToZonesNames[]=
					{
						"Zone_Spine"
					};
					transferToZonesCoefs[]={0.5};
					fatalInjuryCoef=0.050000001;
					class Health: Health
					{
						hitpoints=180;
					};
				};
				class Zone_Legs: Zone_Head
				{
					componentNames[]=
					{
						"Zone_Legs_Front",
						"Zone_Legs_Back"
					};
					transferToZonesNames[]={};
					transferToZonesCoefs[]={};
					fatalInjuryCoef=0;
					class Health: Health
					{
						hitpoints=100;
					};
				};
			};
		};
		class Skinning
		{
			class ObtainedSteaks
			{
				item="WolfSteakMeatSanta";
				count=1;
				itemZones[]=
				{
					"Zone_Chest",
					"Zone_Belly",
					"Zone_Pelvis"
				};
				countByZone[]={3,3,3};
				quantityMinMaxCoef[]={0.5,1};
			};
			class ObtainedPelt
			{
				item="WolfPeltSanta";
				count=1;
				itemZones[]=
				{
					"Zone_Chest",
					"Zone_Belly"
				};
				quantityCoef=1;
				transferToolDamageCoef=1;
			};
			class ObtainedGuts
			{
				item="Guts";
				count=1;
				quantityMinMaxCoef[]={0.5,0.80000001};
			};
			class ObtainedLard
			{
				item="Lard";
				count=1;
				quantityMinMaxCoef[]={0.5,1};
			};
			class ObtainedBones
			{
				item="Bone";
				count=1;
				quantityMinMaxCoef[]={0.69999999,1};
				transferToolDamageCoef=1;
			};
		};
		class enfanimsys
		{
			meshObject="dz\animals\canis_lupus\Data\canis_lupus_skeleton.xob";
			graphname="dz\animals\animations\!graph_files\Wolf\Wolf_Graph.agr";
			defaultinstance="dz\animals\animations\!graph_files\Wolf\Wolf_AnimInstance.asi";
			startnode="AlignToTerrain_Rot";
			skeletonName="canis_lupus_skeleton.xob";
		};
		class AnimEvents
		{
			class Steps
			{
				class Walk1
				{
					soundLookupTable="PawMediumWalk_LookupTable";
					noise="WolfStepNoise";
					effectSet[]=
					{
						"WolfStepEffect1",
						"WolfStepEffect2"
					};
					id=1;
				};
				class Walk2
				{
					soundLookupTable="PawMediumWalk_LookupTable";
					noise="WolfStepNoise";
					effectSet[]=
					{
						"WolfStepEffect1",
						"WolfStepEffect2"
					};
					id=2;
				};
				class Walk3
				{
					soundLookupTable="PawMediumWalk_LookupTable";
					noise="WolfStepNoise";
					effectSet[]=
					{
						"WolfStepEffect1",
						"WolfStepEffect2"
					};
					id=3;
				};
				class Walk4
				{
					soundLookupTable="PawMediumWalk_LookupTable";
					noise="WolfStepNoise";
					effectSet[]=
					{
						"WolfStepEffect1",
						"WolfStepEffect2"
					};
					id=4;
				};
				class Run1
				{
					soundLookupTable="PawMediumRun_LookupTable";
					noise="WolfStepNoise";
					effectSet[]=
					{
						"WolfStepEffect1",
						"WolfStepEffect2"
					};
					id=5;
				};
				class Run2
				{
					soundLookupTable="PawMediumRun_LookupTable";
					noise="WolfStepNoise";
					effectSet[]=
					{
						"WolfStepEffect1",
						"WolfStepEffect2"
					};
					id=6;
				};
				class Run3
				{
					soundLookupTable="PawMediumRun_LookupTable";
					noise="WolfStepNoise";
					effectSet[]=
					{
						"WolfStepEffect1",
						"WolfStepEffect2"
					};
					id=7;
				};
				class Run4
				{
					soundLookupTable="PawMediumRun_LookupTable";
					noise="WolfStepNoise";
					effectSet[]=
					{
						"WolfStepEffect1",
						"WolfStepEffect2"
					};
					id=8;
				};
				class Bodyfall
				{
					soundLookupTable="PawMediumBodyfall_LookupTable";
					noise="WolfStepNoise";
					effectSet[]=
					{
						"WolfStepEffect1",
						"WolfStepEffect2"
					};
					id=11;
				};
				class Settle
				{
					soundLookupTable="PawMediumSettle_LookupTable";
					noise="WolfStepNoise";
					effectSet[]=
					{
						"WolfStepEffect1",
						"WolfStepEffect2"
					};
					id=12;
				};
				class Rest2standA
				{
					soundLookupTable="PawMediumRest2standA_LookupTable";
					noise="WolfStepNoise";
					effectSet[]=
					{
						"WolfStepEffect1",
						"WolfStepEffect2"
					};
					id=13;
				};
				class Rest2standB
				{
					soundLookupTable="PawMediumRest2standB_LookupTable";
					noise="WolfStepNoise";
					effectSet[]=
					{
						"WolfStepEffect1",
						"WolfStepEffect2"
					};
					id=14;
				};
				class Stand2restA
				{
					soundLookupTable="PawMediumStand2restA_LookupTable";
					noise="WolfStepNoise";
					effectSet[]=
					{
						"WolfStepEffect1",
						"WolfStepEffect2"
					};
					id=15;
				};
				class Stand2restB
				{
					soundLookupTable="PawMediumStand2restB_LookupTable";
					noise="WolfStepNoise";
					effectSet[]=
					{
						"WolfStepEffect1",
						"WolfStepEffect2"
					};
					id=16;
				};
				class Stand2restC
				{
					soundLookupTable="PawMediumStand2restC_LookupTable";
					noise="WolfStepNoise";
					effectSet[]=
					{
						"WolfStepEffect1",
						"WolfStepEffect2"
					};
					id=17;
				};
				class Jump
				{
					soundLookupTable="PawMediumJump_LookupTable";
					noise="WolfStepNoise";
					effectSet[]=
					{
						"WolfStepEffect1",
						"WolfStepEffect2"
					};
					id=18;
				};
				class Impact
				{
					soundLookupTable="PawMediumImpact_LookupTable";
					noise="WolfStepNoise";
					effectSet[]=
					{
						"WolfStepEffect1",
						"WolfStepEffect2"
					};
					id=19;
				};
			};
			class Sounds
			{
				class WolfBark
				{
					soundSet="WolfBark_SoundSet";
					noise="WolfRoarNoise";
					id=1;
				};
				class WolfBark_1
				{
					soundSet="WolfBark_SoundSet";
					noise="WolfRoarNoise";
					id=61;
				};
				class WolfBark_2
				{
					soundSet="WolfBark_SoundSet";
					noise="WolfRoarNoise";
					id=71;
				};
				class WolfBark2
				{
					soundSet="WolfBark2_SoundSet";
					noise="WolfRoarNoise";
					id=2;
				};
				class WolfBark3
				{
					soundSet="WolfBark3_SoundSet";
					noise="WolfRoarNoise";
					id=3;
				};
				class WolfBreath
				{
					soundSet="WolfBreath_SoundSet";
					noise="WolfRoarNoise";
					id=4;
				};
				class WolfGroans
				{
					soundSet="WolfGroans_SoundSet";
					noise="WolfRoarNoise";
					id=5;
				};
				class WolfGrowl_A
				{
					soundSet="WolfGrowl_A_SoundSet";
					noise="WolfRoarNoise";
					id=6;
				};
				class WolfGrowl_B
				{
					soundSet="WolfGrowl_B_SoundSet";
					noise="WolfRoarNoise";
					id=7;
				};
				class WolfGrowl
				{
					soundSet="WolfGrowl_A_SoundSet";
					noise="WolfRoarNoise";
					id=8;
				};
				class WolfPant
				{
					soundSet="WolfPant_SoundSet";
					noise="WolfRoarNoise";
					id=9;
				};
				class WolfPantShort
				{
					soundSet="WolfPantShort_SoundSet";
					noise="WolfRoarNoise";
					id=10;
				};
				class WolfPantLong
				{
					soundSet="WolfPantShort_SoundSet";
					noise="WolfRoarNoise";
					id=18;
				};
				class WolfSnarl
				{
					soundSet="WolfSnarl_SoundSet";
					noise="WolfRoarNoise";
					id=11;
				};
				class WolfSnarlShort
				{
					soundSet="WolfSnarlShort_SoundSet";
					noise="WolfRoarNoise";
					id=12;
				};
				class WolfWhimper
				{
					soundSet="WolfWhimper_SoundSet";
					noise="WolfRoarNoise";
					id=13;
				};
				class WolfYelp
				{
					soundSet="WolfYelp_SoundSet";
					noise="WolfRoarNoise";
					id=14;
				};
				class WolfYawn
				{
					soundSet="WolfYelp_SoundSet";
					noise="WolfRoarNoise";
					id=15;
				};
				class WolfDeath
				{
					soundSet="WolfDeath_SoundSet";
					noise="WolfRoarNoise";
					id=20;
				};
				class WolfHowl
				{
					soundSet="WolfHowl_SoundSet";
					noise="WolfRoarNoise";
					id=16;
				};
				class WolfHowls
				{
					soundSet="WolfHowls_SoundSet";
					noise="WolfRoarNoise";
					id=17;
				};
			};
			class Damages
			{
				class Bite
				{
					damage="WolfBiteDamage";
					id=1;
				};
				class BiteLow
				{
					damage="WolfLowBiteDamage";
					id=2;
				};
			};
		};
		class CommandMoveSettings
		{
			useSpeedMapping=1;
			movementSpeedMapping[]={0,0.25,0.5,1.2,4.5,12.2};
		};
		class CommandLookAtSettings
		{
			lookAtFilterTimeout=0.5;
			lookAtFilterSpeed=1.5700001;
		};
	};
	class Animal_CanisZALupus_Santa: Animal_CanisLupusSanta
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\animalSanta\data\wolf_Santa_co.paa",
			"\animalSanta\data\fur_alpha.paa"
		};
	};
	class WolfSteakMeatSanta: WolfSteakMeat
	{
		scope=2;
		displayName="Мясо раненого волка";
		descriptionShort="Продай или перекуси";
		model="\dz\gear\food\meat_steak.p3d";
		rotationFlags=34;
		weight=0;
		interactionWeight=1;
		quantityBar=1;
		varQuantityInit=150;
		varQuantityMin=0;
		varQuantityMax=150;
		itemSize[]={1,2};
		absorbency=0.30000001;
		inventorySlot[]=
		{
			"Ingredient",
			"DirectCookingA",
			"DirectCookingB",
			"DirectCookingC",
			"SmokingA",
			"SmokingB",
			"SmokingC",
			"SmokingD"
		};
		isMeleeWeapon=1;
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeFist";
				range=1;
			};
			class Heavy
			{
				ammo="MeleeFist_Heavy";
				range=1;
			};
			class Sprint
			{
				ammo="MeleeFist_Heavy";
				range=2.8;
			};
		};
		hiddenSelections[]=
		{
			"cs_raw"
		};
		hiddenSelectionsTextures[]=
		{
			"\animalSanta\data\meat_steak_wolfSanta_raw_co.paa",
			"\animalSanta\data\meat_steak_baked_co.paa",
			"\animalSanta\data\meat_steak_boiled_co.paa",
			"\animalSanta\data\meat_steak_dried_co.paa",
			"\animalSanta\data\meat_steak_burned_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\gear\food\data\meat_steak_raw.rvmat",
			"dz\gear\food\data\meat_steak_baked.rvmat",
			"dz\gear\food\data\meat_steak_boiled.rvmat",
			"dz\gear\food\data\meat_steak_dried.rvmat",
			"dz\gear\food\data\meat_steak_burnt.rvmat",
			"dz\gear\food\data\meat_steak_rotten.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=50;
					healthLevels[]=
					{
						
						{
							1,
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
						}
					};
				};
			};
		};
	};
	class WolfPeltSanta: WolfPelt
	{
		scope=2;
		displayName="Шкура раненного волка";
		descriptionShort="Продай";
		model="\dz\gear\consumables\Pelt_Wolf.p3d";
		weight=1200;
		itemSize[]={5,3};
		peltGain=6;
		leatherYield=4;
		hiddenSelections[]=
		{
			"camo",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"\animalSanta\data\pelt_wolf_Santa_co.paa",
			"\animalSanta\data\pelt_wolf_Santa_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=200;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\consumables\data\pelt_wolf.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\consumables\data\pelt_wolf.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\consumables\data\pelt_wolf_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\consumables\data\pelt_wolf_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\consumables\data\pelt_wolf_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class Animal_BearSanta: Animal_UrsusArctos
	{
		simulation="dayzanimal";
		scope=2;
		model="\DZ\animals_bliss\ursus_arctos\ursus_arctos.p3d";
		armor=1.2;
		displayName="Мишка Санты";
		descriptionShort="$STR_CfgVehicles_Animal_UrsusArctos1";
		aiAgentTemplate="Predator_UrsusArctos";
		injuryLevels[]={1,0.5,0.2,0};
		hiddenSelections[]=
		{
			"body_injury",
			"flags"
		};
		hiddenSelectionsTextures[]=
		{
			"\animalSanta\data\bear_Santa_co.paa"
		};
		DamageSphereAmmos[]=
		{
			"MeleeBear",
			"MeleeBearShock",
			"MeleeWolf"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=15000;
					healthLabels[]={1,0.69999999,0.5,0.30000001,0};
				};
				class Blood
				{
					hitpoints=7000;
				};
				class Shock
				{
					hitpoints=7000;
				};
			};
		};
		class Skinning
		{
			class ObtainedGolova
			{
				item = "";
				count = 1;
				quantityMinMaxCoef[] = {0.5,1};
			};
			class ObtainedPelt
			{
				item = "BearPeltBloodSanta";
				count = 1;
				quantityCoef = 1;
				transferToolDamageCoef = 1;
			};
			class ObtainedGuts
			{
				item = "Guts";
				count = 2;
				quantityMinMaxCoef[] = {0.5,1};
			};
			class ObtainedLard
			{
				item = "Lard";
				count = 3;
				quantityMinMaxCoef[] = {0,1};
			};
			class ObtainedSteaks
			{
				item = "BearSteakBloodMeatSanta";
				count = 5;
				quantityMinMaxCoef[] = {0,1};
			};	
			class ObtainedBones
			{
				item = "Bones";
				count = 3;
				quantityMinMaxCoef[] = {0.25,1};
				transferToolDamageCoef = 1;
			};
			class ObtainedTors
			{
				item = "";
				count = 1;
				quantityMinMaxCoef[] = {1,1};
				transferToolDamageCoef = 1;
			};

		};
	};
	class BearPeltBloodSanta: BearPelt
	{
		scope=2;
		displayName="Шкура Мишки Санты";
		descriptionShort="Борода будет доволен. ";
		model="\dz\gear\consumables\Pelt_Bear.p3d";
		weight=1200;
		itemSize[]={8,4};
		peltGain=10;
		leatherYield=12;
		hiddenSelections[]=
		{
			"camo",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"\animalSanta\data\pelt_bear_BloodSanta_co.paa",
			"\animalSanta\data\pelt_bear_BloodSanta_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=200;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\consumables\data\pelt_bear.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\consumables\data\pelt_bear.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\consumables\data\pelt_bear_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\consumables\data\pelt_bear_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\consumables\data\pelt_bear_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class BearSteakBloodMeatSanta: BearSteakMeat
	{
		scope=2;
		displayName="Мясо Мишки Санты";
		descriptionShort="Хавай и не подавись ";
		model="\dz\gear\food\meat_steak.p3d";
		rotationFlags=34;
		weight=0;
		interactionWeight=1;
		quantityBar=1;
		varQuantityInit=180;
		varQuantityMin=0;
		varQuantityMax=180;
		itemSize[]={2,2};
		absorbency=0.30000001;
		inventorySlot[]=
		{
			"Ingredient",
			"DirectCookingA",
			"DirectCookingB",
			"DirectCookingC",
			"SmokingA",
			"SmokingB",
			"SmokingC",
			"SmokingD"
		};
		isMeleeWeapon=1;
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeFist";
				range=1;
			};
			class Heavy
			{
				ammo="MeleeFist_Heavy";
				range=1;
			};
			class Sprint
			{
				ammo="MeleeFist_Heavy";
				range=2.8;
			};
		};
		hiddenSelections[]=
		{
			"cs_raw"
		};
		hiddenSelectionsTextures[]=
		{
			"\animalSanta\data\meat_raw_SantaSteak_co.paa",
			"\animalSanta\data\meat_steak_baked_co.paa",
			"\animalSanta\data\meat_steak_boiled_co.paa",
			"\animalSanta\data\meat_steak_dried_co.paa",
			"\animalSanta\data\meat_steak_burned_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\gear\food\data\meat_steak_raw.rvmat",
			"dz\gear\food\data\meat_steak_baked.rvmat",
			"dz\gear\food\data\meat_steak_boiled.rvmat",
			"dz\gear\food\data\meat_steak_dried.rvmat",
			"dz\gear\food\data\meat_steak_burnt.rvmat",
			"dz\gear\food\data\meat_steak_rotten.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=50;
					healthLevels[]=
					{
						
						{
							1,
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
						}
					};
				};
			};
		};
	};
	class Animal_BearGrizliSanta: Animal_UrsusArctos
	{
		simulation="dayzanimal";
		scope=2;
		model="\DZ\animals_bliss\ursus_arctos\ursus_arctos.p3d";
		armor=1.2;
		displayName="Гризли";
		descriptionShort="$STR_CfgVehicles_Animal_UrsusArctos1";
		aiAgentTemplate="Predator_UrsusArctos";
		injuryLevels[]={1,0.5,0.2,0};
		hiddenSelections[]=
		{
			"body_injury",
			"flags"
		};
		hiddenSelectionsTextures[]=
		{
			"\animalSanta\data\bear_GrizliSanta_co.paa"
		};
		DamageSphereAmmos[]=
		{
			"MeleeBear",
			"MeleeBearShock",
			"MeleeWolf"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=15000;
					healthLabels[]={1,0.69999999,0.5,0.30000001,0};
				};
				class Blood
				{
					hitpoints=9000;
				};
				class Shock
				{
					hitpoints=9000;
				};
			};
		};
		class Skinning
		{
			class ObtainedGolova
			{
				item = "";
				count = 1;
				quantityMinMaxCoef[] = {0.5,1};
			};
			class ObtainedPelt
			{
				item = "BearPeltGrizliSanta";
				count = 1;
				quantityCoef = 1;
				transferToolDamageCoef = 1;
			};
			class ObtainedGuts
			{
				item = "Guts";
				count = 2;
				quantityMinMaxCoef[] = {0.5,1};
			};
			class ObtainedLard
			{
				item = "Lard";
				count = 3;
				quantityMinMaxCoef[] = {0,1};
			};
			class ObtainedSteaks
			{
				item = "BearSteakGrizliMeatSanta";
				count = 5;
				quantityMinMaxCoef[] = {0,1};
			};	
			class ObtainedBones
			{
				item = "Bones";
				count = 3;
				quantityMinMaxCoef[] = {0.25,1};
				transferToolDamageCoef = 1;
			};
			class ObtainedTors
			{
				item = "";
				count = 1;
				quantityMinMaxCoef[] = {1,1};
				transferToolDamageCoef = 1;
			};

		};
	};
	class BearPeltGrizliSanta: BearPelt
	{
		scope=2;
		displayName="Шкура Гризли";
		descriptionShort="Борода будет доволен";
		model="\dz\gear\consumables\Pelt_Bear.p3d";
		weight=1200;
		itemSize[]={8,4};
		peltGain=10;
		leatherYield=12;
		hiddenSelections[]=
		{
			"camo",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"\animalSanta\data\pelt_bear_BloodSanta_co.paa",
			"\animalSanta\data\pelt_bearGrizliSanta_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=200;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\consumables\data\pelt_bear.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\consumables\data\pelt_bear.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\consumables\data\pelt_bear_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\consumables\data\pelt_bear_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\consumables\data\pelt_bear_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class BearSteakGrizliMeatSanta: BearSteakMeat
	{
		scope=2;
		displayName="Мясо Гризли";
		descriptionShort="Самый сочный стейк";
		model="\dz\gear\food\meat_steak.p3d";
		rotationFlags=34;
		weight=0;
		interactionWeight=1;
		quantityBar=1;
		varQuantityInit=180;
		varQuantityMin=0;
		varQuantityMax=180;
		itemSize[]={2,2};
		absorbency=0.30000001;
		inventorySlot[]=
		{
			"Ingredient",
			"DirectCookingA",
			"DirectCookingB",
			"DirectCookingC",
			"SmokingA",
			"SmokingB",
			"SmokingC",
			"SmokingD"
		};
		isMeleeWeapon=1;
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeFist";
				range=1;
			};
			class Heavy
			{
				ammo="MeleeFist_Heavy";
				range=1;
			};
			class Sprint
			{
				ammo="MeleeFist_Heavy";
				range=2.8;
			};
		};
		hiddenSelections[]=
		{
			"cs_raw"
		};
		hiddenSelectionsTextures[]=
		{
			"\animalSanta\data\meat_steakGrizliSanta_raw_co.paa",
			"\animalSanta\data\meat_steak_baked_co.paa",
			"\animalSanta\data\meat_steak_boiled_co.paa",
			"\animalSanta\data\meat_steak_dried_co.paa",
			"\animalSanta\data\meat_steak_burned_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\gear\food\data\meat_steak_raw.rvmat",
			"dz\gear\food\data\meat_steak_baked.rvmat",
			"dz\gear\food\data\meat_steak_boiled.rvmat",
			"dz\gear\food\data\meat_steak_dried.rvmat",
			"dz\gear\food\data\meat_steak_burnt.rvmat",
			"dz\gear\food\data\meat_steak_rotten.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=50;
					healthLevels[]=
					{
						
						{
							1,
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
						}
					};
				};
			};
		};
	};
};
