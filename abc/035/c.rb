n, q = gets.strip.split(' ').map(&:to_i)

lr = readlines.map {|line| line.split(' ').map {|num| (num.to_i-1) } }

result = [0]*n

lr.each do|l,r|
  result[l]+=1
  result[r+1]-=1 if r+1<n
end

(1..n-1).to_a.each do |index|
  result[index] = result[index-1]+result[index]
end

result = result.map {|x| x%2 }

puts result.join('')
