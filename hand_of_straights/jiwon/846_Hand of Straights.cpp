class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int, int> cntMap;
        
        for(int i=0; i<hand.size(); i++){
            cntMap[hand[i]]++;
        }
        
        while(!cntMap.empty()){
            map<int, int>::iterator iter = cntMap.begin();
            int value = iter->first;
            for(int i=0; i<W; i++){
                if(iter == cntMap.end() || iter->first != value + i) return false;
                map<int, int>::iterator next = iter++;
                next->second = next->second - 1;
                if(next->second == 0) cntMap.erase(next);
            }
        }
        return true;
    }
};
