N = gets.to_i
BALLOON = N.times.map { gets.split.map(&:to_i) }

def check(target)
  times = BALLOON.map { |h, s|
    t = target - h

    if t < 0
      -1
    else
      (t / s.to_f).floor
    end
  }.sort

  t = 0

  times.each do |x|
    return false if x < t

    t += 1
  end

  true
end

def binary_search(ok:, ng:)
  while (ok - ng).abs > 1
    mid = (ok + ng) / 2

    if yield(mid)
      ok = mid
    else
      ng = mid
    end
  end

  ok
end

puts binary_search(ok: 10 ** 19, ng: 0) { |x| check(x) }
