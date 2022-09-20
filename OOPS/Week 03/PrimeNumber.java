import java.util.*;
public class Prime {
	public static void main(String[] args) {
		Scanner sh = new Scanner (System.in);
		System.out.println("Enter any number : ");
		int num = sh.nextInt();
		int c=0;
		for (int i=2; i<num/2; i++)
		{
			if (num%i==0)
			{
				c=1;
				break;
			}
		}
		if (c==0)
			System.out.println(num+" is a prime number.");
		else
			System.out.println(num+" is not a prime number.");
	}
}
