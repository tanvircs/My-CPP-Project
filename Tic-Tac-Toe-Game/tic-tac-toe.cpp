#include <iostream>
#include <vector>

enum class Player { None, X, O };

class TicTacToe {
public:
    TicTacToe() : board_(9, Player::None), currentPlayer_(Player::X) {}

    void play() {
        bool gameFinished = false;

        while (!gameFinished) {
            printBoard();
            int move = getPlayerMove();
            makeMove(move);

            if (checkWin()) {
                printBoard();
                std::cout << "Player " << playerToString(currentPlayer_) << " wins!" << std::endl;
                gameFinished = true;
            } else if (checkDraw()) {
                printBoard();
                std::cout << "It's a draw!" << std::endl;
                gameFinished = true;
            } else {
                currentPlayer_ = (currentPlayer_ == Player::X) ? Player::O : Player::X;
            }
        }
    }

private:
    std::vector<Player> board_;
    Player currentPlayer_;

    void printBoard() const {
        std::cout << "Current board:" << std::endl;
        for (int i = 0; i < 9; i += 3) {
            std::cout << " " << playerToString(board_[i]) << " | " << playerToString(board_[i + 1]) << " | "
                      << playerToString(board_[i + 2]) << std::endl;
            if (i < 6)
                std::cout << "---+---+---" << std::endl;
        }
        std::cout << std::endl;
    }

    std::string playerToString(Player player) const {
        if (player == Player::X)
            return "X";
        else if (player == Player::O)
            return "O";
        else
            return " ";
    }

    int getPlayerMove() const {
        int move;
        std::cout << "Player " << playerToString(currentPlayer_) << ", enter your move (1-9): ";
        std::cin >> move;
        return move - 1; // Adjust to 0-based index
    }

    void makeMove(int move) {
        if (isValidMove(move)) {
            board_[move] = currentPlayer_;
        } else {
            std::cout << "Invalid move. Try again." << std::endl;
            makeMove(getPlayerMove());
        }
    }

    bool isValidMove(int move) const {
        return move >= 0 && move < 9 && board_[move] == Player::None;
    }

    bool checkWin() const {
        // Check rows
        for (int i = 0; i < 9; i += 3) {
            if (board_[i] != Player::None && board_[i] == board_[i + 1] && board_[i] == board_[i + 2])
                return true;
        }

        // Check columns
        for (int i = 0; i < 3; ++i) {
            if (board_[i] != Player::None && board_[i] == board_[i + 3] && board_[i] == board_[i + 6])
                return true;
        }

        // Check diagonals
        if (board_[0] != Player::None && board_[0] == board_[4] && board_[0] == board_[8])
            return true;

        if (board_[2] != Player::None && board_[2] == board_[4] && board_[2] == board_[6])
            return true;

        return false;
    }

    bool checkDraw() const {
        for (int i = 0; i < 9; ++i) {
            if (board_[i] == Player::None)
                return false;
        }
        return true;
    }
};

int main() {
    TicTacToe game;
    game.play();
    return 0;
}
