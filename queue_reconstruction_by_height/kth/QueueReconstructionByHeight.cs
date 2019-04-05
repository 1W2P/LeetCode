using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp13
{
    class Program
    {
        static void Main(string[] args)
        {
            var list = new List<int>() { 7, 0, 4, 4, 7, 1, 5, 0, 6, 1, 5, 2 };
            var test = new List<int[]>();
            for (int i = 0; i < list.Count - 1; i+=2)
                test.Add(new int[] { list[i], list[i + 1] });
            var ret = new Solution().ReconstructQueue(test.ToArray());
        }

    }
    class Pair<T>
    {
        public T First { get; set; }
        public T Second { get; set; }
        public Pair(T first, T second)
        {
            this.First = first;
            this.Second = second;
        }
    }
    public class Solution
    {
        public int[][] ReconstructQueue(int[][] people)
        {
            var orderedPeoples = Enumerable.Range(0, people.GetLength(0))
                .Select(x => new Pair<int>(people[x][0], people[x][1]))
                .OrderByDescending(x => x.First)
                .ThenBy(x => x.Second);
            var ret = new List<Pair<int>>();
            foreach (var person in orderedPeoples)
                ret.Insert(person.Second, person);
            Enumerable.Range(0, people.GetLength(0))
                .ToList()
                .ForEach(x =>
            {
                people[x][0] = ret[x].First;
                people[x][1] = ret[x].Second;
            });
            return people;
        }
    }

}
