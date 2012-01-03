/*
 * Copyright (C) 2010-2012 Project StarGate
 */

#include "ScriptPCH.h"
#include "SpellAuraEffects.h"



class spell_massenwiederbelebung : public SpellScriptLoader
{
    public:
        spell_massenwiederbelebung() : SpellScriptLoader("spell_massenwiederbelebung") { }

        class spell_massenwiederbelebung_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_massenwiederbelebung_SpellScript)

            bool Validate(SpellEntry const * /*spellEntry*/)
            {
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (Unit * caster = GetCaster())
                {
                    if (caster->GetTypeId() != TYPEID_PLAYER)
                        return;

                    caster->ToPlayer()->KilledMonsterCredit(44175, 0);
                }
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_massenwiederbelebung_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_HEAL);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_massenwiederbelebung_SpellScript();
        }
};

void AddSC_priest_spell_scripts()
{
    new spell_massenwiederbelebung;
}