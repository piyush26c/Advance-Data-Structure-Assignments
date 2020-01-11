import java.util.Scanner;

public class assgn1 extends today {
	public static void main(String args[])
	{
		today obj = new today();
		Scanner scan = new Scanner(System.in);
		System.out.print("Enter Day : ");
		obj.day=scan.nextInt();
		obj.getmonth();
		obj.display();
		obj.displayL();
		obj.displayG();
		scan.close();
	}
	
	
	

}
