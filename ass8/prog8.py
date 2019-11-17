import random
import collections
def main():
	servers = int(input("Enter number of servers         "))
	rq, wq = [int(x) for x in input("Enter read and write quorum    ").split()]
	if rq + wq <= servers or wq <= servers // 2:
		print("Read write and write write conflicts may occur. Adjust quorum values to specifications and try again.")
		exit()
	versions = [0] * servers
	for i in range(servers):
		versions[i] = random.randint(0, 1)		
	ver = 0
	while True:
		option = int(input("Choose your option: 1. Read file 2. Write file 3. Print Versions List 4. Exit\t"))
		if option == 1:
			count = 0
			latest = []
			for i in range(servers):
				#num = random.randint(0, 100)
				#print("num is   " + str(num))
				#if num > 20:
				if versions[i] > ver:
					ver = versions[i]
					latest = []
					latest.append(i)
				elif versions[i] == ver:
					latest.append(i)
				if i >= rq:
					break
			print(latest)								
		elif option == 2:
			count = 0
			latest = []
			#for i in range(servers):
			#num = random.randint(0, 100)
			#	print("num is    " + str(num))
			#	#if num > 20:
			#	#count += 1
			freq = collections.Counter(versions)		
			#print(freq)	
			maximum = 0
			num1 = freq.most_common()[0][0]
			print(num1)
			num2 = freq.most_common()[0][1]
			print(num2)
			for i in range(servers):
				if versions[i] == num1:
					latest.append(i)
					versions[i] += 1
			print(latest)			
		elif option == 3:
			print(versions)
		elif option == 4:
			exit()	
		else:
			print("Invalid option entered\n")
			continue


if __name__ == "__main__":
	main()
