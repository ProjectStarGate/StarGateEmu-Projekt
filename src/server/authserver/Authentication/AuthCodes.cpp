/*
 * Copyright (C) 2010-2011 Project StarGate
 *
 */

#include "AuthCodes.h"

namespace AuthHelper
{
    bool IsPreBCAcceptedClientBuild(int build)
    {
        int accepted_versions[] = PRE_BC_ACCEPTED_CLIENT_BUILD;

        for (int i = 0; accepted_versions[i]; ++i)
            if (build == accepted_versions[i])
                return true;

        return false;
    }

    bool IsPostBCAcceptedClientBuild(int build)
    {
        int accepted_versions[] = POST_BC_ACCEPTED_CLIENT_BUILD;

        for (int i = 0; accepted_versions[i]; ++i)
            if (build == accepted_versions[i])
                return true;

        return false;
    }

    bool IsPostWotLKAcceptedClientBuild(int build)
    {
        int accepted_versions[] = POST_WOTLK_ACCEPTED_CLIENT_BUILD;

        for (int i = 0; accepted_versions[i]; ++i)
            if (build == accepted_versions[i])
                return true;

        return false;
    }

    bool IsAcceptedClientBuild(int build)
    {
        return (IsPostWotLKAcceptedClientBuild(build) || IsPostBCAcceptedClientBuild(build) || IsPreBCAcceptedClientBuild(build));
    }
};