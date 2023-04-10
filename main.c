/* ��������� "Todo List" � �������������� ������� �������

����� �������� �.�.
09.04.2023
v.1.0 */
/* ������������� ������ � func.c */
#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main()
{
    Node *list_head = NULL; // �������� ��������� �� ������ ������� � ������� ������
    Todo list; // ������������� ���������� ��� �������� ������
    char answer[1]; // ������ ����� �� ���������� ������
    int choice = 0;
    while (1)
    {
        system("cls");
        hello_func();
        scanf("%d", &choice);
        fflush(stdin);
        if (choice == 1) // ���� � ���������� ����������
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
        else if (choice == 2) // �������� � ����������� ������
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
        else if (choice == 3) // ������� ����� ������������� task`a
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
        else if (choice == 4) // ����������� ��������� ������
        {
            system("cls");
            printf("You have %d tasks", recursive_length(list_head));
            system("pause > 0");
        }
        else if (choice == 5) // �������� ���������� task`a
        {
            system("cls");
            puts("Do you want to delete last task? y/n");
            scanf("%c", answer);
            if (answer[0] == 'y') // ���������� ������
            {
                puts("***DELETED***");
                list_head = delete_at_tail(list_head);
                answer[0] = 'n';
                system("pause > 0");
            }

        }
        else if (choice == 6) // ������ �������� ������
        {
            system("cls");
            puts("Do you want to delete list? y/n");
            scanf("%c", answer);
            if (answer[0] == 'y') // ���������� ������
            {
                puts("***LIST DELETED***");
                list_head = delete_list(list_head);
                answer[0] = 'n';
                system("pause > 0");
            }

        }
        else if (choice == 7) // ����� �� ���������
        {
            system("cls");
            puts("Do you want to EXIT?");
            scanf("%c", answer);
            if (answer[0] == 'y') // ���������� ������
            {
                answer[0] = 'n';
                exit(0);
            }
        }
    }

    return 0;
}
