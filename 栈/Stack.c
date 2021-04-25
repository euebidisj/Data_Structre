#include <stdio.h>
#include <malloc.h>

#define STACK_INIT_SIZE 100
#define STACKMAVESIZE 10
#define SElemtype int
#define true 1
#define false 0
#define Status int


typedef struct{
    SElemtype *top;
    SElemtype *base;
    int StackSize;
}SqStack,*SqStack_link;

/*
top ->  base->  a
��ʱ��ջ�ǿ�ջ
*/

Status StackInit(SqStack_link L){
    L->base = (SElemtype *) malloc(STACK_INIT_SIZE * sizeof(SElemtype));
    if (!L->base)
        return false;
    L->top = L->base;
    L->StackSize = STACK_INIT_SIZE;    
    return true;
}


/*
    �ж�ջ�Ƿ�Ϊ��
    1.��ջ��ָ�����ջ��ָ��ʱջΪ��,����Ϊ��
*/
int GetNull(SqStack_link L){
    if(L->top == L->base){
        return 1;
    }
    return 0;
}


Status StackInstert(SqStack_link P,SElemtype e){
    if (P->top - P->base >= P->StackSize)
    {
        P->base = (SElemtype *)realloc(P->base,(P->StackSize + STACKMAVESIZE) * sizeof(SElemtype));
        if (!P->base)
            return false;
        P->top = P->base + P->StackSize;        // �˲����������  ��topָ�볬���ռ䷶Χʱ���ӿռ�����½�topָ��ָ��ջ��
        P->StackSize += STACKMAVESIZE;   
    }
    *(P->top++) = e;         //����Ԫ�� ����topָ���һ
    return true;
}


Status Pop(SqStack_link P){
    if (P->base == P->top)
    {
        return false;
    }
    P->top--;
    return true;
}

Status GetTop(SqStack_link P,SElemtype *e){
    if (P->top == P->base) return false;
    *e = *(P->top-1);
    return true;
}

void StackDisplay(SqStack_link L){
    //SqStack_link P = L;
    SElemtype *P = L->top;
    if (L->base == L->top){
        printf("���ǿ�ջ\n");
        return;
    }
    printf("|-------|\n");
    while (P != L->base)
    {
        P--;
        printf("|   %d   |\n",*P);
    }
    printf("|-------|\n");
}


void main(){
    SqStack S;
    int i,e;
    if (StackInit(&S))
    {
        printf("�洢�ռ����ɹ���\n");
    }else{
        printf("�洢�ռ����ʧ�ܣ�\n");
    }
    StackDisplay(&S);
    if(GetNull(&S)){
        printf("��ʱջΪ��!\n");
    }else{
        printf("��ʱջ��Ϊ��!\n");
    }
    for (i = 0; i < 10; i++)
    {
        StackInstert(&S,i);
    }
    StackDisplay(&S);
    if(GetNull(&S)){
        printf("��ʱջΪ��!\n");
    }else{
        printf("��ʱջ��Ϊ��!\n");
    }
    if(GetTop(&S,&e))
        printf("��ʱ��ջ��Ԫ��Ϊ:%d\n",e);
    else
        printf("��ջ\n");
    Pop(&S);
    printf("���г�ջ����\n");
    StackDisplay(&S);
    if(GetTop(&S,&e))
        printf("��ʱ��ջ��Ԫ��Ϊ:%d\n",e);
    else
        printf("��ջ\n");  
    printf("ջ��Ԫ�ظ���Ϊ��%d\n",S.top-S.base);
}