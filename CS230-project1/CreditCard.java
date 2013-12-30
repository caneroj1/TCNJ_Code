/**	Joe Canero, Project 1
 * 	Class file for a Credit Card Object
 * 	Each object will hold ccT, cvv, ccE, and cardNumber data fields.
 * 	Each object also possesses a toString method that formats each credit card object's information
 * 	and returns a neatly formatted string that has the information of the credit card
*/



import java.text.NumberFormat;
import java.text.DecimalFormat;

public class CreditCard 
{
	// private data for the credit card
	private String ccT = "";
	private int cvv;
	private String ccE = "";
	private long cardNumber;

	// constructor method
	public CreditCard (String ccT, long ccN, int cvv, String ccE)
	{
		this.ccT = ccT;
		this.cvv = cvv;
		this.ccE = ccE;
		
		cardNumber = ccN;
		
	}
	
	// toString method
	// uses the different NumberFormat objects to format the cvv and cardNumber data correctly
	public String toString ()
	{
		NumberFormat fmt = new DecimalFormat ("000");
		NumberFormat fmt2 = new DecimalFormat ("0000000000000000");
		
		String info = ccT + "\t" + (fmt2.format(cardNumber)) + "\t" + (fmt.format(cvv)) + "\t" + ccE;
		return info;
	}
}
