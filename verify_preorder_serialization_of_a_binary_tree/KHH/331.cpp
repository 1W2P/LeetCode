//
//  331.cpp
//  Algorithm_Cpp
//
//  Created by 김혜현 on 02/01/2019.
//  Copyright © 2019 Hyen. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> stack;
        bool isLeft = true;
        stringstream stream;
        stream.str(preorder);
        
        while( stream.good() )
        {
            string substr;
            getline(stream, substr, ',');
            
            if(isLeft)
            {
                if( "#" == substr )
                    isLeft = false;
                else
                    stack.push_back( substr );
                
            }
            else
            {
                if(stack.empty()) return false;
                
                stack.erase(--stack.end());
                
                if( "#" != substr )
                {
                    stack.push_back(substr);
                    isLeft = true;
                }
            }
        }
        
        return stack.empty();
    }
};
