n, y = gets.strip.split.map(&:to_i)

k_10 = 10000
k_5 = 5000
k_1 = 1000

(0..n).each do |i|
  (0..n-i).each do |j|
    if k_10*i + k_5*j + k_1*(n-i-j) == y
      puts [i, j, n-i-j].join(' ')
      exit
    end
  end
end

puts '-1 -1 -1'
