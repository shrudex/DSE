import java.util.*;
import java.io.*;
public class MenuDriven {
   public static void main(String[] args) {
         int ch;
            Scanner sc=new Scanner(System.in);
            System.out.println("Press 1 to read a file");
            System.out.println("Press 2 to write a file");
            System.out.println("Press 3 to copy a file to another file");
            System.out.println("Enter your choice: ");
            ch=sc.nextInt();
            switch(ch) {
                case 1:
                    try {
                        File ffff=new File("myfile.txt");
                        FileReader reader=new FileReader(ffff);
                        Scanner sc1=new Scanner(ffff);
                        while(reader.read()!=-1) {
                            String s=sc1.nextLine();
                            System.out.println(s);
                        }
                    }
                    catch(IOException e) {
                        System.out.println("Error");
                    }
                    break;
                case 2:
                    try {
                        FileWriter writer =new FileWriter("myfile.txt");
                        writer.write("I am here");
                        writer.close();
                    }
                    catch(IOException e) {
                        System.out.println("Error");
                    }
                    break;
                case 3:
                    Scanner sc2=new Scanner(System.in);
                    String a,b;
                    System.out.println("Enter the file which you want to read: ");
                    a=sc2.nextLine();
                    System.out.println("Enter the file which you want to write: ");
                    b=sc2.nextLine();
                    try {
                        FileInputStream in = new FileInputStream(a);
                        FileOutputStream out = new FileOutputStream(b);
                        int n;
                        while((n=in.read())!=-1)
                            out.write(n);
                        
                    }
                    catch(IOException e) {
                        System.out.println("Error");
                    }
                    System.out.println("Copied..");
                    break;
                    default:
                        System.out.println("Invalid");
   }
    }
}
