def dei_maximum(l):
	if len(l) == 1:
		return l[0]

	max = dei_count_even_numbers(l[1:])

	if max > l[0]:
		return max
	else:
		return l[0]

def dei_count_even_numbers2(l):
	if len(l) is 1:
		if l[0] % 2 is 0:
			return 1
		else:
			return 0

	even = dei_count_even_numbers(l[1:])
	if even is not 0:
		return even + 1
	else:
		return even

def dei_count_even_numbers(l):
	if len(l) is 1:
		if l[0] % 2 is 0:
			return 1
		else:
			return 0

	mid = len(l) // 2
	evens_left = dei_count_even_numbers(l[:mid])
	evens_right = dei_count_even_numbers(l[mid:])
	
	return evens_left + evens_right

def main():
	l = []
	n = int(input("Number of elements = "))
	for i in range(n):
		l.append(int(input("l[%d] = " % i)))
	m = dei_count_even_numbers(l)
	print("The given list contains %d even numbers." % m)
main()
