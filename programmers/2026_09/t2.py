from collections import deque

def solution(tray, points):
    answer = []
    board = [list(map(int, row.split())) for row in tray]
    print(board)

    n = len(tray)
    m = 0
    for b in board[0]:
        m += b
    print(n, m )

    board_sum = [[] * m for _ in range(n)]
    for i, bx in enumerate(board):
        sum1 = 0
        for by in bx:
            sum1 += by
            board_sum[i].append(sum1)
    print(board_sum)

    for x, y in points:
        cnt = 0
        sy = 0
        if y != 0:
            sy = board_sum[x][y - 1]
        ey = board_sum[x][y]
        
        nsy = 0
        ney = 0
        for nx in range(x+1, n):
            ay = 0
            check = 0
            for i, by in enumerate(board_sum[nx]):
                print(x, nx, sy, ey, ay , by , nsy, ney)
                if (sy < by <= ey or sy <= ay < ey) or (ay < sy and ey < by):
                    print("cnt += ", board[nx][i])
                    if check == 0:
                        nsy = ay
                        ney = by
                    else :
                        ney = by
                    check = 1
                    cnt += 1
                ay = by
            sy = nsy
            ey = ney
            
        answer.append(cnt)    
        
    return answer

if __name__ == "__main__":
    tray1 = ["1 2 4", "1 1 2 3", "2 3 1 1", "1 1 2 3"]
    points1 = [[0, 1], [1, 1]]
    expected1 = [8, 3]
    result1 = solution(tray1, points1)
    
    print("Test Case 1")
    print("tray: ", tray1)
    print("points: ", points1)
    print("Result: ", result1)
    print("Expected: ", expected1)
    print("")
    
    tray2 = ["5", "2 1 2", "5"]
    points2 = [[2, 0], [0, 0]]
    expected2 = [0, 4]
    result2 = solution(tray2, points2)
    
    print("Test Case 2")
    print("tray: ", tray2)
    print("points: ", points2)
    print("Result: ", result2)
    print("Expected: ", expected2)