typedef struct node//构建一个结构体ElemSN存储整数值和地址。 
{
	int data;
	struct node *next;
 } ElemSN;
 ElemSN * CreatLink(int a[],int n)//正向构建一个链表，将数据域的值存入其中 
 {
 	ElemSN *h,*t,*p;
 	h=NULL;
 	int i;
 	for(i=0;i<n;i++)
 	{
 		p=(ElemSN*)malloc(sizeof(ElemSN));//在空间取一个大小为ElemsN的单元，将指针p指在上面！ 
 		p->data=a[i];//数据域赋值； 
 		p->next=NULL;//指针域赋控，确保其有尾节点。 
 		if(!h) 
 		h=t=p;//如果是头结点，将头指针指在上面。将一个变量指针也只在上面，防止下次跑p时地址丢失。 
 		else
 		t=t->next=p;
	 }
	 return h;
 }
 void PrintLink(ElemSN *h)//输出链表中的值 
 {
 	ElemSN *p;
 	for(p=h;p!=NULL;p=p->next)//遍历链表 
 	printf("%5d",p->data);
 	printf("\n");
 }
 void Exchange(ElemSN *h)//将链表中的最大值与头结点的值交换 
 {
 	ElemSN *p,*pm;
 	int t;
 	pm=h;
 	for(p=h->next;p;p=p->next){
     if(pm->data<p->data)
     pm=p;
 }
 	if(pm!=h){
	t=pm->data;
 	pm->data=h->data;
 	h ->data=t;
 }
 } 
 ElemSN * PreCreatLink(int a[],int n)//逆向构建链表 
{
	int i;
	ElemSN *p,*h;
	h=NULL;//将空链表看成链表的头结点，将头指针指上去； 
	for(i=n-1;i>-1;i--){
		p=(ElemSN *)malloc(sizeof(ElemSN));// 在空间取一个大小为ElemsN的单元，将指针p指在上面！
		p->data=a[i];// 数据域赋值；
		p->next=h;//将链表之间的链接上 
		h=p;//将头指针指向p 
	}
	return h;
}
ElemSN * PreDeleKty(ElemSN *h,int kty)//删除关键字kty所在的结点 
 {
 	ElemSN *p,*q;
 	p=h;
 	while(p){
 		if(p->data-kty){//判断是否等于关键字kty，若果不是，跑链表。 
 			q=p;
 			p=p->next;
		 }
		 else{
		 	if(p==h){//是否在头结点，以及删除方法 
			   h=h->next;
			   free(p);
			   p=h;
		}
		 	else{
			  q->next=p->next;
			  free(p);
			  p=q->next;
		 }
		 }
	 }
	 return h;
 }
 ElemSN * FindKey(ElemSN *h,int key)//输出关键字kty所在节点的地址 
 {
 	ElemSN *p;
 	for(p=h;p&&(p->data)-key;p=p->next);
 	return p;
 }
 ElemSN * PrePrintLink(ElemSN *h)//逆制输出链表 
{
	ElemSN *p,*q;
	q=h;
	p=h->next;
	while(p){
		q->next=p->next; 
		p->next=h;
		h=p;
		p=q->next;
	}
	return h;
}
//带头结点的链表建链方式 
ElemSN * KCreatLink(int data[],int n){
	ElemSN *h,*t;
	int i;
	h=t=(ElemSN *)malloc(sizeof(ElemSN) );
	t->next=NULL;
	for(i=0;i<n;i++)
	{
		t=t->next=(ElemSN *)malloc(sizeof(ElemSN) );
		t->data=data[i];
		t->next=NULL;
	}
	return h;
}
void  KPrintLink(ElemSN *h){
	ElemSN *p;
	for(p=h->next;p;p=p->next){
		printf("%5d",p->data);
	}
}
void DeleteLink(ElemSN *h)//删除链表 
{
	ElemSN *temp;
	while(h){
		temp=h;
		h=h->next;
		free(temp);
	}
}
