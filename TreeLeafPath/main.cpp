#include <iostream>
#include <stack>

struct node
{
  node* left;
  node* right;

  int id;
};

//               n1
//              /  \              
//             n2   n3
//           /  \   / \
//          n4  n5 n6 n7

// Modified depth first search
void DFS(node* current, int sum)
{
  sum += current->id;

  // If it is leaf node
  if(current->left  == NULL &&
     current->right == NULL)
    {      
      std::cout<< sum << std::endl;
      return;
    }
  
  if(current->left)
    {
      DFS(current->left, sum);      
    }

  if(current->right)
    {
      DFS(current->right, sum);
    }
}

int main(void)
{
  node n1, n2, n3, n4, n5, n6, n7;
  
  n1.id  = 1; n1.left = &n2;  n1.right = &n3;
  n2.id  = 2; n2.left = &n4;  n2.right = &n5;
  n3.id  = 3; n3.left = &n6;  n3.right = &n7;
  n4.id  = 4; n4.left = NULL; n4.right = NULL;
  n5.id  = 5; n5.left = NULL; n5.right = NULL;
  n6.id  = 6; n6.left = NULL; n6.right = NULL;
  n7.id  = 7; n7.left = NULL; n7.right = NULL;

  DFS(&n1, 0);
}
