# https://programmers.co.kr/learn/courses/30/lessons/64061?


def solution(board, moves):
    bucket = []  # 뽑힌 인형을 담을 바구니
    answer = 0

    for move in moves:
        index = move - 1  # 실질적으로 쓰일 인덱스 값
        for row_info in board:
            if row_info[index] != 0:
                bucket.append(row_info[index])
                row_info[index] = 0
                if len(bucket) >= 2 and bucket[-1] == bucket[-2]:
                    bucket = bucket[0:-2]  # 맨 끝에 있던 2개를 제외한 배열로 다시 저장
                    answer += 2
                break
