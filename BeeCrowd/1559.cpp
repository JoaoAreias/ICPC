#include <iostream>
#include <cstring>


int main(){
    int n;
    int board[4][4];

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    const char* move_names[] = {"DOWN", "LEFT", "RIGHT", "UP"};
    char available_moves;
    bool done;

    std::cin >> n;
    while(n--){
        // Inicializa as variáveis
        available_moves = 0;
        memset(board, 0, sizeof(board));
        done = false;

        // Lê o tabuleiro
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                std::cin >> board[i][j];
                if (board[i][j] == 2048)
                    done = true;
            }
        }
        
        // Descobre os movimentos disponíveis
        if (!done){
            for(int i=0; i<4; i++){
                for(int j=0; j<4; j++){
                    // Pula posições vazias
                    if (board[i][j] == 0)
                        continue;
                    
                    // Verifica se o movimento é possível
                    if (i < 3 && (board[i][j] == board[i+1][j] || board[i+1][j] == 0))
                        available_moves |= 1 << 0;
                    if (j > 0 && (board[i][j] == board[i][j-1] || board[i][j-1] == 0))
                        available_moves |= 1 << 1;
                    if (j < 3 && (board[i][j] == board[i][j+1] || board[i][j+1] == 0))
                        available_moves |= 1 << 2;
                    if (i > 0 && (board[i][j] == board[i-1][j] || board[i-1][j] == 0))
                        available_moves |= 1 << 3;

                    // Se todos os movimentos forem possíveis, não precisa continuar
                    if (available_moves == 0b1111)
                        break;
                }
                if (available_moves == 0b1111)
                    break;
            }
        }

        // Imprime os movimentos disponíveis
        if (available_moves == 0 || done)
            std::cout << "NONE" << std::endl;
        else {
            bool first = true;
            for(int i=0; i<4; i++){
                if (available_moves & (1 << i)){
                    std::cout << (first ? "" : " ") << move_names[i];
                    first = false;
                }
            }
            std::cout << std::endl;
        }
    }
    return 0;
}