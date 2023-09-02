#cau1 

def Make_matrix(n):
	return [[0]*n for i in range(n)]

def Set_matrix(matrix):
	n = len(matrix)
	for i in range(n):
		for j in range(n):
			element = int(input())
			matrix[i][j] =element

def Go(i,x,y,n):
	if x>=0 and y>=0 and x<n and y<n:
		if i ==0:
			x+= 1
			if x >=n:
				x-=1
		elif i == 1:
			x-= 1
			if x <0:
				x+=1
		elif i == 2:
			y+= 1
			if y >=n:
				y-=1
		else:
			y-= 1
			if y <0:
				y+=1
	return x,y

def Step(x,y,x0,y0,n,s,matrix,matrix_I):
	for i in range(4):
		k = Go(i,x,y,n)
		a,b = k[0],k[1]
		if a== x and b==y:
			continue
		if a == x0 and b ==y0:
			pass
		else:
			Min = matrix[a][b]
			a0,b0 = a,b
	for i in range(4):
		k = Go(i,x,y,n)
		a,b = k[0],k[1]
		if a== x and b==y:
			continue
		if a == x0 and b ==y0:
			continue
		if matrix_I[a][b] == 1:
			continue
		if a<n and b<n:
			if Min > matrix[a][b]:
				Min = matrix[a][b]
				a0,b0 = a,b
		if a==n-1 and b == n-1:
			a0,b0 = a,b
			s.append(matrix[a0][b0])
			print(s)
			return s
	s.append(matrix[a0][b0])
	matrix_I[a0][b0] = 1
	Step(a0,b0,x,y,n,s,matrix,matrix_I)




v = []
n = int(input("Nhap n= "))
A = Make_matrix(n)
Set_matrix(A)
s = [A[0][0]]
I = Make_matrix(n)
Step(0,0,-2,-2,n,s,A,I)
# for i in range(4):
# 	print(Go(i,2,0,3))




#cau2:
def Sum(b):
	s=0
	for i in range(len(b)):
		s+= b[i]
	return s-b[0]

def Max(a,b):
	return a if a>b else b

n = int(input("So thiet bi: "))
m = int(input("Nhap so cong viec: "))
w = [0 for i in range(m)]
a = [[0]*(m+1) for i in range(n)]
for i in range(m):
	w[i] = int(input("Thoi gian cong viec "))

w1 = sorted(w,reverse=True)

for i in range(m):
	Min = Sum(a[0])
	k=0
	for j in range(n):
		if Min > Sum(a[j]):
			Min = Sum(a[j])
			k = j
	a[k][i+1] = w1[i]
b = a[0]
l=0
for i in range(n):
	if b>Max(b,a[i]):	
		b = Max(b,a[i])
		l =i
	print(a[i][1:])

print("Thoi gian ngan nhat: ", Sum(a[l]))
