#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      int cnt = 0;

      while (find(nums.begin(), nums.end(), 0) != nums.end() ) {
        nums.erase(find(nums.begin(), nums.end(), 0));
        cnt++;
      }
      for(int i=0; i<cnt; i++) {
        nums.push_back(0);
      }
    }
};

int main() {
  vector<int> a = {0,1,0,3,12};
  Solution sol;
  sol.moveZeroes(a);
}
