import java.util.Scanner;
class UT implements Runnable {
	int arr1[] = new int[5];
	int arr2[] = new int[5];
 	int x[] = new int[10];
	UT (int num1[], int num2[]) {
		arr1 = num1;
		arr2 = num2;
		}
	public void run() {
		int i, j;
		for (i=0; i<5; ++i) x[i] = arr1[i];
		j = i;
		for (i=0; i<5; ++i) {
			int c = 0;
			for (int k=0; k<j-1; ++k) {
				if (arr2[i]==x[k]) c++;
			}
			if (c==0) x[j++] = arr2[i];
		}
		System.out.println("Union of the two arrays : ");
		for (int m=0; m<j; ++m)
			System.out.println(x[m]);
	}
}

class IT implements Runnable {
	int arr1[] = new int[5];
	int arr2[] = new int[5];
 	int x[] = new int[5];
	IT (int num1[], int num2[]) {
		arr1 = num1;
		arr2 = num2;
		}
	public void run() {
		int i, j, c, k=0;
		for (i=0; i<5; ++i) {
			c = 0;
			for (j=0; j<5; ++j) {
				if (arr1[i]==arr2[j]) c++;
			}
			if (c!=0) x[k++] = arr1[i];
		}
		System.out.println("Intersection of the two arrays : ");
		for (int m=0; m<k; ++m)
			System.out.println(x[m]);
	}
}
public class MultiThreading {
	public static void main(String[] args) throws InterruptedException {
		Scanner in = new Scanner (System.in);
		int a[] = new int[5];
		int b[] = new int[5];
		System.out.println("Enter the first array : ");
		for (int i=0; i<5; ++i) a[i] = in.nextInt();
		System.out.println();
		System.out.println("Enter the second array : ");
		for (int i=0; i<5; ++i) b[i] = in.nextInt();
		System.out.println();
		UT t1 = new UT (a, b);
		Thread ut1 = new Thread (t1);
		ut1.start();
		ut1.join();
		System.out.println();
		IT t2 = new IT (a, b);
		Thread it2 = new Thread (t2);
		it2.start();
		it2.join();
	}
}
