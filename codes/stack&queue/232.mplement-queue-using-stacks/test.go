package main

import "fmt"
func main(){
	s:=[]int{1,2,3}
	ns:=s[:2]
	fmt.Println(&s[0])
	fmt.Println(&ns[0])
	s[0]=4
	fmt.Println(ns[0])
}