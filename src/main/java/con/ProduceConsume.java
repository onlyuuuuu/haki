import java.util.ArrayList;
import java.util.concurrent.locks.*;

class Anything
{
    private final ArrayList<Integer> l = new ArrayList<>();
    public Anything(){}
    public synchronized void produce(String threadName)
    {
        System.out.println(threadName + " was notified! Running produce()...");
        try
        {
            while (!l.isEmpty())
            {
                System.out.println(threadName + ": Cannot produce if the list is not empty!");
                wait();
            }
            int i = 1;
            while (l.size() < 5)
            {
                Thread.sleep(1000);
                l.add(i);
                System.out.println(threadName + ": Added " + i++ + " into the list. Size: " + l.size());
            }
            notify();
//            notifyAll();
        }
        catch (Exception e) {}
    }
    public synchronized void consume(String threadName)
    {
        System.out.println(threadName + " was notified! Running consume()...");
        try
        {
            while (l.isEmpty())
            {
                System.out.println(threadName + ": Cannot consume if the list is empty!");
                wait();
            }
            while (!l.isEmpty())
            {
                Thread.sleep(1000);
                System.out.println(threadName + ": Removed " + l.removeLast() + " into the list. Size: " + l.size());
            }
            notify();
//            notifyAll();
        }
        catch (Exception e) {}
    }
}


class AnythingVersionTwo
{
    private final ArrayList<Integer> l         = new ArrayList<>();
    private final Lock               lock      = new ReentrantLock();
    private final Condition          condition = lock.newCondition();
    public AnythingVersionTwo(){}
    public void produce(String threadName)
    {
        boolean locked = false;
        try
        {
            while (!l.isEmpty())
            {
                System.out.println(threadName + ": Cannot produce if the list is not empty!");
                condition.await();
            }
            int i = 1;
            while (l.size() < 5)
            {
                Thread.sleep(1000);
                l.add(i);
                System.out.println(threadName + ": Added " + i++ + " into the list. Size: " + l.size());
            }
            condition.notify();
        }
        catch (Exception e) {}
        finally
        {
            if (locked)
                lock.unlock();
        }
    }
    public void consume(String threadName)
    {
        boolean locked = false;
        try
        {
            while (l.isEmpty())
            {
                System.out.println(threadName + ": Cannot consume if the list is empty!");
                condition.await();
            }
            while (!l.isEmpty())
            {
                Thread.sleep(1000);
                System.out.println(threadName + ": Removed " + l.removeLast() + " into the list. Size: " + l.size());
            }
            condition.notify();
        }
        catch (Exception e) {}
        finally
        {
            if (locked)
                lock.unlock();
        }
    }
}

// rm -rf *.class > /dev/null 2>&1; javac ProduceConsume.java; java ProduceConsume
public class ProduceConsume
{
    public static void main(String[] args)
    {
        Anything a = new Anything();
        new Thread(() -> { while (true) { a.produce("p1"); } }).start();
        new Thread(() -> { while (true) { a.produce("p2"); } }).start();
        new Thread(() -> { while (true) { a.consume("c1"); } }).start();
        new Thread(() -> { while (true) { a.consume("c2"); } }).start();

//        AnythingVersionTwo a = new AnythingVersionTwo();
//        new Thread(() -> a.produce()).start();
//        new Thread(() -> a.consume()).start();

    }
}
