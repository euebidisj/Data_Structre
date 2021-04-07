#include <stdio.h>
#include <MALLOC.H>
#include <STDLIB.H>

#define LIST_INIT_SIZE 10 //���Ա��ʼ������
#define LISTINCREMENT 1   //���Ӳ���
#define Status int        //״̬ ״̬����Ϊint��
#define ElemType int      //�û���������
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
    ��ʼ�����Ա�
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
    ��ʾ���Ա��е�����
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
    ��ʼ��Ĭ������,������
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
    ��ָ��λ�ò���Ԫ��
*/
Status ListInsert_Sq(SqList *L, int i, ElemType e)
{
    //�������裺1 �жϲ���λ���Ƿ����
    //            2 �жϿռ��Ƿ�������������ӷ���
    //          3 ����
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

    q = L->elem + (i - 1); //����λ��Ԫ�ص�ַ

    for (p = &(L->elem[L->length - 1]); p >= q; --p)
    {
        *(p + 1) = *p; //����ƶ�Ԫ��
        //L->elem[i+1] = L->elem[p];
    }
    *q = e;      //��Ԫ�ز���
    L->length++; //���Ա�������һ
    return TRUE;
}
/*
    ɾ��ָ��λ�õ�Ԫ��
*/
Status ListDelete_Sq(SqList *L, int i, ElemType e)
{
    ElemType *q, *p;
    if (i < 1 || i > L->length)
        return ERROR;
    q = (L->elem + (i - 1));       //��ȡҪɾ��λ��Ԫ��ָ��
    e = *q;                        //���ֵ
    p = &(L->elem[L->length - 1]); //��βԪ�ص�λ��ָ��
    for (q++; q <= p; q++)         //Ҫ���Ǳ߽�����
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
        printf("��ʼ���ɹ�\n");
    }
    else
    {
        printf("ʧ��\n");
    }
    printf("��������������(#)����");
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