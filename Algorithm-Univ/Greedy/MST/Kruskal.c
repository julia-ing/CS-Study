#include <stdio.h>
#include <stdlib.h>

typedef struct Edge
{
    char v1, v2;  // 간선으로 이어지는 정점 2개
    int weight;  // 가중치
    struct Edge* next;  // 다음 연결된 간선
}Edge;

typedef struct IncidentEdge  // 인접 간선 
{
    char aName;  // adjacent name
    Edge* e;
    struct IncidentEdge* next;
}IncidentEdge;

typedef struct Vertex
{
    char vName;  // 정점 이름
    IncidentEdge* iHead;  // 인접 간선 
    struct Vertex* next;
}Vertex;

typedef struct
{
    Vertex* vHead;
    Edge* eHead;
    int eCount, vCount;  // 간선, 정점의 개수
}Graph;

void init(Graph* G)
{
    G->vHead = NULL;
    G->eHead = NULL;
    G->vCount = G->eCount = 0;
}

void makeVertex(Graph* G, char vName)
{
	Vertex* v = (Vertex*)malloc(sizeof(Vertex));
	v->vName = vName;
	v->iHead = NULL;
	v->next = NULL;
	G->vCount++;
	
	Vertex* q = G->vHead;  // 그래프의 헤드가 가리키는 정점을 q라고 지정
	if (q == NULL)  // 그래프가 비어있으면 
		G->vHead = v;  // 헤드가 정점 v가 됨 
	else  // 그래프가 비어있지 않으면 
	{
		while (q->next != NULL)  // 그래프에 원소가 있는 동안
			q = q->next;  // 옆으로 진행하다가 
		q->next = v;  // null을 만나면 빠져나와서 v를 q의 next 정점으로 지정
	}
}

void makeIncidentEdge(Vertex* v, char aName, Edge* e)  // 인접 간선 만드는 함수, v와 aName 정점들이 연결될 것
{
    IncidentEdge* p = (IncidentEdge*)malloc(sizeof(IncidentEdge));  // v와 aName을 연결하게 될 인접 간선
    p->aName = aName;
    p->e = e;
    p->next = NULL;
    IncidentEdge* q = v->iHead;  // 정점 v가 가리키는 헤드를 인접 간선 q에 대입
    if (q == NULL)  // v의 인접 간선이 없으면 
		v->iHead = p;  // p를 헤드로 만들어주고
	else  // 있으면
	{
		while (q->next != NULL)
			q = q->next;
		q->next = p;  // null을 만나면 반복문을 빠져나와 q의 next에 인접 간선 p를 대입
	}
}

Vertex* findVertex(Graph* G, char vName)
{
	Vertex* v = G->vHead;
	while (v->vName != vName)
		v = v->next;
	return v;
}

void insertEdge(Graph* G, char v1, char v2, int w)
{
    Edge* e = (Edge*)malloc(sizeof(Edge));  // 새로 만들어질 간선
    e->weight = w;
    e->v1 = v1;
    e->v2 = v2;
    e->next = NULL;
    G->eCount++;
    
    Edge* q = G->eHead;  // 그래프의 간선 헤드
	if (q == NULL)  // 간선이 없는 상태면
		G->eHead = e;  // e가 헤드가 된다
	else  // 간선이 있는 상태면 
	{
		while (q->next != NULL)
			q = q->next;  // null을 만날 때까지 next로 가다가
		q->next = e;  // 간선 q 가 e를 가리키도록 함
	}
    Vertex* v = findVertex(G, v1);  // v1의 이름으로 정점의 위치를 찾고
    makeIncidentEdge(v, v2, e);  // v2와 인접 간선을 만든다
    v = findVertex(G, v2);  // 반대 작업도 동일하게
    makeIncidentEdge(v, v1, e);
}

void print(Graph* G)
{
	Vertex* p = G->vHead;
	IncidentEdge* q;
	for (; p != NULL; p = p->next)
	{
		printf("[%c] : ", p->vName);
		for (q = p->iHead; q != NULL; q = q->next)
			printf("[%c, %d] ", q->aName, q->e->weight);
		printf("\n");
	}
	printf("\n");
}

