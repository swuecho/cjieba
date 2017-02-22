#include <stdio.h>
#include <stdlib.h>

#include "lib/jieba.h"
#include <string.h>

void CutDemo() {
  printf("CutDemo:\n");
  static const char* DICT_PATH = "./dict/jieba.dict.utf8";
  static const char* HMM_PATH = "./dict/hmm_model.utf8";
  static const char* USER_DICT = "./dict/user.dict.utf8";
  // init will take a few seconds to load dicts.
  Jieba handle = NewJieba(DICT_PATH, HMM_PATH, USER_DICT); 

  const char* s = "小明硕士毕业于中国科学院计算所，后在日本京都大学深造";
  size_t len = strlen(s);
  CJiebaWord* words = Cut(handle, s, len); 
  CJiebaWord* x;
  for (x = words; x && x->word; x++) {
    printf("%*.*s\n", x->len, x->len, x->word);
  }
  FreeWords(words);
  FreeJieba(handle);
}

void CutForSearchDemo() {
  printf("CutForSearchDemo:\n");
  static const char* DICT_PATH = "./dict/jieba.dict.utf8";
  static const char* HMM_PATH = "./dict/hmm_model.utf8";
  static const char* USER_DICT = "./dict/user.dict.utf8";
  // init will take a few seconds to load dicts.
  Jieba handle = NewJieba(DICT_PATH, HMM_PATH, USER_DICT); 

  const char* s = "小明硕士毕业于中国科学院计算所，后在日本京都大学深造";
  size_t len = strlen(s);
  CJiebaToken* tokens = CutForSearch(handle, s, len); 
  CJiebaToken* x;
  for (x = tokens; x && x->word; x++) {
    //printf("%zu\n", x->offset);
    //printf("%zu\n", x->offset + x->len);
    printf("%*.*s\n", x->len, x->len, x->word);
  }
  FreeTokens(tokens);
  FreeJieba(handle);
}

int main(int argc, char** argv) {
  CutDemo();
  CutForSearchDemo();
  return 0;
}
