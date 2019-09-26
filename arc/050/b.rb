r, b = gets.strip.split.map(&:to_i)
x, y = gets.strip.split.map(&:to_i)

result = (0..[r,b].max).bsearch {|bc|
  !( r >= bc && b >= bc && ((r-bc)/(x-1)) + ((b-bc)/(y-1)) >= bc )
}

p result-1
