fun main(args:Array<String>){
    Solution().maxProfit(intArrayOf(100,4,1))
}
class Solution {
    fun maxProfit(prices: IntArray): Int {
        var answer = 0
        if(prices.isEmpty())
            return answer
        var baseValue = prices.first()

        for(price in prices.toList().subList(1, prices.size)){
            if(baseValue > price)
                baseValue = price
            else if(baseValue < price)
                answer = Math.max(answer, price - baseValue)
        }
        return answer
    }
}