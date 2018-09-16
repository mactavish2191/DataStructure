#include <iostream>
#include <stack>
#include <queue>
#include <limits>

struct Binarytree {
	int data;
	Binarytree *left;
	Binarytree *right;
};

Binarytree* createNode(int key) {
	Binarytree *node = new Binarytree;
	if (node == nullptr) {
		std::cerr << "Memory not found.\n";
		return nullptr;
	}
	else {
		node->data = key;
		node->left = nullptr;
		node->right = nullptr;
	}
	return node;
}

void insert(Binarytree **root, int key) {
	//check for empty root
	if (*root == nullptr) {
		*root = createNode(key);
		return;
	}
	else {
		Binarytree *tmp;
		std::queue<Binarytree *> Q;
		Q.push(*root);

		while (Q.empty() != true) {
			tmp = Q.front(); Q.pop();

			if (tmp->left) {
				Q.push(tmp->left);
			}
			else {
				tmp->left = createNode(key);
				return;
			}

			if (tmp->right) {
				Q.push(tmp->right);
			}
			else {
				tmp->right = createNode(key);
				return;
			}

		}

	}
}

int sizeR(Binarytree *root) {
	if (root == nullptr) {
		return 0;
	}
	return (sizeR(root->left) + 1 + sizeR(root->right));
}

//Breadth First Traversal BFT or Level Order Traversal
void BreadthFirstTraversal(Binarytree *root) {
	if (root == nullptr) {
		std::cerr << "No element in tree.\n";
		return;
	}

	Binarytree *tmp;
	std::queue<Binarytree *> Q;
	Q.push(root);

	while (Q.empty() != true) {
		tmp = Q.front(); Q.pop();
		std::cout << tmp->data << " ";
		if (tmp->left)
			Q.push(tmp->left);
		if (tmp->right)
			Q.push(tmp->right);
	}
	std::cout << "\n";
}

//Tree Traversals Recursive
void PreOrderR(Binarytree *root) {
	if (root == nullptr)
		return;
	else {
		std::cout << root->data << " ";
		PreOrderR(root->left);
		PreOrderR(root->right);
	}
}

void InOrderR(Binarytree *root) {
	if (root == nullptr)
		return;
	else {
		InOrderR(root->left);
		std::cout << root->data << " ";
		InOrderR(root->right);
	}
}

void PostOrderR(Binarytree *root) {
	if (root == nullptr)
		return;
	else {
		PostOrderR(root->left);
		PostOrderR(root->right);
		std::cout << root->data << " ";
	}
}

//Tree Traversal Iterative
void PreOrderI(Binarytree *root) {
	if (root == nullptr) {
		return;
	}

	std::stack<Binarytree *> S;
	S.push(root);

	while (S.empty() != true) {
		root = S.top(); S.pop();
		std::cout << root->data << " ";

		if (root->right) {
			S.push(root->right);
		}
		if (root->left) {
			S.push(root->left);
		}
	}
}

void InOrderI(Binarytree *root) {
	if (root == nullptr) {
		return;
	}
	std::stack<Binarytree *> S;

	while (S.empty() != true || root != nullptr) {
		if (root != nullptr) {
			S.push(root);
			root = root->left;
		}
		else {
			root = S.top(); S.pop();
			std::cout << root->data << " ";
			root = root->right;
		}
	}
}

void PostOrderI(Binarytree *root) {
	if (root == nullptr) {
		return;
	}

	std::stack<Binarytree *> S;
	Binarytree *lastNodeVisited = nullptr;

	while (S.empty() != true || root != nullptr) {
		if (root != nullptr) {
			S.push(root);
			root = root->left;
		}
		else {
			Binarytree *peekNode = S.top();
			if (peekNode->right != nullptr && peekNode->right != lastNodeVisited) {
				root = peekNode->right;
			}
			else {
				std::cout << peekNode->data << " ";
				lastNodeVisited = peekNode; S.pop();
			}
		}
	}


}

//Deleting the tree with Postorder recursive traversal
void DeleteTree(Binarytree *root) {
	if (root == nullptr) {
		return;
	}
	else {
		DeleteTree(root->left);
		DeleteTree(root->right);
		delete root;
	}
}

