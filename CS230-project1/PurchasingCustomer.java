/**	Joe Canero, Project 1
*/

public class PurchasingCustomer extends Customer /**this object uses the PersonalInformation, MailingAddress, and CreditCard classes to create a Purchasing Customer */
{
	private CreditCard credit;
	private String track;
	
	public PurchasingCustomer(int num, PersonalInformation info, MailingAddress mail, String track, CreditCard cred)
	{
		super(num, info, mail); //calls the constuctor of the Customer class to set up the num, info, and mail variables
		credit = cred;
		track = track;
	}
	
	public String toString ()
	{
		String info = super.toString() + credit.toString();
		return info;
	}
}

