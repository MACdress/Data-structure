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
void InitQueue(Queue *h)//初始化队列 
	{
	h->front=-1;
	h->rear=-1;
	h->s=50;
	}

void Enqueue(Queue *h,Person p){//入队
	h->rear=(h->rear+1)%(h->s);
	h->data[h->rear]=p;
}

int queueEmpty(Queue * h)//判断队列是否为空
{
	int a=1;
if(h->front==h->rear)
a=0;
return a;
}
Person Dequeue(Queue *h)//出队
{
	h->front=(h->front+1)%(h->s);
return  h->data[h->front];
}

Person quenuefront(Queue * h)//找到没有舞伴的第一个人 
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

	Queue Mdancer,Fdancer;//定义男舞伴队列与女舞伴队列； 
	InitQueue(&Mdancer);//初始化队列 
    InitQueue(&Fdancer);
	scanf("%d",&num);
	getchar();
	dancer=(Person *)malloc((num)*sizeof(Person));//定义跳舞的人数
	//获得跳舞的人的信息 
    for(i=0;i<num;i++)
	   {
		gets((dancer+i)->name);
		 scanf("%c",&dancer[i].sex);
		 getchar();
	}
	/*将舞伴入队*/ 
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
    scanf("%d",&n);/*获得要跳的舞曲*/ 
    getchar();
	while(n--)
	{ 
		//一男一女舞伴出队 
	while(queueEmpty(&Mdancer)&&queueEmpty(&Fdancer))
	{
       p=Dequeue(&Fdancer);
		printf("%s    ",p.name);
		p=Dequeue(&Mdancer);
		printf("%s\n",p.name);
	}
	//将没有舞伴的第一个人输出 
	if(queueEmpty(&Fdancer)) {           
		p=quenuefront(&Fdancer);
		Mdancer.front=-1;/*让队首队尾指针能够正确的指向依次循环后的队首队尾*/
		Fdancer.rear=Fdancer.front;
		Fdancer.front=Fdancer.front+1;
		Fdancer.data[Fdancer.front+1]=Fdancer.data[Fdancer.front];
	printf("%s will be the first to get a partner\n",p.name);
	}
	else if(queueEmpty(&Mdancer))		
	{
		p=quenuefront(&Mdancer);
		printf("%s will be the first to get a partner\n",p.name);
		Fdancer.front=-1;      /*让队首队尾指针能够正确的指向依次循环后的队首队尾*/
		Mdancer.rear=Mdancer.front;
		Mdancer.front=Mdancer.front+1;
		Mdancer.data[Mdancer.front+1]=Mdancer.data[Mdancer.front];
	}
	}
	return 0;
}
