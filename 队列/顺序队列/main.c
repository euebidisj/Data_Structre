#include <STDIO.H>
#include <MALLOC.H>

#define MaxQsize 100
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
    �ж϶����Ƿ�Ϊ��
    1.�ж�����L->rear == L->front
*/
int GetNull(SqQueue *L){
    if(L->rear == L->front){
        return 1;
    }
    return 0;
}


/*
    ��ʾ��������пռ��ڵ���������
    1.����
*/
void SDisPlay(SqQueue *L){
    int i;
    for (i = 0; i < MaxQsize; i++)
    {
        printf("%d ",L->data[i]);
    }
}

/**
 *  ��ʾ�����е�����
 *  1.����ָ��tapָ���ͷ,�ƶ�ָ����ʾ����.
 *  2.�ж����ݶ��в�Ϊ��
*/
Status SSDisPlay(SqQueue *L){
    int tap=L->front;
    while(tap !=L->rear){
        printf("%d ",L->data[tap]);
        tap = (tap+1)%MaxQsize;
    }
    return true;
}




void main(){
    SqQueue S;
    int i,e,n;
    char c[100];

    InitLueue(&S);
    puts("��ʼ������!");
    if (GetNull(&S))
        printf("��ʱ����Ϊ��!\n");
    else
        printf("��ʱ���зǿ�!\n");

    printf("��������������(#)����");
    scanf("%s",c);
    while (*c != '#'){
        EnQueue(&S,atoi(c));
        scanf("%s",c);
    }
    printf("�����е�����:");
    SSDisPlay(&S);
    puts("");

    puts("������Ҫ�����е�Ԫ�ظ���:");
    scanf("%d",&n);
    for (i = 0; i < n; i++)
    {
        if (!DeQueue(&S,&e))
        {
            printf("�����ѿ�!\n");
        }else{
            printf("��%d�γ��ӵ�Ԫ��Ϊ:%d\n",i+1,e);        
        }
    }
    printf("�����е�����:");
    SSDisPlay(&S);
    puts("");    
}