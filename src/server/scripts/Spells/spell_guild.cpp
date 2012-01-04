/*
 * Copyright (C) 2010-2012 Project StarGate
 */

#include "ScriptPCH.h"
#include "SpellAuraEffects.h"

class spell_massenwiederbelebung : public SpellScriptLoader
{
public:
    spell_massenwiederbelebung() : SpellScriptLoader("spell_massenwiederbelebung") { }

    class spell_massenwiederbelebung_AuraScript : public AuraScript
    {
        void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* target = GetTarget();
            if (Unit* pCaster = GetCaster())
                pCaster->CastSpell(target, 72423, true);
        }

        void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
        }

        void Register()
        {
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_massenwiederbelebung_AuraScript();
    }
};

void AddSC_Guild_spell_scripts()
{
    new spell_massenwiederbelebung;
}