/*Exercise 2−5. Write the function any(s1,s2), which returns *the first location in a string s1 where anycharacter from the *string s2 occurs, or −1 if s1 contains no characters from s2. *(The standard libraryfunction strpbrk does the same job but *returns a pointer to the location.)*/

#include<stdio.h>
int any(char s1[],char s2[]);
int main()
{
	int a;
	char str1[20],str2[20];
	printf("Enter string1: ");
	scanf("%s",str1);
	printf("Enter string 2: ");
	scanf("%s", str2);
	a = any(str1,str2);
	printf("Matched location is :%d \n",a);
	return 0;
}
int any(char s1[], char s2[])
{
	int i, j;

	for(i = 0; s1[i] != '\0'; i++) {	
		for(j = 0; s2[j] != '\0'; j++) {	
			if(s1[i] == s2[j]) 		
				return i+1;	
		}
	}
	return -1;				
}

/* Output:-

Enter string 1:abc
Enter string 2:cde
Matched location is :3  (as the character matched is "c" and it is on the "3" position)

*/
