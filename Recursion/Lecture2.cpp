#include <iostream>
#include <vector>

using namespace std;

vector<string> mazePath_HVD(int sr, int sc, int er, int ec)
{
    if (sr == er && sc == ec)
    {
        vector<string> tempAns;
        tempAns.push_back("");
        return tempAns;
    }

    vector<string> finalAns;

    if (sc + 1 <= ec)
    {
        vector<string> horizontalPaths = mazePath_HVD(sr, sc + 1, er, ec);
        for (auto path : horizontalPaths)
            finalAns.push_back('H' + path);
    }

    if (sr + 1 <= er)
    {
        vector<string> verticalPaths = mazePath_HVD(sr + 1, sc, er, ec);
        for (auto path : verticalPaths)
            finalAns.push_back('V' + path);
    }

    if (sr + 1 <= er && sc + 1 <= ec)
    {
        vector<string> diagonalPaths = mazePath_HVD(sr + 1, sc + 1, er, ec);
        for (auto path : diagonalPaths)
            finalAns.push_back('D' + path);
    }

    return finalAns;
}

void mazePath_HVD(int sr, int sc, int er, int ec, vector<string> ans, ...)
{
}

vector<string> mazePath_HVD_multi(int sr, int sc, int er, int ec)
{
    if (sc == ec && sr == er)
    {
        vector<string> tempArr;
        tempArr.push_back("");
        return tempArr;
    }

    vector<string> finalAns;

    // horizontal direction
    for (int jump = 1; sc + jump <= ec; jump++)
    {
        vector<string> tempAns = mazePath_HVD_multi(sr, sc + jump, er, ec);
        for (auto path : tempAns)
            finalAns.push_back("H" + to_string(jump) + path);
    }

    // vertical direction
    for (int jump = 1; sr + jump <= ec; jump++)
    {
        vector<string> tempAns = mazePath_HVD_multi(sr + jump, sc, er, ec);
        for (auto path : tempAns)
            finalAns.push_back("V" + to_string(jump) + path);
    }

    // diagonal direction
    for (int jump = 1; sr + jump <= ec && sc + jump <= ec; jump++)
    {
        vector<string> tempAns = mazePath_HVD_multi(sr + jump, sc + jump, er, ec);
        for (auto path : tempAns)
            finalAns.push_back("D" + to_string(jump) + path);
    }

    return finalAns;
}

vector<string> mazePath_multiDirection(int sr, int sc, int er, int ec,
                                       vector<vector<int>> &directions, vector<string> &directionNames,
                                       vector<vector<bool>> &visited)
{

    vector<string> answer;
    // base case
    if (sr == er && sc == ec)
    {
        answer.push_back("");
        return answer;
    }

    visited[sr][sc] = true;

    for (int d = 0; d < directions.size(); d++)
    {
        for (int jump = 1; ; jump++)
        {
            int newRow = sr + jump * directions[d][0];
            int newCol = sc + jump * directions[d][1];
            if(!(newRow <= er && newRow >= 0 && newCol <= ec && newCol >= 0))
                break;
            if (!visited[newRow][newCol])
            {
                vector<string> directionPaths = mazePath_multiDirection(newRow, newCol, er, ec,
                                                                        directions, directionNames, visited);
                for (auto path : directionPaths)
                {
                    answer.push_back(directionNames[d] + to_string(jump) + " " + path);
                }
            }
        }
    }
    visited[sr][sc] = false;
    return answer;
}

int main()
{
    int rows = 3, cols = 3;
    vector<vector<int>> directions = {
        {1, 0},
        {1, -1},
        {0, -1},
        {-1, -1},
        {-1, 0},
        {-1, 1},
        {0, 1},
        {1, 1}};
    vector<string> directionNames = {"E", "NE", "N", "NW", "W", "SW", "S", "SE"};
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    vector<string> finalAns = mazePath_multiDirection(0, 0, 2, 2, directions, directionNames, visited);
    for (auto path : finalAns)
        cout << path << endl;
    return 0;
}