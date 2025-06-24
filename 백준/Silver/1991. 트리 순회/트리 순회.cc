#include <iostream>
#include <memory>
#include <map>
#include <vector>

using namespace std;

struct Node
{
public:
	shared_ptr<Node> left = nullptr;
	shared_ptr<Node> right = nullptr;

	char value;
};

class Tree
{
public:
	shared_ptr<Node> root = nullptr;

public:
	void preorder()
	{
		if (root != nullptr)
		{
			cout << root->value;
			recursivePreorder(root->left);
			recursivePreorder(root->right);
		}
	}

	void recursivePreorder(const shared_ptr<Node>& node)
	{
		if (node == nullptr)
		{
			return;
		}

		cout << node->value;

		if (node->left != nullptr)
		{
			recursivePreorder(node->left);
		}

		if (node->right != nullptr)
		{
			recursivePreorder(node->right);
		}
	}

	void inorder()
	{
		if (root != nullptr)
		{
			recursiveInorder(root->left);
			cout << root->value;
			recursiveInorder(root->right);
		}
	}

	void recursiveInorder(const shared_ptr<Node>& node)
	{
		if (node == nullptr)
		{
			return;
		}

		if (node->left != nullptr)
		{
			recursiveInorder(node->left);
		}

		cout << node->value;

		if (node->right != nullptr)
		{
			recursiveInorder(node->right);
		}
	}

	void postorder()
	{
		if (root != nullptr)
		{
			recursivePostorder(root->left);
			recursivePostorder(root->right);
			cout << root->value;
		}
	}

	void recursivePostorder(const shared_ptr<Node>& node)
	{
		if (node == nullptr)
		{
			return;
		}

		if (node->left != nullptr)
		{
			recursivePostorder(node->left);
		}

		if (node->right != nullptr)
		{
			recursivePostorder(node->right);
		}
		cout << node->value;
	}
};



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	map<char, shared_ptr<Node>> m;
	shared_ptr<Tree> tree = make_shared<Tree>();

	for (int i = 0; i < N; i++)
	{
		char temp = 'A' + i;
		m[temp] = make_shared<Node>();
		m[temp]->value = temp;
		m[temp]->left = nullptr;
		m[temp]->right = nullptr;

		if (temp == 'A')
		{
			tree->root = m[temp];
		}
	}


	for (int i = 0; i < N; i++)
	{
		char parent, left, right;
		cin >> parent >> left >> right;

		if (left != '.')
		{
			m[left]->value = left;
			m[parent]->left = m[left];
		}
		else
		{
			m[parent]->left = nullptr;
		}

		if (right != '.')
		{
			m[right]->value = right;

			m[parent]->right = m[right];
		}
		else
		{
			m[parent]->right = nullptr;
		}
	}

	tree->preorder();
	cout << '\n';
	tree->inorder();
	cout << '\n';
	tree->postorder();
}