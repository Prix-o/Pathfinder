#include "../inc/pathfinder.h"

int mx_retutn_min_index(t_path paths[], int checked[], int node_count) {
    int min = __INT_MAX__;
    int min_index = 0;
    bool same = false;
    for (int j = 0; j < node_count; j++)
    {
        for (int i = 0; i < node_count; i++)
        {
            if (j == checked[i])
            {
                same = true;
                break;
            }
            
        }
        
        if (paths[j].length < min && !same)
        {
            min = paths[j].length;
            min_index = j;
        }
        same = false;
        
    }
    return min_index;

}

void mx_print_result(int start, t_node arr[], t_path paths[], int node_count) {
    for (int i = start; i < node_count; i++)
    {
        t_bridge *ttt;
        ttt = paths[i].path;
        if (i != start && ttt != NULL)
        {
            
            printf("========================================\n");
            printf("Path: %s -> %s\n", arr[start].name, arr[i].name);
            printf("Route: %s ", arr[start].name);
            for (; ttt != NULL; )
            {
                printf("-> %s ", arr[ttt->node_index].name);
                ttt = ttt->next;
            }
            printf("\n");
            ttt = paths[i].path;
            if (ttt->next == NULL)
            {
                printf("Distance: %d\n", paths[i].length);
            }
            else {
                printf("Distance: %d", ttt->weight);
                ttt = ttt->next;
                for (; ttt != NULL; )
                {
                    printf(" + %d", ttt->weight);
                    ttt = ttt->next;
                }
                printf(" = %d\n",  paths[i].length);
            }

            printf("========================================\n");
        }
       
    }
    

}

void mx_dijkstra_algorithm(int start, t_node arr[], int node_count) {

    int checked[node_count];
    for (int i = 0; i < node_count; i++)
    {
        checked[i] = -1;
    }
    
    t_path paths[node_count];
    for (int i = 0; i < node_count; i++)
    {
        paths[i].length = __INT_MAX__;
        paths[i].path = NULL;
    }
    paths[start].length = 0;

    for (int i = 0; i < node_count; i++)
    {
        checked[i] = mx_retutn_min_index(paths, checked, node_count);
        

        t_bridge *temp;
        temp = arr[checked[i]].connect;
        for (; temp != NULL; )
        {

            if (temp->weight + paths[checked[i]].length < paths[temp->node_index].length)
            {
                paths[temp->node_index].length = temp->weight + paths[checked[i]].length;
                paths[temp->node_index].path = mx_listcpy(paths[temp->node_index].path, paths[checked[i]].path);
                mx_add_bridge(&(paths[temp->node_index].path), temp->weight, temp->node_index);
                
                
            }
            temp = temp->next;

        }

    }

    mx_print_result(start, arr, paths, node_count);

    

    for (int i = 0; i < node_count; i++)
    {
        mx_listdel(&(paths[i].path));
    }
  
    



    
}

