/**
	Joe Canero. CSC 230. Project 2. 3/30/12
	
	This class handles the main functionality of the program. It stores and operates on an array of LinkedSets that store the Message objects of each newsgroup.
	
	This class also contains methods for dealing with the various requirements in the spec file.
	
	All output is printed to a text file.
*/


import java.util.Scanner;
import java.io.*;
import javafoundations.LinkedSet;
import javafoundations.Set;
import javafoundations.LinearNode;
import javafoundations.exceptions.*;
import java.util.Arrays;

public class Processor 
{
	
	final PrintWriter pw;
	final FileWriter fw;
	final BufferedWriter bw;
	
	private String mainDir;
	
	private LinkedSet<Message>[] linkedSet = (LinkedSet<Message>[]) (new LinkedSet[20]);
		
	private int a = 0;
		
		public Processor (String str) throws IOException
		{
			fw = new FileWriter ("p2Output.txt");
			bw = new BufferedWriter (fw);
			pw = new PrintWriter (bw);
			mainDir = str;
		}
		
		public void execution () throws IOException
		{
		 this.processMessages();
 	 	 this.checkCrossPost();
 	 	 this.checkMessages("computer", 2);
 	 	 this.checkMessages("capital", 3);
 	 	 this.doEmails();
 	 	}
		
