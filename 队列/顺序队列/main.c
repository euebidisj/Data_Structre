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
    ˳����е�ADT
*/
typedef struct 
{
    QElemtype *data;    
    int front;
    int rear;
}SqQueue;

/*
    ˳����еĳ�ʼ��
    1.����ռ�
    2.����ͷ�Ͷ�βָ���ʼ��,��ָ���ͷ
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
    ˳�������
    1.�жϱ��� �ж�����Ϊ (L->rear+1)%maxsize == L->front
    2.��������
    3.��L->rearλ�ü�һ
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
    ���Ӳ���
    1.�жϱ��,�ж�����ΪL->rear == L->front
    2.ȡ������ ��L->front��һ
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
    ��ʾѭ�����е�����
    1.��ʾԤ�ȷ���ռ��ڵ���������
    2.����
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
            printf("�����%d������ʱʧ��!\n",i);
        }
    }
    SDisPlay(&S);
    puts("");
    puts("������Ҫ�����е�Ԫ�ظ���");
    scanf("%d",&n);
    for (i = 0; i < n; i++)
    {
        if (!DeQueue(&S,&e))
        {
            printf("����ʧ��\n");
        }else{
            printf("���ӵ�Ԫ��Ϊ:%d\n",e);        
        }
    }
    
    // DeQueue(&S,&e);
    // printf("���ӵ�Ԫ��Ϊ:%d\n",e);
    // DeQueue(&S,&e);
    // printf("���ӵ�Ԫ��Ϊ:%d\n",e);
    // DeQueue(&S,&e);
    // printf("���ӵ�Ԫ��Ϊ:%d\n",e);
    SDisPlay(&S);
    puts("");    
}