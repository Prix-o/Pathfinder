#include "../inc/libmx.h"

char *mx_file_to_str(const char *file) {
    if (file == NULL)
        return NULL;

    int file_in = open (file, O_RDONLY);
    if (file_in < 0)
        return NULL;
    char buf[1];
    int len = read(file_in, buf, 1);
    int size = 0;

    while(len) {
        len = read(file_in, buf, 1);
        if(len < 0) // dodala
            return NULL;
        size++;
    }

    if (size == 0) //dodatok
        return "\0";
    
    if (close(file_in) < 0) 
        return NULL;
    
    int file_in2 = open (file, O_RDONLY);
    if (file_in2 < 0)
        return NULL;

    char *s = mx_strnew(size); // ne size + 1
    for(int i = 0; i < size; i++) {
        len = read(file_in, buf, 1);
        if(len < 0) // dodala
            return NULL;
        s[i] = buf[0];
    }
    if (close(file_in) < 0) 
        return NULL;

    return s;
}


