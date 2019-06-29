N,M = readline.strip.split().map(&:to_i)
bridges = readlines.map(&:strip).map {|bridge| bridge.split.map(&:to_i) }
islands_with_bridge = bridges.flatten.uniq

result = 'IMPOSSIBLE'
counts = []
bridges.each do |bridge|
  index =
    if bridge[0]==1
      bridge[1]
    elsif bridge[1]==N
      bridge[0]
    end
  next if index.nil?

  counts[index] ||= 0
  counts[index]+=1
  if counts[index]==2
    puts 'POSSIBLE'
    exit
  end
end

puts result

#p N
#p M
#p bridges

