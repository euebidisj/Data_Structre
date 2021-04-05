#include <stdio.h>
#include <malloc.h>

#define Elemtype int
#define Status int   //状态 状态类型为int型
#define ElemType int //用户定义类型
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
    初始化链表
*/
Status Init_L(LinkList *L)
{
    //初始化链表就是创建一个头节点，头节点的指针域的指针指向空
    if (*L = (LNode *)malloc(sizeof(LNode)))
    {
        (*L)->next = NULL;
        (*L)->data = 0; //头节点的data域存放链表的长度
        return TRUE;
    }
    else
        return ERROR;
}

/*
    按值查找，只查找第一个匹配的节点
    @t  放回要查找的节点的位置
    @Q  返回要查找的节点的地址
*/
/*
Status ListSelectValues_L(LinkList L, ElemType e,int *t,LinkList *Q){
    LinkList P = L->next;   //直接指向第一个节点
    int i = 1;              //不检查头节点，防止发生错误                  
    while (P && (P->data!=e))           //链表没到头和没找到值
    {
        P = P->next;
        i++;
    }
    if (!P)
    {
        return FALSE;
    }
    *t = i;
    *Q = P;             //将找到节点的地址返回给传递过来的结构体指针变量
    return TRUE;
}
*/

int ListSelectValues_L(LinkList L, ElemType e)
{
    LinkList P = L->next;       //直接指向首节点
    int i = 1;                  //不检查头节点，防止发生错误
    while (P && (P->data != e)) //链表没到头和没找到值
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
    int j = 0; //计数器,0 代表指向头指针
    while (p && j < i)
    {
        p = p->next; //将指针p移向下一个结点
        j++;         //计数器加一
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
    int j = 0;             //查找节点的指针
    while (p && j < i - 1) //找到
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
        L->data++; // 链表长度加一
        return TRUE;
    }
    else
    {
        return ERROR;
    }
}

/*
    插入数据
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
    s = p->next; //暂时保留要删除节点的指针
    p->next = s->next;
    *e = s->data;
    free(s);
    L->data--; // 链表长度减一
    return TRUE;
    /*
    e = (p->next)->data;            //将要删除的数据返回给e
    p->next = (p->next)->next;          //将第i个节点从链表中删除
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
    获取链表长度（头节点为0）
*/
void ListLength_L(LNode *L, int *e)
{
    LNode *p = L->next;
    int i = 0;
    while (p != NULL) //假如指针指向的节点不为空计数器加一
    {
        i++;
        p = p->next;
    }
    *e = i;
}

/*
    尾插法建立链表
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
    头插法建立链表
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
    合并两个链表
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
            printf("插入错误\n");
        }
    }
    ListLength_L(L, &i);
    printf("链表的长度为:%d\n", i);
    printf("头节点(其数据域存储链表的长度)\n|\nV\n");
    ListDisplay_L(L);
    printf("\n");
    // ListDelete_L(L,3,&e);
    // printf("要删除的数据是:%d\n",e);
    // printf("头节点(其数据域存储链表的长度)\n|\nV\n");
    // ListDisplay_L(L);
    // printf("\n");
    Init_L(&L2);
    CreateListHead_L(L2, 10);
    ListLength_L(L2, &i);
    printf("链表的长度为:%d\n", i);
    //    CreateList_L(L,10);
    for (i = 0; i < 10; i++)
    {
        if (ListInsertData_L(L2, i + 1, i + 1) != 1)
        {
            printf("插入错误\n");
        }
    }
    // printf("test");
    ListDisplay_L(L2);
    printf("\n");
    MergeList_e(L, L2, &K);
    ListDisplay_L(K);
    printf("\n");
    ListLength_L(K, &i);
    printf("链表的长度为:%d\n", i);
}