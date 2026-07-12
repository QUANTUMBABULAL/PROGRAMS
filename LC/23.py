class Solution:
    def setZeroes(self, matrix):
        rows = len(matrix)
        cols = len(matrix[0])

        firstRow = False
        firstCol = False

        # Check first row
        for j in range(cols):
            if matrix[0][j] == 0:
                firstRow = True
                break

        # Check first column
        for i in range(rows):
            if matrix[i][0] == 0:
                firstCol = True
                break

        # Use first row and column as markers
        for i in range(1, rows):
            for j in range(1, cols):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0

        # Zero rows
        for i in range(1, rows):
            if matrix[i][0] == 0:
                for j in range(1, cols):
                    matrix[i][j] = 0

        # Zero columns
        for j in range(1, cols):
            if matrix[0][j] == 0:
                for i in range(1, rows):
                    matrix[i][j] = 0

        # Zero first row
        if firstRow:
            for j in range(cols):
                matrix[0][j] = 0

        # Zero first column
        if firstCol:
            for i in range(rows):
                matrix[i][0] = 0