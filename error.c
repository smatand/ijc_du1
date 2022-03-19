// error.c
// Riesenie IJC-DU1, priklad b), 22.03.2022
// Autor: Andrej Smatana, FIT
// Prelozene: gcc 9.4.0

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "error.h"

void warning_msg(const char *fmt, ...) {
	va_list args; // hold data about given args
	va_start(args, fmt); // enable access to data
	fprintf(stderr, "CHYBA: ");
	vfprintf(stderr, fmt, args); // formatted output
	fprintf(stderr, "\n");
	va_end(args); // disable access
}

void error_exit(const char *fmt, ...) {
	va_list args;
	va_start(args, fmt);
	fprintf(stderr, "CHYBA: ");
	vfprintf(stderr, fmt, args);
	fprintf(stderr, "\n");
	va_end(args);

	exit(1);
}
