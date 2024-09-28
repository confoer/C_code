#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100 // 假设图中最多有100个顶点

// 图的邻接矩阵
int graph[MAX_VERTICES][MAX_VERTICES];

// 访问过的顶点集合
bool visited[MAX_VERTICES];

// 初始化图
void initializeGraph()
{
    int i, j;
    for (i = 0; i < MAX_VERTICES; i++)
    {
        for (j = 0; j < MAX_VERTICES; j++)
        {
            graph[i][j] = 0; // 0 表示顶点 i 和 j 之间没有边
        }
    }
}

// 添加边
void addEdge(int start, int end)
{
    graph[start][end] = 1;
    graph[end][start] = 1; // 如果是无向图
}

// 深度优先搜索
void dfs(int v)
{
    visited[v] = true;
    printf("Visited %d\n", v);

    int i;
    for (i = 0; i < MAX_VERTICES; i++)
    {
        if (graph[v][i] == 1 && !visited[i])
        {
            dfs(i);
        }
    }
}

int main()
{
    initializeGraph();
    int vertices = 5; // 假设有5个顶点

    // 添加一些边
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(2, 3);
    addEdge(3, 4);

    // 从顶点0开始DFS
    for (int i = 0; i < vertices; i++)
    {
        visited[i] = false;
    }
    dfs(0);

    return 0;
}