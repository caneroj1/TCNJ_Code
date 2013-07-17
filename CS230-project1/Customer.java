/**	Joe Canero, Project 1
*/


public class Customer implements Comparable
{
	protected PersonalInformation personal;
	protected MailingAddress mailing;
	protected int number;

	public Customer (int num, PersonalInformation info, MailingAddress mail)
	{
		personal = info;
		mailing = mail;
		number = num;
	}
	
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
		
	
	public int compareTo (Object object1) //the Arrays.sort method will use this compareTo method to determine the order
	{
		int returnV = 0;
		int zip1 = this.getZipCode();
		String gen1 = this.getGen();
		String add1 = this.getAddress();
		
		Customer custCompare = (Customer)object1;
		int zip2 = custCompare.getZipCode();
		String gen2 = custCompare.getGen();
		String add2 = custCompare.getAddress();
		
		int genComp = gen1.compareTo(gen2);
		int addComp = add1.compareTo(add2);
		
		
		
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
