#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node* append(struct node *head, int new_data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    return head;
}
void printList(struct node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
int main() {
    struct node *head = NULL; 
    int input;
    printf("Введите элементы списка (0 для завершения):\n");
    while (1) {
        scanf("%d", &input);
        if (input == 0) {
            break;
        }
        head = append(head, input); 
    }
    printf("Список: ");
    printList(head);

    return 0;
}