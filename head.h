#include <stdbool.h>
#define SIZE 45

typedef struct todo{
    char task[SIZE];
}Todo;

typedef struct node{
    Todo todo;
    struct node *next;
}Node;

void hello_func(); // �-��� �����������
void print_task_list(Node *head); // �-��� ������ ������
Node *insert_task_at_tail(Node *head, Todo todo); // �-��� ������� ���� � ����� ������
Node *delete_at_tail(Node *head); // �-��� �������� ���� � ����� ������
int recursive_length(Node *node); // ����������� �-��� ��������� ������

/* �-��� ������� ����, ����� ������������� task`a,
   ��������� ������ �����, ����� task, task ����� �������� ��������� ����� task
*/
Node *insert_after(Node *head, Todo new_task, Todo after_task);
Node *delete_list(Node *node); // �-��� �������� ������
