/*
https://leetcode.com/problems/palindromic-substrings/
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrom(string input) {
      int maxSize = input.length();
        if(input.length() == 2) {
            if(input[0] != input[1]) {
                return false;
            }
        }
        else {
          for(int i=0; i<maxSize/2; i++) 
            if(input.at(i) != input.at(maxSize - 1 - i))
              return false;
        }
        
      return true;
    }

    int countSubstrings(string s) {
        int res = 0;
        int maxSize = s.length();

        // substrig의 길이가 1일 경우 무조건 palindrom
        res += maxSize;
        
        for(int i=0; i<maxSize; i++) {
          string temp = "";
          temp += s[i];
          for(int j=i+1; j<maxSize; j++) {
            temp += s[j];
            if(isPalindrom(temp)) res++;
          }
        }
        return res;
    }
};

int main() {
  string s1 = "abc";
  string s2 = "aaa";
  Solution sol;
  sol.countSubstrings(s1);
}
