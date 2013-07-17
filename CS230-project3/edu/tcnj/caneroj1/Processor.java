/** Joe Canero. Project 3. CSC 230 4/7/12
	This is the Processor class for my project 3. It maintains the 8 LinkedQueues, populates them, and manages them as the simulation progresses.
	This class' process method will begin the traffic simulation. It checks each lane on each side of Church Street and Main Street and allows to traffic
	progress as elaborated in the project spec file.
*/

package edu.tcnj.caneroj1;

import java.util.Random;
import java.io.*;
import javafoundations.*;
import javafoundations.exceptions.*;

public class Processor
{
	int allCars;
	int time = 0;
	int carCount;
	LinkedQueue<Vehicle>[] q = (LinkedQueue<Vehicle>[]) new LinkedQueue[8];

	
	Random rand = new Random();
	
	public Processor ()
	{
		allCars = 1;
		for(int j = 0; j < q.length; j++)
			q[j] = new LinkedQueue<Vehicle>();
	}
	
	private void populate (int floor, int ceiling)
	{
		int randCap = rand.nextInt(ceiling - floor + 1);
		randCap += floor;
		
		
		for(int i = 0; i < randCap; i++)
		{
			if(carCount != 100)
			{
				int s = rand.nextInt(2);
				int d = rand.nextInt(4) + 2;
			
				Vehicle motorCar = new Vehicle(carCount+1, s, d);
				motorCar.setArr(time);
			
				if(s == 0)
				{
					if(d == 2)
						q[0].enqueue(motorCar);
					if(d == 3)
						q[2].enqueue(motorCar);
					if(d == 4)
						q[1].enqueue(motorCar);
					if(d == 5)
						q[3].enqueue(motorCar);
				}
				if(s == 1)
				{
					if(d == 2)
						q[5].enqueue(motorCar);
					if(d == 3)
						q[7].enqueue(motorCar);
					if(d == 4)
						q[6].enqueue(motorCar);
					if(d == 5)
						q[4].enqueue(motorCar);
				}
			
			carCount += 1;
			}
		}
	}
		
		public void process () throws IOException
		{
			PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
			this.populate(5, 10);
			int carC = 0;
			Vehicle current = null;
			int carsAllowed = 0;
			while(!q[0].isEmpty() || !q[1].isEmpty() || !q[2].isEmpty() || !q[3].isEmpty() || !q[4].isEmpty() || !q[5].isEmpty() || !q[6].isEmpty() || !q[7].isEmpty())
			{
				pw.println("---Light Changed. Now processing north/south-bound traffic---");
				
				for(int t = 0; t < 2; t++)
				{
					time +=3;
					
					if(q[0].size() + q[1].size() + q[2].size() + q[3].size() > 0)
					{
							if(!q[0].isEmpty() && carsAllowed < 4)
							{
								current = q[0].dequeue();
								current.setDep(time);
								//System.out.println("[Time: " +time + "] " + current.go());
								pw.println(("[Time: " +time + "] " + current.go()));
								pw.flush();
								carC += 1;
								carsAllowed++;
							}
					
							if(!q[2].isEmpty() && carsAllowed < 4)
							{
								current = q[2].dequeue();
								current.setDep(time);
								//System.out.println("[Time: " +time + "] " + current.go());
								pw.println(("[Time: " +time + "] " + current.go()));
								pw.flush();
								carC += 1;
								carsAllowed++;
							}
					
							if(!q[1].isEmpty() && carsAllowed < 4)
							{
								current = q[1].dequeue();
								current.setDep(time);
								//System.out.println("[Time: " +time + "] " + current.go());
								pw.println(("[Time: " +time + "] " + current.go()));
								pw.flush();
								carC += 1;
								carsAllowed++;
							}
					
							if(!q[3].isEmpty() && carsAllowed < 4)
							{
								current = q[3].dequeue();
								current.setDep(time);
								//System.out.println("[Time: " +time + "] " + current.go());
								pw.println(("[Time: " +time + "] " + current.go()));
								pw.flush();
								carC += 1;
								carsAllowed++;
							}
							//System.out.println(carsAllowed);
							//System.out.println("here");
					}
					carsAllowed = 0;
					}
					
				
					
					
					allCars -= carC;
					carC = 0;
					this.populate(5, 12);
					
				pw.println("---Light Changed. Now processing east/west-bound traffic---");
				
				for(int r = 0; r < 3; r++)
				{
					time +=3;
					
					if(q[4].size() + q[5].size() + q[6].size() + q[7].size() > 0)
					{
							if(!q[4].isEmpty() && carsAllowed < 4)
							{
								current = q[4].dequeue();
								current.setDep(time);
								//System.out.println("[Time: " +time + "] " + current.go());
								pw.println(("[Time: " +time + "] " + current.go()));
								pw.flush();
								carC += 1;
								carsAllowed++;
							}
					
							if(!q[6].isEmpty() && carsAllowed < 4)
							{
								current = q[6].dequeue();
								current.setDep(time);
								//System.out.println("[Time: " +time + "] " + current.go());
								pw.println(("[Time: " +time + "] " + current.go()));
								pw.flush();
								carC += 1;
								carsAllowed++;
							}
					
							if(!q[5].isEmpty() && carsAllowed < 4)
							{
								current = q[5].dequeue();
								current.setDep(time);
								//System.out.println("[Time: " +time + "] " + current.go());
								pw.println(("[Time: " +time + "] " + current.go()));
								pw.flush();
								carC += 1;
								carsAllowed++;
							}
					
							if(!q[7].isEmpty() && carsAllowed < 4)
							{
								current = q[7].dequeue();
								current.setDep(time);
								//System.out.println("[Time: " +time + "] " + current.go());
								pw.println(("[Time: " +time + "] " + current.go()));
								pw.flush();
								carC += 1;
								carsAllowed++;
							}
							//System.out.println(carsAllowed);
					}
					carsAllowed = 0;
				}
					allCars -= carC;
					
					carC = 0;
					this.populate(3, 15);
					//System.out.println(carCount);
			}
			pw.close();
		}                        
				
			}
					
				
				
				
				
				
							
				
				
				
				
				
				
				
