package ransomnote
func canConstruct(ransomNote string, magazine string) bool {
	dict:=make(map[rune]int)
	for _,c:=range magazine{
		dict[c]++
	}

	for _,c:=range ransomNote{
		if dict[c]==0{
			return false
		}
		dict[c]--
	}
	return true
}