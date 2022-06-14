#include <iostream>

using namespace std;

typedef int info;
struct node
{
	node* left,
		* right;
	info info;
	char ch;
};

node* createtree(int nodecount);
void printtree(node* root, int level);
node* binarysearchinsert(node*& root, info value, bool& found);

int main()
{
	bool found = false;
	char ch;
	int n;
	info value;

	cout << "enter nodes count: "; cin >> n;
	node* root = createtree(n);
	cout << endl;

	printtree(root, 0);

	do {
		cout << "value: "; cin >> value;
		node* n;
		n = binarysearchinsert(root, value, found);
		if (found == true)
			cout << "find true" << endl;
		else
			cout << "find false" << endl;
		cout << "to continue : y/n " << endl; cin >> ch;
	} while (ch == 'y' || ch == 'y');

	return 0;
}

node* createtree(int nodecount)
{
	if (nodecount == 0)
		return NULL;
	else
	{
		node* newnode = new node;

		cout << " enter node value: ";
		cin >> newnode->info;
		cout << " enter node symbol: ";
		cin >> newnode->ch;

		int leftcount = nodecount / 2;
		int rightcount = nodecount - leftcount - 1;
		newnode->left = createtree(leftcount);
		newnode->right = createtree(rightcount);
		return newnode;
	}
}
void printtree(node* root, int level)
{
	if (root != NULL)
	{
		printtree(root->right, level + 1);
		for (int i = 1; i <= level; i++)
			cout << "   ";
		cout << root->info;
		cout << root->ch << endl;
		printtree(root->left, level + 1);
	}
}

node* binarysearchinsert(node*& root, info value, bool& found)
{
	if (root == NULL)
	{
		root = new node;
		root->info = value;
		root->left = NULL;
		root->right = NULL;
		found = false;
		return root;
	}
	else
		if (value == root->info)
		{
			found = true;
			return root;
		}
		else
			if (value < root->info)
				return binarysearchinsert(root->left, value, found);
			else
				return binarysearchinsert(root->right, value, found);
}


