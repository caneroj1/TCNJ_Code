/**	Joe Canero, Project 1
 * 	This is the class file for a Customer object. It inherits from Comparable and is therefore able to be compared to
 * 	similar objects.
*/


public class Customer implements Comparable
{
	// data for each Customer. Each customer has its personal information, mailing address, and phone number.
	protected PersonalInformation personal;
	protected MailingAddress mailing;
	protected int number;

	// constructor method
	public Customer (int num, PersonalInformation info, MailingAddress mail)
	{
		personal = info;
		mailing = mail;
		number = num;
	}
	
	// this toString method will neatly format the data in the Customer object and return a string
	public String toString ()
	{
		String info = ( (personal.toString()) + "\t" + (mailing.toString()) + "\t");
		return info;
	}
	
	public int getZipCode ()  //accessor method for getting the zipCode from the mailing object
	{
		int zip = mailing.getZip();
		return zip;
	}
	
	public String getGen () //accessor method for getting the gender from the personal object
	{
		String gender = personal.getGender();
		return gender;
	}
	
	public String getAddress () //accessor method for getting the address from the mailing object
	{
		String address = mailing.getAdd();
		return address;
	}
		
	// the Arrays.sort method will use this compareTo method to determine the order
	// each Customer object will be compared to the other customer objects with this method's custom
	// comparison routine that sorts each customer according to the following prioritization: Gender, ZipCode, Address
	public int compareTo (Object object1) 
	{
		int returnV = 0;					// return value
		int zip1 = this.getZipCode();				// zip code of calling customer object
		String gen1 = this.getGen();				// gender of calling customer object		
		String add1 = this.getAddress();			// address of calling customer object
		
		Customer custCompare = (Customer)object1;
		int zip2 = custCompare.getZipCode();			// zip code of passed customer object
		String gen2 = custCompare.getGen();			// gender of passed customer object
		String add2 = custCompare.getAddress();			// address of passed customer object
		
		int genComp = gen1.compareTo(gen2);			// compare genders
		int addComp = add1.compareTo(add2);			// compared addresses
		
		
		// the following logic will return the relative order of the two compared customers
		// a return value of 0 indicates lexicographic equality, a number < 0 means the calling customer object 
		// is lexicographically before, and a number > 0 means the calling customer object is lexicographically after
		if(genComp > 0 && zip1 == zip2)
			returnV = -1;
		if(genComp < 0 && zip1 == zip2)
			returnV = 1;
		if(genComp == 0 && zip1 == zip2 && addComp < 0)
			returnV = -1;
		if(genComp == 0 && zip1 == zip2 && addComp > 0)
			returnV = 1;
		if(genComp == 0 && zip1 == zip2 && addComp == 0)
			returnV = 0;
		if(zip1 > zip2)
			returnV = 1;
		if(zip1 < zip2)
			returnV = -1;
			
		return returnV;
	}
	

			
}
