public class Solution {
	// you need treat n as an unsigned value
	public static void main(String... args) {
		System.out.println(reverseBits(43261596));
		System.out.println(reverseBits(1));
	}
	public static int reverseBits(int n) {
		StringBuilder sb1 = new StringBuilder(Integer.toBinaryString(n));
		int lengthCount = 32 - sb1.length();
		int i;
		for (i = 0; i < lengthCount; i++) {
			sb1.insert(0, Integer.toString(0));
		}
		StringBuilder sb2 = sb1.reverse();
		return Integer.parseUnsignedInt(sb2.toString(), 2);
	}
}