//
//  playMove.cpp
//  Connect Four Game
//
//  Created by Tarek Abdelrahman on 2019-06-07.
//  Modified by Tarek Abdelrahman on 2020-09-17.
//  Modified by Salma Emara and Ethan Hugh on 2023-09-06
//  Copyright © 2019-2020 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.
//
//  ECE244 Student: write your code for playMove in this file

#include "GameState.h"
#include "globals.h"


// Function prototypes (if you need)

// return false if reach bound
bool checkbound(int bound, int row, int col){
  return (row < 0 || col < 0 || row > bound || col > bound);
}

void playMove(GameState& game_state) {

  //logic for detecting wins
  int direction[4][2] = {
    {1, 0},
    {0, 1},
    {1, 1},
    {-1, 1}
};

  //logic for determining which player it is
  int player = game_state.get_turn();
  if(game_state.get_turn() == true){
    player = R; 
  }else{
    player = Y;
  }
  int sum = 0;
  int cur_index[2] = {game_state.get_selectedRow(), game_state.get_selectedColumn()};
  for(int i = 0; i < 4; i++){
    sum = 1;
    int cur_row = cur_index[0] + direction[i][0];
    int cur_col = cur_index[1] + direction[i][1];
    while(true)
    {
      if(checkbound(boardSize, cur_row, cur_col)){
        break;
      }
      if(game_state.get_gameBoard(cur_row, cur_col) != player){
        break;
      }
      cur_row += direction[i][0];
      cur_col += direction[i][1];
      sum += 1;
    }
    cur_row = cur_index[0] - direction[i][0];
    cur_col = cur_index[1] - direction[i][1];
    while(true)
    {
      if(checkbound(boardSize, cur_row, cur_col)){
        break;
      }
      if(game_state.get_gameBoard(cur_row, cur_col) != player){
        break;
      }
      cur_row -= direction[i][0];
      cur_col -= direction[i][1];
      sum += 1;
    }
    if(sum >= 4){
      game_state.set_gameOver(true);
      game_state.set_winner(player);
      return;
    }
  }
}