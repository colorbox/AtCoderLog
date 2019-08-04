B = 2.times.map { gets.split.map(&:to_i) }
C = readlines.map {|line| line.split.map(&:to_i) }

MEMO={}

def score(board)
  score=0
  2.times {|i| 3.times {|j| score += B[i][j] if board[i*3 + j]==board[(i+1)*3 + j] } }
  3.times {|i| 2.times {|j| score += C[i][j] if board[i * 3 + j]==board[i * 3 + j+1] } }

  score
end

def dfs(board, turn)
  return score(board) if turn > 9
  return MEMO[board] if MEMO[board]

  scores = 9.times.select {|cell| board[cell].to_i.zero?}
             .map {|cell| board.dup.tap {|b| b[cell] = (turn.odd? ? '1' : '2') } }
             .map {|next_board| dfs(next_board, turn+1) }

  (turn.odd? ? scores.max : scores.min).tap {|s| MEMO[board] = s }
end

fullscore = score('1'*9)
score = dfs('0'*9, 1)

#p fullscore
puts [score, fullscore - score]
