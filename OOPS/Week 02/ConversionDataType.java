import java.util.*;
public class Conversion
{
    public static void main(String[] args)
    {
        Scanner sh = new Scanner (System.in); //object creation
        //sh is the name of the object, you can have any other name
        System.out.print("Enter any string : ");
        String str = sh.nextLine();
        System.out.print("Enter any integer number : ");
        int num = sh.nextInt();
        System.out.println("Before swap : "+str+", "+num);
        int temp = num; //copying num to a temporary variable
        num = Integer.parseInt(str); //string to int conversion
        str=String.valueOf(temp); //int to string conversion
        System.out.println("After swap : "+str+", "+num);
    }
}
