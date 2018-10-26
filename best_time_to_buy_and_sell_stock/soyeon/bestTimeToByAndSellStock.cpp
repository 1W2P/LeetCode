#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> 
#include <math.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int ans = 0;

      vector<pair<int,int>> idx;
      for(int i=0;i<prices.size();i++) {
        idx.push_back({prices[i], i});
      }

      vector<pair<int,int>> a(idx);
      vector<pair<int,int>> b(idx);

      sort(a.begin(), a.end()); // 오름차순
      sort(b.begin(), b.end(), greater<pair<int, int>>()); // 내림차순

      int buy, sell;
        
      for(int i=0; i<prices.size(); i++) {
        for(int j=0; j<prices.size(); j++){
          if(a[i].second < b[j].second  && a[i].first < b[j].first) {
            buy = a[i].first;
            sell = b[j].first;
            
            int diff = sell - buy;
            ans = max(diff, ans);
          }
        }
      }

      return ans;
    }
};

int main() {
  vector<int> pri;
  pri = {7,1,5,3,6,4};
  // pri = {7,6,4,3,1};
  // pri = {2,4,1};
  // pri = {3,2,6,5,0,3};

  Solution sol;
  sol.maxProfit(pri);
}
