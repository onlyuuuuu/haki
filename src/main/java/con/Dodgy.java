import java.util.concurrent.Semaphore;

class Dodgier
{
    private final Semaphore semaphore;
    public Dodgier(Semaphore semaphore)
    {
        this.semaphore = semaphore;
    }
    public void doSomethingDodgy()
    {
        boolean locked = semaphore.tryAcquire();
        if (!locked) return;
        try
        {
            System.out.println(Thread.currentThread().getName() + ": Doing something dodgy...");
            Thread.sleep(1000);
            System.out.println(Thread.currentThread().getName() + ": Done doing something dodgy...");
        }
        catch (Exception e) {}
        finally
        {
            if (locked)
                semaphore.release();
        }
    }
}

// rm -rf *.class > /dev/null 2>&1; javac Dodgy.java; java Dodgy
public class Dodgy
{
    private static Semaphore semaphore = new Semaphore(1);
    static void main()
    {
        Dodgier d1 = new Dodgier(semaphore);
        Dodgier d2 = new Dodgier(semaphore);
        Dodgier d3 = new Dodgier(semaphore);
        Dodgier d4 = new Dodgier(semaphore);
        Thread thread1 = new Thread(() -> {while(true)d1.doSomethingDodgy();}, "DodgyThread1");
        Thread thread2 = new Thread(() -> {while(true)d2.doSomethingDodgy();}, "DodgyThread2");
        Thread thread3 = new Thread(() -> {while(true)d1.doSomethingDodgy();}, "DodgyThread3");
        Thread thread4 = new Thread(() -> {while(true)d2.doSomethingDodgy();}, "DodgyThread4");
        thread1.start();
        thread3.start();
        thread2.start();
        thread4.start();
    }
}
