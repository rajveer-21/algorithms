#include<stdio.h>
#include<stdlib.h>

struct node
{
    int val;
    struct node* next;
};
void insert();
void view();
struct node* head;
struct node* temp;

void main()
{
    int flg = 0;
    int choice = 0;
    while(flg == 0)
    {
        printf("enter you choice-");
        scanf("%d",&choice);
        if(choice == 1)
        insert();
        if(choice == 2)
        view();
        if(choice == 3)
        flg = 100000;
    }
}

void insert()
{
    int val = 0;
    printf("enter a value-");
    scanf("%d",&val);
    struct node* temp1 = (struct node*)malloc(sizeof(struct node));
    temp1->val = val;
    temp1->next = NULL;
    if(head == NULL)
    {
        head = temp1;
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = temp1;
    }
}

void view()
{
    temp = head;
    printf("view the fucking nodes!-\n")
    while(temp != NULL)
    {
        printf("%d \n",temp->val);
        temp = temp->next;
    }
}
