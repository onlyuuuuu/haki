package stuff;

import org.junit.jupiter.api.Test;

import java.util.Arrays;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class Ex2Test
{
    @Test
    public void test()
    {
        assertEquals
        (
            4,
            Ex2.optimalNumberOfMovies(2, Arrays.asList
            (
                new Ex2.Movie(0, 1, 5),
                new Ex2.Movie(1, 8, 10),
                new Ex2.Movie(2, 3, 6),
                new Ex2.Movie(3, 2, 5),
                new Ex2.Movie(4, 6, 9)
            ))
        );

        assertEquals
        (
            3,
            Ex2.optimalNumberOfMovies(2, Arrays.asList
            (
                new Ex2.Movie(0, 3, 10),
                new Ex2.Movie(1, 6, 7),
                new Ex2.Movie(2, 3, 6),
                new Ex2.Movie(3, 1, 7)
            ))
        );

        assertEquals
        (
            3,
            Ex2.optimalNumberOfMovies(2, Arrays.asList
            (
                new Ex2.Movie(0, 3, 10),
                new Ex2.Movie(1, 6, 7),
                new Ex2.Movie(2, 3, 6),
                new Ex2.Movie(3, 1, 7),
                new Ex2.Movie(4, 3, 6)
            ))
        );

        assertEquals
        (
            3,
            Ex2.optimalNumberOfMovies(2, Arrays.asList
            (
                new Ex2.Movie(0, 3, 10),
                new Ex2.Movie(1, 6, 7),
                new Ex2.Movie(2, 3, 6),
                new Ex2.Movie(3, 1, 7),
                new Ex2.Movie(4, 3, 6),
                new Ex2.Movie(5, 3, 7)
            ))
        );

        assertEquals
        (
            3,
            Ex2.optimalNumberOfMovies(1, Arrays.asList
            (
                new Ex2.Movie(0, 3, 10),
                new Ex2.Movie(1, 6, 7),
                new Ex2.Movie(2, 3, 6),
                new Ex2.Movie(3, 8, 10),
                new Ex2.Movie(4, 1, 7),
                new Ex2.Movie(5, 3, 6),
                new Ex2.Movie(6, 3, 7)
            ))
        );

        assertEquals
        (
            4,
            Ex2.optimalNumberOfMovies(2, Arrays.asList
            (
                new Ex2.Movie(0, 3, 10),
                new Ex2.Movie(1, 6, 7),
                new Ex2.Movie(2, 3, 6),
                new Ex2.Movie(3, 8, 10),
                new Ex2.Movie(4, 1, 7),
                new Ex2.Movie(5, 3, 6),
                new Ex2.Movie(6, 3, 7)
            ))
        );

        assertEquals
        (
            3,
            Ex2.optimalNumberOfMovies(1, Arrays.asList
            (
                new Ex2.Movie(0, 3, 10),
                new Ex2.Movie(1, 6, 7),
                new Ex2.Movie(2, 3, 6),
                new Ex2.Movie(3, 8, 10),
                new Ex2.Movie(4, 1, 7),
                new Ex2.Movie(5, 3, 6),
                new Ex2.Movie(6, 6, 8),
                new Ex2.Movie(7, 3, 7),
                new Ex2.Movie(8, 6, 9)
            ))
        );

        assertEquals
        (
            5,
            Ex2.optimalNumberOfMovies(2, Arrays.asList
            (
                new Ex2.Movie(0, 3, 10),
                new Ex2.Movie(1, 6, 7),
                new Ex2.Movie(2, 3, 6),
                new Ex2.Movie(3, 8, 10),
                new Ex2.Movie(4, 1, 7),
                new Ex2.Movie(5, 3, 6),
                new Ex2.Movie(6, 6, 8),
                new Ex2.Movie(7, 3, 7),
                new Ex2.Movie(8, 6, 9)
            ))
        );

        assertEquals
        (
            3,
            Ex2.optimalNumberOfMovies(2, Arrays.asList
            (
                new Ex2.Movie(0, 1, 3),
                new Ex2.Movie(1, 2, 4),
                new Ex2.Movie(2, 3, 5)
            ))
        );

        assertEquals
        (
            2,
            Ex2.optimalNumberOfMovies(1, Arrays.asList
            (
                new Ex2.Movie(0, 1, 2),
                new Ex2.Movie(1, 2, 3)
            ))
        );
    }
}
