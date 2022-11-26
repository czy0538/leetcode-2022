package main
// 能够处理unicode的版本
func isAnagram(s string, t string) bool {
	dict:=make(map[rune]int)
	if len(s)!=len(t){
		return false
	}
	for _,r:= range s{
		dict[r]++
	}

	for _,r:= range t{
		dict[r]--
		if dict[r]<0{
			return false;
		}
	}
	return true
}