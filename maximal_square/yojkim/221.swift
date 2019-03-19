import Foundation

class Solution {
    private let zero: Character = "0"
    private let one: Character = "1"
    
    private var maxArea: Int = 0
    private var matrix: [[Character]]?
    
    private func isValidIndex(with x: Int, _ y: Int) -> Bool {
        guard let matrix = matrix,
            let rowCount = matrix.first?.count,
            x < rowCount, y < matrix.count else { return false }
        return true
    }
    
    private func searchThroughRow(with x: Int, _ y: Int) -> Int {
        guard let matrix = matrix,
            self.isValidIndex(with: x, y) else { return 0 }
        
        if matrix[y][x] == one {
            return self.searchThroughRow(with: x + 1, y) + 1
        }
        return 0
    }
    
    private func searchThroughCol(with x: Int, _ y: Int) -> Int {
        guard let matrix = matrix,
            self.isValidIndex(with: x, y) else { return 0 }
        
        if matrix[y][x] == one {
            return self.searchThroughCol(with: x, y + 1) + 1
        }
        
        return 0
    }
    
    private func searchThroughMiddle(with x: Int, _ y: Int) -> Int {
        
        guard let matrix = matrix,
            self.isValidIndex(with: x, y) else { return 0 }
        
        // 1 이라면 다음 row, col, mid 탐색
        if matrix[y][x] == one {
            let rowDepth = self.searchThroughRow(with: x + 1, y) + 1
            let colDepth = self.searchThroughCol(with: x, y + 1) + 1
            let middleDepth = self.searchThroughMiddle(with: x + 1, y + 1) + 1
            
            let minDepth = min(rowDepth, min(colDepth, middleDepth))

            return minDepth
        }
        return 0
    }
    
    func maximalSquare(_ matrix: [[Character]]) -> Int {
        self.matrix = matrix
        
        for (y, row) in matrix.enumerated() {
            for (x, value) in row.enumerated() {
                if value == one {
                    // 1이 보이면 세 갈래로 흩어져서 판단 -> 최소 depth로
                    let minDepth = self.searchThroughMiddle(with: x, y)
                    let area = Int(pow(Double(minDepth), 2))
                    if maxArea < area { maxArea = area }
                }
            }
        }
        return self.maxArea
    }
}
