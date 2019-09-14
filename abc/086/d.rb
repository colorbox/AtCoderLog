# 参考にした実装
# https://atcoder.jp/contests/abc086/submissions/2340945
# https://atcoder.jp/contests/abc086/submissions/2789430

# 二次元累積和行列の構築処理
# https://paiza.hatenablog.com/entry/2014/05/28/もし女子大生プログラマに『アルゴリズム』を図

n, k = gets.strip.split.map(&:to_i)
xyc = readlines.map {|line| line.strip.split }
k2 = 2*k

cum = Array.new(k2+1) { [0]*(k2+1) }

xyc.each do |x, y, c|
  # (2k) * (2k) に収めるための修正
  x = x.to_i % k2
  y = y.to_i % k2

  # 全部白にする補正
  y = (y+k)%k2 if c=='W'

  # 累積和行列作成の仕込み
  cum[x+1][y+1] += 1
  # 累積和計算時に一つの正方形計算で済むように補正
  cum[(x+k)%k2 + 1][(y+k)%k2 + 1] += 1
end

(1..k2).each do |i|
  (1..k2).each do |j|
    cum[i][j] += cum[i-1][j] + cum[i][j-1] - cum[i-1][j-1]
  end
end

ans = 0

(1..k).each do |i|
  (1..k).each do |j|
    current = cum[i+k][j+k] - cum[i+k][j] - cum[i][j+k] +  cum[i][j]
    ans = [ans, current, n-current].max
  end
end

p ans
