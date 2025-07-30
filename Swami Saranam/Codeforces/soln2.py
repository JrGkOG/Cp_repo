def fact(n):
    if n==1 or n==0:
        return 1
    return n * fact(n-1)
def fibo(n):
    if n==1 or n==0:
        return 1
    return fibo(n-2) + fibo(n-1)
print(fact(10))
print(fibo(10))







def binSer(key, arr, l=0, r=len(arr)):
    mid = l+(r-l)/2

    if (arr[mid] > key):
        return binSer(key, arr, mid+1, r)
    
    elif (arr[mid] < key):
        return binSer(key, arr, l, mid-1)
    
    elif (arr[mid] == key):
        return mid
    
    else:
        return None

a = [0, 1, 2, 3, 5, 8, 13]
binSer(5, a)

# 0 1 2 3 5 8 13 ... 