
import java.util.*;
public class Taxi
{
    public static void main(String[] args)
    {
        Scanner sh = new Scanner (System.in);
        //sh is the name of the object, you can have any other name
        System.out.println("Enter the fare : ");
        double fare = sh.nextDouble();
        double dist;
        if (fare<=50)
            dist = fare/10;
        else if (fare<=170)
            dist = 5 + (fare-50)/8;
        else
            dist = 20 + (fare-170)/5;
        if (fare<0 || fare>300)
            System.out.println("Invalid Fare");
        else
            System.out.println("Distance for INR "+fare+" is "+dist);
    }
}
