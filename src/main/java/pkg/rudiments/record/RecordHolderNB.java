package pkg.rudiments.record;

public record RecordHolderNB (String var0, int var1, RecordHolderNB.InnerRecord1 r1, RecordHolderNB.InnerRecord2 r2)
{
    record InnerRecord1(String var0, int var1) { };
    record InnerRecord2(String var0, int var1, InnerRecord1 r1) { };

    public void show()
    {
        System.out.println(this);
    }
}
