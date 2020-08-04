'''
사이트별로 비밀번호를 만들어 주는 프로그램

입력 ) http://naver.com
규칙 - http:// 부분 제외
    - 처음 만나는 점(.) 이후 부분 제외
    - 남은 글자 중 처음 세자리 + 글자 개수 + 글자 내 'e' 개수 + "!" 로 구성
출력 ) nav51!
'''
import sys

url = input('url 입력 : ')
if url.find("http://") == 0:
    path = url[7:url.index(".")]
elif url.find("https://") == 0:
    path = url[8:url.index(".")]
else: sys.exit()    
password = path[:3] + str(len(path)) + str(path.count('e')) + '!'
print("비밀번호 : " + password)