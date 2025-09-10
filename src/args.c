#include "args.h"

void Args_show_usage(Args args) {
    printf(
        "%s, v%s\n"
        "Usage:\n"
        "  %s [option...] <number...>\n"
        "Options:\n"
        "  -h --help              Display usage\n"
        "  -H --harder <a> <b>    How much harder difficulty `a` is than `b`\n"
        "  -e --etoh              The input is an EToH difficulty (default)\n"
        "  -t --tier              The input is a tiered obby difficulty\n",
        args.argv[0], VERSION, args.argv[0]
    );
}

void Args_from(Args *args, int argc, char *argv[]) {
    char *arg = NULL;

    // Initialize
    args->argc = argc;
    args->argv = argv;
    args->a = NULL;
    args->b = NULL;
    args->harder = false;
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
        else if (strcmp(arg, "-H") == 0 || strcmp(arg, "--harder") == 0) {
            args->harder = true;
        }
        else if (strcmp(arg, "-e") == 0) {
            args->is_etoh = true;
        }
        else if (strcmp(arg, "-t") == 0) {
            args->is_etoh = false;
        }
        else if (args->a == NULL) {
            args->a = arg;
        }
        else if (args->harder == true && args->b == NULL) {
            args->b = arg;
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

    if (args->harder == true
        && (args->a == NULL || args->b == NULL)
    ) {
        fprintf(stderr, "Expected two input difficulties to compare\n");
        Args_show_usage(*args);
        exit(1);
    }
}

