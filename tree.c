/* This program has four functions, printParentNode(int *bt, int node), printLeftChildNode(int *bt, int node), printRightChildNode(int *bt, int node), and printNearestCommonAncestor(int *bt, int
node1, int node2) */
/* The main() function runs these four functions with given inputs. */
/* printParentNode(int *bt, int node) prints the parent node of a given node value in a tree, printLeftChildNode(int *bt, int node) prints the left child node of a given node value in a tree,
printRightChildNode(int *bt, int node) prints the right child node of a given node value in a tree, and printNearestCommonAncestor(int *bt, int node1, int node2) which prints the nearest ancestor
of two given node values in a tree */
/* There are two helper functions in addition to the above four and main(). getIndex(int *bt, int node) returns the index of a given node value in a tree. NearestCommonAncestor(int *bt, int
node1, int node2) returns the index of the nearest ancestor of two given node values in a tree. */

#include <stdio.h>

// INPUT: 'bt', a binary tree.
//	'node', a node in the tree.
// OUTPUT: the index of given value in the tree.
int getIndex(int *bt, int node){									
	int counter = 1;						/* This counter represents the index of the array we are looking at - start at 1, the root node */
	while ((*(bt+counter)!= node) && (counter < *bt)){		/* while the value of the current node is not equal to the node we're looking for and the current index is less than the
total number of nodes */	
		counter += 1;						/* check the next index of the array */				
	}
	if ((counter == *bt) && (*(bt+counter)!= node)){		/* if we've checked all the nodes and the final node is not equal to the given node */
		return -1;						/* return -1, signalling that the node doesn't exist in the tree  */
	}
	else{								/* otherwise */
		return counter;						/* return the current index, which should be the index of the given node value  */
	}
}

// INPUT: 'bt', a binary tree.
//	'node ', a node in the tree.
// OUPUT: print the parent node of 'node'. 
void printParentNode (int *bt, int node){					
	int indexno = getIndex(bt, node);					/* indexno is the variable to refer to the index (in the array) of the given node */
	if (indexno == 1){							/* if the index is 1, then the node is a root  */
		printf("\nNode %d is the root and has no parent.\n", node);
		return;
	}
	if (indexno == -1){							/* if the index is -1, then getIndex encountered an error - the node doesn't exist in the tree */
		printf("\nNode %d is not in the given tree.\n", node);		
		return;
	}
	int parentindex = indexno/2;						/* the index of the node's parent is the index of the node divided by 2 */
	int parentvalue = *(bt+parentindex);					/* the value of the node at the calculated parent node index */ 
	printf("\nThe parent node of %d is %d.\n",node,parentvalue); 		
	return;
}

// INPUT: 'bt', a binary tree
//	'node', a node in the tree.
// OUPUT: print the left child of 'node'. 
void printLeftChildNode (int *bt, int node){
	int indexno = getIndex(bt, node);					/* indexno is the variable to refer to the index (in the array) of the given node */
	if (indexno == -1){							/* if the index is 1, then the node is a root */
		printf("\nNode %d is not in the given tree.\n", node);
		return;
	}
	int leftchildindex = 2*indexno;						/* the index of the node's left child is the index of the node multiplied by 2 */
	if (leftchildindex > *bt){						/* if the left child node index is greater than the number of total nodes, then the left child does not exist */
		printf("\nNode %d has no children!\n", node);			/* there can also be no right child */
		return;
	}
	int leftchildvalue = *(bt+leftchildindex);				
	if (*(bt+leftchildindex) == NULL){					/* if the value at the above calculated left child node index is NULL, then the given node doesn't have a left
child */
		printf("\nNode %d has no left child!\n",node);
	}
	else{										
		printf("\nThe left child node of %d is %d.\n",node,*(bt+leftchildindex));	/* otherwise, print the left child node */
	}
	return;
}

