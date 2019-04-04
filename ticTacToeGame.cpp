#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const char X = 'X';
const char O = 'O';
const char empty = ' ';
const char tie = 'T';
const char notOver = 'N';

void displayInstructions();
char askYesNo(string question);
int askNumber( string question, int high, int low = 0);
char userSymbol();
char opponentTurn(char symbol);
void display(const vector<char>& board);
char winner(const vector<char>& board);
bool legalMove(const vector<char>& board, int move);
int userMove(const vector<char>& board, char user);
int compMove(const vector<char>& board, char comp);
void displayWinner(char winner, char comp, char user);

int main()
{
  int move;
  const int sizeBoard = 9;
  vector<char> board(sizeBoard, empty);
  
  displayInstructions();
  
  char user = userSymbol();
  char comp = compSymbol();
  
  char turn = X;
  
  display(board);
  
  while(winner(board) == notOver);
  {
    if (turn == user)
    {
      move = userMove(board, user);
      board[move] = user;
    }
    
    else
    {
      move = compMove(board, comp);
      board[move] = comp;
    }
  
    display(board);
    turn = opponentTurn(turn);
 }

  displayWinner(winner(board), comp, user);
  return 0;
}


void displayInstructions()
{
  cout << "\t\t Tic Tac Toe \n";
  cout << "input moves by typing 0-8 each turn\n";
  cout << "Board example: \n\n";
  cout << " 0 | 1 | 2 \n";
  cout << " 3 | 4 | 5 \n";
  cout << " 6 | 7 | 8 \n\n";
  cout << "The game begins now!\n\n";
}

char askYesNo(string question);
{
  char answer;
  do
  {
    cout<< question << " (Y/N)? ";
    cin >> answer;
  } while (answer != 'Y' && answer != 'N');
  
  return answer;
}

int askNumber( string question, int high, int low = 0);
{

 int num;
 
 do
  {
    cout<< question << "(" << low << "-" << high << ")?";
    cin >> num;
  } while (num > high || num < low);

  return num;
}

char userSymbol();
{
  char firstQuestion = askYesNo("Do you want to go first?");
  if (firstQuestion == 'Y');
     return X;
  else 
     return O;
}

char opponentTurn(char symbol);
{
  if (symbol == 'X')
    return O;
  else 
    return X;
}

void display(const vector<char>& board);
{
  cout << " board[0] | board[1] | board[2] \n";
  cout << " board[3] | board[4] | board[5] \n";
  cout << " board[6] | board[7] | board[8] \n\n";
}

char winner(const vector<char>& board);
{
  const int waysToWin[8][3] = {{0,1,2},{0,4,8},{0,3,6},{1,4,7},{2,5,8},{2,4,6},{3,4,5},{6,7,8}};
  const int rows = 8;
  
  //CHECK FOR WINNER
  for( int i = 0; i <rows; i++)
  {
    if( (board[waysToWin[i][0]] != empty) && (board[waysToWin[i][0]] == board[waysToWin[i][1]])
        && (board[waysToWin[i][1]] == board[waysToWin[i][2]]) )
          return board[waysToWin[i][0]];
  }
  
  //CHECK FOR TIE
  if(count(board.begin(), board.end(), empty) == 0)
    return tie;
    
  else 
    return notOver;
}

inline bool legalMove(const vector<char>& board, int move);
{
  return (board[move] == empty);
}

int userMove(const vector<char>& board, char user);
{
  int move = askNumber("What is your move?", (board.size()-1));
  
  while(!legalMove(board,move))
  {
    cout << "Not an option, box is taken! \n";
    move = askNumber("Try again, what is your move?", (board.size()-1)); 
  }

  return move;
}

int compMove(const vector<char>& board, char comp);
{




}

void displayWinner(char winner, char comp, char user);
{
  if(winner == computer)
    cout << winner << " win the game!\n Please play again\n\n";
  else if(winner == user)
    cout << winner << " win the game!\n Please play again\n\n";
  else 
    cout << "It's a tie! No one wins!\n Please play again\n\n";
}


}
