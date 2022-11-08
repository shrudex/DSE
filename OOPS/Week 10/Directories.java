import java.io.*;
import java.util.*;
public class Directories {
	public static void main (String[] args) {
	File dir=new File("D:/");
	String child[] = dir.list();
	if(child== null)
		System.out.println("Does not Exist");
	else {
		for(int i=0;i<child.length;i++) {
			String s=child[i];
			System.out.println(child[i]);
			}
		}
	}
}
