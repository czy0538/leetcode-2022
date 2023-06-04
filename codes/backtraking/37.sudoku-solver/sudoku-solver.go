package sudoku

type Position struct {
	Row int
	Col int
}

func (pos Position) Next() Position {
	pos.Col++
	if pos.Col == 9 {
		pos.Row++
		pos.Col = 0
	}
	return pos
}

func solveSudoku(board [][]byte) {
	isValid := func(pos Position, val byte) bool {
		for i := 0; i < 9; i++ {
			if board[i][pos.Col] == val || board[pos.Row][i] == val {
				return false
			}
		}
		startRow := pos.Row / 3 * 3
		startCol := pos.Col / 3 * 3
		for i := startRow; i < startRow+3; i++ {
			for j := startCol; j < startCol+3; j++ {
				if board[i][j] == val {
					return false
				}
			}
		}
		return true
	}

	var backtracing func(Position) bool

	backtracing = func(pos Position) bool {
		for ; pos.Row < 9; pos = pos.Next() {
			if board[pos.Row][pos.Col] != '.' {
				continue
			}
			for k := '1'; k <= '9'; k++ {
				if isValid(pos, byte(k)) {
					board[pos.Row][pos.Col] = byte(k)
					if backtracing(pos.Next()) {
						return true
					}
					board[pos.Row][pos.Col] = '.'
				}
			}
			return false
		}
		return true
	}

	backtracing(Position{0, 0})
}
