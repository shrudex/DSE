
import java.util.*;
public class AddBitwise
{
    public static void main(String[] args)
    {
        Scanner sh = new Scanner (System.in); //object creation
        //sh is the name of the object, you can have any other name
        int n1, n2, and;
		System.out.println("Enter the first number : ");
		n1=sh.nextInt();
		System.out.println("Enter the second number : ");
		n2=sh.nextInt();
		while(n2!=0) {
			and=n1&n2;
			n1=n1^n2;
			n2=and<<1;
		}
		System.out.println("Bitwise Sum is : "+n1);
		if(n1%2==0)
			System.out.print("Sum is EVEN");
		else
			System.out.print("Sum is ODD");
    }
}
