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
        Member[] members = new Member[membersNo];
        
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

        TreeSet<Integer> memberTree = new TreeSet<>(new Comparator<Integer>()
        {
            @Override
            public int compare(Integer i, Integer j)
            {
                if (members[i].getAvailableTime() == members[j].getAvailableTime())
                    return Integer.compare(i, j);
                return Integer.compare(members[i].getAvailableTime(), members[j].getAvailableTime());
            }
        });

        movies[0] = new Movie(0, 0);
        for (int i = 1; i <= moviesNo; i++)
        {
            movies[i] = new Movie(scanner.nextInt(), scanner.nextInt());
            movieTree.add(i);
        }

        members[0] = new Member(1);
        for (int i = 1; i <= membersNo; i++)
            members[i] = new Member(1);

        Movie mov = movies[movieTree.pollFirst()];
        members[1].setAvailableTime(mov.getEndTime());
        memberTree.add(1);

        int total = 1;

        while (!movieTree.isEmpty())
        {
            mov = movies[movieTree.pollFirst()];
            if (mov.getStartTime() < members[memberTree.getFirst()].getAvailableTime())
            {
                if (memberTree.size() < membersNo)
                {
                    members[memberTree.size() + 1].setAvailableTime(mov.getEndTime());
                    memberTree.add(memberTree.size() + 1);
                    ++total;
                    continue;
                }
                break;
            }
            int memi = memberTree.pollFirst();
            members[memi].setAvailableTime(mov.getEndTime());
            memberTree.add(memi);
            ++total;
        }

        if (movieTree.isEmpty())
        {
            System.out.print(total);
            return;
        }

        while (true)
        {
            movies[0].setStartTime(members[memberTree.getFirst()].getAvailableTime());
            movies[0].setEndTime(movies[0].getStartTime() + 1);
            Integer ceiling = movieTree.ceiling(0);
            if (ceiling == null)
                break;
            while (true)
            {
                
            }
        }
 
        System.out.print(total);
        return;
    }
}
