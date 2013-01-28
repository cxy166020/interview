#include <iostream>
#include <algorithm>
#include <string>
#include <map>

// Manually permute a string
void PermuteString(std::string str, 
		   int NextIdx,
		   int StrLength,
		   std::map<std::string, int>& StrMap)
{
  if(NextIdx>=StrLength)
    return;

  for(int i=NextIdx; i<StrLength; i++)
    {
      std::string NewStr = str;
      std::swap(NewStr[NextIdx], NewStr[i]);
      
      if(StrMap.count(NewStr)==0)
	{
	  StrMap[NewStr] == 1;
	  std::cout << NewStr << std::endl;
	  PermuteString(NewStr, NextIdx+1, StrLength, StrMap);
	}
    }
}

int main(void)
{
  std::string str1 = "cbca";
  std::string str2 = str1;

  int StrLength = str1.length();
  
  // A lazy way, use next_permutation, but we need to sort the string first
  std::cout << "A lazy way:" << std::endl; 
  std::sort(str1.begin(), str1.end());
  
  do 
    {
      std::cout << str1 << std::endl;
    }
  while(std::next_permutation(str1.begin(), str1.end()));
  
  std::cout << "\n\n";

  // Now we do this manually
  std::sort(str2.begin(), str2.end());
  // The map stores all existing permutations
  std::map<std::string, int> StrMap;
 
  PermuteString(str2, 0, StrLength, StrMap);
}
