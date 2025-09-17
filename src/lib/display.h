#ifndef OBBY_DIFF_LIB_DISPLAY_H
#define OBBY_DIFF_LIB_DISPLAY_H

#include "../args.h"
#include "calc.h"

/**
 * Parses a double from a string.
 *
 * @param str The string to parse a double from
 * @param n Where to store the result
 * @returns True if successful, false otherwise
 */
bool parse_double(char *str, double *n);

/**
 * Displays the conversion for an EToH difficulty as
 * a tiered difficulty.
 *
 * @param accuracy The accuracy to display values with
 * @param n The EToH difficulty
 */
void show_etoh_to_tier(int accuracy, double n);

/**
 * Displays the conversion for a tiered difficulty as
 * an EToH difficulty.
 *
 * @param accuracy The accuracy to display values with
 * @param n The tiered difficulty
 */
void show_tier_to_etoh(int accuracy, double n);

/**
 * Displays how much harder difficulty `a` is than `b`.
 * (EToH)
 *
 * @param accuracy The accuracy to display values with
 * @param a The first difficulty
 * @param b The second difficulty
 */
void show_harder_etoh(int accuracy, double a, double b);

/**
 * Displays how much harder difficulty `a` is than `b`.
 * (Tiered)
 *
 * @param accuracy The accuracy to display values with
 * @param a The first difficulty
 * @param b The second difficulty
 */
void show_harder_tier(int accuracy, double a, double b);

/**
 * Displays which difficulty is `t` times harder than `n`.
 * (EToH)
 *
 * @param accuracy The accuracy to display values with
 * @param n The difficulty
 * @param t The times harder
 */
void show_which_etoh(int accuracy, double n, double t);

/**
 * Displays which difficulty is `t` times harder than `n`.
 * (Tiered)
 *
 * @param accuracy The accuracy to display values with
 * @param n The difficulty
 * @param t The times harder
 */
void show_which_tier(int accuracy, double n, double t);

/**
 * Displays the output for the provided arguments.
 *
 * @param args The parsed command line arguments
 */
void show_output(Args args);

#endif // OBBY_DIFF_LIB_DISPLAY_H
