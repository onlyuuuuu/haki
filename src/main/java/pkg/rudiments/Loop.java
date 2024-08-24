package pkg.rudiments;

public class Loop
{
    public static void main(String[] args)
    {
        int i;

        i = 2;
        while (i < 2)
        {
            System.out.println("Value of i: " + i);
            i++;
        }

        for (int j = 2; j < 2; j++)
            System.out.println("Value of i: " + i);

        // do-while is interesting
        i = 2;
        do
        {
            System.out.println("Value of i: " + i);
            i++;
        }
        while (i < 2);
    }
}
