import java.util.*;

class HandOfStraighs {
    public static void main(String [] args){
        int input[] = {1,2,3,6,2,3,4,7,8};
        System.out.println(isNStraightHand(input, 3));
    }

    public static boolean isNStraightHand(int[] hand, int W) {
        TreeMap<Integer, Integer> map = new TreeMap<>();

        if( hand.length % W != 0 ) 
        {
            return false;
        }

        for( int num : hand ) 
        {
            map.put(num, map.getOrDefault(num, 0) + 1 );
        }

        int loopCount = (hand.length / W);
        while(loopCount > 0){
            int startNum = map.firstKey();
            for( int i = 0; i < W; ++i )
            {
                int currNum = startNum + i;
                if( map.get(currNum) == null){
                    return false;
                }
                map.put(currNum, map.get(currNum) - 1);

                if( map.get(currNum) == 0){
                    map.remove(currNum);
                }
            }
            --loopCount;
        }
        return true;
    }
}