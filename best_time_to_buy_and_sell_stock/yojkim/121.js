/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    maxIdx = 1;
    minIdx = 0;
    maxDiff = 0;
    
    for (i=1; i<prices.length; i++) {
        diff = prices[i] - prices[i-1];
        if (diff > 0) {
            if (prices[minIdx] > prices[i-1]) {
                minIdx = i-1;
                if (maxIdx < minIdx) {
                    maxIdx = i;
                }
            }
        
            if (prices[maxIdx] < prices[i]) {
                maxIdx = i;
            }
            
            if (prices[maxIdx] - prices[minIdx] > maxDiff) {
                maxDiff= prices[maxIdx] - prices[minIdx];
            }
        }
    }
    
    return maxDiff;
};