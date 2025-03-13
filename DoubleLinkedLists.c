#include<stdio.h>
#include<stdlib.h>

int size = 0;//for counting the number of nodes in the DLL

struct node*
{
    int val;
    struct node* next;
    struct node* prev;
};

struct node* head;
struct node* temp1;

void main()
{
    
}

void create()
{
    int val = 0;
    printf("enter a value-"); 
    scanf("%d",&val);
    struct node* temp2 = (struct node*)malloc(sizeof(struct node));
    temp2->val = val;
    temp2->next = NULL;
    temp2->prev = NULL;
    if(head == NULL)
    {
        head = temp2;
    }
    else
    {
        temp1 = head;
        while(temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp2;
        temp2->prev = temp1;
    }
    size++;
}
