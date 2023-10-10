package main
import "fmt"


type stack struct{
    buf []int
}

func (s *stack) push(x int){
    s.buf=append(s.buf,x)
}

func (s *stack) pop(){
    s.buf=s.buf[:len(s.buf)-1]
}

func (s *stack) top()int{
    return s.buf[len(s.buf)-1]
}

func (s *stack)empty()bool{
    if len(s.buf)==0{
        return true
    }
    return false
}


func main(){
    n:=0
    fmt.Scanf("%d",&n)
    s:=stack{}
    for ;n>0;n--{
        x:=0
        fmt.Scanf("%d",&x)
        for !s.empty()&&s.top()>=x{
            s.pop()
        }
        if s.empty(){
            fmt.Printf("-1 ");
        }else{
            fmt.Printf("%d ",s.top())
        }
        s.push(x)
    }
}