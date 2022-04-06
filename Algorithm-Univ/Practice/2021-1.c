#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(a,b) {int t; t=a; a=b; b=t;}

typedef struct DListNode {
	int elem;
	struct DListNode* prev, * next;
}DListNode;

typedef struct {
	DListNode* H;
	DListNode* T;
}SetType;

void initNode(DListNode* H, DListNode* T) {
	H->next = T;
	H->prev = NULL;
	T->prev = H;
	T->next = NULL;
}

void initSet(SetType* S) {
	S->H = (DListNode*)malloc(sizeof(DListNode));
	S->T = (DListNode*)malloc(sizeof(DListNode));
	initNode(S->H, S->T);
}

void addLast(SetType* S, int item) {
	DListNode* node = (DListNode*)malloc(sizeof(DListNode));
	node->elem = item;

	DListNode* prevLast = S->T->prev;

	prevLast->next = node;
	node->prev = prevLast;
	S->T->prev = node;
	node->next = S->T;
}

void printSetType(SetType* S) {
	DListNode* tmp = S->H->next;

	while (tmp != S->T) {
		printf("[%d] ", tmp->elem);
		tmp = tmp->next;
	}
	printf("\n");
}

void removeDupicate(SetType* S) {
    DListNode* deleted = S->H->next;
    
    while (deleted != S->T->prev) {
        if (deleted->elem == deleted->next->elem) {
            deleted->prev->next = deleted->next;
            deleted->next->prev = deleted->prev;
        }
        deleted = deleted->next;
    }
}

void selectionSort(SetType* S) {
    DListNode* start = S->H->next;
    
    while (start != S->T->prev) {
        int min = start->elem;
        DListNode* temp = start->next;
        DListNode* change = start;
        
        while (temp != S->T) {
            
            if (temp->elem < min) {
                min = temp->elem;
                change = temp;
            }
            temp = temp->next;
        }
        
        SWAP(start->elem, change->elem);
        start = start->next;
        
        removeDupicate(S);
    }
}

void insertionSort(SetType* S) {
    DListNode* start = S->H->next;
    
    while (start != S->T) {
        int min = start->elem;
        
        DListNode* temp = start->prev;
        
        while (temp != S->H && temp->elem > min) {
            temp->next->elem = temp->elem;
            temp = temp->prev;
        }
        
        temp->next->elem = min;
        start = start->next;
        
        removeDupicate(S);
    }
}

SetType* add(SetType* s1, SetType* s2) {
    SetType* result = (SetType*)malloc(sizeof(SetType));
    initSet(result);
    
    DListNode* s1Node = s1->H->next;
    DListNode* s2Node = s2->H->next;
    
    while (s1Node != s1->T && s2Node != s2->T) {  // 둘 다 끝나지 않은 경우
        if (s1Node->elem > s2Node->elem) {
            addLast(result, s2Node->elem);
            s2Node = s2Node->next;
        }
        else if (s1Node->elem < s2Node->elem) {
            addLast(result, s1Node->elem);
            s1Node = s1Node->next;
        }
        else {
            addLast(result, s1Node->elem);
            s1Node = s1Node->next;
            s2Node = s2Node->next;
        }
    }
    
    while (s1Node != s1->T) {
        addLast(result, s1Node->elem);
        s1Node = s1Node->next;
    }
    
    while (s2Node != s2->T) {
        addLast(result, s2Node->elem);
        s2Node = s2Node->next;
    }
    
    return result;
}

SetType* minus(SetType* s1, SetType* s2) {
    SetType* result = (SetType*)malloc(sizeof(SetType));
    initSet(result);
    
    DListNode* s1Node = s1->H->next;
    
    while (s1Node != s1->T) {
        int flag = 0;
        DListNode* s2Node = s2->H->next;
        
        while (s2Node != s2->T) {
            if (s2Node->elem == s1Node->elem)
                flag = 1;
            
            s2Node = s2Node->next;
        }
        if (flag == 0)
            addLast(result, s1Node->elem);
        
        s1Node = s1Node->next;
    }
    
    return result;
}

int main() {
	srand(time(NULL));

	SetType* s1 = (SetType*)malloc(sizeof(SetType));
	SetType* s2 = (SetType*)malloc(sizeof(SetType));
	initSet(s1);
	initSet(s2);

	for (int i = 0; i < 10; i++) {
		addLast(s1, rand() % 30 + 11);
		addLast(s2, rand() % 30 + 11);
	}

	printf("리스트 A: ");
	printSetType(s1);
	printf("리스트 B: ");
	printSetType(s2);
	printf("\n");

	printf("선택정렬 - 집합 A: ");
	selectionSort(s1);
	printSetType(s1);

	printf("삽입정렬 - 집합 B: ");
	insertionSort(s2);
	printSetType(s2);
	printf("\n");

	SetType* sum = add(s1, s2);
	printf("A와 B의 합집합: ");
	printSetType(sum);

	SetType* diff = minus(s1, s2);
	printf("A와 B의 차집합: ");
	printSetType(diff);

	return 0;
}