#include<iostream>
using namespace std;
class  Base{
	protected:
		int x,w;
	public:
		Base(){
			x=0;
		}
	    Base(int x,int w){
	    	this->x=x;
	    	this->w=w;
		}
		void print(){
			cout<<"x="<<x<<endl;
			cout<<"w="<<w<<endl;
		}
		~Base(){
			cout<<"Base.des"<<endl; 
		}
};
class  DA:public Base{
	private:
		int y;
	public:
		DA(){
			y=0;
		}
		DA(int y):Base(y+3,y-1){
			this->y=y;
		}
		void print(){
		    cout<<"x="<<x<<endl;
			cout<<"y="<<y<<endl;
		} 
		~DA(){
			cout<<"DA.des"<<endl;
		}
};
class DB:public Base{
	private:
		int z;
	public:
		DB(){
			z=0;
		}
		DB(int z):Base(z+1,z+4){
			this->z=z;
		}
		void print(){
			Base::print();
			cout<<"z="<<z<<endl;
		}
		~DB(){
			cout<<"DB.des"<<endl;
		}
};
int main(void)
{
	DA *pda=new DA();
	DB *pdb=new DB(5);
	pda->print();
	pdb->print();
	delete pda;
	delete pdb;
	return 0;
}
