/**	Joe Canero, Project 1
*/

import java.util.Scanner;
import java.text.NumberFormat;
import java.text.DecimalFormat;

public class MailingAddress //stores the appropriate information for a mailing address
{
	private String address;
	private String state;
	private String city;
	private int zipCode;
	
	public MailingAddress (String address, int zipCode)
	{ 		
		this.address = address;
		this.zipCode = zipCode;
		state = address.substring(address.length() - 2, address.length());
	}

	
	public int getZip ()
	{
		return zipCode;
	}
	
	public String getAdd ()
	{
		return address;
	}
	
	public String toString () //this uses the NumberFormat object to affix zipcodes with leading zeros.
	{
		address = address.substring(0, address.length() - 3);
		NumberFormat fmt = new DecimalFormat ("00000");
		String info = (address + " " + state + "\t" + (fmt.format(zipCode)));
		return info;
	}
}
		
