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
void insertAtPosition();
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
        insertAtPosition();
        if(choice == 5)
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

void insertAtPosition()
{
    if(head == NULL)
    {
        printf("the list doesn't have any nodes!");
    }
    else
    {
        int val = 0;
        int pos = 0;
        printf("enter the position -");
        scanf("%d", &pos);
        printf("enter the value -");
        scanf("%d", &val);
        if(pos > size)
        {
            printf("the postion is greater than the size of the list.");
        }
        else
        {
            if(pos == 0)
            {
               struct node* temp = (struct node*)malloc(sizeof(struct node));
               temp->val = val;
               temp->next = head;
               head = temp;
            }
            else
            {
                temp = head;
                struct node* temp1 = temp->next;
                struct node* nodeInsert = (struct node*)malloc(sizeof(struct node));
                nodeInsert->val = val;
                int c = 0;
                while(c < pos)
                {
                    temp = temp->next;
                    temp1 = temp1->next;
                    c++;
                }
                temp->next = nodeInsert;
                nodeInsert->next = temp1;
            }
            
        }
    }
}
