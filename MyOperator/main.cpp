#include <iostream>
#include <limits>
#include <cmath>

int MySqrt(int n, double low, double high)
{
  if(high-low<=1)
    return low;

  int middle = (int)floor((low + high)/2.0f);
  
  double MiddleSquare = middle*middle;

  if(fabs(MiddleSquare-n)<1)
    return middle;
  else if(MiddleSquare<n)
    return MySqrt(n, middle, high);
  else 
    return MySqrt(n, low, middle);
}

int MyPower(int base, int exponent)
{
  if(exponent==0)
    return 1;
  else if(exponent==1)
    return base;
  else if(exponent%2==1)
    return base*MyPower(base, exponent-1);
  else
    {
      double SquareRoot = MyPower(base, exponent/2);
      return SquareRoot*SquareRoot;
    }
}

int MyMultiplication(int a, int b)
{
  if(b==0)
    return 0;
  else if(b==1)
    return a;
  else if(b%2==1)
    return a + MyMultiplication(a, b-1);
  else
    {
      int half = MyMultiplication(a, b/2);
      return half + half;
    }
}

int MyDivision(int a, int b, double low, double high)
{
  if(high-low<=1)
    return low;
  
  if(b<=0)
    return -1; 
  else if(b==1)
    return a;
  
  double middle = (low+high)/2.0f;

  double c = middle*b;

  if(fabs(c-a)<1)
    return middle;
  else if(c<a)
    return MyDivision(a, b, middle, high);
  else
    return MyDivision(a, b, low, middle);
}

int main(void)
{
  double MinInt = 1.0f;
  double MaxInt = 10000.0f;

  int TestNumber = 21;

  int msqrt  = MySqrt(TestNumber, MinInt, MaxInt);
  int mpower = MyPower(TestNumber, 3);
  int mmul   = MyMultiplication(TestNumber, 3);
  int mdiv   = MyDivision(TestNumber, 4, MinInt, TestNumber);

  std::cout << msqrt  << std::endl;
  std::cout << mpower << std::endl;
  std::cout << mmul   << std::endl;
  std::cout << mdiv   << std::endl;
}
