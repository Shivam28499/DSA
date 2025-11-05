class Solution {
public:
    unordered_map<int,Node*>mp;
    void helper(Node* cloneNode,Node* originalNode){
        for(auto node:originalNode->neighbors){
            if(mp.find(node->val)==mp.end()){
                Node* currNode = new Node(node->val);
                mp[node->val] = currNode;
                cloneNode->neighbors.push_back(currNode);
                helper(currNode,node);
            }else {
                cloneNode->neighbors.push_back(mp[node->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        Node* nb = new Node(node->val);
        mp[node->val] = nb;
        helper(nb,node);
        return nb;
    }
};