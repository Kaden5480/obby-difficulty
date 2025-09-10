#ifndef OBBY_DIFF_CALC_H
#define OBBY_DIFF_CALC_H

#include <math.h>
#include <stdio.h>

/**
 * Converts an EToH difficulty to a tiered difficulty.
 *
 * @param n The difficulty to convert
 * @returns The corresponding tiered difficulty
 */
double etoh_to_tier(double n);

/**
 * Converts a tiered difficulty to an EToH difficulty.
 *
 * @param n The difficulty to convert
 * @returns The corresponding EToH difficulty
 */
double tier_to_etoh(double n);

/**
 * Calculates how many times harder `a` is than `b`.
 * (EToH difficulties)
 *
 * @param a The first difficulty
 * @param b The second difficulty
 * @returns How much harder `a` is than `b`
 */
double harder_etoh(double a, double b);

/**
 * Calculates how many times harder `a` is than `b`.
 * (Tiered difficulties)
 *
 * @param a The first difficulty
 * @param b The second difficulty
 * @returns How much harder `a` is than `b`
 */
double harder_tier(double a, double b);

/**
 * Prints an EToH difficulty as a name.
 *
 * @param n The difficulty to display
 */
void print_etoh_as_name(double n);

#endif // OBBY_DIFF_CALC_H
