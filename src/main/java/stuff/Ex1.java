package stuff;

import java.util.*;

public class Ex1
{
    public static int minimumLoss(List<Long> prices)
    {
        long minLoss = Long.MAX_VALUE;

        TreeSet<Integer> descTree
            = new TreeSet<>(Comparator.comparing(i -> prices.get(i)));

        for (int i = 0; i < prices.size(); i++)
            descTree.add(i);

        for (int i = 0; i < prices.size() - 1; i++)
        {
            descTree.remove(i);
            long buy = prices.get(i);

            Integer floor = descTree.floor(i);
            if (floor == null)
                continue;

            long sell = prices.get(floor);
            long loss = buy - sell;
            if (loss < minLoss)
                minLoss = loss;
        }

        return (int)minLoss;
    }
}
