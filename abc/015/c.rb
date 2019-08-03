n, k = gets.strip.split.map(&:to_i)
t = readlines.map {|line| line.strip.split.map(&:to_i) }

if k==1
  puts t.flatten.inject(:^).zero? ? 'Found' : 'Nothing'
  exit
end

bug = false
(k**n).times do |index|
  base_k_num = ('0'*n + index.to_s(k)).split('').last(n)

#p [index,base_k_num]

  tmp = nil
  base_k_num.each_with_index do |num, i|
    tmp||=0
    tmp = tmp^t[i][num.to_i]
  end
  if tmp.zero?
    bug=true
    break
  end
end

if bug
  puts 'Found'
else
  puts 'Nothing'
end
