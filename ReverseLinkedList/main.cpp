#include <iostream>
#include <vector>

struct node
{
  node* next;
  int id;
};

node* ReverseList(node* root)
{
  std::vector<node*> buffer;

  node* ptr = root;

  while(ptr!=NULL)
    {
      buffer.push_back(ptr);

      ptr = ptr->next;
    }
  
  ptr = buffer.back();
  root = ptr;

  while(buffer.size()!=0)
    {
      buffer.pop_back();

      if(buffer.size()==0)
	ptr->next = NULL;
      else
	ptr->next = buffer.back();

      ptr = buffer.back();
    }

  return root;
}

int main(void)
{
  node* root = new node();

  node* ptr = root;

  const int ListLength = 10;

  for(int i=0; i<ListLength; i++)
    {
      ptr->id = i;

      if(i!=ListLength-1)
	{
	  ptr->next = new node();
	  ptr = ptr->next;
	}
      else
	ptr->next = NULL;
    }

  ptr = root;
  for(int i=0; i<ListLength; i++)
    {
      std::cout << ptr->id << " ";
      
      if(i!=ListLength-1)
	ptr = ptr->next;
    }
  std::cout << std::endl;

  ptr = ReverseList(root);

  for(int i=0; i<ListLength; i++)
    {
      std::cout << ptr->id << " ";
      
      if(i!=ListLength-1)
	ptr = ptr->next;
    }
  std::cout << std::endl;  
}
