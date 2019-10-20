n = gets.strip.to_i
ll = gets.strip.split.map(&:to_i).sort

result=0
(n-2).times do |i|
  a=ll[i]
  k=i+2
  (i+1...n).each do |j|
    b=ll[j]
    while (k<n && ll[k] < a+b && k>j)
      p [a,b,ll[k]]
      k+=1
      result+=1
    end
  end
end

p result
