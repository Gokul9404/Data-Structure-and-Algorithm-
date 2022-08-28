/*
    -------------------------------------------------------------------------------------
    What are Trees?
    Trees are non-linear data-structure which have root and it's nodes..

    Tress are made up of nodes & edges.. N no. of nodes have (N-1) no. of edges
                        O -> 1 node             
                       / \                      Total no. of nodes -> 8
                      O   O -> 2 nodes          No. of edges -> 7
                     /\   /\                    Edges are those nodes which have parent
                    O  O O  O -> 4 nodes        

    Degree => No. of Direct Children (for Node or tree)

    Highest degree of Binary tree is 2 (it can have 0 or 1 or 2 degree)  
    -------------------------------------------------------------------------------------
    Types of Binary Trees
    -> Full / Strict Binary Tree
        All nodes have either 0 or 2 children. E.g below:-
                        O -> 2 children node             
                       / \
   2 children nodes <-O   O -> 0 children node          
                     /\                      
                    O  O       

    -> Perfect Binary Tree
        Internal nodes have 2 children and all leaf nodes are on the same level. E.g below:-
                        O -> 2 children node             
                       / \
   2 children nodes<- O   O -> 2 children nodes        
                     /\   /\             
                    O  O O  O 
                
    -> Complete Binary Tree
        All the nodes have 2 children except the last level nodes, and all the leaf-nodes are as left as possible. E.g below:-
                        O 
                       / \
                      O   O           
                     /\   /                  
                    O  O O    

    -> Degenrated Tree
        Every parent have only one-child node.
    
    -> Skewed Tree
        Every child-node is on the same side
        There are two types of Skewed node:-
            Left-Skewed Tree            Right-Skewed Tree
                        O                  O
                       /                    \
                      O                      O
                     /                        \
                    O                          O
    -------------------------------------------------------------------------------------
*/