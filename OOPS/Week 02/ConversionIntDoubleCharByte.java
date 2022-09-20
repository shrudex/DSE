
import java.util.*;
public class Conversion
{
    public static void main(String[] args)
    {
        Scanner sh = new Scanner (System.in); //object creation
        //sh is the name of the object, you can have any other name
        int i;
		    double d;
		    char c;
		    System.out.println("Enter a number : ");
		    i=sh.nextInt();
		    System.out.println("Enter a floating point number : ");
		    d=sh.nextDouble();
		    System.out.println("Enter a character: ");
		    c=sh.next().charAt(0);
		    byte b1=(byte)i;
		    int i1=(int)c;
		    byte b2=(byte)d;
		    int i2=(int)d;
		    System.out.println("Int "+i+" to Byte is: "+b1);
		    System.out.println("Char "+c+" to Int is: "+i1);
		    System.out.println("Double "+d+" to Byte is: "+b2);
		    System.out.println("Double "+d+" to Int is: "+i2);
    }
}
