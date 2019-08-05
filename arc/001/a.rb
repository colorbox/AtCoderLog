n=gets.strip.to_i
c = gets.strip.split('').map(&:to_i).group_by {|e| e }.map {|k, v| v.length }.sort
tmp = [0,0,0].concat(c).last(4)
puts tmp.minmax.reverse.join(' ')
