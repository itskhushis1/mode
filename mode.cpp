#include <iostream>
 
using namespace std;
 
// A structure to represent a node.
struct list
{
	int data;
	int count;
	list *next;
};
 
// Function to insert data into linked list.
list* insertinlist(list *head, int n)
{
	// Creating newnode and temp node.
	list *newnode = new list;
	list *temp = new list;
 
	// Using newnode as the node to be inserted in the list.
	newnode->data = n;
	newnode->count = 0;
	newnode->next = NULL;
 
	// If head is null then assign new node to head and increase the count.
	if(head == NULL)
	{
		head = newnode;
		head->count++;
		return head;
	}
	else
	{
		temp = head;
 
		// If newnode->data is lesser than head->data, then insert newnode before head and increase the count.
		if(newnode->data < head->data)
		{
			newnode->next = head;
			head = newnode;
			newnode->count++;
			return head;
		}
		// If newnode->data is equal to the head data then increase count of the head node.
		else if(newnode->data == head->data)
		{
			head->count++;
			return head;
		}
 
		// Traverse the list till we get value more than or equal to the newnode->data.
		while(temp->next != NULL)
		{
			// If equals to any of the data present in the list then increse the counter and return.
			if(newnode->data == (temp->next)->data)
			{
				(temp->next)->count++;
				return head;
			}
			if(newnode->data < (temp->next)->data)
				break;
 
			temp=temp->next;
		}
 
		// Insert newnode after temp.
		newnode->next = temp->next;
		temp->next = newnode;
		// Increase the counter.
		newnode->count++;
		return head;
	}	
}	
 
int main()
{
    int n, i, num, max = 0, c;
    // Declaring head of the linked list.
    list *head = new list;
    head = NULL;
 
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;
 
	for(i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>num;
		// Inserting num in the list.
		head = insertinlist(head, num);
	}
 
	// Printing the sorted data.
	cout<<"\nSorted Distinct Data ";
 
	while(head != NULL)
	{
    		if(max < head->count)
    		{
    			c = head->data;
			max = head->count;
		}
		cout<<"->"<<head->data<<"("<<head->count<<")";
		head = head->next;
	}
 
	cout<<"\nThe Mode of given data is "<<c<<" and occurred "<<max<<" times.";
	return 0;
}
