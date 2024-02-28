using namespace std;
#include<iostream>
#include<iomanip>
int main(){
//	snake ladder board

	int i,j;
	int num=100;
	
	for(i=1;i<=10;i++){
//--------------------------------for first row------------------------------------------------
		if(i==1){
			for(j=1;j<=10;j++){
				cout<<setw(4)<<num<<" ";							//num=100,99,98,.....91   
				num--;									// but(exit value of num=90)
			}	
			cout<<"\n";
		}
//-------------------------------for even rows---------------------------------------
		if(i%2==0){									
			num=num-9;									//num=81
			for(j=1;j<=10;j++){
				cout<<setw(4)<<num<<" ";
				num++;									//exit value of num=91
			}
			cout<<"\n";
		}
//-------------------------------for odd rows----------------------------------------
		else if(i%2!=0 &&i!=1 ){						
			num=num-11;							//num=80
			for(j=1;j<=10;j++){
				cout<<setw(4)<<num<<" ";
				num--;
			}
		cout<<"\n";
		}	
	}
	return 0;	
}