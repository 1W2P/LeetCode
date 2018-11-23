package leetcode;

import java.util.Arrays;

/**
 * @author
 **/
public class ShortestUnsortedSubarray {
	public int findUnsortedSubarray(int[] nums) {
		int[] sortedArray = Arrays.stream(nums).sorted().toArray();
		int start = 0;
		int end = 0;

		for (int i = 0; i < nums.length; i++) {
			if (nums[i] != sortedArray[i]) {
				start = i;
				break;
			}
		}

		for (int i = nums.length - 1; i >= 0; i--) {
			if (nums[i] != sortedArray[i]) {
				end = i;
				break;
			}
		}

		int result = end - start;
		return result > 0 ? result + 1 : 0;
	}
}
