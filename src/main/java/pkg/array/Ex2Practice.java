package pkg.array;

import org.apache.commons.lang3.ArrayUtils;

public class Ex2Practice
{
    public static int removeDuplicates(int[] arr)
    {
        return 0;
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
