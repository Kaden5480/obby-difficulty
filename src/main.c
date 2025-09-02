#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERSION "0.1.0"

void show_usage(char *program) {
    printf(
        "%s, v%s\n"
        "Usage:\n"
        "  %s [option] <number>\n"
        "Options:\n"
        "  -h --help      Display usage\n"
        "  -e             Convert to an EToH difficulty (default)\n"
        "  -t             Convert to a tiered obby difficulty\n",
        program, VERSION, program
    );
}

typedef struct Args {
    char *value;
    bool to_etoh;
} Args;

void Args_from(Args *args, int argc, char *argv[]) {
    char *arg = NULL;

    // Ignore first argument (program name)
    for (int i = 1; i < argc; i++) {
        arg = argv[i];

        if (strcmp(arg, "-h") == 0 || strcmp(arg, "--help") == 0) {
            show_usage(argv[0]);
            exit(0);
        }
        else if (strcmp(arg, "-e") == 0) {
            args->to_etoh = true;
        }
        else if (strcmp(arg, "-t") == 0) {
            args->to_etoh = false;
        }
        else if (args->value == NULL) {
            args->value = arg;
        }
        else {
            fprintf(stderr, "Unexpected input: %s\n", arg);
            show_usage(argv[0]);
            exit(1);
        }
    }
}

void print_diff_as_name(double n) {
    double floored = floor(n);

    int whole = (int) floored;
    float decimal = n - floored;

    if (n < 1 || n >= 16) {
        printf("N/A");
        return;
    }

    // Process decimal part
    if (decimal == 0) {
        printf("Baseline");
    }
    else if (decimal >= 0.01 && decimal <= 0.11) {
        printf("Bottom");
    }
    else if (decimal > 0.11 && decimal <= 0.22) {
        printf("Bottom-Low");
    }
    else if (decimal > 0.22 && decimal <= 0.33) {
        printf("Low");
    }
    else if (decimal > 0.33 && decimal <= 0.44) {
        printf("Low-Mid");
    }
    else if (decimal > 0.44 && decimal <= 0.55) {
        printf("Mid");
    }
    else if (decimal > 0.55 && decimal <= 0.66) {
        printf("Mid-High");
    }
    else if (decimal > 0.66 && decimal <= 0.77)  {
        printf("High");
    }
    else if (decimal > 0.77 && decimal <= 0.88) {
        printf("High-Peak");
    }
    else if (decimal > 0.88) {
        printf("Peak");
    }
    else {
        printf("?");
    }

    // Process whole part
    switch (whole) {
        case 1:
            printf(" Easy");
            break;
        case 2:
            printf(" Medium");
            break;
        case 3:
            printf(" Hard");
            break;
        case 4:
            printf(" Difficult");
            break;
        case 5:
            printf(" Challenging");
            break;
        case 6:
            printf(" Intense");
            break;
        case 7:
            printf(" Remorseless");
            break;
        case 8:
            printf(" Insane");
            break;
        case 9:
            printf(" Extreme");
            break;
        case 10:
            printf(" Terrifying");
            break;
        case 11:
            printf(" Catastrophic");
            break;
        case 12:
            printf(" Horrific");
            break;
        case 13:
            printf(" Unreal");
            break;
        case 14:
            printf(" Nil");
            break;
        case 15:
            printf(" Error");
            break;
    }
}

void diff_to_etoh(double diff) {
    double converted = log(pow(2.0, diff)) / log(2.0 * pow(16.0, 1.0/11.0));

    printf("%.2lf (Tiered) -> %.2lf (EToH, ", diff, converted);
    print_diff_as_name(converted);
    puts(")");
}

void diff_to_tier(double diff) {
    double converted = (diff * log(2.0 * pow(16.0, 1.0/11.0))) / log(2.0);

    printf("%.2lf (EToH, ", diff);
    print_diff_as_name(diff);
    printf(") -> %.2lf (Tiered)\n", converted);
}

int main(int argc, char *argv[]) {
    double diff = 0;
    Args args = {
        .value = NULL,
        .to_etoh = true
    };

    if (argc < 1) {
        return 1;
    }

    if (argc == 1) {
        show_usage(argv[0]);
        return 0;
    }

    Args_from(&args, argc, argv);

    diff = strtod(args.value, NULL);

    if (args.to_etoh == true) {
        diff_to_etoh(diff);
    }
    else {
        diff_to_tier(diff);
    }
}
