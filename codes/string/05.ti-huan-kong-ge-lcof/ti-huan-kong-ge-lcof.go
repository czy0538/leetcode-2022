package main

import (
	"bytes"

)
func replaceSpace(s string) string {
	var newS bytes.Buffer
	for _,c:= range s{
		if c==' '{
			newS.WriteString("%20")
		}else{
			newS.WriteRune(c)
		}
	}
	return newS.String()
}