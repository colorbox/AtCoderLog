MOD =  (10e8+7).to_i

$pascal = [
  [1],
  [1,1]
]

def pascal(n,i)
  return 1 if n==0
  return $pascal[n][i] if $pascal[n] && $pascal[n][i]

  if n==i || i==0
    $pascal[n] ||= []
    $pascal[n][i] = 1
  else
    $pascal[n] ||= []
    $pascal[n][i] = ((pascal(n-1, i-1) + pascal(n-1, i)))%MOD
  end

  return $pascal[n][i]
end

N,K = readline.strip.split.map(&:to_i)


dp = []

(1..K).to_a.each do |i|

  if i > N-K+1
    p 0
  else
    p ( pascal(N-K+1, i) * pascal(K-1, i-1))%MOD
  end

end
