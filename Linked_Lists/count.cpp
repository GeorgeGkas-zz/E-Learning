#include <iostream>
#include <cstdio>

struct node {
    int value;
    node* next;
	
};

node* create_node() {
    node* ret = new node;
    ret->next = NULL;
} 


int count(struct node* head, int frequency) {
	
    struct node* current = head;
    int count = 0;

    while (current != NULL) {
        
        if(current->value == frequency) {
            count++;
        }
        
        current = current->next;
    }

    return count;
}

void insert(struct node** root,struct node** prev, struct node** current, int element) {
	
    (*current) = create_node();
    (*current)->value = element;
		
    if((*root) == NULL) {
        (*root) = (*current); 
    }
	 
    else{
        (*prev)->next = (*current); 
    }
    
	(*prev) = (*current);
}

int main() {
	
	int frequency = 0, n = 0;
	node* root = NULL;
	node* current, * prev;
	
	printf("give frequency number to count\n");
	scanf("%i", &frequency);
	printf("frequency number to count is %d\n",frequency);
	
	printf("How many numbers want to insert? ");
	scanf("%i", &n);
	printf("Now insert %d numbers\n",n);
	
	
	for (int i = 0; i < n; ++i) {
            int element;
            scanf("%d", &element);		
            insert(&root,&prev,&current,element);
	}
	
	
	printf("\nNow printing elements:\n");
	current = root;
	
	while (current != NULL) {
            printf("%i\n", current->value);
            current = current->next;
	} 
	
	printf("count of %d is %d",frequency, count(root, frequency)); 
	
}
