n, m = map(int, input().split())
s=[]
for i in range(1, n+1):
    if i%2 == 1:
        s.append('#'*m)
    else:
        if (i//2)%2 == 1:
            s.append('.'*(m-1)+'#')
        else:
            s.append('#'+'.'*(m-1))
for i in s:
    print(i)

def generate_code(n, m):
    s=[]
    for i in range(1, n+1):
        if i %2 == 1:
            s.append('#'*m)
        else:
            if (i//2)%2==1:
                s.append('.'*(m-1)+'#')
            else:
                s.append('#'+'.'*(m-1))
    return s