package main

import "fmt"

type Ordered interface {
    Integer | Float | ~string
}

type Integer interface {
    Signed | Unsigned
}

type Signed interface {
    ~int | ~int8 | ~int16 | ~int32 | ~int64
}

type Unsigned interface {
    ~uint | ~uint8 | ~uint16 | ~uint32 | ~uint64 | ~uintptr
}

type Float interface {
    ~float32 | ~float64
}

func reverse(s []rune, beg, end int) {
	for i,j:=beg,end-1;i<j;{
		s[i],s[j]=s[j],s[i]
		i++
		j--
	}
}

func min[T Ordered](a,b T)T{
	if a<b{
		return a
	}
	return b
}

func reverseStr(s string, k int) string {
	ss := []rune(s)
	for i := 0; i < len(ss); i += k * 2 {
		t:=min(i+k,len(ss))
		reverse(ss,i,t)
	}
	return string(ss)
}

func main(){
	s:="abcd"
	k:=2
	fmt.Println(reverseStr(s,k))
}