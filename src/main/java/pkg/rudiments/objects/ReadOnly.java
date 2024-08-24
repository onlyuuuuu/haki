package pkg.rudiments.objects;

public class ReadOnly
{
    private int someIntValue = 99;
    private String someStringValue = "default string value";

    public int getSomeIntValue()
    {
        return someIntValue;
    }

    public void setSomeIntValue(int someIntValue)
    {
        this.someIntValue = someIntValue;
    }

    public String getSomeStringValue()
    {
        return someStringValue;
    }

    public void setSomeStringValue(String someStringValue)
    {
        this.someStringValue = someStringValue;
    }
}
