rewuire 'byebug'
# from https://atcoder.jp/contests/abc142/submissions/7778197
n,m = gets.split.map!(&:to_i)
kk = m.times.map {
  [
    gets.strip.split.map(&:to_i),
    gets.strip.split.map(&:to_i)
  ]
}

INF = 10**10
dp = Array.new(2**n, INF)

kk.each do |(price, _), targets|
  byebug
  key_state = targets.inject(0) {|memo, c| memo+2**(c-1) }
  dp[key_state] = price if dp[key_state] > price

  dp.each_with_index do |price, current_state|
    next_state = current_state | key_state
    dp[next_state] = dp[current_state] + price if dp[next_state] > dp[current_state] + price
  end

  p dp
end

p dp.last
