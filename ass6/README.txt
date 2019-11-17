So, banker's algorithm can be used for deadlock prevention

So, in this algorithm the number of processes running, the number of resources used, the total number of instances used in every resource,
the available resources vector, the maximum claim vector are all fed as the inputs
Apart from that the needs of the process is also specified.
The output is whether the requested need might land the system in a deadlock or not.

The algorithm goes as follows :

1) Let Work and Finish be vectors of length ‘m’ and ‘n’ respectively.
    Initialize: Work = Available
    Finish[i] = false; for i=1, 2, 3, 4….n

2) Find an i such that both
    a) Finish[i] = false
    b) Needi <= Work
    if no such i exists goto step (4)

3) Work = Work + Allocation[i]
    Finish[i] = true
    goto step (2)

4) if Finish [i] = true for all i
    then the system is not in deadlock state

Details of all files :

deadlock_prevention.c - the main c file which consists the program for the aforementioned algorithm
input.png - has the input given to the program where process 2 requests for an instance of resource 3, which can be granted easily as it is not held by any of the other processes, which essentially shouldn't result in a deadlock
output.png - has the output of the given program, which says that the processes are not in deadlock state after the aforementioned  output is given
WFG1.png - has the wait for graph for the input given to the program as specified in input.png, as one can see no cycles are formed, indicating that no deadlock exists after the instances requested by the process are allotted to it
deadlock_prevention_example.png - input and output where the system is in deadlock state after process 1 requests for a particular set of resources
WFG2.png - has the wait for graph for the input given to the program as specified in deadlock_prevention_example.png, as one can see cycle is formed between processes x and y, hence, deadlock exists. So, prevent deadlock by not allotting the resources to the process 
