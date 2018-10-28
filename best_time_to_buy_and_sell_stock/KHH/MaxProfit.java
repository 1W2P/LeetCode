class MaxProfit{
    public static void main(String[] args) {
        int[] test = {1, 2};
        int result = maxProfit(test);
        System.out.println(result);
    }
    public static int maxProfit(int[] prices) {
        if(prices.length == 0) return 0;
        int buy = prices[0];
        int profit = 0;
        for(int price : prices){
            if(price < buy){
                buy = price;
                isBuy = true;
            } else {
                if( price - buy > profit){
                    profit = price - buy;
                }
            }   
        }
        return profit;
    }
}