#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct _PhoneList
{
	char name[21];
	char number[20];
	struct _PhoneList* next;
	struct _PhoneList* Back_next;
}PhoneList;

void soot(PhoneList** p, PhoneList** start, PhoneList** last);
void lowerstring(char* out, const char* in);
char* lowerstring_ver2(char* in);
char lower(char c);
void upperstring(char* out, const char* in);
char upper(char c);
void gomi();

//入力余り消去
void gomi()
{
	//宣言
	char gomi;

	while (true)
	{
		//入力
		scanf_s("%c", &gomi, 1);
		//捨て終わってら
		if (gomi == '\n')
			break;
	}
}

//ソート昇順
void soot(PhoneList** p, PhoneList* *start, PhoneList** last)
{
	//ポインタを初期位置にセット
	*p = *start;
	/*** 宣言 ***/
	bool flg = true;

	//昇順になったら終了
	while (true)
	{
		//最初から最後まで
		for (int j = 0; (*p)->next != NULL; j++)
		{
			
			//nameよりnexr->nameが小さければ
			if (strcmp((*p)->name, (*p)->next->name) > 0)
			{
				//最初のポインタなら
				if ((*p)->Back_next == NULL)
				{
					*start = (*p)->next;
				}
				else
				{
					//最初のポインタ以外
					(*p)->Back_next->next = (*p)->next;
				}
				//全てのポインタ
				(*p)->next->Back_next = (*p)->Back_next;
				(*p)->Back_next = (*p)->next;
				(*p)->next = (*p)->next->next;
				(*p)->Back_next->next = (*p);
				//nextが最後のポインタ以外
				if ((*p)->next != NULL) (*p)->next->Back_next = (*p);
				flg = false;
				break;
			}

			//ポインタがNULLでなければ　　ポインタを次へ
			if ((*p)->next != NULL) * p = (*p)->next;
		}
		if (flg)
		{
			//ポインタを初期位置にセット
			*last = *p;
			*p = *start;
			return ;
		}
		//flgを初期化
		flg = true;

		//ポインタを初期位置にセット
		*p = *start;
	}
}

//文字列を大文字にする
void upperstring(char* out, const char* in) 
{
	int i;

	i = 0;
	while (in[i] != '\0') 
	{
		out[i] = upper(in[i]);
		i++;
	}
}



//文字を小文字にする
char lower(char c) 
{
	if ('A' <= c && c <= 'Z')
	{
		c = c + ('a' - 'A');
	}
	return c;
}



//文字列を小文字にする
void lowerstring(char* out, const char* in) 
{
	int i;

	i = 0;
	while (in[i] != '\0') 
	{
		out[i] = lower(in[i]);
		i++;
	}
}
//ver2
char* lowerstring_ver2(char* in)
{
	int i;
	char* out = (char*)malloc(sizeof(char) * 20);

	i = 0;
	while (in[i] != '\0')
	{
		out[i] = lower(in[i]);
		i++;
	}
	out[i] = lower(in[i]);
	return out;
}

//文字を大文字にする
char upper(char c) 
{
	if ('a' <= c && c <= 'z') 
	{
		c = c - ('a' - 'A');
	}
	return c;
}

