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
此时的栈是空栈
*/

Status StackInit(SqStack_link L){
    L->base = (SElemtype *) malloc(STACK_INIT_SIZE * sizeof(SElemtype));
    if (!L->base)
        return false;
    L->top = L->base;
    L->StackSize = STACK_INIT_SIZE;    
    return true;
}


Status StackInstert(SqStack_link P,SElemtype e){
    if (P->top - P->base >= P->StackSize)
    {
        P->base = (SElemtype *)realloc(P->base,(P->StackSize + STACKMAVESIZE) * sizeof(SElemtype));
        if (!P->base)
            return false;
        P->top = P->base + P->StackSize;        // 此步需特殊记忆  当top指针超过空间范围时增加空间后重新将top指针指向栈顶
        P->StackSize += STACKMAVESIZE;   
    }
    *(P->top++) = e;         //插入元素 并且top指针加一
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
        printf("这是空栈\n");
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
        printf("存储空间分配成功！\n");
    }else{
        printf("存储空间分配失败！\n");
    }
    StackDisplay(&S);
    for (i = 0; i < 10; i++)
    {
        StackInstert(&S,i);
    }
    StackDisplay(&S);
    if(GetTop(&S,&e))
        printf("此时的栈顶元素为:%d\n",e);
    else
        printf("空栈\n");
    Pop(&S);
    StackDisplay(&S);
    if(GetTop(&S,&e))
        printf("此时的栈顶元素为:%d\n",e);
    else
        printf("空栈\n");  
    printf("栈内元素个数为：%d",S.top-S.base);
}