n, k = gets.split.map(&:to_i)

#p [n,k].inspect

alter_k = k%2==1 ? k : k/2

candidates = (1..n).to_a.keep_if {|e| e%alter_k==0 }

p candidates.size ** 3 and exit if k%2==1

p candidates.partition {|e| e%k==0 }.map {|e|e.count**3 }.inject(0){|m,e|m+e}
