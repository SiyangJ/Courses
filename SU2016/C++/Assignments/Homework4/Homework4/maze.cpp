bool pathExists(std::string maze[], int nRows, int nCols, int sr, int sc, int er, int ec)
{
    if (maze[sr][sc]!='.')
        return 0;
    if (sr==er && sc==ec)
        return 1;
    maze[sr][sc]='1';
    return (pathExists(maze, nRows, nCols, sr-1, sc, er, ec)|| pathExists(maze, nRows, nCols, sr, sc+1, er, ec)|| pathExists(maze, nRows, nCols, sr+1, sc, er, ec)|| pathExists(maze, nRows, nCols, sr, sc-1, er, ec));
}