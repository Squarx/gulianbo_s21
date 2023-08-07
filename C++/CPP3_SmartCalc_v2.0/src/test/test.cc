//
// Created by DimasX on 25.07.2023.
//
#include <gtest/gtest.h>

#include <stdexcept>

#include "../model/calcmodel.h"

class Test_calc {
 public:
  std::string str_1 =
      "15/(7-(1+1))*3-(2+(1+1))*15/(7-(200+1))*3-(2+(1+1))*(15/"
      "(7-(1+1))*3-(2+(1+1))+15/(7-(1+1))*3-(2+(1+1)))";
  std::string str_2 = "2 - 2 - 2 - 2 - 2 - 2 - 2 - 2 - 2 - 2";
  std::string str_3 = "2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2";
  std::string str_4 = "2 / 2 / 2 / 2 / 2 / 2 / 2 / 2 / 2 / 2";
  std::string str_5 = "sin(0.7) + sin(0.7) + sin(0.7) + sin(0.7) + sin(0.7)";
  std::string str_6 = "cos(0.7) + cos(0.7) + cos(0.7) + cos(0.7) + cos(0.7)";
  std::string str_7 = "tan(0.7) + tan(0.7) + tan(0.7) + tan(0.7) + tan(0.7)";
  std::string str_9 =
      "acos(0.7) + acos(0.7) + acos(0.7) + acos(0.7) + acos(0.7)";
  std::string str_10 =
      "asin(0.7) + asin(0.7) + asin(0.7) + asin(0.7) + asin(0.7)";
  std::string str_11 =
      "atan(0.7) + atan(0.7) + atan(0.7) + atan(0.7) + atan(0.7)";
  std::string str_12 =
      "(7 mod 7) + (7 mod 6) + (7 mod 6) + (7 mod 5) + (7 mod 4)";
  std::string str_12_2 = "0 mod 0";
  std::string str_13 =
      "log(7 mod 7 + 1) + log(7 mod 6) + log(7 mod 6) + log(7 mod 5) + log(7 "
      "mod 4)";
  std::string str_14 = "sqrt(4) + sqrt(7) + sqrt(0.99) + sqrt(81) + sqrt(100)";
  std::string str_15 = "7 ^ 2 + 7 ^ 5 + 7 ^ 4 + 7 ^ 3 + 7 ^ 7";
  std::string str_16 = "ln(7) + ln(7) + ln(7) + ln(7) + ln(7)";
  std::string str_17 = "-7";
  std::string str_18 = "2^2^3";
  std::string str_19 = "cos(200^2)^2";
  std::string str_20 = "3 mod 2";
  std::string str_21 = "-2";
  std::string str_22 = "+2";
  std::string str_23 = "2^(1+1)";
  std::string str_24 = "cos(0)";
  std::string str_25 = "sin(0)";
  std::string str_26 = "sin(0)";
  std::string str_27 = "tan(1)";
  std::string str_28 = "sqrt(4)";
  std::string str_29 = "log(2.71828)";
  std::string str_30 = "log(10)";
  std::string str_31 = "(2 + 3)(2 + 3)";
  std::string str_32 = "(2 + 3)   (2 + 3)";
  std::string str_33 = "1 + 2 * 3 * 4(2 + 3)";
  std::string str_34 = "cos 10";
  std::string str_35 = "---------1";
  std::string str_36 = "2++2";
  std::string str_37 = "10+-2";
  std::string str_38 = "10-+2";
  std::string str_39 = "2*---------1";
  std::string str_40 = "2*(--2^--3)";
  std::string str_41 = "6 mod --4";
  std::string str_42 = "3/---3";
  std::string str_43 = "ln(1.123E-3^-3 mod -1e2)";
  std::string str_44 =
      "((((8 - 2 * 4) ^ 2 + 15) * 3 - 5) / 2) + (4 mod 3) * (2 ^ 3) - (10 / 5) "
      "* (-2 + 1) + cos(0) - sin(30) * tan(45) + acos(1/23.2^2) * "
      "asin(atan(log(123.2^2/6)) * asin(123.123^-2)) / atan(1) + sqrt(16) - "
      "ln(1) + log(100) + sin(45) + cos(30) * tan(60) - acos(0.5) * asin(0.25) "
      "/ atan(1) + sqrt(25) - ln(1) + log(100) + (tan(90) + sin(60) * cos(30)) "
      "/ (log(100) - sqrt(16)) + ((asin(0.5) ^ 2) + (acos(0.3) * atan(1.2))) / "
      "(tan(45) + sin(30))";
  std::string str_45 = "((((9 + 3) ^ 2) mod 7) + 4 * (8 - 2)) ^ 3 - 1";
  std::string str_46 = "((((8 * 2) - (6 ^ 2)) mod 5) + 3 * 4) / (7 + 1)";
  std::string str_47 = "((6 * 2 ^ 3) + 7 mod 5) - ((10 / 2) ^ 2) + 3";
  std::string str_48 = "(((-3 + 7) * 5) ^ 2 + 6 / 2) mod 4";
  std::string str_49 = "(((9 - 2) ^ 3) mod 5 * (7 - 4)) + 12 / 4";
  std::string str_50 =
      "sin(45) + cos(30) * tan(60) - acos(0.5) * asin(0.25) / atan(1) + "
      "sqrt(25) - ln(1) + log(100)";
  std::string str_51 = "(tan(90) + sin(60) * cos(30)) / (log(100) - sqrt(16))";
  std::string str_52 =
      "((asin(0.5) ^ 2) + (acos(0.3) * atan(1.2))) / (tan(45) + sin(30))";
  std::string str_53 =
      "((((8 - 2 * 4) ^ 2 + 15) * 3 - 5) / 2) + (4 mod 3) * (2 ^ 3) - (10 / 5) "
      "* (-2 + 1)";
  std::string str_54 = "(((7 + 3) * (6 - 2)) ^ 3 mod 5) / 4";
  std::string str_55 =
      "((((8 - 2 * 4) ^ 2 + 15) * 3 - 5) / 2) + (4 mod 3.3) * (2 ^ 3) - (10 / "
      "5) * (-2 + 1) + cos(0) - sin(30) * tan(45) + acos(1/23.2^2) * "
      "asin(atan(log(123.2^2/6)) * asin(123.123^-2)) / atan(1) + sqrt(16) - "
      "ln(1) + log(100)";
  std::string str_56 = "(7 + 2) * (10 - 3) ^ 2 - 6 mod 6";
};

