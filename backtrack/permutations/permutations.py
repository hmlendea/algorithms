# Toate permutarile de n elemente

def bt_solution_check(l, n):
	return len(l) == n

def bt_solution_found(l):
	print(l)

def bt_consistency_check(l):
	for i in range(0, len(l)):
		for j in range(i + 1, len(l)):
			if l[i] == l[j]:
				return False
	return True

def bt_recursive(l, n):
	l.append(0)
	for i in range(1, n + 1):
		l[-1] = i
		if bt_consistency_check(l):
			if bt_solution_check(l, n):
				bt_solution_found(l)
			else:
				bt_recursive(l[:], n)

def bt_iterative(n):
	l = [0]
	while len(l) > 0:
		ok = False
		while not ok and l[-1] < n:
			l[-1] += 1
			ok = bt_consistency_check(l)
		if ok:
			if bt_solution_check(l, n):
				bt_solution_found(l)
			else:
				l.append(0)
		else:
			l = l[:-1]
def main():
	# The entry point
	while True:
		print("1. Backtrack recursiv")
		print("2. Backtrack iterativ")
		print("0. EXIT")
		cmd = input("Your choice = ")

		if cmd == "0":
			print("Good bye!")
			break
		elif cmd == "1":
			print("Recursive Backtracking selected")
			n = int(input("Number of elements = "))
			bt_recursive([], n)
			break
		elif cmd == "2":
			print("Iterative Backtracking selected")
			n = int(input("Number of elements = "))
			bt_iterative(n)
			break
		else:
			print("Invalid choice! Please try again")

		print("_________________________________")
main()
