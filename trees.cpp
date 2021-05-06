#include<bits/stdc++.h>

using namespace std;


class BinaryTree
{
public:
	int data;
	BinaryTree *left;
	BinaryTree *right;

	BinaryTree(int data)
	{
		this->data = data;
		left = NULL; right = NULL;

	}
	~BinaryTree()
	{
		delete left;
		delete right;
	}

};

void printTree(BinaryTree *root)
{
	if (root == NULL)return;
	cout << root->data << ":";
	if (root->left != NULL)cout << "L-" << root->left->data;
	if (root->right != NULL)cout << " R-" << root->right->data;
	cout << endl;
	printTree(root->left);
	printTree(root->right);
}


BinaryTree *input()
{
	int num;
	// cout << "Enter root data" << endl;
	cin >> num;
	if (num == -1)return NULL;

	BinaryTree *root = new BinaryTree(num);
	BinaryTree *leftData = input();
	BinaryTree *rightData = input();
	root->left = leftData;
	root->right = rightData;


	return root;
}


BinaryTree *inputLevelOrder()
{
	int num; cin >> num;
	if (num == -1)return NULL;
	queue<BinaryTree *>q;

	BinaryTree *root = new BinaryTree(num);
	q.push(root);

	while (!q.empty())
	{
		BinaryTree *front = q.front();
		q.pop();

		int leftChildData, rightChildData;

		cin >> leftChildData;
		if (leftChildData != -1)
		{
			BinaryTree *leftChild = new BinaryTree(leftChildData);
			front->left = leftChild;
			q.push(leftChild);
		}

		cin >> rightChildData;
		if (rightChildData != -1)
		{
			BinaryTree *rightChild = new BinaryTree(rightChildData);
			front->right = rightChild;
			q.push(rightChild);
		}

	}
	return root;
}


void pritLevelOrder(BinaryTree *root)
{
	// if (root == NULL)return ;

	queue<BinaryTree *>pendingNodes;
	// stack<BinaryTree *>
	pendingNodes.push(root);
	// BinaryTree *front = pendingNodes.front();

	// cout << front->left->data << endl;
	// cout << front->right->data << endl;
	while (!pendingNodes.empty())
	{
		BinaryTree *front = pendingNodes.front();
		cout << front->data << ":";
		// BinaryTree *front = pendingNodes.front();
		pendingNodes.pop();
		if (front->left != NULL)
		{
			pendingNodes.push(front->left);
			cout <<  front->left->data << " ";
		}
		// else cout << " N/ ";

		if (front->right != NULL)
		{
			pendingNodes.push(front->right);
			cout <<  front->right->data << " ";
		}
		// else cout <<b " N ";
		cout << endl;
	}
}


void levelOrderReverse(BinaryTree *root)
{
	queue<BinaryTree *>pendingNodes;
	stack<BinaryTree *>reversedNodes;
	pendingNodes.push(root);

	while (!pendingNodes.empty())
	{
		root = pendingNodes.front();
		// cout << front->data << " ";
		pendingNodes.pop();
		reversedNodes.push(root);
		BinaryTree *top =  reversedNodes.top();
		cout << top->data << " ";
		if (root->right != NULL)
		{
			pendingNodes.push(root->right);
		}

		if (root->left != NULL)
		{
			pendingNodes.push(root->left);
		}



		// while (!reversedNodes.empty())
		// {
		// 	root = reversedNodes.top();
		// 	cout << root->data << " ";
		// 	reversedNodes.pop();
		// }
	}
}


int countNode(BinaryTree *root)
{
	if (root == NULL)return 0;

	return 1 + countNode(root->left) + countNode(root->right);
}

bool findNode(BinaryTree *root, int data)
{
	// bool ans = false;
	if (root == NULL)return false;

	if (root->data == data)return true;
	bool ans = findNode(root->left, data);
	if (ans)return 1;

	bool ans1 = findNode(root->right, data);

	return ans1;
}


