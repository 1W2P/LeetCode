import Foundation

class Solution {
    
    var matrix: [[Bool]]?
    
    func searchPath(currentRow: Int) -> [[Int]] {
        guard var matrix = self.matrix else { return [] }
        
        var result: [[Int]] = []
        
        for (idx, isValid) in matrix[currentRow].enumerated() {
            if isValid {
                let returnPath = self.searchPath(currentRow: idx)
                for path in returnPath {
                    var retPath = path
                    retPath.insert(currentRow, at: 0)
                    result.append(retPath)
                }
            }
        }
        
        if result.count == 0 {
            return [[currentRow]]
        }
        
        return result
    }
    
    func allPathsSourceTarget(_ graph: [[Int]]) -> [[Int]] {
        self.matrix = Array(
            repeating: Array(
                repeating: false,
                count: graph.count
            ), count: graph.count
        )
        
        graph.enumerated().forEach {
            let (idx, values) = $0
            values.forEach {
                matrix?[idx][$0] = true
            }
        }
        
        return self.searchPath(currentRow: 0)
    }
}
