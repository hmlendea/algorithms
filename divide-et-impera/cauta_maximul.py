def dei1_find_max(l):
# Divide and Conquer, 1 / n-1
	if len(l) == 1:
		return l[0]

	max = dei1_find_max(l[1:])

	if max > l[0]:
		return max
	else:
		return l[0]

def dei2_find_max(l):
# Divide and Conquer, n / k
	if len(l)==1:
		return l[0]

	mid = len(l) // 2
	max1 = dei2_find_max(l[:mid])
	max2 = dei2_find_max(l[mid:])

	if max1 > max2:
		return max1
	else:
		return max2

def main():
	l = []
	n = int(input("n = "))
	for i in range(n):
		l.append(int(input("l[%d] = " % i)))
	print("Divide and Conquer (1 / n-1) >> max = ", dei1_find_max(l))
	print("Divide and Conquer (n / k) >>>> max = ", dei2_find_max(l))
main()
