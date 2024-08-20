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
        int trace = -1;
        for (int i = arr.length; i >= 0; i--)
        {

        }
        return new int[] { 0 };
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
