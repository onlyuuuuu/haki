import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.*;

// rm -rf *.class > /dev/null 2>&1; javac BlockingSyncBlock.java; java BlockingSyncBlock
class SomethingBlocking
{
    public SomethingBlocking()
    {
    }

    public synchronized void doSomething()
    {
        try
        {
            System.out.println("Doing something...");
            Thread.sleep(3000);
            System.out.println("Done doing something...");
        }
        catch (InterruptedException e)
        {

        }
    }

    public synchronized void doSomethingElse()
    {
        try
        {
            System.out.println("Doing something else...");
            Thread.sleep(3000);
            System.out.println("Done doing something else...");
        }
        catch (InterruptedException e)
        {

        }
    }
}
class SomethingNonBlocking
{
    private final Lock lock1 = new ReentrantLock(true);
    private final Lock lock2 = new ReentrantLock(true);

    public SomethingNonBlocking()
    {
    }

    public void doSomething()
    {
        try
        {
            lock1.tryLock();
            System.out.println("Doing something...");
            Thread.sleep(3000);
            System.out.println("Done doing something...");
        }
        catch (InterruptedException e)
        {

        }
        finally
        {
            lock1.unlock();
        }
    }

    public void doSomethingElse()
    {
        try
        {
            lock2.tryLock();
            System.out.println("Doing something else...");
            Thread.sleep(3000);
            System.out.println("Done doing something else...");
        }
        catch (InterruptedException e)
        {

        }
        finally
        {
            lock2.unlock();
        }
    }

    public void doSomethingDodgy()
    {
        boolean locked = false;
        try
        {
//            locked = lock2.tryLock();

            System.out.println("Trying to get lock2...");
            locked = lock2.tryLock(2000, TimeUnit.MILLISECONDS);
            System.out.println("Done trying to get lock2...");

            if (!locked)
            {
                System.out.println("Nope, not gonna do anything dodgy today!");
                return;
            }
            System.out.println("Doing something dodgy...");
            Thread.sleep(3000);
            System.out.println("Done doing something dodgy...");
        }
        catch (Exception e)
        {
            System.err.println(e);
        }
        finally
        {
            if (locked)
                lock2.unlock();
        }
    }
}
public class BlockingSyncBlock
{
    public static void main(String[] args) throws InterruptedException
    {
//        SomethingBlocking sb = new SomethingBlocking();
//        new Thread(() ->
//        {
//            sb.doSomething();
//        }).start();
//        new Thread(() ->
//        {
//            sb.doSomethingElse();
//        }).start();

        SomethingNonBlocking snb = new SomethingNonBlocking();
        new Thread(() ->
        {
            snb.doSomething();
        }).start();
        new Thread(() ->
        {
            snb.doSomethingElse();
        }).start();
        new Thread(() ->
        {
            snb.doSomethingDodgy();
        }).start();
    }
}
