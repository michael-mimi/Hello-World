#include <stdio.h>
#include <stdlib.h>

struct student
{
    int num;
    int score;
    struct student *next;
};

typedef struct student STU;

STU *create(void)
{
    STU *head = NULL, *tail = NULL, *pNewElement = NULL;
    head = (STU *)malloc(sizeof(STU));
    if (head == NULL)
    {
        printf("head memory allocation failed\n");
        return NULL;
    }
    head->next = NULL;
    tail = head;
    int n, s;
    while (1)
    {
        printf("Please input number and score of the student\n");
        scanf("%d%d", &n, &s);
        if (n > 0 && s > 0)
        {
            pNewElement = (STU *)malloc(sizeof(STU));
            if (pNewElement == NULL)
            {
                printf(" newElement memory allocation failed\n");
                return NULL;
            }
            pNewElement->num = n;
            pNewElement->score = s;
            pNewElement->next = NULL;
            tail->next = pNewElement;
            tail = pNewElement;
        }
        else
            break;
    }
    pNewElement = head;
    head = head->next;
    free(pNewElement);
    return head;
}

void disp(STU *head)
{
    STU *p = head;
    while (1)
    {
        if (p == NULL)
            return;
        printf("number: %d, score: %d\n", p->num, p->score);
        p = p->next;
    }
}

STU *insert(STU *head)
{
    int n, s;
    STU *Einsert = NULL, *E1 = NULL, *E2 = NULL;
    E1 = head;
    while (1)
    {
        printf("please input the number and score of the student\n");
        scanf("%d%d", &n, &s);
        if (n > 0 && s > 0)
        {
            Einsert = (STU *)malloc(sizeof(STU));
            if (Einsert == NULL)
            {
                printf("failed to get the memory\n");
                return NULL;
            }
            Einsert->num = n;
            Einsert->score = s;
            while (n > E1->num && E1->next != NULL)
            {
                E2 = E1;
                E1 = E1->next;
            }
            if (n <= E1->num)
            {
                if (head == E1)
                {
                    Einsert->next = E1;
                    head = Einsert;
                }
                else
                {
                    Einsert->next = E1;
                    E2->next = Einsert;
                }
            }
            else
            {
                E1->next = Einsert;
                Einsert->next = NULL;
            }
        }
        else
            break;
    }
    return head;
}

STU *del(STU *head, int num)
{
    STU *p1 = NULL, *p2 = NULL;
    p1 = head;
    while (num != p1->num && p1->next != NULL)
    {
        p2 = p1;
        p1 = p1->next;
    }
    if (num == p1->num)
    {
        if (p1 == head)
        {
            head = p1->next;
            free(p1);
        }
        else
        {
            p2->next = p1->next;
            free(p2);
        }
    }
    else
        printf("can't find the number.\n");
    return head;
}

STU *reverse(STU *head)
{
    STU *p1 = NULL, *p2=NULL, *p3=NULL;
    if (head == NULL||head->next==NULL)
    {
        return head;
    }
    
    p1 = head;
    p2 = p1->next;
    while (p2)
    {
        p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;

    }
    head->next = NULL;
    head = p1;
    return head;

}

void freeAll(STU *head)
{
    STU *p=NULL, *q=NULL;
    p=head;
    while (p->next!=NULL)
    {
        q = p->next;
        p->next = q->next;
        free(q);
    }
    free(head);
    
}

int main(void)
{
    STU *head = NULL;
    head = create();
    disp(head);
}