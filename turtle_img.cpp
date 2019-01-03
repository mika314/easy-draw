/* GIMP RGBA C-Source image dump 1-byte-run-length-encoded (turtle.c) */

#define GIMP_IMAGE_RUN_LENGTH_DECODE(image_buf, rle_data, size, bpp) do \
{ unsigned int __bpp; unsigned char *__ip; const unsigned char *__il, *__rd; \
  __bpp = (bpp); __ip = (image_buf); __il = __ip + (size) * __bpp; \
  __rd = (rle_data); if (__bpp > 3) { /* RGBA */ \
    while (__ip < __il) { unsigned int __l = *(__rd++); \
      if (__l & 128) { __l = __l - 128; \
        do { memcpy (__ip, __rd, 4); __ip += 4; } while (--__l); __rd += 4; \
      } else { __l *= 4; memcpy (__ip, __rd, __l); \
               __ip += __l; __rd += __l; } } \
  } else { /* RGB */ \
    while (__ip < __il) { unsigned int __l = *(__rd++); \
      if (__l & 128) { __l = __l - 128; \
        do { memcpy (__ip, __rd, 3); __ip += 3; } while (--__l); __rd += 3; \
      } else { __l *= 3; memcpy (__ip, __rd, __l); \
               __ip += __l; __rd += __l; } } \
  } } while (0)
