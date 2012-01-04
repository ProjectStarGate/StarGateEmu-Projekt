#include "ScriptPCH.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"

#define SAY_AGGRO "YOU tread upon the sacrosanct! Mortals have no place amidst the clouds."
#define SAY_RANDOM "BACK to the earth with you!"
#define SAY_RANDOM_1 "BACK to the earth with you!"
#define SAY_CAST_FIELD "Al'Akir, your servant calls for aid!"
#define SAY_DEATH "The winds take me!"

enum Spells
{
// Assad
SPELL_STORM = 86930, //Supremacy of the Storm
SPELL_CLING_H = 87618, //Static Cling
SPELL_FIELD = 86911, //Unstable Grounding Field
SPELL_CHAIN_N = 87622, //Chain Lightning
SPELL_CHAIN_H = 93993, //Chain Lightning
// Etoile tombe-ciel
SPELL_BARRAGE_N = 87854,
SPELL_BARRAGE_H = 92756,
};

enum Creatures
{
    NPC_SKYFALL_STAR = 45932,
};

enum Events
{
EVENT_STORM,
EVENT_CLING,
EVENT_FIELD,
EVENT_CHAIN,
EVENT_SUMMON,
EVENT_SAY,
EVENT_BARRAGE,
};

#define MAX_SUMMON_POS 5

const Position aSpawnLocations[5] =
{
    {2728.12f, -3544.43f, 261.91f, 6.04f},
    {2729.05f, -3544.47f, 261.91f, 5.58f},
    {2728.24f, -3465.08f, 264.20f, 3.56f},
    {2704.11f, -3456.81f, 265.53f, 4.51f},
    {2663.56f, -3464.43f, 262.66f, 5.20f},
};

/********
** Assad
*********/
class boss_assad: public CreatureScript
{
    public:
        boss_assad() : CreatureScript("boss_assad") { }

        struct boss_assadAI : public ScriptedAI
        {
boss_assadAI(Creature * pCreature) : ScriptedAI(pCreature), Summons(me)
{
pInstance = pCreature->GetInstanceScript();
}

InstanceScript* pInstance;
EventMap events;
SummonList Summons;

void EnterCombat(Unit * /*who*/)
{
EnterPhaseGround();
me->MonsterYell(SAY_AGGRO, 0, 0);
}

void JustDied(Unit* /*killer*/)
{
me->MonsterYell(SAY_DEATH, 0, 0);
}

void JustSummoned(Creature *pSummoned)
{
pSummoned->SetInCombatWithZone();
if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM,0))
                pSummoned->AI()->AttackStart(pTarget);

Summons.Summon(pSummoned);
}

void SummonedCreatureDespawn(Creature *summon)
{
Summons.Despawn(summon);
}

void EnterPhaseGround()
{
events.ScheduleEvent(EVENT_STORM, 50000);
events.ScheduleEvent(EVENT_CLING, 60000);
events.ScheduleEvent(EVENT_FIELD, 30000);
events.ScheduleEvent(EVENT_CHAIN, 20000);
events.ScheduleEvent(EVENT_SUMMON, 20000);
events.ScheduleEvent(EVENT_SAY, 45000);
}

void UpdateAI(const uint32 diff)
{
                if (!UpdateVictim())
                    return;

events.Update(diff);

while (uint32 eventId = events.ExecuteEvent())
{
switch(eventId)
{
case EVENT_SAY:
me->MonsterYell(SAY_RANDOM, 0, 0);
events.ScheduleEvent(EVENT_SAY, 45000);
return;
case EVENT_CLING:
DoCastAOE(SPELL_CLING_H);
events.ScheduleEvent(EVENT_CLING, 60000);
return;
case EVENT_FIELD:
me->MonsterYell(SAY_CAST_FIELD, 0, 0);
DoCast(me->getVictim(), SPELL_FIELD);
events.ScheduleEvent(EVENT_FIELD, 30000);
return;
case EVENT_STORM:
DoCast(me->getVictim(), SPELL_STORM);
events.ScheduleEvent(EVENT_STORM, 50000);
return;
case EVENT_CHAIN:
if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
DoCast(DUNGEON_MODE(SPELL_CHAIN_N,SPELL_CHAIN_H));
events.ScheduleEvent(EVENT_CHAIN, 20000);
return;
case EVENT_SUMMON:
me->SummonCreature(NPC_SKYFALL_STAR, aSpawnLocations[0].GetPositionX(), aSpawnLocations[0].GetPositionY(), aSpawnLocations[0].GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
me->SummonCreature(NPC_SKYFALL_STAR, aSpawnLocations[1].GetPositionX(), aSpawnLocations[1].GetPositionY(), aSpawnLocations[1].GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
me->SummonCreature(NPC_SKYFALL_STAR, aSpawnLocations[2].GetPositionX(), aSpawnLocations[2].GetPositionY(), aSpawnLocations[2].GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
me->SummonCreature(NPC_SKYFALL_STAR, aSpawnLocations[3].GetPositionX(), aSpawnLocations[3].GetPositionY(), aSpawnLocations[3].GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
events.ScheduleEvent(EVENT_SUMMON, 20000);
return;
}
}
DoMeleeAttackIfReady();
}
};

    CreatureAI* GetAI(Creature* creature) const
    {
return new boss_assadAI(creature);
    }
};

/**************
** Skyfall Star
***************/
class mob_star: public CreatureScript
{
    public:
        mob_star() : CreatureScript("mob_star") { }

        struct mob_starAI : public ScriptedAI
        {
mob_starAI(Creature * pCreature) : ScriptedAI(pCreature) {}

EventMap events;

void EnterCombat(Unit * /*who*/)
{
EnterPhaseGround();
}

void EnterPhaseGround()
{
events.ScheduleEvent(EVENT_BARRAGE, 5000);
}

void UpdateAI(const uint32 diff)
{
                if (!UpdateVictim())
                    return;

events.Update(diff);

while (uint32 eventId = events.ExecuteEvent())
{
switch(eventId)
{
case EVENT_BARRAGE:
if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
DoCast(pTarget, DUNGEON_MODE(SPELL_BARRAGE_N,SPELL_BARRAGE_H));
events.ScheduleEvent(EVENT_BARRAGE, 5000);
return;
}
}
}
};

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_starAI(creature);
        }
};

void AddSC_boss_assad()
{
    new boss_assad();
new mob_star();
};