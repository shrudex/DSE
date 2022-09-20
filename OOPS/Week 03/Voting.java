import java.util.*;
public class Voting
{
    public static void main(String[] args)
    {
        Scanner sh = new Scanner (System.in); //object creation
        //sh is the name of the object, you can have any other name
        System.out.print("Enter your age : ");
        int age = sh.nextInt();
        if (age>=18)
            System.out.println("You are ELIGIBLE for voting!");
        else if (age<0)
            System.out.println("Wrong Age Entered");
        else
            System.out.println("You are not ELIGIBLE for voting!");
    }
}
