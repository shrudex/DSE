import java.util.Scanner; 
public class Extension  
{ 
  public static void main(String[] args) {  
    Scanner sc=new Scanner(System.in); 
    String arr[]=new String[5];  
    System.out.println("Enter file names"); 
    for(int i=0; i<5; i++)  arr[i]=sc.nextLine(); 
  int l=arr[0].length(); 
  String str=arr[0].substring(l-3); 
  for(String ele :arr) { 
    try { 
      if(ele.endsWith(str)==false) 
        throw new MyException("Invalid_File_Extn"); 
    } 
    catch(MyException e) { 
      System.out.println("Exception: "+ e.des + "\nFile: "+ ele); 
    } 
  } 
 }  
} 
class MyException extends Exception 
{ 
String des; 
MyException(String ex) 
{ des=ex; } 
}
