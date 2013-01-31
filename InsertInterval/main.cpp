#include <iostream>
#include <utility>
#include <vector>
#include <cmath>

typedef std::pair<int, int> interval;
typedef std::vector<interval> IntVec;

bool overlap(const interval& i1,
	     const interval& i2)
{
  return 
    i1.second >= i2.first &&
    i1.first  <= i2.second;
  
  // return x2 >= y1 && x1 <= y2;)
}

interval merge(const interval& i1,
	       const interval& i2)
{
  return interval(std::min(i1.first,  i2.first),
		  std::max(i1.second, i2.second));
}

IntVec InsertInterval(const IntVec& IntervalVec, 
		      interval InsertedValue)
{
  IntVec ret;

  for(int i=0; i<IntervalVec.size(); i++)
    {
      // Check if current interval has overlap with the
      // inserted one
      if(overlap(InsertedValue, IntervalVec[i]))
	{
	  InsertedValue = merge(InsertedValue, 
				IntervalVec[i]);
	}
      else if(InsertedValue.second <
	      IntervalVec[i].first)
	{
	  ret.push_back(InsertedValue);
	  ret.push_back(IntervalVec[i]);
	}
      else
	{
	  ret.push_back(IntervalVec[i]);
	}
    }

  return ret;
}

int main(void)
{
  IntVec IntervalVec;

  IntervalVec.push_back(interval(1,  2));
  IntervalVec.push_back(interval(3,  5));
  IntervalVec.push_back(interval(6,  7));
  IntervalVec.push_back(interval(8,  10));
  IntervalVec.push_back(interval(12, 16));

  IntVec NewVec = InsertInterval(IntervalVec, interval(4, 9));

  for(int i=0; i<NewVec.size(); i++)
    {
      std::cout << "[" <<NewVec[i].first << " " 
		<< NewVec[i].second << "]"
		<< " ";
    }
  std::cout << std::endl;
}
