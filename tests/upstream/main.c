/* SPDX-License-Identifier: BSD-3-Clause */
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>
int upstream_tests_main(int argc, char **argv);
int main(void)
{
	char *args[] = {"nghttp3-tests", "--no-fork", "--seed", "0x51a7", NULL};
	int rc;
	setvbuf(stdout, NULL, _IONBF, 0);
	if (mkdir("/tmp", 0700) && errno != EEXIST)
		return 1;
	rc = upstream_tests_main(4, args);
	printf("UPSTREAM_TESTS nghttp3 %s\n", rc ? "FAIL" : "PASS");
	return rc;
}
