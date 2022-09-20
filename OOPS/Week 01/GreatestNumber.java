
import java.util.*;
public class GreatestNumber
{
    public static void main(String[] args)
    {
        Scanner sh = new Scanner (System.in); //object creation
        //sh is the name of the object, you can have any other name
        System.out.println("Enter 3 numbers : ");
        int n1 = sh.nextInt();
        int n2 = sh.nextInt();
        int n3 = sh.nextInt();
        int g; //variable g to store the greatest number
        if (n1>n2)
        {
            if (n1>n3)
                g=n1;
            else
                g=n3;
        }
        else
        {
            if (n2>n3)
                g=n2;
            else
                g=n3;
        }
            System.out.println("Greatest number among "+n1+", "+n2+" and "+n3+" is "+g);
    }
}
