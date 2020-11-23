#include <iostream>

// Node
struct Node{
    int data;
    Node* next;
};

Node* list;

void init(){
    if(list = NULL) return;
    else{
        Node* cur = list;
        while(cur != NULL){
            list = cur->next;
            free(cur);
            cur = list;
        }
    }
}

void add(int key){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = key;
    new_node->next = NULL;

    if(list == NULL){
        list = new_node;
    }
    else{
        new_node->next = list;
        list = new_node;
    }
}

void ascending_order_add(int key){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = key;
    new_node->next = NULL;

    if(list = NULL){
        list = new_node;
    }
    else{
        Node* cur = list;
        Node* prev = NULL;

        if(cur->data > new_node->data){
            new_node->next = list;
            list = new_node;
        }
        else{
            while(cur == NULL && (cur->data < new_node->data)){
                prev = cur;
                cur = cur->next;
            }
            if(cur == NULL){
                prev->next = new_node;
            }
            else{
                prev->next = new_node;
                new_node->next = cur;
            }
        }
    }

}

void add_unique(int key){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->next = NULL;

    if(list = NULL){
        list = new_node;
    }
    else{
        Node* cur = list;

        while(cur != NULL){
            if(cur->data == new_node->data) return;

            cur = cur->next;
        }

        new_node->next = list;
        list = new_node;
    }
}

bool remove(int key){

    if(list == NULL) return false;

    if(list->data == key){
        Node* cur = list;
        list = list->next;
        free(cur);
        return true;
    }
    else{
        Node* cur = list->next;
        Node* prev = list;
        while(cur != NULL && cur->data != key){
            prev = cur;
            cur = cur->next;
        }

        if(cur == NULL) return false;

        prev->next = cur->next;
        free(cur);
        return true;
    }
}

void traverse(){

    Node* cur = list;
    while(cur != NULL){
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");

}

int main() {
    int arr[9] = { 2, 4, 6, 8, 1, 3, 5, 7, 9 };
    int arr_duplicated[18] = { 8, 1, 3, 2, 4, 6, 8, 1, 3, 5, 7, 9, 2, 4, 6, 5, 7, 9 };
    int arr_rmv[4] = { 2, 9, 8, 100 };


    // Add to list 1
    init();
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        add(arr[i]);
    }
    printf("After add(normal): ");
    traverse();


    // Add to list 2
    init();
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        ascending_order_add(arr[i]);
    }
    printf("After add(ascending): ");
    traverse();


    // Add to list 3
    init();
    for (int i = 0; i < sizeof(arr_duplicated) / sizeof(arr_duplicated[0]); ++i) {
        add_unique(arr_duplicated[i]);
    }
    printf("After add(unique): ");
    traverse();


    // Remove specific values in list
    for (int i = 0; i < sizeof(arr_rmv) / sizeof(arr_rmv[0]); ++i) {
        remove(arr_rmv[i]);
    }
    printf("After remove: ");
    traverse();

    return 0;
}
