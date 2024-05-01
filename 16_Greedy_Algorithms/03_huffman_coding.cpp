class Node {
    public:
    int data;
    Node *left, *right;
    
    Node(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};
 
class cmp{
    public:
    bool operator()(Node*a, Node*b) {
        return a->data > b->data; // for min heap
    }
};

class Solution{
    private:
        void traverse(Node* root, vector<string> &ans, string temp){
            if(root->left == NULL && root->right == NULL){
                ans.push_back(temp);
                return;
            }
            traverse(root->left, ans, temp+"0");
            traverse(root->right, ans, temp+"1");
        }
	public:
		vector<string> huffmanCodes(string S,vector<int> f,int n){
		    // Code here
		    priority_queue<Node*, vector<Node*>, cmp> pq;
		    for(int i=0; i<n; i++){
		        Node* temp = new Node(f[i]);
		        pq.push(temp);
		    }
		    
		    while(pq.size() > 1){
		        Node* firstNode = pq.top();
		        pq.pop();
		        Node* secondNode = pq.top();
		        pq.pop();
		        Node* temp = new Node(firstNode->data + secondNode->data);
		        temp->left = firstNode;
		        temp->right = secondNode;
		        pq.push(temp);
		    }
		    Node* root = pq.top();
		    string temp = "";
		    vector<string> ans;
		    traverse(root, ans, temp);
		    return ans;
		}
};

/*
The operator() is a special function in C++ known as the function call operator or the “()” operator. When this operator is overloaded in a class, it allows the objects of that class to be called like functions.

In your code, operator() is being overloaded in the cmp class. This class is being used to define a custom comparison function for the priority queue.

Here’s a breakdown of what’s happening:

class cmp: This defines a new class named cmp.
public:: This keyword means that the following members of the class are accessible from outside the class.
bool operator()(Node*a, Node*b): This is the function call operator. It’s a function that takes two pointers to Node objects as parameters.
return a->data > b->data;: This is the body of the function. It returns true if the data member of Node a is greater than the data member of Node b. This is used to order the elements in the priority queue.
*/