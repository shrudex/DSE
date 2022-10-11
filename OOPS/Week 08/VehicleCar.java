import java.util.Scanner;
class Vehicle {
	String type;
	int mileage;
	String brand;
	double price;
	Vehicle (String t, int m, String b, Double p) {
		type = t;
		mileage = m;
		brand = b;
		price = p;
	}
	void details() {
		System.out.println("Vehicle : ");
		System.out.println("type of vehicle : "+type);
		System.out.println("mileage of vehicle : "+mileage);
		System.out.println("brand of vehicle : "+brand);
		System.out.println("price of vehicle : "+price);
	}
}
class Car extends Vehicle {
	int model;
	Car (int m, String b, Double p, int mo) {
		super("CAR", m, b, p);
		this.model = mo;
	}
	void show() {
		System.out.println("Car : ");
		System.out.println("type is : "+type);
		System.out.println("mileage of car : "+mileage);
		System.out.println("brand of car : "+brand);
		System.out.println("price of car : "+price);
		System.out.println("car model : "+model);
	}
}
public class VehicleInheritance {
	public static void main(String[] args) {
		Scanner in = new Scanner (System.in);
		double p; int m, mo;
		System.out.println("Enter the brand : ");
		String brand = in.nextLine();
		while (true) {
			System.out.println("Enter the mileage : ");
            try {
 
            	String mil = in.nextLine();
                m = Integer.parseInt(mil);
                break;
            }
            catch (NumberFormatException e) {
                System.out.println("Invalid Mileage entered.");
            }
        }
		while (true) {
			System.out.println("Enter the price : ");
            try {
 
            	String price = in.nextLine();
                p = Double.parseDouble(price);
                break;
            }
            catch (NumberFormatException e) {
                System.out.println("Invalid Price entered.");
            }
		}
		while (true) {
			System.out.println("Enter the model : ");
            try {
 
            	String model = in.nextLine();
                mo = Integer.parseInt(model);
                break;
            }
            catch (NumberFormatException e) {
                System.out.println("Invalid Price entered.");
            }
		}
		Car c = new Car (m, brand, p, mo);
		c.show();
	}
}