class TestIncorrect {
 public:
  std::string str_2 = "1+";
  std::string str_3 = "sin(^)";
  std::string str_4 = "sin(1-)";
  std::string str_5 = "sin(0)-";
  std::string str_6 = "sin(1+0()))";
  std::string str_7 = "12 mod ";
  std::string str_8 = "1-----1-";
  std::string str_9 = "1-^2";
  std::string str_10 = "1.1.1 + 2";
  std::string str_11 =
      "((((8 - 2 * 4) ^ 2 + 15) * 3 - 5) / 2) + (4 mod 3.3) * (2 ^ 3) - (10 / "
      "5) * (-2 + 1) + cos(0) - sin(30) * tan(45) + acos(1/23.2^2) * "
      "asin(atan(log(123.2^2/6))) * asin(123.123^-2)) / atan(1) + sqrt(16) - "
      "ln(1) + log(100)";
  std::string str_12 = "x+";
  std::string str_14 = "sin(2^((2/3)*(x * 3(cos(sin(sqrt(1/)))))))";
  std::string str_15 = "sin(x-)";
  std::string str_16 = "sin(x)-";
  std::string str_17 = "sin(x+x()))";
  std::string str_18 = "x mod ";
  std::string str_19 = "1-----x-";
  std::string str_20 = "x-^x";
  std::string str_21 = "1.1.1 + x";
  std::string str_22 = "x. + 2";
};

