using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp12
{
    class Program
    {
        static void Main(string[] args)
        {
            
            var ret = new Solution().MaxArea(new int[] { 1, 8, 6, 2, 5, 4, 8, 3, 7 });
            Debug.WriteLine(ret);
        }
    }

    public class Solution
    {
        public int MaxArea(int[] height)
        {
            int max = 0;
            for(int i=0; i < height.Length; i++)
            {
                for(int j= i + 1; j < height.Length; j++)
                {
                    var x = j - i;
                    var y = Math.Min(height[i], height[j]);
                    max = Math.Max(x * y, max);
                }
            }
            return max;
        }
    }
}
