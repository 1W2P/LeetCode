
// https://leetcode.com/problems/reverse-bits/
// Runtime: 4 ms, faster than 82.39% of C++ online submissions for Reverse Bits.

#include <iostream>
#include <bitset>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
      bitset<32> origin;
      uint32_t reverse;

      origin = bitset<32>(n);
      string originS = origin.to_string();
      string reverseS = "";

      for(int i=originS.length() - 1 ; i>=0; i--) {
        reverseS += originS[i];
      }
      reverse = bitset<32>(reverseS).to_ulong();
      return reverse;
    }
};

int main() {
  unsigned int input = 43261596;
  Solution sol;
  sol.reverseBits(input);
}
