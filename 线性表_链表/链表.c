#include <stdio.h>
#include <malloc.h>

#define Elemtype int
#define Status int   //״̬ ״̬����Ϊint��
#define ElemType int //�û���������
#define TRUE 1
#define FALSE 0
#define ERROR -1

typedef struct LNode
{
    Elemtype data;
    struct LNode *next;
} LNode, *LinkList;

LinkList L;
LinkList L2;

/*
    ��ʼ������
*/
Status Init_L(LinkList *L)
{
    //��ʼ��������Ǵ���һ��ͷ�ڵ㣬ͷ�ڵ��ָ�����ָ��ָ���
    if (*L = (LNode *)malloc(sizeof(LNode)))
    {
        (*L)->next = NULL;
        (*L)->data = 0; //ͷ�ڵ��data��������ĳ���
        return TRUE;
    }
    else
        return ERROR;
}

/*
    ��ֵ���ң�ֻ���ҵ�һ��ƥ��Ľڵ�
    @t  �Ż�Ҫ���ҵĽڵ��λ��
    @Q  ����Ҫ���ҵĽڵ�ĵ�ַ
*/
/*
Status ListSelectValues_L(LinkList L, ElemType e,int *t,LinkList *Q){
    LinkList P = L->next;   //ֱ��ָ���һ���ڵ�
    int i = 1;              //�����ͷ�ڵ㣬��ֹ��������                  
    while (P && (P->data!=e))           //����û��ͷ��û�ҵ�ֵ
    {
        P = P->next;
        i++;
    }
    if (!P)
    {
        return FALSE;
    }
    *t = i;
    *Q = P;             //���ҵ��ڵ�ĵ�ַ���ظ����ݹ����Ľṹ��ָ�����
    return TRUE;
}
*/

int ListSelectValues_L(LinkList L, ElemType e)
{
    LinkList P = L->next;       //ֱ��ָ���׽ڵ�
    int i = 1;                  //�����ͷ�ڵ㣬��ֹ��������
    while (P && (P->data != e)) //����û��ͷ��û�ҵ�ֵ
    {
        P = P->next;
        i++;
    }
    if (!P)
    {
        return -1;
    }
    return i;
}

Status GetElem_L(LNode *L, int i, ElemType *e)
{
    LNode *p = L;
    int j = 0; //������,0 ����ָ��ͷָ��
    while (p && j < i)
    {
        p = p->next; //��ָ��p������һ�����
        j++;         //��������һ
    }
    if (!p || i > j)
    {
        return ERROR;
    }
    *e = p->data;
    return TRUE;
}

/*
    j               
    ^
    0   1   2   3   4
    |   |   |   |   |
*/

Status ListInsert_L(LNode *L, int i, ElemType e)
{
    LNode *p = L, *s;
    int j = 0;             //���ҽڵ��ָ��
    while (p && j < i - 1) //�ҵ�
    {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1)
        return ERROR;
    if (s = (LNode *)malloc(sizeof(LNode)))
    {
        s->next = p->next;
        p->next = s;
        s->data = e;
        L->data++; // �����ȼ�һ
        return TRUE;
    }
    else
    {
        return ERROR;
    }
}

/*
    ��������
*/
Status ListInsertData_L(LinkList L, int i, ElemType e)
{
    LinkList P = L;
    int j = 0;
    while (P && j < i)
    {
        P = P->next;
        j++;
    }
    if (!P || j > i)
    {
        return ERROR;
    }
    P->data = e;
    return TRUE;
}

Status ListDelete_L(LNode *L, int i, ElemType *e)
{
    LNode *p = L, *s;
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1)
    {
        return ERROR;
    }
    s = p->next; //��ʱ����Ҫɾ���ڵ��ָ��
    p->next = s->next;
    *e = s->data;
    free(s);
    L->data--; // �����ȼ�һ
    return TRUE;
    /*
    e = (p->next)->data;            //��Ҫɾ�������ݷ��ظ�e
    p->next = (p->next)->next;          //����i���ڵ��������ɾ��
    free(); */
}

void ListDisplay_L(LNode *L)
{
    LNode *p = L;
    while (p)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
}

/*
    ��ȡ�����ȣ�ͷ�ڵ�Ϊ0��
*/
void ListLength_L(LNode *L, int *e)
{
    LNode *p = L->next;
    int i = 0;
    while (p != NULL) //����ָ��ָ��Ľڵ㲻Ϊ�ռ�������һ
    {
        i++;
        p = p->next;
    }
    *e = i;
}

/*
    β�巨��������
*/
void CreateList_L(LinkList L, int n)
{
    LinkList P, Q;
    int i;
    P = L;
    for (i = 0; i < n; i++)
    {
        Q = (LinkList)malloc(sizeof(LNode));
        Q->next = NULL;
        P->next = Q;
        P = Q;
    }
}

/*
    ͷ�巨��������
*/
void CreateListHead_L(LinkList L, int n)
{
    LinkList P;
    int i;
    for (i = 0; i < n; i++)
    {
        P = (LinkList)malloc(sizeof(LNode));
        P->next = L->next;
        L->next = P;
    }
}

/*
    �ϲ���������
*/
void MergeList_e(LinkList L1, LinkList L2, LinkList *L3)
{
    LinkList PA, PB, PC;
    PA = L1->next;
    PB = L2->next;
    PC = *L3 = L1;
    while (PA && PB)
    {
        if (PA->data < PB->data)
        {
            PC->next = PA;
            PC = PA;
            PA = PA->next;
        }
        else
        {
            PC->next = PB;
            PC = PB;
            PB = PB->next;
        }
    }
    PC->next = (PA ? PA : PB);
    free(L2);
}

void main()
{
    //    LNode *L;
    LinkList K;
    int i;
    Init_L(&L);
    ListLength_L(L, &i);
    CreateListHead_L(L, 10);
    //    CreateList_L(L,10);
    for (i = 0; i < 10; i++)
    {
        if (ListInsertData_L(L, i + 1, i * i) != 1)
        {
            printf("�������\n");
        }
    }
    ListLength_L(L, &i);
    printf("����ĳ���Ϊ:%d\n", i);
    printf("ͷ�ڵ�(��������洢����ĳ���)\n|\nV\n");
    ListDisplay_L(L);
    printf("\n");
    // ListDelete_L(L,3,&e);
    // printf("Ҫɾ����������:%d\n",e);
    // printf("ͷ�ڵ�(��������洢����ĳ���)\n|\nV\n");
    // ListDisplay_L(L);
    // printf("\n");
    Init_L(&L2);
    CreateListHead_L(L2, 10);
    ListLength_L(L2, &i);
    printf("����ĳ���Ϊ:%d\n", i);
    //    CreateList_L(L,10);
    for (i = 0; i < 10; i++)
    {
        if (ListInsertData_L(L2, i + 1, i + 1) != 1)
        {
            printf("�������\n");
        }
    }
    // printf("test");
    ListDisplay_L(L2);
    printf("\n");
    MergeList_e(L, L2, &K);
    ListDisplay_L(K);
    printf("\n");
    ListLength_L(K, &i);
    printf("����ĳ���Ϊ:%d\n", i);
}