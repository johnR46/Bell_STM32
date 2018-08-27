#include <stdio.h>
#include <string.h>

char text[4096]; //
char dest[40];   // test
#define line 96
#define LineSize_ 40
char Buffer[line][LineSize_];

void convert_textto_buffer(char *str)
{
	int count = 0;
	int Line = 0;
	int Size_ = 0;
	while (*str != '\0')
	{
		count++;
		str++;
		if (*str == '\r')
		{
			Buffer[Line][Size_] = '\r';
			Size_++;
			Buffer[Line][Size_] = '\n';
			str++;
			Line++;
			Size_ = 0;
			count = 0;
		}
		if (Line == line)
		{
			break;
		}
		if (Size_ == LineSize_)
		{
			Line++;
			Size_ = 0;
		}
		if (count != Size_)
		{
			Buffer[Line][Size_] = *str;
			Size_++;
		}
	}
}

void main()
{

	strcpy(text, "\r\n\r\nbbbbbbbbffffffffffffffffffffffffffffpppppppppppppppppppppppppfffffffffffffffffbbbbbbbbbbbbb\r\nccccccccccc\r\n\r\n\r\nTEST\r\ngg");

	convert_textto_buffer(text);

	printf("%s", Buffer[0]); // �aaaaaaaaaaaaaaaaaaaaaaaaa�
	printf("%s", Buffer[1]); // �bbbbbbbbbbbbbbbbbbbbb�
	printf("%s", Buffer[2]); // �ccccccccccc�
	printf("%s", Buffer[3]); // ""
	printf("%s", Buffer[4]); // ""
	printf("%s", Buffer[5]); //�TEST�
	printf("%s", Buffer[6]); //�TEST�
}
