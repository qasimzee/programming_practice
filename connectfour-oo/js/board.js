//Our game model
function GameBoard(board = null) {
  if (board)
    this.board = board;
  else  {
    this.board = [
      [-1,-1,-1,-1,-1,-1,-1],
      [-1,-1,-1,-1,-1,-1,-1],
      [-1,-1,-1,-1,-1,-1,-1],
      [-1,-1,-1,-1,-1,-1,-1],
      [-1,-1,-1,-1,-1,-1,-1],
      [-1,-1,-1,-1,-1,-1,-1],
    ];
  }
  this.player = {red:1, blue:2};
  this.board_width = 7;
  this.board_height = 6;
  this.current_player = this.player.red;  //Red to move first
  this.is_finished = false;
  this.is_drawn = false;
  this.winner = null;
  this.winning_pieces = null; //Return the coordinates of the winning pieces
}

GameBoard.prototype.boardlog = function() {
  console.log(this.board);
}

/**
 * It's a public function, it accepts the column number 
 * and calculates the possible move plus also sets whether the game
 * is finished and/or drawn.
 * */
GameBoard.prototype.makeMove = function(col) {
  var i;
  //Return null if game is already finished
  if (this.is_finished)
    return null;
  for (i = 0; i < this.board_height; i++) {
    if (this.board[i][col] != -1) {
      break;
    }
  }

  if (i > 0) {
    this.board[i - 1][col] = this.current_player;
    this.isFinished(i - 1, col);
    this.isDrawn(i - 1, col);
    this.current_player = this.current_player == this.player.red ? this.player.blue : this.player.red;
    return i - 1;
  }
  return null;
}

GameBoard.prototype.currentPlayerColor = function() {
  return this.current_player == this.player.red ? 'red' : 'blue';
}

GameBoard.prototype.nextPlayerColor = function() {
  return this.current_player == this.player.red ? 'blue' : 'red';
}

GameBoard.prototype.checkBottom = function(row, col) {
  var positions = [];
  while (row >= 0 && this.board[row][col] == this.current_player)
    row--;
  var winning_count = 0;
  
  for (var i = row + 1; i < this.board_height; i++) {
    if (this.board[i][col] == this.current_player) {
      positions.push({row:i, col:col});
      winning_count++;
    }
    else {
      break
    }
  }
  if (winning_count == 4) {
    return positions;
  }
  
}

GameBoard.prototype.checkRight = function(row, col) {
  var positions = [];
  while (col >= 0 && this.board[row][col] == this.current_player)
    col--;
  var winning_count = 0;
  for (var i = col + 1; i < this.board_width; i++) {
    if (this.board[row][i] == this.current_player) {
      positions.push({row: row, col: i});
      winning_count++;
    }
    else {
      break;
    }
  }
  if (winning_count >= 4) {
    return positions;
  }
  
}

GameBoard.prototype.checkRightDg = function(row, col) {
  var positions = [];
  while (col >= 0 && row >= 0 && this.board[row][col] == this.current_player) {
    col--;
    row--;
  }
  var winning_count = 0;
  for (var j = row + 1, i = col + 1; i < this.board_width, j < this.board_height; i++, j++) {
    if (this.board[j][i] == this.current_player) {
      positions.push({row:j, col: i});
      winning_count++;
    }
    else {
      break;
    }
  }
  if (winning_count >= 4) {
    return positions;
  }
}

GameBoard.prototype.checkLeftDg = function(row, col) {
  var positions = [];
  while (col < this.board_width && row >= 0 && this.board[row][col] == this.current_player) {
    col++;
    row--;
  }
  var winning_count = 0;
  for (var j = row + 1, i = col - 1; i >= 0, j < this.board_height; i--, j++) {
    if (this.board[j][i] == this.current_player) {
      positions.push({row: j, col: i});
      winning_count++;
    }
    else {
      break;
    }
  }

  if (winning_count >= 4) {
    return positions;
  }
}

GameBoard.prototype.isFinished = function(row, col) {
  //Need to rewrite, can be done in lesser code using string function calls .apply
  var winning_pieces = this.checkBottom(row, col);
  if (!winning_pieces)
    winning_pieces = this.checkRight(row, col);
  if (!winning_pieces)
    winning_pieces = this.checkRightDg(row, col);
  if (!winning_pieces)
    winning_pieces = this.checkLeftDg(row, col);
  
  if (winning_pieces) {
    this.winner = this.current_player;
    this.winning_pieces = winning_pieces;
    this.is_finished = true;
  }
}

/**
 * Check if top row is filled.
 * */
GameBoard.prototype.isDrawn = function() {
  for (var i = 0; i < this.board_width; i++) {
    if (this.board[0][i] == -1) {
      return;
    }
  }
  this.is_finished = true;
  this.is_drawn = true;
}

GameBoard.prototype.getIsFinished = function() {
  return this.is_finished;
}