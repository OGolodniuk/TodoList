/* Программа "Todo List" с использованием связных списков

автор Голоднюк О.И.
09.04.2023
v.1.0 */
/* Компилировать вместе с func.c */
#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main()
{
    Node *list_head = NULL; // Создание указателя на первый елемент в связном списке
    Todo list; // Инициализация переменной для хранения тасков
    char answer[1]; // Храним ответ на уточняющий вопрос
    int choice = 0;
    while (1)
    {
        system("cls");
        hello_func();
        scanf("%d", &choice);
        fflush(stdin);
        if (choice == 1) // Сбор и сохранения информации
        {
            system("cls");
            puts("First task");
            while (gets(list.task) != NULL && list.task[0] != '\0')
                {
                    list_head = insert_task_at_tail(list_head, list);
                    puts("Next task or ENTER");
                }
                system("cls");
        }
        else if (choice == 2) // Проверка и отображения списка
        {
            system("cls");
            if (recursive_length(list_head) == 0)
            {
                 puts("Empty list");
                system("pause > 0");
            }
            else
            {
                print_task_list(list_head);
                system("pause > 0");
            }
        }
        else if (choice == 3) // Вставка после определенного task`a
        {
            system("cls");
            Todo after_task;
            puts("After task:");
            gets(after_task.task);
            fflush(stdin);
            puts("New task:");
            gets(list.task);
            fflush(stdin);
            list_head = insert_after(list_head, list, after_task);
        }
        else if (choice == 4) // Рекурсивное измерения списка
        {
            system("cls");
            printf("You have %d tasks", recursive_length(list_head));
            system("pause > 0");
        }
        else if (choice == 5) // Удаления последнего task`a
        {
            system("cls");
            puts("Do you want to delete last task? y/n");
            scanf("%c", answer);
            if (answer[0] == 'y') // Уточняющий вопрос
            {
                puts("***DELETED***");
                list_head = delete_at_tail(list_head);
                answer[0] = 'n';
                system("pause > 0");
            }

        }
        else if (choice == 6) // Полное удаления списка
        {
            system("cls");
            puts("Do you want to delete list? y/n");
            scanf("%c", answer);
            if (answer[0] == 'y') // Уточняющий вопрос
            {
                puts("***LIST DELETED***");
                list_head = delete_list(list_head);
                answer[0] = 'n';
                system("pause > 0");
            }

        }
        else if (choice == 7) // Выход из программы
        {
            system("cls");
            puts("Do you want to EXIT?");
            scanf("%c", answer);
            if (answer[0] == 'y') // Уточняющий вопрос
            {
                answer[0] = 'n';
                exit(0);
            }
        }
    }

    return 0;
}
