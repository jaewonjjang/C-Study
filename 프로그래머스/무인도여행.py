def solution(maps):
    answer = []
    cols = len(maps[0])
    rows = len(maps)
    checklist = [[False for j in range(cols)] for i in range(rows)]
    queue =[]
    for i in range(rows):
        for j in range(cols):
            result = 0
            if maps[i][j] != "X" and checklist[i][j]==False:
                queue.append([i,j])
                checklist[i][j] = True
                while len(queue):
                    pop = queue[0]
                    result = result + int(maps[pop[0]][pop[1]])
                    del queue[0]
        
                    if pop[1]+1 < cols and checklist[pop[0]][pop[1]+1]==False and maps[pop[0]][pop[1]+1] != "X":
                        queue.append([pop[0], pop[1]+1])
                        checklist[pop[0]][pop[1]+1] = True


                    if pop[1]-1 >= 0 and checklist[pop[0]][pop[1]-1]==False and maps[pop[0]][pop[1]-1] != "X":
                        queue.append([pop[0], pop[1]-1])
                        checklist[pop[0]][pop[1]-1] = True


                    if pop[0]+1 < rows and checklist[pop[0]+1][pop[1]]==False and maps[pop[0]+1][pop[1]] != "X":
                        queue.append([pop[0]+1, pop[1]])
                        checklist[pop[0]+1][pop[1]] = True


                    if pop[0]-1 >= 0 and checklist[pop[0]-1][pop[1]]==False and maps[pop[0]-1][pop[1]] != "X":
                        queue.append([pop[0]-1, pop[1]])
                        checklist[pop[0]-1][pop[1]] = True


                answer.append(result)

    
    if len(answer)==0:
        answer.append(-1)
    else :
        answer.sort()

    return answer