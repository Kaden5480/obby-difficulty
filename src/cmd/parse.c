#include "parse.h"

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

bool parse_double(char *str, double *n) {
    char *end = NULL;
    size_t str_len = strlen(str);

    if (str_len < 1) {
        return false;
    }

    *n = strtod(str, &end);

    if (str + str_len != end) {
        fprintf(stderr, "Invalid number: %s\n", str);
        return false;
    }

    return true;
}

bool parse_int(char *str, int *n) {
    char *end = NULL;
    size_t str_len = strlen(str);

    if (str_len < 1) {
        return false;
    }

    *n = strtol(str, &end, 10);

    if (str + str_len != end) {
        fprintf(stderr, "Invalid whole number: %s\n", str);
        return false;
    }

    return true;
}

bool parse_arg(int argc, char **argv, int i, char **value) {
    if (i + 1 >= argc) {
        fprintf(stderr, "Expected argument for %s\n", argv[i]);
        return false;
    }

    *value = str_trim(argv[i + 1]);
    return true;
}

bool parse_arg_double(int argc, char **argv, int i, double *value) {
    char *arg = NULL;

    if (parse_arg(argc, argv, i, &arg) == false) {
        return false;
    }

    return parse_double(arg, value);
}

bool parse_arg_int(int argc, char **argv, int i, int *value) {
    char *arg = NULL;

    if (parse_arg(argc, argv, i, &arg) == false) {
        return false;
    }

    return parse_int(arg, value);
}
