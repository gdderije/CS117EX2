# Floating Point Conversion to Binary and Decimal

binary64.hpp Calculates the IEEE 754 standard 64-bit binary floating-point representation of a real number

Fixed-Point and FLoating-Point Representations

Assume that we have N memory positions to store a given number. One way to store
numbers is to use 1 position on the sign s, k positions for digits after the point, and
N − k − 1 positions before the point. This leads us to the following fixed-point number
system

![image](https://github.com/gdderije/Floating-Point-Conversion-to-Binary-and-Decimal/assets/71222985/5401053a-8909-45b0-a6be-b77b8d291447)

For binary positional representations, a memory position corresponds precisely to a bit,
that is, either, 0 or 1.

Proposition 0.3.4 Given a positive integer k, we have |FI(β, N, k)| = 2β^(N−1) − 1,

![image](https://github.com/gdderije/Floating-Point-Conversion-to-Binary-and-Decimal/assets/71222985/f19eca72-1c31-4718-951a-517289244dba)

To circumvent the limitations of fixed-point number systems, one may do scaling. For
this, let us introduce the normalized floating-point number system

![image](https://github.com/gdderije/Floating-Point-Conversion-to-Binary-and-Decimal/assets/71222985/bc8f7eb8-b499-4b63-9274-71df82a3e7cc)

where e_min < 0 < e_max are elements of Z_(β,N−p−2). Here, p + 1 is the number of significant
digits, e the exponent and m = x_0.x_1 · · · x_p is the mantissa. The condition x_0 != 0 is
called the normalization condition.

Note that the exponent e can be stored in N − p − 2 positions, hence we used a total
number of (N − p − 2) + (p + 1) + 1 = N positions for the storage of exponent, mantissa
and the sign.

For the complete floating-point number system, we have

![image](https://github.com/gdderije/Floating-Point-Conversion-to-Binary-and-Decimal/assets/71222985/a842914f-0d27-4680-9891-9b8f321112f3)

If a certain arithmetic operation leads to a result for which |x| > x_max, then we say
that we have overflow. On the other hand, if |x| < x_min then we say that we have an
underflow occurs (or graceful underflow in the presence of de-normalized numbers). In
the first situation, an error message will be returned or the value is set to a special
number, called “infinity”. For the second one, the result is either set to zero or we have
an error message.

Example: There are several IEEE^8 standards, however, we only discuss the IEEE
754 for floating-point computation developed in 1987. On a typical computer, there are
two floating-point formats, namely the single and double precision. In the language of
C/C++, these correspond to the data types float and double, respectively.

![image](https://github.com/gdderije/Floating-Point-Conversion-to-Binary-and-Decimal/assets/71222985/e6e324b7-f6a2-4d94-9253-1c976fa3bb79)

The IEEE 754 single precision format is the floating-point number system

![image](https://github.com/gdderije/Floating-Point-Conversion-to-Binary-and-Decimal/assets/71222985/415f110e-adff-4256-bea2-d9c197679316)

while for the double precision format we have

![image](https://github.com/gdderije/Floating-Point-Conversion-to-Binary-and-Decimal/assets/71222985/bf5e8b9e-f0f4-4772-8bfe-254329012b92)

Observe that −126, 127 ∈ Z_(2,7) and −1022, 1023 ∈ Z_(2,10) (since 7 = 32 − 23 − 2 and 10 = 64 − 52 − 2).


![image](https://github.com/gdderije/Floating-Point-Conversion-to-Binary-and-Decimal/assets/71222985/ff67ca26-7928-4af0-9fe2-d9c314e18a70)


![image](https://github.com/gdderije/Floating-Point-Conversion-to-Binary-and-Decimal/assets/71222985/dc60fea8-6d38-4605-bde6-46b127a6a87d)

The IEEE 754 standard uses different storage mechanisms for the mantissa and the sign. Note that for normalized binary floating-point numbers, the normalization conditions x_0 != 0 is equivalent to x_0 = 1. Therefore, the bit x_0 is not stored, and it is called the hidden bit. In this case, the storage of the mantissa is precisely equal to 23 bits for
single precision and 52 bits for double precision. 

For the exponent, instead of storing the binary representation of e, it is converted to an unsigned integer E = e + e_max, called the biased exponent, and is the one being stored. Then 1 ≤ E ≤ 2e_max, and E is stored in 8 bits for single precision and 11 bits for double precision. The extra bit is compensated from the hidden bit. This is advantageous when
comparing nonnegative floating-point numbers as if they are integers. In summary, a normalized binary floating-point number is represented by

![image](https://github.com/gdderije/Floating-Point-Conversion-to-Binary-and-Decimal/assets/71222985/e4a246ce-1cbf-42a9-9207-a6f0c0c4ea1c)

These are also adapted in the case of de-normalized numbers.

The IEEE 754 also contains codings for some exceptional cases of the exponents: the
signed zero −0, infinities ±∞ and NaNs (stands fo Not a Number)10. This is to handle
computations that lead to overflow or underflow, and as well as the computation of
expressions such as 0/0, x/0 for x != 0, log 0 and √−1.

![image](https://github.com/gdderije/Floating-Point-Conversion-to-Binary-and-Decimal/assets/71222985/809da948-6b7c-49e1-ab98-06d8a8238d05)
