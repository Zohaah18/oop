#include<iostream>
using namespace std;
class Chesspiece{
     string name;
     string color;
     char symbol;
     public:
     Chesspiece():name("Pawn"),color("White"),symbol('p'){
     }
     Chesspiece(string name,string color,char symbol):name(name),color(color),symbol(symbol){
     }
     void set_name(string n){
        name=n;
     }
     void set_color(string c){
        color=c;
     }
     void set_symbol(char sym){
        symbol=sym;
     }
     string get_name(){
        return name;
     }
     string get_color(){
        return color;
     }
     char get_symbol(){
        return symbol;
     }
};
class chessboard{
   Chesspiece* board[8][8];
   public:
   chessboard(){
     for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            board[i][j]=NULL;
        }
     }
        board[0][0] = new Chesspiece("Rook", "Black", 'R');
        board[0][1] = new Chesspiece("Knight", "Black", 'N');
        board[0][2] = new Chesspiece("Bishop", "Black", 'B');
        board[0][3] = new Chesspiece("Queen", "Black", 'Q');
        board[0][4] = new Chesspiece("King", "Black", 'K');
        board[0][5] = new Chesspiece("Bishop", "Black", 'B');
        board[0][6] = new Chesspiece("Knight", "Black", 'N');
        board[0][7] = new Chesspiece("Rook", "Black", 'R');
        for (int j = 0; j < 8; j++) {
            board[1][j] = new Chesspiece("Pawn", "Black", 'P');
        }

        
        board[7][0] = new Chesspiece("Rook", "White", 'r');
        board[7][1] = new Chesspiece("Knight", "White", 'n');
        board[7][2] = new Chesspiece("Bishop", "White", 'b');
        board[7][3] = new Chesspiece("Queen", "White", 'q');
        board[7][4] = new Chesspiece("King", "White", 'k');
        board[7][5] = new Chesspiece("Bishop", "White", 'b');
        board[7][6] = new Chesspiece("Knight", "White", 'n');
        board[7][7] = new Chesspiece("Rook", "White", 'r');
        for (int j = 0; j < 8; j++) {
            board[6][j] = new Chesspiece("Pawn", "White", 'p');
        }



   }
   void display() {
        // Display the board with proper formatting
        cout << "  a b c d e f g h" << endl;
        for (int i = 0; i < 8; i++) {
            cout << 8 - i << " ";
            for (int j = 0; j < 8; j++) {
                if (board[i][j] != nullptr) {
                    cout << board[i][j]->get_symbol() << " ";
                } else {
                    cout << ". ";
                }
            }
            cout << 8 - i << endl;
        }
        cout << "  a b c d e f g h" << endl;
   }
    bool movePiece(string source, string destination) {
        // Convert source and destination positions to array indices
        int sourceRow = 8 - (source[1] - '0');
        int sourceCol = source[0] - 'a';
        int destRow = 8 - (destination[1] - '0');
        int destCol = destination[0] - 'a';

        // Check if source and destination are within the board bounds
        if (sourceRow < 0 || sourceRow >= 8 || sourceCol < 0 || sourceCol >= 8 ||
            destRow < 0 || destRow >= 8 || destCol < 0 || destCol >= 8) {
            cout << "Invalid move: Source or destination out of bounds." << endl;
            return false;
        }

        // Check if the source position is empty
        if (board[sourceRow][sourceCol] == nullptr) {
            cout << "Invalid move: No piece at the source position." << endl;
            return false;
        }

        // Get the piece being moved
        Chesspiece* piece = board[sourceRow][sourceCol];

        // Check if the destination is occupied by a piece of the same color
        if (board[destRow][destCol] != nullptr && board[destRow][destCol]->get_color() == piece->get_color()) {
            cout << "Invalid move: Destination occupied by a piece of the same color." << endl;
            return false;
        }

        // Determine if the move is valid based on the piece type
        char pieceSymbol = piece->get_symbol();
        int rowDiff = abs(destRow - sourceRow);
        int colDiff = abs(destCol - sourceCol);

        // Valid moves for a knight on the first turn
        if (pieceSymbol == 'N' || pieceSymbol == 'n') {
            if ((rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2)) {
                // Move is valid
                board[destRow][destCol] = board[sourceRow][sourceCol];
                board[sourceRow][sourceCol] = nullptr;
                cout << "Move successful!" << endl;
                return true;
            } else {
                cout << "Invalid move: Knights can only move in an L-shape." << endl;
                return false;
            }
        }

        // Valid moves for a pawn on the first turn
        if (pieceSymbol == 'P' || pieceSymbol == 'p') {
            if ((piece->get_color() == "White" && sourceRow - destRow == 2 && colDiff == 0) ||
                (piece->get_color() == "Black" && destRow - sourceRow == 2 && colDiff == 0)) {
                // Move is valid
                board[destRow][destCol] = board[sourceRow][sourceCol];
                board[sourceRow][sourceCol] = nullptr;
                cout << "Move successful!" << endl;
                return true;
            } else {
                cout << "Invalid move: Pawns can only move two squares forward on the first turn." << endl;
                return false;
            }
        }
        }
};

int main()
{
    chessboard cb;
    cb.display();
    cb.movePiece("b8","a6");
    cb.movePiece("b8","d7");
}