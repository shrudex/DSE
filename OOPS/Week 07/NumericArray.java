import java.util.Scanner;
public class NumericArray {
	public static void main(String[] args) {
		Scanner sh = new Scanner (System.in);
		int arr[] = new int[3];
		int count = 0;
		System.out.println("Start entering elements : ");
		while(count!=3) {
			try {
				String st = sh.nextLine();
				int number = Integer.parseInt(st);
				arr[count++]=number;
			}
			catch (NumberFormatException e) {
				System.out.println("Enter a numeric value.");
			}
		}
		for (int i=0; i<3; ++i)
			System.out.print(arr[i]+"\t");
	}
}
