#include<iostream>
using namespace std;
class PX{
	private:
			int *a;
	        int n;
	public:
		PX(int *b,int n){
			a=new int[n+1];
			for(int i=1;i<=n;i++){
				a[i]=b[i];
			}
			this->n=n; 
		}
		void ZCP(){
			int i,j;
			for(i=2;i<=n;i++){
				a[0]=a[i];
				for(j=i-1;j>=0;j--){
					if(a[j]>a[0]){
						a[j+1]=a[j];
					}
					else{
						a[j+1]=a[0];
						break;
					}
				}
			}
			cout<<"	ZCP.des"<<endl;
		}
		void ZXP(){
			int i,j,temp;
			for(i=1;i<n-1;i++){
				a[0]=i;
				for(j=i;j<=n;j++){
					if(a[a[0]]>a[j]){
						a[0]=j;
					}
				}
				temp=a[a[0]];
				a[a[0]]=a[i];
				a[i]=temp;
			}
			cout<<"ZXP.des"<<endl;
		}
		void DP(){
			int end,tag,p;
			end=n;
			while(end>1){
				while(1){
					tag=0;
					p=end/2;
					while(p){
						if(a[p]<a[2*p]){
							a[0]=a[p];
							a[p]=a[2*p];
							a[2*p]=a[0];
							tag=1;
						}
						if(2*p+1<=end&&a[p]<a[2*p+1]){
							a[0]=a[p];
							a[p]=a[2*p+1];
							a[2*p+1]=a[0];
							tag=1;
						} 
						p--;
					}
					if(!tag){
						break;
					}
				}
				a[0]=a[1];
				a[1]=a[end];
				a[end]=a[0];
				end--;
			}
			cout<<"DP.des"<<endl;
		}
		void GB(int left,int right,int middle){
			int *type,i,j,k;
			a[0]=(right-left+1);
			type=new int[a[0]+1];
			for(i=left,j=middle+1,k=1;i<=middle&&j<=right;){
				if(a[i]<=a[j]){
					type[k++]=a[i];
					i++;
				}
				else{
					type[k++]=a[j];
					j++;
				}
			}
			while(i<=middle){
				type[k++]=a[i++];
			}
			while(j<=right){
				type[k++]=a[j++];
			}
			for(i=left,j=1;i<=right;i++){
				a[i]=type[j++];
			}
			delete []type;
			type=NULL;
		}
		void GBPX(int left,int right){
			if(left<right){
				int middle=(left+right)/2;
				GBPX(left,middle);
				GBPX(middle+1,right);
				GB(left,right,middle);
			}
		}
		void GBPX0(){
			GBPX(1,n);
			Print();
		}
		void KP(int left,int right){
			if(right-left>0){
				int i,j,temp;
				i=left;
				j=right;
				a[0]=a[right];
				while(i<j){
					while(i<j&&a[i]<=a[0]) i++;
					a[j]=a[i];
					while(i<j&&a[j]>a[0]) j--;
					a[i]=a[j];
				}
				a[i]=a[0];
				Print();
				KP(left,i-1);
				KP(i+1,right);
			}
			Print();
		}
		void Print(){
			for(int i=1;i<=n;i++){
				cout<<a[i]<<" ";
			}
			cout<<endl;
		}
		~PX(){
			delete a;
			a=NULL;
			cout<<"PX.des"<<endl;
		}
};
int main(void){
	int n;
	cin>>n;
	int * a=new int[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	PX b(a,n);
	b.GBPX0();
	delete a;
	a=NULL;
	return 0;
}