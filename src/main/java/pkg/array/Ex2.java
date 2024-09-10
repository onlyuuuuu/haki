package pkg.array;

import org.apache.commons.lang3.ArrayUtils;

public class Ex2
{
    public static int removeDuplicates(int[] arr)
    {
        int trace = 0;
        for (int i = 1; i < arr.length; i++)
        {
            if (arr[i] == arr[trace] + 1)
            {
                trace++;
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
