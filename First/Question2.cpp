#include <iostream>

char * toupper(char * ch);
char * tolower(char * ch);
int isspace(const char * ch);
char * strncpy (char * dest, const char * src, int n);
int strcmp (const char * cstr1, const char * cstr2);
char * strncat (char * dest, const char * src, int n);
char * strstr (char * cstr1, char * cstr2);
char * strtok (char * cstr, const char * delim);


int main()
{	
	// Inputted arrays
	char arr[100] = "hello bro"; // for first 2 functions

	const char array[100] = "\t"; // for 3rd function

	const char one[100] = "amogus"; // for 4th function and 6th function
	char two[100] = "sus"; // for 4th function and 6th function

	const char three[100] = "brother"; // for 5th function
	const char four[100] = "brothef"; // for 5th function

	char five[100] = "amogsushaha"; // for 7th function
	char six[100] = "sus"; // for 7th function

	char seven[100] = "hello world"; // for 8th function


	// Function callings
	std::cout << toupper(arr);
	std::cout << tolower(arr);
	std::cout << std::endl << std::endl;

	std::cout << isspace(array);
	std::cout << std::endl << std::endl;

	std::cout << strncpy(two, one, 4);
	std::cout << std::endl << std::endl;

	std::cout << strcmp(three, four);
	std::cout << std::endl << std::endl;

	std::cout << strncat(two, one, 7);
	std::cout << std::endl << std::endl;

	std::cout << strstr(five, six);
	std::cout << std::endl << std::endl;

	std::cout << strtok(seven, "o");
	std::cout << std::endl << std::endl;

	return 0;
}

char * toupper(char * ch)
{
	int counter = 0;
	int i = 0;
	while (1)
	{
		if (*(ch + i) != '\0')
		{
			counter++;
			i++;
		}
		else
		{
			break;
		}
	}
	for (int i = 0; i < counter; i++)
	{
		if (*(ch + i) == ' ')
		{
			continue;
		}

		*(ch + i) -= 32; // making them big letter
	}


	return ch;
}

char * tolower(char * ch)
{
	int counter = 0;
	int i = 0;
	while (1)
	{
		if (*(ch + i) != '\0')
		{
			counter++;
			i++;
		}
		else
		{
			break;
		}
	}
	for (int i = 0; i < counter; i++)
	{
		if (*(ch + i) == ' ')
		{
			continue;
		}

		*(ch + i) += 32; // making them big letter
	}

	std::cout << counter;

	return ch;
}

int isspace(const char * ch)
{
	if (*(ch) == ' ' || *(ch) == '\r' || *(ch) == '\n' || *(ch) == '\t' || *(ch) == '\f' || *(ch) == '\v')
	{
		return 1;
	}
	else 
		return 0;
}

char * strncpy (char * dest, const char * src, int n)
{
	int counter_src = 0;
	int counter_dest = 0;
	int i = 0;
	while (1)
	{
		if (*(src + i) != '\0')
		{
			counter_src++;
			i++;
		}
		else
		{
			break;
		}
	}
	i = 0;
	while (1)
	{
		if (*(dest + i) != '\0')
		{
			counter_dest++;
			i++;
		}
		else
		{
			break;
		}
	}

	if (n > counter_dest)
	{
		std::cout << "Warning, the destination array is smaller than the numbers you wish to add." << std::endl;
		n = counter_dest;
	}

	if (n > counter_src)
	{
		std::cout << "Warning, the source array is smaller than the numbers you wish to add." << std::endl;
		n = counter_src;
	}

	for (int i = 0; i < n; i++)
	{
		*(dest + i) = *(src + i);
	}

	return dest;
}


int strcmp (const char * cstr1, const char * cstr2)
{
	int counter_cstr1 = 0;
	int counter_cstr2 = 0;
	int i = 0;
	while (1)
	{
		if (*(cstr1 + i) != '\0')
		{
			counter_cstr1++;
			i++;
		}
		else
		{
			break;
		}
	}
	i = 0;
	while (1)
	{
		if (*(cstr2 + i) != '\0')
		{
			counter_cstr2++;
			i++;
		}
		else
		{
			break;
		}
	}

	if (counter_cstr1 < counter_cstr2)
	{
		return -1;
	}
	else if (counter_cstr1 > counter_cstr2)
	{
		return 1;
	}
	else
	{
		for (int i = 0; i < counter_cstr1; i++)
		{
			if (*(cstr1 + i) != *(cstr2 + i))
			{
				return 10;
			}
		}
		return 0;
	}

	std::cout << counter_cstr1 << std::endl << counter_cstr2;
	return 10;
}

char * strncat (char * dest, const char * src, int n)
{
	int counter_src = 0;
	int counter_dest = 0;
	int i = 0;
	while (1)
	{
		if (*(src + i) != '\0')
		{
			counter_src++;
			i++;
		}
		else
		{
			break;
		}
	}
	i = 0;
	while (1)
	{
		if (*(dest + i) != '\0')
		{
			counter_dest++;
			i++;
		}
		else
		{
			break;
		}
	}

	if (n > counter_src)
	{
		std::cout << "Warning, the source array is smaller than the input n." << std::endl;
		n = counter_src;
	}

	for (int i = 0; i < n; i++)
	{
		*(dest + counter_dest + i) = *(src + i);
	}

	*(dest + counter_dest + n) = '\0';
	return dest;
}

char * strstr (char * cstr1, char * cstr2)
{
	int counter_cstr1 = 0;
	int counter_cstr2 = 0;
	int i = 0;
	while (1)
	{
		if (*(cstr1 + i) != '\0')
		{
			counter_cstr1++;
			i++;
		}
		else
		{
			break;
		}
	}
	i = 0;
	while (1)
	{
		if (*(cstr2 + i) != '\0')
		{
			counter_cstr2++;
			i++;
		}
		else
		{
			break;
		}
	}

	if (counter_cstr2 == 0)
	{
		return cstr1;
	}

	i = 0;
	int check = 0; // to check if the sub-string really exists
	int index = 0; // storing the index for string 1 we have to return it

	for (int i = 0; i < counter_cstr1; i++)
	{	
		for (int j = 0; j < counter_cstr2; j++)
		{
			if (*(cstr1 + i) == *(cstr2 + j))
			{
				for (int k = 0; k < counter_cstr2; k++)
				{
					if (*(cstr1 + i + k) == *(cstr2 + k))
					{
						check++;
					}
				}
				index = i;
				if (check == counter_cstr2)
				{
					char * arr = (cstr1 + index);
					return arr;
				}
				else
					return NULL;
			}
		}	
	}
	return NULL;
}

char * strtok (char * cstr, const char * delim)
{

	if (*delim == '\0') // input validation, there must NOT be 0 delim
	{
		std::cout << "Warning, there's no delimeter stated in the function." << std::endl;
		return cstr;
	}
	if (*(delim + 1) != '\0') // input validation, the delim must NOT be more than 1
	{
		std::cout << "Error: There must only be one delimeter.";
		return NULL;
	}

	int counter_cstr = 0;
	int i = 0;
	int index = 0;
	while (1)
	{
		if (*(cstr + i) != '\0')
		{
			if (*(cstr + i) == *delim)
			{
				index = i;
			}
			counter_cstr++;
			i++;
		}
		else
		{
			break;
		}
	}

	index = counter_cstr - index;
	*(cstr + index) = '\0'; // shorting the cstr array by putting a null right after
	return cstr;
}
