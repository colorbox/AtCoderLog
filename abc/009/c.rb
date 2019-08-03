n,k  =gets.strip.split.map(&:to_i)
s = gets.strip

sorted = s.split('').sort


def diff(arr1, arr2)
  duped = arr2.dup
  arr1.each do |c|
    target_index = duped.index(c)
    duped.delete_at(target_index) if target_index
  end
  duped.length
end

result = []
n.times do |index|
  current_origin = s.split('')[index..-1]

  of = current_origin.shift

  sorted.each do |c|
    d = 0
    d+=1 if of!=c
    current_sorted = sorted.dup
    current_sorted.delete_at(current_sorted.index(c))

    d += diff(current_origin, current_sorted)

    if d<= k
      result.push(c)
      sorted.delete_at(sorted.index(c))
      k-=1 if c!= of
      break
    end

# sorted要素を次々に見ていき、許容に収まる要素を探す。
# 許容に収まるとは、対象のsorted要素がorigin先頭と等しくなければ+1、対象要素を抜いたsortedと戦闘要素を抜いたoriginalのdiffをさらに足して許容量kを超えないかで判定
# 今から突っ込む要素によって発生するdiffと突っ込む要素を取り除いたあとに発生するdiffとの合計が許容量を超えてはいけない

  end
end

puts result.join('')
