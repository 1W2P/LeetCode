import java.util.Arrays;
import java.util.Scanner;

public class Leet_846 {
	public static void main(String[]args){
		Scanner in = new Scanner(System.in);
		int hand[] = {5,1};
		int w = 2;

		System.out.println(isNStraightHand(hand,w));
	}
	public static boolean isNStraightHand(int[] hand, int w){
	
		if(hand.length%w!=0){
			return false;
		}
		else{
			Arrays.sort(hand);
			boolean visited[] = new boolean[hand.length];
			int tmp[] = new int[w];
			
			for(int i=0;i<hand.length/w;i++){
				int cnt =0;
				for(int j=0;j<hand.length;j++){
					if(!visited[j]){
						if(cnt ==0){
							visited[j] = true;
							tmp[cnt] = hand[j];
							cnt++;
						}
						else{
							if(cnt!=w){
								if(tmp[cnt-1]+1 == hand[j]){
									tmp[cnt] = hand[j];
									visited[j] = true;
									cnt++;
								}
							}
						}
					}
				}
			}
			for(int i=0;i<visited.length;i++){
				if(!visited[i]){
					return false;
				}
			}
		}
		return true;
	}
}
