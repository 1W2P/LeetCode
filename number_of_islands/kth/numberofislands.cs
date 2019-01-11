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
        int[] dx = { 0, 0, -1, 1 };
        int[] dy = { 1, -1, 0, 0 };
        int MAX_Y;
        int MAX_X;
        char[,] Map = null;
        bool[,] Visited = null;
        public int NumIslands(char[,] grid)
        {
            this.Map = grid;
            var row = grid.GetLength(0);
            var height = grid.GetLength(1);
            Visited = new bool[row + 1, height + 1];
            MAX_Y = row;
            MAX_X = height;
            int ret = 0;
            for(int i = 0; i < row; i++)
            {
                for(int j = 0; j < height; j++)
                {
                    if (!Visited[i, j] && Map[i,j] == '1')
                    {
                        BFS(i, j);
                        ret++;
                    }
                }
            }
            return ret;
        }
        public void BFS(int y, int x)
        {
            var q = new Queue<Point>();
            q.Enqueue(new Point() { Y = y, X = x });
            while (q.Any())
            {
                var element = q.Dequeue();
                for (int i = 0; i < 4; i++)
                {
                    var ny = element.Y + dy[i];
                    var nx = element.X + dx[i];
                    if (ny < 0 || nx < 0 || ny >= MAX_Y || nx >= MAX_X || Visited[ny,nx]|| Map[ny,nx] == '0')
                        continue;
                    Visited[ny, nx] = true;
                    q.Enqueue(new Point() { Y = ny, X = nx });
                }
            }
        }
    }
    public class Point
    {
        public int Y { get; set; }
        public int X { get; set; }
    }

}