		private void processMessages () throws IOException
		{
			String newsgroups = "";
			String from = "";
			String subject = "";
			String date = "";
			String message = "";
			
			pw.println("-----------------------------------------\nSection 0: Newsgroup Counts\n-----------------------------------------\n");
			for(int c = 0; c < 20; c++)
 	 	 			linkedSet[c] = new LinkedSet<Message>();
			
			Scanner scan;
			File dataDir = new File("newsgroups");
			String[] nameOfDir = new String[20];
 	 	 
			if (dataDir.isDirectory())
			{
				 String [] dirListing = dataDir.list();
				
 	 	 	 	 for (String name : dirListing)
 	 	 	 	 {
 	 	 	 	 	 if(!name.equals(".DS_Store"))
 	 	 	 	 	 	 {
 	 	 	 	 	
 	 	 	 	 	File dirFile = new File("newsgroups" , name);
 	 	 	 	 	nameOfDir[a] = name;
 	 	 	 
 	 	 	 	 	if (dirFile.isDirectory())
 	 	 	 	 		System.out.println("Directory: " + dirFile);
 	 	 	 
 	 	 	 	 	String [] tempFiles = dirFile.list();
 	 	 	 	 	
 	 	 			for(int i = 0; i < tempFiles.length; i++)
 	 	 			{
 	 	 	 	 		if(tempFiles[i].length() > 5)
 	 	 	 	 			i++;
 	 	 	 	 		
 	 	 	 	 		File input = new File(dirFile, tempFiles[i]);
 	 	 	 	 		 	 		
 	 	 	 	 		int lineCount = this.headerLength(input);
 	 	 	 	 		
 	 	 	 	 		FileInputStream read = new FileInputStream (input);
 	 	 	 	 		BufferedInputStream buffer = new BufferedInputStream (read);

 	 	 	 	 		scan = new Scanner (buffer);
 	 	 	 	 		scan.useDelimiter("\n");
 	 	 	 	 		
 	 	 	 	 		String[] header = new String[lineCount];
 
 	 	 	 	 		for(int b = 0; b < lineCount; b++)
 	 	 	 	 		{
 	 	 	 	 			header[b] = scan.next();
 	 	 	 	 		}
 	 	 	 	 		
 	 	 	 	 		
 	 	 	 	 		for(int c = 0; c < lineCount; c++)
 	 	 	 	 		{
 	 	 	 				if (header[c].contains("From:") || header[c].contains("from:"))
 	 	 	 				{
 	 	 	 					from = header[c].substring(5, header[c].length());
 	 	 	 					header[c] = null;
 	 	 	 				}
 	 	 	 				
 	 	 	 				if(header[c] != null)
 	 	 	 				{
 	 	 	 					if (header[c].contains("Newsgroups:") || header[c].contains("newsgroups:"))	
 	 	 	 					{
 	 	 	 						newsgroups = header[c].substring(11, header[c].length());
 	 	 	 						header[c] = null;
 	 	 	 					}
 	 	 	 				}
 	 	 	 				
 	 	 	 				if(header[c] != null)
 	 	 	 				{
 	 	 	 					if (header[c].contains("Subject:") || header[c].contains("subject:"))
 	 	 	 					{
 	 	 	 						subject = header[c].substring(8, header[c].length());
 	 	 	 						header[c] = null;
 	 	 	 					}
 	 	 	 				}
 	 	 	 				
 	 	 	 				if(header[c] != null)
 	 	 	 				{
 	 	 	 					if (header[c].contains("Date:") || header[c].contains("date:"))
 	 	 	 					{
 	 	 	 						date = header[c].substring(5, header[c].length());
 	 	 	 						header[c] = null;
 	 	 	 					}
 	 	 	 				}
 	 	 	 				
 	 	 	 					
 	 	 	 	 		
 	 	 	 	 		}
 	 	 	 	 		
 	 	 	 	 		LinkedSet<String> headerSet = new LinkedSet<String>();
 	 	 	 	 		
 	 	 	 	 		for(int joe = 0; joe < lineCount; joe++)
 	 	 	 	 		{
 	 	 	 	 			if(header[joe] != null)
 	 	 	 	 				headerSet.add(header[joe]);
 	 	 	 	 		}
 	 	 	 	 			
 	 	 	 	 		message = "";
 	 	 	 	 		while(scan.hasNext())
 	 	 	 	 			message += scan.nextLine() + "\n";
 	
 	 	 	 	 		Message message1 = new Message (newsgroups, from, subject, date, message, headerSet);

 	 	 	 	 		linkedSet[a].add(message1);
 	 	 	 	 		 	 	 	 	
 	 	 	 	 		from = "";
 	 	 	 	 		newsgroups = "";
 	 	 	 	 		subject = "";
 	 	 	 	 		date = "";
 	 	 	 	 		headerSet = null;
 	 	 	 	 	}
 	 	 	 		a++;
 	 	 	 		}
 	 	 	 		
 	 	 	 	 	
 	 	 	 	 }
 	 	 	 	 }
 	 	 	 	 for(int h = 0; h < linkedSet.length; h++)
 	 	 	 	 {
 	 	 	 	 	pw.println("Directory: " + nameOfDir[h] + " \tTotal Number of Messages: " + linkedSet[h].size());
 	 	 	 	 	pw.flush();
 	 	 	 	 }
 	 	 	}
 	 	 	
 	 	 	private int headerLength (File file) throws IOException
 	 	 	{
 	 	 		FileInputStream read = new FileInputStream (file);
 	 	 		BufferedInputStream buffer = new BufferedInputStream (read);
 	 	 		Scanner scan3 = new Scanner (read);
 	 	 		int count = 1;
 	 	 		String line = scan3.nextLine();
 	 	 		do
 	 	 		{
 	 	 			boolean a = line.contains(":");
 	 	 			if(a || line.contains("a") || line.contains("e") || line.contains("i") || line.contains("o") || line.contains("u"))
 	 	 			{
 	 	 				line = scan3.nextLine();
 	 	 				count++;
 	 	 			}
 	 	 			else
 	 	 			{	
 	 	 				scan3.useDelimiter("\n");
 	 	 				scan3.nextLine();
 	 	 			}
 	 	 				
 	 	 		}
 	 	 		while(scan3.hasNext());
 	 	 		scan3.close();
 	 	 		return count;
 	 	 	}
 	 	 	
