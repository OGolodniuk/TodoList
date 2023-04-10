#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"
static void copy_to_node(Todo todo, Node *new_node); // Копирование литералов в нод

static void copy_to_node(Todo todo, Node *new_node)
{
    new_node->todo = todo;
}

Node *delete_list(Node *node)
{
    if (node != NULL) // Рекурсивно ,поочередно, "удаляем" ноды
    {
        delete_list(node->next);
        free(node);
    }
    return NULL;
}

Node *delete_at_tail(Node *head) // Удаление в конце списка
{
    if (head == NULL) return NULL; // Если связный список пустой возвращаем NULL
    else if (head->next == NULL) // Если в связном списке 1 нод
    {
        free(head); // "УДАЛЯЕМ" нод
        return NULL;
    }
    else
    {
        Node *current = head; // Указатель на начало списка
        Node *prev = NULL; // Указатель на нод предыдущий current

        while (current->next != NULL) // Проходимся по всему списку,
        {
            prev = current;           // присваиваем значения текущего нода
            current = current->next;  // сдвигаем переменну на 1 нод
        }

        prev->next = NULL; // Присваиваем значения конца списка
        free(current); // "УДАЛЯЕМ" нод
        return head;
    }

}

int recursive_length(Node *node) // Рекурсивная проверка длинны
{
    if (node == NULL) return 0;
    else return 1 + recursive_length(node->next);
}

Node *insert_after(Node *head, Todo new_task, Todo after_task) // Функция вставки нода после
{                                                              // определенного task`a
    Node *new_node = calloc(1, sizeof(Node)); // Создание нода
    copy_to_node(new_task, new_node);

    if (head == NULL) return new_node; // Если список пустой возвращаем новый нод
    else
    {
        Node *current = head;
        while (current->next != NULL) // Проверка каждого нода
        {
            if (strcmp(current->todo.task, after_task.task) == 0)
            {
                new_node->next = current->next;//Новый нод указывает на следующий нод после current->value
                current->next = new_node; // А current нод указывает на новый нод
                return head;
            }
            else current = current->next; // Если не нашли after_value продолжаем сдвиг вперед
        }
        // Если мы дошли до конца списка и не нашли after_value, то делаем вставку в конце списка
        new_node->next = current->next; // new_node указывает на NULL
        current->next = new_node;// А current на новый нод
        return head;
    }
}

Node *insert_task_at_tail (Node *head, Todo todo) // Вставка нода в конец списка
{
    Node *new_node = calloc(1, sizeof(Node)); // Создание нода
    copy_to_node(todo, new_node);

    if (head == NULL) return new_node;
    else
    {
        Node *current = head;
        while(current->next != NULL) current = current->next; // Сдвиг до последнего нода

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
