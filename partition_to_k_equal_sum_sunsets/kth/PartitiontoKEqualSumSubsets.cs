using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp7
{
    class Program
    {
        static void Main(string[] args)
        {
            Debug.WriteLine(new Solution().CanPartitionKSubsets((new int[] { 2, 2, 10, 5, 2, 7, 2, 2, 13 }), 3)); //2 * 5 + 5인 경우?? 

        }
    }
    public class Pair
    {
        public bool IsVisited { get; set; }
        public int Number { get; set; }
        public Pair(bool isVisited, int number) { this.IsVisited = isVisited; this.Number = number; }
    }
    public class Solution
    {
        private int Target;
        List<Pair> pList = new List<Pair>();
        public bool CanPartitionKSubsets(int[] nums, int k)
        {
            Target = nums.Sum() / k;
            if ((nums.Sum() % k) != 0)
                return false;
            if (Target == 0)
                return false;
            if (nums.Count() < k)
                return false;
            pList = (from num in nums
                     orderby num descending
                     select new Pair(false, num)).ToList();
            for (int i = 0; i < k; i++)
            {
                if (!Solve(0, 0))
                    return false;
                pList = (from pair in pList
                         where !pair.IsVisited
                         select pair).ToList();
            }
            return true;
        }
        private bool Solve(int idx, int sum)
        {
            if (sum > Target)
                return false;
            if (sum == Target)
                return true;
            for(int i = idx; i < pList.Count(); i++)
            {
                if (!pList[i].IsVisited) {
                    pList[i].IsVisited = true;
                    bool ret = Solve(idx + 1, sum + pList[i].Number);
                    if (ret)
                        return ret;
                    pList[i].IsVisited = false;
                }
            }
            return false;
        }
    }
}
