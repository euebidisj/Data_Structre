#include <stdio.h>
#include <MALLOC.H>
#include <STDLIB.H>

#define LIST_INIT_SIZE 10 //线性表初始话长度
#define LISTINCREMENT 1   //增加步长
#define Status int        //状态 状态类型为int型
#define ElemType int      //用户定义类型
#define TRUE 1
#define FALSE 0
#define ERROR -1

typedef struct
{
    ElemType *elem;
    int length;
    int listsize;
} SqList;

/*
    初始化线性表
*/
Status InitList_Sq(SqList *P)
{
    //printf("test\n");
    P->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    //printf("mall\n");
    if (!P->elem)
        printf("test2\n"); //exit(ERROR);
    P->length = 0;
    //printf("test\n");
    P->listsize = LIST_INIT_SIZE;
    return TRUE;
}

/*
    显示线性表中的数据
    1   2   3   4
*/

void DisPlay(SqList *L)
{
    int i = 0;
    for (i = 0; i < L->length; i++)
    {
        printf("%d\t", *(L->elem + i));
    }
    printf("\n");
}

/*
    初始化默认数据,测试用
    0-9
*/

void InitData_Sq(SqList *L)
{
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        L->elem[i] = i;
        L->length++;
    }
}

/*
    在指定位置插入元素
*/
Status ListInsert_Sq(SqList *L, int i, ElemType e)
{
    //三个步骤：1 判断插入位置是否合理
    //            2 判断空间是否满，如果满增加分配
    //          3 插入
    ElemType *q;
    ElemType *p;
    if (i < 1 || i > L->length + 1)
        return ERROR;
    if (L->length >= L->listsize)
    {
        SqList P;
        P.elem = (ElemType *)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));
        if (!P.elem)
            exit(ERROR);
        L->elem = P.elem;
        L->listsize += LISTINCREMENT;
    }

    q = L->elem + (i - 1); //插入位置元素地址

    for (p = &(L->elem[L->length - 1]); p >= q; --p)
    {
        *(p + 1) = *p; //向后移动元素
        //L->elem[i+1] = L->elem[p];
    }
    *q = e;      //将元素插入
    L->length++; //线性表长度增加一
    return TRUE;
}
/*
    删除指定位置的元素
*/
Status ListDelete_Sq(SqList *L, int i, ElemType e)
{
    ElemType *q, *p;
    if (i < 1 || i > L->length)
        return ERROR;
    q = (L->elem + (i - 1));       //获取要删除位置元素指针
    e = *q;                        //输出值
    p = &(L->elem[L->length - 1]); //表尾元素的位置指针
    for (q++; q <= p; q++)         //要考虑边界问题
    {
        *(q - 1) = *(q);
    }
    --L->length;
    return TRUE;
}

void main()
{
    SqList lee;
    char c[100];
    //printf("AAAAAAAA");
    if (InitList_Sq(&lee))
    {
        printf("初始化成功\n");
    }
    else
    {
        printf("失败\n");
    }
    printf("请输入数据输入(#)结束");
    scanf("%s",c);
    while (*c != '#')
    {
        ListInsert_Sq(&lee,lee.length+1,atoi(c));
        scanf("%s",c);
    }
    
//    InitData_Sq(&lee);
    DisPlay(&lee);
    ListDelete_Sq(&lee, 1, 10);
    DisPlay(&lee);
    printf("-------------------------------------\n");
    ListInsert_Sq(&lee, 5, 555);
    DisPlay(&lee);
}