def genSubs(s, t="", idx=0):
2	    if (idx == len(s)):
3	        return print(t)
4	    
5	    genSubs(s, t+s[idx], idx+1)
6	    genSubs(s, t, idx+1)
7	    
8	genSubs("abc")