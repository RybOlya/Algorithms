# Algorithms
## Finding the minimum depth of a binary tree
 - Given a binary tree, find its minimum depth. The minimum depth is the total number of nodes along the shortest path from the root node to the nearest end node.
For example, the minimum depth of the following binary tree is 3. The shortest path is 1 —> 3 —> 6.

To represent the graph, used the adjacency list, the data is read from the input.txt file

input.txt contains:
1 #root
1,2 # a list of edges where the order of the vertices determines the direction. In this case, the edge is directed from 1 to 2
1.3
2.4
…


The result (minimum depth of the tree) should be output to the output.txt file