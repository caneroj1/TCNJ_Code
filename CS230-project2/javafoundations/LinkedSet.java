//********************************************************************
//	LinkedSet.java	Joe Canero Project 2. 3/30/12
//
//	Defines the Linked Set class
//
//	Defines methods that were implemented from the Set ADT.
//********************************************************************
package javafoundations;

import javafoundations.exceptions.*;

public class LinkedSet<T extends Comparable<T>> implements Set<T>
{	

	private int count;
	private LinearNode<T> top;
	
	public LinkedSet()
	{
		count = 0;
		top = null;
	}
	
	//Adds the specified element to the set
	public void add(T element)
	{
		if(!this.contains(element))
		{
			LinearNode<T> node = new LinearNode (element);
			node.setNext(top);
			top = node;
			count++;
		}
	}

	//Removes the specified element from the set
	public T remove (T element) throws ElementNotFoundException
	{

		T result = null;
			if(count == 0)
				throw new ElementNotFoundException ("Pop operation failed. " + "The stack is empty.");
			else
			{
				LinearNode<T> current = top;
				LinearNode<T> nextNode = current.getNext();
				
				while((nextNode.getElement()).compareTo(element) != 0 && (current.getNext()) != null)
				{
					current = current.getNext();
					nextNode = current.getNext();
				}
				if((nextNode.getElement()).compareTo(element) != 0)
				{
					LinearNode<T> previous = current;
					current = current.getNext();
					nextNode = null;
				
					previous.setNext(current.getNext());
					current.setNext(null);
					result = current.getElement();
					current = null;
					count--;
				}
				
				return result;
			}
	}
	
	//Returns a true value if the specified element is a member of the set
	public boolean contains (T element)
	{
		boolean contains = false;
		
		if(top != null)
		{
			LinearNode<T> current = top;
			for(int i = 0; i < this.size(); i++)
			{
				if(current.getElement() == element || (current.getElement()).compareTo(element) == 0)
					contains = true;
				
				current = current.getNext();
			}
		}
			
		return contains;
		
	}
			
			
	
	//Returns true if the set contains no elements and false otherwise
	public boolean isEmpty()
	{
		if(count == 0)
			return true;
		else
			return false;
	}
	
	//Returns  the number of elements in the set
	public int size()
	{
		return count;
	}
	
	
	//Returns a string representation of the set
	public String toString()
	{
		String details = "";
		
		LinearNode<T> item = top;
		for(int a = 0; a < this.size(); a++)
		{
			details += ((item.getElement()).toString());
			item = item.getNext();
		}
	
		return details;
	}
	
	public T get(int num) throws ElementNotFoundException
	{		
		if(num < 0 || num > count)
			throw new ElementNotFoundException ("The number entered is outside usable range.");
		else
		{
		LinearNode<T> item = top;		
		for(int a = 0; a < num; a++)
			item = item.getNext();

		return item.getElement();
		}
	}
		
		
		
		
		
		
		
		
		
}
	
