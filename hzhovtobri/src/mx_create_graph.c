#include "../inc/pathfinder.h"

void mx_check_name(char* name, int line) {

    if (name[0] == '\0')
    {
        error_output(5, mx_itoa(line));
        exit(1);
    }
    

    for (int i = 0; name[i] != '\0'; i++)
    {
        if (!mx_isalpha(name[i]))
        {
            error_output(5, mx_itoa(line));
            exit(1);
        }
        
    }
    


}

void mx_create_graph(t_node arr[], char** lines, int node_count) {
    int free_index = 0;
    int index1 = 0;
    int index2 = 0;
    int dash = 0;
    int comma = 0;
    long int sum = 0;
   
    for (int i = 1; lines[i] != NULL; i++)
    {
        dash = mx_get_char_index(lines[i], '-');
        comma = mx_get_char_index(lines[i], ',');
        char* name1 = mx_strndup(lines[i], dash);
        char* name2 = mx_strndup(mx_strchr(lines[i], '-')+1, comma-dash-1);
        int weight = mx_atoi(mx_strchr(lines[i], ',')+1);
        if (weight <= 0)
        {
            error_output(5, mx_itoa(i+1));
            exit(1);
        }
        
        mx_check_name(name1, i+1);
        mx_check_name(name2, i+1);

        if (mx_strcmp(name1, name2) == 0)
        {
            error_output(5, mx_itoa(i+1));
            exit(1);
        }

        for (int j = 0; j < node_count; j++)
        {
            if (mx_strcmp(name1, arr[j].name) == 0)
            {
                index1 = j;
                break;
            }
            if (j == node_count-1)
            {
                if (free_index == node_count)
                {
                    error_output(6, "");
                    exit(1);
                }
                arr[free_index].name = mx_strdup(name1);
                arr[free_index].index = free_index;
            
                index1 = free_index;
                free_index++;
            }
            
        }

        for (int j = 0; j < node_count; j++)
        {
            if (mx_strcmp(name2, arr[j].name) == 0)
            {
                index2 = j;
                break;
            }
            if (j == node_count-1)
            {
                if (free_index == node_count)
                {
                    error_output(6, "");
                    exit(1);
                }
                
                arr[free_index].name = mx_strdup(name2);
                arr[free_index].index = free_index;
                index2 = free_index;
                free_index++;
            }
            
        }

        mx_add_bridge(&(arr[index1].connect), weight, index2);
        mx_add_bridge(&(arr[index2].connect), weight, index1);
        sum += weight;
        
        free(name1);
        free(name2); 
    }

    if (sum > 2147483647)
    {
        error_output(8, "");
        exit(1);
    }
    
}
