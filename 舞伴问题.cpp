#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define  MAX  50
typedef struct node{
	char name [20];
	char sex;
}Person;
typedef struct {
Person data[MAX];
int rear,front;
int s;
}Queue;
void InitQueue(Queue *h)//��ʼ������ 
	{
	h->front=-1;
	h->rear=-1;
	h->s=50;
	}

void Enqueue(Queue *h,Person p){//���
	h->rear=(h->rear+1)%(h->s);
	h->data[h->rear]=p;
}

int queueEmpty(Queue * h)//�ж϶����Ƿ�Ϊ��
{
	int a=1;
if(h->front==h->rear)
a=0;
return a;
}
Person Dequeue(Queue *h)//����
{
	h->front=(h->front+1)%(h->s);
return  h->data[h->front];
}

Person quenuefront(Queue * h)//�ҵ�û�����ĵ�һ���� 
{
	int a=h->front;
	a=(a+1)%(h->s);
return h->data[a];
}
int main(void)
{
	Person *dancer;
	int num,i,n,ni,per;
	Person p;

	Queue Mdancer,Fdancer;//��������������Ů�����У� 
	InitQueue(&Mdancer);//��ʼ������ 
    InitQueue(&Fdancer);
	scanf("%d",&num);
	getchar();
	dancer=(Person *)malloc((num)*sizeof(Person));//�������������
	//���������˵���Ϣ 
    for(i=0;i<num;i++)
	   {
		gets((dancer+i)->name);
		 scanf("%c",&dancer[i].sex);
		 getchar();
	}
	/*��������*/ 
	for(i=0;i<num;i++)
	{
		if(dancer[i].sex=='F'){
	     p=dancer[i];
		 Enqueue(&Fdancer,p);
		}
		else{
         p=dancer[i];
		 Enqueue(&Mdancer,p);
		}
		}
		Fdancer.s=Fdancer.rear+2;
		Mdancer.s=Mdancer.rear+2; 
    scanf("%d",&n);/*���Ҫ��������*/ 
    getchar();
	while(n--)
	{ 
		//һ��һŮ������ 
	while(queueEmpty(&Mdancer)&&queueEmpty(&Fdancer))
	{
       p=Dequeue(&Fdancer);
		printf("%s    ",p.name);
		p=Dequeue(&Mdancer);
		printf("%s\n",p.name);
	}
	//��û�����ĵ�һ������� 
	if(queueEmpty(&Fdancer)) {           
		p=quenuefront(&Fdancer);
		Mdancer.front=-1;/*�ö��׶�βָ���ܹ���ȷ��ָ������ѭ����Ķ��׶�β*/
		Fdancer.rear=Fdancer.front;
		Fdancer.front=Fdancer.front+1;
		Fdancer.data[Fdancer.front+1]=Fdancer.data[Fdancer.front];
	printf("%s will be the first to get a partner\n",p.name);
	}
	else if(queueEmpty(&Mdancer))		
	{
		p=quenuefront(&Mdancer);
		printf("%s will be the first to get a partner\n",p.name);
		Fdancer.front=-1;      /*�ö��׶�βָ���ܹ���ȷ��ָ������ѭ����Ķ��׶�β*/
		Mdancer.rear=Mdancer.front;
		Mdancer.front=Mdancer.front+1;
		Mdancer.data[Mdancer.front+1]=Mdancer.data[Mdancer.front];
	}
	}
	return 0;
}
