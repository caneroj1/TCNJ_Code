/**	Joe Canero, Project 1
*/


import java.io.*;

public class Driver //this class instantiates an Information object and calls "go" to execute the proper methods
{
	public static void main (String[] args) throws IOException
	{
		Information processor = new Information();
		processor.go();
	}
}
