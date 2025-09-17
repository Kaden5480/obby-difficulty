#include "args.h"

char *str_trim(char *str) {
    char *end = str + strlen(str) - 1;

    // Beginning
    while (*str != '\0' && isspace(*str) != 0) {
        str++;
    }

    // End
    while (end >= str && isspace(*end) != 0) {
        *end = '\0';
        end--;
    }

    return str;
}

void Args_show_usage(Args args) {
    printf(
        "%s, v%s\n"
        "Usage:\n"
        "  %s [option...] <number...>\n"
        "Options:\n"
        "  -h --help              Display usage\n"
        "  -e --etoh              The input is an EToH difficulty (default)\n"
        "  -t --tier              The input is a tiered obby difficulty\n"
        "  -a --accuracy <number> The number of decimal places to display\n"
        "  -H --harder <a> <b>    How much harder difficulty `a` is than `b`\n"
        "  -w --which <n> <t>     Which difficulty is `t` times harder than `n`\n",
        args.argv[0], VERSION, args.argv[0]
    );
}

void Args_from(Args *args, int argc, char *argv[]) {
    char *arg = NULL;

    // Initialize
    args->argc = argc;
    args->argv = argv;
    args->accuracy = NULL;
    args->a = NULL;
    args->b = NULL;
    args->mode = MODE_CONVERT;
    args->is_etoh = true;

    // If not enough arguments, just quit
    if (argc < 1) {
        exit(1);
    }

    // If no arguments, just display help
    if (argc == 1) {
        Args_show_usage(*args);
        exit(0);
    }

    // Ignore first argument (program name)
    for (int i = 1; i < argc; i++) {
        arg = argv[i];

        if (strcmp(arg, "-h") == 0 || strcmp(arg, "--help") == 0) {
            Args_show_usage(*args);
            exit(0);
        }
        else if (strcmp(arg, "-e") == 0) {
            args->is_etoh = true;
        }
        else if (strcmp(arg, "-t") == 0) {
            args->is_etoh = false;
        }
        else if (strcmp(arg, "-a") == 0 || strcmp(arg, "--accuracy") == 0) {
            if (i + 1 >= argc) {
                fprintf(stderr, "Expected an accuracy to be provided\n");
                Args_show_usage(*args);
                exit(1);
            }

            i++;
            arg = argv[i];
            args->accuracy = str_trim(arg);
        }
        else if (strcmp(arg, "-H") == 0 || strcmp(arg, "--harder") == 0) {
            args->mode = MODE_HARDER;
        }
        else if (strcmp(arg, "-w") == 0 || strcmp(arg, "--which") == 0) {
            args->mode = MODE_WHICH;
        }
        else if (args->a == NULL) {
            args->a = str_trim(arg);
        }
        else if (args->mode != MODE_CONVERT && args->b == NULL) {
            args->b = str_trim(arg);
        }
        else {
            fprintf(stderr, "Unexpected input: %s\n", arg);
            Args_show_usage(*args);
            exit(1);
        }
    }

    if (args->a == NULL) {
        fprintf(stderr, "Expected input difficulty to convert\n");
        Args_show_usage(*args);
        exit(1);
    }

    if (args->a == NULL || args->b == NULL) {
        if (args->mode == MODE_HARDER) {
            fprintf(stderr, "Expected two input difficulties to compare\n");
            Args_show_usage(*args);
            exit(1);
        }

        if (args->mode == MODE_WHICH) {
            fprintf(stderr, "Expected a difficulty and a number\n");
            Args_show_usage(*args);
            exit(1);
        }

    }
}

