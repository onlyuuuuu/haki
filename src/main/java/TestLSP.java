public class TestLSP
{
  public static class InnerStaticClass
  {
    public static void sayHi()
    {
      System.out.println("Hi there! from " + InnerStaticClass.class);
      return;
    }
    
    public static void saySomething()
    {
      System.out.println("Something...");
      return;
    }
  }

  public static void main(String[] args)
  {
    System.out.println("Hello World!");
    System.out.println("Trying to see if auto complete works?");
    System.out.println("Running on OS: " + System.getProperty("os.name"));
    System.out.println("Current time: " + System.currentTimeMillis());
    return;
  }
}
