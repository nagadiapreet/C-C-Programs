#include<bits/stdc++.h>
using namespace std;

long long int combination(int N)
{
	long long int a = N/2, b = N-a;
	long long int ans = a*(a-1)/2 + b*(b-1)/2;
	return ans;
}

long long int split(long long int hash[])
{
	long long int N=26;
	long long int ans = 0;
	for(long long int n=0;n<N;n++)
	{
		if(hash[n]>2)
			ans += combination(hash[n]);
	}
	return ans;
}

int main()
{
	long long int N;
	cin>>N;
	long long int hash[26]={0};
	for(long long int n=0;n<N;n++)
	{
		string temp;
		cin>>temp;
		hash[temp[0]-'a']++;
	}
	cout<<split(hash)<<endl;
	return 0;	
}