//.........................................................................................
//
//#include <iostream>
//#include <fstream>
//#include <windows.h>
//#include <conio.h>
//#include <string>
//
//using namespace std;
//
//typedef int Info;
//
//struct Node
//{
//	Node* left,
//		* right;
//	int k = 1;
//	Info info;
//	char ch;
//};
//
//
//
//
//void BalanceHeight(Node*& root);
//void InsertNode(Node* root);
//void DisplayTree(Node* root, int level);
//void DeleteNodeOfTree(Node* Tree);
//void DeleteBranchOfTree(Node*& Tree);
//void DestroyTree(Node* Root);
//int Height(Node* Root);
//int Leaves(Node* Root);
//
//
//
//
//
//Node* CreateTree(int nodeCount);
//void PrintTree(Node* root, int level);
//
//
//
//int main(int argc, TCHAR* argv[])
//{
//
//	Node* root = NULL;
//	int N, min = -9999999999;
//	int i = 0;
//	
//
//	while (true) {
//		cout << endl << endl;
//		cout << "0  - Create" << endl;
//		cout << "1  - Print" << endl;
//		cout << "3  - Zbalansyvatu" << endl;
//		cout << "4  - Delete Node Of Tree" << endl;
//		cout << "5  - Delete Branch Of Tree" << endl;
//		cout << "6  - Display Tree" << endl;
//		cout << "7  - Insert Node" << endl;
//		cout << "9  - Destroy Tree" << endl;
//		cout << "Enter - ";
//		cin >> i;
//		switch (i) {
//
//		case 0: 
//			cout << "Enter nodes count: "; cin >> N;
//			root = CreateTree(N); cout << endl; break;
//		case 1: PrintTree(root, 0); cout << endl; break;
//		case 3: BalanceHeight(root); break;
//		case 4: DeleteNodeOfTree(root); break;
//		case 5: DeleteBranchOfTree(root); break;
//		case 6: DisplayTree(root, 0); break;
//		case 7: InsertNode(root); break;
//		case 9: DestroyTree(root);
//			return 0;
//		}
//	}
//
//	return 0;
//
//
//	system("pause");
//	return 0;
//}
//
//Node* CreateTree(int nodeCount)
//{
//	if (nodeCount == 0)
//		return NULL;
//	else
//	{
//		Node* newNode = new Node;
//
//		cout << " Enter node value: ";
//		cin >> newNode->info;
//		cout << " Enter node symbol: ";
//		cin >> newNode->ch;
//
//		int leftCount = nodeCount / 2;
//		int rightCount = nodeCount - leftCount - 1;
//		newNode->left = CreateTree(leftCount);
//		newNode->right = CreateTree(rightCount);
//		return newNode;
//	}
//}
//
//void PrintTree(Node* root, int level)
//{
//	if (root != NULL)
//	{
//		PrintTree(root->right, level + 1);
//		for (int i = 1; i <= level; i++)
//			cout << "  ";
//		cout << root->info;
//		cout << root->ch << endl;
//		PrintTree(root->left, level + 1);
//	}
//}
//
//
//
//
//void Include(Node*& R, Info value) {
//	if (R == NULL) {
//		R = new Node;
//		R->info = value;
//		R->left = R->right = NULL;
//	}
//	else  if (value == R->info) R->k++; else {
//		if (value < R->info)  Include(R->left, value);
//		else if (value > R->info) Include(R->right, value);
//	}
//}
//
//void CreateTree(Node*& root) {
//	int n;
//	Info data;
//	DestroyTree(root);
//	root = NULL;
//	cout << "??????? ????????? ????????? - ";
//	cin >> n;
//	if (n < 1) return;
//	for (int i = 1; i <= n; i++) {
//		cout << "??????? -" << i << "  ";
//		cin >> data;
//		Include(root, data);
//	}
//}
//
//void InsertNode(Node* root) {
//	Info data;
//	cout << endl;
//	cout << "??????? ??????? ";
//	cin >> data;
//	Include(root, data);
//	cout << endl << endl;
//	cout << "Leaves: " << Leaves(root) << endl;
//	cout << "Height: " << Height(root) << endl << endl;
//}
//
//void Backpass(Node* T) {
//	if (T != NULL) {
//		Backpass(T->left);
//		cout << T->info << "   ";
//		Backpass(T->right);
//	}
//}
//
//void PrefixBackpass(Node* T) {
//	if (T != NULL) {
//		cout << T->info << "   ";
//		PrefixBackpass(T->left);
//		PrefixBackpass(T->right);
//	}
//}
//
//void  PostfixBackpass(Node* T) {
//	if (T != NULL) {
//		PostfixBackpass(T->left); PostfixBackpass(T->right);
//		cout << T->info << "   ";
//	}
//}
//
//void BackpassCount(Node* T, int& k) {
//	if (T != NULL) {
//		BackpassCount(T->left, k); k++;
//		BackpassCount(T->right, k);
//	}
//}
//
//
//void DestroyTree(Node* Root) {
//	Node* L, * R;
//	if (Root == NULL) return; L = Root->left;
//	R = Root->right;
//	delete Root; DestroyTree(L); DestroyTree(R);
//}
//
//int Leaves(Node* Root) {
//	if (Root == NULL) return 0;
//	else if ((Root->left == NULL) && (Root->right == NULL)) return 1;
//	else return(Leaves(Root->left) + Leaves(Root->right));
//}
//
//int Max(int x, int y) {
//	if (x > y) return x;
//	else return y;
//}
//
//int Height(Node* Root) {
//	int hL, hR;
//	if (Root == NULL) return 0;
//	hL = Height(Root->left);
//	hR = Height(Root->right); return (1 + Max(hL, hR));
//}
//
//void RightRotation(Node*& root) {
//	Node* tmp1 = root->left; Node* tmp2 = tmp1->right;
//	tmp1->right = root; root->left = tmp2; root = tmp1;
//}
//
//void LeftRotation(Node*& root) {
//	Node* tmp1 = root->right; Node* tmp2 = tmp1->left;
//	tmp1->left = root; root->right = tmp2; root = tmp1;
//}
//
//int Height_(Node* root) {
//	if (root == NULL) return 0;
//	int hL = Height_(root->left);
//	int hR = Height_(root->right);
//	if (hL > hR) return hL + 1;
//	else return hR + 1;
//}
//
//int bfactor(node* root) {
//	return height_(root->right) - height_(root->left);
//}
//
//void balanceheight(node*& root) {
//	if (root != null) {
//		balanceheight(root->left);
//		balanceheight(root->right);
//		if (bfactor(root) == 2) {
//			if (bfactor(root->right) < 0)
//				rightrotation(root->right);
//			leftrotation(root);
//		}
//		if (bfactor(root) == -2) {
//			if (bfactor(root->left) > 0)
//				leftrotation(root->left);
//			rightrotation(root);
//		}
//	}
//}
//
//int NodeCount(Node* T) {
//	int k = 0;
//	if (T != NULL) {
//		NodeCount(T->left);
//		if ((T->left != NULL) && (T->right != NULL)) k++;
//		NodeCount(T->right);
//	}
//	return k;
//}
//
//int rightmost(Node* root) {
//	while (root->right != NULL)
//		root = root->right;
//	return root->info;
//}
//
//Node* DeleteNode(Node* root, Info val)
//{
//	if (NULL == root) return NULL;
//	if (root->info == val) {
//		if (NULL == root->left && NULL == root->right) {
//			free(root); return NULL;
//		}
//		if (NULL == root->right && root->left != NULL) {
//			Node* temp = root->left; free(root); return temp;
//		}
//		if (NULL == root->left && root->right != NULL) {
//			Node* temp = root->right;
//			free(root);
//			return temp;
//		}
//		root->info = rightmost(root->left);
//		root->left = DeleteNode(root->left, root->info); return root;
//	}
//	if (val < root->info) {
//		root->left = DeleteNode(root->left, val); return root;
//	}
//	if (val > root->info) {
//		root->right = DeleteNode(root->right, val); return root;
//	}
//	return root;
//}
//
//void DeleteNodeOfTree(Node* Tree) {
//	Info data;
//	cout << endl << endl;
//	cout << "Enter node who want delete: ";
//	cin >> data;
//	Tree = DeleteNode(Tree, data);
//}
//
//void RemoveBranch(Node*& root, int X, Node* V, BOOL B) {
//	if (root != NULL)
//		if (X < root->info) {
//			V = root; B = true; RemoveBranch(root->left, X, V, B);
//		}
//		else if (X > root->info) {
//			V = root; B = false; RemoveBranch(root->right, X, V, B);
//		}
//		else {
//			DestroyTree(root);
//			if (B) V->left = NULL;
//			else V->right = NULL; return;
//		}
//	return;
//}
//
//void DeleteBranchOfTree(Node*& Tree) {
//	Info data;
//	cout << endl << endl;
//	cout << "Enter branch who want delete: ";
//	cin >> data;
//	if (data == Tree->info) {
//		DestroyTree(Tree); Tree = NULL; return;
//	}
//	else RemoveBranch(Tree, data, NULL, true);
//}
//
//void DisplayTree(Node* root, int level)
//{
//	if (root != NULL)
//	{
//		DisplayTree(root->right, level + 1);
//		for (int i = 1; i <= level; i++) cout << "  ";
//		cout << root->info << endl;
//		DisplayTree(root->left, level + 1);
//	}
//}
//
//
