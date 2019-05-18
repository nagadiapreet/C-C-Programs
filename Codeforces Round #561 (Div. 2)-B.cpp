#include<bits/stdc++.h>
using namespace std;

string findWord(int n, int m)
{
	string ans="", vowels="aeiou";
	
	for(int j=0;j<m;j++)
	{
		//string temp="";
		int index = j%5;
		for(int i=0;i<n;i++)
		{
			//temp += vowels[index];
			ans += vowels[index];
			index = (index+1)%5;
		}
		//cout<<temp<<endl;
	}
	//cout<<endl;
	return ans;
}

string findFactors(int N)
{
	for(int n=5;n<N;n++)
	{
		if(N%n==0 && N/n>=5)
			return 	findWord(n, N/n);
	}
	return "-1";
}

int main()
{
	int N;
	cin>>N;
	if(N<25)
		cout<<"-1"<<endl;
	else
		cout<<findFactors(N)<<endl;
	return 0;
}
