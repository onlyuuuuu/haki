package con;

import java.util.concurrent.atomic.AtomicReference;

public class ConcurrentReadWriteEx0
{
    static class Coordinate
    {
        public int x;
        public int y;
        public Coordinate(int x, int y)
        {
            this.x = x;
            this.y = y;
        }
    }

    static record ImmutableCoordinate(int x, int y) {};

    static void process(Coordinate coord)
    {
        final int x = coord.x;
        final int y = coord.y;
        if (x != y)
        {
            System.err.println("WRONG! Coordinates are suppose to be equal: x=" + x + ", y=" + y);
            return;
        }
        return;
    }

    static void process2(Coordinate coord)
    {
        if (coord.x != coord.y)
        {
            System.err.println("WRONG! Coordinates are suppose to be equal, but instead is different");
            return;
        }
        return;
    }

    static void process3(Coordinate coord)
    {
        synchronized (coord)
        {
            if (coord.x != coord.y)
            {
                System.err.println("WRONG! Coordinates are suppose to be equal, but instead is different");
                return;
            }
            return;
        }
    }

    static void process(ImmutableCoordinate coord)
    {
        final int x = coord.x;
        final int y = coord.y;
        if (x != y)
        {
            System.err.println("WRONG! Coordinates are suppose to be equal: x=" + x + ", y=" + y);
            return;
        }
        return;
    }

    static void process2(ImmutableCoordinate coord)
    {
        if (coord.x != coord.y)
        {
            System.err.println("WRONG! Coordinates are suppose to be equal, but instead is different");
            return;
        }
        return;
    }

    //private static Coordinate c = new Coordinate(5, 5);

    private static volatile ImmutableCoordinate sharedIC = new ImmutableCoordinate(5, 5);

    private static volatile Coordinate _C = new Coordinate(5, 5);

    public static void main(String[] args)
    {
        System.out.println("ConcurrentReadWrite started...");

        final Coordinate c = new Coordinate(5, 5);

        AtomicReference<ImmutableCoordinate> cRef = new AtomicReference<>(new ImmutableCoordinate(5, 5));

        AtomicReference<Coordinate> arc = new AtomicReference<>(c);

        Thread t1 = new Thread(() -> {
            while(true)
            {
                //process(c);
                //process2(c);
                //process3(c);

//                final ImmutableCoordinate ic = cRef.get();
//                c.x = ic.x;
//                c.y = ic.y;
//                process(c);

                //process(sharedIC);
                //process2(sharedIC);

//                final ImmutableCoordinate ic = sharedIC; // atomic read
//                c.x = ic.x;
//                c.y = ic.y;
//                process(c);

                process2(arc.get());
            }
        });

        Thread t2 = new Thread(() -> {
            while(true)
            {
                for (int i = 1; i <= 10; i++)
                {
                    c.x = i;
                    c.y = i;
                }
            }
        });

        Thread t3 = new Thread(() -> {
            while(true)
            {
                for (int i = 1; i <= 10; i++)
                {
                    synchronized (c)
                    {
                        c.x = i;
                        c.y = i;
                    }
                }
            }
        });

        Thread t4 = new Thread(() -> {
            while(true)
            {
                for (int i = 1; i <= 10; i++)
                {
                    cRef.set(new ImmutableCoordinate(i, i));
                }
            }
        });

        Thread t5 = new Thread(() -> {
            while(true)
            {
                for (int i = 1; i <= 10; i++)
                {
                    sharedIC = new ImmutableCoordinate(i, i);
                }
            }
        });

        Thread t6 = new Thread(() -> {
            while(true)
            {
                for (int i = 1; i <= 10; i++)
                {
                    _C = new Coordinate(i, i);
                }
            }
        });

        Thread t7 = new Thread(() -> {
            while(true)
            {
                for (int i = 1; i <= 10; i++)
                {
                    arc.set(new Coordinate(i, i));
                }
            }
        });

        t1.start();
//        t2.start();
//        t3.start();
//        t4.start();
//        t5.start();
//        t6.start();
        t7.start();
    }

}
