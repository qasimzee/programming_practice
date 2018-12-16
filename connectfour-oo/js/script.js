var game_board = new GameBoard();
var cell_size = 52;
var game_finished = false;

$('div.cell').click(function(){
  var cell_pos = $(this).offset();
  var parent_pos = $('div.board').offset();
  var left = cell_pos.left - parent_pos.left;
  $('div.piece').show();
  $('div.piece').css({left: left, top: 0});
  $('div.piece').css({'background-color': game_board.currentPlayerColor()});
  var col_number = Math.ceil(left / cell_size);
  
  var avaiable_row = game_board.makeMove(col_number);
  if (avaiable_row != null && !game_finished) {
    game_finished = game_board.is_finished;
    var current_pos = $('div.piece').position();
    $('div.piece').animate({
      top: (avaiable_row - 1) * (cell_size) + 3
      },
      300,
      "linear",
      function() {
        $('div.piece').show();
        var elem = 'div.row:nth-child('+(avaiable_row + 2)+') div.cell:nth-child('+(col_number + 1)+')';
        $(elem).append('<div class="current-piece" style="background-color:'+ game_board.nextPlayerColor() +'"></div>');
        $('div.current-move').css({'background-color': game_board.currentPlayerColor()});
        $('div.piece').css({top: 0});
        $('div.piece').css({'background-color': '#fff'});
        if (game_board.is_finished) {
          if (game_board.winner) {
            var winner =  game_board.winner == game_board.player.red ? 'Red player' : 'Blue Player';
            alert(winner + ' WON');
            animateFinish(game_board.winning_pieces);
          }
          else {
            alert('Game Drawn');
          }
        }
    });  
  }
  else {
    $('div.piece').css({'background-color': '#fff'});
  }
  $('div.piece').css({top: 0});  
  
}); 

function animateFinish(positions) {
  var winning = -1;
  for (var i = 0; i < positions.length; i++) {
    var elem = 'div.row:nth-child('+(positions[i].row + 2)+') div.cell:nth-child('+(positions[i].col + 1)+')';
    
    $(elem).addClass('winning-cell');
  }
  
}

$('a.reset').click(function(){
  location.reload();
});