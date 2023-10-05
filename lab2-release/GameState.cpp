//
//  GameState.cpp
//  Connect Four Game
//
//  Created by Tarek Abdelrahman on 2019-06-07.
//  Modified by Tarek Abdelrahman on 2020-09-17.
//  Modified by Salma Emara and Ethan Hugh on 2023-09-06.
//  Copyright © 2019-2020 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.
//

#include "GameState.h"
#include "globals.h"

// ECE244 Student: add you code below

// Constructor
GameState:: GameState(){
    selectedRow = 0;
    selectedColumn = 0;
    moveValid = true;
    gameOver = false;
    turn = true;
    winner = Empty;
    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j < boardSize; j++){
            gameBoard[i][j] = Empty;
        }
    }
}

int GameState:: get_selectedRow(){
    return selectedRow;
}

int GameState:: get_selectedColumn(){
    return selectedColumn;
}

void GameState:: set_selectedRow(int value){
    for(int i = 0; i < boardSize; i++){
        if(gameBoard[i][selectedColumn] == 0){
            selectedRow = value;
            break;
        }else{
            moveValid = false;
        }
    }
    if(gameBoard[selectedRow][selectedColumn] == 0){
        return;
    }else{
        moveValid = false;
        return;
        }
}

void GameState:: set_selectedColumn(int value){
    if (value >= 0 && value <= boardSize){
        selectedColumn = value;
    }else{
        moveValid = false;
        return;
    }
}

bool GameState:: get_moveValid(){
    return moveValid;
}

void GameState:: set_moveValid(bool value){
    moveValid = value;
}

bool GameState:: get_gameOver(){
    return gameOver;
}

void GameState:: set_gameOver(bool value){ //set to true if the game is over
    gameOver = value;
}

bool GameState:: get_turn(){
    return turn;
}

void GameState:: set_turn(bool value){
    turn = value;
}


int GameState:: get_winner(){
    return winner;
}

void GameState:: set_winner(int value){
    winner = value;
}

int GameState:: get_gameBoard(int rol, int col){
    if(rol >= 0 && rol <= boardSize && col >= 0 && col <= boardSize){
        return gameBoard[rol][col];
    }else{
        return Empty;
    }
}

void GameState:: set_gameBoard(int rol, int col, int value){
    if (value != -1 || value != 1){
        return;
    }
    if(rol >= 0 && rol <= boardSize && col >= 0 && col <= boardSize){
        gameBoard[rol][col] = value;
    }else{
        return;
    }
}





