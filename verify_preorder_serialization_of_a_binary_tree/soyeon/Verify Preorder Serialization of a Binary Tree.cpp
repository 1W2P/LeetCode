#include <iostream>
#include <string>
#include <string.h>
#include <stack>
#include <vector>
using namespace std;

/*
class Solution {
public:
    bool isValidSerialization(string preorder) {
      stack<string> s;
      bool flag = false;

      vector<string> tree;
      vector<char> temp(preorder.begin(), preorder.end());
      temp.push_back('\0');
      
      char* pre = &temp[0];
      char* token = strtok(pre, ",");

      while(token != NULL) {
        tree.push_back(token);
        token = strtok(NULL, ",");
      }

      if(tree.size() == 1) {
        if(tree[0] == "#") return true;
        else return false;
      }
      else {
        if(tree[0] == "#") return false;
      }
      if(tree.size()%2 == 0) return false;
      s.push(tree[0]);

      for(int i=1; i<tree.size(); i++) {
        if(s.top()=="#") {
          if(!flag) {
            s.pop();
            flag = true;
          }
          else if(flag) {
            if(s.size() <= 2) return false;
            else {
              s.pop(); s.pop();
            }
            flag = false;
          }
        }
        s.push(tree[i]);
      }

      return true;
    }
};
*/

class Solution {
public:
    bool isValidSerialization(string preorder) {
      stack<string> s;
      int cnt = 0;
      bool flag = false;

      vector<string> tree;
      vector<char> temp(preorder.begin(), preorder.end());
      temp.push_back('\0');
      
      char* pre = &temp[0];
      char* token = strtok(pre, ",");

      while(token != NULL) {
        tree.push_back(token);
        token = strtok(NULL, ",");
      }

      if(tree.size() == 1) {
        if(tree[0] == "#") return true;
        else return false;
      }
      else {
        if(tree[0] == "#") return false;
      }
      if(tree.size()%2 == 0) return false;

      for(int i=0; i<tree.size(); i++) {
        s.push(tree[i]);
        if(s.top()=="#") {
          if(!flag) {
            s.pop(); cnt++; flag = true;
          }
          else {
            s.pop(); s.pop(); cnt+=2;
            if(s.empty()) {
              if(cnt == tree.size()) return true;
              else return false;
            }
            flag = false;
          }
        }
      }

      if(s.size()%3 == 0) return true;

      return false;
    }
};

int main() {
  string str1 = "9,3,4,#,#,1,#,#,2,#,6,#,#";
  string str2 = "1,#";
  string str3 = "9,#,#,1";
  string str4 = "9,#,92,#,#";
  string str5 = "1,#,#,#,#";

  Solution sol;
  sol.isValidSerialization(str1);
  return 0;
}
