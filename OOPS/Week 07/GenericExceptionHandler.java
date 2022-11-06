import java.util.Scanner; 
public class Generic  
{ 
public static void main(String[] args) 
{ 
Scanner sc=new Scanner(System.in); 
System.out.println("Enter 1, 2, 3, 4"); 
int n=sc.nextInt(); 
try 
{ 
switch (n) 
{ 
case 1: 
int a=44/0; 
break; 
case 2: 
int arr[]=new int[12]; 
arr[44]=0; 
break; 
case 3: 
System.out.println("Enter any character: "); 
int err=sc.nextInt(); 
break; 
case 4: 
String str="oops"; 
char ch=str.charAt(22); 
break; 
} 
} 
catch(Exception e) 
{ 
System.out.println("Exception caught: "+e); 
} 
} 
}
