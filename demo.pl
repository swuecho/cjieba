use FFI::Platypus;
use FFI::CheckLib 0.06;

my $libpath = './';
check_lib_or_exit( lib => [ 'jieba'  ],  libpath => './' );

my $ffi = FFI::Platypus->new;
$ffi->lib($libpath);

my  $DICT_PATH = "./dict/jieba.dict.utf8";
my  $HMM_PATH = "./dict/hmm_model.utf8";
my  $USER_DICT = "./dict/user.dict.utf8";

// init will take a few seconds to load dicts.
Jieba handle = NewJieba(DICT_PATH, HMM_PATH, USER_DICT); 

  const char* s = "南京市长江大桥";
  size_t len = strlen(s);
  CJiebaWord* words = Cut(handle, s, len); 
  CJiebaWord* x;
  for (x = words; x && x->word; x++) {
    printf("%*.*s\n", x->len, x->len, x->word);
  }
  FreeWords(words);
  FreeJieba(handle);
}

