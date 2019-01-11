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
            
        }

    }
    public class Solution
    {
        public int FindDuplicate(int[] nums)
        {
            var uniq = nums.Distinct();
            return (nums.Sum() - uniq.Sum())/(nums.Count() - uniq.Count());
        }
    }

}
