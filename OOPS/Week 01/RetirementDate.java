
import java.util.*;
public class Retirement
{
    public static void main(String[] args)
    {
        Scanner sh = new Scanner (System.in); //object creation
        //sh is the name of the object, you can have any other name
        System.out.println("Enter your DOB in DD/MM format : ");
        String y1=sh.nextLine();
        System.out.println("Enter your DOB in YYYY format : ");
        int y2=sh.nextInt();
        System.out.println("Enter the age at which you started working : ");
        int age=sh.nextInt();
        System.out.println("Enter your expected years of service : ");
        int service=sh.nextInt();
        int ret = y2+age+service;
        System.out.println("Date of retirement : "+y1+"/"+ret);
    }
}
