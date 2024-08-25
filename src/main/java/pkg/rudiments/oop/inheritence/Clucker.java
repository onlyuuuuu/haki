package pkg.rudiments.oop.inheritence;

public class Clucker extends Animal
{
    public Clucker(String name, int age)
    {
        super(name, age);
    }

    @Override
    public void eat(String food)
    {
        super.eat(food);
        if (!"grass".equalsIgnoreCase(food))
        {
            System.out.println(super.name + " cannot eat this kind of food!");
            return;
        }
        System.out.println(food + " has been consumed");
        System.out.println("Digested.");
    }
}
