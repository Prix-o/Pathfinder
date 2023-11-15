#include "../inc/pathfinder.h"

t_bridge* mx_create_bridge(int weight, int index) {
    t_bridge *new_bridge = malloc(sizeof(t_bridge));
    new_bridge->node_index = index;
    new_bridge->weight = weight;
    new_bridge->next = NULL;
    return new_bridge;
}

void mx_add_bridge (t_bridge** connection, int weight, int index) {
    t_bridge *new_bridge = mx_create_bridge(weight, index);

    if (*connection == NULL) {
        *connection = new_bridge;
        return;
    }
    t_bridge *temp = *connection;
        for (; temp->next != NULL; )
        {
            if (temp->next->node_index == index)
            {
                error_output(7, "");
                exit(1);
            }
            
            temp = temp->next;
        }
        temp->next = new_bridge;

}

void mx_listdel(t_bridge **head) {

    t_bridge *t;
    if(*head == NULL || head == NULL){
        return;
    }

   
    while (*head != NULL) {

        t = *head;
        if (t->next == NULL) {
            free(t);
            *head = NULL;
            break;
        }
        while (t->next->next != NULL) {
            t = t->next;
        }
        free(t->next);
        t->next = NULL;
    
    }
    

}

t_bridge *mx_listcpy(t_bridge *dst, t_bridge *src) {

    if (dst != NULL)
    {
        mx_listdel(&dst);
    }
    t_bridge *temp = src;
    for (; temp != NULL; )
    {
        mx_add_bridge(&(dst), temp->weight, temp->node_index);
        temp = temp->next;
    }
    return dst;

    

}

