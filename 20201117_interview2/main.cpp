#include <iostream>


typedef struct _node
{
    int data;
    struct _node *next;
} Node;

Node* Reverse(Node* head){
    Node* tail = NULL;  // 새로 만들어질 노드이 헤드 포인터
    Node* curNode;      // 남아있는 오리지널 노드의 주소를 가리킬 포인터

    while(head != NULL){
        curNode = head->next;
        head->next = tail;
        tail = head;
        head = curNode;
    }
    return tail;
}