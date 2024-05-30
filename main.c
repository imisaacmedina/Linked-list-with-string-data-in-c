#include "linked_list.h"

int main(){
	struct Node* head = NULL;
	remove_data(&head, 7);
	find(head, 5);
	remove_nth(&head, 0);
	remove_first(&head);
	insert_last(&head, 12);
	find(head, 5);
	remove_nth(&head, 0);
	insert_last(&head, 33);
	insert_at(&head, 5, 0);
	remove_nth(&head, 1);
	insert(&head, 4);
	remove_first(&head);
	insert(&head, 3);
	insert(&head, 2);
	insert_at(&head, 17, 3);
	insert_at(&head, 99, 5);
	find(head, 4);
	find(head, 5);
	find(head, 2);
	insert(&head, 1);
	remove_first(&head);
	insert_last(&head, 32);
	find(head, 32);
	find(head, 33);
	remove_data(&head, 2);
	remove_data(&head, 7);
	remove_data(&head, 17);
	remove_data(&head, 32);
	remove_data(&head, 3);
	remove_data(&head, 5);
	return 0;
}
