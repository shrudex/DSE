
import java.util.*;
public class RegNo
{
    public static void main(String[] args)
    {
        Scanner sh = new Scanner (System.in); //object creation
        //sh is the name of the object, you can have any other name
        System.out.println("Enter a 9-digit registration number : ");
        long reg = sh.nextLong();
        int c=0; //counter variable
        while(reg>99) //dividing by 10 unless we get a 2-digit number
        {    
            reg/=10;
            c++;
        }
        if (c==7) //reg no is 9-digit number
            System.out.println("The year of joining is "+reg);
        else //if reg no is not 9-digit
            System.out.println("Invalid Registration Number");
    }
}
