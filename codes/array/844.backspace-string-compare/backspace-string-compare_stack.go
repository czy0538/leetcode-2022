package main
type stack struct{
	value []rune
	size int
}

func (s *stack) Push(t rune){
	s.size++
	s.value=append(s.value, t)
}

func (s *stack) Pop()(rune, bool){
	if s.size==0{
		return 0,false
	}
	s.size--
	t:=s.value[s.size]
	s.value=s.value[:s.size]
	return t,true
}

func backspaceCompare(s string, t string) bool {
	var ss,ts stack
	for _,i:=range s{
		if i=='#'{
			ss.Pop()
		}else{
			ss.Push(i)
		}
	}
	for _,i:=range t{
		if i=='#'{
			ts.Pop()
		}else{
			ts.Push(i)
		}
	}

	if ss.size!=ts.size{
		return false
	}

	for (ss.size>0){
		st,_:=ss.Pop()
		tt,_:=ts.Pop()
		if st!=tt{
			return false
		}
	}
	return true

}