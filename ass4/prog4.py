def main():
	proc = int(input("Enter number of processes:\t"))
	counter = [0] * proc
	while(1):
		option = int(input("Choose your option: 1. Event at process 2. Send Message 3. Exit\n"))
	
		if option == 1:
			procno = int(input("Enter process where event took place:   "))
			if procno > proc:
				print("Invalid process number entered. Try again\n")
				continue
			counter[procno - 1] += 1
		elif option == 2:
			var1, var2 = [int(x) for x in input("Enter sender and receiver of message:  ").split()]
			if var1 > proc and var2 > proc:
				print("Invalid process number entered. Try again\n")
				continue
			counter[var1 - 1] += 1
			counter[var2 - 1] = max(counter[var2 - 1], counter[var1 - 1]) + 1
		elif option == 3:
			exit()
		else:
			print("Invalid option entered.\n")
			continue
		print("The current counter is  " + str(counter))

if __name__ == "__main__":
	main()
