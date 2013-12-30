/**	Joe Canero, Project 1
 * 	This is the class file for a Purchasing Customer object. It extends a regular customer as this type of customer object
 * 	has purchasing information, like a credit card number and a tracking number for their purchase.
*/

public class PurchasingCustomer extends Customer /**this object uses the PersonalInformation, MailingAddress, and CreditCard classes to create a Purchasing Customer */
{
	private CreditCard credit;		// stores a credit card object
	private String track;			// tracking number for purchase
	
	// constructor method
	// a purchasing customer, just like a regular customer, has personal information and mailing objects, with the 
	// addition of the tracking number and credit card object
	public PurchasingCustomer(int num, PersonalInformation info, MailingAddress mail, String track, CreditCard cred)
	{
		super(num, info, mail); //calls the constuctor of the Customer class to set up the num, info, and mail variables
		credit = cred;
		track = track;
	}
	
	// toString method that will format the purchasing customer's data. It calls the toString method of a regular
	// customer and also the toString method of the Credit Card object to properly format the string.
	public String toString ()
	{
		String info = super.toString() + credit.toString();
		return info;
	}
}

