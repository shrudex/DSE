import java.util.Scanner;
class Area {
	double height;
	Area (double h) {
		this.height=h;
	}
}
class Triangle extends Area {
	double base;
	Triangle (double h, double b) {
		super(h);
		this.base=b;
	}
	double cal_t() {
		double a = 0.5*base*height;
		return a;
	}
}
class Rectangle extends Area {
	double width;
	Rectangle (double w, double h) {
		super (h);
		this.width=w;
	}
	double cal_r() {
		double a = height*width;
		return a;
	}
}
public class AreaInheritance {

	public static void main(String[] args) {
		Scanner in = new Scanner (System.in);
		double h, b, w;
		System.out.println("Enter the height : ");
		String height = in.nextLine();
		try {
			 h = Double.parseDouble(height); 
		}
		catch (NumberFormatException e) {
			System.out.println("Invalid height entered");
			System.out.println("Height set to zero");
			 h = 0;
			 in.nextLine();
		}
		System.out.println("Enter the base of the triangle : ");
		String breadth = in.nextLine();
		try {
			 b = Double.parseDouble(breadth); 
		}
		catch (NumberFormatException e) {
			System.out.println("Invalid breadth entered");
			System.out.println("Breadth set to zero");
			 b = 0;
			 in.nextLine();
		}
		System.out.println("Enter the width of the rectangle : ");
		String width = in.nextLine();
		try {
			 w = Double.parseDouble(width); 
		}
		catch (NumberFormatException e) {
			System.out.println("Invalid width entered");
			System.out.println("Width set to zero");
			 w = 0;
		}
		Rectangle r = new Rectangle(w, h);
		Triangle t = new Triangle(h, b);
		System.out.println("Area of the triangle : "+t.cal_t());
		System.out.println("Area of the rectangle : "+r.cal_r());
	}

}
