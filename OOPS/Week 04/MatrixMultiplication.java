
import java.util.*;

public class matrix_multiplication {
	static void display(int arr[][])
	{
		for (int i=0; i<2; i++)
		{
			for (int j=0; j<2; j++)
				System.out.print(arr[i][j]+"\t");
			System.out.println();
		}
	}

	public static void main(String[] args) {
		Scanner shubh = new Scanner (System.in);
		int m1[][] = new int[2][2];
		int m2[][] = new int[2][2];
		int n=2;
		System.out.println("Start entering the first matrix : \n");
		for (int i=0; i<2; i++)
		{
			for (int j=0; j<2; j++)
				m1[i][j] = shubh.nextInt();
		}
		System.out.println("\nStart entering the second matrix : \n");
		for (int i=0; i<2; i++)
		{
			for (int j=0; j<2; j++)
				m2[i][j] = shubh.nextInt();
		}
		int m3[][] = new int[2][2];
		for (int i=0; i<2; i++)
		{
			for (int j=0; j<2; j++)
				m3[i][j] = (m1[i][n-2])*(m2[n-2][j]) + (m1[i][n-1])*(m2[n-1][j]);
		}
		System.out.println("\nMATRIX 1 : ");
		display(m1);
		System.out.println("\nMATRIX 2 : ");
		display(m2);
		System.out.println("\nMATRIX 3 : ");
		display(m3);
	}

}
