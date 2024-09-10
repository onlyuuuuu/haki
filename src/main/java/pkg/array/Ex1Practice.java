package pkg.array;

import org.apache.commons.lang3.ArrayUtils;

public class Ex1Practice
{
    // Practice
    // Given an array, left side is > M, right side is <= M
    // Example: 1, 6, 9, 3, 5, 10, 13 and M = 7
    // Expected: 9, 10, 13 on left side. 1, 3, 5, 6 on right side
    public static int classify(int arr[], int m)
    {
        int trace = arr.length;
        for (int i = arr.length - 1; i >= 0; i--)
        {
            if (arr[i] <= m)
            {
                trace--;
                int temp = arr[i];
                arr[i] = arr[trace];
                arr[trace] = temp;
            }
        }
        return trace;
    }


    public static void main(String[] args)
    {
        int arr[];
        int n;
        int boundary;

        arr = new int[] { 1, 6, 9, 3, 5, 10, 13 };
        n = 7;
        System.out.println(ArrayUtils.toString(arr) + ". Midpoint: " + n);
        boundary = classify(arr, n);
        System.out.println(ArrayUtils.toString(arr) + ". Boundary index: " + boundary + ". Boundary value: " + arr[boundary]);

        arr = new int[] { 1, 6, 9, 3, 5, 10, 13, 7 };
        n = 7;
        System.out.println(ArrayUtils.toString(arr) + ". Midpoint: " + n);
        boundary = classify(arr, n);
        System.out.println(ArrayUtils.toString(arr) + ". Boundary index: " + boundary + ". Boundary value: " + arr[boundary]);
    }
}
