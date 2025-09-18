#ifndef OBBY_DIFF_CMD_PARSE_H
#define OBBY_DIFF_CMD_PARSE_H

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Trims whitespace from both ends of a string
 *
 * NOTE: This modifies the string in place, it doesn't allocate
 * any extra memory.
 *
 * @param str The string to trim
 * @returns A new pointer to the beginning of the string
 */
char *str_trim(char *str);

/**
 * Parses a double from a string.
 *
 * @param str The string to parse a double from
 * @param n Where to store the result
 * @returns True if successful, false otherwise
 */
bool parse_double(char *str, double *n);

/**
 * Parses an int from a string.
 *
 * @param str The string to parse an int from
 * @param n Where to store the result
 * @returns True if successful, false otherwise
 */
bool parse_int(char *str, int *n);

/**
 * Parses a command line argument.
 *
 * @param argc The number of command line arguments
 * @param argv The command line arguments
 * @param i The index of the flag to parse for
 * @param value Where to store the argument
 * @returns True if parsed successfully, false otherwise
 */
bool parse_arg(int argc, char **argv, int i, char **value);

/**
 * Parses a double from command line arguments.
 *
 * @param argc The number of command line arguments
 * @param argv The command line arguments
 * @param i The index of the flag to parse for
 * @param value Where to store the double
 * @returns True if parsed successfully, false otherwise
 */
bool parse_arg_double(int argc, char **argv, int i, double *value);

/**
 * Parses an int from command line arguments.
 *
 * @param argc The number of command line arguments
 * @param argv The command line arguments
 * @param i The index of the flag to parse for
 * @param value Where to store the int
 * @returns True if parsed successfully, false otherwise
 */
bool parse_arg_int(int argc, char **argv, int i, int *value);

#endif // OBBY_DIFF_CMD_PARSE_H
