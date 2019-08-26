a, b = gets.strip.split.map(&:to_i)

result = Array.new(50){ ['#']*100 } + Array.new(50){ ['.']*100 }
a-=1
b-=1

(a/50.0).ceil.times do |i|
  50.times do |j|
    break if a==0
    y = i*2
    x = i.odd? ? j*2+1 : j*2
    result[y][x]='.'
    a-=1
  end
end

(b/50.0).ceil.times do |i|
  50.times do |j|
    break if b==0
    y = (99-i*2)
    x = y.odd? ? j*2+1 : j*2
    result[y][x]='#'
    b-=1
  end
end

puts [result.length, result.first.length]
result.each do |l|
  puts l.join('')
end