class TestXvalue {
 public:
  long double var_replace{};
  std::string str_1 = "x + x + x + x + x + x + x + x + x + x";
  std::string str_2 = "x - x - x - x - x - x - x - x - x - x";
  std::string str_3 = "x * x * x * x * x * x * x * x * x * x";
  std::string str_4 = "x / x / x / x / x / x / x / x / x / x";
  std::string str_5 = "sin(x) + sin(x) + sin(x) + sin(x) + sin(x)";
  std::string str_6 = "cos(x) + cos(x) + cos(x) + cos(x) + cos(x)";
  std::string str_7 = "tan(x) + tan(x) + tan(x) + tan(x) + tan(x)";
  std::string str_12 =
      "(x mod x) + (x mod 6) + (x mod 6) + (x mod 5) + (x mod 4)";
  std::string str_13 =
      "log(x mod x + 1) + log(x mod 6) + log(x mod 6) + log(x mod 5) + log(x "
      "mod 4)";
  std::string str_14 = "sqrt(4) + sqrt(x) + sqrt(0.99) + sqrt(81) + sqrt(100)";
  std::string str_15 = "x ^ 2 + x ^ 5 + x ^ 4 + x ^ 3 + x ^ x";
};

class TestSmartMult {
 public:
  long double var_replace{};
  std::string str_1 = "cos(10)sin(10)";
  std::string str_2 = "cos(-10)sin(10)";
  std::string str_3 = "cos(10)sin(10)";
  std::string str_4 = "cos(-10)sin(-10)";
  std::string str_5 = "2sin(-10)";
  std::string str_6 = "2sin(-10)*4cos(sqrt(log(ln(200000))))";
  std::string str_7 = "(-10)4";
  std::string str_8 = "10log(100)cos(20)sin(30)xXx";
  std::string str_9 = "(-10)(4)";
  std::string str_10 = "1/3sinX+6^2^3";
};

TEST(CalcmodelTest, SmartMulti) {
  s21::CalcModel m;
  TestSmartMult tester;

  auto res = m.GetResult(tester.str_1);

  ASSERT_NEAR(res, 0.4564726253638138, 1e-6);

  res = m.GetResult(tester.str_2);

  ASSERT_NEAR(res, 0.4564726253638138, 1e-6);

  res = m.GetResult(tester.str_3);

  ASSERT_NEAR(res, 0.4564726253638138, 1e-6);

  res = m.GetResult(tester.str_4);

  ASSERT_NEAR(res, -0.4564726253638138, 1e-6);

  res = m.GetResult(tester.str_5);

  ASSERT_NEAR(res, 1.0880422217787395, 1e-6);

  res = m.GetResult(tester.str_6);

  ASSERT_NEAR(res, 2.194181048, 1e-6);

  EXPECT_THROW(m.GetResult(tester.str_7), std::exception);

  tester.var_replace = 5;
  res = m.GetResult(tester.str_8, tester.var_replace);

  ASSERT_NEAR(res, -1007.994956, 1e-6);

  res = m.GetResult(tester.str_9, tester.var_replace);

  ASSERT_NEAR(res, -40, 1e-6);

  res = m.GetResult(tester.str_10, tester.var_replace);

  ASSERT_NEAR(res, -0.3196414 + 1679616, 1e-6);
}

TEST(CalcmodelTest, TestXvalue) {
  s21::CalcModel m;
  TestXvalue tester;
  tester.var_replace = 2;
  auto res = m.GetResult(tester.str_1, tester.var_replace);

  ASSERT_EQ(res, 20);

  res = m.GetResult(tester.str_2, tester.var_replace);

  ASSERT_EQ(res, -16);

  res = m.GetResult(tester.str_3, tester.var_replace);

  ASSERT_EQ(res, 1024);

  res = m.GetResult(tester.str_4, tester.var_replace);

  ASSERT_NEAR(res, 3.90625e-3, 1e-6);

  tester.var_replace = 7;
  res = m.GetResult(tester.str_5, tester.var_replace);

  ASSERT_NEAR(res, 3.28493299, 1e-6);

  res = m.GetResult(tester.str_6, tester.var_replace);

  ASSERT_NEAR(res, 3.76951127, 1e-6);

  res = m.GetResult(tester.str_7, tester.var_replace);

  ASSERT_NEAR(res, 4.35724, 1e-6);

  res = m.GetResult(tester.str_12, tester.var_replace);

  ASSERT_EQ(res, 7);

  res = m.GetResult(tester.str_13, tester.var_replace);

  ASSERT_NEAR(res, 0.7781512503836436, 1e-6);

  res = m.GetResult(tester.str_14, tester.var_replace);

  ASSERT_NEAR(res, 24.6407387, 1e-6);

  res = m.GetResult(tester.str_15, tester.var_replace);

  ASSERT_EQ(res, 843143);
}

