#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"
static void copy_to_node(Todo todo, Node *new_node); // ����������� ��������� � ���

static void copy_to_node(Todo todo, Node *new_node)
{
    new_node->todo = todo;
}

Node *delete_list(Node *node)
{
    if (node != NULL) // ���������� ,����������, "�������" ����
    {
        delete_list(node->next);
        free(node);
    }
    return NULL;
}

Node *delete_at_tail(Node *head) // �������� � ����� ������
{
    if (head == NULL) return NULL; // ���� ������� ������ ������ ���������� NULL
    else if (head->next == NULL) // ���� � ������� ������ 1 ���
    {
        free(head); // "�������" ���
        return NULL;
    }
    else
    {
        Node *current = head; // ��������� �� ������ ������
        Node *prev = NULL; // ��������� �� ��� ���������� current

        while (current->next != NULL) // ���������� �� ����� ������,
        {
            prev = current;           // ����������� �������� �������� ����
            current = current->next;  // �������� ��������� �� 1 ���
        }

        prev->next = NULL; // ����������� �������� ����� ������
        free(current); // "�������" ���
        return head;
    }

}

int recursive_length(Node *node) // ����������� �������� ������
{
    if (node == NULL) return 0;
    else return 1 + recursive_length(node->next);
}

Node *insert_after(Node *head, Todo new_task, Todo after_task) // ������� ������� ���� �����
{                                                              // ������������� task`a
    Node *new_node = calloc(1, sizeof(Node)); // �������� ����
    copy_to_node(new_task, new_node);

    if (head == NULL) return new_node; // ���� ������ ������ ���������� ����� ���
    else
    {
        Node *current = head;
        while (current->next != NULL) // �������� ������� ����
        {
            if (strcmp(current->todo.task, after_task.task) == 0)
            {
                new_node->next = current->next;//����� ��� ��������� �� ��������� ��� ����� current->value
                current->next = new_node; // � current ��� ��������� �� ����� ���
                return head;
            }
            else current = current->next; // ���� �� ����� after_value ���������� ����� ������
        }
        // ���� �� ����� �� ����� ������ � �� ����� after_value, �� ������ ������� � ����� ������
        new_node->next = current->next; // new_node ��������� �� NULL
        current->next = new_node;// � current �� ����� ���
        return head;
    }
}

Node *insert_task_at_tail (Node *head, Todo todo) // ������� ���� � ����� ������
{
    Node *new_node = calloc(1, sizeof(Node)); // �������� ����
    copy_to_node(todo, new_node);

    if (head == NULL) return new_node;
    else
    {
        Node *current = head;
        while(current->next != NULL) current = current->next; // ����� �� ���������� ����

        current->next = new_node;
        return head;
    }
}

void print_task_list(Node *head)
{
    Node *current = head;
    int i = 0;
    while (current != NULL)
    {
        printf("ToDo %d: %s\n", ++i, current->todo.task);
        current = current->next;
    }
}
void hello_func()
{
    puts("1. Create ToDo list.");
    puts("2. See ToDo list.");
    puts("3. Insert task after.");
    puts("4. Length of ToDo list.");
    puts("5. Delete at tail.");
    puts("6. Delete list.");
    puts("7. Exit.");

}
