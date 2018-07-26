#include <stdio.h>
#include <stdint.h>

#define BIT_MASK_MAKER(n) bitMaskValue##n = n

void print_binary(uint8_t value);

int main(void)
{
	uint8_t BIT_MASK_MAKER(1);
	uint8_t BIT_MASK_MAKER(2);
	uint8_t BIT_MASK_MAKER(4);
	uint8_t BIT_MASK_MAKER(8);
	uint8_t BIT_MASK_MAKER(16);
	uint8_t BIT_MASK_MAKER(32);
	uint8_t BIT_MASK_MAKER(64);
	uint8_t BIT_MASK_MAKER(128);

	print_binary(bitMaskValue1);
	print_binary(bitMaskValue2);
	print_binary(bitMaskValue4);
	print_binary(bitMaskValue8);
	print_binary(bitMaskValue16);
	print_binary(bitMaskValue32);
	print_binary(bitMaskValue64);
	print_binary(bitMaskValue128);

	return 0;
}

void print_binary(uint8_t value)
{
	int i = 0;
	uint8_t bitMask = 128;

	for (i = 0; i < 8; i++)
	{
		if (value & bitMask)
		{
			printf("%d", 1);
		}
		else
		{
			printf("%d", 0);
		}
		bitMask = bitMask >> 1;
	}
	putchar(10);

	return;
}
