#include<iostream>
using namespace std;
class Base{
	private: int x,y;
	public:
		Base(){
			x=0;
			y=0;
		}
		Base(int x,int y)
		{
			this->x=x;
			this->y=y; 
		}
	virtual	void fun()=0;
	~Base(){
		cout<<"Base.Des"<<endl;
	}
};
class  D1:public Base{
	private:
		int z;
		public:
	void fun(){
		cout<<"D1.fun"<<endl;
	}		
};
class D2:public Base{
	private:
		int z;
	public:
		void fun()
		{
			cout<<"D2.fun"<<endl;
		}
};
int main(void)
{
	Base *pb;
	pb=new D2;
	pb->fun();
	delete pb;
	return 0;
}

