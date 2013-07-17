/**
	Joe Canero. CSC 230. Project 2. 3/30/12
	
	This is the driver class for Project 2. Instantiates a Processor object and begins program.
*/

import java.io.*;

public class Driver
{
	public static void main(String[] args) throws IOException
	{
		Processor process = new Processor("newsgroups");
		process.execution();
	}
}