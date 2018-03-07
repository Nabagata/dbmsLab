#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
#include<cstdlib>
#include<string>
#include<vector>
#include<map>
using namespace std;

struct triplets
{
	int a, b, c;
	int count = 0;
};
int main()
{
	ifstream fin;
	fin.open("Minimumcount.txt");
	string lin;
	vector<vector<int> > v;
	if(fin) cout << "file exists" << endl;
	while(fin)
	{
		getline(fin, lin);
		char arr[20];
		int count = 0;
		while(lin[count]!=' ')
		{
			arr[count] = lin[count];
			count++;
		}
		arr[count] ='\0';
		count++;
		int k = 0;
		char arr2[20];
		while(lin[count]!= ' ' && lin[count]!='\t')
		{
			arr2[k] = lin[count];
			k++;
			count++;
		}
		arr2[k] ='\0';
		char arr3[3];
		char arr4[3];
		{
			int k = 1;
			while(arr[k])
			{
				arr3[k-1] = arr[k];
				k++;
			}
			arr3[k-1] = '\0';
			k = 1;

			while(arr2[k])
			{
				arr4[k-1] = arr2[k];
				k++;
			}
			arr4[k-1] = '\0';
			int a = atoi(arr3);
			int b = atoi(arr4);
			cout << arr3 << " " <<arr4 << " ";
			cout << a << " " << b << endl;
			v[a].push_back(b);	
		}
		cout << "stuck in repeated loop?" << endl;
	}
	for(int i = 0; i < 21; i++)
	{
		cout << i << " ";
		for(int j = 0; j < v[i].size(); j++)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
