import os, sys

def main(source):
	print("Compiling")
	os.system(f"g++ -std=c++11 -O3 -o {source}.exe {source}.cpp")
	
	print("Running")
	os.system(f"{source}.exe < in.txt > out.txt")
	
	print("Testing")
	output = []
	with open("out.txt") as file:
		output = file.read().split()

	expected = []
	with open("expected.txt") as file:
		expected = file.read().split()

	if len(output) != len(expected):
		print("Lengths are different")
		sys.exit(0)

	err = 0
	for i, val in enumerate(output):
		if output[i] != expected[i]:
			err += 1
			print(f"Line {i}:\nExpected: {expected[i]}\nOutput: {output[i]}")
			print("--------------------------------------------------------")
	print("Error rate: {:.2f}%".format(100*err/len(output)))


if __name__ == '__main__':
	main(sys.argv[1])