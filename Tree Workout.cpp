

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

struct tnode
{	
	int count = 0;
	int val;
	tnode *lchild;
	tnode *rchild;	
};
tnode* root;
//new node function
tnode* myNewNode()
{
	tnode *temp;
	temp = new tnode;
	temp->val = 0;
	temp->lchild = NULL;
	temp->rchild = NULL;
	return temp;
}
//insert function
void insert(tnode *r, int v)
{		
	tnode* prev;
	prev = NULL;
		
	if (r->val == v)
	{

	}
	while (r != NULL)
	{		
		prev = r;
		if (v < r->val)			
			r = r->lchild;		
		else		
			r = r->rchild;		
	}
	r = myNewNode();
	r->val = v;
	r->count=1;
	if (prev == NULL)
	{
		root = r;
	}
	if (prev != NULL)
	{
		if (v < prev->val)
		{
			prev->lchild = r;
		}
		else
		{
			prev->rchild = r;
		}
	}	
}
//search function
tnode* search(tnode *r,int v)
{
	while (r != NULL&&r->val!=v)
	{		
		if (v < r->val)
		{
			r = r->lchild;
		}
		else			
		{			
			r = r->rchild;			
		}
	}
	if (r != NULL)
	{
		if (r->val == v)
		{
			r->count++;
		}
	}
	return r;
}


//printing in order
void printinorder(tnode* r,int k,int &cnt)
{	
	if (r == NULL)
		return;

	printinorder(r->lchild, k, cnt);
		if (cnt < k)
		{
			cout << r->val << " ";
			++cnt;
		}
	printinorder(r->rchild, k, cnt);
}

//printing in postorder
void printpostorder(tnode* r,int k,int &cnt)
{
	if (r == NULL)
		return;
	
	printpostorder(r->lchild, k, cnt);
	printpostorder(r->rchild, k, cnt);
	if (cnt < k)
	{
		cout << r->val << " ";
		++cnt;
	}
	
}

//printing in preorder
void preorder(tnode* r,int k,int &cnt) 
{
	if (r == NULL)
		return;
	if (cnt < k)
	{
		cout << r->val << " ";
		++cnt;
	}	
	preorder(r->lchild,k,cnt);
	preorder(r->rchild,k,cnt);	
}


//D. & L counting how many nodes in tree
int size(tnode* r)
{
	if (r == NULL)
		return 0;
	else
		return(size(r->lchild) + 1 + size(r->rchild));
}
//F. Number of duplicates
int numofdups(tnode* r)
{
	if (r == r->lchild)	
		return(numofdups(r->lchild) + 1 + numofdups(r->rchild));
	if (r == r->rchild)
		return(numofdups(r->lchild) + 1 + numofdups(r->rchild));
}

//E. & M summing the tree
int sum(tnode* r)
{
	if (r == NULL)
		return 0;
	else
		return(sum(r->lchild) + r->val + sum(r->rchild));
}

//G. Count the number of leafs in the tree
int leaftcount(tnode* r, float& total)
{
	if (r == NULL)
	{
		return 0;
	}
	leaftcount(r->lchild, total);
	if (r->lchild == NULL && r->rchild == NULL)
	{
		total++;
	}
	leaftcount(r->rchild, total);
	return total;
}


//H. nodes with only one child function
size_t getchildcount(tnode* r)
{	
	if (!r)
		return 0;
	return getchildcount(r) + getchildcount(r->lchild) + getchildcount(r->rchild);
	
}
size_t number_children(const tnode* t)
{
	int count = 0;
	if (t->lchild != NULL) count++;
	if (t->rchild != NULL) count++;
	return count;
}
size_t tree_one_child(const tnode* t)
{
	if (!t || number_children(t) == 0)
	{
		return 0;
	}
	if (number_children(t) == 1)
	{
		return 1 + tree_one_child(t->lchild) + tree_one_child(t->rchild);
	}
	else
	{
		return tree_one_child(t->lchild) + tree_one_child(t->rchild);
	}
}	

