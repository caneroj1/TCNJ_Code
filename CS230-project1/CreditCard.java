/**	Joe Canero, Project 1
*/



import java.text.NumberFormat;
import java.text.DecimalFormat;

public class CreditCard 
{
	private String ccT = "";
	private int cvv;
	private String ccE = "";
	private long cardNumber;

	public CreditCard (String ccT, long ccN, int cvv, String ccE)
	{
		this.ccT = ccT;
		this.cvv = cvv;
		this.ccE = ccE;
		
		cardNumber = ccN;
		
	}
	
	public String toString ()	//uses the different NumberFormat objects to format the cvv and cardNumber data correctly
	{
		NumberFormat fmt = new DecimalFormat ("000");
		NumberFormat fmt2 = new DecimalFormat ("0000000000000000");
		
		String info = ccT + "\t" + (fmt2.format(cardNumber)) + "\t" + (fmt.format(cvv)) + "\t" + ccE;
		return info;
	}
}
