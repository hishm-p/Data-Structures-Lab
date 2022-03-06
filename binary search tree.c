 #include<stdio.h>
 #include<stdlib.h>
struct node
{
    int key;
    struct node *left,*right;
};

struct node *newNode(int item)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node *insert(struct node *node,int key)
{
    if(node==NULL)
        return newNode(key);
    if (key < node->key)
    {
        node->left = insert(node->left,key);
    }
    else
    {
        node->right = insert(node->right,key);
    }
    return node;

}

void inorder(struct node *rt)
{
    if(rt!=NULL)
    {
        inorder(rt->left);
        printf("%d->",rt->key);
        inorder(rt->right);
    }

}

void preorder(struct node *rt)
{
    if(rt!=NULL)
    printf("%d->",rt->key);
    preorder(rt->left);
    preorder(rt->right);
}

void postorder(struct node *rt)
{
    if(rt!=NULL)
    {
        postorder(rt->left);
        postorder(rt->right);
        printf("%d->",rt->key);
    }
}

struct node *minvaluenode(struct node *node)
{
    struct node *current = node;
    while(current!=NULL)
    {
        current = current->left;
    }
    return current;
}

struct node *delete(struct node *root,int key)
{
    if(root==NULL)
      return root;
    if(key < root->key)
    {
        root->left = delete(root->left,key);
    }
    else if(key > root->key)
    {
        root->right = delete(root->right,key);
    }
    else
    {
        if(root->left==NULL)
        {
            struct node *temp;
            temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            struct node *temp;
            temp = root->left;
            free(root);
            return temp;
        }

    struct node *temp = minvaluenode(root->right);
    root->key = temp->key;
    root->right = delete(root->right,temp->key);
    }
    return root;
}

int main()
{
    struct node *root = NULL;
    int ch=1,value;
    while(ch!=0)
    {
    printf("\n1:Insert into Binary Tree 2:Delete from Binary Tree 3:Inorder Traversal 4:Preorder Traversal 5:Postorder traversal");
    printf("\nEnter your Operation : ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1 : printf("Enter the value to insert : ");
                 scanf("%d",&value);
                 if(root==NULL)
                    root = insert(root,value);
                 else
                    insert(root,value);
                 break;
        case 2 : printf("Enter the value to delete : ");
                 scanf("%d",&value);
                 root = delete(root,value);
                 break;

        case 3 : printf("Inorder Traversal : \n");
                 inorder(root);
                 break;
        case 4 : printf("Preorder Traversal : \n");
                 preorder(root);
                 break;
        case 5 : printf("Postorder Traversal : \n");
                 postorder(root);
                 break;
        default : printf("Invalid Input");
                  break;

    }
    }
    // root = newNode(8);
    // insert(root,6);
    // insert(root,10);
    // inorder(root);
    // printf("\n");
    // preorder(root);
    // printf("\n");
    // postorder(root);
}
