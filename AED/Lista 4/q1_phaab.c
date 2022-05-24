#include <stdio.h>
#include <ctype.h>
char chess[8][8];

int checkmate(char piece, int line, int column);
int pawn(int line, int column);
int horse(int line, int column);
int king(int line, int column);
int tower(int line, int column);
int bishop(int line, int column);
int queen(int line, int column);

int main(void){
    int result = 0;
    int i, j;
    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            scanf(" %c", &chess[i][j]);
        }
    }

    for(i = 0; i < 8 && !result; i++){
        for(j = 0; j < 8 && !result; j++){
            if(chess[i][j] != '-' && islower(chess[i][j])){
                result = checkmate(chess[i][j], i, j);
            }
        }
    }

    if(result){
        printf("XEQUE");
    }
    else{
        printf("NAO XEQUE");
    }

    return 0;
}

int checkmate(char piece, int line, int column){
    int checkOrNot = 0;

    if(piece == 'p'){
        checkOrNot = pawn(line,column);
    }

    else if(piece == 'c'){
        checkOrNot = horse(line, column);
    }

    else if(piece == 'k'){
        checkOrNot = king(line, column);
    }

    else if(piece == 't'){
        checkOrNot = tower(line,column);
    }

    else if(piece == 'b'){
        checkOrNot = bishop(line,column);
    }

    else if(piece == 'q'){
        checkOrNot = queen(line,column);
    }

    return checkOrNot;
}

int queen(int line, int column){
    int check = 1;
    int i, j;

    //down right
    for(i = 0; i<8-line && check; i++){
        if(chess[line+1+i][column+1+i] != '-'){
            if (chess[line+1+i][column+1+i] == 'K' && check){
                return 1;
            }
            check = 0;
        }
    }

    //up left
    check = 1;
    for(i = 0; i<line && check; i++){
        if(chess[line-1-i][column-1-i] != '-'){
            if (chess[line-1-i][column-1-i] == 'K' && check){
                return 1;
            }
            check = 0;
        }
    }

    //up right
    check = 1;
    for(i = 0; i<line && check; i++){
        if(chess[line-1-i][column+1+i] != '-'){
            if (chess[line-1-i][column+1+i] == 'K' && check){
                return 1;
            }
            check = 0;
        }
    }

    //down left
    check = 1;
    for(i = 0; i<8-line && check; i++){
        if(chess[line+1+i][column-1-i] != '-'){
            if (chess[line-1-i][column+1+i] == 'K' && check){
                return 1;
            }
            check = 0;
        }
    }

    //up
    for (i = 0; i < line && check; i++){
        if(chess[line-1-i][column] != '-'){
            if (chess[line-1-i][column] == 'K' && check){
                return 1;
            }
            check = 0;
        }
    }

    //down
    check = 1;
    for (i = 0; i < 8 - line && check; i++){
        if(chess[line+1+i][column] != '-'){
            if (chess[line+1+i][column] == 'K' && check){
                return 1;
            }
            check = 0;
        }
    }

    //left
    check = 1;
    for (i = 0; i < column && check; i++){
        if(chess[line][column-1-i] != '-'){
            if (chess[line][column-1-i] == 'K' && check){
                return 1;
            }
            check = 0;
        }
    }

    //right
    check = 1;
    for (i = 0; i < 8 - column && check; i++){
        if(chess[line][column+1+i] != '-'){
            if (chess[line][column+1+i] == 'K' && check){
                return 1;
            }
            check = 0;
        }
    }

    return 0;
}

int bishop(int line, int column){
    int check = 1;
    int i, j;
    //down right
    for(i = 0; i<8-line && check; i++){
        if(chess[line+1+i][column+1+i] != '-'){
            if (chess[line+1+i][column+1+i] == 'K' && check){
                return 1;
            }
            check = 0;
        }
    }

    //up left
    check = 1;
    for(i = 0; i<line && check; i++){
        if(chess[line-1-i][column-1-i] != '-'){
            if (chess[line-1-i][column-1-i] == 'K' && check){
                return 1;
            }
            check = 0;
        }
    }

    //up right
    check = 1;
    for(i = 0; i<line && check; i++){
        if(chess[line-1-i][column+1+i] != '-'){
            if (chess[line-1-i][column+1+i] == 'K' && check){
                return 1;
            }
            check = 0;
        }
    }

    //down left
    check = 1;
    for(i = 0; i<8-line && check; i++){
        if(chess[line+1+i][column-1-i] != '-'){
            if (chess[line-1-i][column+1+i] == 'K' && check){
                return 1;
            }
            check = 0;
        }
    }

    return 0;
}

int tower(int line, int column){
    int check = 1;
    int i, j;
    //up
    for (i = 0; i < line && check; i++){
        if(chess[line-1-i][column] != '-'){
            if (chess[line-1-i][column] == 'K' && check){
                return 1;
            }
            check = 0;
        }
    }

    //down
    check = 1;
    for (i = 0; i < 8 - line && check; i++){
        if(chess[line+1+i][column] != '-'){
            if (chess[line+1+i][column] == 'K' && check){
                return 1;
            }
            check = 0;
        }
    }

    //left
    check = 1;
    for (i = 0; i < column && check; i++){
        if(chess[line][column-1-i] != '-'){
            if (chess[line][column-1-i] == 'K' && check){
                return 1;
            }
            check = 0;
        }
    }

    //right
    check = 1;
    for (i = 0; i < 8 - column && check; i++){
        if(chess[line][column+1+i] != '-'){
            if (chess[line][column+1+i] == 'K' && check){
                return 1;
            }
            check = 0;
        }
    }
    
    return 0;
}

int pawn(int line, int column){
    
    if(chess[line + 1][column + 1] == 'K'){
        return 1;
    }

    else if(chess[line + 1][column - 1] == 'K'){
        return 1;
    }
    
    return 0;
}

int king(int line, int column){
    int i, j;
    
    line = line - 1;
    column = column - 1;

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(chess[line + i][column + j] == 'K'){
                return 1;
            }
        }
    }

    return 0;
}

int horse(int line, int column){
    
    if(chess[line+2][column+1] == 'K'){
        return 1;
    }

    else if(chess[line+1][column+2] == 'K'){
        return 1;
    }

    else if(chess[line-1][column+2] == 'K'){
        return 1;
    }
    
    else if(chess[line-2][column+1] == 'K'){
        return 1;
    }

    else if(chess[line-2][column-1] == 'K'){
        return 1;
    }

    else if(chess[line-1][column-2] == 'K'){
        return 1;
    }

    else if(chess[line+1][column-2] == 'K'){
        return 1;
    }

    else if(chess[line+2][column-1] == 'K'){
        return 1;
    }

    return 0;
}