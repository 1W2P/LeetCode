
/*
https://leetcode.com/problems/number-of-1-bits/submissions/
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of 1 Bits.
*/

#include <iostream>
#include <bitset>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
      string inputBitS;
      inputBitS = bitset<32>(n).to_string();
      int res = 0;

      for(int i=0; i<inputBitS.length(); i++) {
        if(inputBitS[i] == '1') res++;
      }

      return res;
    }
};

int main() {
  // unsigned int input = 128;
  unsigned int input = 11;
  Solution sol;
  sol.hammingWeight(input);
}
