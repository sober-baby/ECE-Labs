// binary search tree
// opeartions:
//search, key, min/max key, print in order
//Insert: Strategy searchc for key, insert where it should be, Impl split across, BSTTree, BstNode
//Insert 1, 2, 3, 4, 5, 6
//greater elements go to the right subtree, smaller to the left

// root (null ptr)  -> 1 
//                  /    \ 
//                        2
//                          \
//                          3                               
//                            \                       
//                             4             
//                              \                   
//                               5                   
//                                  \
//                                   6



void BSTree:: insert(int k){
    if(root == NULL){
        root = new BSTNode(k); //root is a ptr to a BSTNode
    }else{
        root->bstInsert(k);
    }
}

void BstNode:: bstInsert(int k){
    if(key == k){
        return;
    }if(k < key){
        if(left == NULL){
            left = new BstNode(k);
        }else{
            left->bstInsert(k);
        }
    }else{
        if(right == NULL){
            right = new BstNode(k);
        }else{
            right->bstInsert(k);
        }
    }
}

//delete strategy: 
//find node
//if no subtrees, delete node, update parent ptr
//if exactly one subtree, delete node, update parent ptr
//if two subtrees, replace the node with the min of the right subtree, delete the min of the right subtree

void BstNode:: bstDelete(int k, BstNode*& pp){
    if(k < key){ //delete from left subtree
        if(left != NULL) left -> bstDelete(k, left);
        return;
    }
        
    if(k > key){ //delete from the right subtree
        if(right != NULL){
            right -> bstDelete(k, right);
            return;
        }
    }
    //delete this node
    if(left == NULL && right == NULL){ //no subtrees
        pp = NULL;
        delete this;
        return;
    }
    if((left == NULL)){ //only right subtree
        pp = right;
        right = NULL;
        delete this;
        return;
    }
    if((right == NULL)){ //only left subtree
        pp = left;
        left = NULL;
        delete this;
        return;
    }
    int minkey = right->bstMinimum();  //two subtrees
    key = minkey;
    right->bstDelete(minkey, right);
}


