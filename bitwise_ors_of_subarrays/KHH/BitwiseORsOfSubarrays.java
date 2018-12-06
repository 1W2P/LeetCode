import java.util.*;

class BitwiseORsOfSubarrays
{
    public static void main(String[] args)
    {
        int[] testCase = {1,11,6,11};
        // 0000 0001
        // 0000 1011
        // 0000 0110
        // 0000 1011
        System.out.println(subarrayBitwiseORs(testCase));
    }
    public static int subarrayBitwiseORs(int[] A) {
        Set<Integer> result = new HashSet<>();
        Set<Integer> set = new HashSet<>();

        for(int target : A )
		{   
            Set<Integer> temp = new HashSet<>();
            temp.add(target);

			for(int num : set)
			{
                temp.add(num | target);
            }
            result.addAll(temp);
            set = temp;
			
        }
        return result.size();
    }
}