#include<iostream>
using namespace std;
void displayBoard(char[][3]);
void makeAMove(char board[][3], char player);
char changePlayer(char player);
int countempty(char board[][3], char player);
bool Whowin(char board[][3], char player);
int main() {
   char board[3][3] =  {{ ' ',' ',' ' },
                   { ' ',' ',' ' },
                   { ' ',' ',' ' }};
   char player = 'X';
   while (true) {
      displayBoard(board);//board보여주기
      if (countempty(board, player) == 0) {
         cout << "no one cannot wil" << endl;
         return 0;
      }
      makeAMove(board, player);//돌놓기
      if (Whowin(board, player)) {//이겼는지 확인
         displayBoard(board);
         cout << player << " WON!" << endl;
         break;
      }
      else {//안이겼으면 플레이어 바꿔서 다시 돌리기   
         player = changePlayer(player);
         continue;
      }

   }
   return 0;
}
void displayBoard(char board[][3]) {
   cout << "-------------" << endl;
   for (int i = 0; i < 3; i++) {
      cout << "| ";
      for (int j = 0; j <3; j++)
         cout << board[i][j] << " | ";
      cout << "\n-------------" << endl;
   }
}
//돌 놓기
void makeAMove(char board[][3], char player) {
   bool done = false;
   do {
      cout << "Enter a row (0,1, or 2) for player " << player << ": ";
      int row;
      cin >> row;
      cout << "Enter a column (0,1, or 2) for player " << player << ": ";
      int column;
      cin >> column;

      if (board[row][column] == ' ') {
         board[row][column] = player;
         done = true;
      }
      else
         cout << "This cell is already occuried. Try a different call! " << endl;
   } while (!done);
}
bool Whowin(char board[][3], char player) {
   bool win = false;
   //check row
   int row = 1;
   for (int j = 0; j < 3; j++)
      for (int i = 0; i < 2; i++) {
         if (board[j][i] == player && board[j][i + 1] == player)
            row++;
         else
            break;
         if (row == 3) {
            win = true;
            break;
         }
      }
   //check column
   int column = 1;
   for (int j = 0; j < 3; j++)
      for (int i = 0; i < 2; i++) {
         if (board[i][j] == player && board[i + 1][j] == player)
            column++;
         else
            break;
         if (column == 3) {
            win = true;
            break;
         }
      }
   //check 정형 대각선
   int deagakson1 = 1;
   for (int i = 0; i < 3; i++) {
      if (board[i][i] == player && board[i + 1][i + 1] == player)
         deagakson1++;
      else
         break;
      if (deagakson1 == 3) {
         win = true;
         break;
      }
   }
   //check 역행 대각선
   int deagakson2 = 1;
   for (int i = 2; i >= 0; i--) {
      if (board[i][i] == player && board[i - 1][i - 1] == player)
         deagakson1++;
      else
         break;
      if (deagakson1 == 3) {
         win = true;
         break;
      }
   }
   return win;
}
char changePlayer(char player) {
   if (player == 'X')
      player = 'Y';
   else
      player = 'X';

   return player;
}
int countempty(char board[][3], char player) {
   int emptycnt = 0;
   for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
         if (board[i][j] == ' ')
            emptycnt++;
   return emptycnt;
}
