n = gets.strip.to_i

# p n

ans=''
while(n!=0)
  if n%2==1
    n=n-1
    ans = '1'+ans
  else
    ans = '0'+ans
  end
  n = n/-2
end

ans='0' if ans.empty?

puts ans
