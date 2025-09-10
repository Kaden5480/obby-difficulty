#include "display.h"

void show_harder_etoh(Args args, double a, double b) {
    double result = harder_etoh(a, b);
    (void) args;

    printf("%.2lf (", a);
    print_etoh_as_name(a);
    printf(") is %.2lfx harder than %.2lf (", result, b);
    print_etoh_as_name(b);
    printf(")\n");
}

void show_harder_tier(Args args, double a, double b) {
    double result = harder_tier(a, b);
    (void) args;

    printf("%.2lf is %.2lfx harder than %.2lf\n", a, result, b);
}

void show_etoh_to_tier(Args args, double n) {
    double converted = etoh_to_tier(n);
    (void) args;

    printf("%.2lf (EToH, ", n);
    print_etoh_as_name(n);
    printf(") -> %.2lf (Tiered)\n", converted);
}

void show_tier_to_etoh(Args args, double n) {
    double converted = tier_to_etoh(n);
    (void) args;

    printf("%.2lf (Tiered) -> %.2lf (EToH, ", n, converted);
    print_etoh_as_name(converted);
    puts(")");
}

void show_output(Args args) {
    double a = 0.0, b = 0.0;

    if (args.a != NULL) {
        a = strtod(args.a, NULL);
    }

    if (args.b != NULL) {
        b = strtod(args.b, NULL);
    }

    if (args.harder == true) {
        if (args.is_etoh == true) {
            show_harder_etoh(args, a, b);
        }
        else {
            show_harder_tier(args, a, b);
        }
        return;
    }

    if (args.is_etoh == true) {
        show_etoh_to_tier(args, a);
    }
    else {
        show_tier_to_etoh(args, a);
    }
}
