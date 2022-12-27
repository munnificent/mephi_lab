#include <stdio.h>
#include <ctype.h>
char*  str_erase(char* str, const char* sw);
char*  stri_erase(char* str, const char* sw);


int  main() {
  char str[]  = "ocean oceans[ocean] xocean, ocean(ocean,ocean,ocean)";
  char stri[] = "APL apl capl(Apl, APLI, aPl, apl). lang-APL";
  puts( str_erase(str,   "ocean") );
  puts( stri_erase(stri, "apl") );
  getchar();
  return 0;
}

// удаление из строки только указанное слово, не подстроки.
char*  str_erase(char* str, const char* sw) {
   int len;
   const char* ptr;
   char* iter, *sa, *sb, *tmp = str;
   while(*str) {
        ptr  = sw;
        iter = str;
        while(*iter++ == *ptr++ && *iter && *ptr);
        if(! *ptr && ! isalpha(*iter)) {
             if(str != tmp) {
                   if(isalpha(*(str-1))) {
                        *str++;
                        continue;
                   }
              }
              len = iter - str;
              while(len--)
                   for(sa = str, sb = str + 1; *sa; *sa++ = *sb++);
         }
        *str++;
    }
    return tmp;
}

// удаление из строки только указанное слово(без учёта регистра букв), не подстроки.
char*  stri_erase(char* str, const char* sw) {
   int len;
   const char* ptr;
   char* iter, *sa, *sb, *tmp = str;
   while(*str) {
          ptr  = sw;
          iter = str;
          while(toupper(*iter++) == toupper(*ptr++) && *iter && *ptr);
          if(! *ptr && ! isalpha(*iter)) {
                if(str != tmp) {
                     if(isalpha(*(str-1))) {
                          *str++;
                           continue;
                     }
                 }
                 len = iter - str;
                 while(len--)
                       for(sa = str, sb = str + 1; *sa; *sa++ = *sb++);
             }
             *str++;
     }
     return tmp;
}
