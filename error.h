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
