/**
	Joe Canero. CSC 230. Project 2 3/30/12
	
	This class handles the functionality of the Message objects. It stores all relevant data. Important headers receive their own reference while
	those less integral to the program are placed into a LinkedSet.
	
	This class also includes getters, methods for checking if the message is cross posted, if the message contains a certain word, if the message is equal to
	another message, and a message that returns a String representation.
*/

import javafoundations.*;

public class Message implements Comparable<Message>
{
	private String Newsg;
	private String From;
	private String Subject;
	private String Date;
	private String Message;
	private LinkedSet<String> set;
	
	public Message (String Newsg, String From, String Subject, String Date, String Message, LinkedSet<String> set)
	{
		this.Newsg = Newsg;
		this.From = From;
		this.Subject = Subject;
		this.Date = Date;
		this.Message = Message;
		this.set = set;
	}
	
	public String getMessage ()
	{
		return Message;
	}
	
	public String getFrom ()
	{
		return From;
	}
	
	public String getDate ()
	{
		return Date;
	}
	
	public String getSubject ()
	{
		return Subject;
	}
	
	public boolean foundInMessage (String str)
	{
		boolean found = false;
		
		if(Message.toLowerCase().contains(str))
			found = true;
		
		return found;
	}
	
	public boolean checkPost ()
	{
		boolean crossPost;
		
		if(Newsg.contains(","))
			crossPost = true;
		else 
			crossPost = false;
		
		return crossPost;
	}
	
	public int compareTo(Message object)
	{
		
		int compareResult = 1;
		String date = object.getDate();
		String from = object.getFrom();
		String subject = object.getSubject();
		
		if((this.getMessage()).compareTo (date) == 0)
		{
			if((this.getMessage()).compareTo (subject) < 0)
			{
				if((this.getMessage()).compareTo (from) > 0)
					compareResult = 0;
			}
		}
		
		else
			compareResult = 1;
		
		return compareResult;
	}
	
	public String toString ()
	{
		//Prints a summary of the Message Object
		String information = From + "\n" + Subject + "\n" + Date;
		information += "\n------------------------\n";
		
		return information;
	}
}
