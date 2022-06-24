#include "sfp.h"
#include <stdlib.h>

#define WORD_SIZE 16
#define FRAC_SIZE 10
#define EXP_SIZE 5
#define EXP_BIAS 15
#define NEG_INFINITY ((sfp)((0b111111) << (FRAC_SIZE)))
#define POS_INFINITY ((sfp)((0b011111) << (FRAC_SIZE)))
#define NAN ((sfp)((0b011111) << (FRAC_SIZE)) | (1))
#define NEG_ZERO ((sfp)((1) << ((EXP_SIZE) + (FRAC_SIZE))))
#define TMAX (0x7FFFFFFF)
#define TMIN (0x80000000)
#define FMAX ((float)(0x7F800000))
#define FMIN ((float)(0xFF800000))
#define LSB(bits) ((bits) & (1))
#define MSB(bits) ((bits) >> (WORD_SIZE - 1))

// The function returns sfp value correspond to given input integer
sfp int2sfp(int input){

	sfp sign = 0, exp = 0, frac = 0;

	/* If input is zero, returns +0.0 */
	if (!input)
		return (sfp)0;

	/* If MSB of input is 1 */
	if (input >> 31)
		sign = NEG_ZERO;
	
	int expn = 0;

	/* while input is zero, find the binary representation of input */
	while (input)
	{
		/* If exp exceeds 15 */
		if (expn == 16)
		{
			if (sign)
				return NEG_INFINITY;

			else
				return POS_INFINITY;
		}

		/* By dividing 2, store the value at fraction using bit operation */
		if (input % 2)
			frac = frac | (1 << expn);

		input /= 2;
		expn++;
	}

	expn--;

	/* By shifting fraction, put the decimal point in right place */
	if (expn >= FRAC_SIZE)
	{
		frac = frac >> (expn - FRAC_SIZE);
		frac = frac & (0b0000001111111111);
	}

	else
	{
		frac = frac << (FRAC_SIZE - expn);
		frac = frac & (0b0000001111111111);
	}

	expn += EXP_BIAS;
	int i = 0;

	/* Store expn to the exp at the right place  */
	while (expn)
	{
		if (expn % 2)
			exp = exp | (1 << (i + FRAC_SIZE));

		expn /= 2;
		i++;
	}

	/* Return all values by combibing all */
	return ((sign) | (exp) | (frac));
	
}

// The function returns integer value correspond to given sfp
int sfp2int(sfp input){
	/* Infinity case */
	if (input == POS_INFINITY)
		return TMAX;
	else if (input == NEG_INFINITY)
		return TMIN;

	/* Get the sign and ignore it while doing computation */
	int sign = (int)(MSB(input));
	input = input & ~(NEG_ZERO);

	/* Get the exponent */
	int exp = (int)((input >> FRAC_SIZE));
	exp -= EXP_BIAS;

	/* NAN case */
	if (exp == 16)
		return TMIN;

	/* Extract the fraction and add the leading one */
	input = input & ((sfp)0b0000001111111111);
	input = input | ((sfp)(1 << (FRAC_SIZE)));

	/* Shift the fraction to place the decimal point to the right place */
	if (exp >= FRAC_SIZE)
		input = input << (exp - FRAC_SIZE);

	else
		input = input >> (FRAC_SIZE - exp);

	/* Using casting, get the fraction value */
	int frac = (int)input;

	/* Return the value that sign is considered */
	if (sign)
		return frac * -1;

	else
		return frac;
		
}

