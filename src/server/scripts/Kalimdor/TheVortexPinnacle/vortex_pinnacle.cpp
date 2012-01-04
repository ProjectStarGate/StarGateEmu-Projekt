#include "InstanceScript.h"
#include "ScriptedGossip.h"
#include "ScriptPCH.h"
#include "vortex_pinnacle.h"

class npc_slipstream : public CreatureScript
{
public:
    npc_slipstream() : CreatureScript("npc_slipstream") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 Sender, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();

        if (Sender != GOSSIP_SENDER_MAIN)
            return true;
        if (!player->getAttackers().empty())
            return true;

        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                player->TeleportTo(657, -914.87f, -190.27f, 664.50f, 2.43f);
            break;
            case GOSSIP_ACTION_INFO_DEF+2:
                player->TeleportTo(657, -1189.04f, 475.85f, 634.78f, 0.46f);
            break;
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        InstanceScript* instance = creature->GetInstanceScript();

        if (instance && instance->GetData(DATA_GRAND_VIZIER_ERTAN)==DONE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Teleport me to platform 2", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        if (instance && instance->GetData(DATA_ALTAIRUS)==DONE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Teleport me to platform 3", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);

        player->SEND_GOSSIP_MENU(2475, creature->GetGUID());
        return true;
    }
};

void AddSC_vortex_pinnacle()
{
    new npc_slipstream();
}