#include "../inc/pathfinder.h"

int main(int argc, char* argv[]) {

    if (argc != 2)
    {
        error_output(1, argv[1]);
        exit(1);
    } 

    char* file = mx_file_to_str(argv[1]);

    if (file == NULL)
    {
        error_output(2, argv[1]);
        exit(1);
    }

    if (*file == '\0')
    {
        error_output(3, argv[1]);
        exit(1);
    } 

    char** lines = mx_strsplit(file, '\n');

    if (mx_atoi(lines[0]) == 0)
    {
        error_output(4, "");
        exit(1);
    }

    int node_count = mx_atoi(lines[0]);
 
    t_node arr[node_count];
    for (int i = 0; i < node_count; i++)
    {
        arr[i].name = "";
        arr[i].index = -1;
        arr[i].connect = NULL;
    }

    mx_create_graph(arr, lines, node_count);

    for (int i = 0; i < node_count-1; i++)
    {
        mx_dijkstra_algorithm(i, arr, node_count);
    }

    for (int i = 0; i < node_count; i++)
    {
        mx_listdel(&(arr[i].connect));
    }
    
    
    free(file);
 
    
    
    
    

    

    
    

}


