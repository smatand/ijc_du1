#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "error.h"

/**
 * warning message to stderr without terminating the program
 *
 * @param fmt (works as in printf("%s", fmt)
 * @param ...
 */
void warning_msg(const char *fmt, ...) {
	va_list args; // hold data about given args
	va_start(args, fmt); // enable access to data
	fprintf(stderr, "CHYBA: ");
	vfprintf(stderr, fmt, args); // formatted output
	fprintf(stderr, "\n");
	va_end(args); // disable access
}

/**
 * warning message and terminate program by exit() function
 *
 * @param fmt (works as in printf("%s", fmt)
 * @param ...
 */
void error_exit(const char *fmt, ...) {
	va_list args;
	va_start(args, fmt);
	fprintf(stderr, "CHYBA: ");
	vfprintf(stderr, fmt, args);
	fprintf(stderr, "\n");
	va_end(args);

	exit(1);
}
