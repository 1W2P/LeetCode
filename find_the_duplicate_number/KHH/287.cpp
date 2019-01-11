//
//  287.cpp
//  Algorithm_Cpp
//
//  Created by 김혜현 on 11/01/2019.
//  Copyright © 2019 Hyen. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution{
public:
    int findDuplicate(vector<int>& nums)
    {
        vector<int> temp(nums.size());
        for (auto num : nums)
        {
            ++temp[num];
            if (temp[num] > 1)
                return num;
        }
        
        return 0;
    }
};


int main()
{
    Solution sol;
    vector<int> testCase ={1,2,2,3,4};
    cout << sol.findDuplicate(testCase) << endl;
    return 0;
}
