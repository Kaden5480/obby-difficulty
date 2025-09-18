#include "calc.h"

double etoh_to_tier(double n) {
    return n * log(2.0 * pow(16.0, 1.0/11.0))
        / log(2.0);
}

double tier_to_etoh(double n) {
    return log(pow(2.0, n))
        / log(2.0 * pow(16.0, 1.0/11.0));
}

double diff_etoh(double a, double b) {
    double diff = a - b;
    double base = 2.0 * pow(16.0, 1.0/11.0);

    // Difficulties in EToH don't scale nicely, so a different
    // base has to be used
    return pow(base, diff);
}

double diff_tier(double a, double b) {
    double diff = a - b;

    // Luckily tiers are easy, each difficulty is twice
    // as hard as the previous
    return pow(2.0, diff);
}

double which_etoh(double n, double t) {
    double base = 2.0 * pow(16.0, 1.0/11.0);

    return n + (log(t) / log(base));
}

double which_tier(double n, double t) {
    return n + (log(t) / log(2.0));
}

void print_etoh_as_name(double n) {
    double floored = floor(n);

    int whole = (int) floored;
    float decimal = n - floored;

    if (n < 0 || n >= 16) {
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
        case 0:
            printf(" Effortless");
            break;
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
