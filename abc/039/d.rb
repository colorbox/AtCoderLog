require 'set'

h, w = gets.strip.split.map(&:to_i)
ss = readlines.map {|line| line.strip.split('') }

dirs = [[0, -1], [1, -1], [1, 0], [1, 1], [0, 1], [-1, 1], [-1, 0], [-1, -1]]

center_blacks = Set.new
pre_blacks = Set.new

h.times do |y|
  w.times do |x|
    if ss[y][x]=='#'
      pre_blacks.add([y, x])
      count=0
      dirs.each do |dy, dx|
        cy = y+dy
        cx = x+dx
        if !((0...h)===cy) || !((0...w)===cx)
          count += 1
          next
        end
        #p [ cy,cx, (!(0...h)===cy || !(0...w)===cx) ] if cy==4
        if ss[cy][cx]=='#'
          count += 1
        else
          break
        end
      end
      center_blacks.add([y, x]) if count==8
    end
  end
end

#p center_blacks
blacks = center_blacks.dup
center_blacks.each do |y, x|
  dirs.each do |dy, dx|
    cy = y+dy
    cx = x+dx
    next if !((0...h)===cy) || !((0...w)===cx)
    blacks.add([cy, cx])
  end
end

#p blacks
#p pre_blacks

if blacks!=pre_blacks
  puts 'impossible'
  exit
else
  puts 'possible'
end



h.times do |y|
  line = []
  w.times do |x|
    if center_blacks.include?([y, x])
      line.push('#')
    else
      line.push('.')
    end
  end
  puts line.join('')
end
