package pkg.rudiments.record;

public class Sandbox0
{
    public static void main(String[] args)
    {
        NoBoilerplate immutableObject = new NoBoilerplate("foo bar", 99);
        System.out.println(immutableObject);

        ImmutableObject object = new ImmutableObject("bar foo", 109, immutableObject);
        System.out.println(object);

        RecordHolder recordHolder = new RecordHolder("23423iuy44", 2347623);
        recordHolder.show();

        RecordHolderNB.InnerRecord1 r1 = new RecordHolderNB.InnerRecord1("23423iuy44", 2347623);
        RecordHolderNB recordHolderNB = new RecordHolderNB
        (
            "23423iuy44",
            2347623,
            r1,
            new RecordHolderNB.InnerRecord2("23423iuy44", 2347623, r1)
        );
        recordHolderNB.show();
    }
}
