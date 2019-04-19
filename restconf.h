/* 
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
#ifndef __RESTCONF_H__
#define __RESTCONF_H__

#define FLAGS_CONTENT_JSON       (1 << 0)
#define FLAGS_CONTENT_XML        (1 << 1)
#define FLAGS_ACCEPT_JSON        (1 << 2)
#define FLAGS_ACCEPT_XML         (1 << 3)

#define RESTCONF_API_PATH           "/restconf"
#define RESTCONF_API_DATA_PATH      RESTCONF_API_PATH "/data"
#define RESTCONF_API_RPC_PATH       RESTCONF_API_PATH "/operations"
#define RESTCONF_API_VERSION_PATH   RESTCONF_API_PATH "/yang-library-version"

char *restconf_api(int flags, const char *path, const char *action, const char *query);

#endif                          /* __RESTCONF_H__ */
