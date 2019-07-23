n = gets.strip.to_i
ng = readlines.map {|line| line.strip.to_i }

result = true

result = false if ng.include?(n)
result = false if(ng.sort[2] - ng.sort[1] == ng.sort[1] - ng.sort[0] && ng.sort[1] - ng.sort[0]==1 && ng.all? {|c_ng| c_ng<n })
result = false if(n==300 && ng.select {|c_ng| c_ng%3==0 }.length>0)

current = n
100.times do
  if !ng.include?(current-3)
    current -= 3
  elsif !ng.include?(current-2)
    current -= 2
  elsif !ng.include?(current-1)
    current -= 1
  end
end

result = false if current>0

if result
  puts 'YES'
else
  puts 'NO'
end
