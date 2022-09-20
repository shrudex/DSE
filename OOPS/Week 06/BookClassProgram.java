import java.util.Scanner;
public class BookClassProgram {
    public static void main(String[] args) {
        Scanner sh = new Scanner (System.in);
        String n;
        int i;
        double p;
        System.out.println("Enter the NAME : ");
        n = sh.nextLine();
        System.out.println("Enter the ID : ");
        i = sh.nextInt();
        System.out.println("Enter the PRICE : ");
        p = sh.nextDouble();
        Book b = new Book(i, n, p);
        System.out.println();
        System.out.println("The ID is : "+b.getID());
        System.out.println("The NAME is : "+b.getName());
        System.out.println("The PRICE is : "+b.getPrice());
    }
}
    class Book
    {
        String name;
        int id;
        double price;
        
        Book (int id, String name, double price)
        {
            this.name = name;
            this.id = id;
            this.price = price;
        }
        int getID()
        {
            return id;
        }
        double getPrice()
        {
            return price;
        }
        String getName()
        {
            return name;
        }
    }
