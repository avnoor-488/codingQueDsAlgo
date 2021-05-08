#include<bits/stdc++.h>
using namespace std;

class PriorityQueue
{
public:
	vector<int>vi;


	bool isEmpty()
	{
		return vi.size() == 0;
	}

	int getSize()
	{
		return vi.size();
	}

	int getMin()
	{
		if (isEmpty())return 0;

		return vi[0];
	}

	void insert(int element)
	{
		vi.push_back(element);

		int childIndex, parentIndex;
		childIndex = vi.size() - 1;
		while (childIndex > 0  )
		{
			parentIndex = (childIndex - 1) / 2;
			if (vi[childIndex] < vi[parentIndex])swap(vi[parentIndex], vi[childIndex]);
			else break;
			childIndex = parentIndex;
		}

	}

	int deleteElement()
	{
		if (isEmpty())return 0;


		int ans = vi[0];
		swap(vi[0], vi[vi.size() - 1]);
		vi.pop_back();

		int rightChild, leftChild, parentIndex = 0;
		leftChild = (2 * parentIndex) + 1;
		rightChild = (2 * parentIndex) + 2;

		while (leftChild < vi.size()   and rightChild < vi.size() )
		{
			int minIndex = parentIndex;
			if (vi[leftChild] < vi[minIndex])minIndex = leftChild;
			if ( vi[rightChild] < vi[minIndex]) minIndex = rightChild;
			if (minIndex == parentIndex)break;

			swap(vi[parentIndex], vi[minIndex]);


			parentIndex = minIndex;
			leftChild = (2 * parentIndex) + 1;
			rightChild = (2 * parentIndex) + 2;
		}




		return ans;
	}




};

vector<int> mergeKArrays(vector<vector<int>> vec, int K)
{
	//code here
	vector<int>ans;
	priority_queue <int, vector<int>, greater<int>> pq;
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++)
			pq.push(vec[i][j]);
		// cout << endl;//
	}

	while (!pq.empty())
	{
		ans.push_back(pq.top());
		pq.pop();
	}

	return ans;
}


void mergeHeaps(int merged[], int a[], int b[], int n, int m) {

	priority_queue<int>pq;

	for (int i = 0; i < n; i++)pq.push(a[i]);

	for (int i = 0; i < m; i++)pq.push(b[i]);


	int i = 0;
	while (!pq.empty())
	{
		merged[i] = pq.top();
		pq.pop();
		i++;
	}
}


int kthSmallest(int arr[], int l, int r, int k) {
	//code here
	priority_queue<int, vector<int>, greater<int>>pq;
	for (int i = 0; i < r; i++)
		pq.push(arr[i]);

	int count = 1;
	while (count != k)
	{
		pq.pop();
		count++;
	}

	return pq.top();
}


int main()
{
	PriorityQueue pq;
	pq.insert(0);
	pq.insert(1);
	pq.insert(20);
	pq.insert(3);
	pq.insert(4);
	pq.insert(5);
	// pq.insert(0);
	cout << pq.getSize() << " " << endl;
	while (!pq.isEmpty())
		cout << pq.deleteElement() << " ";

}