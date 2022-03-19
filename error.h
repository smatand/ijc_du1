// error.h
// Riesenie IJC-DU1, priklad b), 22.03.2022
// Autor: Andrej Smatana, FIT
// Prelozene: gcc 9.4.0

#ifndef ERROR_H
#define ERROR_H

/**
 * @brief Print out warning message
 *
 * @param *fmt is formatted string
 */
void warning_msg(const char *fmt, ...);

/**
 * @brief Print out warning message and terminate the program
 *
 * @param *fmt is formatted string
 */
void error_exit(const char *fmt, ...);

#endif // ERROR_H
