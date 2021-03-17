# include <stdio.h>
# include <pthread.h>
# define arrSize 10

struct StructMax
{
    int iMax;
};

int arr[arrSize];

void *thread_search_max(void *);

int main()
{
	pthread_t tid;
    struct StructMax *st_main,*st_th;
    int FinalMax;

    st_main=(struct StructMax*)malloc(sizeof(struct StructMax));

    int iCount;
    for(iCount=0;iCount<arrSize;iCount++)
    {
        printf("Enter Value of arr[%d] :",iCount);
        scanf("%d",&arr[iCount]);
    }        
    pthread_create(&tid,NULL,thread_search_max,NULL);

    st_main->iMax=arr[0];

    for(iCount=1;iCount<arrSize/2;iCount++)
    {
        if(arr[iCount] > st_main->iMax)
        {
            st_main->iMax=arr[iCount];
        }
    }    

    pthread_join(tid,(void**)&st_th);    

    if(st_main->iMax >= st_th->iMax)
    {
        FinalMax=st_main->iMax;
    }    
    else
    {
        FinalMax=st_th->iMax;
    }


    printf("Final Max : %d \n",FinalMax);
    return 0;
}


void *thread_search_max(void *para)
{
    struct StructMax *st;
    st=(struct StructMax*)malloc(sizeof(struct StructMax));

    int iCount;
    st->iMax=arr[arrSize/2];


    for(iCount=arrSize/2 + 1;iCount<arrSize;iCount++)
    {
        if(arr[iCount] > st->iMax)
        {
            st->iMax=arr[iCount];
        }
    }    

    pthread_exit((void*)st);        
}
