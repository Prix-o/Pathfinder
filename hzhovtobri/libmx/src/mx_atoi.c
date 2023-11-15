#include "../inc/libmx.h"

int mx_atoi(const char *str) {
    int num = 0;
    int mult = 1;
    for (int i = mx_strlen(str) - 1; i >= 0; i--) {
        if((str[i] < '0' || str[i] > '9') && str[i] != '-')
            return 0;
        if (str[i] == '-' && i == 0) {
            num *= -1;
            return num;
        }
        else if (str[i] == '-' && i != 0) {
            return 0;
        }
        num += (str[i] - 48) * mult;
        mult *= 10;
    }
    return num;
}


