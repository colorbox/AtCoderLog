r, c = gets.strip.split.map {|num| num.to_i-1 }
sy, sx = gets.strip.split.map {|num| num.to_i-1 }
gy, gx = gets.strip.split.map {|num| num.to_i-1 }
maze = readlines.map {|line| line.strip.chars }

queue = [[sy, sx, []]]

maze_speed = []
r.times do
  maze_speed.push(Array.new(c, Float::INFINITY))
end
maze_speed[sy][sx]=0

result = nil
while !queue.empty?
  current = queue.shift

  if current[0]==gy && current[1]==gx
    result ||=  current.last
    result = current.last if current.last.length < result.length
  end

  nexts = [
    [current[0]-1, current[1]],
    [current[0]+1, current[1]],
    [current[0], current[1]-1],
    [current[0], current[1]+1]
  ]

  nexts.each do |n|
    in_height = (n[0] >= 0 && n[0] < r)
    in_width = (n[1] >= 0 && n[1]< c)
    has_not_go = !current[2].include?(n.slice(0,2))
    if in_height && in_width && maze[n[0]][n[1]]=='.' && has_not_go && maze_speed[n[0]][n[1]] > current[2].length
      tmp = current[2].dup
      tmp.push(current.slice(0,2))
      queue.push([n[0], n[1], tmp])
      maze_speed[n[0]][n[1]] = current[2].length
    end
  end
end

p result.length
