//Test class
/**
 * JS file to run tests
 * 
 * We can also use some opensource framework like Karam or QUnit but
 * I was not sure if that was allowed to use, so I am writing my own
 * small framework
 * */

/**
 * My own assertion function to check whether first value is equal to 
 * the second one.
 * */
function assertEquals(val1, val2) {
  return (val1 == val2) ? 'Passed' : 'Failed';
}

var tests = {
  /*  Test the following case
      [X, X, X, X, X, X, X],
      [X, X, X, X, X, X, X],
      [X, X, X, R, X, X, X],
      [X, X, X, R, B, X, X],
      [X, X, X, R, B, X, X],
      [X, X, X, R, B, X, X],
  */
  test_win_vertical: function() { 
    var game_board = new GameBoard();
    var moves = [3,4,3,4,3,4,3];
    for (var i = 0; i < moves.length; i++)
      game_board.makeMove(moves[i]);
    return assertEquals(game_board.winner, game_board.player.red);
  },

  /*  Test the following case
      [X, X, X, X, X, X, X],
      [X, X, X, X, X, X, X],
      [X, X, X, X, X, X, X],
      [X, X, X, X, X, X, X],
      [X, X, B, B, B, X, X],
      [X, X, R, R, R, R, X],
  */
  test_win_horizontal: function() { 
    var game_board = new GameBoard();
    var moves = [2,2,3,3,4,4,5];
    for (var i = 0; i < moves.length; i++)
      game_board.makeMove(moves[i]);
    return assertEquals(game_board.winner, game_board.player.red);
  },

  /*  Test the following case
      [X, X, X, X, X, X, X],
      [X, X, X, X, X, X, X],
      [X, R, X, X, X, X, X],
      [X, B, R, X, X, X, X],
      [X, R, B, R, R, X, X],
      [X, B, B, B, R, X, X],
  */
  test_win_right_diagonal: function() { 
    var game_board = new GameBoard();
    var moves = [4, 3, 3, 2, 4, 2, 2, 1, 1, 1, 1];
    for (var i = 0; i < moves.length; i++)
      game_board.makeMove(moves[i]);
    return assertEquals(game_board.winner, game_board.player.red);
  },

  /*  Test the following case
      [X, X, X, X, X, X, X],
      [X, X, X, X, X, X, X],
      [X, X, X, X, X, X, R],
      [X, X, X, X, B, R, B],
      [X, X, X, X, R, B, R],
      [X, X, X, R, B, R, B],
  */
  test_win_left_diagonal: function() { 
    var game_board = new GameBoard();
    var moves = [3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 6];
    for (var i = 0; i < moves.length; i++)
      game_board.makeMove(moves[i]);
    return assertEquals(game_board.winner, game_board.player.red);
  },

  /*  Test the following case
      [X, X, X, X, X, X, X],
      [X, B, X, X, X, X, X],
      [X, R, X, X, X, X, X],
      [X, B, R, X, X, X, X],
      [X, R, B, R, R, X, X],
      [X, B, B, B, R, X, X],
  */
  test_null_move_if_game_finished: function() { 
    var game_board = new GameBoard();
    var moves = [4, 3, 3, 2, 4, 2, 2, 1, 1, 1, 1, 1];
    var next_move = null;
    for (var i = 0; i < moves.length; i++)
      next_move = game_board.makeMove(moves[i]);
    return assertEquals(next_move, null);
  },
  /*  Test the following case
      [B, R, B, R, B, B, R],
      [B, R, B, R, R, B, R],
      [B, R, B, R, B, B, R],
      [R, B, R, B, R, R, B],
      [R, B, R, B, B, R, B],
      [R, B, R, B, R, R, B],
  */
  test_draw: function() { 
    var game_board = new GameBoard();
    var moves = [0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 2, 3, 2, 3, 2, 3, 3, 2, 3, 2, 3, 2, 5, 6, 5, 6, 5, 6, 6, 5, 6, 5, 6, 5, 4, 4, 4, 4, 4, 4];
    for (var i = 0; i < moves.length; i++)
      game_board.makeMove(moves[i]);
    return assertEquals(game_board.is_drawn, true);
  },
  
};

for (var test in tests) {
  $('.test-results').append('<div>Test - ' + test + ': ' + tests[test]() + '</div>');
}