//I. Print the value taht is the deepest leaf down in the tree
tnode* deepestleaf(struct tnode* r)
{
	struct tnode* present = r;
	while (present && present->lchild != NULL)
		present = present->lchild;
	return present;
}
int sumthedigits(int x)
{
	if (x == 0)
		return 0;

	return(x % 10 + sumthedigits(x / 10));
}
//J. Delete
struct tnode* deleting(struct tnode* r, int k)
{
	if (r == NULL)
		return root;

	if (k < r->val)
		r->lchild = deleting(r->lchild, k);

	else if (k > r->val)
		r->rchild = deleting(r->rchild, k);

	else
	{
		if (r->lchild == NULL)
		{
			struct tnode* temp = r->rchild;
			free(r);
			return temp;
		}
		else if (r->rchild == NULL)
		{
			struct tnode* temp = r->lchild;
			free(r);
			return temp;
		}

		struct tnode* temp = deepestleaf(r->rchild);

		r->val = temp->val;
	}
	return r;
}

void nine(tnode* r)
{
	if (r == NULL)
	{
		return;
	}
	nine(r->lchild);
	int a = r->val;
	int b = sumthedigits(a);

	if (b < 9)
	{
		deleting(root, a);
		return;
	}
	nine(r->rchild);
}

void printdeepest(tnode* ptr)
{
	printf("Value: %d\n", *ptr);
}





int main()
{
	ifstream infile;
	ofstream outfile;
	float thesum=0;
	int thesize = 0;
	int dupecount = 0;
	int numtoprint = 20;
	int countforprint = 0;
	int val, count, numofleafs;
	float total = 0;
	count = 0;	
	infile.open("TreeNbrsV2...txt");
	outfile.open("Tree results.txt");
	
	if (!infile)
	{
		
		cout << "Error opening file, shutting down";
		system("pause");
		return 0;
	}

	while (!infile.eof())
	{
		int i = 0;
		infile >> val;
		if (search(root, val))
		{
			thesum = thesum + val;
			thesize = thesize++;
			dupecount++;
		}
		else
		{
			insert(root, val);
			i++;
		}
	}

	//A. printing in order
	cout << "In order" << endl;
	printinorder(root,numtoprint,countforprint);
	cout << endl;
	//B. printing in preorder
	countforprint = 0;
	cout << "Preorder" << endl;
	preorder(root,numtoprint,countforprint);
	cout << endl;
	//C. printing in postorder
	countforprint = 0;
	cout << "Postorder" << endl;
	printpostorder(root,numtoprint,countforprint);
	cout << endl;
	//D. print out number of nodes	
	thesize=thesize+size(root);
	cout << "There are " << thesize << " nodes in the tree." << endl;
	//E. printing out the sum and average	
	float theaverage;
	thesum =thesum+ sum(root);
	cout << "The sum of all the values in the tree, including duplicates, is: " << thesum << endl;
	theaverage = thesum / thesize;
	cout << "The average of all the values in the tree is: " <<fixed<<setprecision(2)<< theaverage << endl;
	//F. Count the number of duplicates that were read in
	cout << "There were " << dupecount << " duplicates read in, but not added to the tree. " << endl;
	//G.Count the number of leafs in the tree 
	numofleafs=leaftcount(root, total);
	cout << "Number of leafs: " << numofleafs << endl;
	//H. Print the number of nodes that have only one child
	int numofnodesone;
	numofnodesone = tree_one_child(root);
	cout << "Number of nodes with only one child: " << numofnodesone << endl;
	//I. Print the value that is the deepest leaf down in the tree
	tnode* answer = deepestleaf(root);
	cout << "The deepest leaf ";
	printdeepest(answer);
	int c = 0;
	//J. Delete
	while (c < count)
	{
		nine(root);
		c++;
	}
	//K. printing in order
	printinorder(root,numtoprint,countforprint);
	cout << endl;
	//L. print out number of nodes	
	int thesize2;
	thesize2 = size(root);
	cout << "There are " << thesize2 << " nodes in the tree." << endl;
	//M. Sum up all values in the tree
	float thesum2;
	float theaverage2;
	thesum2 = sum(root);
	cout << "The sum of all the values in the tree, including duplicates, is: " << thesum2 << endl;

	system("pause");
	return 0;
}
