//WEEK 6 - Q2
import java.util.Scanner;
public class Fail {
   public static void main(String[] args) {
        Scanner sh = new Scanner (System.in);
        int id;
        int arr[] = new int [5];
        System.out.println("Enter ID : ");
        id = sh.nextInt();
        System.out.println("Enter MARKS : ");
        for (int i=0; i<5; ++i)
            arr[i]=sh.nextInt();
        Student s = new Student (arr);
        s.score();
        s.pass();
   }
}
class Student
{
    int id;
    int m[] = new int[5];
    
    Student (int marks[])
    {
        for (int i=0; i<5; ++i)
            m[i]=marks[i];
    }
    int total()
    {
        int t = 0;
        for (int i=0; i<5; ++i)
            t+=m[i];
        return t;
    }
    void score()
    {
        System.out.println("Score is : "+total());
    }
    void pass()
    {
        int check=0;
        for (int i=0; i<5; ++i) {
        if (m[i]>=40)
            check++;}
        if (check==5)
            System.out.println("PASS");
        else
            System.out.println("FAIL");
    }
}
