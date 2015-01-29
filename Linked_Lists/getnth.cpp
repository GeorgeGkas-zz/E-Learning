#include <iostream>
#include <cstdio>

struct node{
	int value;
	struct node* next;
	
};

node* create_node(){
	
	node* ret = new node;
	ret->next = NULL;	
}

void insert(struct node** root, struct node** prev, struct node** current, int element) {
	
	(*current) = create_node();
	
	(*current)->value = element;
	
	if((*root)==NULL)
		(*root)=(*current);
	else
		(*prev)->next = (*current);
	
	(*prev) = (*current);
	
	
}

int getNth(struct node* head,int index){
	
	struct node* current = head;
	int count = 0;
	
	while(current != NULL){
		if(count == index)
			return(current->value);
			count++;
		current = current->next;		
		
	}
	printf("Element is non-existence! ");
	
}

int main() {
	
	node* root = NULL;
	node* prev, * current;
	
	int n = 3, index = 2, element = 0;
	
	
	for(int i = 0; i < n; i++) {
		scanf("%d",&element);
		insert(&root,&prev,&current,element);
		
		
	}
	
	
	printf("\nNow printing elements:\n");
	current = root;
	while (current != NULL) {
		printf("%i\n", current->value);
		current = current->next;
	} 
	
	printf("Value in index %d is %d",index,getNth(root,index));
	
}
