#include"ScriptPCH.h"
#include"halls_of_origination.h"

#define ENCOUNTERS 7

/* Boss Encounters
Temple Guardian Anhuur
Earthrager Ptah
Anraphet
Isiset
Ammunae
Setesh
Rajh
*/

class instance_halls_of_origination : public InstanceMapScript
{
public:
    instance_halls_of_origination() : InstanceMapScript("instance_halls_of_origination", 644) { }

    InstanceScript* GetInstanceScript(InstanceMap *map) const
    {
        return new instance_halls_of_origination_InstanceMapScript(map);
    }

    struct instance_halls_of_origination_InstanceMapScript: public InstanceScript
    {
        instance_halls_of_origination_InstanceMapScript(InstanceMap *map) : InstanceScript(map) { }

        uint32 uiEncounter[ENCOUNTERS];

        uint64 uiTempleGuardianAnhuur;
        uint64 uiEarthragerPtah;
        uint64 uiAnraphet;
        uint64 uiIsiset;
        uint64 uiAmmunae;
        uint64 uiSetesh;
        uint64 uiRajh;
        uint64 uiLightsBossDoorGUID;
		uint64 uiLightsHallDoorGUID;
        uint64 uiTeamInInstance;
        uint64 uiAnhuurBridgeGUID;
		uint64 uiAnhuurDoorGUID;

        void Initialize()
        {
            uiTempleGuardianAnhuur = 0;
            uiEarthragerPtah = 0;
            uiAnraphet = 0;
            uiIsiset = 0;
            uiAmmunae = 0;
            uiSetesh = 0;
            uiRajh = 0;
            uiAnhuurBridgeGUID = 0;
			uiAnhuurDoorGUID = 0;
            uiLightsBossDoorGUID = 0;
			uiLightsHallDoorGUID = 0;

            for(uint8 i=0; i<ENCOUNTERS; ++i)
                uiEncounter[i] = NOT_STARTED;
        }

        bool IsEncounterInProgress() const
        {
            for(uint8 i=0; i<ENCOUNTERS; ++i)
            {
                if (uiEncounter[i] == IN_PROGRESS)
                    return true;
            }

            return false;
        }

        void OnCreatureCreate(Creature* creature, bool)
        {
            switch(creature->GetEntry())
            {
                case BOSS_TEMPLE_GUARDIAN_ANHUUR:
                    uiTempleGuardianAnhuur = creature->GetGUID();
                    break;
                case BOSS_EARTHRAGER_PTAH:
                    uiEarthragerPtah = creature->GetGUID();
                    break;
                case BOSS_ANRAPHET:
                    uiAnraphet = creature->GetGUID();
                    break;
                case BOSS_ISISET:
                    uiIsiset = creature->GetGUID();
                    break;
                case BOSS_AMMUNAE:
                    uiAmmunae = creature->GetGUID();
                    break;
                case BOSS_SETESH:
                    uiSetesh = creature->GetGUID();
                case BOSS_RAJH:
                    uiRajh = creature->GetGUID();
            }
        }

        void OnGameObjectCreate(GameObject* go)
        {
            switch (go->GetEntry()) /* Lights_Boss_Door */
            {
                case GO_Lights_Boss_Door:
                    uiLightsBossDoorGUID = go->GetGUID();
                    //if (GetData(DATA_FLAME_WARDEN) == DONE && GetData(DATA_EARTH_WARDEN) == DONE && GetData(DATA_WATER_WARDEN) == DONE && GetData(DATA_AIR_WARDEN) == DONE)
                    if (GetData(DATA_WATER_WARDEN) == DONE)    
					HandleGameObject(uiLightsBossDoorGUID, true, go);

                            //go->SetUInt32Value(GAMEOBJECT_LEVEL, 0);
                            go->SetGoState(GO_STATE_ACTIVE);
                        
                    break;
				case GO_Lights_Hall_Door:
                    uiLightsHallDoorGUID = go->GetGUID();
                    if (GetData(DATA_EARTHRAGER_PTAH) == DONE)
                            HandleGameObject(uiLightsHallDoorGUID, true, go);
                    break;
                case GO_ANHUUR_BRIDGE:
                    uiAnhuurBridgeGUID = go->GetGUID();
                    if (GetData(DATA_TEMPLE_GUARDIAN_ANHUUR) == DONE)
                            HandleGameObject(uiAnhuurBridgeGUID, true, go);

				case GO_ANHUUR_BRIDGE2:
                    uiAnhuurBridgeGUID = go->GetGUID();
                    if (GetData(DATA_TEMPLE_GUARDIAN_ANHUUR) == DONE)
                            HandleGameObject(uiAnhuurBridgeGUID, true, go);
                    break;
				case GO_ANHUUR_DOOR:
                    uiAnhuurDoorGUID = go->GetGUID();
                    if (GetData(DATA_TEMPLE_GUARDIAN_ANHUUR) == DONE)
                            HandleGameObject(uiAnhuurDoorGUID, true, go);
                    break;
            }
        }

