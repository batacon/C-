#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256 // 入力行の最大長
#define NAME_SIZE 256

int main(void);
void get_line(char *buffer, int size);

int main(void)
{
  char name1[NAME_SIZE];    // 名前を格納する変数
  char name2[NAME_SIZE];    // 名前を格納する変数
  char buffer[BUFFER_SIZE]; // 入力した年齢を表す文字列を一時的に格納
  double age1, age2;

  printf("2人の平均年齢を計算します。\n");

  printf("1人目の名前を入力してください。\n");
  get_line(name1, NAME_SIZE);
  printf("%sさんの年齢を入力してください。\n", name1);
  get_line(buffer, BUFFER_SIZE);
  age1 = atoi(buffer);

  printf("2人目の名前を入力してください。\n");
  get_line(name2, NAME_SIZE);
  printf("%sさんの年齢を入力してください。\n", name2);
  get_line(buffer, BUFFER_SIZE);
  age2 = atoi(buffer);

  double average = (age1 + age2) / 2;
  printf("%sさんと%sさんの平均年齢は%0.1f歳です。\n", name1, name2, average);

  return 0;
}

void get_line(char *buffer, int size)
{
  if (fgets(buffer, size, stdin) == NULL) // fgetsで入力待ち
  {
    buffer[0] = '\0';
    return;
  }

  for (int i = 0; i < size; i++)
  {
    if (buffer[i] == '\n')
    {
      buffer[i] = '\0';
      return;
    }
  }
}