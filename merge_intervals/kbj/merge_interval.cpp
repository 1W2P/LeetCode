#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Interval
{
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution
{
public:
  static bool compare(Interval a, Interval b)
  {
    return a.start < b.start;
  }
  vector<Interval> merge(vector<Interval> &intervals)
  {
    vector<Interval> ans;

    if (intervals.size() == 0)
    {
      return ans;
    }

    sort(intervals.begin(), intervals.end(), compare);

    Interval iv(-1, -1);

    for (auto v : intervals)
    {
      // 0일때 초기화
      if (iv.start == -1)
      {
        iv.start = v.start;
        iv.end = v.end;
        continue;
      }

      // 더이상 포함하지 못할때
      if (iv.end < v.start)
      {
        ans.push_back(Interval(iv.start, iv.end));
        iv = Interval(v.start, v.end);
      }
      // 포함가능일때
      else if (iv.end < v.end)
      {
        iv.end = v.end;
      }
    }

    //마지막 것은 무조건 하나 남으므로 남은거 푸시
    ans.push_back(Interval(iv.start, iv.end));

    return ans;
  }
};