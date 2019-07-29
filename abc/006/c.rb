n, m = gets.strip.split.map(&:to_i)

(0..n).each do |b|
  next if (m > b*4 + (n-b)*3) || (m < b*4 + (n-b)*2)
  (0..n-b).each do |o|
    a = (n-b-o)
    current = b*4 + o*3 + a*2
    if current==m
      puts [a, o, b].join(' ')
      exit
    end
  end
end

puts '-1 -1 -1'
