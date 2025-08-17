import java.io.*;
import java.util.*;

class nQueens
{
    public static void main(String args[])throws IOException
    {
        int n = 8;
        List<List<String>> possibilities = new ArrayList<>();
        possibilities = findSolutions(n);
        int count = 1;
        System.out.println("number of solutions is - " + possibilities.size());
        BufferedWriter bw = new BufferedWriter(new FileWriter("output.txt"));
        try(bw)
        { 
        bw.write("number of solutions is - " + possibilities.size());
        bw.newLine();
        for(int i = 0; i < possibilities.size(); i++)
        {
            bw.write("Solution " + count + " = ");
            bw.newLine();
            for(int j = 0; j < possibilities.get(i).size(); j++)
            {
                bw.write(possibilities.get(i).get(j));
                bw.newLine();
            }
            bw.newLine();
            count++;
        }
        System.out.println("Solutions written to outputs.txt");
        }
        catch(Exception e)
        {
            System.out.println("Unexpected error when writing to file. Check if a valid file exists.");
        }
    }
    
    public static List<List<String>> findSolutions(int n)
    {
        char board[][] = new char[n][n];
        for(int i = 0; i < n; i++)
        Arrays.fill(board[i], '.');
        List<List<String>> possibilities = new ArrayList<>();
        solveNQueens(n, 0, board, possibilities);
        return possibilities;
    }
    
    public static void solveNQueens(int n, int rows, char board[][], List<List<String>> solutions)
    {
        if(n == rows)
        {
            List<String> current = new ArrayList<>();
            for(int i = 0; i < n; i++)
            {
                current.add(new String(board[i]));
            }
            solutions.add(current);
            return;
        }
        
        for(int cols = 0; cols < n; cols++)
        {
            board[rows][cols] = 'Q';
            if(isSafe(rows, cols, board, n) == true)
            solveNQueens(n, rows + 1, board, solutions);
            board[rows][cols] = '.'; 
        }
    }
    
    public static boolean isSafe(int rows, int cols, char board[][], int n)
    {
        for(int i = 0; i < rows; i++)
        {
            if(board[i][cols] == 'Q')
            return false;
        }
        
        for(int j = cols - 1, i = rows - 1; i >= 0 && j >= 0; i--, j--)
        {
            if(board[i][j] == 'Q')
            return false;
        }
        
        for(int j = cols + 1, i = rows - 1; j < n && i >= 0; i--, j++)
        {
            if(board[i][j] == 'Q')
            return false;
        }
        return true;
    }
}