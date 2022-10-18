import java.util.*;
class Student_Detail {
	String name;
	int id;
	String college_name;
	Student_Detail (String n, int id, String cn) {
		name = n;
		this.id = id;
		college_name = cn;
	}
	void display_details() {
		System.out.println("Name : "+name);
		System.out.println("Id : " +id);
		System.out.println("College Name : "+college_name);
	} }
public class Record {
	public static void main(String[] args) {
		Scanner in = new Scanner (System.in);
		System.out.println("Enter your name : ");
		String n = in.nextLine();
		System.out.println("Enter your ID : ");
		int id;
		while (true) {
			try {
				String i = in.nextLine();
				id = Integer.parseInt(i);
				break;
			}
			catch (NumberFormatException e) {
				System.out.println("Enter a valid ID!");
			}
		}
		System.out.println("Enter the college name : ");
		String c = in.nextLine();
		Student_Detail sd = new Student_Detail (n, id, c);
		System.out.println("Name : "+sd.name);
		System.out.println("ID : "+sd.id);
		System.out.println("College Name : "+sd.college_name);
	}
}
