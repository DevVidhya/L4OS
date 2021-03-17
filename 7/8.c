#include<stdio.h>


void scan_algorithm(int left[], int right[], int count, int limit)
{
      int arr[20];
      int x = count - 1, y = count + 1, c = 0, d = 0, j;
      while(x > -1)
      { 
         
            arr[d] = left[x];
            x--;
            d++;
      }
      arr[d] = 0;
      while(y < limit + 1)
      {
            arr[y] = right[c];
            c++;
            y++;
      }
      printf("\nScanning Order:\n");
      for(j = 0; j < limit + 1; j++)
      {
            printf("%d\n", arr[j]);
      }
}

void division(int elements[], int limit, int disk_head)
{
      int count = 0, p, q, m, x;
      int left[20], right[20];
      for(count = 0; count < limit; count++)
      {
            if(elements[count] > disk_head)
            {
                 
                  break;
            }
      }
      
      q = 1;
      p = 0;
      m = limit;
      left[0] = elements[0];
      
      while(q < count)
      {
            
            left[q] = elements[q];
            
            q++;
            
      }
      x = count;
      while(x < m)
      {
            right[p] = elements[x];
            
            p++;
            x++;
      }
      scan_algorithm(left, right, count, limit);
}

void sorting(int elements[], int limit)
{
      int location, count, j, temp, small;
      for(count = 0; count < limit - 1; count++)
      {
            small = elements[count];
            location = count;
            for(j = count + 1; j < limit; j++)
            {
                  if(small > elements[j])
                  {
                        small = elements[j];
                        location = j;
                  }
            }
            temp = elements[location];
            elements[location] = elements[count];
            elements[count] = temp;
      }
}

int main()
{
      int count, disk_head, elements[20], limit;
      printf("Enter total number of locations: ");
      scanf("%d", &limit);
      printf("Enter position of disk head: ");
      scanf("%d", &disk_head);
      printf("Enter elements of disk head queue: \n");
      for(count = 0; count < limit; count++)
      {
            scanf("%d", &elements[count]);
      }
      sorting(elements, limit);
      division(elements, limit, disk_head);
     
      return 0;
}
