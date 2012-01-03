/*
 * Copyright (C) 2010-2012 Project StarGate
 */

#ifndef TRINITY_PASSIVEAI_H
#define TRINITY_PASSIVEAI_H

#include "CreatureAI.h"
//#include "CreatureAIImpl.h"

class PassiveAI : public CreatureAI
{
    public:
        explicit PassiveAI(Creature *c);

        void MoveInLineOfSight(Unit *) {}
        void AttackStart(Unit *) {}
        void UpdateAI(const uint32);

        static int Permissible(const Creature *) { return PERMIT_BASE_IDLE;  }
};

class PossessedAI : public CreatureAI
{
    public:
        explicit PossessedAI(Creature *c);

        void MoveInLineOfSight(Unit *) {}
        void AttackStart(Unit *target);
        void UpdateAI(const uint32);
        void EnterEvadeMode() {}

        void JustDied(Unit*);
        void KilledUnit(Unit* victim);

        static int Permissible(const Creature *) { return PERMIT_BASE_IDLE;  }
};

class NullCreatureAI : public CreatureAI
{
    public:
        explicit NullCreatureAI(Creature *c);

        void MoveInLineOfSight(Unit *) {}
        void AttackStart(Unit *) {}
        void UpdateAI(const uint32) {}
        void EnterEvadeMode() {}
        void OnCharmed(bool /*apply*/) {}

        static int Permissible(const Creature *) { return PERMIT_BASE_IDLE;  }
};

class CritterAI : public PassiveAI
{
    public:
        explicit CritterAI(Creature *c) : PassiveAI(c) {}

        void DamageTaken(Unit *done_by, uint32 & /*damage*/);
        void EnterEvadeMode();
};

class TriggerAI : public NullCreatureAI
{
    public:
        explicit TriggerAI(Creature *c) : NullCreatureAI(c) {}
        void IsSummonedBy(Unit *summoner);
};

#endif