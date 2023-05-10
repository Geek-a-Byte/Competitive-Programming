//just keep this checking
/*
It is assumed that if there is no edge between any two vertices i and j, 
then the matrix at d[i][j] contains a large number (large enough so that it is greater than 
the length of any path in this graph). 
Then this edge will always be unprofitable to take, and the algorithm will work correctly.

However if there are negative weight edges in the graph, 
special measures have to be taken. Otherwise the resulting values 
in matrix may be of the form ∞−1, ∞−2, etc., 
which, of course, still indicates that between the respective vertices doesn't exist a path. 
Therefore, if the graph has negative weight edges, 
it is better to write the Floyd-Warshall algorithm in the following way, 
so that it does not perform transitions using paths that don't exist.
*/
for (int k = 0; k < n; ++k)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (d[i][k] < INF && d[k][j] < INF)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
    }
}