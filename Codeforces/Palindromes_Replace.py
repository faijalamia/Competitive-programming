s = input()
s = list(s)
n = len(s)
for i in range(n//2):
    if s[i]=='?':
        s[i]=s[n-1-i];
    if s[n-1-i]=='?':
        s[n-1-i]=s[i]

for i in range(n):
    if s[i]=='?':
        s[i]='a'
        
s = "".join(s)
s1 = s[::-1]

if s==s1:
    print(s)
else:
    print(-1)
