n, k = gets.strip.split.map(&:to_i)
xy = readlines.map {|line| line.strip.split.map(&:to_i) }

xs = xy.sort_by {|x,y| x }
ys = xy.sort_by {|x,y| y }

result = (ys[0][-1] - ys[-1][-1]) * (xs[0][0] - xs[-1][0])

n.times do |lxi|
  lx = xs[lxi]
  (lxi+1...n).each do |rxi|
    n.times do |byi|
      by = ys[byi]
      byy = ys[byi][1]
      (byi+1...n).each do |tyi|
        rx = xs[rxi]
        ty = ys[tyi]
        tyy = ys[tyi][1]


        next if !(lx[0]..rx[0]).include?(by[0]) || !(lx[0]..rx[0]).include?(ty[0])

        num=0
        xs[lxi..rxi].each do |x, y|
          num+=1 if byy <= y && y <= tyy
        end
        if num >= k
          current_result = (ty[-1] - by[-1]) * (rx[0] - lx[0])
          result = current_result if current_result < result
        end

      end
    end
  end
end

p result
