#include<iostream>
using namespace std;

int rem(int f[10],int n)
{
	int t=0;
	for(int i=0;i<n;i++)
	{
		if(f[i]==0)
		{
			t=1;
			break;
		}
	}
	return t;
}

int main()
{
	int i,j,n,m,alloc[10][10],max[10][10],avail[10],need[10][10],f[10],ans[10],index=0,count=0;
	cout<<"\n Enter number of processes : ";
	cin>>n;
	cout<<"\n Enter number of resources : ";
	cin>>m;
	cout<<"\n Enter already allocated : \n";
	for(i=0;i<n;i++)
	for(j=0;j<m;j++)
	cin>>alloc[i][j];
	cout<<"\n Enter maximum that can be allocated : \n";
	for(i=0;i<n;i++)
	for(j=0;j<m;j++)
	cin>>max[i][j];
	cout<<"\n Enter number of resources available : ";
	for(i=0;i<m;i++)
	cin>>avail[i];
	for(i=0;i<n;i++)
	for(j=0;j<m;j++)
	need[i][j]=max[i][j]-alloc[i][j];
	
	for(i=0;i<n;i++)
	f[i]=0;
	 
	int check; 
	while(rem(f,n))
	{
		count++;
		if(count>20)
		{
			cout<<"\n no safe allocation ";
			break;
		}
		for(i=0;i<n;i++)
		{
			if(f[i]==0)
			{
				check=1;
				for(j=0;j<m;j++)
				{
					if(need[i][j]>avail[j])
					check=0;
					break;
				}
				if(check==1)
				{
					ans[index++]=i;
					for(j=0;j<m;j++)
					avail[j]+=alloc[i][j];
					f[i]=1;
				}
			}
		}
	}
	
	for(i=0;i<index;i++)
	cout<<ans[i]<<" ";
		
}
