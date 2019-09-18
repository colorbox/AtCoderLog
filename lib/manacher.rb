require 'byebug'

# from https://snuke.hatenablog.com/entry/2014/12/02/235837

s = 'aaaaaabaaaaaa'

cc = 0
r = Array.new(s.length, 0)
s.length.times do |ii|
  # 今から計算する座標(ii)から前の座標(cc)を見て、線対称にある位置を特定している
  ll = cc - (ii-cc)

  p [ii+r[ll], cc+r[cc], ii+r[ll] < cc+r[cc]]
  byebug
  # `cc+r[cc]`は前のループで計算した計算範囲(jをインクリメントしているwhileループで、回文であることを確認した範囲)
  # 以前のループで既にチェック済みの箇所の計算を省略している
  if (ii+r[ll] < cc+r[cc])
    p [ll, cc, ii]
    byebug
    r[ii] = r[ll]
  else
    j = cc+r[cc] - ii
    while (ii-j >= 0 && ii+j < s.length && s[ii-j] == s[ii+j]) do
       j+=1
    end

    r[ii] = j
    cc = ii
  end
  p r
end

p "###"
p s.split('')
p r.map(&:to_s)

#  aabaabaaa
# _010123452
