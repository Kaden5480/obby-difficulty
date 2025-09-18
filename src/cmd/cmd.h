#ifndef OBBY_DIFF_CMD_CMD_H
#define OBBY_DIFF_CMD_CMD_H

#include <stdio.h>

#include "parse.h"
#include "../common.h"
#include "../lib/display.h"

#define CMD_DEFAULT_IS_ETOH  true
#define CMD_DEFAULT_ACCURACY 2

/**
 * Each subcommand has its own `run`, `parse`, and `usage` functions.
 *
 * Where `run` runs the subcommand, `parse` parses command line arguments, and
 * the `usage` function displays the usage for the subcommand.
 *
 * For `run` the arguments are the number of
 * command line arguments and the command line arguments.
 *
 * For `parse` the arguments are the number of command line arguments,
 * the command line arguments, and where to store parsed values.
 *
 * For `usage` the only argument is `program` which is
 * a pointer to the string of the program name.
 */

/**
 * Converts between EToH and tiered difficulties.
 */
typedef struct CmdConvert {
    int accuracy;
    bool is_etoh;
    double number;
} CmdConvert;
void cmd_convert_usage(const char *program);
void cmd_convert_parse(int argc, char **argv, CmdConvert *store);
void cmd_convert_run(int argc, char **argv);

/**
 * Calculates how much harder one difficulty is than another.
 */
typedef struct CmdDiff {
    int accuracy;
    bool is_etoh;
    double a;
    double b;
} CmdDiff;
void cmd_diff_usage(const char *program);
void cmd_diff_parse(int argc, char **argv, CmdDiff *store);
void cmd_diff_run(int argc, char **argv);

/**
 * Calculates which difficulty is `t` times harder than the provided one.
 */
typedef struct CmdWhich {
    int accuracy;
    bool is_etoh;
    double n;
    double t;
} CmdWhich;
void cmd_which_usage(const char *program);
void cmd_which_parse(int argc, char **argv, CmdWhich *store);
void cmd_which_run(int argc, char **argv);

/**
 * Parses command line arguments and dispatches to the
 * corresponding subcommand.
 */
void cmd_usage(const char *program);
void cmd_run(int argc, char **argv);

#endif // OBBY_DIFF_CMD_CMD_H
