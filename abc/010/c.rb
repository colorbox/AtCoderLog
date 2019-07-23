tx1, ty1, tx2, ty2, t, v = gets.strip.split.map(&:to_f)
n = gets.strip.to_i
xy = readlines.map {|line| line.strip.split.map(&:to_f) }

def  distance(x1, y1, x2, y2)
  Math.sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) )
end

xy.each do|gx, gy|
  if distance(tx1, ty1, gx, gy) + distance(gx, gy, tx2, ty2) <= t*v
    puts 'YES'
    exit
  end
end

puts 'NO'
