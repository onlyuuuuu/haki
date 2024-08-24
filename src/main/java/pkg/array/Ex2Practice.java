package pkg.array;

import org.apache.commons.lang3.ArrayUtils;

public class Ex2Practice
{
    public static int removeDuplicates(int[] arr)
    {
        int trace = arr.length - 1;
        for (int i = arr.length - 2; i > -1; i--)
        {
            if (arr[i] == arr[trace] - 1)
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
        int[] arr;
        int boundary;

        arr = new int[] { 1, 2, 3, 3, 4, 4, 4, 5, 5, 6 };
        System.out.println(ArrayUtils.toString(arr));
        boundary = removeDuplicates(arr);
        System.out.println(ArrayUtils.toString(arr) + ". Boundary index: " + boundary + ". Boundary value: " + arr[boundary]);
    }
}
