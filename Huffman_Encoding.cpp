#include<bits/stdc++.h>
using namespace std;

// Node structure for Huffman Tree
struct Node{
    char data;
    unsigned freq;
    Node *left, *right;
    Node(char data, int freq){
        this->data = data;
        this->freq = freq;
        this->left = NULL;
        this->right = NULL;
    }
};

// Comparison function for priority queue
struct Compare{
    bool operator()(Node* left, Node* right){
        return left->freq > right->freq; // Compares frequencies of nodes
    }
};

// Function to build the Huffman Tree from the input string
Node* buildHuffmanTree(const string &s){
    map<char, int> mpp;
    
    // Calculate frequency of each character in the input string
    for(char ch : s){
        mpp[ch]++;
    }
    
    // Priority queue to store nodes (min heap based on frequencies)
    priority_queue<Node*, vector<Node*>, Compare> pq;
    
    // Create a leaf node for each character and push it into the priority queue
    for(auto &it : mpp){
        pq.push(new Node(it.first, it.second));
    }
    
    // Build Huffman Tree by combining the two nodes with the lowest frequencies until only one node remains
    while(pq.size() > 1){
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();
        
        // Create a new internal node with '$' as data and the sum of frequencies of left and right nodes
        Node* internalNode = new Node('$', left->freq + right->freq);
        internalNode->left = left;
        internalNode->right = right;
        
        // Add the new internal node to the priority queue
        pq.push(internalNode);
    }
    return pq.top(); // Return the root of the Huffman Tree
}

// Function to generate Huffman Codes for each character in the tree
void generate(Node* root, string code, map<char, string> &ans){
    if(root == NULL){
        return;
    }
    if(!root->left && !root->right){
        ans[root->data] = code; // Store Huffman code for leaf node character
    }
    // Traverse left and right subtrees recursively
    generate(root->left, code + "0", ans);
    generate(root->right, code + "1", ans);
}

// Function to encode the input string using the generated Huffman Codes
string encode(string &s, map<char, string> &ans){
    string encodedString = "";
    for(char ch : s){
        encodedString += ans[ch]; // Append Huffman code of each character to the encoded string
    }
    return encodedString; // Return the encoded string
}

int main(){
    string s;
    cin >> s;
    
    // Build Huffman Tree from the input string
    Node* root = buildHuffmanTree(s);
    
    // Map to store Huffman Codes for each character
    map<char, string> ans;
    
    // Generate Huffman Codes for each character in the tree
    generate(root, "", ans);
    
    // Display the generated Huffman Codes for each character
    for(auto it : ans){
        cout << it.first << " " << it.second << endl;
    }
    
    // Encode the input string using the generated Huffman Codes
    string encodedString = encode(s, ans);
    cout << encodedString << endl; // Display the encoded string
    
    return 0;
}
