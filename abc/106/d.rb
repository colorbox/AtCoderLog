n, m, q = gets.strip.split.map(&:to_i)
lr = m.times.map { gets.strip.split.map(&:to_i)}
pq = q.times.map { gets.strip.split.map(&:to_i)}

board = Array.new(n+1){ [0]*(n+1) }

lr.each do |l, r|
  board[l][r]+=1
end

#(0..n).each do |i|
#    p board[i]
#end


(1..n).each do |i|
  (1..n).each do |j|
    board[i][j]+=board[i-1][j]
  end
end

(1..n).each do |i|
  (1..n).each do |j|
    board[i][j]+=board[i][j-1]
  end
end

#p "---"
#(0..n).each do |i|
#    p board[i]
#end

results = []

pq.each do |from, to|
  current = board[to][to] - board[to][from-1] - board[from-1][to] + board[from-1][from-1]
  results << current
end

results.each do |r|
  p r
end
