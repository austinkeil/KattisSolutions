a = [1, 1]
for n in range(2, 100):
	a.append(a[n-1] + a[n-2])
	print(a)
# for n in range(0, 100):
# 	print(a[n])