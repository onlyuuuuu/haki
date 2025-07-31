package pkg.rudiments.patterns.singleton;

import java.io.File;

public class S3BucketHandler
{
    private static S3BucketHandler _INSTANCE;
    private final String accessKey;
    private final String secretKey;

    private S3BucketHandler(String accessKey, String secretKey)
    {
        this.accessKey = accessKey;
        this.secretKey = secretKey;
        System.out.printf("Handling creation...\n");
    }

    public synchronized static S3BucketHandler getInstance(String accessKey, String secretKey)
    {
        if (_INSTANCE == null)
            _INSTANCE = new S3BucketHandler(accessKey, secretKey);
        return _INSTANCE;
    }

    public void uploadFile(File file)
    {
        System.out.printf("Uploading file %s...\n", file.getName());
        System.out.printf("Done uploading file %s.\n", file.getName());
    }

    public String getAccessKey()
    {
        return accessKey;
    }

    public String getSecretKey()
    {
        return secretKey;
    }
}
