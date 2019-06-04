lines = readlines.map(&:strip)

n, a, b, c, d = lines.shift.split.map(&:to_i)
s = lines.shift.chomp.chars

blocker_index = []
(n-1).times do |index|
  blocker_index.push(index) if (s[index..index+1].join)=='##'
end

blocker_index.each do |index|
  if (a-1 <= index && index <= c-1) || (b-1 <= index && index <= d-1)
    puts 'No'
    exit
  end
end

if (d < c)
  space_index = []
  (n-2).times do |index|
    space_index.push(index) if (s[index..index+2].join)=='...'
  end

  space_index.each do |index|
    if ((b-2 <= index && index <= d-2))
      puts 'Yes'
      exit
    end
  end
  puts 'No'
else
  puts 'Yes'
end


=begin
9 1 2 8 7
..#..#...

7 1 3 7 5
....#.#.#.

```
if ((b-1 <= index && index <= d-1))
```
is not good because slipping for 1 box, it does not consider B don't move from start point, and B cannot move right than d.
3 boxes from d-1 is over 1 box from B movable spaces
so 3 boxes from d-2 is right
=end
