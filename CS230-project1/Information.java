/**	Joe Canero, Project 1
*/


import java.net.URL;
import java.util.Scanner;
import java.util.Arrays;
import java.io.*;


public class Information
{
	// array for Customer objects
	private Customer[] cust = new Customer[40000];
	
	// constructor method for the information object that will drive the program
	public Information () 
	{
		URL input;
		Scanner iScan;
	}
	
	// method that will drive the program. it processes the data, sorts it and then outputs the results
	public void go () throws IOException
	{
		processData();
		sortData();
		dataOut();
	}
	
	// method to process the data
	private void processData() throws IOException //this method reads from the URL and stores the tokens in their corresponding 
						      //variables
	{
		// initialization of variables for data processing
		int number;
		String gender;
		String givenName;
		String middleI;
		String surname;
		String address;
		int zipCode;
		String email;
		String tele;
		String natID;
		String birthday;
		String ccT;
		String ccN;
		int cvv;
		String ccE;
		String track;
		
		// URL that links to the site where all the data are stored
		URL input = new URL ("http://s3.amazonaws.com/depasquale/datasets/personalData.txt");
		
		// Scanner that will parse the web data
		Scanner iScan = new Scanner (input.openStream());
		Scanner scan;
		
		// array that will store the contents of the web data
		String[] customers = new String[40001];
		int a = 0;
		
		while(iScan.hasNext()) // this stores all of the lines from the URL in an array
		{
			customers[a] = iScan.nextLine();
			a++;
		}
		
		iScan.close(); // close the input stream
		
		String[] newCustomers = new String[40000]; //the customers array is read backwards into the newCustomers array and stops before it reaches the first line of the URL
		
		for (int i = 40000; i > 0; i--)
			newCustomers[i-1] = customers[i];
		
		customers = null;
		input = null;
		
		// loop to process the data	
		for(int i = 0; i < newCustomers.length; i++) //this for loop will read from the newCustomers array
		{	
			scan = new Scanner(newCustomers[i]); //scanner that will go through the array of lines from the URL
			scan.useDelimiter("\\t");
		
			// read the information from the file and store them in each of the data variables 
			// for each customer
			number = scan.nextInt();
			gender = scan.next();
			givenName = scan.next();
			middleI = scan.next();
			surname = scan.next();
			address = scan.next();
				while(!scan.hasNextInt())
					address = address + " " + scan.next();
			zipCode = scan.nextInt();
			email = scan.next();
			tele = scan.next();
			natID = scan.next();
			birthday = scan.next();
			
			// if the customer is a purchasing customer, see if there is a credit card for the customer
			// if the appropriate credit card info is present, the scanner will continue on and store cedit card information
			if(scan.hasNext("MasterCard") || scan.hasNext("Visa")) 
			{
				// scan all of the information pertaining to a purchasing customer
				// and store it in the appropriate variables
				ccT = scan.next();
				ccN = scan.next();
				long num;
				num = Long.parseLong(ccN);
				cvv = scan.nextInt();
				ccE = scan.next();
				track = scan.nextLine();
				
				//a PurchasingCustomer object is instantiated after the PersonalInformation, MailingAddress, and CreditCard objects are instantiated
				PersonalInformation per = new PersonalInformation(givenName, middleI, surname, gender, email, natID, tele, birthday);
				MailingAddress mal = new MailingAddress(address, zipCode);
				CreditCard cre = new CreditCard(ccT, num, cvv, ccE);
				cust[i] = new PurchasingCustomer(number, per, mal, track, cre);
			}
			
			else 
			{
				//a Customer object is instantiated after the PersonalInformation and MailingAddress, objects are instantiated
				PersonalInformation per = new PersonalInformation(givenName, middleI, surname, gender, email, natID, tele, birthday);
				MailingAddress mal = new MailingAddress(address, zipCode);
				cust[i] = new Customer(number, per, mal);
			}
			if(i == 39999)
				scan.close(); //close the scanner
		}
	}
		
	private void sortData () throws IOException //this methods sorts the array
	{
		Arrays.sort(cust);
	}
	
	private void dataOut () throws IOException //this method will print out the sorted array into a .txt file
	{
		FileWriter fw = new FileWriter ("sortedData.txt");
		BufferedWriter bw = new BufferedWriter (fw);
		PrintWriter pw = new PrintWriter (bw);
		
		for(int i = 0; i < cust.length; i++) {
			pw.println(cust[i].toString());
		}
		pw.close();
	}
}
		
		
		
	
	
