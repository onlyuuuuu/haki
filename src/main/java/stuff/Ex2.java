package stuff;

import java.util.*;

public class Ex2
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

        public int getDuration()
        {
            return end - start;
        }

        @Override
        public boolean equals(Object o)
        {
            if (o == null || getClass() != o.getClass()) return false;
            Movie other = (Movie) o;
            return compareTo(other) == 0;
        }

        @Override
        public int hashCode()
        {
            return Objects.hash(this.index);
        }
    }

    static class Member implements Comparable<Member>
    {
        private final int index;

        private int numberOfMovies = 0;
        private int availableTime = 1;

        public static final Comparator DEFAULT_ORDER
            = Comparator.comparingInt(Member::getAvailableTime)
                .thenComparingInt(Member::getIndex);

        @Override
        public int compareTo(Member other)
        {
            return DEFAULT_ORDER.compare(this, other);
        }

        public Member(int index)
        {
            this.index = index;
            this.availableTime = 1;
            this.numberOfMovies = 0;
        }

        public Member(int index, int availableTime)
        {
            this.index = index;
            this.availableTime = availableTime;
        }

        public int getIndex()
        {
            return index;
        }

        public Member addMovie(int end)
        {
            this.availableTime = end;
            this.numberOfMovies++;
            return this;
        }

        public int getAvailableTime()
        {
            return this.availableTime;
        }

        public int getNumberOfMovies()
        {
            return this.numberOfMovies;
        }

        @Override
        public boolean equals(Object o)
        {
            if (o == null || getClass() != o.getClass()) return false;
            Member other = (Member) o;
            return DEFAULT_ORDER.compare(this, other) == 0;
        }

        @Override
        public int hashCode()
        {
            return Objects.hashCode(this.index);
        }
    }

    public static int optimalNumberOfMovies(int membersNo, List<Movie> orgMovies)
    {
        TreeSet<Member> members = new TreeSet<>();
        for (int i = 0; i < membersNo; i++)
            members.add(new Member(i));

        TreeSet<Movie> movies = new TreeSet<>();
        for (Movie movie : orgMovies)
            movies.add(movie);

        while (!movies.isEmpty())
        {
            Movie mov = movies.pollFirst();
            Member mem = members.floor(new Member(Integer.MAX_VALUE, mov.getStart()));

            if (mem == null)
                continue;

            members.remove(mem);
            members.add(mem.addMovie(mov.end));
        }

        int sum = 0;
        for (Member m : members)
            sum += m.getNumberOfMovies();

        return sum;
    }

    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object
        int moviesNo = scanner.nextInt();
        int members = scanner.nextInt();
        List<Movie> movies = new ArrayList<>(moviesNo);
        for (int i = 0; i < moviesNo; i++)
            movies.add(new Movie(i, scanner.nextInt(), scanner.nextInt()));
        System.out.println(optimalNumberOfMovies(members, movies));
    }
}
