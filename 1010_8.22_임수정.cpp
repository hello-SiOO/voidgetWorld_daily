#include<iostream>
using namespace std;
void displayBoard(char board[][7]) {
	for (int i = 0; i < 6; i++) {
		cout << "|";
		for (int j = 0; j < 7; j++)
			cout << board[i][j] << "|";
		cout << endl;
	}
	cout << "----------------" << endl;
}
char changePlayer(char player) {
	if (player == 'R')
		player = 'Y';
	else
		player = 'R';
	return player;
}
int countempty(char board[][7], char player) {
	int emptycnt = 0;
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 7; j++)
			if (board[i][j] == ' ')
				emptycnt++;
	return emptycnt;
}
bool Whowin(char board[][7], char player) {
	bool win = false;
	//check row
	int row = 1;
	for (int j = 0; j < 6; j++)
		for (int i = 0; i < 7; i++) {
			if (board[j][i] == player && board[j][i + 1] == player)
				row++;
			else
				break;
			if (row == 4) {
				win = true;
				break;
			}
		}
	//check column
	int column = 1;
	for (int j = 0; j < 7; j++)
		for (int i = 0; i < 6; i++) {
			if (board[i][j] == player && board[i + 1][j] == player)
				column++;
			else
				break;
			if (column == 4) {
				win = true;
				break;
			}
		}
	//check ���� �밢��
	for (int k = 0; k < 6; k++) {
		for (int m = 0; m < 7; m++) {
			int deagakson1 = 1;
			for (int i = k ; i < k+4; i++) {
				if (board[i][i] == player && board[i + 1][i + 1] == player)
					deagakson1++;
				else
					break;
				if (deagakson1 == 4) {
					win = true;
					break;
				}
			}
		}
	}
	//check ���� �밢��
	for (int k = 5; k >=0 ; k--) {
		for (int m = 6; m >=0 ; m--) {
			int deagakson2 = 1;
			for (int i = k; i > k-4; i--) {
				if (board[i][i] == player && board[i-1][i-1] == player)
					deagakson2++;
				else
					break;
				if (deagakson2 == 4) {
					win = true;
					break;
				}
			}
		}
	}
	return win;
}
int main() {
	char board[6][7] = {' ', };
	char player = 'R';
	int column;
	int row = 5;
	//�ݺ�
	while(true){
		displayBoard(board);
		if (countempty(board, player) == 0) {
			cout << "no one cannot wil" << endl;
			return 0;
		}
		//������߸���
			cout << "Drop a " << player << " disk at column (0-6): ";
			cin >> column;
			if (board[row][column] == ' '){	
				if (row == 5) board[row][column] = player;
				else if((row != 5 && board[row + 1][column] != ' '))	
 					board[row][column] = player;
			}
			else
				board[row-1][column] = player;
			//�ش� ĭ�� ��ĭ�� �ƴϸ� �ٽùݺ�
			if (Whowin(board, player)) {//�̰���� Ȯ��
				displayBoard(board);
				cout << player << " WON!" << endl;
				break;
			}
			else {
				player = changePlayer(player);
				continue;
			}	
	}

	return 0;
}
