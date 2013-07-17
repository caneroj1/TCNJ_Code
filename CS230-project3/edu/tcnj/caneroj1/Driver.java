/** Joe Canero. Project 3. CSC 230 4/7/12
	This is the driver class for the program. It instantiates an object of type Processor and calls the process method to begin program execution.

*/

package edu.tcnj.caneroj1;
import java.io.*;

public class Driver
{
	public static void main(String[] args) throws IOException
	{
		Processor unit = new Processor();
		unit.process();
	}
}
