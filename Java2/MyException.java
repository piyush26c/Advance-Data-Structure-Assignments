
public class MyException extends Exception{
	String exc;
	MyException(String e)
	{
		exc=e;		
	}
	
	public String toString()
	{
		return ("Exception Occured : " + exc);
	} 

}
