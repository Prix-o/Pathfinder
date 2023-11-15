#include "../inc/pathfinder.h"


void error_output(int err_case, char* err_cause){
    switch (err_case)
    {
    case 1:
        mx_printerr("usage: ./pathfinder [filename]\n");
        break;

    case 2:
        mx_printerr("file ");
        mx_printerr(err_cause);
        mx_printerr(" does not exist\n");
        break;

    case 3:
        mx_printerr("file ");
        mx_printerr(err_cause);
        mx_printerr(" is empty\n");
        break;
       
    case 4:
        mx_printerr("error: line 1 is not valid\n");
        break;
       
    case 5:
        mx_printerr("error: line ");
        mx_printerr(err_cause);
        mx_printerr(" is not valid\n");
        break;
       
    case 6:
        mx_printerr("error: invalid number of islands\n");
        break;
       
    case 7:
        mx_printerr("error: duplicate bridges\n");
        break;
       
    case 8:
        mx_printerr("error: sum of bridges lengths is too big\n");
        break;
    
    default:
        break;
    }
}

