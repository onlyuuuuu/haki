package stuff;

import org.junit.jupiter.api.Test;

import java.util.*;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class Ex1Test
{
    @Test
    public void testTree()
    {
        TreeSet<Integer> tree = new TreeSet<>(Comparator.reverseOrder());
        tree.add(11);
        tree.add(7);
        tree.add(9);
        tree.add(2);
        // 11 9 7 2
        // ceiling means right branch (>=, relative to order)
        assertEquals(2, tree.ceiling(6));
        assertEquals(7, tree.ceiling(7));
        // floor means left branch (<=, relative to order)
        assertEquals(9, tree.floor(9));
        assertEquals(11, tree.floor(10));
    }

    @Test
    public void test()
    {
        assertEquals(2, Ex1.minimumLoss(Arrays.asList(5l, 8l, 3l)));
        assertEquals(2, Ex1.minimumLoss(Arrays.asList(20l, 7l, 8l, 2l, 5l)));
        assertEquals(3, Ex1.minimumLoss(Arrays.asList(20l, 15l, 8l, 2l, 12l)));
        assertEquals(1, Ex1.minimumLoss(Arrays.asList(17l, 20l, 16l, 1l, 6l)));
        assertEquals(3, Ex1.minimumLoss(Arrays.asList(1l, 5l, 2l, 10l, 20l)));
        assertEquals(1, Ex1.minimumLoss(Arrays.asList(3l, 5l, 2l, 10l, 20l)));
        assertEquals(1, Ex1.minimumLoss(Arrays.asList(4l, 3l, 5l)));
        assertEquals(1, Ex1.minimumLoss(Arrays.asList(3l, 2l)));
    }
}
