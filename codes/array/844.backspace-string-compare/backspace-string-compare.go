package main

func backspaceCompare(s, t string) bool {
	var iSkip, jSkip int
	i := len(s) - 1
	j := len(t) - 1
	for i >= 0 || j >= 0 {
		// 找到s的非删除字符
		for i >= 0 {
			if s[i] == '#' { //如果是#，则记录跳过字符数，并且移动
				iSkip++
				i--
			} else if iSkip > 0 { // 如果不是#，而且需要跳过字符，则跳过字符
				i --
				iSkip --
                // 这里一定不可以直接i-=iSkip,如这种情况
                //"bxj##tw"
                //"bxo#j##tw"
                // 直接跳过去将会导致o#j之间的#被跳过
			} else { // 否则，说明i指向有效字符，退出
				break
			}
		}

		// 找到t的非删除字符
		for j >= 0 {
			if t[j] == '#' { //如果是#，则记录跳过字符数，并且移动
				jSkip++
				j--
			} else if jSkip > 0 { // 如果不是#，而且需要跳过字符，则跳过字符
				j --
				jSkip --
			} else { // 否则，说明i指向有效字符，退出
				break
			}
		}

		if i >= 0 && j >= 0 { // 两者字符比较
			if s[i] != t[j] {
				return false
			}
		} else if i >= 0 || j >= 0 { // 两者有一个到头了，但另一个没有到头，仍存在可比较字符
			return false
		}
		//继续比较
		i--
		j--

	}
	return true // 两者同时退出比较，说明完全相同
}
