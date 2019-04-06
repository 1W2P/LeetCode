using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp4
{
    class Program
    {
        static void Main(string[] args)
        {
            var ret = new int[4][];
            ret[0] = new int[] { 1, 2 };
            ret[1] = new int[] { 3 };
            ret[2] = new int[] { 3 };
            ret[3] = new int[] { };
            var test = new Solution().AllPathsSourceTarget(ret);

            //스윔 : 
        }
        public class Solution
        {
            int[][] Graph = default;
            public List<IList<int>> DFS(List<int> subList, List<IList<int>> ret)
            {
                if (Graph[subList.Last()].Length == 0)
                {
                    if (subList.Last() == Graph.GetLength(0) - 1)
                    {
                        ret.Add(subList.ToList());
                    }
                }
                else
                {
                    foreach (var node in Graph[subList.Last()])
                    {
                        subList.Add(node);
                        DFS(subList, ret);
                        subList.Remove(node);
                    }
                }
                return ret;

            }
            public IList<IList<int>> AllPathsSourceTarget(int[][] graph)
            {
                this.Graph = graph;
                return DFS(new List<int>() { 0 }, new List<IList<int>>());
            }
        }
    }
}
