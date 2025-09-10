#ifndef OBBY_DIFF_LIB_DISPLAY_H
#define OBBY_DIFF_LIB_DISPLAY_H

#include "../args.h"
#include "calc.h"

/**
 * Displays how much harder difficulty `a` is than `b`.
 * (EToH)
 *
 * @param args The parsed command line arguments
 * @param a The first difficulty
 * @param b The second difficulty
 */
void show_harder_etoh(Args args, double a, double b);

/**
 * Displays how much harder difficulty `a` is than `b`.
 * (Tiered)
 *
 * @param args The parsed command line arguments
 * @param a The first difficulty
 * @param b The second difficulty
 */
void show_harder_tier(Args args, double a, double b);

/**
 * Displays the conversion for an EToH difficulty as
 * a tiered difficulty.
 *
 * @param args The parsed command line arguments
 * @param n The EToH difficulty
 */
void show_etoh_to_tier(Args args, double n);

/**
 * Displays the conversion for a tiered difficulty as
 * an EToH difficulty.
 *
 * @param args The parsed command line arguments
 * @param n The tiered difficulty
 */
void show_tier_to_etoh(Args args, double n);

/**
 * Displays the output for the provided arguments.
 *
 * @param args The parsed command line arguments
 */
void show_output(Args args);

#endif // OBBY_DIFF_LIB_DISPLAY_H
