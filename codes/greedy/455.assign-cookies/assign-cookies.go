func findContentChildren(g []int, s []int) (sum int) {
	sort.Ints(s)
	sort.Ints(g)

	for i, j := 0, 0; i < len(g) && j < len(s); {
		for s[j] < g[i] {
			j++
			if j >= len(s) {
				return
			}
		}
		sum++
		i++
		j++
	}
	return
}
