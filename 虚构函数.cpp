#include<iostream>
using namespace std;
class Base{
	double x,y;
	public:
		virtual double math()=0;
}; 
class D1:public Base{
	protected:
		double x,y;
	public:
		D1(){
			x=0;y=1;
		}
		 void fun(double x,double y){
			this->x=x;
			this->y=y;
			if(this->y==0) throw 0;
		}
	double math(){
		double sum,a,b;
		try{
			cout<<"���Ϊ:"<<endl;
			cin>>a>>b;
			fun(a,b);
			sum=this->x/this->y;
			cout<<sum<<endl;
		}
		catch(int e){
		if(e==0){
		cout<<"��������������"<<endl;
		cin>>a>>b;
	    fun(a,b);
	    cout<<x<<y<<endl;
	}
		}
	}
	~D1(){
		cout<<"�ɹ�"<<endl; 
	} 
};
int main(void)
{
	double x,y;
	printf("������Ҫ�������"); 
	scanf("%lf%lf",&x,&y);
	D1 d1; 
	d1.math();
	return 0;
}
