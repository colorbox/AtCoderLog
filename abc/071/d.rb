N=readline.to_i
s1= readline.strip.split('')
s2= readline.strip.split('')

domino = s1.zip(s2).map {|u, d| u==d ? 1 : 2 }

frame = []
until domino.empty?
  frame << domino.shift
  domino.shift if frame.last==2
end

pre = frame.shift
result = 3
result = 6 if pre==2

MOD = 10**9+7
frame.each do |c|
  tmp=2
  tmp=1 if pre==2 && c==1
  tmp=3 if pre==2 && c==2
  result = (result * tmp)%MOD
  pre = c
end

p result
