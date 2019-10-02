require 'set'

h, w = gets.strip.split.map(&:to_i)
@h, @w = [h, w]
cc = Array.new(h) { [0]*w }
s=g=nil
h.times do |i|
  gets.strip.split('').each_with_index do |c, j|
    cc[i][j] = 1 if c=='#'
    s = [i, j] if c=='s'
    g = [i, j] if c=='g'
  end
end

d = [0, 1, 0, -1]
@dd = 4.times.map {|i| [d[i], d[i^1]] }
def dirs(y, x)
  @dd.map {|dy, dx| [y+dy, x+dx] }
end

def walk_roads(g, q, cc)
  h = cc.length
  w = cc.first.length
  visited = Array.new(h) { [false]*w }
  until q.empty?
    cy, cx = c = q.shift
    if g==c
      puts 'YES'; exit
    end
    next if visited[cy][cx]
    visited[cy][cx]=true

    dirs(*c).each do |y, x|
      # next if !((0...h)===y) || !((0...w)===x) || cc[y][x]==1
      next if y<0 || y>=h ||x<0 || x>=w || cc[y][x]==1
      q.push([y, x])
    end
  end

  # cc.each {|l| p l}
  visited
end

def break_wall(visited, cc)
  h = cc.length
  w = cc.first.length
  broken = Set.new
  h.times do |i|
    w.times do |j|
      if visited[i][j]
        dirs(i, j).each do |y, x|
          next if y<0 || y>=h ||x<0 || x>=w || cc[y][x]==0 || visited[y][x]

          cc[y][x]=0
          broken.add([y, x])
        end
      end
    end
  end

  broken.to_a
end


first_trip = walk_roads(g, [s], cc)
first_break = break_wall(first_trip, cc)

second_trip = walk_roads(g, first_break, cc)
second_break = break_wall(second_trip, cc)

walk_roads(g, second_break, cc)

puts 'NO'
