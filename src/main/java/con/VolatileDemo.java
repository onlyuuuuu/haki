// rm -rf *.class > /dev/null 2>&1; javac VolatileDemo.java; java VolatileDemo
public class VolatileDemo
{
//    public volatile static boolean stop = false;
    public static boolean stop = false;
    public static void main(String[] args) throws InterruptedException
    {
        new Thread(() ->
       {
           System.out.println("This external thread has been started!");
           while (!stop) {}
           System.out.println("This external thread has been stopped!");
       }, "myExternalThread").start();
        Thread.sleep(5000);
        System.out.println("Stopping the external thread!");
        stop = true;
        System.out.println("Stopped the external thread!");
    }
}
