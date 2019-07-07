l, r = gets.strip.split(' ').map(&:to_i)

if (r-l+1 >= 2019)
  p 0
  exit
end




result = 2019

arr = (l..r).to_a
arr.each_with_index do |num, i|

  arr.each_with_index do |num, j|

    next if  i>=j
    tmp = (arr[i] * arr[j])%2019
#    p [arr[i], arr[j]] if tmp < result
    result = [tmp, result].min

  end
end

p result
