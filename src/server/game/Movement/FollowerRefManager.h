/*
 * Copyright (C) 2010-2012 Project StarGate
 */

#ifndef _FOLLOWERREFMANAGER
#define _FOLLOWERREFMANAGER

#include "RefManager.h"

class Unit;
class TargetedMovementGeneratorBase;

class FollowerRefManager : public RefManager<Unit, TargetedMovementGeneratorBase>
{
};
#endif