TEST(CalcmodelTest, TestIncorrectInputStrings) {
  s21::CalcModel m;
  TestIncorrect tester;
  EXPECT_THROW(m.GetResult(tester.str_2), std::exception);
  EXPECT_THROW(m.GetResult(tester.str_3), std::exception);
  EXPECT_THROW(m.GetResult(tester.str_4), std::exception);
  EXPECT_THROW(m.GetResult(tester.str_5), std::exception);
  EXPECT_THROW(m.GetResult(tester.str_6), std::exception);
  EXPECT_THROW(m.GetResult(tester.str_7), std::exception);
  EXPECT_THROW(m.GetResult(tester.str_8), std::exception);
  EXPECT_THROW(m.GetResult(tester.str_9), std::exception);
  EXPECT_THROW(m.GetResult(tester.str_10), std::exception);
  EXPECT_THROW(m.GetResult(tester.str_11), std::exception);
  EXPECT_THROW(m.GetResult(tester.str_12), std::exception);
  EXPECT_THROW(m.GetResult(tester.str_14), std::exception);
  EXPECT_THROW(m.GetResult(tester.str_15), std::exception);
  EXPECT_THROW(m.GetResult(tester.str_16), std::exception);
  EXPECT_THROW(m.GetResult(tester.str_17), std::exception);
  EXPECT_THROW(m.GetResult(tester.str_18), std::exception);
  EXPECT_THROW(m.GetResult(tester.str_19), std::exception);
  EXPECT_THROW(m.GetResult(tester.str_20), std::exception);
  EXPECT_THROW(m.GetResult(tester.str_21), std::exception);
  EXPECT_THROW(m.GetResult(tester.str_22), std::exception);
}

