using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp8
{
    class Program
    {
        static void Main(string[] args)
        {
            Debug.WriteLine(new Solution().FindTargetSumWays(new int[] { 1, 1, 1, 1, 1 }, 3));
        }

    }
    public class Solution
    {
        public int target = 0;
        public int[] Nums = null;
        int[,] cache = new int[21, 2002];
        public int FindTargetSumWays(int[] nums, int S)
        {
            target = S;
            Nums = nums;
            for (int i = 0; i <= 20; i++)
                for (int j = 0; j <= 2001; j++)
                    cache[i,j] = -1;
            return DFS(0, 0);
        }
        public int DFS(int idx, int sum)
        {
            if(idx == Nums.Length)
            {
                if (sum == target)
                    return 1;
                else
                    return 0;
            }
            if (cache[idx, sum + 1000] != -1)
                return cache[idx, sum + 1000];
            cache[idx, sum + 1000] = DFS(idx + 1, sum + Nums[idx]);
            cache[idx, sum + 1000] += DFS(idx + 1, sum - Nums[idx]);
            return cache[idx, sum + 1000];
        }
    }

}
