// 백준 네트워크 문제 c언어 연습용.. 

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define INF 10000
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

int parent[MAX];

struct Edge {
    int start, end, weight;
};

typedef struct Graph {
    int edgeCnt;
    struct Edge edges[2 * MAX];
}Graph;

int partition(struct Edge edges[], int left, int right) {
    struct Edge pivot, temp;
    int low, high;
    
    pivot.weight = edges[left].weight;
    low = left; high = right + 1;
    
    do {
        do
            low++;
        while (low <= right && edges[low].weight < pivot.weight); 
        
        do  
            high--;
        while (high >= left && edges[high].weight > pivot.weight);  
        
        if(low < high)
            SWAP(edges[low], edges[high], temp); 
    
    } while (low < high); 
    
    SWAP(edges[left], edges[high], temp); 
    return high; 
}

void quickSort(struct Edge edges[], int left, int right) {
    if(left < right)
    {
        int p = partition(edges, left, right);
        quickSort(edges, left, p - 1);
        quickSort(edges, p + 1, right);
    }
}

void set_init(int n) {
    for(int i = 0; i < n ; i++)
        parent[i] = -1;
}

void graph_init(Graph* g) {
    g->edgeCnt = 0;
    for(int i = 0; i < 2 * MAX; i++) {
        g->edges[i].start = 0;
        g->edges[i].end = 0;
        g->edges[i].weight = INF;
    }
}

int set_find(int curr) {
    if(parent[curr] == -1) return curr;
    while(parent[curr] != -1) curr = parent[curr];
    return curr;
}

void set_union(int a, int b) {
    int root1 = set_find(a);
    int root2 = set_find(b);
    if(root1 != root2) parent[root2] = root1;
}

void insert_edge(Graph* g, int start, int end, int weight) {
    g->edges[g->edgeCnt].start = start;
    g->edges[g->edgeCnt].end = end;
    g->edges[g->edgeCnt].weight = weight;
    g->edgeCnt++;
}

int kruskal(Graph* g) {
    int edge_accpted = 0;
    int uset, vset;
    struct Edge e;
    
    int result;
    
    set_init(g->edgeCnt);
    quickSort(g->edges, 0, g->edgeCnt);
    
    for(int i = 0; i < g->edgeCnt; i++)
        printf("%2d - %2d: %2d\n", g->edges[i].start, g->edges[i].end, g->edges[i].weight);
    
    int i = 0;
    while(edge_accpted < (g->edgeCnt - 1)) {
        e = g->edges[i];
        uset = set_find(e.start);
        vset = set_find(e.end);
        if(uset != vset) {
            printf("Edge (%d, %d) %d\n", e.start, e.end, e.weight);
            edge_accpted++;
            set_union(uset, vset);
            result += e.weight;
        }
        i++;
    }
    return result;
}

int main()
{
    int n = 6, m = 9;
    Graph* g = (Graph*)malloc(sizeof(Graph));
    graph_init(g);
    
    int start, end, weight;
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &start, &end, &weight);
        insert_edge(g, start, end, weight);
    }
    
    int result = kruskal(g);
    printf("\n%d\n", result);
    free(g);

    return 0;
}
