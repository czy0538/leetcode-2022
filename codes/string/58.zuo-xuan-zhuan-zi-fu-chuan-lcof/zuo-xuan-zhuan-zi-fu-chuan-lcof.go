package main


func reverseLeftWords(s string, n int) string {
	sb:=[]byte(s)
	reverse(sb,0,n)
	reverse(sb,n,len(sb))
	reverse(sb,0,len(sb))
	return string(sb)
}

func reverse(s []byte,beg,end int) {
	for i,j:=beg,end-1;i<j;{
		s[i],s[j]=s[j],s[i]
		i++
		j--
	}
}
