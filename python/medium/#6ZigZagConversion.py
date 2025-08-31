class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        rows_array = [[] for _ in range(numRows)]

        outputStr = ""
        currentRow = 0
        direction = 1

        for char in s:
            # if only 1 row, do not attempt to traverse down/up stay on row 1
            if numRows == 1:
                rows_array[0].append(char)
                continue

            rows_array[currentRow].append(char)

            currentRow += direction

            if currentRow == numRows - 1 or currentRow == 0:
                direction *= -1


        for row in rows_array:
            outputStr += "".join(row)

        return outputStr