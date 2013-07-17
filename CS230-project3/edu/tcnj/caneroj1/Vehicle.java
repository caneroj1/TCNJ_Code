/** Joe Canero. Project 3. CSC 230 4/7/12
	This is the vehicle class for my project 3. This class maintains the instance data specific to each vehicle, such as what street each starts on and
	which direction it is headed. The class possesses a method called go which creates a String object that gives information telling how the car passed
	through the intersection and what street is is on afterwards.
*/

package edu.tcnj.caneroj1;

public class Vehicle
{
	private int vehNumber;
	streetE Street;
	directionE direction;
	
	private static enum streetE {CHURCH, MAIN}
	private static enum directionE {N, S, E, W}
	
	private int arr_T;
	private int dep_T;
	
	public Vehicle (int vehNumber, int str, int dir)
	{
		this.vehNumber = vehNumber;
		
		
		if(str < 2 && str >= 0)
		{
			switch (str)
			{
				case 0:
					Street = streetE.CHURCH;
					break;
				case 1:
					Street = streetE.MAIN;
					break;
			}
		}
		
		if(dir < 6 && dir >= 2)
		{
			switch(dir)
			{
				case 2:
					direction = directionE.N;
					break;
				case 3:
					direction = directionE.S;
					break;
				case 4:
					direction = directionE.E;
					break;
				case 5:
					direction = directionE.W;
					break;
			}
		}
		
		arr_T = 0;
		dep_T = 0;
		//System.out.println(direction);
		//System.out.println(Street);
	}
	
	public void setArr (int time)
	{
		arr_T = time;
	}
	
	public void setDep (int dTime)
	{
		dep_T = dTime;
	}
	
	private int findWait ()
	{
		int waitT = 0;
		waitT = dep_T - arr_T;
		return waitT;
	}
		
	private String vehicleHeading ()
	{
		String carHeading = "";
		
		if(this.Street == streetE.CHURCH)
		{
			if (this.direction == directionE.N)
				carHeading += "(northbound) moved straight through the interection.";
			if (this.direction == directionE.S)
				carHeading += "(southbound) moved straight through the intersection.";
			if (this.direction == directionE.W)
				carHeading += "(southbound) turned right onto Main Street heading westbound.";
			if (this.direction == directionE.E)
				carHeading += "(northbound) turned right onto Main Street heading eastbound.";
		}
		
		if(this.Street == streetE.MAIN)
		{
			if (this.direction == directionE.N)
				carHeading += "(westbound) turned right onto Church Street heading northbound.";
			if (this.direction == directionE.S)
				carHeading += "(eastbound) turned right onto Church Street heading southbound.";
			if (this.direction == directionE.W)
				carHeading += "(westbound) moved straight through the intersection.";
			if (this.direction == directionE.E)
				carHeading += "(eastbound) moved straight through the intersection.";
		}
		
		return carHeading;
	}
	
	public String go ()
	{
		String result = "Vehicle # " + this.vehNumber + " " + this.vehicleHeading() + " Total wait time " + this.findWait() + " seconds.";
		return result;
	}
	
	public String toString ()
	{
		String info = "Vehicle # " + this.vehNumber + " " + this.vehicleHeading();
		return info;
	}
}
	
	
