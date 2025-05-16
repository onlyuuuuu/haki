package stuff;

import java.util.*;

public class Ex5
{
    static class Movie
    {
        private final int startTime;
        private final int endTime;

        public Movie(int startTime, int endTime)
        {
            this.startTime = startTime;
            this.endTime = endTime;
        }

        public int getStartTime()
        {
            return startTime;
        }

        public int getEndTime()
        {
            return endTime;
        }
    }

    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        int moviesNo = scanner.nextInt();
        int membersNo = scanner.nextInt();

        if (membersNo >= moviesNo)
        {
            System.out.print(moviesNo);
            return;
        }

        int total = 0;

        Movie[] movies = new Movie[moviesNo + 1];

        TreeSet<Integer> st = new TreeSet<>
        (
            new Comparator<Integer>()
            {
                @Override
                public int compare(Integer i1, Integer i2)
                {
                    return Integer.compare(movies[i1].getStartTime(), movies[i2].getStartTime());
                }
            }
        );
        TreeSet<Integer> et = new TreeSet<>
        (
            new Comparator<Integer>()
            {
                @Override
                public int compare(Integer i1, Integer i2)
                {
                    return Integer.compare(movies[i1].getEndTime(), movies[i2].getEndTime());
                }
            }
        );

        for (int i = 1; i <= moviesNo; i++)
        {
            Movie movie = new Movie(scanner.nextInt(), scanner.nextInt());
            movies[i] = movie;
            st.add(i);
            et.add(i);
        }

        for (int i = 0; i < membersNo && !st.isEmpty() && !et.isEmpty(); i++)
        {
            int sum = 1;
            int polled = et.pollFirst();
            st.remove(polled);
            movies[0] = new Movie(movies[polled].getEndTime(), 0);
            Integer next = st.ceiling(0);
            while (next != null)
            {
                ++sum;
                et.remove(next);
                st.remove(next);
                movies[0] = new Movie(movies[next].getEndTime(), 0);
                next = st.ceiling(0);
            }
            total += sum;
        }

        System.out.print(total);
        return;
    }
}
