#include<bits/stdc++.h>
using namespace std;


int main(){

	
	int noOftrans;
    int totNoOfItems=20;
	
	cout<<"Enter the number of transactions?\n";
	cin>>noOftrans;
	
	ofstream fout;
	fout.open("Class1.txt");
	
	int vis[20];
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=noOftrans;i++){
		fout<<"T"<<i<<"\t\t";
		memset(vis,0,sizeof(vis));
		int bought=0;
		bought=rand()%20+1;
		
		for(int j=0;j<bought;){
			int x=rand()%20;
			if(!vis[x])
			{
				vis[x]=1;
				
				j++;
			}
		}
		for(int j=0;j<20;j++)
		if(vis[j])
		fout<<"I"<<(j+1)<<" ";
		fout<<endl;
	}
}
