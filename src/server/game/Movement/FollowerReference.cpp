/*
 * Copyright (C) 2010-2012 Project StarGate
 */

#include "gamePCH.h"
#include "Unit.h"
#include "TargetedMovementGenerator.h"
#include "FollowerReference.h"

void FollowerReference::targetObjectBuildLink()
{
    getTarget()->addFollower(this);
}

void FollowerReference::targetObjectDestroyLink()
{
    getTarget()->removeFollower(this);
}

void FollowerReference::sourceObjectDestroyLink()
{
    getSource()->stopFollowing();
}