// The function returns sfp value correspond to given input float
sfp float2sfp(float input){
	sfp sign = 0, exp = 0, frac = 0;

	/* If input is zero, return zero */
	if (!input)		return (sfp)0;

	/* If input is negative, record it and compute it ignore the sign */
	if (input < 0)
	{
		sign = NEG_ZERO;
		input = -input;
	}

	/* Divide the integer and decimal */
	int input_int = (int)input;
	float input_frac = input - (float)input_int;
	int int_zero = 0;						// flag that is integer part is zero or not

	/* If no integer part exist */
	if (!input_int)	int_zero++;

	int expn = 0;

	while (input_int)
	{
		/* If exp exceeds 15 */
		if (expn == 16)
		{
			if (sign)
				return POS_INFINITY;

			else
				return NEG_INFINITY;
		}

		if (input_int % 2)
			frac = frac | (1 << expn);

		input_int /= 2;
		expn++;
	}
	
	if (!int_zero) expn--;
	
	int i = expn;
	float pow2 = 1;							// 2^(-n)
	while (input_frac && i != 16 && expn != -15)
	{
		/* If there is no integer part, move the decimal point to negative */
		if (int_zero)	expn--;

		frac = frac << 1;
		pow2 /= 2;

		/* If remaining value is not less than 2^(-n) */
		if (input_frac >= pow2)
		{
			int_zero = 0;
			input_frac -= pow2;
			frac = frac | 1;
		}
		
		i++;
	}
	 
	/* If integer part is not zero, shift frac to put the decimal point in right place */
	if (expn >= 0)
	{
		if (i >= FRAC_SIZE)
		{
			frac = frac >> (i - FRAC_SIZE);
			frac = frac & (0b0000001111111111);
		}

		else
		{
			frac = frac << (FRAC_SIZE - i);
			frac = frac & (0b0000001111111111);
		}
	}

	/* If integer part is zero, and normalized case */
	   
	else if(expn != -15)
	{
		if (i >= FRAC_SIZE + 1)
		{
			frac = frac >> (i + expn - FRAC_SIZE);
			frac = frac & (0b0000001111111111);
		}

		else
		{
			frac = frac << (FRAC_SIZE - i - expn);
			frac = frac & (0b0000001111111111);
		}
	}

	/* Denormalized case */
	else if (!input_frac)
	{
		expn = -14;
		int cnt = 10;

		while (input_frac && cnt)
		{
			if (input_frac >= pow2)
			{
				input_frac -= pow2;
				frac = frac | (1 << (cnt - 1));

			}	
		}
	}
	
	expn += EXP_BIAS;
	i = 0;

	/* Same as int */
	while (expn)
	{
		if (expn % 2)
			exp = exp | (1 << (i + FRAC_SIZE));

		expn /= 2;
		i++;
	}
	
	return ((sign) | (exp) | (frac));
}

// The function returns float value correspond to given input sfp value
float sfp2float(sfp input){

	/* Extract the sign */
	int sign = (int)(MSB(input));
	input = input & ~(NEG_ZERO);

	/* Extract the exp */
	int exp = (int)((input >> FRAC_SIZE));
	exp -= EXP_BIAS;

	float ret;								// Value that will be return

	if (exp == 16)
	{
		ret = 1.0;
		int cnt = 128;
		while (cnt--)
			ret *= 2.0;

		if (sign)
			return -1 * ret;

		else
			return ret;
	}
	
	

	/* Denormalized case */
	if (exp == -15)
	{
		/* Use that fraction of denormalized one is 0.***** */
		input = input & ((sfp)0b0000001111111111);
		ret = input;
		
		while (++exp)
			ret /= 2;

		return ret;
	}

	/* Use that fraction of normalized one is 1.***** */
	input = input & ((sfp)0b0000001111111111);
	input = input | ((sfp)(1 << (FRAC_SIZE)));

	/* Put the fraction value to the ret */
	ret = (float)input;

	/* Calculate the exponent */
	if (exp >= FRAC_SIZE)
		while (exp-- != FRAC_SIZE)
			ret *= 2;

	else
		while (exp++ != FRAC_SIZE)
			ret /= 2;

	/* Calculate the sign */
	if (sign)
		return ret * -1;

	else
		return ret;
}

