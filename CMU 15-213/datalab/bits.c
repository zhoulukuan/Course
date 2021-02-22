/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
	Replace the "return" statement in each function with one
	or more lines of C code that implements the function. Your code 
	must conform to the following style:
 
	int Funct(arg1, arg2, ...) {
			/* brief description of how your implementation works */
			int var1 = Expr1;
			...
			int varM = ExprM;

			varJ = ExprJ;
			...
			varN = ExprN;
			return ExprR;
	}

	Each "Expr" is an expression using ONLY the following:
	1. Integer constants 0 through 255 (0xFF), inclusive. You are
			not allowed to use big constants such as 0xffffffff.
	2. Function arguments and local variables (no global variables).
	3. Unary integer operations ! ~
	4. Binary integer operations & ^ | + << >>
		
	Some of the problems restrict the set of allowed operators even further.
	Each "Expr" may consist of multiple operators. You are not restricted to
	one operator per line.

	You are expressly forbidden to:
	1. Use any control constructs such as if, do, while, for, switch, etc.
	2. Define or use any macros.
	3. Define any additional functions in this file.
	4. Call any functions.
	5. Use any other operations, such as &&, ||, -, or ?:
	6. Use any form of casting.
	7. Use any data type other than int.  This implies that you
		 cannot use arrays, structs, or unions.

 
	You may assume that your machine:
	1. Uses 2s complement, 32-bit representations of integers.
	2. Performs right shifts arithmetically.
	3. Has unpredictable behavior when shifting if the shift amount
		 is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
	/*
	 * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
	 */
	int pow2plus1(int x) {
		 /* exploit ability of shifts to compute powers of 2 */
		 return (1 << x) + 1;
	}

	/*
	 * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
	 */
	int pow2plus4(int x) {
		 /* exploit ability of shifts to compute powers of 2 */
		 int result = (1 << x);
		 result += 4;
		 return result;
	}

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
	1. Define or use any macros.
	2. Define any additional functions in this file.
	3. Call any functions.
	4. Use any form of casting.
	5. Use any data type other than int or unsigned.  This means that you
		 cannot use arrays, structs, or unions.
	6. Use any floating point data types, operations, or constants.


NOTES:
	1. Use the dlc (data lab checker) compiler (described in the handout) to 
		 check the legality of your solutions.
	2. Each function has a maximum number of operations (integer, logical,
		 or comparison) that you are allowed to use for your implementation
		 of the function.  The max operator count is checked by dlc.
		 Note that assignment ('=') is not counted; you may use as many of
		 these as you want without penalty.
	3. Use the btest test harness to check your functions for correctness.
	4. Use the BDD checker to formally verify your functions
	5. The maximum number of ops for each function is given in the
		 header comment for each function. If there are any inconsistencies 
		 between the maximum ops in the writeup and in this file, consider
		 this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
	int mask_11 = (~x) & (~y);
	int ans = ~(x & y) & (~mask_11);
	return ans;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
	return 1 << 31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
	int y = x + 1;
	x = x ^ y;
	x = !(~x); // z=1可以确定x,y为(tmax,tmin)或者(-1,0)之一
	return x & (!!y); // !!y在上述情况下为1和0
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
	int m = 0xAA;
	m = (m << 8) + 0xAA;
	m = (m << 8) + 0xAA;
	m = (m << 8) + 0xAA;
	return !(m^(m & x));
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
	return (~x) + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
	int sign1 = (x >> 31) & 1; // x的符号位
	int y = (~x) + 1 + 0x39;
	int sign2 = (y >> 31) & 1; // 0x39-x的符号位
	int z = (~0x30) + 1 + x;
	int sign3 = (z >> 31) & 1; // x-0x30的符号位
	return !(sign1 | sign2 | sign3);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
	x = ~(!!x) + 1; // x为1/0,使用小技巧取~+1后可以变成11...111/00...000
	return (x & y)|(~x & z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
	int sx = x >> 31;
	int sy = y >> 31;
	int same = !!(sx ^ sy); // 符号相同为零,否则为1
	int sum = (~x) + 1 + y;
	int ss = sum >> 31 & 1; // y-x的符号位
	return (same & (sx & 1)) | // 符号不同则x必须为负
					(!same & !ss); // 符号相同y-x>=0
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
	int y = x | (~x+1); 
	// a|-a后,a从尾巴开始往前找到第1个1,该位置及之前所有位都会变成1
	// 因此若x不为0,y的符号位一定是1,当且仅当x为0即不包含任何1的时候,y的符号位是0
	return (y >> 31) + 1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5    1100
 *            howManyBits(298) = 10  100021010
 *            howManyBits(-5) = 4    1011
 *            howManyBits(0)  = 1    0
 *            howManyBits(-1) = 1    1
 *            howManyBits(0x80000000) = 32  
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
	int b16, b8, b4, b2, b1;
	int sign = x >> 31;
	x = (sign & (~x)) | (~sign & x);

	b16 = !!(x >> 16) << 4;  // x的高16位是否有1,有则为1否则为0,左移4位后得到b16的值为16/0
	x = x >> b16;  // b16为16,高位有1,则右移16位在高16位中继续找;否则x不需要右移，高16位都是0，直接在低16位中找
	b8 = !!(x >> 8) << 3; 
	x = x >> b8;
	b4 = !!(x >> 4) << 2;
	x = x >> b4;
	b2 = !!(x >> 2) << 1;
	x = x >> b2;   
	b1 = x >> 1;  // x >> 1仅剩下1位,因此不需要再进行!!等操作 
	x = x >> b1;
	return x + b1 + b2 + b4 + b8 + b16 + 1;   // x可能是1,比如0x3ff...f的情况,因此也要加进来
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
	unsigned exp = (0x7f800000 & uf) >> 23;
	unsigned frac = 0x007fffff & uf; 
	if (exp == 255) { // 异常值段,直接返回
		return uf;
	} else if (exp == 0) {  // d段
		return (uf & 0x80000000) + (frac << 1);
	} else { // n段,frac不变,exp直接加1
		exp += 1;
		return (uf & 0x807fffff) + (exp << 23);
	}
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
	unsigned sign = (uf >> 31) & 1;
	int exp = (0x7f800000 & uf) >> 23;
	unsigned frac = 0x007fffff & uf; 
	if (exp == 0) {
		return 0;	// (int) f是截断操作,d段可以直接得到0
	} else if (exp == 255) {
		return 0x80000000; // 异常值直接视作溢出
	} else {
		exp -= 127;
		if (exp > 31 || (exp == 31 && !(frac == 0 && sign == 1))) return 0x80000000; // 超过2**31-1以及-2**31则溢出
		if (exp < 0) return 0;  // 1.XX的负次幂必然小于1，截断操作为0
		frac = (1 << 23) + frac; // frac补充忽略的1然后进行位移操作
		if (23 - exp >= 0) { 
			frac = frac >> (23 - exp);
		} else {
			frac = frac << (exp - 23);
		}
		if (sign == 1) {  // 负号则需要取反
			frac = (~frac) + 1;
		}
		return frac;
	}
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
	if (x < -149) {		// 浮点数最小表示为2^(-23)*2^(1-127),超过则太小直接返回0
		return 0;
	} else if (x > 127) {	// 浮点数最小表示为2^(254-127),太大溢出
		return 0x7f800000;
	} else if (x >= -149 && x <= -127) { 	// d段
		x += 126;
		return 1 << (23 + x);
	} else {	// n段
		x += 127;
		return x << 23;
	}
}
