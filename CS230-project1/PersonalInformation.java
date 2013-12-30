/**	Joe Canero, Project 1
 * 	This is the class file for a Personal Information object. A personal information object is stored by each customer
 * 	and contains all of the relevant information for that customer. Each object has a getter method for the gender
 * 	and a toString method.
*/

public class PersonalInformation /**stores all of the information that makes up the PersonalInformation segment of a Customer */
{
	// private data for the personal information object
	private String gender;			
	private String givenName;		// customers first name
	private String middleI;			
	private String surname;
	private String email;
	private String tele;			// telephone number
	private String natID;			// ID of the country where customer is located
	private String birthday;
	
	// constructor method for the Personal Information object
	public PersonalInformation (String givenName, String middleI, String surname, String gender, String email, String natID, String tele, String birthday)
	{
		this.givenName = givenName;
		this.middleI = middleI;
		this.surname = surname;
		this.gender = gender;
		this.email = email;
		this.natID = natID;
		this.tele = tele;
		this.birthday = birthday;
	}
	
	// getter method for the gender attribute
	public String getGender ()
	{
		return gender;
	}
	
	// toString method that will neatly format the information contained in the Personal Information object
	// and return an informative string
	public String toString ()
	{
		String info = gender + "\t" + givenName + "\t" + middleI + "\t" + surname + "\t" + email + "\t" + tele + "\t" + natID + "\t" + birthday;
		return info;
	}
}
		
