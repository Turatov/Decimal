// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// void float_to_binary(float f, char *binary_string)
// {
//     unsigned char *bytes = (unsigned char *)&f;
//     int i;
//     for (i = 3; i >= 0; i--) {
//         int j;
//         for (j = 7; j >= 0; j--) {
//             int bit = (bytes[i] >> j) & 1;
//             strcat(binary_string, bit ? "1" : "0");
//         }
//     }
// }
// void double_to_binary(double d, char *binary_string)
// {
//     unsigned char *bytes = (unsigned char *)&d;
//     int i;
//     for (i = 7; i >= 0; i--) {
//         int j;
//         for (j = 7; j >= 0; j--) {
//             int bit = (bytes[i] >> j) & 1;
//             strcat(binary_string, bit ? "1" : "0");
//         }
//     }
// }
// int main()
// {
//     float f = 3.14f;
//     char binary_string[33] = "";
//     float_to_binary(f, binary_string);
//     printf("Float %f in binary is %s\n", f, binary_string);

//     double d = 3.14;
//     binary_string[0] = '\0';
//     double_to_binary(d, binary_string);
//     printf("Double %lf in binary is %s\n", d, binary_string);
//     return 0;
// }

// В данном примере функции `float_to_binary` и `double_to_binary` 
// принимают соответственно `float` и `double` значения и возвращают
// их двоичное представление в виде строки символов.
// Функции используют указатель на массив байтов, чтобы получить 
// отдельные байты, составляющие число с плавающей точкой. 
// Затем байты считываются в обратном порядке, чтобы получить 
// правильный порядок битов. Каждый байт затем преобразуется в 
// последовательность из 8 битов, и эти биты добавляются в строку 
// двоичного представления.
// Пример использования функций включает преобразование чисел 
// `float` и `double` в их двоичное представление и вывод результатов 
// в консоль.

#include <stdio.h>

#include "s21_decimal.h"
int main(int argc, char const *argv[]) {
  s21_decimal n = {{48, 0}};
  s21_decimal d = {{6, 0}};
  s21_decimal r = {{42, 0}};
  s21_decimal q;
  s21_add(n, d, &q);  // 48+6 = 54
  int res;
  s21_from_decimal_to_int(q, &res);
  printf("%d", res);
  return 0;
}