 	 	 	private void checkCrossPost ()
 	 	 	{
 	 	 		int house = 0;
 	 	 		String posted = "";
 	 	 		
 	 	 		for(int poo = 0; poo < 20; poo++)
 	 	 		{
 	 	 			for(int e = 0; e < linkedSet[poo].size(); e++)
 	 	 			{
 	 	 				if(linkedSet[poo].get(e).checkPost())
 	 	 				{
 	 	 					posted += linkedSet[poo].get(e) + "\n";
 	 	 					house++;
 	 	 				}
 	 	 			}
 	 	 		}
 	 	 		pw.println("\n-----------------------------------------\nSection 1: Cross-Posted Analysis\n-----------------------------------------\nTotal Number of Cross-Posted Messages: " + house + "\n-----------------------------------------\n");
 	 	 		pw.println(posted );
 	 	 		pw.flush();
 	 	 	}
 	 	 	
 	 	 	private void checkMessages (String str, int cou)
 	 	 	{
 	 	 		int numb = 0;
 	 	 		String checked = "";
 	 	 		
 	 	 		for(int p = 0; p < 20; p++)
 	 	 		{
 	 	 			for(int e = 0; e < linkedSet[p].size(); e++)
 	 	 			{
 	 	 				if(linkedSet[p].get(e).foundInMessage(str))
 	 	 				{
 	 	 					checked += linkedSet[p].get(e) + "\n";
 	 	 					numb++;
 	 	 				}
 	 	 			}
 	 	 		}
 	 	 		pw.println("\n-----------------------------------------\nSection " + cou + ": Message Bodies Containing " +  str + "\n-----------------------------------------\nTotal Number of Messages: " + numb + "\n-----------------------------------------\n");
 	 	 		pw.println(checked);
 	 	 		pw.flush();
 	 	 	}
 	 	 	
 	 	 	private void doEmails ()
 	 	 	{
 	 	 		int emailCount = 0;
 	 	 		LinkedSet<String> emails = new LinkedSet<String> ();
 	 	 		String tMess = "";
 	 	 		String tFrom = "";
 	 	 		String[] emailArr;
 	 	 		Scanner emailScan;
 	 	 		
 	 	 		for(int q = 0; q < 20; q++)
 	 	 		{
 	 	 			for(int r = 0; r < linkedSet[q].size(); r++)
 	 	 			{
 	 	 				tMess = (linkedSet[q].get(r)).getMessage();
 	 	 				tFrom = (linkedSet[q].get(r)).getFrom();
 	 	 				
 	 	 				emailScan = new Scanner(tMess);
 	 	 				
 	 	 				emails.add(tFrom);
 	 	 				emailCount++;
 	 	 				
 	 	 				while(emailScan.hasNext())
 	 	 				{
 	 	 					String iToken = emailScan.next();
 	 	 					if(iToken.contains("@") && (iToken.contains(".") /*|| iToken.contains("e") || iToken.contains("i") || iToken.contains("o") || iToken.contains("u"))*/))
 	 	 					{
 	 	 						emails.add(iToken);
 	 	 						emailCount++;
 	 	 					}
 	 	 				}
 	 	 						
 	 	 					
 	 	 			}
 	 	 		}
 	 	 		
 	 	 		
 	 	 		emailArr = new String[emails.size()];
 	 	 		
 	 	 		for(int z = 0; z < emailArr.length; z++)
 	 	 			emailArr[z] = emails.get(z);
 	 	 		
 	 	 		Arrays.sort(emailArr);
 	 	 		pw.println("\n-----------------------------------------\nSection 4: Email List\n-----------------------------------------\nTotal Number of Emails: " + emailCount + "\n-----------------------------------------\n");
 	 	 		
 	 	 		for(int z = 0; z < emailArr.length; z++)
 	 	 		{
 	 	 			if(emailArr[z].contains("@") && (emailArr[z].contains(".") && (emailArr[z].contains("a") || emailArr[z].contains("e") || emailArr[z].contains("i") || emailArr[z].contains("o") || emailArr[z].contains("u"))))
 	 	 				pw.println(emailArr[z]);
 	 	 		}
 	 	 		
 	 	 		pw.flush();
 	 	 		pw.close();
 	 	 	}

}


