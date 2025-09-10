#include "args.h"
#include "calc.h"

int main(int argc, char *argv[]) {
    double result, a = 0.0, b = 0.0;
    Args args = {0};

    Args_from(&args, argc, argv);

    if (args.a != NULL) {
        a = strtod(args.a, NULL);
    }

    if (args.b != NULL) {
        b = strtod(args.b, NULL);
    }

    if (args.harder == true) {
        if (args.is_etoh == true) {
            result = harder_etoh(a, b);
            printf("%.2lf (", a);
            print_etoh_as_name(a);
            printf(") is %.2lfx harder than %.2lf (", result, b);
            print_etoh_as_name(b);
            printf(")\n");
        }
        else {
            result = harder_tier(a, b);
            printf("%.2lf is %.2lfx harder than %.2lf\n", a, result, b);
        }

        return 0;
    }

    if (args.is_etoh == true) {
        result = etoh_to_tier(a);
        printf("%.2lf (EToH, ", a);
        print_etoh_as_name(a);
        printf(") -> %.2lf (Tiered)\n", result);
    }
    else {
        result = tier_to_etoh(a);
        printf("%.2lf (Tiered) -> %.2lf (EToH, ", a, result);
        print_etoh_as_name(result);
        puts(")");
    }
}
