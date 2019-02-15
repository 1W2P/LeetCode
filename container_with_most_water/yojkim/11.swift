class Solution {
    func maxArea(_ height: [Int]) -> Int {
        var max = Int.min
        
        for i in 0..<height.count - 1 {
            for j in i..<height.count {
                let width = j - i
                let amt = width * min(height[i], height[j])
                if max < amt {
                    max = amt
                }
            }
        }
        return max
    }
}
