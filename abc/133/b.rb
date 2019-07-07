n,d = gets.strip.split(' ').map(&:to_i)
x = readlines.map {|line| line.strip.split(' ').map(&:to_f) }

result = 0
n.times do |i|
  (i+1..n-1).to_a.each do |j|
    next if i==j
    dis = Math.sqrt( x[i].zip(x[j]).map {|y, z| (y-z)**2 }.inject(:+) )
    result+=1 if dis.floor - dis == 0.0
  end
end

p result
