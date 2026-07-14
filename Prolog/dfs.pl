% ---------------------------------------------------------
% Purpose:
% Finds a path between two nodes using
% Depth First Search (DFS).
%
% Technique Used:
% Depth First Search (DFS), Recursion, Backtracking
% ---------------------------------------------------------

% Define graph edges
edge(a, b).
edge(a, c).
edge(b, d).
edge(c, d).
edge(d, e).

% DFS Predicate
dfs(Start, Goal, Path) :-
    dfs_util(Start, Goal, [Start], Path).

% Base Case: Goal Reached
dfs_util(Goal, Goal, Visited, Path) :-
    reverse(Visited, Path).

% Recursive Case
dfs_util(Current, Goal, Visited, Path) :-
    edge(Current, Next),
    \+ member(Next, Visited),      % Avoid revisiting nodes
    dfs_util(Next, Goal, [Next|Visited], Path).

/*---------------------------------------------------------

Consult

?- consult('C:/Users/YourName/Documents/prolog/dfs.pl').

----------------------------------------------------------

Query

?- dfs(a, e, Path).

----------------------------------------------------------

Output

Path = [a, b, d, e].

----------------------------------------------------------

How it Works

1. The graph is represented using edge/2 facts.
2. DFS starts from the source node (a).
3. It explores one branch as deeply as possible.
4. If the current path cannot reach the goal, Prolog
   automatically backtracks and tries another path.
5. The member/2 predicate prevents revisiting nodes,
   avoiding infinite loops.
6. Once the goal node (e) is reached, reverse/2 returns
   the path in the correct order.

---------------------------------------------------------*/