import java.util.concurrent.ConcurrentHashMap;
import java.util.Iterator;
import java.util.*;
import java.util.stream.IntStream;
class Partition
{
    public static void main(String[] args)
    {
        // int testCase[] = {4, 3, 2, 3, 5, 2, 1};,4
        // int testCase[] = {1,2,3,4};,3
        // int testCase[] = {2,2,2,2,3,4,5};
        int testCase[] = {4,3,2,3,5,2,1};

        /*
        [3522,181,521,515,304,123,2512,312,922,407,146,1932,4037,2646,3871,269]
        5
        true
        */
        System.out.println(canPartitionKSubsets(testCase,4));
    }
    public static boolean canPartitionKSubsets(int[] nums, int k) {
        int total = IntStream.of(nums).sum();
        float expValue = (float)total/k; 
        if( Math.ceil(expValue) != expValue )
        {
            return false;
        }
        Arrays.sort(nums);
        boolean sumCheck[] = new boolean[nums.length];
        
        int end = nums.length-1;
        int count = 0;
        boolean result;
        int sum;
        
        while(true)
        {
            sum = 0;
            result = false;
            for(int i = end; i >= 0; --i)
            {
                if(sumCheck[i]) { continue; }
                
                if(expValue >= (sum + nums[i]))
                {
                    System.out.println(nums[i]);
                    sum += nums[i];
                    sumCheck[i] = true;

                    if(expValue == sum)
                    {
                        ++count;
                        --end;
                        result = true;
                        break;
                    }
                }
            }
            if(count == k || !result)
            {
                break;
            }
        }
        return result;
    }
}