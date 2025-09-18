#include "display.h"

// Convert
void show_etoh_to_tier(int accuracy, double n) {
    double converted = etoh_to_tier(n);

    printf("%.*lf (EToH, ", accuracy, n);
    print_etoh_as_name(n);
    printf(") -> %.*lf (Tiered)\n", accuracy, converted);
}

void show_tier_to_etoh(int accuracy, double n) {
    double converted = tier_to_etoh(n);

    printf(
        "%.*lf (Tiered) -> %.*lf (EToH, ",
        accuracy, n,
        accuracy, converted
    );
    print_etoh_as_name(converted);
    puts(")");
}

// Diff
void show_diff_etoh(int accuracy, double a, double b) {
    double result = diff_etoh(a, b);

    printf("%.*lf (", accuracy, a);
    print_etoh_as_name(a);
    printf(
        ") is %.*lfx harder than %.*lf (",
        accuracy, result,
        accuracy, b
    );
    print_etoh_as_name(b);
    printf(")\n");
}

void show_diff_tier(int accuracy, double a, double b) {
    double result = diff_tier(a, b);

    printf(
        "%.*lf is %.*lfx harder than %.*lf\n",
        accuracy, a,
        accuracy, result,
        accuracy, b
    );
}

// Which
void show_which_etoh(int accuracy, double n, double t) {
    double result = which_etoh(n, t);

    printf("%.*lf (", accuracy, result);
    print_etoh_as_name(result);
    printf(
        ") is %.*lfx harder than %.*lf (",
        accuracy, t,
        accuracy, n
    );
    print_etoh_as_name(n);
    printf(")\n");
}

void show_which_tier(int accuracy, double n, double t) {
    double result = which_tier(n, t);

    printf(
        "%.*lf is %.*lfx harder than %.*lf\n",
        accuracy, result,
        accuracy, t,
        accuracy, n
    );
}
