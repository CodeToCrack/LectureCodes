#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *prev;
	int data;
	struct node* next;
};

void insertion(struct node** head_ref, int new_data, int position)
{
	struct node* current=*head_ref;
	int i;
	/* allocate node */
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	/* put in the data */
	newNode->data = new_data;

	/*Check for insertion at the beginning condition*/
	if(position==0){
		newNode->next = (*head_ref); //put new node in front of the old list
		(*head_ref) = newNode; //move the head to point to the new node
		newNode->prev = NULL;
		return;
	}

	/*Move current pointer to the the Node after which insertion will take place*/
	for(i=1;i<position && current !=NULL;i++){
		current=current->next;
	}


	/*Check for out of bound insertion condition*/
	if(current !=NULL){
		newNode->next=current->next;
		current->next=newNode;
		newNode->prev=current;
		(newNode->next)->prev=newNode;
	} else {
		printf("Insertion Location is greater than the Length of the Doubly Linked List \n");
	}
}


void deletion(struct node** head_ref, int position){
	struct node* current=*head_ref;
	int i;
	if(*head_ref==NULL){
		printf("List is Empty");
		return;
	}
	/*Check for deletion at the beginning condition*/
	if(position==0){
		(*head_ref) = (*head_ref)->next;
		printf("The deleted value is %d \n",current->data);
		free(current);
		return;
	}

	/*Move current pointer to the the Node after which deletion will take place*/
	for(i=1;i<position && current->next !=NULL;i++){
		current=current->next;
	}

	/*Check for out of bound deletion condition*/
	if(current->next !=NULL){
		struct node* temp=current->next;
		current->next=(current->next)->next;
		(current->next)->prev=current;
		printf("The deleted value is %d \n",temp->data);
		free(temp);
		return;
	}else {
		printf("Deletion Location is greater than the Length of the Doubly Linked List \n");
	}
}

void traversal(struct node *current)
{
	//current is initialized with "head" since we are passing head as the parameter
	while (current != NULL)
	{
		printf("%d->", current->data);
		current = current->next;
	}
	printf("NULL\n");

}

int main()
{
	/* Start with the empty list */
	struct node* head = NULL;
	int i;

	for (i=5; i>0; i--)
	{
		insertion(&head, i,0); //insertion at beginning
		traversal(head);
	}

	insertion(&head,10,2); //insertion after 2nd node with value 10
	traversal(head);

	deletion(&head,0); //deletion at the beginning
	deletion(&head,3); //deletion after 3rd node
	traversal(head);
	return 0;
}
