#include <stdbool.h>
#define SIZE 45

typedef struct todo{
    char task[SIZE];
}Todo;

typedef struct node{
    Todo todo;
    struct node *next;
}Node;

void hello_func(); // Ф-ция приветствия
void print_task_list(Node *head); // Ф-ция печати списка
Node *insert_task_at_tail(Node *head, Todo todo); // Ф-ция вставки нода в конец списка
Node *delete_at_tail(Node *head); // Ф-ция удаления нода в конце списка
int recursive_length(Node *node); // Рекурсивная ф-ция измерения списка

/* Ф-ция вставки нода, после определенного task`a,
   принимает начало спика, новый task, task после которого вставлеем новый task
*/
Node *insert_after(Node *head, Todo new_task, Todo after_task);
Node *delete_list(Node *node); // Ф-ция удаления списка
