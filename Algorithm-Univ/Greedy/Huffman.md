## 허프만 압축
---

### 1. 개념 🌱

파일에 빈번히 나타나는 문자에 짧은 이진 코드를 할당하는 방식. 이러한 이진 코드를 **허프만 코드**라고 한다.

<과정 및 알고리즘>

<img width="652" alt="스크린샷 2022-04-13 오후 1 03 41" src="https://user-images.githubusercontent.com/77239220/163097884-e600ec2d-2671-4a4a-87fd-9b0e6b44b4b5.png">

    HuffmanCoding
    1. 각 문자당 노드를 만들고 그 문자의 빈도수를 노드에 저장
    2. n 노드의 빈도수에 대해 우선 순위 큐 Q 생성
    3. for i=1 to n-1:  // 즉 Q에 있는 노드 수가 2 이상일 동안
            remove(Q, a)
            remove(Q, b)
            r = new Node
            r->left = a
            r->right = b
            r->freq = a->freq + b->freq
            insert(Q, r)
    4. return Q

    참고
    typedef struct Node
    {
        int freq;
        struct node* left, * right;
    }Node
            
### 2. 특징 🌸

- 허프만 압축으로 변환시킨 문자 코드들 사이에는 **접두부 특성**이 존재
    
    : 각 문자에 할당된 이진 코드는 다른 어떤 문자에 할당된 이진 코드의 접두부가 되지 않는다. 따라서 코드와 코드 사이를 구분할 구분자가 필요하지 않다.

- 반환된 트리에서 루트로부터 왼쪽 자식 노드로 내려가며 '0'을, 오른쪽 자식 노드에는 '1'을 부여하면서 단말에 도달할 때까지의 이진수를 추출해 문자의 이진 코드를 얻는다.

- 압축된 파일의 비트 수 B(T) = Σ (freq * depth)

- 원래 아스키 코드로 된 파일의 크기 = 빈도수의 합 * 8

- **압축률**
    
    - 압축된 파일의 크기 / 원래 파일의 크기 * 100

### 3. 시간 복잡도 ⏰
- n개의 노드를 만들고 빈도수 저장 : O(n)
- 우선 순위 큐 : 이진 힙 사용하면 O(n)
- while 루프 n-1 번 , Q에서 노드 제거와 삽입 : (n-1) * O(logn) = O(nlogn)

-> 최종: O(n) + O(n) + O(nlogn) + O(1) = **O(nlogn)**

### 4. 코드 🧑‍💻

- C언어
    ```c
    #include <stdio.h>
    #include <stdlib.h>
    #define MAX_ELEMENT 200
    
    //허프만 코드 생성
    typedef struct TreeNode{
        int weight;
        char ch;
        struct TreeNode* left;
        struct TreeNode* right;
    }TreeNode;

    typedef struct {
        TreeNode* ptree;
        char ch;
        int key;
    }element;

    typedef struct {
        element heap[MAX_ELEMENT];
        int heap_size;
    }HeapType;

    HeapType* create() //생성
    {
        return (HeapType*)malloc(sizeof(HeapType));
    }

    void init(HeapType* h) //초기화
    {
        h->heap_size = 0;
    }

    void insert_min_heap(HeapType* h, element item) //삽입
    {
        int i;
        i = ++(h->heap_size);

        while ((i != 1) && (item.key < h->heap[i / 2].key)) {
            h->heap[i] = h->heap[i / 2];
            i /= 2;
        }
        h->heap[i] = item;
    }

    element delete_min_heap(HeapType* h) //삭제
    {
        int parent, child;
        element item, temp;

        item = h->heap[1];
        temp = h->heap[(h->heap_size)--];
        parent = 1;
        child = 2;

        while (child <= h->heap_size) {
            if ((child < h->heap_size) && (h->heap[child].key) > h->heap[child + 1].key)
                child++;
            if (temp.key < h->heap[child].key) break;
            h->heap[parent] = h->heap[child];
            parent = child;
            child *= 2;
        }
        h->heap[parent] = temp;
        return item;
    }

    TreeNode* make_tree(TreeNode* left, TreeNode* right)
    {
        TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
        node->left = left;
        node->right = right;
        return node;
    }

    void destroy_tree(TreeNode* root)
    {
        if (root == NULL) return;
        destroy_tree(root->left);
        destroy_tree(root->right);
        free(root);
    }

    int is_leaf(TreeNode* root)
    {
        return !(root->left) && !(root->right);
    }

    void print_array(int codes[], int n)
    {
        for (int i = 0; i < n; i++)
            printf("%d", codes[i]);
        printf("\n");
    }

    void print_codes(TreeNode* root, int codes[], int top)
    {
        if (root->left){
            codes[top] = 1;
            print_codes(root->left, codes, top + 1);
        }
        if (root->right) {
            codes[top] = 0;
            print_codes(root->right, codes, top + 1);
        }
        if (is_leaf(root)) {
            printf("%c: ", root->ch);
            print_array(codes, top);
        }
    }

    void huffman_tree(int freq[], char ch_list[], int n) // 허프만 트리 함수
    {
        int i;
        TreeNode* node, * x;
        HeapType* heap;
        element e, e1, e2;
        int codes[100];
        int top = 0;

        heap = create();
        init(heap);
        for (i = 0; i < n; i++) {
            node = make_tree(NULL, NULL);
            e.ch = node->ch = ch_list[i];
            e.key = node->weight = freq[i];
            e.ptree = node;
            insert_min_heap(heap, e);
        }
        for (i = 1; i < n; i++) {
            e1 = delete_min_heap(heap);
            e2 = delete_min_heap(heap);
            x = make_tree(e1.ptree, e2.ptree);
            e.key = x->weight = e1.key + e2.key;
            e.ptree = x;
            printf("%d + %d -> %d \n", e1.key, e2.key, e.key);
            insert_min_heap(heap, e);
        }
        e = delete_min_heap(heap);
        print_codes(e.ptree, codes, top);
        destroy_tree(e.ptree);
        free(heap);
    }

    int main()
    {
        char ch_list[] = { 's','i','n','t','e' };
        int freq[] = { 4,6,8,12,15 };
        huffman_tree(freq, ch_list, 5);
        return 0;
    }
    ```
