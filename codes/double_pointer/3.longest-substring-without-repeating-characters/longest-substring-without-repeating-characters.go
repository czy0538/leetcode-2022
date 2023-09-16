func lengthOfLongestSubstring(s string) int {
    return func()int{
        f:=make(map[rune]struct{},5e4+10)
        res:=0
        ss:=[]rune(s)
        for i,j:=0,0;i<len(ss);i++{
            for _,ok:=f[ss[i]];ok;_,ok=f[ss[i]]{
                delete(f,ss[j])
                j++
            }
            res=maxInt(i-j+1,res)
            f[ss[i]]=struct{}{}
        }
        return res
    }()



}
func maxInt(a,b int)int{
    if a<b{
        return b
    }
    return a
}