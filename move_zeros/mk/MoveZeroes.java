package leetcode;

/**
 * @author
 **/
public class MoveZeroes {

	public static void main(String... args) {
		moveZeroes(new int[]{0,1,0,3,12});
	}

	public static void moveZeroes(int[] nums) {
		int start = 0;
		for (int i : nums) {
			if (i != 0) {
				nums[start++] = i;
			}
		}

		for (int i = start; i < nums.length; i++) {
			nums[i] = 0;
		}
	}
}
