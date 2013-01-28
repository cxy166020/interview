#include <iostream>
#include <vector>

struct node
{
  node* next;
  node* arb;

  int id;
};

//          ___________________
//   ______|______  ____       |
//  |      |     |  |   |      |
//  |     \|/   \|/\|/  |      |
//  1 ---> 2 --->3 ---> 4 ---> 5 
// /|\    |/|\   |            /|\|
//  |_____| |    |_____________| |			
//          |____________________|
//
int main(void)
{
  node n1, n2, n3, n4, n5;

  n1.id = 1; n1.next = &n2;  n1.arb = &n3;
  n2.id = 2; n2.next = &n3;  n2.arb = &n1;
  n3.id = 3; n3.next = &n4;  n3.arb = &n5;
  n4.id = 4; n4.next = &n5;  n4.arb = &n3;
  n5.id = 5; n5.next = NULL; n5.arb = &n2;

  node* root = &n1;

  // To copied lists, the only visible variable is root
  
  node* ptr = root;

  node* croot = new node();
  node* cptr = croot;

  std::vector<node*> NextBackup;

  while(ptr!=NULL)
    {
      cptr->id = ptr->id;
      
      if(ptr->next!=NULL)
	{
	  cptr->next = new node();
	  cptr = cptr->next;
	}
      else
	cptr->next = NULL;

      NextBackup.push_back(ptr->next);

      ptr = ptr->next;
    }

  // Now connect all original list's next pointer to its copy
  ptr  = root;
  cptr = croot;
  
  do
    {
      node* temp = ptr->next;

      ptr->next = cptr;
      cptr->arb = ptr;
      
      ptr  = temp;
      cptr = cptr->next;      
    }
  while(cptr!=NULL);


  // Now copy arb pointer
  cptr = croot;
  do
    {
      ptr = cptr->arb;

      node* temp;      
      if(cptr->next!=NULL)
	temp = cptr->next->arb;
      else
	temp = NULL;
      
      cptr->arb = ptr->arb->next;                
            
      cptr = cptr->next;
    }
  while(cptr!=NULL);

  cptr = croot;  
  do
    {
      std::cout << cptr->id << " " << cptr->arb->id << " ";
      cptr = cptr->next;
    }
  while(cptr!=NULL);

  std::cout << "\n";

  ptr = root;
  int counter = 0;
  do
    {
      ptr->next = NextBackup[counter];
      std::cout << ptr->id << " " << ptr->arb->id << " ";
      ptr = ptr->next;
      counter++;
    }
  while(ptr!=NULL);

  std::cout << "\n";


  return 0;
}
