#ifndef OBBY_DIFF_ARGS_H
#define OBBY_DIFF_ARGS_H

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

/**
 * Which mode to use.
 */
typedef enum Mode {
    // Convert between EToH/Tiered difficulties
    MODE_CONVERT,

    // How much harder is difficulty `a` than `b`
    MODE_HARDER,

    // Which difficulty is `t` times harder than `n`
    MODE_WHICH,
} Mode;

typedef struct Args {
    // Number of command line arguments
    // and the arguments
    int argc;
    char **argv;

    // How accurately to display values
    char *accuracy;

    // Input difficulties
    char *a;
    char *b;

    // Whether to check if `b` is harder than `a`
    Mode mode;

    // Whether the inputs are EToH difficulties
    bool is_etoh;
} Args;

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
 * Shows the help for this program.
 *
 * @param args An Args struct which has already parsed command
 *             line arguments
 */
void Args_show_usage(Args args);


/**
 * Parses command line arguments, collecting values into
 * an Args struct.
 *
 * @param args The Args struct to collect values into
 * @param argc The number of command line arguments
 * @param argv The command line arguments
 */
void Args_from(Args *args, int argc, char *argv[]);

#endif // OBBY_DIFF_ARGS_H
