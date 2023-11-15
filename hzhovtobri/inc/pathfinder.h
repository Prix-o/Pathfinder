#ifndef PATHFINDER_H
#define PATHFINDER_H




#include "libmx.h"

typedef struct s_bridge {
    int weight;
    int node_index;
    struct s_bridge* next;

} t_bridge;

typedef struct s_node {

    char* name;
    int index;
    struct s_bridge* connect;
    

} t_node;

typedef struct s_path {

    int length;
    struct s_bridge* path;
    

} t_path;

void error_output(int err_case, char* err_cause);
t_bridge* mx_create_bridge(int weight, int index);
void mx_add_bridge (t_bridge** connection, int weight, int index);
void mx_check_name(char* name, int line);
void mx_create_graph(t_node arr[], char** lines, int node_count);
int mx_retutn_min_index(t_path paths[], int checked[], int node_count);
void mx_listdel(t_bridge **head);
t_bridge *mx_listcpy(t_bridge *dst, t_bridge *src);
void mx_dijkstra_algorithm(int start, t_node arr[], int node_count);
void mx_print_result(int start, t_node arr[], t_path paths[], int node_count);
#endif

