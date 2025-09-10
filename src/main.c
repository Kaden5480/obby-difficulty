#include "lib/display.h"

int main(int argc, char *argv[]) {
    Args args = {0};

    Args_from(&args, argc, argv);
    show_output(args);
}
