/*
What is heap?
A heap is a almost complete binary tree.
There are two type of heap:-
    -> Max heap
        Parent node value is always greater than child node value
    -> Min heap
        Parent node value is always less than child node value
If a heap is complete binary tree
then, height of heap :- log(n)                      Where n is the no. of nodes

::When heap converted to array::
Parent node index: i
then it's left child index is => i*2 & right child index is=> i*2 + 1.
*/
/*
Insert Operation   :: O(log n) ::
        50
    30      40
  10   5  20   37
Now inseting '60' into the tree, '60' is insert to the last free left side of lowest level of tree
Step 1)
                50                  Inserted at position 8
            30      40              
          10  5   20   37           
        60                          check for parent node value if less: then swap

Step 2)
                50                  
            30      40              
          60  5   20   37           check for parent node value if less: then swap
        10                          

Step 3)
                50                  check for parent node value if less: then swap
            60      40              
          30  5   20   37           
        10                          

Step 4)
                60                  check for parent node value if less: then swap
            50      40              
          30  5   20   37           
        10                          
*/
/*
Delete operation    :: O(log n) ::
        40
    30      10
  20   15  
Here we will try to delete 40 from the tree
:: Step 1) Replace the node to delete with the last node of lowest level,and the delet the node
        40              15
    30      10      30      10
  20   15         20   40
Array represntation
 {40, 30, 10, 20, 15} -> {15, 30, 10, 20, 40} -> {15, 30, 10, 20}

:: Step 2) Now try to balance the heap
        15                   30             30
    30      10      -->   15   10  -->   20    10
  20                    20             15
Array represntation
{15, 30, 10, 20}    -> {30, 15, 10, 20} -> {30, 20, 10, 15}
*/