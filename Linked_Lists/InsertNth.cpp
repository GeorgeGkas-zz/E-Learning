/*Insert a new node at any index within a list. Insert SFINA*/
#include <iostream>
#include <cstdio>

#define SUCCESS 0
#define MAX 4
#define INDEX 2
#define DATA 942

struct node {
    int value;  
    node* next;
};

node* create_node() {
    node* ret = new node;
    ret->next = NULL;
}

void insert(struct node** root, struct node** prev, struct node** current, int element) {
    (*current) = create_node();
    (*current)->next = NULL;
    
    if ((*root) == NULL) {
        (*root) = (*current);
    }
    else {
        (*prev)->next = (*current);
    }
    
    (*prev) = (*current);
}

int main() {
    node* root = NULL;
    node* prev, * current;
    
    for (int i = 1; i <= MAX; i++) {
        int element;
        scanf("%d", &element);
        insert(&root, &prev, &current, element);
    }
    
    /*=========================================*/
    //I couldn't pass it to function
    current = root; 
    for (int i = 0; i < INDEX; i++) {
    	current = current->next;
     } 
    
    //Try to make a cycle linked list
    if (current->next == NULL) {
        current->next = root;
    }
    
    node* new_item = create_node();
    new_item->value = DATA;
    new_item->next = current->next;
    current->next = new_item;
    /*=========================================*/
    
    //FALSE OUTPUT WHY?
    printf("\nNow printing elements:\n");
    current = root;
    while (current != NULL) {
        printf("%i\n", current->value);
        current = current->next;
    } 
    
    return SUCCESS;
}
