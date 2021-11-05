#include <stdio.h>
#include <stdlib.h>

/* Binary Serach Tree 구조의 binary_node 구조체 정의 */
typedef struct binary_node
{
    int data;

    struct binary_node *left;  // left node
    struct binary_node *right; // right node
} BinNode;

/* binary_node 동적할당 및 Initializing */
BinNode *getBinaryNode(void)
{
    BinNode *newNode = calloc(1, sizeof(BinNode));

    newNode->data = 0;     // data 초기화
    newNode->left = NULL;  // 왼쪽 자식 노드 초기값 NULL
    newNode->right = NULL; // 오른쪽 자식 노드 초기값 NULL

    // 노드 초기화 확인 message
    // printf("Initializing the binary_node : Success\n");

    return newNode;
}

/* left child node, right child node 설정 */
void setBinNode(BinNode *node, int data, BinNode *left_child, BinNode *right_child)
{
    node->data = data;
    node->left = left_child;
    node->right = right_child;
}

/* node 추가 함수 */
BinNode *addNode(BinNode *node, int data)
{
    if (node == NULL)
    {
        // node가 비어있는 경우, data를 node에 추가
        node = getBinaryNode();
        setBinNode(node, data, NULL, NULL);
    }
    else if (data < node->data)
    {
        // data 값이 저장된 node 값보다 적을 경우, left node에 추가
        node->left = addNode(node->left, data); // 재귀적으로 addNode 호출하여 if (node==NULL) 실행
    }
    else if (data > node->data)
    {
        // data 값이 저장된 node 값보다 클 경우, right node에 추가
        node->right = addNode(node->right, data); // 재귀적으로 addNode 호출하여 if (node==NULL) 실행
    }
    return node;
}

/* 정렬된 node 출력 함수 */
void showTree(const BinNode *node)
{
    if (node != NULL)
    {
        showTree(node->left);
        printf("%d ", node->data);
        showTree(node->right);
    }
}

/* 특정 key 검색하는 함수 */
BinNode *searchTree(BinNode *ptr, int key)
{
    if (ptr == NULL)
    {
        // 찾는 key 값이 tree에 없음
        printf("\nFAIL to search %d\n", key);
        return NULL;
    }
    else if (key == ptr->data)
    {
        // 찾는 key 값이 tree 내에 존재함
        printf("\nSUCCESS to search %d\n", key);
    }
    else if (key < ptr->data)
    {
        // 왼쪽 노드 searchTree 함수 재귀적으로 호출하여 탐색
        searchTree(ptr->left, key);
    }
    else if (key > ptr->data)
    {
        // 오른쪽 노드 searchTree 함수 재귀적으로 호출하여 탐색
        searchTree(ptr->right, key);
    }
}

/* 모든 노드 메모리 해제 */
void deleteTree(BinNode *node)
{
    if (node != NULL)
    {
        deleteTree(node->left);
        deleteTree(node->right);
        free(node);
    }
}

int main(void)
{
    // Show the message that the program start
    printf("\nStart the program\n");

    // Text file open as read mode
    FILE *pFile = fopen("test.txt", "r");
    printf("Open the file as read mode\n");

    int intTemp = -1;
    int key;                // 탐색할 key 값
    BinNode *root = NULL;   // 값 저장하여 정렬할 tree node 선언
    BinNode *search = NULL; // key 탐삭할 node 선언

    if (pFile == NULL)
    {
        // file open 실패 시, 프로그램 종료
        printf("File does not exist\n");
        return 0;
    }

    // file open 성공 시
    while (pFile != NULL)
    {
        fscanf(pFile, "%d", &intTemp);
        if (intTemp < 0)
            break; // file의 끝을 알리는 '-1' 값에 도달하면 이 program unit 종료

        // 트리생성
        root = addNode(root, intTemp);
    }

    printf("\n/*-----Sorting Success-----*/\n"); // 정렬에 성공했음을 알림

    // 생성된 tree 보기
    // showTree(root);

    // 생성된 트리에서 키 검색
    printf("\nEnter the key value to search : ");
    scanf("%d", &key);
    search = searchTree(root, key);

    // 파일 형태로 반환
    fclose(pFile); // close file

    deleteTree(root); // tree에 할당된 node 해제

    return 0;
}