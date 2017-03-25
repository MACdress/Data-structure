#include<iostream>
using namespace std;
class Myclass{
	private:
		int x,y;
	public:
		Myclass(){
			x=0;
			y=0;
			} 
		Myclass(int x,int y);
		void print();
};
int main(void){
	int x,y;
	Myclass::Myclass( x, y){
	 this->x=x;
	 this->y=y;
	}
	void Myclass::print(){
	  cout<<"x="<<x<<endl;
	  cout<<"y="<<y<<endl;	
	}
	return 0;
}
