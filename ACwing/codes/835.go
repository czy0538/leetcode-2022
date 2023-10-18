// go版本整个活，使用map去实现一个理论上支持所有字符的版本
package main

import "fmt"

type node struct {
	cnt  int
	next map[rune]*node
}

func newNode() *node {
	return &node{
		next: make(map[rune]*node),
	}
}

type trie = node

func NewTrie() *trie {
	return newNode()
}

func (t *trie) insert(s string) {
	rs := []rune(s)
	p := t
	for _, v := range rs {
		if _, ok := p.next[v]; !ok {
			p.next[v] = newNode()
		}
		p = p.next[v]
	}
	p.cnt++
}

func (t *trie) query(s string) int {
	p := t
	for _, r := range s {
		if _, ok := p.next[r]; !ok {
			return 0
		}
		p = p.next[r]
	}
	return p.cnt
}

func main() {
	n := 0
	fmt.Scanf("%d", &n)
	t := NewTrie()
	for i := 0; i < n; i++ {
		var op, s string
		fmt.Scanf("%s%s", &op, &s)
		if op == "I" {
			t.insert(s)
		} else {
			cnt := t.query(s)
			fmt.Println(cnt)
		}
	}
}
