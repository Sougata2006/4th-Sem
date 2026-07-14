% ---------------------------------------------------------
% Purpose:
% Finds the shortest path between two nodes using
% Breadth First Search (BFS).
%
% Technique Used:
% Breadth First Search (BFS), Queue, Recursion
% ---------------------------------------------------------

% Define graph edges
edge(a,b).
edge(a,c).
edge(b,d).
edge(b,e).
edge(c,f).
edge(e,g).

% BFS Predicate
bfs(Start, Goal, Path) :-
    bfs_queue([[Start]], Goal, RevPath),
    reverse(RevPath, Path).

% Base Case: Goal Found
bfs_queue([[Goal|Rest]|_], Goal, [Goal|Rest]).

% Recursive Case
bfs_queue([[Node|RestPath]|OtherPaths], Goal, SolutionPath) :-
    findall([Next,Node|RestPath],
            (edge(Node, Next),
             \+ member(Next, [Node|RestPath])),
            NewPaths),
    append(OtherPaths, NewPaths, UpdatedQueue),
    bfs_queue(UpdatedQueue, Goal, SolutionPath).

/*---------------------------------------------------------

Consult

?- consult('C:/Users/YourName/Documents/prolog/bfs.pl').

----------------------------------------------------------

Query

?- bfs(a, g, Path).

----------------------------------------------------------

Output

Path = [a, b, e, g].

----------------------------------------------------------

How it Works

1. The graph is represented using edge/2 facts.
2. BFS starts from the source node (a).
3. A queue stores all possible paths.
4. The first path is expanded level by level.
5. Unvisited adjacent nodes are added to the end of the queue.
6. When the goal node (g) is found, the shortest path is returned.
7. reverse/2 displays the path in the correct order.

---------------------------------------------------------*/