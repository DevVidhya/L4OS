#include<iostream>
using namespace std;

int searchInd(int fs,int frame[10],int pg[100],int n,int pos,int arr[100])
{
	int i,lru=1000;
	
	for(i=0;i<fs;i++)
	{
		if(arr[frame[i]]<lru)
		lru=arr[frame[i]];
	}
	return lru;
}

int main()
{
	int i,j,fs,pg[100],index=0,hit=0,miss=0,n,arr[100];
	cout<<"\n Enter frame size : ";
	cin>>fs;
	cout<<"\n Enter number of references : ";
	cin>>n;
	cout<<"\n Enter page numbers : ";
	for(i=0;i<n;i++)
	cin>>pg[i];
	
	int frame[100];
	for(i=0;i<fs;i++)
	frame[i]=-1;
	
	for(i=0;i<n;i++)
	{
		if(frame[index]==-1)
		{
			frame[index]=pg[i];
			arr[pg[i]]=i;
			miss++;
			index=(index+1)%fs;
		}
		else
		{
			int avail=0;
			for(j=0;j<fs;j++)
			if(frame[j]==pg[i])
			{
				hit++;
				arr[pg[i]]=i;
				avail=1;
			}
			if(avail==1)
			continue;
			    
		    index=searchInd(fs,frame,pg,n,i+1,arr);
		    frame[index]=pg[i];
		    arr[pg[i]]=i;
		    miss++;
		}
	}
	
	cout<<"hits : "<<hit<<"\t miss : "<<miss;
}
