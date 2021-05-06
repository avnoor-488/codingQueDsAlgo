#include<bits/stdc++.h>
using namespace std;


class Node
{

public:
	int data;
	Node *next;

	Node(int num)
	{
		this->data = num;
		next = NULL;
	}

	~Node()
	{
		delete next;
	}
};



void print(Node *head)
{
	if (head == NULL)cout << "LL empty";
	Node *temp = head;
	if (temp == NULL)return;
	else
	{
		while (temp != NULL)
		{
			if (temp->next == NULL)cout << temp->data << " ";
			else
				cout << temp->data << "->";

			temp = temp->next;
		}

	}
}

Node * insert()
{
	int num;
	cin >> num;

	Node *head = NULL;
	Node *tail = NULL;
	while (num != -1)
	{
		Node *newNode = new Node(num);

		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = tail->next;
		}
		cin >> num;
	}
	return head;
}

int lengthLL(Node *head)
{
	int count = 0;
	Node *temp = head;
	if (head == NULL)
	{
		return 0;
	}
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count ;
}


void printNthNode(Node *head, int key)
{
	Node *temp = head;
	int count = 1;
	int len = lengthLL(head);
	if (key > len)cout << "-1";
	else if (head == NULL)cout << "-1";
	else
	{
		while (count != len)
		{
			if (key == count)cout << temp->data;
			temp = temp->next;
			count++;
		}
	}
}


Node *insertAtNthNode(Node *head, int data, int pos)
{

	int count = 0;
	Node *temp = head;
	Node *newNode = new Node(data);
	Node *prvNode;

	if (pos == 0)
	{
		newNode->next = head;
		return newNode;
	}

	else {
		while (temp != NULL & count < pos - 1)
		{
			temp = temp->next;
			count++;
		}
		if (temp !=  NULL)
		{
			prvNode = temp->next;
			temp->next = newNode;
			newNode->next = prvNode;
		}

		return head;
	}
}

Node *deleteNode(Node *head, int pos)
{
	Node *temp = head;
	Node *prv = NULL;
	int count;
	if (pos == 0)
	{
		temp = head->next;
		// head;
		return temp;
	}
	else {
		while (temp != NULL && count < pos - 1)
		{

			temp = temp->next;
			count++;
		}

		Node *next = temp->next->next;
		// delete temp->next;
		temp->next = next;
		return head;
	}
}

Node * middlePoint(Node *head)
{

	int len = lengthLL(head), count = 0, data;
	Node *temp = head;
	Node *newList = NULL;
	if (len == 1)return head;
	if (head == NULL)return NULL;
	else
	{
		int mid = len / 2 - 1;
		while (temp != NULL && count < mid )
		{
			temp = temp->next;
			count++;
		}
		// break;
		newList = temp->next;

	}

	return newList;
}

Node* divide(Node *head, int n)
{
	Node *temp = head;
	Node *oddHead = NULL;
	Node *oddTail = NULL;
	Node *evenTail = NULL;
	Node *evenHead = NULL;


	while (temp != NULL)
	{
		if (temp->data % 2 == 0)
		{
			// int num=temp->data;
			if (evenHead == NULL)
			{
				// Node *newNode = new Node(num);
				// cout << temp->data << " ";
				evenHead = temp;
				evenTail = temp;
			}
			else
			{
				// Node *newNode = new Node(num);
				// cout << temp->data << " ";
				evenTail->next = temp;
				evenTail = evenTail->next;
			}
		}
		else
		{
			if (oddHead == NULL)
			{
				// Node *newNode = new Node(num);
				// cout << temp->data << " ";
				oddHead = temp;
				oddTail = temp;
			}
			else
			{
				// Node *newNode = new Node(num);
				// cout << temp->data << " ";
				oddTail->next = temp;
				oddTail = oddTail->next;
			}
		}
		temp = temp->next;

	}

	if (evenHead == NULL )return oddHead;
	else if (oddHead == NULL)return evenHead;
	evenTail->next = oddHead;
	oddTail->next = NULL;



	return evenHead;

}

void reverseBetween(Node* head, int m, int n)
{
	Node *temp = head;
	Node *newList = NULL;
	int len = lengthLL(head);
	Node *newListTail = NULL;
	vector<int>v;
	// if (head == NULL)return head;


	int count = 1;
	while (temp != NULL)
	{
		if (count == m)
		{

			newList = temp;
			while (count != n)
			{
				v.push_back(temp->data);
				count++;
				temp = temp->next;
			}
			temp = temp->next;

			v.push_back(temp->data);
			break;
		}
		else
			count++;
	}
	// cout << v.size() << endl;
	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)cout << v[i] << " ";


	while (len--)
	{
		temp = temp->next;
		temp->next = temp;

	}


	// return head;
}


void reverse(Node* head, int k)
{
	// vector<int>v;
	Node *curr = head;
	Node *prevous = NULL;
	Node *next = NULL;
	Node  *temp = NULL;
	int count = 0;
	Node *tail = NULL;
	while (curr != NULL && count < k )
	{
		if (count == k - 1 )tail = curr->next;
		next = curr->next;
		curr->next = prevous;
		prevous = curr;
		curr = next;
		count++;
		// cout << count << endl;
	}
	temp = prevous;
	while (prevous->next != NULL)
	{
		if (prevous->next == NULL)temp->next = tail;
		prevous = prevous->next;
	}

	// cout << head->data;
	cout << temp->data << " " << temp->next->data << " ";
	cout << tail->data << " " << tail->next->data << " " << tail->next->next->data;
}




Node *addoOne(Node *head)
{
	Node *temp = head;
	int count = 0;
	Node *prev = NULL;
	Node  *tail = NULL;
	while (temp != NULL)
	{

		if (temp->next == NULL)temp = tail;
		temp = temp->next;

	}

	tail->data = tail->data + 1;
	temp = head;
	while (temp != NULL)
	{

		if (temp->next == NULL)temp = tail;
		temp = temp->next;

	}
	// temp=head;


	return head;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Node *head = insert();

	print(head);
	int len = lengthLL(head);
	cout << endl;
	// cout << len << endl;
	// printNthNode(head, 1);
	// reverse(head, 5);
	Node *head1 = insertAtNthNode	(head, 100, 9);
	print(head1);

}