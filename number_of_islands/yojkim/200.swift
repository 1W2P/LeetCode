class Solution {
    var islandCount = 0
    var grid: [[Character]]!
    
    func searchIsland(_ i: Int, _ j: Int) {
        self.grid[i][j] = "-"
        if j+1 < self.grid[i].count && self.grid[i][j+1] == "1" {
            searchIsland(i, j+1)
        }
        
        if j-1 >= 0 && self.grid[i][j-1] == "1" {
            searchIsland(i, j-1)
        }
        
        if i+1 < self.grid.count && self.grid[i+1][j] == "1" {
            searchIsland(i+1, j)
        }
        
        if i-1 >= 0 && self.grid[i-1][j] == "1" {
            searchIsland(i-1, j)
        }
    }
    
    func numIslands(_ grid: [[Character]]) -> Int {
        self.grid = grid
        for i in 0..<self.grid.count {
            for j in 0..<self.grid[i].count {
                if self.grid[i][j] == "1" {
                    searchIsland(i, j)
                    islandCount += 1
                }
            }
        }
        return islandCount
    }
}
