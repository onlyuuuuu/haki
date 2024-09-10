import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;

public class JUnitExampleTest
{

    private final JUnitExample jUnitExample = new JUnitExample();

    @Test
    void justReturnAnArrayTest()
    {
        assertArrayEquals(new int[] { 1, 2, 3, 4 }, jUnitExample.justReturnAnArray());
    }

}
