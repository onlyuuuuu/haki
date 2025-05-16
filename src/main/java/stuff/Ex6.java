package stuff;

import java.util.*;

public class Ex6
{
    static class Movie
    {
        private int startTime;
        private int endTime;

        public Movie(int startTime, int endTime)
        {
            this.startTime = startTime;
            this.endTime = endTime;
        }

        public void setStartTime(int startTime)
        {
            this.startTime = startTime;
        }

        public int getStartTime()
        {
            return startTime;
        }

        public void setEndTime(int endTime)
        {
            this.endTime = endTime;
        }

        public int getEndTime()
        {
            return endTime;
        }
    }
    
    static class Member
    {
        private int availableTime;

        public Member(int availableTime)
        {
            this.availableTime = availableTime;
        }

        public void setAvailableTime(int availableTime)
        {
            this.availableTime = availableTime;
        }

        public int getAvailableTime()
        {
            return availableTime;
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

        Movie[] movies = new Movie[moviesNo + 1];
        
        TreeSet<Integer> movieTree = new TreeSet<>(new Comparator<Integer>()
        {
            @Override
            public int compare(Integer i, Integer j)
            {
                if (movies[i].getEndTime() == movies[j].getEndTime())
                {
                    if (movies[i].getStartTime() == movies[j].getStartTime())
                        return Integer.compare(i, j);
                    return Integer.compare(movies[i].getStartTime(), movies[j].getStartTime());
                }
                return Integer.compare(movies[i].getEndTime(), movies[j].getEndTime());
            }
        });

        movies[0] = new Movie(0, 0);
        for (int i = 1; i <= moviesNo; i++)
        {
            movies[i] = new Movie(scanner.nextInt(), scanner.nextInt());
            movieTree.add(i);
        }

        int total = 0;

        Movie mov;
        Integer ceilingIndex;

        for (int i = 1; i <= membersNo && !movieTree.isEmpty(); i++)
        {
            mov = movies[movieTree.pollFirst()];
            while (mov != null)
            {
                ++total;
                movies[0].setStartTime(mov.getEndTime());
                movies[0].setEndTime(mov.getEndTime() + 1);
                ceilingIndex = movieTree.ceiling(0);
                while (ceilingIndex != null && movies[ceilingIndex].getStartTime() < mov.getEndTime())
                {
                    movies[0].setStartTime(mov.getEndTime());
                    movies[0].setEndTime(movies[ceilingIndex].getEndTime());
                    ceilingIndex = movieTree.ceiling(0);
                }
                if (ceilingIndex == null)
                    break;
                movieTree.remove(ceilingIndex);
                mov = movies[ceilingIndex];
            }
        }
 
        System.out.print(total);
        return;
    }
}
