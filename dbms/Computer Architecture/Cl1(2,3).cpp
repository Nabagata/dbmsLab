#include<bits/stdc++.h>
using namespace std;

int main()
{
	ifstream fin;
	fin.open("Class1.txt");
	
	ofstream fout;
	fout.open("Class(2).txt");
	
	string line;
	int totNoOfItems=20;
	map<int,vector<string> > m;
	getline(fin,line);
	cout<<line<<endl;
	while(fin)
	{
		getline(fin,line);
		cout<<line<<endl;
		string str="";
		int i=0,l=line.length();
		string p;
		while(i<l)
		{
			cout<<str<<endl;
			if(line[i]==' '||line[i]=='	')
			{
				if(str.length()>0)
				{
					if(str[0]=='I')
					{
						int op=atoi(str.substr(1).c_str());
						m[op].push_back(p);
					}
				else
				p=str;
				str="";
				}
			}
			else str+=line[i];
		i++;
		}
	}
	map<int,vector<string> > ::iterator it=m.begin();
	while(it!=m.end())
	{
		fout<<"I";
		fout<<(*it).first<<"			";
		for(int i=0;i<m[(*it).first].size();i++)
		fout<<m[(*it).first][i]<<",";
		fout<<"\n";
		it++;
	}
	fout.close();
	fout.open("Class1(3).txt");
	it=m.begin();
		while(it!=m.end())
		{
			fout<<(*it).first<<"				";
			fout<<m[(*it).first].size();
			fout<<"\n";
			it++;
		}
		fout.close();
		
	return 0;
}