// Adds two sfp value and return it
sfp sfp_add(sfp a, sfp b){
	/* Not normal cases */
	if (a == NAN || b == NAN)
		return NAN;

	else if (a == POS_INFINITY)
	{
		if (b == NEG_INFINITY)
			return NAN;

		else
			return POS_INFINITY;
	}

	else if (a == NEG_INFINITY)
	{
		if (b == POS_INFINITY)
			return NAN;

		else
			return NEG_INFINITY;
	}

	else if (b == POS_INFINITY)
	{
		return POS_INFINITY;
	}

	else if (b == NEG_INFINITY)
	{
		return NEG_INFINITY;
	}
	
	/* Extract signs */
	int sign_a = (MSB(a));
	a = a & ~(NEG_ZERO);

	int sign_b = (MSB(b));
	b = b & ~(NEG_ZERO);

	/* Extract exponents */
	int expn_a = (int)(a >> FRAC_SIZE);
	int expn_b = (int)(b >> FRAC_SIZE);

	int dif;
	int expn;

	/* Extract fraction */

	sfp frac_a = (0b0000001111111111) & a;
	if(expn_a)							// Normalized case
		frac_a = (0b0000010000000000) | frac_a;

	sfp frac_b = (0b0000001111111111) & b;
	if (expn_b)							// Normalized case
		frac_b = (0b0000010000000000) | frac_b;

	/* To do rounding, make two extra bits. So shift two bit left */
	frac_a = frac_a << 2;
	frac_b = frac_b << 2;

	/* Compare two exponent and shift the value to match the exponent */
	if (expn_a > expn_b)
	{
		expn = expn_a;
		dif = expn_a - expn_b;

		while (dif--)
		{
			/* Shift the fraction to right */
			frac_b = frac_b >> 1;
		}

	}

	/* Opposite case */
	else if (expn_a < expn_b)
	{
		expn = expn_b;
		dif = expn_b - expn_a;

		while (dif--)
		{
			frac_a = frac_a >> 1;
		}

	}

	/* If exponents are same */
	else
		expn = expn_a;

	sfp sgn, frac, exp = 0;
	
	/* If signs are same, just add */
	if (sign_a == sign_b)
	{
		sgn = sign_a;
		frac = frac_a + frac_b;

		/* If overflow occurred */
		if (frac & (1 << (FRAC_SIZE + 3)))
		{
			frac = frac >> 1;
			expn++;
		}

	}

	/* For different signs, follow the sign of big fraction and substract it */
	else
	{
		/* If two fractions are same, added result is zero */
		if(frac_a == frac_b)
			return (sfp)0;

		else if(frac_a < frac_b)
		{
			sgn = sign_b;
			frac = frac_b - frac_a;
		}

		else
		{
			sgn = sign_a;
			frac = frac_a - frac_b;
		}

	}

	/* If both exponent and fraction are zero, added result is zero (only case when 0 + 0) */
	if (!expn && !frac) return (sfp)0;

	/* If the added result is not the form of 1.**, make this form by shifting left */
	while (!(frac & (1 << (FRAC_SIZE + 2))))
	{
		frac = frac << 1;
		expn--;
	}

	/* Do the rounding by seeking the least significant 2 bits */
	if (LSB(frac >> 1))
	{
		/* The case when last two end is '11' */
		if (LSB(frac))
			frac += 1;
		/* The case when last two end is '10' and LSB of original fraction is 1 */
		else if (LSB(frac >> 2))
			frac += 2;
	}

	/* Remove the leading one */
	frac = frac >> 2;
	frac = frac & (0b01111111111);

	int i = 0;

	/* If the exponent is overflowed, return infinity */
	if (expn >= 31)
	{
		if (sgn)
			return NEG_INFINITY;

		else
			return POS_INFINITY;
	}

	/* Store the exponent */
	while (expn)
	{
		if (expn % 2)
			exp = exp | (1 << (i + FRAC_SIZE));

		expn /= 2;
		i++;
	}

	/* Store the sign */
	if (sgn)	sgn = NEG_ZERO;

	return ((sgn) | (exp) | (frac));
}

// Print the spf value to its bits
char* sfp2bits(sfp result){
	char* bits = (char*)malloc(sizeof(char)*(WORD_SIZE + 1));

	for (int i = 0; i < WORD_SIZE; i++)
	{
		if (LSB(result))
			bits[WORD_SIZE - 1 - i] = '1';

		else
			bits[WORD_SIZE - 1 - i] = '0';

		result = result >> 1;
	}

	bits[WORD_SIZE] = '\0';					// To mark the end of string
	return bits;
}

