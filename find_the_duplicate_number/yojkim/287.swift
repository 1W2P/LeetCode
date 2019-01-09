class Solution {
    func findDuplicate(_ nums: [Int]) -> Int {
        for i in 0..<nums.count-1 {
            for j in i+1..<nums.count {
                if nums[i] == nums[j] {
                    return nums[i]
                }
            }
        }
        return 0
    }
}