void incSort(Graph* G, Edge* e[])  // 가중치 오름차순으로 정렬시키는 함수
{
    int i, least;
    Edge* p = G->eHead;  // 그래프의 간선 헤드를 p에 대입
    for(i = 0; i < G->eCount; i++)
    {
        e[i] = p;  // 하나씩 간선 배열에 대입
        p = p->next;
    }
    
	for (i = 0; i < G->eCount - 1; i++)
	{
		least = i;  // 최소를 i로 초기화
		for (int j = i + 1; j < G->eCount; j++)  // i번째 다음부터
			if (e[j]->weight < e[least]->weight)  // j번째 가중치가 least번째 가중치보다 작으면
				least = j;  // 최소를 j로 업데이트
		
		p = e[least];  
		e[least] = e[i];  // least번째 있는 원소와 i번째 있는 원소를 교환
		e[i] = p;
        // 예를 들어 3 8 2 1 5 에서 i=0 일 경우 3과 1을 swap
	}
    
    for(i = 0; i < G->eCount; i++)
        printf("[%c%c(%d)] ", e[i]->v1, e[i]->v2, e[i]->weight);
	printf("\n\n");
}

int vFind(int v[], int vNum) {  // 정점의 부모를 찾는 함수
    if(v[vNum] == -1)  // 정점 배열 중 vNum번째 정점의 부모가 없으면, 즉 인접 간선 중 아직 선택된 간선이 없으면 
        return vNum;  // 해당 인덱스 반환
        
    while(v[vNum] != -1)  // 부모가 있으면
        vNum = v[vNum];  // 최종 root를 찾는다
        
    return vNum;
}

void vUnion(int v[], int vNum1, int vNum2) {
    int r1 = vFind(v, vNum1);
    int r2 = vFind(v, vNum2);  // 부모를 찾고

    if(r1 != r2)  // 부모가 다르면, 즉 사이클을 만들지 않으면
        v[r2] = r1;  // v2의 부모를 업데이트 (v1과 v2가 MST 에 선택된 간선이라는 표시)
}

void kruskal(Graph* G, Edge* e[], int v[]) {
    int eCnt = 0, i = 0;
    int vNum1, vNum2;  // union find에 사용될 변수
    Edge* p;
    
    while(eCnt < G->vCount - 1) {  // 간선 수의 - 1 이 되면 MST 완선
        p = e[i];  // 간선 선택
        
        vNum1 = vFind(v, p->v1 - 97);  // ascii 코드를 고려해 97 빼줌 (문자 -> 숫자)
        vNum2 = vFind(v, p->v2 - 97);  // 부모를 찾고
        
        if(vNum1 != vNum2) {  // different parent 인 경우
            printf("%d. [%c%c (%d)]\n", eCnt+1, p->v1, p->v2, p->weight);  // 최종 그래프에 추가
            eCnt++;
            vUnion(v, vNum1, vNum2);  // union 시켜줌
        }
        i++;
    }
}

int main()
{
    Graph G;
    init(&G);
    
    makeVertex(&G, 'a'); makeVertex(&G, 'b'); makeVertex(&G, 'c'); 
    makeVertex(&G, 'd'); makeVertex(&G, 'e'); makeVertex(&G, 'f');
    
    insertEdge(&G, 'a', 'b', 8); insertEdge(&G, 'a', 'd', 2);
    insertEdge(&G, 'a', 'e', 4); insertEdge(&G, 'b', 'c', 1);
    insertEdge(&G, 'b', 'd', 4); insertEdge(&G, 'b', 'f', 2);
    insertEdge(&G, 'c', 'f', 1); insertEdge(&G, 'd', 'e', 3);
    insertEdge(&G, 'd', 'f', 7); insertEdge(&G, 'e', 'f', 9);   
    
    print(&G);
    
    Edge* e[20];
    incSort(&G, e);
    
    int v[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    kruskal(&G, e, v);
    
    return 0;
}
