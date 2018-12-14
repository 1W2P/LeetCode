
import java.util.*;

class PalindromicSubstrings
{
    public static void main(String[] args)
    {
        System.out.println(countSubstrings("aba"));
    }
    public static int countSubstrings(String s) 
    {
        StringBuilder sb = new StringBuilder(s);
        Map<String,Integer> map = new HashMap<>();
        String target;
        int length = sb.length();
        
        for(int i = 0; i < length; ++i)
        {  
            for(int j = (i + 1); j <= length; ++j)
            {
                target = sb.substring(i,j);

                if (null != map.get(target))
                {
                    map.put(target, map.get(target) + 1);
                }
                else
                {
                    if(isPalindromic(target))
                    {
                        map.put(target, 1);
                    }
                }
            }
        }
        return map.values().stream().mapToInt(i->i).sum();
    }

    public static boolean isPalindromic(String str)
    {
        String reverse = new StringBuilder(str).reverse().toString();
        return str.equals(reverse);
    }
}