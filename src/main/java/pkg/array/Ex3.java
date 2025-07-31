package pkg.array;

public class Ex3
{
    public static int maxProfit(int[] prices)
    {
        int profit = 0;
        int buy = 0;
        for (int sell = 1; sell < prices.length; sell++)
        {
            if (prices[sell] <= prices[buy])
            {
                buy = sell;
                continue;
            }
            int diff = prices[sell] - prices[buy];
            if (diff > profit)
                profit = diff;
        }
        return profit;
    }

    public static void main(String[] args)
    {
        int[] prices;

        prices = new int[] { 7,1,5,3,6,4 };
        System.out.println("Max profit is: " + maxProfit(prices));

        prices = new int[] { 7,6,4,3,1 };
        System.out.println("Max profit is: " + maxProfit(prices));
    }
}
