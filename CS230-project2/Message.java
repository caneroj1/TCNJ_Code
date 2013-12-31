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
	// private data for each each message object
	private String Newsg;	// the newsgroup the particular message is from
	private String From;
	private String Subject;
	private String Date;
	private String Message;
	private LinkedSet<String> set;
	
	// constructor method for a message object
	public Message (String Newsg, String From, String Subject, String Date, String Message, LinkedSet<String> set)
	{
		this.Newsg = Newsg;
		this.From = From;
		this.Subject = Subject;
		this.Date = Date;
		this.Message = Message;
		this.set = set;
	}
	
	// accessor method for the message part of the message object 
	public String getMessage ()
	{
		return Message;
	}
	
	// accessor method for the From part of the message object
	public String getFrom ()
	{
		return From;
	}
	
	// accessor method for the Date of the message object
	public String getDate ()
	{
		return Date;
	}
	
	// accessor method for the Subject of the message object
	public String getSubject ()
	{
		return Subject;
	}
	
	// method that will return a boolean indicating if the message part of the
	// message object contains the desired string
	public boolean foundInMessage (String str)
	{
		boolean found = false;
		
		if(Message.toLowerCase().contains(str))
			found = true;
		
		return found;
	}
	
	// method that returns a boolean if the message was posted in more than one newsgroup
	// it does this by checking if there is a comma indicating additional newsgroups
	public boolean checkPost ()
	{
		boolean crossPost;
		
		if(Newsg.contains(","))
			crossPost = true;
		else 
			crossPost = false;
		
		return crossPost;
	}
	
	// compareTo method for each message that that will be used for sorting and determining order of the messages
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
	
	// toString method for the message object that will neatly format the contents of the message and return
	// an informative string
	public String toString ()
	{
		//Prints a summary of the Message Object
		String information = From + "\n" + Subject + "\n" + Date;
		information += "\n------------------------\n";
		
		return information;
	}
}
