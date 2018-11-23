
class SubArray
{
    public static int[] sortedArr;
    static int startIndex;
    static int endIndex;

    public static void main (String args[])
    {
        int[] testArr = {2, 6, 4, 8, 10, 9, 15};
        System.out.println(findUnsortedSubarray(testArr));
    }
    
    public static int findUnsortedSubarray(int[] nums) {
        startIndex = nums.length;
        endIndex = -1;
        sortedArr = new int[nums.length];

        mergeArray(nums,0,nums.length-1);

        if (-1 == endIndex)
        {
            return 0;
        }

        return endIndex - startIndex + 1;
    }

    static public void mergeArray(int[] nums, int start, int end)
    {
        if (start < end)
        {
            int mid  = (start + end) / 2;
            //left
            mergeArray(nums, start, mid); 
            //rigth
            mergeArray(nums, mid + 1, end); 

            merge(nums, start, mid, end);
        }
    }
    public static void merge(int[] nums, int start, int mid, int end) {
        int i = start;
        int j = mid + 1;
        int k = start;
 
        while (i <= mid && j <= end) 
        {
            if (nums[i] <= nums[j])
            {
                sortedArr[k] = nums[i++];
            }
            else
            {   
                startIndex = Math.min(startIndex,i);
                endIndex = Math.max(endIndex,j);
                sortedArr[k] = nums[j++];
            }
            k++;
        }
 
        if (i > mid) 
        {
            for (int t = j; t <= end; ++t, ++k)
            {
                sortedArr[k] = nums[t];
            }
        } 
        else 
        {
            for (int t = i; t <= mid; ++t, ++k)
            {
                sortedArr[k] = nums[t];
            }
        }
 
        for (int t = start; t <= end; ++t)
        {
            nums[t] = sortedArr[t];
        }
    }
}

