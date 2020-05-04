/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node){
        if (!node) return NULL;
        unordered_map<Node*, Node*> hm;
        queue<Node*> q;
        q.push(node);
        hm[node] = new Node(node->val);
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            for (auto n : current->neighbors) {
                if (hm.find(n) == hm.end()) {
                    hm[n] = new Node(n->val);
                    q.push(n);
                }
                hm[current]->neighbors.push_back(hm[n]);
            }
        }

        return hm[node];
    }
};
