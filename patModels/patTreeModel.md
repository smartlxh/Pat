## 树
建树
中序 + 前序/后序
以前序+中序为例子

节点结构体
```
struct node{
    int val;
    node* left;
    node* right;
    node(int value){
        val = value;
        left = NULL;
        right = NULL;
    }
};
typedef  struct node node ;

```

```
vector<int> in;
vector<int> pre;
void buildTree(node* &root ,int l1,int r1,int l2,int r2){
    if(l1<=r1){
        int value = pre[l1];
        root = new node(value);

        int middle=l2;
        while(middle<=r2 && in[middle]!=value){
            middle++;
        }
        buildTree(root->left, l1,l1+1+middle-1-l2, l2, middle-1);
        buildTree(root->right, r1-(r2-middle-1), r1, middle+1, r2);
    }
}


```
#### BST的插入(BST构树过程可以以前序遍历的顺序进行建树)
```
void insert(node* &root,int val){
    if(root==NULL){
        root = new node(val);
        return;
    }
    else{
        if(root->val<val){
            insert(root->right, val);

        }
        else{
            insert(root->left, val);
        }
    }
}


```
#### 层次遍历+中序遍历
```
void createTree(node* &root,int val,int index){
    if(root==NULL){
        root = new node(val);
        return ;
    }

    int rootIndex=0;
    for(int i=0;i<N;i++){
        if(root->val==in[i]){
            rootIndex = i;
            break;
        }
    }
    if(rootIndex<index){
        createTree(root->right, val, index);

    }
    else{
        createTree(root->left, val, index);
    }
}

int main(){

    node* root = NULL;
    for(int i=0;i<N;i++){

        int index=0;
        for(int j=0;j<N;j++){
            if(level[i]==in[j]){
                index = j;
                break;
            }
        }
        createTree(root, level[i], index);
    }
}
```

#### 判断是否是完全二叉树
层次遍历到空节点后，查看队列中剩余节点是否还有非空节点。

#### AVL树的插入和调整
```
int getHeight(node* root){
    if(root==NULL) return 0;
    else return max(getHeight(root->left),getHeight(root->right))+1;
}
node* rotateLeft(node* root){
    node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    return temp;
}

node* rotateRight(node* root){
    node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    return temp;
}

node* rotateLeftRight(node* root){
    root->left = rotateLeft(root->left);
    root = rotateRight(root);
    return root;
}

node* rotateRightLeft(node* root){
    root->right = rotateRight(root->right);
    root = rotateLeft(root);
    return root;
}

node* insertTree(node* root,int val){
    if(root==NULL){
        root = new node(val);
        return root;
    }
    if(root->val<=val){
        root->right = insertTree(root->right, val);
        if(getHeight(root->right)-getHeight(root->left)==2){
            if(val>root->right->val){
                root = rotateRight(root);
            }
            else{
                root = rotateRightLeft(root);
            }
        }
    }
    else{
        root->left = insertTree(root->left, val);
        if(getHeight(root->left)-getHeight(root->right)==2){
            if(val<root->left->val){
                root = rotateLeft(root);
            }
            else{
                root = rotateLeftRight(root);
            }
        }
    }
    return root;

}


```

#### BST 排序是中序遍历 重要性质！！！
