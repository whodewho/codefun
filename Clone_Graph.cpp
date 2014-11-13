/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
//O(N)
//O(N)

class Solution {
    public:

        UndirectedGraphNode *worker(UndirectedGraphNode *node,map<int, UndirectedGraphNode*> &copied)
        {
            map<int,UndirectedGraphNode*>::iterator it=copied.find(node->label);
            if(it==copied.end())
            {
                UndirectedGraphNode *newNode=new UndirectedGraphNode(node->label);
                copied.insert(pair<int,UndirectedGraphNode*>(newNode->label,newNode));
                for(size_t i=0;i<node->neighbors.size();i++)
                {
                    UndirectedGraphNode *neighbor=worker(node->neighbors[i],copied);
                    newNode->neighbors.push_back(neighbor);
                }
                return newNode;
            }
            return copied[node->label];
        }

        UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            if(node==NULL)return NULL;
            map<int,UndirectedGraphNode*> copied;
            return worker(node,copied);
        }


        UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            if(node==NULL)return NULL;

            map<int,UndirectedGraphNode*> copied;
            queue<UndirectedGraphNode* > q;
            q.push(node);
            UndirectedGraphNode* result=NULL;
            while(!q.empty())
            {
                UndirectedGraphNode* tmpNode=q.front();
                q.pop();
                if(copied.find(tmpNode->label)==copied.end())
                {
                    copied.insert(pair<int, UndirectedGraphNode*>(tmpNode->label, new UndirectedGraphNode(tmpNode->label)));
                }
                for(int i=0;i<tmpNode->neighbors.size();i++)
                {
                    if(copied.find(tmpNode->neighbors[i]->label)==copied.end())
                        q.push(tmpNode->neighbors[i]);
                }
            }

            q.push(node);
            set<int> visited;
            visited.insert(node->label);
            while(!q.empty())
            {
                UndirectedGraphNode* tmpNode=q.front();
                q.pop();
                for(int i=0;i<tmpNode->neighbors.size();i++)
                {
                    copied[tmpNode->label]->neighbors.push_back(copied[tmpNode->neighbors[i]->label]);
                    if(visited.find(tmpNode->neighbors[i]->label)==visited.end())
                    {
                        q.push(tmpNode->neighbors[i]);
                        visited.insert(tmpNode->neighbors[i]->label);
                    }
                }
            }
            return copied[node->label];
        }
};
