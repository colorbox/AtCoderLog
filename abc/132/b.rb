N = readline.strip.to_i
P = readline.strip.split().map(&:to_i)

result=0
P.each_with_index{|p, i|

  result+=1 if( i>0 && i<N-1 && ( (P[i-1] < P[i] && P[i] < P[i+1]) || (P[i-1] > P[i] && P[i] > P[i+1]) ) )
}

p result
