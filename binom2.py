def binom2(n, k):
    memo = {}
    
    if n < 0 or k < 0:
        return 0
    if n < k:
        return 0
    
    for i in range(0, n+1):
        memo[i, 0] = 1
        memo[i, i] = 1

    for i in range(2, n+1):
            for j in range(max(1,i+k-n),min(i,k)+1):
                if i==j: continue
                memo[i, j] = memo[i-1, j] + memo[i-1, j-1]
            
    return memo[n, k]

print(binom2(15,3))
