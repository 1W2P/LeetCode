using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp20
{
    public class Interval
    {
        public int start;
        public int end;
        public Interval() { start = 0; end = 0; }
        public Interval(int s, int e) { start = s; end = e; }
    }
    class Program
    {
        static void Main(string[] args)
        {
            IList<Interval> testCaseIntervals = new List<Interval>()
            {
                new Interval(1, 3),
                new Interval(2, 6),
                new Interval(8, 10),
                new Interval(15, 18)
            };
            var ret = new Solution().Merge(testCaseIntervals);

        }
    }
    public class Solution
    {
        public IList<Interval> Merge(IList<Interval> intervals)
        {
            if (!intervals.Any())
                return new List<Interval>();
            var start = (from interval 
                        in (from element in intervals select element.start)
                        orderby interval
                        select interval).ToArray();
            var end = (from interval
                        in (from element in intervals select element.end)
                         orderby interval
                         select interval).ToArray();
            var baseIdx = default(int);
            var ret = new List<Interval>();
            for(int i=0; i < intervals.Count() - 1; i++)
            {
                if(start[i+1] > end[i])
                {
                    ret.Add(new Interval()
                    {
                        start = start[baseIdx],
                        end = end[i]
                    });
                    baseIdx = i + 1;
                }
            }
            if ((ret.LastOrDefault()?.end ?? 0) != end.Last())
                ret.Add(new Interval(start[baseIdx], end.Last()));
            return ret;
        }
    }
}
