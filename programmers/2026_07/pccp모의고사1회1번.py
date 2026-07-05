def solution(input_string):
    answer = ''
    alpha = [0] * 26
    pre = input_string[0]

    for s in input_string:
        if pre != s :
            alpha[ord(pre)- ord('a')] += 1
        pre = s

    alpha[ord(input_string[-1]) - ord('a')] +=1

    for i,a in enumerate(alpha):
        if a >=2:
            answer+=chr(i+ord('a'))

    if answer == '':
        return "N"
    return answer