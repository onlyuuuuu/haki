package stuff;

import org.junit.jupiter.api.Test;

import java.util.Arrays;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class Ex1Test
{
    @Test
    public void test()
    {
        assertEquals(1, Ex1.minimumLoss(Arrays.asList(17l, 20l, 16l, 1l, 6l)));
        assertEquals(1, Ex1.minimumLoss(Arrays.asList(-17l, -20l, -16l, -1l, -6l)));
        assertEquals(3, Ex1.minimumLoss(Arrays.asList(1l, -5l, -2l, 10l, 20l)));
        assertEquals(1, Ex1.minimumLoss(Arrays.asList(2l, 3l, 4l)));
    }
}
