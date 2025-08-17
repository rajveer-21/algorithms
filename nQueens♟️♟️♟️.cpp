#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::vector<std::vector<std::string>> solveNQueens(int size);
bool positionIsSafe(int size, int rows, int cols, std::vector<std::string>& board);
void findSolutions(int size, int rows, std::vector<std::string>& board, std::vector<std::vector<std::string>>& solutions);

int main()
{
    int size;
    std::cout << "Enter the size of the board - " << std::endl;
    std::cin >> size;
    std::vector<std::vector<std::string>> solutions = solveNQueens(size);

    std::ofstream outFile("solutions.txt");
    if(!outFile)
    {
        std::cerr << "File could not be opened." << std::endl;
        return 1;
    }
    outFile << "Number of solutions is = " << solutions.size() << "\n\n";
    for(int i = 0; i < (int)solutions.size(); i++)
    {
        outFile << "Solution " << i + 1 << " is :\n";
        for(int j = 0; j < (int)solutions[i].size(); j++)
        {
            outFile << solutions[i][j] << "\n";
        }
        outFile << "\n";
    }
    outFile.close();
    std::cout << "Solutions written to solutions.txt." << std::endl;
    return 0;
}

std::vector<std::vector<std::string>> solveNQueens(int size)
{
    std::vector<std::string> board(size, std::string(size, '.'));
    std::vector<std::vector<std::string>> solutions; 
    findSolutions(size, 0, board, solutions);
    return solutions;
}

void findSolutions(int size, int rows, std::vector<std::string>& board, std::vector<std::vector<std::string>>& solutions)
{
    if(rows == size)
    {
        solutions.push_back(board);
        return;
    }
    for(int i = 0; i < size; i++)
    {
        board[rows][i] = 'Q';
        if(positionIsSafe(size, rows, i, board) == true)
        {
            findSolutions(size, rows + 1, board, solutions);
        }
        board[rows][i] = '.';
    }
}

bool positionIsSafe(int size, int rows, int cols, std::vector<std::string>& board)
{
    for(int i = 0; i < rows; i++)
    {
        if(board[i][cols] == 'Q')
        return false;
    }

    for(int i = rows - 1, j = cols - 1; i >= 0 && j >= 0; i--, j--)
    {
        if(board[i][j] == 'Q')
        return false;
    }

    for(int i = rows - 1, j = cols + 1; i >= 0 && j < size; i--, j++)
    {
        if(board[i][j] == 'Q')
        return false;
    }
    return true;
}
