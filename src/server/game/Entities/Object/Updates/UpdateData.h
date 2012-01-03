/*
 * Copyright (C) 2010-2012 Project StarGate
 */

#ifndef __UPDATEDATA_H
#define __UPDATEDATA_H

#include "ByteBuffer.h"
class WorldPacket;

enum OBJECT_UPDATE_TYPE
{
    UPDATETYPE_VALUES               = 0,
    //UPDATETYPE_MOVEMENT             = 0xFF, //deleted in 4.0.3.
    UPDATETYPE_CREATE_OBJECT        = 1,
    UPDATETYPE_CREATE_OBJECT2       = 2,
    UPDATETYPE_OUT_OF_RANGE_OBJECTS = 3,
    //UPDATETYPE_NEAR_OBJECTS         = 0xFF //deleted in 4.0.3.
};

enum OBJECT_UPDATE_FLAGS
{
    UPDATEFLAG_NONE         = 0x0000,
    UPDATEFLAG_SELF         = 0x0001,
    UPDATEFLAG_TRANSPORT    = 0x0002,
    UPDATEFLAG_HAS_TARGET   = 0x0004,
    //UPDATEFLAG_LOWGUID      = 0x0008, deleted in 4.0.3
    //UPDATEFLAG_HIGHGUID     = 0x0010, deleted in 4.0.3
    UPDATEFLAG_LIVING       = 0x0020,
    UPDATEFLAG_HAS_POSITION = 0x0040,
    UPDATEFLAG_VEHICLE      = 0x0080,
    UPDATEFLAG_POSITION     = 0x0100,
    UPDATEFLAG_ROTATION     = 0x0200,
    UPDATEFLAG_UNK1         = 0x0400, //not found.
    UPDATEFLAG_UNK2         = 0x0800, //added in 4.0.3
    UPDATEFLAG_UNK3         = 0x1000, //added in 4.0.3
};

class UpdateData
{
    public:
        UpdateData();

        void AddOutOfRangeGUID(std::set<uint64>& guids);
        void AddOutOfRangeGUID(const uint64 &guid);
        void AddUpdateBlock(const ByteBuffer &block);
        bool BuildPacket(WorldPacket *packet);
        bool HasData() { return m_blockCount > 0 || !m_outOfRangeGUIDs.empty(); }
        void Clear();

        std::set<uint64> const& GetOutOfRangeGUIDs() const { return m_outOfRangeGUIDs; }
        uint16 m_map;

    protected:
        uint32 m_blockCount;
        std::set<uint64> m_outOfRangeGUIDs;
        ByteBuffer m_data;

        void Compress(void* dst, uint32 *dst_size, void* src, int src_size);
};
#endif