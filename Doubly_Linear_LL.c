#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

int Count(PNODE head)
{
    int iCnt = 0;

    while(head != NULL)
    {
        iCnt++;
        head = head->next;
    }
    return iCnt;
}
void Display(PNODE head)
{
    printf("Data from the LL is : \n");

    printf("NULL<->");
    
    while(head != NULL)
    {
        printf("|%d|<->",head->data);
        head = head->next;
    }
    printf("NULL\n");
}
void InsertFirst(PPNODE head, int no)
{
    PNODE newn = NULL;
    
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*head == NULL)
    {
        *head = newn;
    }
    else
    {
        newn->next = *head;
        (*head)->prev = newn;
        *head = newn;
    }
}
void InsertLast(PPNODE head, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*head == NULL)
    {
        *head = newn;
    }

    else
    {   temp = *head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
}
void InsertAtPos(PPNODE head, int no, int pos)
{   
    PNODE temp = NULL;
    PNODE newn = NULL;
    
    int size = 0;
    int iCnt = 0;

    size = Count(*head);

    if(pos < 1 || pos > size+1)
    {
        printf("Invalid Position\n");
        return;
    }
    if(pos == 1)
    {
        InsertFirst(head, no);
    }
    else if(pos == size +1)
    {
        InsertLast(head, no);
    }
    else
    {   
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = *head;

        for(iCnt = 1; iCnt < pos -1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        newn->next->prev = newn;
        temp->next = newn;
        newn->next = temp;
    }
}
void DeleteFirst(PPNODE head)
{
    if(*head == NULL)
    {
        return;
    }

    else if((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    
    else
    {   
        *head = (*head)->next;
        free((*head)->prev);
        (*head)->prev = NULL;

    }
}
void DeleteLast(PPNODE head)
{
    PNODE temp = NULL;

    if(*head == NULL)
    {
        return;
    }
    
    else if((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
    }

    else
    {
        temp = *head;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}
void DeleteAtPos(PPNODE head, int pos)
{
    int size = 0;
    int iCnt = 0;
    PNODE temp = NULL;
    
    size = Count(*head);

    if((pos < 1) || (pos > size))
    {
        printf("Invalid Position\n");
        return;
    }
    if(pos == 1)
    {
        DeleteFirst(head);
    }
    else if(pos == size)
    {
        DeleteLast(head);
    }
    else
    {
        temp = *head;

        for(iCnt = 1; iCnt < (pos -1); iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;
    }   
}

int main()
{
    PNODE First = NULL;
    int iRet = 0;

    InsertFirst(&First, 51);
    InsertFirst(&First, 21);
    InsertFirst(&First, 11);
    InsertLast(&First, 101);
    InsertLast(&First, 111);

    Display(First);
    iRet = Count(First);
    printf("Number of Elements in LL are : %d\n",iRet);

    DeleteFirst(&First);
    DeleteLast(&First);

    Display(First);
    iRet = Count(First);
    printf("Number of Elements in LL are : %d\n",iRet);

    return 0;
}