package main

import "bytes"
func reverseWords(s string) string {
	var newS bytes.Buffer
	i:=len(s)-1
	j:=i
	for i>=0{
		for i>=0&&s[i]==' '{
			i--
		}
		j=i
		for j>=0&&s[j]!=' '{
			j--;
		}
		if j<0{
			newS.WriteString(s[0:i+1])
		}else{
			newS.WriteString(s[j+1:i+1])
			newS.WriteRune(' ')
		}
        i=j-1;
	}
	rs:=newS.String()
	if rs[len(rs)-1]==' '{
		return rs[:len(rs)-1]
	}else{
		return rs
	}

}