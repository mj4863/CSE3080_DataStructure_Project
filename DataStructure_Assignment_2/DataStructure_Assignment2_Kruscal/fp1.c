#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Edge {
    int u, v, weight;
};

struct Graph {
    int V, E;
    struct Edge* edges;
};

struct disjoint_set_tree {
    int* parent;
    int* rank;
};

struct min_heap_Node {
    int u, v, weight;
};

struct min_heap {
    int size;
    int capacity;
    struct min_heap_Node* array;
};

struct Graph* create_graph(int V, int E) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = malloc(E * sizeof(struct Edge));

    return graph;
}

struct disjoint_set_tree* create_disjoint_set_tree(int V) {
    struct disjoint_set_tree* dst = malloc(sizeof(struct disjoint_set_tree));
    dst->parent = malloc(V * sizeof(int));
    dst->rank = malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        dst->parent[i] = i;
        dst->rank[i] = 0;
    }

    return dst;
}

int find_root(struct disjoint_set_tree* dst, int x) {
    if (dst->parent[x] != x)
        dst->parent[x] = find_root(dst, dst->parent[x]);

    return dst->parent[x];
}

void union_set(struct disjoint_set_tree* dst, int x, int y) {
    int rootX = find_root(dst, x);
    int rootY = find_root(dst, y);
    if (rootX != rootY) {
        if (dst->rank[rootX] < dst->rank[rootY])
            dst->parent[rootX] = rootY;
        else if (dst->rank[rootX] > dst->rank[rootY])
            dst->parent[rootY] = rootX;
        else {
            dst->parent[rootY] = rootX;
            dst->rank[rootX]++;
        }
    }
}

int compare_edge(const void* x, const void* y) {
    return ((struct Edge*)x)->weight - ((struct Edge*)y)->weight;
}

void Kruskal(struct Graph* graph) {
    clock_t start_time = clock();

    int V = graph->V;
    struct Edge* result = malloc((V - 1) * sizeof(struct Edge));
    int e = 0, i = 0, total_cost = 0;
    qsort(graph->edges, graph->E, sizeof(struct Edge), compare_edge);
    struct disjoint_set_tree* dst = create_disjoint_set_tree(V);

    while (e < V - 1 && i < graph->E) {
        struct Edge next_edge = graph->edges[i++];
        int x = find_root(dst, next_edge.u);
        int y = find_root(dst, next_edge.v);
        if (x != y) {
            result[e++] = next_edge;
            union_set(dst, x, y);
            total_cost += next_edge.weight;
        }
    }

    FILE* outputFile = fopen("fp1_result.txt", "w");
    for (i = 0; i < e; i++) {
        fprintf(outputFile, "%d %d %d\n", result[i].u, result[i].v, result[i].weight);
    }
    fprintf(outputFile, "%d\n", total_cost);
    fprintf(outputFile, "%s\n", e == V - 1 ? "CONNECTED" : "DISCONNECTED");
    
    clock_t finish_time = clock();
    double running_time = (double)(finish_time - start_time) / CLOCKS_PER_SEC;

    printf("output written to fp1_result.txt.\n");
    printf("running time: %.6lf seconds\n", running_time);
    
    free(result);
    fclose(outputFile);
}

int main(int argc, char* argv[]) {
    
    if (argc != 2) {
        printf("usage: ./fp1 input_filename\n");
        exit(1);
    }

    FILE* inputFile = fopen(argv[1], "r");

    if (inputFile == NULL) {
        printf("The input file does not exist.\n");
        return 1;
    }

    int vertex_num, edge_num;
    fscanf(inputFile, "%d %d", &vertex_num, &edge_num);
    struct Graph* graph = create_graph(vertex_num, edge_num);

    for (int i = 0; i < edge_num; i++) {
        fscanf(inputFile, "%d %d %d", &graph->edges[i].u, &graph->edges[i].v, &graph->edges[i].weight);
    }
    fclose(inputFile);

    Kruskal(graph);

    free(graph->edges);
    free(graph);

    return 0;
}