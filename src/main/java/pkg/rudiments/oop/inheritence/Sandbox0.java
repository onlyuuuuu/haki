package pkg.rudiments.oop.inheritence;

public class Sandbox0
{
    public static void main(String[] args)
    {
        Clucker samuel = new Clucker("Samuel", 5);
        samuel.eat("Grass");
        samuel.eat("Rocks");

        // Works just like interfaces, which is great
        Animal doe = new Clucker("Doe", 10);
        doe.eat("Grass");
        doe.eat("Rocks");
    }
}
