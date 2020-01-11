import java.util.Scanner;

public class today {
	public int day;
	protected int month;
	private int year = 2010;

	public void getmonth() {
		Scanner in = new Scanner(System.in);
		System.out.print("Enter month :");
		month = in.nextInt();
		in.close();
	}

	public void displayL() {
		int year = 2019;
		System.out.println("Local variable");
		System.out.println("Year :" + year);

	}

	public void displayG() {
		System.out.println("Global variable");
		System.out.println("Year :" + year);

	}

	public void display() {
		System.out.println();
		System.out.println("Day :" + day + "\n" + "Month :" + month);

	}
}
