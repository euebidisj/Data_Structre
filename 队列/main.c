#include <STDIO.H>
#include <MALLOC.H>

#define QElemtype int
#define Status int
#define true 1
#define false 0
#define error 0
#define overflow -1
#define ok 1


/*
    链式队列的ADT
*/
typedef struct QNode{
    QElemtype data;
    struct QNode *next;
}QNode,*QueuePtr;
typedef struct {
    QNode *front;
    QNode *rear;
}LinkQueue;



/*
    队列的初始化
    1.创建一个头节点并将队列头和尾指向它
*/
Status InitQueue(LinkQueue *Q){
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q->front)
        return overflow;
    Q->front->next = NULL;
    return ok;
}




/*
    队列的销毁
    1.释放每一个节点
*/
Status Destroyqueue(LinkQueue *Q){
    while(Q){
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
    return ok;
}



/*
    入队操作
    1.生成一个节点,放到队尾
        将节点的指针域赋值NULL
    2.将要入队列的值赋给节点的数据域
*/
Status EnQueue(LinkQueue *Q,QElemtype e){
    QueuePtr P = (QueuePtr)malloc(sizeof(QNode));
    if (!P)
        return overflow;
    P->data = e;
    P->next = NULL;
    Q->rear->next = P;
    Q->rear = P;
    return ok;
}


/*
    出队操作
    1.直接使用头节点读取要出队的元素
    2.将头节点的指针域指向下一个节点,
    3.释放节点
*/

Status DeQueue(LinkQueue *Q,QElemtype *e){
    QueuePtr P = Q->front->next;   //将指针指向头节点队头,释放节点用 
    if (Q->front == Q->rear)
        return error;
    *e = P->data;
    Q->front->next = P->next;
    if (Q->rear == P)
        Q->rear=Q->front;
    free(P);
    return ok;
}

/*
    显示队列内容到屏幕
    1.指针不为NULL就显示
*/
void DisPlay(LinkQueue *Q){
    QueuePtr P = Q->front->next;
    while (P){
        printf(" - %d",P->data);
        P = P->next;
    }
}



void main(){
    LinkQueue Q;
    int i,n,e;
    if (!InitQueue(&Q))
        puts("存储空间分配失败!");
    for (i = 0; i < 10; i++)
        EnQueue(&Q,i);
    DisPlay(&Q);
    printf("\n请输入要出队列次数:");
    scanf("%d",&n);
    for (i = 0; i < n; i++){
        if(!DeQueue(&Q,&e)){
            puts("队列已空");
            break;
        }    
        else
            printf("第%d次出队列的元素值为%d\n",i+1,e);
    }
}
