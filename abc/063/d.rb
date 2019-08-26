n, a, b=gets.strip.split.map(&:to_i)
h = readlines.map {|line| line.strip.to_i }
c=a-b

ok=(h.max/b.to_f).ceil
ng=1
while ok-ng > 1
#p [ok,ng]
  mid = (ok+ng)/2
  remains = h.map {|e| e-b*mid }.select {|e| e>0 }
  if remains.length.zero?
    ok=mid
    next
  end
  if mid >= remains.map {|e| (e/c.to_f).ceil }.inject(:+)
    ok=mid
  else
    ng=mid
  end
end

p ok
