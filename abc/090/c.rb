n, m = gets.chomp.split.map(&:to_i)

if n==1 && m==1
  p 1
  exit;
end

if n==1 || m==1
  p [n,m].max-2
  exit;
end

p (n-2)*(m-2)
