//
// Created by Gulian Boris on 12/16/22.
//
#include <math.h>
#include <string.h>

#include "../s21_string.h"
int main(void) {
  char str_arr1[] = "School-21";
  char str_arr2[] = "School-21";
  char dest10[] = "///test1///test2/test3/";
  char orig10[] = "///test1///test2/test3/";
  char *tok7 = s21_strtok(str_arr1, "Sc");
  char *tok8 = strtok(str_arr2, "Sc");
  printf("|%s| |%s|\n", tok7, tok8);
  char *tok9 = s21_strtok(str_arr1, "21");
  char *tok10 = strtok(str_arr2, "21");
  printf("|%s| |%s|\n", tok9, tok10);
  //  int d1 = 0, d2 = 0, d3 = 0, d4 = 0, res1 = 0, res2 = 0;
  ////  float e1 = 0, e2 = 0;
  //  int r1 = 0, r2 = 0, d1 = 0, d2 = 0, i1 = 0, i2 = 0;
  ////////  unsigned u1 = 0, u2 = 0;
  //  char s1[100] = {0}, s2[100] = {0}, c1 = 0, c2 = 0;
  ////
  //  int d1 = 0, d2 = 0, i1 = 0, i2 = 0, n1 = 0, n2 = 0;
  // int  r1 = 0, r2 = 0;
  //  float e1 = 0, e2 = 0, E1 = 0, E2 = 0, f1 = 0, f2 = 0, g1 = 0, g2 = 0, G1 =
  //  0,
  //      G2 = 0;
  ////  unsigned int o1 = 0, o2 = 0, u1 = 0, u2 = 0, x1 = 0, x2 = 0, X1 = 0, X2
  ///= 0;
  //  void *p1 = 0, *p2 = 0;
  //  unsigned o1 = 0, o2 = 0, o3 = 0, o4 = 0, o5 = 0, o6 = 0;
  //  char s1[100] = {0}, s2[100] = {0}, c1, c2, proc1[100] = {0}, proc2[100] =
  //  {0}; short hi1 = 0, hi2 = 0, hd1 = 0, hd2 = 0; unsigned long lo1 = 0, lo2
  //  = 0, lu1 = 0, lu2 = 0; long double Le1 = 0, Le2 = 0, LE1 = 0, LE2 = 0, Lg1
  //  = 0, Lg2 = 0, LG1 = 0,
  //      LG2 = 0;

  //  printf("orig - %d %d %d %s %c %e\nmy - %d %d %d %s %c %e\n", r1, i1, d1,
  //  s1, c1, e1, r2, i2, d2, s2, c2, e2);

  //  r1 = sscanf(
  //      "4 123 amogusq 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21 "
  //      "shrek "
  //      "& amogus is sus?",
  //      "%*i%12i%4d%20s%c%3e%7E%*i%1f%9g%5G%6o%12u%*x%11x%2X%10p%n%21s%%",
  //      &i1, &d1, s1, &c1, &e1, &E1, &f1, &g1, &G1, &o1, &u1, &x1, &X1, &p1,
  //      &n1, proc1);
  //  r2 = s21_sscanf(
  //      "4 123 amogusq 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21 "
  //      "shrek "
  //      "& amogus is sus?",
  //      "%*i%12i%4d%20s%c%3e%7E%*i%1f%9g%5G%6o%12u%*x%11x%2X%10p%n%21s%%",
  //      &i2, &d2, s2, &c2, &e2, &E2, &f2, &g2, &G2, &o2, &u2, &x2, &X2, &p2,
  //      &n2, proc2);
  //  printf("orig - %d %d %d %s %c %e\nmy - %d %d %d %s %c %e\n", r1, i1, d1,
  //  s1, c1, e1, r2, i2, d2, s2, c2, e2);

  //  char a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;
  //
  //  int16_t res1 = sscanf("   a     b c d", "%c %c %c %c", &a1, &b1, &c1,
  //  &d1);
  //
  //  int16_t res2 = s21_sscanf("   a     b c d", "%c %c %c %c", &a2, &b2, &c2,
  //  &d2); printf("orig - %d -%c- -%c- -%c- -%c-\nmy   - %d -%c- -%c- -%c-
  //  -%c-\n", res1, a1, b1, c1, d1, res2, a2, b2, c2, d2);

  //  r1 = sscanf("123 amogus   q", "%d%9s %c", &d1, s1, &c1);
  //  r2 = s21_sscanf("123 amogus   q", "%d%9s %c", &d2, s2, &c2);
  //  printf("orig - %d -%d- -%s- -%c-\nmy   - %d -%d- -%s- -%c-\n", r1, d1, s1,
  //  c1, r2, d2, s2, c2);

  // v
  //   printf("orig - %d %i %i %i\nmy   - %d %i %i %i\n", r1, nmbX1, nmbO1,
  //   nmbD1, r2, nmbX2, nmbO2, nmbD2);
  //
  //   printf("orig - %d %ld\nmy   - %d %ld\n", r1, x1, r2, x2);

  //  printf("orig - %d %.20lf %.20lf\nmy   - %d %.20lf %.20lf\n", r1, fl1,
  //  dbl1, r2, fl2, dbl2);

  //  printf("orig - %d %.20lf\nmy   - %d %.20lf\n", r1, dbl1, r2, dbl2);

  //  printf("orig - %d -%e- -%g-\nmy   - %d -%e- -%g-\n", r1, e1, g1, r2, e2,
  //  g2);

  //  short int i7, i8, i9, i10, i11, i12;

  //  int i1 = -1, i2 = -1, i3 = 0, i4 = 0, i5 = 0, i6 = 0;
  //  r1 = sscanf("0x9 -0xa2      0xBa1", "%*i%5i%i", &i1, &i3);
  //  r2 = s21_sscanf("0x9 -0xa2      0xBa1", "%*i%5i%i", &i2, &i4);
  //  printf("orig - %d %d %d\nmy   - %d %d %d\n", r1, i1, i3, r2, i2, i4);

  //  printf("orig - %d %hi %hi %hi\nmy   - %d %hi %hi %hi\n", r1, i7, i9, i11,
  //  r2, i8, i10, i12);

  //  float f1 = 0, f2 = 0;
  //
  //  r1 = sscanf("12e-3", "%f", &f1);
  //  r2 = s21_sscanf("12e-3", "%f", &f2);
  //  printf("orig - %d %f\nmy - %d %f\n", r1, f1, r2, f2);

  //  printf("orig - %d %s %d %s\nmy - %d %s %d %s\n", res1, str3, a2, str4,
  //  res2, str1, a1, str2);

  //  r1 = sscanf("-1x123", "%u", &u1);
  //  r2 = s21_sscanf("-1x123", "%u", &u2);
  //  printf("orig - %d %u\nmy - %d %u\n", r1, u1, r2, u2);

  //  printf("orig - %d %e\nmy - %d %e\n", r1, e1, r2, e2);
  //  printf("orig - %d %d %d\nmy - %d %d %d\n", r1, d3, d4, r2, d1, d2);
}
