import java.util.Scanner;

public class Leet_190 {
	public static void main(String[]args){
		Scanner in = new Scanner(System.in);

		int n = in.nextInt();
		System.out.println(reverseBits(n));
	}
	public static int reverseBits(int n) {

		String num = Integer.toBinaryString(n);
		String reverse = "";
		int length = num.length();
		for(int i=0;i<32-length;i++){
			num='0'+num;
		}

		for(int i=num.length()-1;i>=0;i--){
			reverse+=num.charAt(i);
		}
		int res  = 0;
		int mask = 1;

		for(int i=reverse.length()-1;i>=0;i--){
			if(reverse.charAt(i)=='1'){
				res+=mask;
			}
			mask <<=1;
		}

		return res;
	}
}
