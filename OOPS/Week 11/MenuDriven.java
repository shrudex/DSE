import java.util.*;
class T1 implements Runnable {
	public void run() {
		System.out.println("Thread Using Runnable Interface");
	}
}
class T2 extends Thread {
	public void run() {
		System.out.println("Thread Using Thread Class");
	}
}
public class MenuDriven {
	public static void main(String[] args) {
		Scanner in = new Scanner (System.in);
		System.out.println("Enter 1 to create a thread using Runnable Interface");
		System.out.println("Enter 2 to create a thread using Thread Class");
		System.out.println("Enter your choice : ");
		int ch = in.nextInt();
		switch (ch) {
		case 1:
			Thread tt = new Thread (new T1());
			tt.start();
			break;
		case 2:
			T2 tx = new T2();
			tx.start();
			break;
		default:
			System.out.println("Wrong Choice");
			}
	}
}
