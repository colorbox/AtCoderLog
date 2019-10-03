h, w = gets.strip.split.map(&:to_i)
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

q = [s]
INF=10**12
dist = Array.new(h) { [INF]*w }
dist[s.first][s.last] = 0
until q.empty?
  cy, cx = c = q.shift
  dirs(*c).each do |y, x|
    next if y < 0 || y >= h || x < 0 || x >= w

    cd = cc[y][x]==1 ? 1+dist[cy][cx] : dist[cy][cx]
    next if dist[y][x] <= cd

    dist[y][x] = cd
    if cc[y][x]==1
      q.push([y, x])
    else
      q.unshift([y, x])
    end
  end
end

# cc.each {|l|p l}
# p "###"
# dist.each {|l|p l}

if dist[g.first][g.last] <= 2
  puts 'YES'
else
  puts 'NO'
end
