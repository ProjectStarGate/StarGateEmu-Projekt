

#ifndef DEF_GRIM_BATOL_H
#define DEF_GRIM_BATOL_H

enum Data
{
    DATA_GENERAL_UMBRISS_EVENT,
    DATA_FORGEMASTER_THRONGUS_EVENT,
    DATA_DRAHGA_SHADOWBURNER_EVENT,
    DATA_ERUDAX_EVENT,
    DATA_TEAM_IN_INSTANCE,
};

enum Data64
{
    DATA_GENERAL_UMBRISS,
    DATA_FORGEMASTER_THRONGUS,
    DATA_DRAHGA_SHADOWBURNER,
    DATA_ERUDAX,
};

enum CreatureIds
{
    //Dungeon Bosses

    BOSS_GENERAL_UMBRISS        = 39625,
    BOSS_FORGEMASTER_THRONGUS   = 40177,
    BOSS_DRAHGA_SHADOWBURNER    = 40319,
    BOSS_ERUDAX                 = 40484,

    //Trash mobs

    NPC_ASCENDED_FLAMESEEKER    = 39415,
    NPC_ASCENDED_ROCKBREAKER    = 40272,
    NPC_ASCENDED_WATERLASHER    = 40273,
    NPC_ASCENDED_WINDWALKER     = 39414,
    NPC_AZURBORNE_GUARDIAN      = 39854,
    NPC_AZURBORNE_SEER          = 39855,
    NPC_AZURBORNE_WARLORD       = 39909,
    NPC_BATTERED_RED_DRAKE      = 48523,
    NPC_CRIMSONBORNE_GUARDIAN   = 39381,
    NPC_CRIMSONBORNE_SEER       = 40290,
    NPC_CRIMSONBORNE_WARLORD    = 39626,
    NPC_ENSLAVED_BURNING_EMBER  = 39892,
    NPC_ENSLAVED_ROCK_ELEMENTAL = 39900,
    NPC_ENSLAVED_THUNDER_SPIRIT = 40269,
    NPC_ENSLAVED_GRONN_BRUTE    = 40166,
    NPC_ENSLAVED_WATER_SPIRIT   = 39961,
    NPC_TWILIGHT_FIRE_CATCHER   = 39870,
    NPC_TWILIGHT_SHADOW_WEAVER  = 39954,
    NPC_TWILIGHT_STORM_BREAKER  = 39962,
    NPC_TWILIGHT_THUNDER_CALLER = 40270,
    NPC_TWILIGHT_WYRM_CALLER    = 39873,
	//MOB_FACELESS = 40600,



    //Various NPCs

    NPC_VELASTRASZA             = 50390,
    NPC_VALIONA                 = 40320,
    NPC_BALEFLAME               = 50387,
    NPC_FARSEER_TOORANU         = 50385,
};

enum GameObjectIds
{
    GO_DWARVEN_BONE_PILE        = 207411,
};


enum Spells
{
    //boss_erudax
    SPELL_PLAGUE = 82622, //seuche der zeitalter
    SPELL_ORKAN = 75664, //schattenorkan
    SPELL_SPAWN = 75704, //gesichtslosen beschwören
    //faceless curruptor
    SPELL_CORRUPTION = 75520,
    SPELL_UMBRALE = 75763,
    SPELL_SIPHON = 75755,
};

enum Yells
{
    SAY_AGGRO = -1800200,
    SAY_DEATH = -1800201,
    SAY_SUMMON = -1800201,
};

enum Events
{
    //boss_erudax
    EVENT_PLAGUE = 1,
    EVENT_ORKAN = 2,
    EVENT_SUMMON = 3,
    //faceless curruptor
    EVENT_CORRUPTION = 4,
    EVENT_UMBRALE = 5,
    EVENT_SIPHON = 6,
};

enum SummonIds
{
    MOB_FACELESS = 40600,
};

const Position aSpawnLocations[2] =
{
    {-0.0f, -0.0f, 0.0f, 0.0f},
    {-0.0f, -0.0f, 0.0f, 0.0f},
};

#endif