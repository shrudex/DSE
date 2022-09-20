import java.util.Scanner;

public class PostOffice {

	public static void main(String[] args) {
		Scanner in = new Scanner (System.in);
		int n;
		System.out.println("Enter the number of parcels : ");
		n = in.nextInt();
		Parcel[] p = new Parcel[n];
		System.out.println("Start entering the details : /n");
		for (int i=0; i<n; i++)
		{
			String name;
			double id, par_wt;
			name = in.next();
			id = in.nextDouble();
			par_wt = in.nextDouble();
			p[i] = new Parcel(name, id, par_wt);
			p[i].show();
			System.out.println();
		}

	}
	}
	class Parcel
	{
		String cus_name;
		double par_id;
		double par_wt;
		Parcel (String name, double id, double weight)
		{
			cus_name = name;
			par_id = id;
			par_wt = weight;
		}
		double cal()
		{
			double charges;
			if (par_wt<=0)
				charges = 0;
			else if (par_wt<=2.0)
				charges = 32.50;
			else
				charges = 32.50 + (par_wt-2.0)*10.5;
			return charges;
		}
		void show()
		{
			System.out.println("Customer Name : "+cus_name);
			System.out.println("Parcel Id : "+par_id);
			System.out.println("Parcel Weight : "+par_wt);
			System.out.println("Charges : "+cal());
		}
}
