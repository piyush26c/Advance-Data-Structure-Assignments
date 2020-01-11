import java.util.Scanner;

import demo.Cal;
public class Final_Salary {
	public static void main(String args[])
	{
		double baseSalary,salary;
		
		Cal obj=new Cal();
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter Base Salary:");
		baseSalary=sc.nextInt();
		salary=obj.calculate_salary(baseSalary);
		System.out.println("Total Salary: "+salary);
		
	}
}
