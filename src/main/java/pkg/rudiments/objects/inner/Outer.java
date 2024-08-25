package pkg.rudiments.objects.inner;

public class Outer
{
    private String var0;
    private int var1;

    public Outer(String var0, int var1)
    {
        this.var0 = var0;
        this.var1 = var1;
    }

    class Inner
    {
        private float var2;

        public Inner(float var2)
        {
            this.var2 = var2;
        }

        public void process()
        {
            System.out.printf("Processing using %s, %d, %f as input parameters\n", var0, var1, var2);
            System.out.printf("Done\n");
        }
    }

    public Inner initInner(float f)
    {
        return new Inner(f);
    }
}
