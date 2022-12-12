#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Given a list of intervals, merge all the overlapping intervals
// to produce a list that has only mutually exclusive intervals.
/*
Intervals: [[1,4], [2,5], [7,9]]
Output: [[1,5], [7,9]]
Explanation: Since the first two intervals [1,4] and [2,5] overlap, we merged
them into one [1,5].
*/

// Note: So much we learned here.

class IntervalMerge {
public:
  int start;
  int end;
  IntervalMerge(int st, int en) : start(st), end(en) {}
};

// function returns a vector
vector<IntervalMerge> mergeIntervals(vector<IntervalMerge>& intervals){
  vector<IntervalMerge> mergedIntervals;
  // Note: sort data using lambda function
  sort(intervals.begin(), intervals.end(),
    [](const IntervalMerge &x, const IntervalMerge &y){ return x.start < y.start; });

  // for (auto element: intervals)
  //   cout<<element.start<<endl;

  // Note: vector of complex data structure and sing "const_interator"
  vector<IntervalMerge>::const_iterator itr = intervals.begin();
  auto interval = *itr++;
  int start = interval.start;
  int end = interval.end;
  while(itr != intervals.end()){
    //cout<<itr->start<<endl;
    interval = *itr++;
    if (interval.start <= end) {
      end = max(end, interval.end);
    } else {
      // Note: instantiate an object {start,end}
      mergedIntervals.push_back({start, end});
      start = interval.start;
      end = interval.end;
      //cout<<start<<" "<<end<<endl;
    }
  }
  // Note: last elemnet
  mergedIntervals.push_back({start,end});
  return mergedIntervals;
}

int main() {
  std::cout << "Hello World!\n";
  vector<IntervalMerge> inputs = {{1, 3}, {2, 5}, {7, 9}};
  auto result = mergeIntervals(inputs);
  for(auto itr: result)
    cout<<itr.start<<" "<<itr.end<<endl;
}