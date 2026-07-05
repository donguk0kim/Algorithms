# Graphs

num_edges <= num_nodes(num_nodes - 1)			Directed graph
num_edges <= num_nodes(num_nodes - 1) / 2		Undirected graph

Dense graph - many edges
Sparse graph - little edges

Directed
- ordered edge pairs
- digraph
Undirected - unordered edge pairs

Graph traversal = web crawling

Self loops - origin same as destination (page contains link to itself)
Multi edge - many flight trajectories from the same city to another same city

Simple path - no repeated vertex passings and edge passings
Walk - repeated vertex passings and edge passings
Trail - repeated vertex passings but no edge passings
Closed walk - path that ends where it starts after journey where num nodes passed > 0
Simple cycle - path where the only repeated node is the origin (destination)

Strongly connected graph - a path exists to go from any node to another (directed)
Connected graph - a path exists to go from any node to another (undirected)
Weakly connected graph - if directed graph with missing paths converted to undirected can become connected graph