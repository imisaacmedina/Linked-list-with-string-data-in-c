#include "linked_list.h"

int is_list_empty(struct Node** head){
	return *head == NULL;
}

int list_lenght(struct Node** head){
	if(is_list_empty(head)){
		return 0;
	}
	
	int length = 0;
	struct Node* temp = *head;
	
	while(temp != NULL){
		length++;
		temp = temp->next;
	}
	
	return length;
}

int search(struct Node* head, int data) {
	if (is_list_empty(&head)){
		return -1;
	}
	
	struct Node* temp = head;
	int length = 0;
	
	while (temp != NULL) {
		if (temp->data == data){
			return length;
		}
		length++;
		temp = temp->next;
	}
	
	return -1;
}

void print_nodes(struct Node* head){
	if (head != NULL){
		printf("%d", head->data);
		
		if (head->next != NULL){
			printf(", ", head->data);	
		}
		
		print_nodes(head->next);
	}
}

void insert(struct Node** head, int data) {
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	
	if (temp == NULL) {
		printf("Memory allocation failed.");
		exit(EXIT_FAILURE);
	}
	
	printf("Inserting %d...\n", data);
	
	temp->data = data;
	temp->next = *head;
	
	*head = temp;
	print_nodes(*head);
	printf("\n");
}

void remove_first(struct Node** head){
	if (is_list_empty(head)){
		printf("Unable to remove first, as the list is empty...\n\n");
		return;
	}

	struct Node* temp = *head;
	
	printf("Removing first data...\n");
	
	*head = temp->next;
	free(temp); 
	print_nodes(*head);
	printf("\n");
}

void insert_at(struct Node** head, int data, int pos){
	if(is_list_empty(head) && pos > 0){
		printf("Unable to insert at inder %d as the list is empty...\n\n");
		return;
	}
	
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	
	if (new_node == NULL) {
		printf("Memory allocation failed.");
		exit(EXIT_FAILURE);	
	}
	
	new_node->data = data;
	
	if (pos == 0){
		new_node->next = *head;
		*head = new_node;
		printf("Insert %d at index 0\n", data);
		print_nodes(*head);
		printf("\n");
		return;
	}
	
	if (pos > list_lenght(head)){
		printf("%d is an invalid position as the list is only %d.\n\n", pos, list_lenght(head));
		return;
	}
	
	int i;
	
	struct Node* temp = *head;
	struct Node* prev = NULL;
	
	for (i = 0; i < pos; i++){
		prev = temp;
		temp = temp->next;
	}
	
	prev->next = new_node;
	new_node->next = temp;
	
	printf("Insert %d at index %d\n", data, pos);
	print_nodes(*head);
	printf("\n");
}

void insert_last(struct Node** head, int data){
	struct Node* new_data = (struct Node*)malloc(sizeof(struct Node));
	
	if (new_data == NULL){
		printf("Memory allocation failed.");
		exit(EXIT_FAILURE);
	}
	
	new_data->data = data;
	
	if (*head == NULL) {
		printf("Inserting %d...\n", data);
		new_data->next = *head;
		*head = new_data;
		print_nodes(*head);
		printf("\n");
		return;
	}
	struct Node* temp = *head;
	
	while(temp->next != NULL){
		temp = temp->next;
	}
	
	printf("Inserting %d at the end of the list...\n", data);
	temp->next = new_data;
	new_data->next = NULL;
	
	print_nodes(*head);
	printf("\n");
}

void remove_nth(struct Node** head, int nth){
	if (is_list_empty(head)){
		printf("Unable to remove data, the list is empty...\n\n");
		return;
	}
	
	int len = list_lenght(head);
	if (nth > len){
		printf("Unable to remove data at index %d, the list is only %d...\n\n", nth, len);
		return;
	}
	
	struct Node* temp = *head;
	struct Node* prev = NULL;
	int i;
	
	if (temp->next == NULL) {
		printf("Removing data at first index %d...\n", nth);
		*head = NULL;
		free(temp);
		print_nodes(*head);
		printf("\n");
		return;
	}
	
	for (i = 0; i < nth; i++) {
		prev = temp;
		temp = temp->next;
	}
	
	printf("Removing data at index %d...\n", nth);
	
	prev->next = temp->next;
	free(temp);
	print_nodes(*head);
	printf("\n");
}

void find(struct Node* head, int data){
	int location = search(head, data);
	
	if (location == -1){
		printf("%d is not in the list...\n\n");
		return;
	}else{
		printf("%d is at index %d.\n\n", data, location);
	}
}

void remove_data(struct Node** head, int data) {
	int location = search(*head, data);
	
	if (location == -1){
		printf("Unable to remove %d as it is not in the list.\n\n");
		return;
	}
	
	struct Node* temp = *head;
	
	if (location == 0) {
		printf("Removing %d...\n");
		temp = temp->next;
		free(*head);
		*head = temp;
		print_nodes(*head);
		printf("\n");
		return;
	}
	
	struct Node* prev = NULL;
	int i;
	for(i = 0; i < location; i++){
		prev = temp;
		temp = temp->next;
	}
	
	printf("Removing %d...\n");
	prev->next = temp->next;
	free(temp);
	print_nodes(*head);
	printf("\n");
}
