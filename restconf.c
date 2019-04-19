/**
 * RESTCONF(RFC8040)
 *
 * Copyright (C) 2019 ECLB Ltd
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this library. If not, see <http://www.gnu.org/licenses/>
 */
#include "internal.h"

static char *restconf_api_data_options(int flags, const char *path, const char *action,
                                       const char *query)
{
    VERBOSE("OPTIONS: todo\n");
    return NULL;
}

static char *restconf_api_data_head(int flags, const char *path, const char *action,
                                    const char *query)
{
    VERBOSE("HEAD: todo\n");
    return NULL;
}

static char *restconf_api_data_get(int flags, const char *path, const char *action,
                                   const char *query)
{
    VERBOSE("HEAD: todo\n");
    return NULL;
}

static char *restconf_api_data_post(int flags, const char *path, const char *action,
                                    const char *query)
{
    VERBOSE("POST: todo\n");
    return NULL;
}

static char *restconf_api_data_put(int flags, const char *path, const char *action,
                                   const char *query)
{
    VERBOSE("PUT: todo\n");
    return NULL;
}

static char *restconf_api_data_patch(int flags, const char *path, const char *action,
                                     const char *query)
{
    VERBOSE("PATCH: todo\n");
    return NULL;
}

static char *restconf_api_data_delete(int flags, const char *path, const char *action,
                                      const char *query)
{
    VERBOSE("DELETE: todo\n");
    return NULL;
}

char *restconf_api(int flags, const char *path, const char *action, const char *query)
{
    char *resp = NULL;

    /* Sanity check parameters */
    if (!path || !action ||
        !(flags & FLAGS_ACCEPT_JSON) ||
        strncmp(path, RESTCONF_API_PATH, strlen(RESTCONF_API_PATH)) != 0) {
        ERROR("ERROR: invalid parameters (flags:0x%x, path:%s, action:%s)\n",
              flags, path, action);
        return NULL;
    }

    VERBOSE("%s(0x%x) %s%s\n", action, flags, path, query);

    /* Data */

    /* Authentication */

    /* Process method */
    if (strncmp(path, RESTCONF_API_DATA_PATH, strlen(RESTCONF_API_DATA_PATH)) == 0) {
        if (strcmp(action, "OPTIONS") == 0)
            resp = restconf_api_data_options(flags, path, action, query);
        else if (strcmp(action, "HEAD") == 0)
            resp = restconf_api_data_head(flags, path, action, query);
        else if (strcmp(action, "GET") == 0)
            resp = restconf_api_data_get(flags, path, action, query);
        else if (strcmp(action, "POST") == 0)
            resp = restconf_api_data_post(flags, path, action, query);
        else if (strcmp(action, "PUT") == 0)
            resp = restconf_api_data_put(flags, path, action, query);
        else if (strcmp(action, "PATCH") == 0)
            resp = restconf_api_data_patch(flags, path, action, query);
        else if (strcmp(action, "DELETE") == 0)
            resp = restconf_api_data_delete(flags, path, action, query);
    } else if (strncmp(path, RESTCONF_API_RPC_PATH, strlen(RESTCONF_API_RPC_PATH)) == 0) {
        VERBOSE("RPC: todo\n");
    } else if (strncmp(path, RESTCONF_API_VERSION_PATH,
                       strlen(RESTCONF_API_VERSION_PATH)) == 0) {
        resp = strdup("Status: 200\r\n"
                      "Content-Type: application/yang-data+xml\r\n"
                      "\r\n" "{\"yang-library-version\": \"2016-06-21\"}");
    }
    return resp;
}
