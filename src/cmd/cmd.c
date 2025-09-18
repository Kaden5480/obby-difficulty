#include "cmd.h"
#include "parse.h"

// Yes, this is a bit spaghetti, but it's simple enough to think about
// and runs fast enough, so that's fine for now.

// Convert
void cmd_convert_usage(const char *program) {
    printf(
        "%s, %s\n"
        "Usage:\n"
        "  %s convert [option...] <number>\n"
        "Description:\n"
        "  Converts between EToH and tiered difficulties\n"
        "Options:\n"
        "  -h --help          Display the usage for this subcommand\n"
        "  -a --accuracy <n>  Display this many decimal places (Default: 2)\n"
        "  -e --etoh          The input is in EToH difficulty (Default)\n"
        "  -t --tier          The input is in tiered difficulty\n",
        program, VERSION, program
    );
}

void cmd_convert_parse(int argc, char **argv, CmdConvert *store) {
    const char *program = argv[0];
    char *arg = NULL;
    char *n = NULL;

    // Skip program and subcommand
    for (int i = 2; i < argc; i++) {
        arg = str_trim(argv[i]);

        if (strcmp(arg, "-h") == 0 || strcmp(arg, "--help") == 0) {
            cmd_convert_usage(program);
            exit(0);
        }
        else if (strcmp(arg, "-a") == 0 || strcmp(arg, "--accuracy") == 0) {
            if (parse_arg_int(argc, argv, i++, &(store->accuracy)) == false) {
                cmd_convert_usage(program);
                exit(1);
            }
        }
        else if (strcmp(arg, "-e") == 0 || strcmp(arg, "--etoh") == 0) {
            store->is_etoh = true;
        }
        else if (strcmp(arg, "-t") == 0 || strcmp(arg, "--tier") == 0) {
            store->is_etoh = false;
        }
        else if (n == NULL) {
            n = arg;
        }
        else {
            fprintf(stderr, "Unexpected argument: %s\n", arg);
            cmd_convert_usage(program);
            exit(1);
        }
    }

    // Check args
    if (n == NULL) {
        fprintf(stderr, "Number to convert was not provided\n");
        cmd_convert_usage(program);
        exit(1);
    }

    if (parse_double(n, &(store->number)) == false) {
        cmd_convert_usage(program);
        exit(1);
    }
}

void cmd_convert_run(int argc, char **argv) {
    CmdConvert store = {
        .accuracy = CMD_DEFAULT_ACCURACY,
        .is_etoh = CMD_DEFAULT_IS_ETOH,
        .number = 0.0,
    };

    cmd_convert_parse(argc, argv, &store);

    // Extra checks
    if (store.accuracy < 0 || store.accuracy > 16) {
        fprintf(stderr, "Accuracy must be between 0 and 16 (inclusive)\n");
        exit(1);
    }

    if (store.is_etoh == true) {
        show_etoh_to_tier(store.accuracy, store.number);
    }
    else {
        show_tier_to_etoh(store.accuracy, store.number);
    }
}

// Diff
void cmd_diff_usage(const char *program) {
    printf(
        "%s, %s\n"
        "Usage:\n"
        "  %s diff [option...] <a> <b>\n"
        "Description:\n"
        "  Calculates how much harder difficulty `a` is than difficulty `b`\n"
        "Options:\n"
        "  -h --help          Display the usage for this subcommand\n"
        "  -a --accuracy <n>  Display this many decimal places (Default: 2)\n"
        "  -e --etoh          The input is in EToH difficulty (Default)\n"
        "  -t --tier          The input is in tiered difficulty\n",
        program, VERSION, program
    );
}

void cmd_diff_parse(int argc, char **argv, CmdDiff *store) {
    const char *program = argv[0];
    char *arg = NULL;
    char *a = NULL, *b = NULL;

    // Skip program and subcommand
    for (int i = 2; i < argc; i++) {
        arg = str_trim(argv[i]);

        if (strcmp(arg, "-h") == 0 || strcmp(arg, "--help") == 0) {
            cmd_diff_usage(program);
            exit(0);
        }
        else if (strcmp(arg, "-a") == 0 || strcmp(arg, "--accuracy") == 0) {
            if (parse_arg_int(argc, argv, i++, &(store->accuracy)) == false) {
                cmd_diff_usage(program);
                exit(1);
            }
        }
        else if (strcmp(arg, "-e") == 0 || strcmp(arg, "--etoh") == 0) {
            store->is_etoh = true;
        }
        else if (strcmp(arg, "-t") == 0 || strcmp(arg, "--tier") == 0) {
            store->is_etoh = false;
        }
        else if (a == NULL) {
            a = arg;
        }
        else if (b == NULL) {
            b = arg;
        }
        else {
            fprintf(stderr, "Unexpected argument: %s\n", arg);
            cmd_diff_usage(program);
            exit(1);
        }
    }

    // Check args
    if (a == NULL || b == NULL) {
        fprintf(stderr, "Expected two numbers to compare\n");
        cmd_diff_usage(program);
        exit(1);
    }

    if (
        parse_double(a, &(store->a)) == false
        || parse_double(b, &(store->b)) == false
    ) {
        cmd_diff_usage(program);
        exit(1);
    }
}

