#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        int sizeOfV = hand.size();
        vector<int> check(sizeOfV, 0);

        if(sizeOfV == 1 || W == 1) {
          return true;
        }
        
        else if(sizeOfV < W || sizeOfV % W != 0 ) {
          return false;
        }

        else if (sizeOfV % W == 0) {
        sort(hand.begin(), hand.end());
            
        for(int i=0; i<sizeOfV-1; i++) {
          int diff = 1;
            if(check[i] == 0)
            for(int j=i+1; j<sizeOfV; j++) {
              if(check[j] == 0) 
                if(diff < W && hand[j] - hand[i] == diff) {
                  check[i] = 1;
                  check[j] = 1;
                  diff++;
                }
            }
            if(check[i] != 1)
            return false;
        }
        }
        
        return true;
    }
};

int main() {
  vector<int> hand;
  int W;

  // false
  hand = {1,1,2,2,3,3};
  W = 2;

  // hand = {1,2,3,4,5,6};
  // W = 2;

  // true;
  // hand = {1,2,3,6,2,3,4,7,8};
  // W = 3;

  Solution sol;
  sol.isNStraightHand(hand, W);
}
