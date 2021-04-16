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
    ��ʽ���е�ADT
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
    ���еĳ�ʼ��
    1.����һ��ͷ�ڵ㲢������ͷ��βָ����
*/
Status InitQueue(LinkQueue *Q){
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q->front)
        return overflow;
    Q->front->next = NULL;
    return ok;
}




/*
    ���е�����
    1.�ͷ�ÿһ���ڵ�
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
    ��Ӳ���
    1.����һ���ڵ�,�ŵ���β
        ���ڵ��ָ����ֵNULL
    2.��Ҫ����е�ֵ�����ڵ��������
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
    ���Ӳ���
    1.ֱ��ʹ��ͷ�ڵ��ȡҪ���ӵ�Ԫ��
    2.��ͷ�ڵ��ָ����ָ����һ���ڵ�,
    3.�ͷŽڵ�
*/

Status DeQueue(LinkQueue *Q,QElemtype *e){
    QueuePtr P = Q->front->next;   //��ָ��ָ��ͷ�ڵ��ͷ,�ͷŽڵ��� 
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
    ��ʾ�������ݵ���Ļ
    1.ָ�벻ΪNULL����ʾ
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
        puts("�洢�ռ����ʧ��!");
    for (i = 0; i < 10; i++)
        EnQueue(&Q,i);
    DisPlay(&Q);
    printf("\n������Ҫ�����д���:");
    scanf("%d",&n);
    for (i = 0; i < n; i++){
        if(!DeQueue(&Q,&e)){
            puts("�����ѿ�");
            break;
        }    
        else
            printf("��%d�γ����е�Ԫ��ֵΪ%d\n",i+1,e);
    }
}