void cmd_diff_run(int argc, char **argv) {
    CmdDiff store = {
        .accuracy = CMD_DEFAULT_ACCURACY,
        .is_etoh = CMD_DEFAULT_IS_ETOH,
        .a = 0.0,
        .b = 0.0,
    };

    cmd_diff_parse(argc, argv, &store);

    // Extra checks
    if (store.accuracy < 0 || store.accuracy > 16) {
        fprintf(stderr, "Accuracy must be between 0 and 16 (inclusive)\n");
        exit(1);
    }

    if (store.is_etoh == true) {
        show_diff_etoh(store.accuracy, store.a, store.b);
    }
    else {
        show_diff_tier(store.accuracy, store.a, store.b);
    }
}

// Which
void cmd_which_usage(const char *program) {
    printf(
        "%s, %s\n"
        "Usage:\n"
        "  %s which [option...] <n> <t>\n"
        "Description:\n"
        "  Calculates which difficulty is `t` times harder than `n`\n"
        "Options:\n"
        "  -h --help          Display the usage for this subcommand\n"
        "  -a --accuracy <n>  Display this many decimal places (Default: 2)\n"
        "  -e --etoh          The input is in EToH difficulty (Default)\n"
        "  -t --tier          The input is in tiered difficulty\n",
        program, VERSION, program
    );
}

void cmd_which_parse(int argc, char **argv, CmdWhich *store) {
    const char *program = argv[0];
    char *arg = NULL;
    char *n = NULL, *t = NULL;

    // Skip program and subcommand
    for (int i = 2; i < argc; i++) {
        arg = str_trim(argv[i]);

        if (strcmp(arg, "-h") == 0 || strcmp(arg, "--help") == 0) {
            cmd_which_usage(program);
            exit(0);
        }
        else if (strcmp(arg, "-a") == 0 || strcmp(arg, "--accuracy") == 0) {
            if (parse_arg_int(argc, argv, i++, &(store->accuracy)) == false) {
                cmd_which_usage(program);
                exit(1);
            }
        }
        else if (strcmp(arg, "-e") == 0 || strcmp(arg, "--etoh") == 0) {
            store->is_etoh = true;
        }
        else if (strcmp(arg, "-t") == 0 || strcmp(arg, "--tier") == 0) {
            store->is_etoh = false;
        }
        else if (n == NULL) {
            n = arg;
        }
        else if (t == NULL) {
            t = arg;
        }
        else {
            fprintf(stderr, "Unexpected argument: %s\n", arg);
            cmd_which_usage(program);
            exit(1);
        }
    }

    // Check args
    if (n == NULL || t == NULL) {
        fprintf(stderr, "Expected numbers `n` and `t`\n");
        cmd_which_usage(program);
        exit(1);
    }

    if (
        parse_double(n, &(store->n)) == false
        || parse_double(t, &(store->t)) == false
    ) {
        cmd_which_usage(program);
        exit(1);
    }
}

void cmd_which_run(int argc, char **argv) {
    CmdWhich store = {
        .accuracy = CMD_DEFAULT_ACCURACY,
        .is_etoh = CMD_DEFAULT_IS_ETOH,
        .n = 0.0,
        .t = 0.0,
    };

    cmd_which_parse(argc, argv, &store);

    // Extra checks
    if (store.accuracy < 0 || store.accuracy > 16) {
        fprintf(stderr, "Accuracy must be between 0 and 16 (inclusive)\n");
        exit(1);
    }

    if (store.is_etoh == true) {
        show_which_etoh(store.accuracy, store.n, store.t);
    }
    else {
        show_which_tier(store.accuracy, store.n, store.t);
    }
}

// Main
void cmd_usage(const char *program) {
    printf(
        "%s, %s\n"
        "Usage:\n"
        "  %s <subcommand>\n"
        "Subcommands:\n"
        "  help/-h/--help       Display the usage for this command\n"
        "  convert <number...>  Converts between EToH and tiered difficulties\n"
        "  diff <a> <b>         Calculates how much harder difficulty `a` is than difficulty `b`\n"
        "  which <n> <t>        Calculates which difficulty is `t` times harder than `n`\n",
        program, VERSION, program
    );
}

void cmd_run(int argc, char **argv) {
    char *subcmd = NULL;

    if (argc < 1) {
        exit(1);
    }

    if (argc == 1) {
        cmd_usage(argv[0]);
        exit(0);
    }

    subcmd = argv[1];

    if (strcmp("help", subcmd) == 0
        || strcmp("-h", subcmd) == 0
        || strcmp("--help", subcmd) == 0
    ) {
        cmd_usage(argv[0]);
        exit(0);
    }
    else if (strcmp("convert", subcmd) == 0) {
        cmd_convert_run(argc, argv);
    }
    else if (strcmp("diff", subcmd) == 0) {
        cmd_diff_run(argc, argv);
    }
    else if (strcmp("which", subcmd) == 0) {
        cmd_which_run(argc, argv);
    }
    else {
        fprintf(stderr, "Unknown subcommand: %s\n", subcmd);
        cmd_usage(argv[0]);
        exit(1);
    }
}
