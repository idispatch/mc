/*
   libmc - checks for processing esc sequences in replace string

   Copyright (C) 2011-2025
   Free Software Foundation, Inc.

   Written by:
   Andrew Borodin <aborodin@vmail.ru>, 2014

   This file is part of the Midnight Commander.

   The Midnight Commander is free software: you can redistribute it
   and/or modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation, either version 3 of the License,
   or (at your option) any later version.

   The Midnight Commander is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#define TEST_SUITE_NAME "lib/search/glob"

#include "tests/mctest.h"

#include "glob.c"  // for testing static functions

/* --------------------------------------------------------------------------------------------- */

/* @DataSource("test_glob_prepare_replace_str_ds") */
static const struct test_glob_prepare_replace_str_ds
{
    const char *input_value;
    const char *glob_str;
    const char *replace_str;
    const char *expected_result;
} test_glob_prepare_replace_str_ds[] = {
    {
        // 0.
        "qqwwee",
        "*ww*",
        "\\1AA\\2",
        "qqAAee",
    },
    {
        // 1.
        "qqwwee",
        "*qq*",
        "\\1SS\\2",
        "SSwwee",
    },
    {
        // 2.
        "qqwwee",
        "*ee*",
        "\\1RR\\2",
        "qqwwRR",
    },
};

/* @Test(dataSource = "test_glob_prepare_replace_str_ds") */
START_PARAMETRIZED_TEST (test_glob_prepare_replace_str, test_glob_prepare_replace_str_ds)
{
    // given
    mc_search_t *s;
    char *dest_str;

    s = mc_search_new (data->glob_str, NULL);
    s->is_case_sensitive = TRUE;
    s->search_type = MC_SEARCH_T_GLOB;

    // when
    mc_search_run (s, data->input_value, 0, strlen (data->input_value), NULL);
    dest_str = mc_search_prepare_replace_str2 (s, data->replace_str);

    // then
    mctest_assert_str_eq (dest_str, data->expected_result);

    g_free (dest_str);
    mc_search_free (s);
}
END_PARAMETRIZED_TEST

/* --------------------------------------------------------------------------------------------- */

int
main (void)
{
    TCase *tc_core;

    tc_core = tcase_create ("Core");

    // Add new tests here: ***************
    mctest_add_parameterized_test (tc_core, test_glob_prepare_replace_str,
                                   test_glob_prepare_replace_str_ds);
    // ***********************************

    return mctest_run_all (tc_core);
}

/* --------------------------------------------------------------------------------------------- */
