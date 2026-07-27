import string
from collections import Counter
import time
from concurrent.futures import ProcessPoolExecutor  


def count_letters(text):
    text = text.lower()
    letters = [c for c in text if c in string.ascii_lowercase]
    return dict(Counter(letters))

def cpu_bound_task(text):  
    text = text.lower()
    letters = [c for c in text if c in string.ascii_lowercase]
    return dict(Counter(letters))
    
def count_letters_parallel(text, chunk_size=100000):
    l = len(text) // chunk_size
    #print(l)
    tasks = []
    for t in range(0,l+1):
        tasks.append(text[chunk_size*t:chunk_size*(t+1)])
        #print(text[chunk_size*t:chunk_size*(t+1)])
    #tasks.append(text[chunk_size*l-1:])
    #print(text[chunk_size*l:] + " !")


    start_time = time.time()  

    with ProcessPoolExecutor() as executor:  
        results = executor.map(cpu_bound_task, tasks)  

    d = {}
    for i in results:
        for k,v in i.items():
            if k in d:
                d[k]+=v
            else:
                d[k] =v
    end_time = time.time()  
    #print(f"n** CPU-bound 병렬 처리(ProcessPool) 총 소요 시간: {end_time - start_time:.2f}초 **") 
    return d


if __name__ == "__main__":
    text =""
    for i in range(11):
        with open(f"texts/text_{i}.txt", "r") as f:
            text += f.read()
    
    #with open(f"texts/text_{10}.txt", "r") as f:
    #        text = f.read()
    

    print(len(text))
    start_time = time.time()
    print(count_letters(text))
    end_time = time.time()
    print(f"실행 시간: {end_time - start_time}초")
    start_time = time.time()
    print(count_letters_parallel(text))
    end_time = time.time()
    print(f"실행 시간: {end_time - start_time}초")
