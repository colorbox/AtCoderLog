mm = readlines.map {|line| line.strip.split('').map(&:to_sym) }

def walk(mm, s)
  sx, sy = s
  d = [0, 1, 0, -1]

  stack = [s]
  land = []
  until stack.empty?
    c = stack.pop
    cy, cx = c
    next if !((0...10)===cy) || !((0...10)===cx) || mm[cy][cx]==:x || land.include?(c)
    land << c if mm[cy][cx]==:o

    4.times do |i|
      dy, dx = d[i], d[i^1]
      stack.push([cy+dy, cx+dx])
    end
  end

  land
end


def check(mm, s)
  land = walk(mm, s)
  10.times do |i|
    10.times do |j|
      if mm[i][j]==:o && !land.include?([i, j])
        return false
        exit
      end
    end
  end

  true
end


10.times do |i|
  10.times do |j|
    past = mm[i][j]
    mm[i][j] = :o
    if check(mm, [i,j])
#mm.each {|l|p l}
#p [i,j]
      puts 'YES'
      exit
    end

    mm[i][j] = past
  end
end

puts 'NO'
#mm.each {|l|p l}