        uint64 GetData64(uint32 identifier)
        {
            switch(identifier)
            {
                case DATA_TEMPLE_GUARDIAN_ANHUUR:
                    return uiTempleGuardianAnhuur;
                case DATA_EARTHRAGER_PTAH:
                    return uiEarthragerPtah;
                case DATA_ANRAPHET:
                    return uiAnraphet;
                case DATA_ISISET:
                    return uiIsiset;
                case DATA_AMMUNAE:
                    return uiAmmunae;
                case DATA_SETESH:
                    return uiSetesh;
                case DATA_RAJH:
                    return uiRajh;
            }
            return 0;
        }

        void SetData(uint32 type,uint32 data)
        {
            switch(type)
            {
                case DATA_TEMPLE_GUARDIAN_ANHUUR:
                    uiEncounter[0] = data;
                    break;
                case DATA_EARTHRAGER_PTAH:
                    uiEncounter[1] = data;
                    break;
                case DATA_ANRAPHET:
                    uiEncounter[2] = data;
                    break;
                case DATA_ISISET:
                    uiEncounter[3] = data;
                    break;
                case DATA_AMMUNAE:
                    uiEncounter[4] = data;
                    break;
                case DATA_SETESH:
                    uiEncounter[5] = data;
                    break;
                case DATA_RAJH:
                    uiEncounter[6] = data;
                    break;
            }

            if (data == DONE)
                SaveToDB();
        }

        uint32 GetData(uint32 type)
        {
            switch(type)
            {
                case DATA_TEMPLE_GUARDIAN_ANHUUR:
                    return uiEncounter[0];
                case DATA_EARTHRAGER_PTAH:
                    return uiEncounter[1];
                case DATA_ANRAPHET:
                    return uiEncounter[2];
                case DATA_ISISET:
                    return uiEncounter[3];
                case DATA_AMMUNAE:
                    return uiEncounter[4];
                case DATA_SETESH:
                    return uiEncounter[5];
                case DATA_RAJH:
                    return uiEncounter[6];
            }
            return 0;
        }

        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;

            std::string str_data;
            std::ostringstream saveStream;
            saveStream << "H O" << uiEncounter[0] << " " << uiEncounter[1] << " " << uiEncounter[2] << " " << uiEncounter[3] << " " << uiEncounter[4] << " " << uiEncounter[5] << " " << uiEncounter[6];
            str_data = saveStream.str();

            OUT_SAVE_INST_DATA_COMPLETE;
            return str_data;
        }

        void Load(const char* in)
        {
            if (!in)
            {
                OUT_LOAD_INST_DATA_FAIL;
                return;
            }

            OUT_LOAD_INST_DATA(in);

            char dataHead1, dataHead2;
            uint16 data0, data1, data2, data3, data4, data5, data6;

            std::istringstream loadStream(in);
            loadStream >> dataHead1 >> dataHead2 >> data0 >> data1 >> data2 >> data3 >> data4 >> data5 >> data6;

            if (dataHead1 == 'H' && dataHead2 == 'O')
            {
                uiEncounter[0] = data0;
                uiEncounter[1] = data1;
                uiEncounter[2] = data2;
                uiEncounter[3] = data3;
                uiEncounter[4] = data4;
                uiEncounter[5] = data5;
                uiEncounter[6] = data6;

                for(uint8 i=0; i<ENCOUNTERS; ++i)
                    if (uiEncounter[i] == IN_PROGRESS)
                        uiEncounter[i] = NOT_STARTED;
            }
            else OUT_LOAD_INST_DATA_FAIL;

            OUT_LOAD_INST_DATA_COMPLETE;
        }
    };
};

void AddSC_instance_halls_of_origination()
{
    new instance_halls_of_origination();
}