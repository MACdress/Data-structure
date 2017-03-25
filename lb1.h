typedef struct node//����һ���ṹ��ElemSN�洢����ֵ�͵�ַ�� 
{
	int data;
	struct node *next;
 } ElemSN;
 ElemSN * CreatLink(int a[],int n)//���򹹽�һ���������������ֵ�������� 
 {
 	ElemSN *h,*t,*p;
 	h=NULL;
 	int i;
 	for(i=0;i<n;i++)
 	{
 		p=(ElemSN*)malloc(sizeof(ElemSN));//�ڿռ�ȡһ����СΪElemsN�ĵ�Ԫ����ָ��pָ�����棡 
 		p->data=a[i];//������ֵ�� 
 		p->next=NULL;//ָ���򸳿أ�ȷ������β�ڵ㡣 
 		if(!h) 
 		h=t=p;//�����ͷ��㣬��ͷָ��ָ�����档��һ������ָ��Ҳֻ�����棬��ֹ�´���pʱ��ַ��ʧ�� 
 		else
 		t=t->next=p;
	 }
	 return h;
 }
 void PrintLink(ElemSN *h)//��������е�ֵ 
 {
 	ElemSN *p;
 	for(p=h;p!=NULL;p=p->next)//�������� 
 	printf("%5d",p->data);
 	printf("\n");
 }
 void Exchange(ElemSN *h)//�������е����ֵ��ͷ����ֵ���� 
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
 ElemSN * PreCreatLink(int a[],int n)//���򹹽����� 
{
	int i;
	ElemSN *p,*h;
	h=NULL;//���������������ͷ��㣬��ͷָ��ָ��ȥ�� 
	for(i=n-1;i>-1;i--){
		p=(ElemSN *)malloc(sizeof(ElemSN));// �ڿռ�ȡһ����СΪElemsN�ĵ�Ԫ����ָ��pָ�����棡
		p->data=a[i];// ������ֵ��
		p->next=h;//������֮��������� 
		h=p;//��ͷָ��ָ��p 
	}
	return h;
}
ElemSN * PreDeleKty(ElemSN *h,int kty)//ɾ���ؼ���kty���ڵĽ�� 
 {
 	ElemSN *p,*q;
 	p=h;
 	while(p){
 		if(p->data-kty){//�ж��Ƿ���ڹؼ���kty���������ǣ������� 
 			q=p;
 			p=p->next;
		 }
		 else{
		 	if(p==h){//�Ƿ���ͷ��㣬�Լ�ɾ������ 
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
 ElemSN * FindKey(ElemSN *h,int key)//����ؼ���kty���ڽڵ�ĵ�ַ 
 {
 	ElemSN *p;
 	for(p=h;p&&(p->data)-key;p=p->next);
 	return p;
 }
 ElemSN * PrePrintLink(ElemSN *h)//����������� 
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
//��ͷ������������ʽ 
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
void DeleteLink(ElemSN *h)//ɾ������ 
{
	ElemSN *temp;
	while(h){
		temp=h;
		h=h->next;
		free(temp);
	}
}
