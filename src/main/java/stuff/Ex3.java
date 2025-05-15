package stuff;

import java.util.*;

public class Ex3
{
    static class Movie implements Comparable<Movie>
    {
        private final int index;
        private final int start;
        private final int end;

        @Override
        public int compareTo(Movie other)
        {
            if (this.end == other.end)
            {
                if (this.start == other.start)
                    return Integer.compare(this.index, other.index);
                return Integer.compare(other.start, this.start);
            }
            return Integer.compare(this.end, other.end);
        }

        public Movie(int index, int start, int end)
        {
            this.index = index;
            this.start = start;
            this.end = end;
        }

        public int getIndex()
        {
            return index;
        }

        public int getStart()
        {
            return start;
        }

        public int getEnd()
        {
            return end;
        }

        @Override
        public boolean equals(Object other)
        {
            return compareTo((Movie)other) == 0;
        }

        @Override
        public int hashCode()
        {
            return Objects.hash(this.index);
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

        int[] members = new int[membersNo + 1];

        TreeSet<Movie> movies = new TreeSet<>();
        TreeSet<Integer> tree = new TreeSet<>(new Comparator<Integer>()
        {
            @Override
            public int compare(Integer i1, Integer i2)
            {
                if (members[i1] == members[i2])
                    return Integer.compare(i1, i2);
                return Integer.compare(members[i1], members[i2]);
            }
        });

        for (int i = 0; i < moviesNo; i++)
            movies.add(new Movie(i, scanner.nextInt(), scanner.nextInt()));

        for (int i = 0; i < membersNo; i++)
        {
            members[i] = movies.pollFirst().getEnd();
            tree.add(i);
        }

        int total = membersNo;

        while (!movies.isEmpty())
        {
            Movie movie = movies.pollFirst();
            members[membersNo] = movie.getStart();
            Integer floor = tree.floor(membersNo);
            if (floor == null)
                continue;
            ++total;
            tree.remove(floor);
            members[floor] = movie.getEnd();
            tree.add(floor);
        }

        System.out.print(total);
        return;
    }
}
