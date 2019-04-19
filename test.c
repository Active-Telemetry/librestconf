/*
 * @file test.c
 * Unit tests for librestconf
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
#include <glib.h>

static void test_test1(void)
{
    g_assert_cmpstr("test string", ==, "test string");
}

static void test_test2(void)
{
    g_assert_cmpstr("test string", !=, "not test string");
}

int main(int argc, char *argv[])
{
    g_test_init(&argc, &argv, NULL);
    g_test_add_func("/restconf/test1", test_test1);
    g_test_add_func("/restconf/test2", test_test2);
    return g_test_run();
}
