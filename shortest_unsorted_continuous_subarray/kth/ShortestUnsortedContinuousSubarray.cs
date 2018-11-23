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
            Debug.WriteLine(new Solution().FindUnsortedSubarray((new int[] { 1,2,3,4 }))); 

        }
    }
    public class Solution
    {
        public int FindUnsortedSubarray(int[] nums)
        {
            var sortedNums = (from num in nums orderby num select num).ToList();
            var diff = sortedNums.Select((num, index) => new { Number = num, Index = index })
                .Where(x => nums[x.Index] != x.Number).Select(x => x.Index).ToList();
            return diff.Count() == 0 ? 0 : diff.Last() - diff.First() + 1;
        }
    }
}
