package pkg.rudiments.record;

public class Sandbox0
{
    public static void main(String[] args)
    {
        NoBoilerplate immutableObject = new NoBoilerplate("foo bar", 99);
        System.out.println(immutableObject);

        ImmutableObject object = new ImmutableObject("bar foo", 109, immutableObject);
        System.out.println(object);
    }
}
