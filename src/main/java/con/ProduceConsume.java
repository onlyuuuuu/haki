import java.util.*;
import java.util.concurrent.locks.*;

class Broker
{
    public final Lock      producerLock      = new ReentrantLock();
    public final Lock      consumerLock      = new ReentrantLock();
    public final Condition producerCondition = producerLock.newCondition();
    public final Condition consumerCondition = consumerLock.newCondition();
}

class Producer implements Runnable
{
    private final    Broker              broker;
    private volatile LinkedList<Integer> queue;

    public Producer(Broker broker, LinkedList<Integer> queue)
    {
        this.broker = broker;
        this.queue  = queue;
    }

    @Override
    public void run()
    {
        while (true)
        {
            boolean locked = false;
            try
            {
                while (queue.size() > 0)
                    broker.producerCondition.await();
                locked = broker.producerLock.tryLock();
                if (!locked) return;
                int i = 1;
                while (queue.size() < 5)
                {
                    Thread.sleep(1000);
                    queue.push(i);
                    System.out.println(Thread.currentThread().getName() + ": Added: " + i++ + ". Size: " + queue.size());
                }
                broker.consumerCondition.signalAll();
            }
            catch (Exception e) {}
            finally
            {
                if (locked)
                    broker.producerLock.unlock();
            }
        }
    }
}

class Consumer implements Runnable
{
    private final    Broker              broker;
    private volatile LinkedList<Integer> queue;

    public Consumer(Broker broker, LinkedList<Integer> queue)
    {
        this.broker = broker;
        this.queue  = queue;
    }

    @Override
    public void run()
    {
        while (true)
        {
            boolean locked = false;
            try
            {
                while (queue.isEmpty() || queue.size() != 5)
                    broker.consumerCondition.await();
                locked = broker.consumerLock.tryLock();
                if (!locked) return;
                while (queue.size() > 0)
                {
                    Thread.sleep(1000);
                    System.out.println(Thread.currentThread().getName() + ": Deled: " + queue.pop() + ". Size: " + queue.size());
                }
                broker.producerCondition.signalAll();
            }
            catch (Exception e) {}
            finally
            {
                if (locked)
                    broker.consumerLock.unlock();
            }
        }
    }
}

// rm -rf *.class > /dev/null 2>&1; javac ProduceConsume.java; java ProduceConsume
public class ProduceConsume
{
    private static volatile LinkedList<Integer> queue = new LinkedList<>();
    public static void main(String[] args)
    {
        Broker broker = new Broker();
        Thread p1 = new Thread(new Producer(broker, queue), "Thead-Producer1");
        Thread p2 = new Thread(new Producer(broker, queue), "Thead-Producer2");
        Thread c1 = new Thread(new Consumer(broker, queue), "Thead-Consumer1");
        Thread c2 = new Thread(new Consumer(broker, queue), "Thead-Consumer2");

//        p1.start(); c1.start();
//        p2.start(); c2.start();

        p2.start(); c2.start();
        p1.start(); c1.start();
    }
}
