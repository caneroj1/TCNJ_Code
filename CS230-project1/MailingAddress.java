/**	Joe Canero, Project 1
 * 	This is the class file for a Mailing Address object. These objects are stored in each Customer object and contain
 * 	the following information: address, state, city, and zip code. The mailing address object has getter methods for its
 * 	data and also a toString method that formats the information
*/

import java.util.Scanner;
import java.text.NumberFormat;
import java.text.DecimalFormat;

public class MailingAddress //stores the appropriate information for a mailing address
{
	// mailing address data
	private String address;
	private String state;
	private String city;
	private int zipCode;
	
	// constructor method
	public MailingAddress (String address, int zipCode)
	{ 		
		this.address = address;
		this.zipCode = zipCode;
		state = address.substring(address.length() - 2, address.length());
	}

	// getter method for the zip code
	public int getZip ()
	{
		return zipCode;
	}
	
	// getter method for the address
	public String getAdd ()
	{
		return address;
	}
	
	// toString method that will neatly format the contents of the mailing address and return a string
	// containing the mailing address object's information
	public String toString () //this uses the NumberFormat object to affix zipcodes with leading zeros.
	{
		address = address.substring(0, address.length() - 3);
		NumberFormat fmt = new DecimalFormat ("00000");
		String info = (address + " " + state + "\t" + (fmt.format(zipCode)));
		return info;
	}
}
		
