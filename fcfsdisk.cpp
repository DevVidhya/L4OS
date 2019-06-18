#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int n,req[100],current,i,sum=0;
	cout<<"\n Enter the current position of the header : ";
	cin>>current;
	cout<<"\n Enter number of requests : ";
	cin>>n;
	cout<<"\n Enter the requests : ";
	req[0]=current;
	for(i=1;i<=n;i++)
	cin>>req[i];
	
	for(i=0;i<n;i++)
	{
		cout<<"\n"<<req[i]<<"->"<<req[i+1]<<"\t"<<abs(req[i]-req[i+1]);
		sum+=abs(req[i]-req[i+1]);
	}
	cout<<"\n Total distance head traversed = "<<sum;
}
