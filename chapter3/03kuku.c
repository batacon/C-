#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_Q 10        // 表示する問題の個数
#define BUFFER_SIZE 256 // 入力行の最大長

// プロトタイプ宣言
int main(void);
int kuku(int qn);
void get_line(char *buffer, int size);

int main(void)
{
  double good_rate;     // 正答率
  int good_answers = 0; // 政党数合計

  // 現在時刻を使って乱数の種を設定
  srand((unsigned int)time(NULL));
  printf("%d\n", rand());

  // オープニングメッセージを表示
  printf("これから九九の問題を%d問出します。", MAX_Q);

  good_answers = 0;
  for (int i = 0; i < MAX_Q; i++)
  {
    good_answers += kuku(i);
  }

  // 正答率を計算する。
  good_rate = good_answers * 100.0 / MAX_Q;

  // 結果を表示する
  printf("問題は%d問ありました\n", MAX_Q);
  printf("%d問は正しく答えられましたが、\n", good_answers);
  printf("%d問は間違ってしまいました。\n", MAX_Q - good_answers);
  printf("正答率%0.1f%%です。\n", good_rate);
  printf("\n");
  printf("お疲れ様。\n");
  return 0;
}

// 関数kukuは九九の問題を1問出し、答えを待つ。
// 政党・後藤の別を表示する。
// 正答なら１、誤答なら0を返す。
int kuku(int qn)
{
  int x, y, result;
  char buffer[BUFFER_SIZE];

  // 問題をランダムに生成する。
  x = rand() % 9 + 1;
  y = rand() % 9 + 1;

  // 出題する
  printf("[第%d問] %d * %d =\n", qn + 1, x, y);

  // 端末が開業待ちで表示を抑止するのを防ぐ
  fflush(stdout);

  // 解答の入力を待つ
  get_line(buffer, BUFFER_SIZE);

  // 解答を正数に変換する
  result = atoi(buffer);

  // 正答か誤答か確認する
  if (x * y == result)
  {
    printf("はい、正しいです\n");
    return 1;
  }
  else
  {
    printf("残念、間違いです。\n");
    return 0;
  }
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