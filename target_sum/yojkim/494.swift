class Solution {
    private var cnt = 0
    func searchTargetSum(with nums: [Int], current: Int, sum: Int) -> Int {
        if nums.count == 0 {
            return abs(current) == abs(sum) ? (sum == 0 ? 2 : 1) : 0
        }
        
        var tempCnt = 0
        var tempNums = nums
        tempNums.removeFirst()
        
        tempCnt += searchTargetSum(with: tempNums, current: current + nums[0], sum: sum)
        tempCnt += searchTargetSum(with: tempNums, current: current - nums[0], sum: sum)
        return tempCnt
    }
    
    func findTargetSumWays(_ nums: [Int], _ S: Int) -> Int {
        return searchTargetSum(with: nums, current: 0, sum: S)
    }
}
