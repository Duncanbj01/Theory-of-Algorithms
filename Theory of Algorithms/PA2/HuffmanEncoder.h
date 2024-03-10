#include <unordered_map>
#include <string>
#include <queue>
#include "BinaryTreeNode.h"
#include "BinaryTreeNodeComparator.h"

#ifndef HUFFMANENCODER_H_
#define HUFFMANENCODER_H_

class HuffmanEncoder {
    
	int encodingLength;
	int tableSize;
	unordered_map<char, string> charToEncodingMapping;
    unordered_map<char, int> frequencyMap;

public:

	HuffmanEncoder(unordered_map<char, int> freqMap) {
		frequencyMap = freqMap;
		encodingLength = tableSize = 0;
	}
    
    ~HuffmanEncoder() {
        
    }

    void encode() 
	{ // complete this method
		BinaryTreeNode* root = buildTree(); 
		createTable(root, ""); 

		//iteration over frequency map
		for (auto it = frequencyMap.begin(); it != frequencyMap.end(); ++it)
		{
			char c = it->first; 
			int f = it->second; 
			string code = getEncoding(c); 
			encodingLength += f * code.length();
			tableSize += code.length() + 8; 
		}

    }
    
private:

    BinaryTreeNode *buildTree() 
	{ // complete this method
		priority_queue<BinaryTreeNode*, vector<BinaryTreeNode*>, BinaryTreeNodeComparator> PQ; 

		for (auto it = frequencyMap.begin(); it != frequencyMap.end(); ++it)
		{
			char c = it->first; 
			int f = it->second; 
			BinaryTreeNode* z = new BinaryTreeNode(c, f); 
			PQ.push(z); 
		}

		while (PQ.size() > 1)
		{
			BinaryTreeNode* min = PQ.top(); 
			PQ.pop(); 
			BinaryTreeNode* secondMin = PQ.top(); 
			PQ.pop(); 
			BinaryTreeNode* z = new BinaryTreeNode('\0', min->value + secondMin->value); 
			z->left = min; 
			z->right = secondMin; 

			PQ.push(z); 

			//delete min; 
			//delete secondMin; 
		}
		return PQ.top();
		
		/*return top node from priority queue
		BinaryTreeNode* roor = PQ.top();
		PQ.pop(); 
		return root; */
    }

    void createTable(BinaryTreeNode *node, string encoding) 
	{ // complete this method
		if (node->left == nullptr && node->right == nullptr)
		{
			charToEncodingMapping[node->character] = encoding;
		}
		else
		{
			if (node->left != nullptr)
			{
				createTable(node->left, encoding + "0");
				//delete node->left; 
			}
			if (node->right != nullptr)
			{
				createTable(node->right, encoding + "1");
				//delete node->right; 
			}
		}
    }

public:

	string getEncoding(char c) {
		return charToEncodingMapping[c];
	}

	int getTableSize() {
		return tableSize;
	}

	int getEncodingLength() {
		return encodingLength;
	}
};

#endif /* HUFFMANENCODER_H_ */
