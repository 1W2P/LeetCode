#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> rightOrder(nums);
        sort(rightOrder.begin(), rightOrder.end());
        
        if(rightOrder == nums) {
            return 0;
        }
        
        int first, last;
        
        for(int i=0; i<rightOrder.size(); i++) {
            cout << rightOrder[i] << ' ';
        }
        
        for(int i=0; i<nums.size(); i++) {
            if(rightOrder[i] != nums[i]) {
                first = i;
                break;
            }
        }
        
        for(int i=nums.size()-1; i>=0; i--) {
            if(rightOrder[i] != nums[i]) {
                last = i;
                break;
            }
        }
        
        cout << last - first + 1;
        return last - first + 1;
    }
};

int main() {
  vector<int>nums = {2, 6, 4, 8, 10, 9, 15};
  Solution sol;
  sol.findUnsortedSubarray(nums);
}
   
