#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100  // 程序中节点的最大数量

// 邻接表中每个顶点的结构体
typedef struct Vertex {
    int id;  // 顶点的唯一标识
    struct Edge *edges;  // 与该顶点相关的所有边
} Vertex;

// 邻接表中每条边的结构体
typedef struct Edge {
    struct Vertex *to_vertex;  // 边所指向的顶点
    struct Edge *next_edge;  // 指向下一条与该顶点相连的边的指针
} Edge;

// 路径中经过的所有节点的 ID 及数量的结构体
typedef struct Path {
    int length;  // 路径中经过的节点数量
    int vertices[MAX_VERTICES];  // 路径中经过的所有节点的 ID
} Path;

// 初始化邻接表中每个顶点
void initialize_vertices(Vertex *vertices, int num_vertices) {
    for (int i = 0; i < num_vertices; i++) {
        vertices[i].id = i;
        vertices[i].edges = NULL;
    }
}

// 将顶点之间的连通关系添加到邻接表中
void add_edge(Vertex *vertices, int from_vertex, int to_vertex) {
    Edge *edge = malloc(sizeof(Edge));
    edge->to_vertex = &vertices[to_vertex];
    edge->next_edge = vertices[from_vertex].edges;
    vertices[from_vertex].edges = edge;
}

// 根据起点和终点生成所有基本路径
void generate_paths(Vertex *vertices, int start_vertex, int end_vertex, Path *path, int *num_paths) {
    Vertex *vertex = &vertices[start_vertex];
    Edge *edge = vertex->edges;
    path->vertices[path->length++] = vertex->id;

    // 如果到达了终点，将当前路径保存到结果中
    if (vertex->id == end_vertex) {
        Path *new_path = malloc(sizeof(Path));
        memcpy(new_path, path, sizeof(Path));
        num_paths++;
        path->length--;
        return;
    }

    // 对于每条出边，递归地生成基本路径
    while (edge != NULL) {
        if (path->length < MAX_VERTICES) {
            generate_paths(vertices, edge->to_vertex->id, end_vertex, path, num_paths);
        }
        edge = edge->next_edge;
    }

    path->length--;
}

// 生成程序中所有的基本路径
void generate_all_paths(Vertex *vertices, int num_vertices, Path **paths, int *num_paths) {
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            if (i != j) {
                Path *path = malloc(sizeof(Path));
                path->length = 0;
                generate_paths(vertices, i, j, path, num_paths);
            }
        }
    }
}


// 主函数
void text() {
    Vertex vertices[] = {
            {0, NULL},
            {1, NULL},
            {2, NULL},
            {3, NULL},
            {4, NULL},
            {5, NULL},
            {6, NULL},
            {7, NULL}
    };

// 将顶点之间的连通关系添加到邻接表中
    add_edge(vertices, 0, 1);
    add_edge(vertices, 0, 2);
    add_edge(vertices, 1, 3);
    add_edge(vertices, 1, 4);
    add_edge(vertices, 2, 3);
    add_edge(vertices, 2, 5);
    add_edge(vertices, 3, 6);
    add_edge(vertices, 4, 6);
    add_edge(vertices, 5, 6);
    add_edge(vertices, 6, 7);

// 生成程序中所有的基本路径
    Path **paths = malloc(sizeof(Path *) * MAX_VERTICES * MAX_VERTICES);
    int num_paths = 0;
    generate_all_paths(vertices, sizeof(vertices) / sizeof(vertices[0]), paths, &num_paths);

// 打印所有生成的基本路径
    printf("共生成 %d 条基本路径：\n", num_paths);
    for (int i = 0; i < num_paths; i++) {
        printf("路径 %d：", i + 1);
        for (int j = 0; j < paths[i]->length; j++) {
            printf("%d ", paths[i]->vertices[j]);
        }
        printf("\n");
        free(paths[i]);
    }
    free(paths);

    return ;
}