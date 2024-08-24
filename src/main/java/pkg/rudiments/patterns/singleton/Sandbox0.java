package pkg.rudiments.patterns.singleton;

import java.io.File;

public class Sandbox0
{
    public static void main(String[] args)
    {
        S3BucketHandler handler = S3BucketHandler.getInstance("2342yj4h324ln324", "234hjk324yu34");
        handler.uploadFile(new File("file0.exe"));
    }
}
