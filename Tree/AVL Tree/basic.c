/*
    AVL Tree
    A Tree that is height balanced binary search tree
    height difference between height of left sub-tree and right sub-tree is either 1 or 0, i.e it balance factor is 1 or 0
    Balance factor => |height of left sub-tree - height of right sub-tree|
*/
/*
    Thus rotation is done on AVL Tree is required when the Tree's Balance Factor is greater than 1.

    Types of rotation:-
        |->  LL rotation    :- When the Tree have more height on left sub-tree 
        |->  RL rotation    :- When right sub-tree's balance factor is 0 or 1, but it disturbs it's Parent tree's balance factor
        |->  LR rotation    :- When left sub-tree's balance factor is 0 or 1, but it disturbs it's Parent tree's balance factor
        |->  RR rotation    :- When the Tree have more height on right sub-tree 
*/