import java.util.*;
class MoveZeroes
{
    public static void main(String[] args)
    {
        int testCase[] ={0,1,0,3,12};
        moveZeroes(testCase);
        System.out.println(Arrays.toString(testCase));
    }

    public static void moveZeroes(int[] nums) {
        int zeroCount = 0;
        int length = nums.length - 1;
        for(int i = length; i >= 0; --i)
        {
            if (0 == nums[i])
            {
                for(int j = i+1; j <= length - zeroCount; ++j)
                {
                    nums[j-1] = nums[j];
                }
                nums[length - zeroCount]  = 0;
                ++zeroCount;
            }
        }
    }
}