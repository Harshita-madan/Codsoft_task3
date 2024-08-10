#include <iostream>
#include <vector>
using namespace std;

string Player1="Player1";
string Player2="Player2";
int row ; 
int col;
char token ;
vector<vector<char>> board( 3 , vector<char> (3));


void grid ( vector<vector<char>> &board){
    for ( int i=0 ; i<3 ; i++){
        for (int j=0 ; j<3 ; j++){
            board[i][j]=' ';
        }
    }
}

void displayGrid ( vector<vector<char>> &board ){
    for (int i=0 ; i<3 ; i++){
        for (int j=0 ; j<3 ; j++ ){
            cout << " " << board[i][j]<< "  ";
            if ( j<2 ) cout << "|";
        }
        cout<< endl;
        if(i<2 ) cout << "----|----|----"<<endl;
    }
}


bool isMoveValid( vector<vector<char>> &board , int row , int col){
    
    return row>=0 && row<3 && col>=0 && col<3 && board[row][col]==' ' ;
    
}
void playerDetails (){   

    cout<< "Enter your move ( row and col ) For example 0 0 for top left corner , 1 0 for middle row leftmost column " << endl;
    cin>>row>>col;

    while ( isMoveValid ( board, row , col)){
        if(token == 'X' && board[row][col]== ' '){
            board[row][col]='X';
            token = '0';
            displayGrid(board);
        }
        
        if(token == '0' && board[row][col]== ' '){
            board[row][col]='0';
            token = 'X';
            displayGrid(board);
        } 
    } 
}

void movePlayer (char token){
    cout << "Enter your move (row and col): ";
    cin >> row >> col;
    while (!isMoveValid(board, row, col)){
        cout << "Invalid move. Try again: ";
        cin >> row >> col;
    }
    board[row][col] = token;
    displayGrid(board);
}

bool checkWin ( vector<vector<char>>& board , char token){
    
    for (int i=0 ; i<3 ; i++){
        if (token == board[i][0] && board[i][0]== board[i][1] && board[i][0]== board[i][2] || token== board[0][i] && board[0][i] == board [1][i] && board[0][i]==board[2][i]){
            return true;
        }
    }
    
    if(token == board[0][0] && board[0][0]==board[2][2] && board[0][0]==board[1][1] || token==board[0][2]  && board[0][2] == board[1][1] && board[0][2] == board[2][0]){
        return true;
    }
    
    return false;
    
}


bool checkDraw (vector<vector<char>>&board){
    for(int i=0 ; i<3 ; i++){
        for(int j=0; j<3;j++){
            if(board[i][j] ==' '){
                return false;
            }
        }
    }
    return true ;
}

void changePlayer (char &token ){
    token = (token=='X') ? '0' : 'X';
}

int main() {
    
    grid(board);
    displayGrid(board);
    
    cout << Player1 << " will play first. "<< endl ;
    cout << "Player1 will use X "<< endl;
    cout<<endl;
    cout << "Player2 will use 0 "<< endl;
    token='X';
    
    playerDetails();
     
    bool win = false;
    bool draw = false;

    while (!win && !draw) {
        movePlayer(token);
        win = checkWin(board, token);
        if (win) {
            cout << (token == 'X' ? Player1 : Player2) << " has won ! Keep going !! " << endl;
        } else {
            draw = checkDraw(board);
            if (draw) {
                cout << "Draw " << endl;
            } else {
                changePlayer(token);
            }
        }
    }
    return 0;
}
