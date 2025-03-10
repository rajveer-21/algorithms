#include<stdio.h>
#include<stdlib.h>

int size = 0;
struct node
{
    int val;
    struct node* next;
};
void insert();
void delete();
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
        delete();
        if(choice == 4)
        {
            flg = 100000;
            printf("thanks for using this piece of shit!");
        }
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
    size++;
}

void delete()
{
    int pos = 0;
    printf("enter the postion you want to delele at-");
    scanf("%d",&pos);
    if(size == 0)
    {
        printf("the list has no nodes at all!");
        return;
    }
    if(pos >= size)
    {
        printf("the position is greater than the size of the list!");
        return;
    }
    else
    {
        if(pos == 0)
        {
            temp = head;
            head = head->next;
            free(temp);
        }
        else
        {
            int curr = 0;
            pos = pos - 1;
            temp = head;
            struct node* temp1 = temp->next;
            while(curr != pos)
            {
                temp = temp->next;
                temp1 = temp1->next;
                curr++;
            }
            temp->next = temp1->next;
            free(temp1);
        }
        size--;
    }
}

void view()
{
    temp = head;
    printf("view the fucking nodes!-\n");
    while(temp != NULL)
    {
        printf("%d \n",temp->val);
        temp = temp->next;
    }
}
