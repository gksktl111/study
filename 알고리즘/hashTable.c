#include <stdio.h>
#include <stdlib.h> //  메모리 할당을 위함

struct bucket *hashTable = NULL;
int BUCKET_SIZE = 10; // 버켓의 총길이 (열쇠를 넣을 서랍의 개수)

struct node // 노드 구조체 선언
{
    int key;           // 해시함수에서 사용할 key
    int value;         // key 가 가지고 있는 데이터
    struct node *next; // 다음 노드를 가리키는 포인터
};

struct bucket // 버켓 구조체 선언
{
    struct node *head; // 버켓 가장 앞에 있는 노드의 포인터
    int count;         // 버켓에 들어있는 노드의 개수
};

struct node *createNode(int key, int value) // 해쉬 테이블이 삽입될 때 새로 노드를 생성해주는 함수 (초기화)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node)); // 메모리 할당

    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL; // 생성 할때는  next를  NULL로 초기화

    return newNode;
}

int hashFunction(int key) // 단순히 key를 버켓 길이로 나눈 나머지로 함수를 만듬
{
    return key % BUCKET_SIZE;
}

void add(int key, int value) //  새로 키를 추가하는 함수
{
    int hashIndex = hashFunction(key);             // 어느 버켓에 추가할지 인덱스를 계산
    struct node *newNode = createNode(key, value); //새로 노드 생성

    if (hashTable[hashIndex].count == 0) // 계산한 인덱스 버켓에 아무 노드도 없을경우
    {
        hashTable[hashIndex].count = 1;
        hashTable[hashIndex].head = newNode; // head 교체
    }
    else // 버켓에 다를 노드가 있을경우 한칸씩 밀고 내가 헤드가 된다(실제로는 포인터만 바꿔줌)
    {
        newNode->next = hashTable[hashIndex].head;
        hashTable[hashIndex].head = newNode;
        hashTable[hashIndex].count++;   // 노드 개수가 늘어났다는 표사
    }
}

void remove_key(int key) // key를 삭제해주는 함수
{
    int hashIndex = hashFunction(key);
    int flag = 0; // 삭제가 되었는지 확인하는 flag 선언

    struct node *node;   // 키를 찾아줄 iterator 선언
    struct node *before; // 노드가 지나간 바로 전 노드

    node = hashTable[hashIndex].head; // 버켓의 head부터 시작

    while (node != NULL) // NULL 값이 나올때까지 순회
    {
        if (node->key == key)
        {
            if (node == hashTable[hashIndex].head) // 포인터 바꿔주기 (노드가 헤드인 경우, 아닌 경우)
            {
                hashTable[hashIndex].head = node->next; // 다음 노드가 이제 헤드
            }
            else
            {
                before->next = node->next; // 전 노드가 내 다음 노드를 가리킴
            }
            hashTable[hashIndex].count--;
            free(node);
            flag = 1;
        }
        before = node; // 노드 바꿔주기전에 저장
        node = node->next;
    }
    if (flag == 1)
    {
        printf("\n [ %d ] 이/가 삭제되었습니다. \n", key);
    }
    else
    {
        printf("\n [ %d ] 이/가 존재하지 않아 삭제하지 못했습니다. \n", key);
    }
}

void search(int key) // key를 주면 value를 알려주는 함수
{
    int hashIndex = hashFunction(key);
    struct node *node = hashTable[hashIndex].head;
    int flag = 0;
    while (node != NULL)
    {
        if (node->key == key)
        {
            flag = 1;
            break;
        }
        node = node->next;
    }
    if (flag == 1) // key를 찾았다면
    {
        printf("\n 키는 [ %d ], 값은 [ %d ] 입니다. \n", node->key, node->value);
    }
    else
    {
        printf("\n 존재하지 않는 키는 찾을 수 없습니다. \n");
    }
}

void display() // 해쉬테이블 전체를 출력해주는 함수
{
    struct node *iterator; // 반복자 선언
    printf("\n========= display  start ===========\n");
    for (int i = 0; i < BUCKET_SIZE; i++)
    {
        iterator = hashTable[i].head;
        printf("Bucket [%d] : ", i);
        while (iterator != NULL)
        {
            printf("(key : %d, val : %d) ->  ", iterator->key, iterator->value);
            iterator = iterator->next;
        }
        printf("\n");
    }
    printf("\n=========== display complete ===========\n");
}

int main()
{
    hashTable = (struct bucket *)malloc(BUCKET_SIZE * sizeof(struct bucket)); // 해시테이블 메모리 할당

    for (int i = 0; i < 16; i++)
    {
        add(i, 10 * i);
    }
    // 몇개 더 추가
    add(21, 210);
    add(31, 310);
    add(41, 410);

    display();

    remove_key(31);
    remove_key(11);
    remove_key(51);

    display();

    search(11);
    search(1);

    return 0;
}