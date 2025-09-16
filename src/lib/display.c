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

// Harder
void show_harder_etoh(int accuracy, double a, double b) {
    double result = harder_etoh(a, b);

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

void show_harder_tier(int accuracy, double a, double b) {
    double result = harder_tier(a, b);

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

void show_output(Args args) {
    int accuracy = 2;
    double a = 0.0, b = 0.0;

    if (args.accuracy != NULL) {
        accuracy = atoi(args.accuracy);

        if (accuracy < 0 || accuracy > 16) {
            fprintf(stderr, "Accuracy must be between 0 and 16 (inclusive)\n");
            Args_show_usage(args);
            exit(1);
        }
    }

    if (args.a != NULL) {
        a = strtod(args.a, NULL);
    }

    if (args.b != NULL) {
        b = strtod(args.b, NULL);
    }

    switch (args.mode) {
        case MODE_CONVERT: {
            if (args.is_etoh == true) {
                show_etoh_to_tier(accuracy, a);
            }
            else {
                show_tier_to_etoh(accuracy, a);
            }
        } break;
        case MODE_HARDER: {
            if (args.is_etoh == true) {
                show_harder_etoh(accuracy, a, b);
            }
            else {
                show_harder_tier(accuracy, a, b);
            }
        } break;
        case MODE_WHICH: {
            if (args.is_etoh == true) {
                show_which_etoh(accuracy, a, b);
            }
            else {
                show_which_tier(accuracy, a, b);
            }
        } break;
        default: {
            fprintf(stderr, "Invalid mode: %d\n", args.mode);
            exit(1);
        } break;
    }
}
