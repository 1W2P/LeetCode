public class Solution {
	// you need to treat n as an unsigned value
	public static void main(String... args) {
		System.out.println(hammingWeight(11));
		System.out.println(hammingWeight(128));
	}
	public static int hammingWeight(int n) {
		return Integer.bitCount(n);
    }
}