
import java.util.Scanner;
public class MenuDriven {
    static int check (String s1, String s2)
    {
        for (int i = 0; i <= s1.length()-s2.length(); i++) {
            int j;
            for (j = 0; j < s2.length(); j++)
                if (s1.charAt(i + j) != s2.charAt(j))
                    break;
            if (j == s2.length())
                return i;
        }
        return -1;
    }
   public static void main(String[] args) {
        Scanner sh = new Scanner (System.in);
        System.out.println("MENU");
        System.out.println("1 --> Compare 2 Strings");
        System.out.println("2 --> Convert UpperCase to LowerCase & Vice Versa");
        System.out.println("3 --> Check if a String is a Substring of Other");
        System.out.println("4 --> If entered String is a Substring, replace with Hello");
        System.out.println("Enter your CHOICE : ");
        int ch;
        ch = sh.nextInt();
        sh.nextLine();
        switch(ch)
        {
        case 1:
            System.out.println("Enter the 2 Strings : ");
            String str1, str2;
            str1 = sh.nextLine();
            str2 = sh.nextLine();
            int l1 = str1.length();
            int l2 = str2.length();
            int diff = 0;
            int lmin = Math.min(l1, l2);
            for (int i = 0; i < lmin; ++i) {
                int str1_ch = (int)str1.charAt(i);
                int str2_ch = (int)str2.charAt(i);
                if (str1_ch != str2_ch) {
                    diff =  str1_ch - str2_ch;
                }
            }
            if (l1 != l2)
                diff = l1 - l2;
            if (diff==0)
                System.out.println("Strings are SAME");
            else
                System.out.println("Strings are not SAME. Difference is : "+diff);
            break;
        case 2:
            System.out.println("Enter STRING : ");
            String str = sh.nextLine();
            String newStr = "";
            for (int i = 0; i < str.length(); i++) {
                char c = str.charAt(i);
                int a = c;
                if (a>=65 && a<=90)
                    newStr+=(char)(a+32);
                else if (a>=97 && a<=122)
                    newStr+=(char)(a-32);
                else
                    newStr+=(char)a;
            }
            System.out.println("STRING after case conversion : " + newStr);
            break;
        case 3:
            System.out.println("Enter STRING : ");
            String st = sh.nextLine();
            System.out.println("Enter SUBSTRING : ");
            String sub = sh.nextLine();
            int flag = check(st, sub);
            if (flag==-1)
                System.out.println("Not a SUBSTRING");
            else
                System.out.println("Is a SUBSTRING");
            break;
        case 4:
            System.out.println("Enter STRING : ");
            String st1 = sh.nextLine();
            System.out.println("Enter SUBSTRING : ");
            String st2 = sh.nextLine();
            if (check(st1, st2)!=-1)
                st2="Hello";
            System.out.println("STRING1 : "+st1);
            System.out.println("STRING2 : "+st2);
            break;
        default:
            System.out.println("WRONG CHOICE");    
        }    
       }
}
