
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
        Set<String> set = new HashSet<>();

        String target;
        int length = sb.length();
        int count = 0;

        for(int i = 0; i < length; ++i)
        {  
            for(int j = (i + 1); j <= length; ++j)
            {
                target = sb.substring(i,j);

                if (set.contains(target))
                {
                    ++count;
                }
                else
                {
                    if(target.equals(new StringBuilder(target).reverse().toString()))
                    {
                        map.add(target);
                        ++count;
                    }
                }
            }
        }
        
        return count;
    }
}