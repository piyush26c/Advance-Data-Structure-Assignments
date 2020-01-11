import java.util.Scanner;
public class Television {
	String model;
	int  size;
	int price;
	void readData()
	{
		Scanner in= new Scanner(System.in);
		try
		{
			System.out.println("Enter Model No. : ");
			model=in.next();
			if(model.length() > 4)
			throw new MyException("Exception in Model Number!");
			
			System.out.println("Enter Screen size in Inches : ");
			size=in.nextInt();
			if(size < 12 || size > 70)
			throw new MyException("Exception in Screen Size!");
			
			System.out.println("Enter Price in $ : ");
			price=in.nextInt();
			if(price < 0 || price > 5000)
			throw new MyException("Exception in Price!");
			
			System.out.println("All details correct");
			in.close();
		}
		catch(MyException exce)
		{
			System.out.println(exce);			
		}
				
	}
	public static void main(String [] args)
	{
		Television o= new Television();
		o.readData();
		
	}
	

}
