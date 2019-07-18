r, c, k = gets.strip.split.map(&:to_i)
s = readlines.map {|line| line.strip.split('') }

counters = []
r.times do |i|
  counters.push [k]*c
end

r.times do |i|
  sinchoku = 0
  c.times do |j|
    if s[i][j]=='o'
      sinchoku +=1
    else
      sinchoku = 0
    end
    if counters[i][j] > sinchoku
      counters[i][j] = sinchoku
    else
      sinchoku = counters[i][j]
    end
  end
end

r.times do |i|
  sinchoku = 0
  c.times.reverse_each do |j|
    if s[i][j]=='o'
      sinchoku +=1
    else
      sinchoku = 0
    end
    if counters[i][j] > sinchoku
      counters[i][j] = sinchoku
    else
      sinchoku = counters[i][j]
    end
  end
end

c.times do |j|
  sinchoku = 0
  r.times do |i|
    if s[i][j]=='o'
      sinchoku +=1
    else
      sinchoku = 0
    end
    if counters[i][j] > sinchoku
      counters[i][j] = sinchoku
    else
      sinchoku = counters[i][j]
    end
  end
end

c.times do |j|
  sinchoku = 0
  r.times.reverse_each do |i|
    if s[i][j]=='o'
      sinchoku +=1
    else
      sinchoku = 0
    end
    if counters[i][j] > sinchoku
      counters[i][j] = sinchoku
    else
      sinchoku = counters[i][j]
    end
  end
end

#s.each {|ss| p ss }
#counters.each {|c| p c }

result=0

(k-1..r-k).each do |i|
  (k-1..c-k).each do |j|
    result+=1 if counters[i][j]>=k
  end
end

p result
