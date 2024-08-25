import java.util.Scanner;

public class Ex4
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        if (n == 1)
        {
            System.out.println(scanner.nextInt() != 1 ? "NO" : "YES");
            return;
        }
        int loose = 0;
        for (int i = 0; i < n; i++)
        {
            if (scanner.nextInt() == 0)
                loose++;
            if (loose > 1)
            {
                System.out.println("NO");
                return;
            }
        }
        if (loose < 1)
        {
            System.out.println("NO");
            return;
        }
        System.out.println("YES");
    }
}
