#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void PrintfSS(char *ss, char *szBuf)
{
	char *cp = szBuf;
	for (; *ss != '\n'; ss++)
	{
		if (*ss != '/')
		{
			*szBuf = *ss;
			szBuf++;
		}
	}
	*szBuf = '\0';
	szBuf = cp;
	printf("%s", cp);
}

void PrintfSA(char *sa, char *szBuf)
{
	char *cp = szBuf;
	bool exitStr = false;
	//printf("%d:exitStr is %d\n", __LINE__, exitStr);
	for (; *sa != '\n'; sa++)
	{
		if ((*sa != '/') && (*sa != '*'))
		{
			//printf("%d:%c\n", __LINE__, *szBuf);
			*szBuf = *sa;
			szBuf++;
			exitStr = true;
		}
	}
	//printf("%d:exitStr is %d\n", __LINE__, exitStr);
	if (exitStr)
	{
		*szBuf = '\0';
		szBuf = cp;
		printf("%s", cp);
	}
}



int main()
{
	char sz[256] = { 0, };
	
	bool sa = false;
	while (fgets(sz, sizeof(sz), stdin))
	{
		//printf("入力：%s\n", sz);
		char szBuf[256] = { 0, };
		//”//”があるか調べる
		char *pss = strstr(sz, "//");
		if (pss != NULL)
		{
			PrintfSS(pss, szBuf);
		}

		//"/*"があるか調べる
		char *psa = strstr(sz, "/*");
		if (psa != NULL)
		{
			sa = true;
		}

		if (sa)
		{
			PrintfSA(psa, szBuf);
			if (strstr(sz, "*/"))
			{
				sa = false;
			}
		}

	}
	return 0;
}