import java.util.Scanner;


public class Leet_191 {
	public static void main(String[]args){
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		System.out.println(hammingWeight(n));
	}
	public static int hammingWeight(int n) {
		String num = Integer.toBinaryString(n);
		int res = 0;
		for (int i = 0; i < num.length(); i++) {
			if(num.charAt(i)=='1'){
				res++;
			}
		}
		return res;
	}
}

