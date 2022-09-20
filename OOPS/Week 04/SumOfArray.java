
import java.util.Scanner;
public class SumArr {

	public static void main(String[] args) {
		Scanner sh = new Scanner (System.in);
		System.out.println("Enter the no of elements : ");
		int n=sh.nextInt();
		float arr[] = new float[n];
		float sum = 0;
		System.out.println("Start entering elements : ");
		for (int i=0; i<n; i++)
		{
			arr[i]=sh.nextFloat();
			sum+=arr[i];
		}
		System.out.println("Sum of all elements = "+sum);
	}
}
