#include <stdio.h>
#include <stdlib.h>
//----------------------------------------------------------------------------------
struct Binary_node
{
    int data;
    struct Binary_node *left;
    struct Binary_node *right;
};

struct Binary_node *Create_node(int dataa)
{
    struct Binary_node *node;
    node = (struct Binary_node *)malloc(sizeof(struct Binary_node));
    node->data = dataa;
    node->left = NULL;
    node->right = NULL;
    return node;
}
//----------------------------------------------------------------------------------
int are_symmetric(struct Binary_node *root1, struct Binary_node *root2)
{
    if ((root1 == NULL) && (root2 == NULL))
    {
        return 1;
    }
    if ((root1->data != root2->data) || ((root1 == NULL) != (root2 == NULL)))
    {
        return 0;
    }
    int l, r, z;
    l = are_symmetric(root1->left, root2->right);
    r = are_symmetric(root1->right, root2->left);
    z = l && r;
    return z;
}

int Is_symmetric(struct Binary_node *root)
{
    if (root == NULL)
    {
        return 1;
    }
    return are_symmetric(root->left, root->right);
}
//----------------------------------------------------------------------------------
int main()
{
    /*  Here created binary tree is like below:-
                        1
                    3       3
                5   7       7   5
    */
    struct Binary_node *head, *left, *left11, *left12, *right, *right11, *right12;
    head = Create_node(1);
    left = Create_node(3);
    left11 = Create_node(5);
    left12 = Create_node(7);
    right = Create_node(3);
    right11 = Create_node(7);
    right12 = Create_node(5);
    //------------------------------------------------------------------------------
    head->left = left;
    head->right = right;
    left->left = left11;
    left->right = left12;
    right->left = right11;
    right->right = right12;
    //------------------------------------------------------------------------------
    int z = Is_symmetric(head);
    printf("The tree is symmetric:- %d", z);
    return 0;
}
