#ifndef OBBY_DIFF_ARGS_H
#define OBBY_DIFF_ARGS_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

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
    bool harder;

    // Whether the inputs are EToH difficulties
    bool is_etoh;
} Args;

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
