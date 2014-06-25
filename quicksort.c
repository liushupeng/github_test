#include <stdio.h>
/*
 * 快速排序. 此排序是先确定第一个数的位置.在把这个数组分成两半.
 * 在先确定左边第一个数的位置.在确定右边第一个数的位置.
 * 在折半.在确定.  直到所有的数都确定位置了.
*/

static int _findPos(int *a, int low, int high)
{
  int val = a[low];

  while(low < high)
  {
    while(low < high && a[high] >= val)
    {
      high--;
    }
    a[low] = a[high];
    
    while(low < high && a[low] <= val)
    {
      low++;
    }
    a[high] = a[low];
  }
  a[low] = val;
  
  return (low);
}

extern void quickSort(int * a, int low, int high)
{
  int 	pos;
  
  if(low < high)
  {
    pos = _findPos(a, low, high);
    quickSort(a, low, pos-1);
    quickSort(a, pos+1, high);
  }
}

int main()
{
  int	i;
  int 	a[7] = {2, 5, 7, 8, 5, 4, 1};
  
  quickSort(a, 0, 6);
  for(i=0; i<7; i++)
    printf("%d    ", a[i]);
  printf("\n");
  
  return (0);
}

