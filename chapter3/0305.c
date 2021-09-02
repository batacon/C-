#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256 // プリプロセッサによって処理されるマクロ定義(定数と何が違う？)

int main(void);
void get_line(char *buffer, int size);

int main(void)
{
  char buffer[BUFFER_SIZE]; // char型の配列bufferを{BUFFER_SIZE}個作成
  int age;

  printf("あなたの名前は？\n");
  get_line(buffer, BUFFER_SIZE);

  printf("%sさん、こんにちは\n", buffer);

  printf("年齢を入力してください\n");
  get_line(buffer, BUFFER_SIZE);
  age = atoi(buffer); // stdlib.hのatoi(ASCII to Integer)関数は数字の文字列をint型に変換する
  printf("今%d歳とすると、10年後は%d歳ですね。\n", age, age + 10);

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
