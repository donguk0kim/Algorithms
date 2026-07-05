# Bit Manipulation

## XOR Operations

representation of 1 using 3 bits is 001  
representation of 2 using 3 bits is 010  
representation of 3 using 3 bits is 011  

001 XOR 010 is 011  
001  ^  010 is 011  
1    ^   2  is 3

001 XOR 011 is 010  
001  ^  011 is 010  
1    ^   3  is 2

The amount is bits used to represent numbers in a computer depends on the computer (32 bit, 64 bit)


## 

[1,2,3] ^ [1,2]

01		1  
10		2
___  
11		3*  
11		3
___  
00		0*  
10		1
___  
10		1*  
01		2
___  
11		3

So the missing element is 3
Using this unique element finder using XOR only used 2 bits.