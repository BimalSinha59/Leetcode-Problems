/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL){
            return NULL;
        }
        // queue<Node*>q;
        // q.push(root);
        // while(!q.empty()){
        //     int size=q.size();
        //     Node* prev;
        //     for(int i=0; i<size; i++){
        //         Node* node=q.front();
        //         q.pop();
        //         if(i==0){
        //             prev=node;
        //         }
        //         if(i>0){
        //             prev->next=node;
        //             prev=node;
        //         }
        //         if(i==size-1){
        //             node->next=NULL;
        //         }
        //         if(node->left){
        //             q.push(node->left);
        //         }
        //         if(node->right){
        //             q.push(node->right);
        //         }
        //     }
        // }
        // return root;

        ///O(1) space code//
        
        Node* lmost=root;
        while(lmost->left){
            Node* curr=lmost;
            lmost=lmost->left;
            while(curr){
                curr->left->next=curr->right;
                if(curr->next){
                    curr->right->next=curr->next->left;
                }
                curr=curr->next;
            }
        }
        return root;
    }
};