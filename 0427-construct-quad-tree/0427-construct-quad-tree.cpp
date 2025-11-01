/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        Node* root = new Node();
        construct_tree(0,grid.size(),0,grid[0].size(),grid,root);
        return root;
        
    }
    void construct_tree(int x1,int x2,int y1,int y2,vector<vector<int>>& grid,Node* root){
        bool allones=true;
        bool allzeroes=true;
        for(int i=x1;i<x2;i++){
            if(!allones && !allzeroes){
                break;
            }
            for(int j=y1;j<y2;j++){
                if(grid[i][j]==1){
                    allzeroes=false;
                    
                }
                else{
                    allones=false;
                }
            }
        }
        if(allones){
            root->isLeaf=true;
            root->val=true;
        }
        if(allzeroes){
            root->isLeaf=true;
            root->val=false;
        }
        
        if(!allones && !allzeroes){
            root->isLeaf=false;
            
             root->topLeft=new Node();
             root->topRight=new Node();
           root->bottomLeft=new Node();
           root->bottomRight=new Node();
            int midx=(x1+x2)/2;
            int midy=(y1+y2)/2;
            construct_tree(x1,(midx),y1,(midy),grid,root->topLeft);
            construct_tree(x1,(midx),(midy),y2,grid,root->topRight);
            construct_tree(midx,x2,y1,(midy),grid,root->bottomLeft);
            construct_tree(midx,x2,(midy),y2,grid,root->bottomRight);

        }
        
    }
};