int height(BinaryTree *root)
{


	if (root == NULL)return 0;
	return max((1 + height(root->right)), (1 + height(root->left)));

}

BinaryTree *mirror(BinaryTree *root)
{

	if (root == NULL)return NULL;

	swap(root->left, root->right);

	if (root->left)mirror(root->left);
	if (root->right != NULL)mirror(root->right);

	return root;
}

// void leftView(BinaryTree *root)
// {
// 	if (root == NULL)return ;

// 	while(root->left || root->right)
// }
void inorder(BinaryTree *root)
{
	if (root == NULL)return;

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);

}

void preOrder(BinaryTree *root)
{
	if (root == NULL)return;

	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);

}

void postOrder(BinaryTree *root)
{

	if (root == NULL)return;

	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
}


int diameter(BinaryTree *root)
{
	if (root == NULL)return 0;

	int option1 = height(root->left) + height(root->right);
	int option2 = diameter(root->right);
	int option3 = diameter(root->left);

	return max(option2, max(option1, option3));

}

pair<int, int>heightDiameter(BinaryTree *root)
{

	if (root == NULL)
	{
		pair<int, int>p;
		p.first = 0;
		p.second = 0;
		return p;
	}

	pair<int, int>leftAns = heightDiameter(root->left);
	pair<int, int>rightAns = heightDiameter(root->right);

	int lh = leftAns.first;
	int ld = leftAns.second;
	int rh = rightAns.first;
	int rd = rightAns.second;

	int height = 1 + max(lh, rd);
	int diameter = max(lh + rh, max(rd, ld));

	pair<int, int>p;
	p.first = height;
	p.second = diameter;

	return p;


}

void createDuplicate(BinaryTree *root)
{
	if (root == NULL)
		return ;


	createDuplicate(root->left);
	createDuplicate(root->right);


	BinaryTree *left = root->left; //7
	BinaryTree *duplicate = new BinaryTree(root->data); //10
	root->left = duplicate; //10
	root->left->left = left; //7




}



void PairSum(BinaryTree *root, int sum)
{

	if (root == NULL)
	{
		return ;
	}

	if (root->data + root->left->data == sum)cout << root->data << " " << root->left->data << endl;
	if (root->data + root->right->data == sum)cout << root->data << " " << root->right->data << endl;
	if (root->left->data + root->right->data == sum)cout << root->left->data << " " << root->right->data << endl;
	PairSum(root->left, sum);
	PairSum(root->right, sum);
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	BinaryTree *root = inputLevelOrder();
	// BinaryTree *node1 = new BinaryTree(2);
	// BinaryTree *node2 = new BinaryTree(3);
	// root->left = node1;
	// root->right = node2;
	// cout << root->data << ": " << root->left->data << ", " << root->right->data << endl;
	// BinaryTree *newNode = new BinaryTree(4);
	// node1->left = newNode;
	// BinaryTree *newNode1 = new BinaryTree(5);
	// node1->right = newNode1;
	// cout << node1->data;
	// cout << node1->data << ": " << node1->left->data << ", " << node1->right->data;

	// BinaryTree *node3 = new BinaryTree(6);

	// printTree(root);
	// levelOrderReverse(root);
	// cout << endl;
	// pritLevelOrder(root);
	// printTree(node1);
	// cout << endl;
	// cout << countNode(root) << endl;
	// if (findNode(root, 2))cout << "Node got" << endl;
	// else cout << "Not found" << endl;

	// cout << height(root);
	// cout << endl;
	pritLevelOrder(root);
	cout << endl;
	// BinaryTree *NewTree = mirror(root);
	// printTree(NewTree);

	// leftView(root);
	// cout << "Inorder:";
	// inorder(root);

	// cout << endl;
	// cout << "PreOrder:";
	// preOrder(root)1;

	// cout << endl;
	// cout << "postOrder:";
	// postOrder(root);
	// cout << diameter(root);/
	// createDuplicate(root);
	// pritLevelOrder(root);
	PairSum(root, 15);
	// cout << vp[0].first;
}