/*
 * Copyright 2024 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


static void clar_print_init(int test_count, int suite_count, const char *suite_names)
{
	(void)test_count;
	(void)suite_names;
	(void)suite_count;
	printf("TAP version 13\n");
}

static void clar_print_shutdown(int test_count, int suite_count, int error_count)
{
	(void)test_count;
	(void)suite_count;
	(void)error_count;

	if (!error_count)
		printf("# passed all %d test(s)\n", test_count);
	else
		printf("# failed %d among %d test(s)\n", error_count,
			test_count);
	printf("1..%d\n", test_count);
}

static void clar_print_error(int num, const struct clar_error *error)
{
	(void)num;

	printf("  ---\n");
	printf("  message : %s\n", error->error_msg);
	printf("  severity: fail\n");
	printf("  suite   : %s\n", error->suite);
	printf("  test    : %s\n", error->test);
	printf("  file    : %s\n", error->file);
	printf("  line    : %d\n", error->line_number);

	if (error->description != NULL)
		printf("  description: %s\n", error->description);

	printf("  ...\n");
}

static void clar_print_ontest(const char *test_name, int test_number, int failed)
{
	printf("%s %d - %s\n",
		failed ? "not ok" : "ok",
		test_number,
		test_name
	);

	clar_report_errors();
}

static void clar_print_onsuite(const char *suite_name, int suite_index)
{
	printf("# *** %s (#%d) ***\n", suite_name, suite_index);
}

static void clar_print_onabort(const char *msg, ...)
{
	va_list argp;
	va_start(argp, msg);
	fprintf(stdout, "Bail out! ");
	vfprintf(stdout, msg, argp);
	va_end(argp);
}
