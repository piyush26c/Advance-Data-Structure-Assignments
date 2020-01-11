package demo;

public class Cal implements Cal_implement{
	public double TA;
	public double DA;
	public double HRA;
	
	public Cal()
	{
		TA=20;
		DA=60;
		HRA=25;
	}
	public double calculate_salary( double baseSalary)
	{
		double temp1=0;
		double temp2=0;
		double temp3=0;
		
		temp1=(baseSalary*TA)/100;
		temp2=(baseSalary*DA)/100;
		temp3=(baseSalary*HRA)/100;
		
		return baseSalary=temp1+temp2+temp3;
	}
}