//Find the height of the tree
int heightR(Binarytree *root) {
	if (root == nullptr) {
		return 0;
	}
	else {
		int leftHeight = heightR(root->left);
		int rightHeight = heightR(root->right);

		if (leftHeight > rightHeight) {
			return (leftHeight + 1);
		}
		else {
			return (rightHeight + 1);
		}
	}
}

int heightI(Binarytree *root) {
	if (root == nullptr) {
		return 0;
	}
	int level = 0;
	std::queue<Binarytree *> Q;
	Q.push(root);
	Q.push(nullptr);

	while (Q.empty() != true) {
		root = Q.front(); Q.pop();

		if (root == nullptr) {
			if (Q.empty() != true) {
				Q.push(nullptr);
			}
			level++;
		}
		else {
			if (root->left)
				Q.push(root->left);
			if (root->right)
				Q.push(root->right);
		}
	}

	return level;
}

int deepestNode(Binarytree *root) {
	if (root == nullptr) {
		return -1;
	}

	std::queue<Binarytree *> Q;
	Q.push(root);

	while (Q.empty() != true) {
		root = Q.front(); Q.pop();

		if (root->left)
			Q.push(root->left);
		if (root->right)
			Q.push(root->right);
	}
	return root->data;
}

int leavesCountR(Binarytree *root) {
	if (root == nullptr) {
		return 0;
	}
	else if (root->left == nullptr && root->right == nullptr) {
		return 1;
	}
	else
		return leavesCountR(root->left) + leavesCountR(root->right);
}

int leavesCountI(Binarytree *root) {
	if (root == nullptr) {
		return 0;
	}
	int count = 0;
	std::queue<Binarytree *> Q;
	Q.push(root);

	while (Q.empty() != true) {
		root = Q.front(); Q.pop();

		if (root->left == nullptr && root->right == nullptr) {
			count++;
		}
		else {
			if (root->left)
				Q.push(root->left);
			if (root->right)
				Q.push(root->right);
		}
	}
	return count;
}

int identicalTrees(Binarytree *root1, Binarytree *root2) {
	if (root1 == nullptr && root2 == nullptr)
		return 1;
	if (root1 == nullptr || root2 == nullptr)
		return 0;

	return(root1->data == root2->data && identicalTrees(root1->left, root2->left) && identicalTrees(root1->right, root2->right));
}

int levelMaxSum(Binarytree *root) {
	if (root == nullptr) {
		return -1;
	}

	int maxSum = std::numeric_limits<int>::min();
	int levelSum = 0;
	std::queue<Binarytree *> Q;
	Q.push(root);
	Q.push(nullptr);

	while (Q.empty() != true) {
		root = Q.front(); Q.pop();

		if (root == nullptr) {
			if (Q.empty() != true) {
				Q.push(nullptr);
			}
			if (levelSum > maxSum) { // check the levelSum is greater than maxSum
				maxSum = levelSum;
			}
			levelSum = 0; // reset levelSum
		}
		else {
			levelSum += root->data;
			if (root->left)
				Q.push(root->left);
			if (root->right)
				Q.push(root->right);
		}
	}

	return maxSum;
}

void printPath(Binarytree *root) {

}

int main()
{
	Binarytree *root = nullptr;
	insert(&root, 1);
	insert(&root, 2);
	insert(&root, 3);
	insert(&root, 4);
	insert(&root, 5);
	insert(&root, 6);
	insert(&root, 7);

	BreadthFirstTraversal(root);

	std::cout << "Level Max Sum:" << levelMaxSum(root) << "\n";

	// std::cout << "Size: " << sizeR(root) << "\n";
	// std::cout << "Height: " << heightI(root) << "\n";
	// std::cout << "Deepest Node: " << deepestNode(root) << "\n";
	// std::cout << "Leaves: " << leavesCountI(root) << "\n";
	// std::cout << "Identical: " << identicalTrees(root, root) << "\n";


	// PreOrderR(root); std::cout <<"\n";
	// InOrderR(root); std::cout <<"\n";
	// PostOrderR(root); std::cout <<"\n";
	// PreOrderI(root); std::cout << "\n";
	// InOrderI(root); std::cout << "\n";
	// PostOrderI(root); std::cout << "\n";


	DeleteTree(root);
	return 0;
}