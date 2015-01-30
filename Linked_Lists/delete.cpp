/*Program that destroy a linked list*/
#include <iostream>
#include <cstdio>
#include <cstdlib>

#define MAX 4
#define SUCCESS 0

struct node {
    int value;
    node* next;
};

/*Functions Prototype*/
node* create_node();
int insert(struct node** root, struct node** prev, struct node** current, int element);
void DeleteList(struct node** root, struct node** prev, struct node** current);

/*Start of Program*/
int main() {
    node* root = NULL;
    node* prev, * current;

    for (int i = 1; i <= MAX; i++){
        int element;
        scanf("%d", &element);
        insert(&root, &prev, &current, element);      
    }
        
    DeleteList(&root, &prev, &current);
    
    return SUCCESS;
}

node* create_node() {
    node* ret = new node;
    ret->next = NULL; 
}

int insert(struct node** root, struct node** prev, struct node** current, int element) {
    (*current) = create_node();
    (*current)->value = element;
    
    if ((*root) == NULL) {
        (*root) = (*current);
    }
    else {
        (*prev)->next = (*current);
    }
    
    (*prev) = (*current);
}

void DeleteList(struct node** root, struct node** prev, struct node** current) {
    (*root) = (*current);
    node* next;

    while ((*current) != NULL) {
       next = (*current)->next;
       free(current);
       (*current) = next;
    }
    
    (*root) = NULL;
}