static const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */ 
  char         	*comment;
  unsigned char	 rle_pixel_data[5022 + 1];
} gimp_image = {
  64, 64, 4,
  (char*) 0,
  "\234\000\000\000\000\011\213\312y\025\213\312yw\213\312y\302\213\312y\367\213\312y"
  "\374\213\312y\322\213\312y\217\213\312y&\213\312y\001\264\000\000\000\000\004\213\312"
  "y\001\000\000\000\000\213\312ys\213\312y\354\206\213\312y\377\003\213\312y\373\213\312"
  "y\235\213\312y\002\264\000\000\000\000\001\213\312y\231\212\213\312y\377\002\213\312y\321"
  "\213\312y\010\262\000\000\000\000\001\213\312y^\214\213\312y\377\001\213\312y\230\261"
  "\000\000\000\000\002\213\312y\007\213\312y\354\215\213\312y\377\001\213\312y>\260\000\000\000"
  "\000\005\213\312yx\213\312y\377\213\313y\377\206\304w\377\207\305w\377\206\213"
  "\312y\377\002\210\307w\377\205\303v\377\202\213\312y\377\001\213\312y\330\260"
  "\000\000\000\000\007\213\312y\367\215\314z\377y\266q\377Q\213_\377R\214`\377|\272r"
  "\377\214\313y\377\203\213\312y\377\007\210\307x\377V\220a\377P\211^\377l\250"
  "k\377\215\314z\377\213\312y\377\213\312y;\256\000\000\000\000\010\213\312yA\213\312"
  "y\377\217\317{\377W\221b\377K\204\\\377I\202[\377f\241h\377\216\315z\377"
  "\202\213\312y\377\010\214\314z\377w\263o\377H\201[\377K\204\\\377O\211^\377"
  "\214\313y\377\213\312y\377\213\312y\223\256\000\000\000\000\010\213\312y\177\213\312"
  "y\377\215\314z\377v\263o\377P\211^\377P\212^\377{\271r\377\214\313z\377\203"
  "\213\312y\377\010\207\306w\377S\215`\377O\211^\377h\244i\377\215\315z\377"
  "\213\312y\377\213\312y\303\213\312y\002\255\000\000\000\000\001\213\312y\241\202\213"
  "\312y\377\004\213\313y\377\205\303v\377\205\304v\377\214\313y\377\205\213\312"
  "y\377\003\207\305w\377\204\302v\377\212\311y\377\202\213\312y\377\002\213\312"
  "y\322\213\312y\020\255\000\000\000\000\001\213\312y\254\220\213\312y\377\002\213\312y"
  "\327\213\312y\024\255\000\000\000\000\001\213\312y\251\220\213\312y\377\002\213\312y\325"
  "\213\312y\023\240\000\000\000\000\005\213\312y\010\213\312y\243\213\312y\342\213\312"
  "y\251\213\312y\007\210\000\000\000\000\001\213\312y\215\220\213\312y\377\002\213\312y\305"
  "\213\312y\005\207\000\000\000\000\005\213\312y\040\213\312y\310\213\312y\376\213\312y"
  "\301\213\312y\024\223\000\000\000\000\002\213\312y\014\213\312y\317\203\213\312y\377"
  "\002\213\312y\360\213\312y(\207\000\000\000\000\001\213\312y<\220\213\312y\377\001\213"
  "\312y\214\207\000\000\000\000\002\213\312y\070\213\312y\373\203\213\312y\377\002\213\312"
  "y\334\213\312y\022\222\000\000\000\000\001\213\312yu\205\213\312y\377\002\213\312y\300"
  "\213\312y\003\207\000\000\000\000\001\213\312y\344\203\213\312y\377\002\212\312y\377\211"
  "\311x\377\204\210\311x\377\002\211\311x\377\212\312y\377\204\213\312y\377\001"
  "\213\312y\032\206\000\000\000\000\002\213\312y\002\213\312y\312\205\213\312y\377\001\213"
  "\312y{\222\000\000\000\000\001\213\312y\324\206\213\312y\377\001\213\312y\064\207\000\000"
  "\000\000\020\212\312y\070\213\312y\377\216\313z\377\223\315}\377\240\322\202\377"
  "\257\327\212\377\273\334\217\377\301\335\221\377\300\335\221\377\272\333"
  "\217\377\257\327\211\377\240\322\202\377\223\315}\377\216\313z\377\213\312"
  "y\377\213\312y\215\207\000\000\000\000\001\213\312yI\206\213\312y\377\001\213\312y\353"
  "\222\000\000\000\000\207\213\312y\377\001\213\312y\322\207\000\000\000\000\004\311\341\225!\261"
  "\330\212\336\274\334\217\377\311\341\225\377\210\312\341\225\377\004\310\341"
  "\225\377\273\334\217\377\255\327\211\366\273\334\217'\207\000\000\000\000\001\213\312"
  "y\334\207\213\312y\377\222\000\000\000\000\001\213\312y\350\207\213\312y\377\001\213"
  "\312y-\204\000\000\000\000\003\307\340\224\005\307\340\224\221\307\340\224\376\202\307"
  "\340\224\377\012\310\340\224\377\304\337\223\377\266\331\214\377\254\326\210"
  "\377\250\325\206\377\251\325\206\377\256\327\210\377\271\333\215\377\306"
  "\340\223\377\310\340\224\377\202\307\340\224\377\003\307\340\224\376\307\340"
  "\224\214\307\340\224\004\204\000\000\000\000\001\213\312y\061\207\213\312y\377\001\213\312"
  "y\357\222\000\000\000\000\001\213\312y\243\207\213\312y\377\001\213\312y\220\203\000\000"
  "\000\000\007\307\340\224:\307\340\224\322\307\340\224\377\311\341\225\377\277\335"
  "\220\377\253\326\207\377\230\316\177\377\202\210\311x\377\203\211\311x\377"
  "\202\210\311x\377\010\212\311x\377\234\321\201\377\261\330\212\377\302\336"
  "\222\377\310\340\225\377\307\340\224\377\307\340\224\321\307\340\224\067\203"
  "\000\000\000\000\001\213\312y\234\207\213\312y\377\001\213\312y\233\222\000\000\000\000\001\213"
  "\312y?\207\213\312y\377\012\213\312y\327\214\312y\024\000\000\000\000\307\340\224i"
  "\307\340\224\365\307\340\224\377\306\340\224\377\244\324\204\377\217\313"
  "{\377\212\312y\377\211\213\312y\377\202\212\312y\377\011\221\314{\377\255"
  "\327\211\377\312\341\225\377\307\340\224\377\307\340\224\363\307\340\224"
  "d\000\000\000\000\214\312y\025\213\312y\332\207\213\312y\377\001\213\312y\067\222\000\000"
  "\000\000\002\213\312y\017\213\312y\317\207\213\312y\377\007\210\311x@\307\340\224"
  "]\307\340\224\377\310\340\224\377\306\340\224\377\244\323\204\377\212\311"
  "x\377\216\213\312y\377\002\210\311x\377\254\326\207\377\203\307\340\224\377"
  "\002\310\340\224W\210\311xM\207\213\312y\377\002\213\312y\303\213\312y\013\223"
  "\000\000\000\000\001\213\312y]\206\213\312y\377\010\212\312y\377\250\324\206\337\310"
  "\340\224\377\312\341\225\377\262\331\213\377\237\321\202\377\305\337\223"
  "\377\217\313{\377\215\213\312y\377\011\212\312y\377\221\315|\377\305\337\223"
  "\377\242\323\204\377\276\334\220\377\311\341\225\377\310\340\224\377\246"
  "\324\205\336\211\311x\377\204\213\312y\377\003\213\312y\376\213\312y\377\213"
  "\312yM\225\000\000\000\000\001\213\312y\254\205\213\312y\377\011\227\316\177\377\305"
  "\337\223\377\307\340\224\377\264\331\213\377\214\313z\377\213\312y\377\270"
  "\333\215\377\272\334\217\377\210\311x\377\214\213\312y\377\011\210\311w\377"
  "\274\334\217\377\267\332\215\377\213\312y\377\216\313z\377\276\335\220\377"
  "\307\340\224\377\304\337\223\377\226\316~\377\205\213\312y\377\001\213\312"
  "y\213\227\000\000\000\000\001\213\312y\303\203\213\312y\377\012\214\312y\377\275\335"
  "\217\377\311\341\225\377\276\335\220\377\217\313{\377\213\312y\377\212\312"
  "y\377\226\316~\377\310\340\224\377\236\321\201\377\214\213\312y\377\011\240"
  "\322\203\377\307\340\224\377\223\315|\377\212\312y\377\213\312y\377\227\317"
  "~\377\305\337\223\377\310\340\224\377\274\334\217\377\204\213\312y\377\003"
  "\213\312y\260\000\000\000\000\213\312y\001\226\000\000\000\000\011\213\312y\030\213\312y\346"
  "\213\312y\377\210\311w\377\257\327\212\377\311\341\225\377\310\340\225\377"
  "\221\314|\377\212\312y\377\202\213\312y\377\004\211\311x\377\247\325\206\377"
  "\276\334\220\377\215\313z\377\212\213\312y\377\004\215\313z\377\300\335\220"
  "\377\247\325\205\377\211\311x\377\202\213\312y\377\011\211\312x\377\236\321"
  "\201\377\313\342\226\377\311\341\225\377\255\326\211\377\210\311x\377\213"
  "\312y\377\213\312y\333\213\312y\021\231\000\000\000\000\007\213\312y&\213\312y\370\225"
  "\315}\377\306\340\224\377\310\340\224\377\244\324\204\377\212\312y\377\204"
  "\213\312y\377\004\214\312y\377\303\337\222\377\240\322\203\377\212\312x\377"
  "\210\213\312y\377\003\212\311x\377\244\323\205\377\277\335\221\377\205\213"
  "\312y\377\007\211\311x\377\263\331\213\377\310\340\224\377\307\340\224\377"
  "\224\316}\377\213\312y\357\213\312y\023\233\000\000\000\000\005\214\313z\062\262\331"
  "\213\346\307\340\224\377\276\335\220\377\217\313{\377\206\213\312y\377\004"
  "\241\322\203\377\306\337\223\377\217\314{\377\207\311w\377\206\207\311x\377"
  "\004\207\311w\377\220\314|\377\306\340\224\377\240\322\203\377\206\213\312"
  "y\377\005\224\316}\377\303\337\223\377\307\340\224\377\262\330\213\340\215"
  "\313z%\234\000\000\000\000\005\307\340\224\022\307\340\224\346\307\340\224\377\250\324"
  "\206\377\212\312x\377\206\213\312y\377\004\212\312y\377\276\335\220\377\300"
  "\335\221\377\267\332\215\377\206\270\332\215\377\004\267\332\215\377\302\336"
  "\222\377\274\334\217\377\211\311x\377\207\213\312y\377\004\266\331\214\377"
  "\307\340\224\377\307\340\224\337\307\340\224\020\234\000\000\000\000\001\307\340\224"
  "H\202\307\340\224\377\001\215\313z\377\207\213\312y\377\003\212\312y\377\267"
  "\332\215\377\310\340\225\377\210\310\340\224\377\003\310\340\225\377\263\331"
  "\213\377\212\311x\377\206\213\312y\377\005\212\312y\377\233\320\200\377\310"
  "\340\225\377\307\340\224\377\307\340\224E\234\000\000\000\000\004\307\340\224\275\310"
  "\341\225\377\263\331\213\377\210\311x\377\207\213\312y\377\002\237\322\202"
  "\377\306\340\224\377\212\307\340\224\377\002\306\337\223\377\232\320\200\377"
  "\207\213\312y\377\004\210\311x\377\305\340\223\377\307\340\224\377\307\340"
  "\224\253\234\000\000\000\000\004\307\340\224\377\313\341\226\377\227\316~\377\212\312"
  "y\377\206\213\312y\377\002\214\313z\377\272\334\216\377\213\307\340\224\377"
  "\003\310\340\224\377\266\332\215\377\214\312y\377\206\213\312y\377\004\211\311"
  "x\377\251\326\207\377\311\341\225\377\307\340\224\377\233\000\000\000\000\004\307\340"
  "\224\067\307\340\224\377\305\340\223\377\214\313z\377\206\213\312y\377\003\211"
  "\311x\377\245\324\205\377\312\341\225\377\214\307\340\224\377\003\311\341\225"
  "\377\235\320\201\377\211\311x\377\205\213\312y\377\005\212\312y\377\227\316"
  "~\377\313\341\226\377\307\340\224\377\307\340\224\070\232\000\000\000\000\004\307\340"
  "\224r\307\340\224\377\274\334\217\377\214\312z\377\206\213\312y\377\002\220"
  "\314{\377\310\340\224\377\216\307\340\224\377\002\306\337\224\377\214\313y"
  "\377\206\213\312y\377\004\214\313z\377\310\340\225\377\307\340\224\377\307"
  "\340\224d\232\000\000\000\000\004\307\340\224\242\307\340\224\377\263\330\213\377\214"
  "\312y\377\206\213\312y\377\001\264\331\213\377\220\307\340\224\377\001\256\327"
  "\211\377\206\213\312y\377\004\214\313z\377\276\335\220\377\307\340\224\377"
  "\307\340\224\212\232\000\000\000\000\003\307\340\224\271\310\340\224\377\253\326\210"
  "\377\206\211\311x\377\002\225\316~\377\306\337\223\377\220\307\340\224\377"
  "\002\304\337\222\377\222\315|\377\205\211\311x\377\004\212\312y\377\270\333\215"
  "\377\307\340\224\377\307\340\224\261\232\000\000\000\000\005\307\340\224\300\307\340"
  "\224\377\275\334\217\377\263\331\213\377\262\331\213\377\204\262\330\213"
  "\377\002\277\335\220\377\310\340\224\377\220\307\340\224\377\002\310\340\224"
  "\377\273\333\216\377\204\257\330\211\377\005\256\330\211\377\257\330\212\377"
  "\300\335\221\377\307\340\224\377\307\340\224\304\232\000\000\000\000\003\307\340\224"
  "\301\307\340\224\377\267\332\215\377\206\251\325\206\377\002\270\333\215\377"
  "\310\340\224\377\220\307\340\224\377\003\310\341\225\377\266\332\215\377\252"
  "\326\207\377\204\252\326\210\377\004\253\326\210\377\277\335\220\377\307\340"
  "\224\377\307\340\224\305\232\000\000\000\000\003\307\340\224\273\310\340\224\377\252"
  "\326\210\377\206\213\312y\377\002\226\316~\377\304\337\223\377\220\307\340"
  "\224\377\002\301\336\221\377\223\315}\377\205\213\312y\377\004\214\312y\377\267"
  "\333\215\377\307\340\224\377\307\340\224\267\232\000\000\000\000\004\307\340\224\252"
  "\310\340\224\377\261\330\212\377\214\312y\377\205\213\312y\377\002\212\312"
  "y\377\261\330\212\377\217\307\340\224\377\003\310\340\224\377\254\326\210\377"
  "\212\312y\377\205\213\312y\377\004\214\312z\377\273\334\217\377\307\340\224"
  "\377\307\340\224\223\232\000\000\000\000\004\307\340\224}\307\340\224\377\271\333\216"
  "\377\214\312z\377\206\213\312y\377\002\216\313z\377\310\341\224\377\216\307"
  "\340\224\377\001\302\336\222\377\207\213\312y\377\004\214\313z\377\305\337\223"
  "\377\307\340\224\377\307\340\224k\232\000\000\000\000\004\307\340\224J\307\340\224"
  "\377\302\336\221\377\215\313z\377\206\213\312y\377\003\211\311x\377\240\321"
  "\202\377\311\341\225\377\214\307\340\224\377\003\312\341\226\377\232\320\201"
  "\377\212\312y\377\206\213\312y\377\004\222\314}\377\314\341\226\377\307\340"
  "\224\377\307\340\224F\232\000\000\000\000\004\307\340\224\002\307\340\224\377\312\341"
  "\225\377\220\314|\377\210\213\312y\377\001\272\333\216\377\213\307\340\224"
  "\377\003\310\340\224\377\264\331\214\377\212\312y\377\206\213\312y\377\005\211"
  "\311x\377\242\323\204\377\312\341\225\377\307\340\224\377\307\340\224\002\233"
  "\000\000\000\000\004\307\340\224\323\311\341\225\377\253\325\207\377\211\311x\377\207"
  "\213\312y\377\002\235\321\201\377\306\337\223\377\212\307\340\224\377\002\305"
  "\337\223\377\231\317\200\377\207\213\312y\377\004\206\311w\377\276\334\217"
  "\377\310\340\224\377\307\340\224\275\234\000\000\000\000\004\307\340\224a\307\340\224"
  "\377\302\337\222\377\211\311x\377\207\213\312y\377\003\211\311x\377\271\333"
  "\216\377\310\340\224\377\210\311\341\225\377\003\310\340\225\377\264\331\214"
  "\377\210\311x\377\207\213\312y\377\004\222\314|\377\311\341\225\377\307\340"
  "\224\377\307\340\224c\234\000\000\000\000\005\307\340\224\030\307\340\224\363\310\341"
  "\225\377\236\321\202\377\212\312y\377\206\213\312y\377\004\211\312x\377\273"
  "\334\217\377\275\335\220\377\247\324\205\377\206\251\325\206\377\004\247\324"
  "\205\377\300\336\221\377\270\333\216\377\210\311x\377\206\213\312y\377\005"
  "\212\312x\377\256\327\211\377\307\340\224\377\307\340\224\355\307\340\224"
  "\025\234\000\000\000\000\004\307\340\224\004\307\340\224\247\307\340\224\377\270\333\215"
  "\377\207\213\312y\377\004\236\321\202\377\307\340\224\377\222\315|\377\211"
  "\311x\377\206\212\312y\377\004\211\311x\377\224\315}\377\307\340\224\377\235"
  "\321\201\377\206\213\312y\377\005\220\314{\377\277\335\220\377\307\340\224"
  "\377\307\340\224\246\307\340\224\004\235\000\000\000\000\004\307\340\224D\307\340\224"
  "\377\306\340\224\377\232\320\200\377\206\213\312y\377\003\276\335\220\377\246"
  "\324\206\377\211\311x\377\210\213\312y\377\003\210\311x\377\252\326\207\377"
  "\275\334\217\377\205\213\312y\377\005\212\312x\377\246\324\205\377\310\341"
  "\225\377\307\340\224\377\307\340\224=\237\000\000\000\000\004\307\340\224\277\310\340"
  "\224\377\277\335\220\377\210\311x\377\203\213\312y\377\004\211\311x\377\244"
  "\323\204\377\277\335\221\377\216\313{\377\212\213\312y\377\004\217\313{\377"
  "\300\335\221\377\242\323\204\377\211\311x\377\203\213\312y\377\004\220\313"
  "{\377\311\341\224\377\307\340\224\377\307\340\224\266\240\000\000\000\000\005\266\331"
  "\214\021\302\336\222\377\311\341\225\377\261\330\212\377\212\312x\377\202"
  "\213\312y\377\004\221\314|\377\311\341\225\377\241\323\203\377\212\312y\377"
  "\213\213\312y\377\003\244\323\204\377\307\340\224\377\217\313{\377\202\213"
  "\312y\377\005\215\313z\377\277\335\220\377\310\340\224\377\301\336\221\377"
  "\240\321\202\032\240\000\000\000\000\002\212\312y\254\236\321\201\377\202\307\340\224"
  "\377\006\245\324\205\377\212\312y\377\213\312y\377\265\331\214\377\274\334"
  "\217\377\212\312x\377\214\213\312y\377\006\212\312y\377\276\334\220\377\264"
  "\331\213\377\213\312y\377\212\312y\377\262\330\213\377\202\307\340\224\377"
  "\003\235\321\201\377\213\312y\314\214\312y\010\236\000\000\000\000\012\213\312y\204\213"
  "\312y\377\212\312y\377\260\327\212\377\307\340\224\377\310\341\225\377\236"
  "\321\202\377\230\317\177\377\307\340\224\377\220\314{\377\215\213\312y\377"
  "\014\212\312y\377\224\315}\377\310\340\224\377\225\316~\377\254\327\210\377"
  "\312\341\225\377\307\340\224\377\257\330\212\377\212\312x\377\213\312y\377"
  "\213\312y\245\213\312y\005\234\000\000\000\000\002\213\312yO\213\312y\376\202\213\312"
  "y\377\007\212\311x\377\257\330\211\377\312\341\225\377\311\341\225\377\300"
  "\335\221\377\247\324\206\377\212\312x\377\216\213\312y\377\007\211\311x\377"
  "\253\325\210\377\304\337\222\377\311\341\225\377\312\341\225\377\257\330"
  "\211\377\212\311y\377\203\213\312y\377\001\213\312yz\233\000\000\000\000\001\213\312"
  "y\033\205\213\312y\377\007\214\312y\377\255\326\210\377\307\340\224\377\310"
  "\340\224\377\275\334\217\377\217\313z\377\212\312x\377\214\213\312y\377\003"
  "\211\311x\377\231\317\177\377\304\337\222\377\202\307\340\224\377\002\254\326"
  "\210\377\214\312y\377\205\213\312y\377\001\213\312yK\232\000\000\000\000\001\213\312"
  "y\277\206\213\312y\377\011\207\311w\236\305\337\223\204\307\340\224\357\310"
  "\340\224\377\312\341\225\377\254\326\210\377\227\316~\377\214\313z\377\211"
  "\311x\377\202\212\312y\377\202\213\312y\377\014\212\312y\377\212\312x\377"
  "\211\311x\377\217\313z\377\231\317\200\377\264\331\213\377\312\341\225\377"
  "\307\340\224\377\307\340\224\356\307\340\224y\206\310vu\213\312y\376\205"
  "\213\312y\377\002\213\312y\336\213\312y\013\230\000\000\000\000\002\213\312y\067\213\312"
  "y\364\205\213\312y\377\014\213\312y\371\213\312yE\000\000\000\000\307\340\224*\307"
  "\340\224\271\307\340\224\377\310\341\225\377\305\337\223\377\273\334\217"
  "\377\261\330\212\377\241\322\203\377\226\316~\377\202\222\315|\377\014\230"
  "\317\177\377\244\323\204\377\264\332\214\377\275\335\220\377\306\340\224"
  "\377\310\340\224\377\307\340\224\377\307\340\224\265\307\340\224)\000\000\000\000"
  "\213\312y\037\213\312y\366\206\213\312y\377\001\213\312yS\230\000\000\000\000\001\213"
  "\312yn\206\213\312y\377\001\213\312y\351\204\000\000\000\000\006\307\340\224=\307\340"
  "\224\324\307\340\224\367\307\340\224\376\307\340\224\377\310\340\225\377"
  "\204\311\341\225\377\006\310\340\224\377\307\340\224\377\307\340\224\376\307"
  "\340\224\366\307\340\224\320\307\340\224\071\204\000\000\000\000\001\213\312y\301\206"
  "\213\312y\377\001\213\312y\242\230\000\000\000\000\001\213\312y\263\206\213\312y\377"
  "\001\213\312yw\206\000\000\000\000\005\307\340\224\066\307\340\224m\307\340\224\242\307"
  "\340\224\313\277\335\221\377\202\302\336\222\377\005\300\336\221\375\307\340"
  "\224\313\307\340\224\241\307\340\224k\307\340\224\064\206\000\000\000\000\001\213\312"
  "y\064\206\213\312y\377\001\213\312y\326\230\000\000\000\000\001\213\312y\273\206\213\312"
  "y\377\211\000\000\000\000\003\307\340\224\003\274\333\216\011\216\313z\331\202\215\313"
  "z\377\003\216\313z\313\274\334\217\011\307\340\224\003\211\000\000\000\000\001\213\312y"
  "\336\205\213\312y\377\001\213\312y\346\230\000\000\000\000\001\213\312y\206\205\213\312"
  "y\377\001\213\312y\214\212\000\000\000\000\002\213\312y\001\213\312y\274\202\213\312y\377"
  "\002\213\312y\231\213\312y\001\212\000\000\000\000\001\213\312y\\\205\213\312y\377\001\213"
  "\312y\257\230\000\000\000\000\003\213\312y+\213\312y\365\213\312y\376\202\213\312y"
  "\377\002\213\312y\350\213\312y\033\212\000\000\000\000\002\213\312y\001\213\312y\267\202"
  "\213\312y\377\001\213\312ye\213\000\000\000\000\002\213\312y\014\213\312y\323\203\213"
  "\312y\377\002\213\312y\376\213\312yN\231\000\000\000\000\005\213\312yQ\213\312y\370\213"
  "\312y\366\213\312y\354\213\312y,\213\000\000\000\000\005\213\312y\002\213\312y\310\213"
  "\312y\377\213\312y\355\213\312y(\214\000\000\000\000\002\213\312y\017\213\312y\332\202"
  "\213\312y\367\001\213\312y\211\233\000\000\000\000\002\213\312y\016\213\312y,\215\000\000"
  "\000\000\004\213\312y\014\213\312y\376\213\312y\377\213\312y\263\217\000\000\000\000\002\213"
  "\312y,\213\312y\036\253\000\000\000\000\004\213\312y\210\213\312y\377\213\312y\372\213"
  "\312y\012\273\000\000\000\000\004\213\312y#\213\312y\377\213\312y\315\213\312y!\240"
  "\000\000\000\000",
};

#include "turtle_img.hpp"

std::unique_ptr<sdl::Surface> loadTurtle() noexcept
{
  auto surf = std::make_unique<sdl::Surface>(0,
                                             gimp_image.width,
                                             gimp_image.height,
                                             8 * gimp_image.bytes_per_pixel,
                                             0x000000ff,
                                             0x0000ff00,
                                             0x00ff0000,
                                             0xff000000);
  GIMP_IMAGE_RUN_LENGTH_DECODE(static_cast<unsigned char *>(surf->get()->pixels),
                               gimp_image.rle_pixel_data,
                               gimp_image.width * gimp_image.height,
                               gimp_image.bytes_per_pixel);

  return surf;
}