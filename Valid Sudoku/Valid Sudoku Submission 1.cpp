class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {

        int size = board.size();

        for (int i = 0; i < size; i++)
        {
            unordered_map<int, int> mprow;
            for (int j = 0; j < size; j++)
            {
                // cout<<board[i][j]<<" ";
                if (board[i][j] == '.')
                {
                    continue;
                }
                if (mprow.find(board[i][j]) == mprow.end())
                {
                    mprow[board[i][j]]++;
                }
                else
                {
                    cout << "Each row must contain the digits 1-9 without repetition.";
                    return false;
                }
            }
            // cout<<endl;
        }

        for (int j = 0; j < size; j++)
        {
            unordered_map<int, int> mpcol;
            for (int i = 0; i < size; i++)
            {
                // cout<<board[i][j]<<" ";
                if (board[i][j] == '.')
                {
                    continue;
                }
                if (mpcol.find(board[i][j]) == mpcol.end())
                {
                    mpcol[board[i][j]]++;
                }
                else
                {
                    cout << "Each column must contain the digits 1-9 without repetition.";
                    return false;
                }
            }
            // cout<<endl;
        }

        for (int rows = 0; rows < size; rows += 3)
        {
            for (int cols = 0; cols < size; cols += 3)
            {

                unordered_map<int, int> mpsub;
                for (int i = rows; i < rows + 3; i++)
                {
                    for (int j = cols; j < cols + 3; j++)
                    {
                        // cout<<board[i][j]<<" ";

                        if (board[i][j] == '.')
                        {
                            continue;
                        }
                        if (mpsub.find(board[i][j]) == mpsub.end())
                        {
                            mpsub[board[i][j]]++;
                        }
                        else
                        {
                            cout << "Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.";
                            return false;
                        }
                    }
                }
                // cout<<endl;
            }
        }

        return true;
    }
};