import java.util.*;
import java.util.concurrent.Semaphore;

class Producer
{
    private final String name;
    private final LinkedList<Integer> queue;
    private final Semaphore semaphore;

    public Producer(String name, LinkedList<Integer> queue, Semaphore semaphore)
    {
        this.name  = name;
        this.queue = queue;
        this.semaphore = semaphore;
    }

    public void produce()
    {
        if (!queue.isEmpty()) return;
        boolean locked = semaphore.tryAcquire();
        if (!locked) return;
        try
        {
            System.out.println(name + " | " + Thread.currentThread().getName() + ": Start producing...");
//            while (!queue.isEmpty())
//            {
//                System.out.println(name + " | " + Thread.currentThread().getName() + ": Can't produce while Q is not " +
//                                   "empty!");
//                wait();
//            }
            int i = 1;
            while (queue.size() < 5)
            {
                Thread.sleep(1000);
                queue.add(i);
                System.out.println(name + " | " + Thread.currentThread().getName() + ": Added: " + i++ + ". Size: " + queue.size());
            }
//            notifyAll();
        }
        catch (Exception e) {}
        finally
        {
            if (locked) semaphore.release();
        }
    }
}

class Consumer
{
    private final String name;
    private final LinkedList<Integer> queue;
    private final Semaphore semaphore;

    public Consumer(String name, LinkedList<Integer> queue, Semaphore semaphore)
    {
        this.name  = name;
        this.queue = queue;
        this.semaphore = semaphore;
    }

    public void consume()
    {
        if (queue.isEmpty()) return;
        boolean locked = semaphore.tryAcquire();
        if (!locked) return;
        try
        {
            System.out.println(name + " | " + Thread.currentThread().getName() + ": Start comsuming...");
//            while (queue.isEmpty())
//            {
//                System.out.println(name + " | " + Thread.currentThread().getName() + ": Can't consume while Q is empty!");
//                wait();
//            }
            while (!queue.isEmpty())
            {
                Thread.sleep(1000);
                System.out.println(name + " | " + Thread.currentThread().getName() + ": Delet: " + queue.removeLast() + ". Size: " + queue.size());
            }
//            notifyAll();
        }
        catch (Exception e) {}
        finally
        {
            if (locked) semaphore.release();
        }
    }
}

// rm -rf *.class > /dev/null 2>&1; javac ProdCons.java; java ProdCons
public class ProdCons
{
    private static volatile LinkedList<Integer> queue = new LinkedList<>();
    private static volatile Semaphore semaphore = new Semaphore(1);
    public static void main(String[] args) throws InterruptedException
    {
        Producer p1 = new Producer("Producer1", queue, semaphore);
        Producer p2 = new Producer("Producer2", queue, semaphore);
        Consumer c1 = new Consumer("Consumer1", queue, semaphore);
        Consumer c2 = new Consumer("Consumer2", queue, semaphore);
        Thread t1 = new Thread(() -> {
            while (true)
            {
                try
                {
                    Thread.sleep(200);
                }
                catch (Exception e) {}
                p1.produce();
            }
        }, "Thread1");
        Thread t2 = new Thread(() -> {
            while (true)
            {
                try
                {
                    Thread.sleep(200);
                }
                catch (Exception e) {}
                p2.produce();
            }
        }, "Thread2");
        Thread t3 = new Thread(() -> {
            while (true)
            {
                try
                {
                    Thread.sleep(200);
                }
                catch (Exception e) {}
                c1.consume();
            }
        }, "Thread3");
        Thread t4 = new Thread(() -> {
            while (true)
            {
                try
                {
                    Thread.sleep(200);
                }
                catch (Exception e) {}
                c2.consume();
            }
        }, "Thread4");
        t1.start();
        Thread.sleep(200);
        t2.start();
        Thread.sleep(200);
        t3.start();
        Thread.sleep(200);
        t4.start();
    }
}
