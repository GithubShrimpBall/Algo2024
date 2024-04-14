def memoize(f):
    memo={}
    def helper(n,k):
        if(n,k) not in memo:
            memo[(n,k)]=f(n,k)
        return memo[(n,k)]
    return helper

def p(n,k):
    if k>n: return 0
    if n==k or k==1: return 1
        
    val=p(n-k,k)+p(n-1,k-1)
    return val

def result(n):
    sum=0
    for i in range(1,n+1):
        sum+=p(n,i)

    return sum
p=memoize(p)

print(result(200))
