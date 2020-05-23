DAA PROJECT REPORT ON INTAL

Name: Vishnu S Reddy
SRN: PES2201800118
Class and Section: 4th semester B section Electronic City Campus 

--------------------------

What is an Intal?
Intal stands for non-negative INTeger of Arbitrary Length not exceeding 1000 digits.
The integer is stored as a null terminated string composed of ASCII characters. The integers are stored in a big endian style i.e the most significant digit is stored at the head of the string. This is like if we consider a 2 digit number, for example 39, then '3' is stored at str[0], '9' at str[1], and finally null at str[2] as it is the terminating character.

---------------------------

The Functions:

intal_add:
This function is to return the sum of two intals. Here the process we use is similar to the way we carry out addition by hand. We add digit by digit and if there is a carry i.e if the number is greater than or equal to 10, then we add the tens digit to the next digit.

intal_compare:
This function is to compare two intals. It returns 0 when both are equal and returns +1 when intal1 is greater and -1 when intal2 is greater.
First we remove any preceding zeros if they exist.
Here first we compare the length of each intal and return if either is of a different length than the other. Then if both are of the same length, then we compare character by character.

intal_diff:
This function returns the difference of two intals. It returns the absolute value i.e abs(intal1 - intal2), so it does not return a negative number.
First we make use of the previous function to compare the intals, and then based on which of these is greater, we do the difference and preceding zeros to make the numbers to be of same length for simplicity.
Then we subtract the digits from right to the left, if minuend is smaller, then 10 is added and and 1 is subtracted from the digit tothe left of the minuend.

intal_multiply:
First we compare the intals to identify which is greater, and then assign them to a or b based on that. Then we create an integer array with a size equal to the length of both the intals. Then we compute the products from right to left. Then based on the number of characters in the second intal, we left shift. All the partial products are added in the end to form the final result.

intal_mod:
This function returns intal1 mod intal2. We make use of long division method. We make use of a while loop to do this. In this we do not store the quotient, but we store only the result. finally the value of intal1 mod intal2 is stored in d1 which which the remainder by long division method.

intal_pow:
This function returns intal1 to the power n. If intal1 = 0, then we return 0. If n = 0, then we return 1. For all other values of n, we use a recursive algorithm. Suppose we have to find, 10^4, then we find, 10^2 and to find 10^2, we find 10^1. Then we multiply, 10^1 * 10^1 = 10^2, then 10^2 * 10^2 = 10^4 i.e the answer.
We make use of the multiple functions i.e intal_multiple to do the multiplications.

intal_gdc:
This function returns greatest common devisor of intal1 and intal2. If both the intals are zero, then the gcd is given to be equal to 0. We make use of euclids algorithm to make sure that we do not exceed the time limit.
The algorithm we use is:
gcd(a,b):
	if a = 0:
		return b
	gcd(b mod a, a)
We implement the same algorithm in a interative manner instead of a recursive algorithm.

intal_fibonacci:
This function returns the nth fibonacci number.
We use the same regualar logic for this. We start at 0 and 1, keep adding the previous numbers to come to the nth fibonacci number.
Algorithm:
f(0) = 0
f(1) = 1
f(n) = f(n-1) + f(n-2)

intal_factorial:
For this first we start off with 1. If n is equal to 0, we return 1. We have defined another function to aid to find the number of digits and create a char* to store the number. Then we compute the factorial by multiplying the number and subtracting 1 each time.

intal_bincoeff:
This function returns the binomial coefficient C(n,k).
We make use of Pascal's identity C(n,k) = C(n-1,k) + C(n-1,k-1) to find the binomial coefficient. We make use of the dynamic programming algorithm for better efficiency.

