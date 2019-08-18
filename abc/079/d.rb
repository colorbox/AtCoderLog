h, w = gets.strip.split.map(&:to_i)
c = 10.times.map { gets.strip.split.map(&:to_i) }
a = h.times.map { gets.strip.split.map(&:to_i) }

10.times do |via|
  10.times do |from|
    10.times do |to|
      c[from][to] = c[from][via] + c[via][to] if c[from][to] > c[from][via] + c[via][to]
    end
  end
end

p a.flatten.select {|e| e>=0 }.map {|e| c[e][1] }.inject(:+)
