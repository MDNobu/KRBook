#include "stdio.h"
#include "ctype.h"
#include "math.h"
#define MAXLEN 1024

double atof(char s[]) {
	int i,sign;
	double power,result;
	
	result = 0.0;
	sign = 1;
	power = 1.0;
	
	for(i = 0; isspace(s[i]); i++)
		;
	if(s[i] == '-')
		sign = -1;
	if(s[i] == '-' || s[i] == '+') 
		i++;
	for(; isdigit(s[i]); i++) {
		result = result * 10 + (s[i] - '0');
	}
	if(s[i] == '.') {
		i++;
		for(; isdigit(s[i]); i++) {
			result = result * 10 + (s[i] - '0');
			power *= 10.0;
		}
	}
	
	int exp = 0;
	if(s[i] == 'e' || s[i] == 'E') {
		i++;
		int sign = 1;
		if(s[i] == '-')
			sign = -1;
		if(s[i] == '-' || s[i] == '+') 
			i++;
		for(; isdigit(s[i]); i++) {
			exp = exp * 10 + (s[i] - '0');
		}
		exp = exp * sign;
	}
	
	return sign * result * pow(10, exp) / power ; 
}

int main (int argc, char const* argv[])
{
	printf("%f\n", pow(10, 3));
	
	char s[] = "123.45e-2";
	double dest = atof(s);
	printf("%f\n", dest);
	return 0;
}