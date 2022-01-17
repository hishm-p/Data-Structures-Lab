#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
} *start = NULL;

void create(int value)
{
    struct node *temp, *q;
    temp = malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        q = start;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = temp;
    }
}

void insert_at_begin(int value)
{
    struct node *temp;
    temp = malloc(sizeof(struct node));
    temp->data = value;
    temp->next = start;
    start->prev = temp;
    start = temp;
}

void insert_at_middle(int pos, int value)
{
    struct node *q, *temp;
    int count = 1;
    temp = malloc(sizeof(struct node));
    temp->data = value;
    q = start;
    while (count < pos - 1)
    {
        q = q->next;
        count++;
    }
    temp->next = q->next;
    temp->prev = q;
    q->next = temp;
}

void insert_at_end(int value)
{
    struct node *q, *temp;
    temp = malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;
    q = start;
    while (q->next != NULL)
    {
        q = q->next;
    }
    temp->prev = q;
    q->next = temp;
}

void delete_begin()
{
    struct node *temp;
    int value;
    if (start == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    value = start->data;
    printf("Deleted element is :%d\n", value);
    temp = start;
    start = temp->next;
    temp->prev = NULL;
    free(temp);
}

void delete_at_position(int pos)
{
    struct node *q, *temp;
    int value, count = 1;
    if (start == NULL)
    {
        printf("\nLinked list is empty\n");
        return;
    }
    q = start;
    if (pos == 1)
    {
        value = temp->data;
        temp->prev = NULL;
        start = temp->next;
        printf("\nDeleted element is %d\n", value);
        free(temp);
        return;
    }
    while (count < pos - 1)
    {
        q = q->next;
        count++;
        if (q->next == NULL)
        {
            printf("\nGiven position is not present in the linked list\n");
            return;
        }
    }
    temp = q->next;
    value = temp->data;
    q->next = temp->next;
    temp->next->prev = q;
    printf("\nDeleted element is %d\n", value);
    free(temp);
}

void delete_at_end()
{
    int value;
    struct node *q, *temp;
    if (start == NULL)
    {
        printf("\nLinked list is empty\n");
        return;
    }
    q = start;
    if (q->next == NULL)
    {
        temp = q;
        start = NULL;
    }
    while (q->next != NULL)
    {
        temp = q;
        q = q->next;
    }
    temp->next = NULL;
    temp = q;
    value = temp->data;
    printf("\nDeleted element is :%d\n", value);
    free(temp);
    return;
}

void display()
{
    struct node *q;
    q = start;
    if (q == NULL)
    {
        printf("\nLinked list is empty\n");
        return;
    }
    else
    {
        printf("\nLinked list elements are:\n");
        while (q != NULL)
        {
            printf("%d\t", q->data);
            q = q->next;
        }
        printf("\n");
    }
    return;
}

int main()
{
    int choice, num, value, pos;
    printf("Enter your choice:");
    while (1)
    {
        printf("\n1.Create a list\n2.Insert at beginning\n3.Insert at a position\n4.Insert at end\n5.Delete from beginning\n6.Delete from a specific position\n7.Delete from the end\n8.Display\n9.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number of elements to be inserted:");
            scanf("%d", &num);
            for (int i = 0; i < num; i++)
            {
                printf("Enter the element:");
                scanf("%d", &value);
                create(value);
            }
            break;
        case 2:
            printf("Enter the data to be inserted:");
            scanf("%d", &value);
            insert_at_begin(value);
            break;
        case 3:
            printf("Enter the position where data to be inserted:");
            scanf("%d", &pos);
            printf("Enter the data to be inserted:");
            scanf("%d", &value);
            insert_at_middle(pos, value);
            break;
        case 4:
            printf("Enter the data to be inserted:");
            scanf("%d", &value);
            insert_at_end(value);
            break;
        case 5:
            delete_begin();
            break;
        case 6:
            printf("Enter the position where element to be deleted:");
            scanf("%d", &pos);
            delete_at_position(pos);
            break;
        case 7:
            delete_at_end();
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
        default:
            break;
        }
    }
    return 0;
}