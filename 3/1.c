#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
  

#define max 16 

#define Th_max 4 
  

int a[max] = { 1, 5, 7, 10, 12, 14, 15, 18, 20, 22, 25, 27, 300, 64, 110, 220 }; 
  


int thread_no = 0; 

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
}
  
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    
    int i = (low - 1);  
  
    for (int j = low; j <= high- 1; j++) 
    { 
        
        if (arr[j] <= pivot) 
        { 
            i++;    
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        
        int pi = partition(arr, low, high); 
  
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

void* quickSortth(void* arg) 
{ 
    int num=thread_no++;

    int low=num*(max/4);
    int high=(num+1)*(max/4)-1;

    quickSort(a,low,high);

} 
  

int main() 
{ 
    
    int i; 
    pthread_t threads[Th_max]; 
  
    
    for (i = 0; i < Th_max; i++) 
        pthread_create(&threads[i], NULL, 
                       quickSortth, (void*)NULL); 
  
    for (i = 0; i < Th_max; i++) 
        pthread_join(threads[i], NULL); 
  
    
  
    for(int i=0;i<max;i++)
        printf("%d ",a[i]);
	
	printf("\n");	
  
    return 0; 
} 
