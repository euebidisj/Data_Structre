#include <STDIO.H>
#include <MALLOC.H>

#define MaxQsize 5
#define QElemtype int
#define Status int
#define true 1
#define false 0
#define error 0
#define overflow -1
#define ok 1

/*
    顺序队列的ADT
*/
typedef struct 
{
    QElemtype *data;    
    int front;
    int rear;
}SqQueue;

/*
    顺序队列的初始化
    1.分配空间
    2.将队头和队尾指针初始化,都指向队头
*/
Status InitLueue(SqQueue *L){
    L->data = (QElemtype *)malloc(MaxQsize*sizeof(QElemtype));
    if (!L->data)
    {
        return overflow;
    }
    L->front=L->rear = 0;
    return ok;
}

/*
    顺序表的入队
    1.判断表满 判断条件为 (L->rear+1)%maxsize == L->front
    2.放入数据
    3.将L->rear位置加一
*/
Status EnQueue(SqQueue *L,int e){
    if ((L->rear+1)%MaxQsize == L->front)
    {
        return error;
    }
    L->data[L->rear] = e;
    L->rear = (L->rear+1)%MaxQsize;
    return ok;
}

/*
    出队操作
    1.判断表空,判断条件为L->rear == L->front
    2.取出数据 将L->front减一
    3.
*/
Status DeQueue(SqQueue *L,QElemtype *e){
    if (L->front == L->rear){
        return error;
    }
    *e = L->data[L->front];
    L->front = (L->front+1)%MaxQsize;
    return ok;
}

/*
    显示循环队列的数据
    1.显示预先分配空间内的所有数据
    2.遍历
*/
void SDisPlay(SqQueue *L){
    int i;
    for (i = 0; i < MaxQsize; i++)
    {
        printf("%d ",L->data[i]);
    }
}

void main(){
    SqQueue S;
    int i,e,n;
    InitLueue(&S);
    for (i = 0; i < 5; i++){
        if (!EnQueue(&S,i+1))
        {
            printf("插入第%d个数据时失败!\n",i);
        }
    }
    SDisPlay(&S);
    puts("");
    puts("请输入要出队列的元素个数");
    scanf("%d",&n);
    for (i = 0; i < n; i++)
    {
        if (!DeQueue(&S,&e))
        {
            printf("出队失败\n");
        }else{
            printf("出队的元素为:%d\n",e);        
        }
    }
    
    // DeQueue(&S,&e);
    // printf("出队的元素为:%d\n",e);
    // DeQueue(&S,&e);
    // printf("出队的元素为:%d\n",e);
    // DeQueue(&S,&e);
    // printf("出队的元素为:%d\n",e);
    SDisPlay(&S);
    puts("");    
}