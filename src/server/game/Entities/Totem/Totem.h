/*
 * Copyright (C) 2010-2011 Project StarGate
 */

#ifndef TRINITYCORE_TOTEM_H
#define TRINITYCORE_TOTEM_H

#include "TemporarySummon.h"

enum TotemType
{
    TOTEM_PASSIVE    = 0,
    TOTEM_ACTIVE     = 1,
    TOTEM_STATUE     = 2 // copied straight from MaNGOS, may need more implementation to work
};

#define SENTRY_TOTEM_ENTRY  3968

class Totem : public Minion
{
    public:
        explicit Totem(SummonPropertiesEntry const *properties, Unit *owner);
        virtual ~Totem(){};
        void Update(uint32 time);
        void InitStats(uint32 duration);
        void InitSummon();
        void UnSummon();
        uint32 GetSpell(uint8 slot=0) const { return m_spells[slot]; }
        uint32 GetTotemDuration() const { return m_duration; }
        TotemType GetTotemType() const { return m_type; }

        bool UpdateStats(Stats /*stat*/) { return true; }
        bool UpdateAllStats() { return true; }
        void UpdateResistances(uint32 /*school*/) {}
        void UpdateArmor() {}
        void UpdateMaxHealth() {}
        void UpdateMaxPower(Powers /*power*/) {}
        void UpdateAttackPowerAndDamage(bool /*ranged*/) {}
        void UpdateDamagePhysical(WeaponAttackType /*attType*/) {}

        bool IsImmunedToSpellEffect(SpellEntry const* spellInfo, uint32 index) const;

    protected:
        TotemType m_type;
        uint32 m_duration;
};
#endif