n = gets.strip.to_i
cc = readlines.map {|l| l.strip.to_i }

results = [cc.shift]
cc.each do |c|
  i=results.bsearch_index{|e| c<e }
  if i
    results[i]=c
  else
    results.push(c)
  end
#p results
end
p n-results.length
