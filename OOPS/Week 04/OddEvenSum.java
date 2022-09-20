//WEEK 4 - Q2
import java.util.Scanner;
public class OddEvenSum {
	public static void main(String[] args) {
		Scanner sh = new Scanner (System.in);
		System.out.println("Enter the no of elements : ");
		int n=sh.nextInt();
		int arr[] = new int[n];
		int sum = 0;
		System.out.println("Start entering elements : ");
		for (int i=0; i<n; i++)
			arr[i]=sh.nextInt();
		if (n%2==0)
			sum = arr[0]+arr[n-1];
		else
			sum = arr[0]+arr[(n-1)/2]+arr[n-1];
		System.out.println("Sum is : "+sum);
	}
}
