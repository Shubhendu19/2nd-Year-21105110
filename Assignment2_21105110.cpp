//Ans 1
//Let's take an example
#include <bits/stdc++.h>
using namespace std;

class Node
{
	public:
	int data;
	Node *next;
};
void push(Node **head_ref, int data)
{
	Node *ptr1 = new Node();
	Node *temp = *head_ref;
	ptr1->data = data;
	ptr1->next = *head_ref;
	if (*head_ref != NULL)
	{
		while (temp->next != *head_ref)      //<== This Condition states that the traversal has reached the first element
			temp = temp->next;
		temp->next = ptr1;
	}
	else
		ptr1->next = ptr1;

	*head_ref = ptr1;
}
void printList(Node *head)
{
	Node *temp = head;
	if (head != NULL)
	{
		do
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		while (temp != head);
	}
}

int main()
{
	Node *head = NULL;
	push(&head, 15);
	push(&head, 50);
	push(&head, 20);
	push(&head, 10);

	cout << "Result:  ";
	printList(head);

	return 0;
}



//In the above code the condition [while (temp->next != *head_ref) temp = temp->next;] states the traversal has reached the first element


/*Ans 2
> Round Robin scheduling technique in games - Basically each player matches up with other players at least once
> Audio/Video Streaming - Example- Music Playlist
> Circular Escalators
> App Overview in phones -  The operating software keeps on iterating over these applications. */
