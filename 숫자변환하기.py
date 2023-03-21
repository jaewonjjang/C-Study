def solution(x, y, n):
    q = [];
    
    q.append([y, 0]);
    
    while len(q) :
        pop = q[0][0]
        calNum = q[0][1]
        del q[0]
        
        if pop==x:
            return calNum
        
        for i in range(0,3) :
            if i==0 and pop-n >= x :
                q.append([pop-n, calNum+1])
            elif i==1 and pop%2==0 and pop/2>= x :
                q.append([pop/2, calNum+1]);
            elif i==2 and pop%3==0 and pop/3 >= x :
                q.append([pop/3, calNum+1]);

    return -1;