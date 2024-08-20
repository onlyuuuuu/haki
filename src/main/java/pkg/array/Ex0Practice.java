package pkg.array;

import org.apache.commons.lang3.ArrayUtils;

public class Ex0Practice
{
    // Practice
    // Given an array, left side is <= N, right side is > N
    // Example: 1, 6, 9, 3, 5, 10, 13 and N = 7
    // Expected: 1, 3, 5, 6 on left side, 9, 10, 13 on right side
    public static int[] classify(int arr[], int n)
    {
        int trace = arr.length;
        int i;
        for (i = arr.length - 1; i >= 0; i--)
        {
            if (arr[i] > n)
            {
                trace--;
                int temp = arr[i];
                arr[i] = arr[trace];
                arr[trace] = temp;
            }
        }
        System.out.println("Stopped at " + arr[trace]);
        return arr;
    }


    public static void main(String[] args)
    {
        int arr[];
        int n;

        arr = new int[] { 1, 6, 9, 3, 5, 10, 13 };
        n = 7;
        System.out.println(ArrayUtils.toString(arr));
        System.out.println(ArrayUtils.toString(classify(arr, n)));

        arr = new int[] { 1, 6, 9, 3, 5, 10, 13, 7 };
        n = 7;
        System.out.println(ArrayUtils.toString(arr));
        System.out.println(ArrayUtils.toString(classify(arr, n)));
    }
}
