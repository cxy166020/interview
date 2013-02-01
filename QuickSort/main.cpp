#include <iostream>
#include <algorithm>

void QuickSort(int* a, int len)
{
  if(len<=1)
    return;

  int* large;

  // First element of large partition
  large = NULL;

  int LargeLen = 0;
  int SmallLen = 0;

  int idx = len-1;

  for(int i=0; i<len-1; i++)
    {
      if(a[i]<a[idx])
	{
	  if(large!=NULL)
	    {
	      std::swap(*large, a[i]);
	      large++;
	    }

	  SmallLen++;
	}
      else 
	{	 
	  if(large==NULL)
	    large = &a[i];

	  LargeLen++;
	}
    }
  
  // If all elements are smaller than pivot
  if(large==NULL)
    {
      QuickSort(a, len-1);
    }
  else
    {
      // Swap pivot with first element of large partition
      std::swap(*large, a[idx]);
      large++;
      QuickSort(a, SmallLen);
      QuickSort(large, LargeLen);
    }
}

int main(void)
{
  int a[9] = {3, 5, 1, 4, 0, 9, 8, 7, 2};

  QuickSort(&a[0], 9);

  for(int i=0; i<9; i++)
    std::cout << a[i] << " ";

  std::cout << std::endl;

  return 0;
}
