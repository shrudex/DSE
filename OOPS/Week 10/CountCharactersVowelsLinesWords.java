import java.util.*;
import java.io.*;
public class CountCharsVowWordsLines {
   public static void main(String[] args) {
        try {
        int words=0,lines=0,vowels=0,i,chars=0,c=0;
        File f=new File("demofile.txt");
        FileReader reader=new FileReader(f);
        Scanner sc=new Scanner(f);
        int k;
        if((reader.read())!=-1) {
            String s=sc.nextLine();
            for(i=0;i<s.length();i++) {
                if(s.charAt(i)=='a'||s.charAt(i)=='e'||s.charAt(i)=='i'||s.charAt(i)=='o'||s.charAt(i)=='u'
                    ||s.charAt(i)=='A'||s.charAt(i)=='E'||s.charAt(i)=='I'||s.charAt(i)=='O'||s.charAt(i)=='U')
                    vowels++;
                if(s.charAt(i)==' ')
                    words++;
            }
            lines++;
            chars+=s.length();
        }
        words+=lines;
        System.out.println("Lines : "+lines);
        System.out.println("Characters : "+chars);
        System.out.println("Words : "+words);
        System.out.println("Vowels : "+vowels);
    }
    catch(IOException e) {
        System.out.println("ERROR!!!");
    }
}
}