// INPUT: 'bt', a binary tree
//	'node', a node in the tree.
// OUPUT: print the right child of 'node' 
void printRightChildNode (int *bt, int node){
	int indexno = getIndex(bt, node); 					/* indexno is the variable to refer to the index (in the array) of the given node */
	if (indexno == -1){							/* if the index is 1, then the node is a root */
		printf("\nNode %d is not in the given tree.\n", node);
		return;
	}
	int rightchildindex = 2*indexno + 1;					/* the index of the node's right child is the index of the node multiplied by 2 and plus 1 */
	if (rightchildindex > *bt){						/* if the right child node index is greater than the number of total nodes, then the right child does not exist */
		printf("\nNode %d has no right child!\n", node);		
		return;
	}
	if (*(bt+rightchildindex) == NULL){						/* if the value at the above calculated right child node index is NULL, then the given node doesn't have a
right child */
		printf("\nNode %d has no right child!\n",node);			
	}	
	else{											
		printf("\nThe right child node of Node %d is %d.\n",node,*(bt+rightchildindex));	/* otherwise, print the right child node */
	}
	return;
}

// INPUT: 'bt', a binary tree
//      'node1', a node in the tree.
//      'node2', a node in the tree.
// OUPUT: return the index of the nearest ancestor of 'node1' and 'node2'.
int NearestCommonAncestor(int *bt, int node1, int node2){
        int indexnode1 = getIndex(bt,node1);     						/* index of the first node */
        int indexnode2 = getIndex(bt,node2);							/* index of the second node */
        int parentindexnode1 = indexnode1/2;							/* index of parent node of a given node is the index of the given node divided by 2 */
        int parentindexnode2 = indexnode2/2;
        if (parentindexnode1 == parentindexnode2){  						/* if the index of the parent of the first node is the same as the second's... */
                return parentindexnode1; 							/* then return the index of the parent of the first node */
        }
        if (parentindexnode1 > parentindexnode2){						/* if the index of the parent of the first node is greater than the second's... */
                return NearestCommonAncestor(bt,*(bt+parentindexnode1),*(bt+indexnode2));	/* then return recursive call using the second node and the parent of the first node */
	}
	if (parentindexnode1 < parentindexnode2){						/* if the index of the parent of the first node is smaller than the second's... */ 
		return NearestCommonAncestor(bt,*(bt+indexnode1),*(bt+parentindexnode2));	/* then return recursive call using the first node and the parent of the second node */
	}
	else{
		return -1;									/* otherwise, return -1, error signal */
	}
}


// INPUT: 'bt', a binary tree
//	'node1', a node in the tree.
//	'node2', a node in the tree.
// OUPUT: print the nearest ancestor of 'node1' and 'node2'. 
void printNearestCommonAncestor(int *bt, int node1, int node2){
	if ((getIndex(bt,node1) == -1) || (getIndex(bt,node2) == -1)){			/* if the index value of the first given node or second given node is -1, then the node(s) don't exist */
		printf("\nOne or more of the given nodes do not exist. \n");		
		return;
	}
	else {
		int answer = *(bt+NearestCommonAncestor(bt,node1,node2));		/* value of the nearest common ancestor node, using the node index from NearestCommonAncestor call */
		printf("\nThe nearest common ancestor of Node %d and Node %d is Node %d. \n", node1,node2,answer);	
		return;
	}
}	

/* binaryTree is an array to encode a binary tree.
The first element of this array is used to encode the number of nodes. */

int main() {

	int binaryTree[11] = {10, 16, 14, 10, 8, 7, 9, 3, 2, 4, 1};	/* array representation of the binary tree */

	printParentNode(binaryTree, 16);
	printParentNode(binaryTree, 3);

	printLeftChildNode(binaryTree, 7);
	printLeftChildNode(binaryTree, 9);

	printRightChildNode(binaryTree, 7);
	printRightChildNode(binaryTree, 10);

	printNearestCommonAncestor(binaryTree, 8, 1);
	printNearestCommonAncestor(binaryTree, 8, 9);

	return 0;
}

