package pkg.rudiments.record;

public class RecordHolder
{
    private String var0;
    private int var1;

    record InnerRecord1(String var0, int var1) { };
    record InnerRecord2(String var0, int var1, InnerRecord1 r1) { };

    InnerRecord1 r1;
    InnerRecord2 r2;

    public RecordHolder(String var0, int var1)
    {
        this.var0 = var0;
        this.var1 = var1;
        this.r1 = new InnerRecord1(var0, var1);
        this.r2 = new InnerRecord2(var0, var1, r1);
    }

    public int getVar1()
    {
        return var1;
    }

    public String getVar0()
    {
        return var0;
    }

    public InnerRecord1 getR1()
    {
        return r1;
    }

    public InnerRecord2 getR2()
    {
        return r2;
    }

    @Override
    public String toString()
    {
        return "RecordHolder{" +
                "var0='" + var0 + '\'' +
                ", var1=" + var1 +
                ", r1=" + r1 +
                ", r2=" + r2 +
                '}';
    }

    public void show()
    {
        System.out.println(this);
    }
}
