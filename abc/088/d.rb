h, w = gets.strip.split.map(&:to_i)
s = readlines.map {|line| line.strip.split('') }

white_count = s.flatten.count {|e| e=='.' }

start = [0,0]
goal=[h-1, w-1]
queue = [ [ start, [start] ] ]
checked = {}

shortest = 10**12
until queue.empty?
  current, passed = queue.shift

  next if passed.length > shortest || checked[ current.to_s ]

  if current == goal
    shortest = passed.length if passed.length < shortest

#p [passed.length, passed]

    next
  end

  checked[ current.to_s ]=true

  y, x = current

  queue.push( [[y-1, x], passed.dup.push([y-1, x])] )  if (0...h)===(y-1) && (0...w)===(x) && !passed.include?( [y-1, x] ) && s[y-1][x]=='.'

  queue.push( [[y+1, x], passed.dup.push([y+1, x])] ) if (0...h)===(y+1) && (0...w)===(x) && !passed.include?( [y+1, x] ) && s[y+1][x]=='.'

  queue.push( [[y, x-1], passed.dup.push([y, x-1])] ) if (0...h)===(y) && (0...w)===(x-1) && !passed.include?( [y, x-1] ) && s[y][x-1]=='.'

  queue.push( [[y, x+1], passed.dup.push([y, x+1])] ) if (0...h)===(y) && (0...w)===(x+1) && !passed.include?( [y, x+1] ) && s[y][x+1]=='.'

end

if shortest > 10**10
  p -1
  exit
end

#p [white_count, shortest]
p white_count - shortest
