/**	Joe Canero, Project 1
*/

public class PersonalInformation /**stores all of the information that makes up the PersonalInformation segment of a Customer */
{
	private String gender;
	private String givenName;
	private String middleI;
	private String surname;
	private String email;
	private String tele;
	private String natID;
	private String birthday;
	
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
	
	public String getGender ()
	{
		return gender;
	}
	
	public String toString ()
	{
		String info = gender + "\t" + givenName + "\t" + middleI + "\t" + surname + "\t" + email + "\t" + tele + "\t" + natID + "\t" + birthday;
		return info;
	}
}
		
