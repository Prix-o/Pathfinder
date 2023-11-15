#include "../inc/libmx.h"

bool mx_isalpha(int c) {
    if (c > 64 && c < 91) {
    return true;
    }

    if (c > 96 && c < 123) {
    return true;
    }

    return false;
}



