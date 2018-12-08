import java.util.Arrays;
import java.util.Scanner;

public class Leet_283 {
	public static void main(String[]args){
		Scanner in =new Scanner(System.in);
		int[] nums = {0,1,0,3,12};
		
		moveZeroes(nums);
	}
	public static void moveZeroes(int[] nums) {
		int cnt = 0;
		int res[] = new int[nums.length];
		for(int i=0;i<nums.length;i++){
			if(nums[i]!=0){
				nums[cnt] = nums[i];
				cnt++;
			}
		}
		for(int i = cnt;i<nums.length;i++){
			nums[i] = 0;
		}
		
		for(int i=0;i<nums.length;i++){
			System.out.print(nums[i]+" ");
		}
	}
}
