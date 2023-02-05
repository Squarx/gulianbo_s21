//
// Created by DimasX on 02.01.2023.
//

#include "../Smart_calc.h"
#include <math.h>
void diff_calc(double mortgage, double percent, int month);
enum test {
  DAY = 1,
  MONTH = 3,
  YEAR = 4,
};
int main(void) {
  diff_calc(10000, 10, 12);
  /*
  double deposit = 0;
  int month = 0;
  double percent = 0;
  int kapitalization = 0;
  int period_viplat = 0;
  int popolnenie_or_cn9tie = 0;
  int period_plus_min = 0;
  double sum_popolnenie = 0, sum_cn9tie = 0;
  double RES = 0;
// init
  kapitalization = 1;
  popolnenie_or_cn9tie = MONTH;
  sum_popolnenie = 10000;
  sum_cn9tie = 3000000;
  double key_rate = 20;
  key_rate /= 100;
  month = 12;
  period_viplat = MONTH;
  deposit = 700000;
  percent = 8;
  percent /= 100;
  double nalog = 0;
  double start = deposit;
  for (int i = 0; deposit > 0 && i < month * 31; i++) {
    if (kapitalization == 0) {
      if (period_viplat == YEAR && i % (12 * 31) == 0) {
        RES += deposit * percent;
      }
      if (period_viplat == MONTH && i % (31) == 0) {
        RES += deposit * percent / 12;
      }
      if (period_viplat == DAY) {
        RES += deposit * percent / 12 / 31;
      }
    } else {
      if (period_viplat == YEAR && i % (12 * 31) == 0) {
        deposit += deposit * percent;
      }
      if (period_viplat == MONTH && i % (31) == 0) {
        deposit += deposit * percent / 12;
      }
      if (period_viplat == DAY) {
        deposit += deposit * percent / 12 / 31;
      }
    }
    if (popolnenie_or_cn9tie == DAY && i != 0 ) {
      if (deposit + (sum_popolnenie - sum_cn9tie) > 0) {
        deposit += (sum_popolnenie - sum_cn9tie);
      } else {
        deposit = 0;
        nalog = 0;
        RES = 0;
      }
    }
    if (popolnenie_or_cn9tie == MONTH && i != 0 && i % (31) == 0) {
      if (deposit + (sum_popolnenie - sum_cn9tie) > 0) {
        deposit += (sum_popolnenie - sum_cn9tie);
      } else {
        deposit = 0;
        nalog = 0;
        RES = 0;
      }
    }
    if (popolnenie_or_cn9tie == YEAR && i != 0 && i % (12 * 31) == 0) {
      if (deposit + (sum_popolnenie - sum_cn9tie) > 0) {
        deposit += (sum_popolnenie - sum_cn9tie);
      } else {
        deposit = 0;
        nalog = 0;
        RES = 0;
      }
    }
  }
  // taxes
  double cmp_sum = key_rate * 1e6;
  if (kapitalization == 1) {
    if ((deposit - start) > cmp_sum) {
      nalog = (deposit - start) * 0.13;
      deposit -= nalog;
    }
  } else {
    if (RES > cmp_sum) {
      nalog = RES * 0.13;
      RES -= nalog;
    }
  }
  printf("Na4islennii %f = (without nalog = %f) Sum nalog = %f, Deosit = %f Ne oblagaema9 summa = %f\n",
         kapitalization ? (deposit - start) : RES, kapitalization ? (deposit - start + nalog) : RES + nalog,
         nalog,
         deposit, cmp_sum);
  */
  return 0;
}

void diff_calc(double mortgage, double percent, int month) {
  percent = percent / 100 / 12.;
  double ostatok = mortgage, min = mortgage, max = 0, viplata = 0;
  double stable = mortgage / month;
  double all = 0;
  all = viplata;
  printf("stable  = %f\n", stable);
  printf("SUMMA  = %f, viplata %f OSTAOK = %f, \n", viplata + stable, viplata, ostatok);
  while (month > 0) {
    viplata = ostatok * percent;
    ostatok = ostatok - stable;

    all += viplata;
    if (viplata > max) max = viplata;
    if (viplata < min) min = viplata;
    month--;
    printf("SUMMA = %f OSTAOK = %f, viplata %f\n", viplata + stable, ostatok, viplata);
  }
  printf("min = %f max = %f  all  = %f\n", min, max, all);
}



