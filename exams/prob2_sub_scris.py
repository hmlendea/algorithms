def f(l):
# Checks if the given list contains at least one uneven number
	if l == None:
		raise ValueError()
	for e in l:
		if e % 2 == 1:
			return True
	return False

def test_f():
	assert f([1,2,3]) == True
	assert f([2,4,6]) == False
	assert f([1,3,5]) == True
	assert f([1]) == True
	assert f([2]) == False
	try:
		f(None)
		assert False
	except ValueError:
		assert True

test_f()
print("Everything's OK!")