TEST(CalcmodelTest, TestAllNormalStrings) {
  s21::CalcModel m;
  Test_calc tester;
  auto res = m.GetResult(tester.str_1);
  ASSERT_NEAR(res, -30.072164948453608L, 1e-6);

  res = m.GetResult(tester.str_2);
  ASSERT_EQ(res, -16L);

  res = m.GetResult(tester.str_3);
  ASSERT_EQ(res, 1024L);

  res = m.GetResult(tester.str_4);
  ASSERT_NEAR(res, 0.00390625, 1e-6);

  res = m.GetResult(tester.str_5);
  ASSERT_NEAR(res, 3.22108844, 1e-6);

  res = m.GetResult(tester.str_6);
  ASSERT_NEAR(res, 3.82421094, 1e-6);

  res = m.GetResult(tester.str_7);
  ASSERT_NEAR(res, 4.2114419, 1e-6);

  res = m.GetResult(tester.str_9);
  ASSERT_NEAR(res, 3.976994151, 1e-6);

  res = m.GetResult(tester.str_10);
  ASSERT_NEAR(res, 3.876987483, 1e-6);

  res = m.GetResult(tester.str_11);
  ASSERT_NEAR(res, 3.053629822, 1e-6);

  res = m.GetResult(tester.str_12);
  ASSERT_EQ(res, 7L);

  res = m.GetResult(tester.str_12_2);
  ASSERT_TRUE(std::isnan(res));

  res = m.GetResult(tester.str_13);
  ASSERT_NEAR(res, 0.7781512503836436, 1e-6);

  res = m.GetResult(tester.str_14);
  ASSERT_NEAR(res, 24.6407387, 1e-6);

  res = m.GetResult(tester.str_15);
  ASSERT_EQ(res, 843143L);

  res = m.GetResult(tester.str_16);
  ASSERT_NEAR(res, 9.729550745, 1e-6);

  res = m.GetResult(tester.str_17);
  ASSERT_EQ(res, -7L);

  res = m.GetResult(tester.str_18);
  ASSERT_EQ(res, 256L);

  res = m.GetResult(tester.str_19);
  ASSERT_NEAR(res, 0.10406267813194549, 1e-6);

  res = m.GetResult(tester.str_20);
  ASSERT_EQ(res, 1L);

  res = m.GetResult(tester.str_21);
  ASSERT_EQ(res, -2L);

  res = m.GetResult(tester.str_22);
  ASSERT_EQ(res, 2L);

  res = m.GetResult(tester.str_23);
  ASSERT_EQ(res, 4L);

  res = m.GetResult(tester.str_24);
  ASSERT_EQ(res, 1L);

  res = m.GetResult(tester.str_25);
  ASSERT_EQ(res, 0L);

  res = m.GetResult(tester.str_26);
  ASSERT_EQ(res, 0L);

  res = m.GetResult(tester.str_27);
  ASSERT_NEAR(res, 1.557408, 1e-6);

  res = m.GetResult(tester.str_28);
  ASSERT_NEAR(res, 2L, 1e-6);

  res = m.GetResult(tester.str_29);
  ASSERT_NEAR(res, 0.434294, 1e-6);

  res = m.GetResult(tester.str_30);
  ASSERT_NEAR(res, 1L, 1e-6);

  res = m.GetResult(tester.str_31);
  ASSERT_EQ(res, 25L);

  res = m.GetResult(tester.str_32);
  ASSERT_EQ(res, 25L);

  res = m.GetResult(tester.str_33);
  ASSERT_EQ(res, 121L);

  res = m.GetResult(tester.str_34);
  ASSERT_NEAR(res, -0.839072, 1e-6);

  res = m.GetResult(tester.str_35);
  ASSERT_EQ(res, -1L);

  res = m.GetResult(tester.str_36);
  ASSERT_EQ(res, 4L);

  res = m.GetResult(tester.str_37);
  ASSERT_EQ(res, 8L);

  res = m.GetResult(tester.str_38);
  ASSERT_EQ(res, 8L);

  res = m.GetResult(tester.str_39);
  ASSERT_EQ(res, -2L);

  res = m.GetResult(tester.str_40);
  ASSERT_EQ(res, 16L);

  res = m.GetResult(tester.str_41);
  ASSERT_EQ(res, 2L);

  res = m.GetResult(tester.str_42);
  ASSERT_EQ(res, -1L);

  res = m.GetResult(tester.str_43);
  ASSERT_NEAR(res, 4.498866159, 1e-6);

  res = m.GetResult(tester.str_44);
  ASSERT_NEAR(res, 49.374741849295295, 1e-6);

  res = m.GetResult(tester.str_45);
  ASSERT_NEAR(res, 21951, 1e-6);

  res = m.GetResult(tester.str_46);
  ASSERT_NEAR(res, 1.5, 1e-6);

  res = m.GetResult(tester.str_47);
  ASSERT_NEAR(res, 28, 1e-6);

  res = m.GetResult(tester.str_48);
  ASSERT_NEAR(res, 3, 1e-6);

  res = m.GetResult(tester.str_49);
  ASSERT_NEAR(res, 16, 1e-6);

  res = m.GetResult(tester.str_50);
  ASSERT_NEAR(res, 7.5633632117622634, 1e-6);

  res = m.GetResult(tester.str_51);
  ASSERT_NEAR(res, 1.0211089462271227, 1e-6);

  res = m.GetResult(tester.str_52);
  ASSERT_NEAR(res, 2.189711247886146, 1e-6);

  res = m.GetResult(tester.str_53);
  ASSERT_NEAR(res, 30, 1e-6);

  res = m.GetResult(tester.str_54);
  ASSERT_NEAR(res, 0, 1e-6);

  res = m.GetResult(tester.str_55);
  ASSERT_NEAR(res, 36.200558443419763, 1e-6);

  res = m.GetResult(tester.str_56);
  ASSERT_NEAR(res, 441, 1e-6);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}