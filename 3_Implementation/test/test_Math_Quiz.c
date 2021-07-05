/**
 * @file test_Math_Quiz.c
 * @author Manikanta Suri (manikanta.suri@ltts.com)
 * @brief Function which tests the submodules in the Math quiz
 * @version 0.1
 * @date 2021-07-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include "MQuiz.h"
#include "unity.h"
#include "unity_internals.h"
#include<stddef.h>
math_quiz m1;
void setUp(){}
void tearDown(){}
/**
 * @brief Check for System error during entry of total question numbers
 * 
 */
void test_check_question_number_entered_null(void)
{
    TEST_ASSERT_EQUAL(2,check_question_number_entered(NULL));
}
/**
 * @brief Check for invalid total question numbers entered by user
 * 
 */
void test_check_question_number_entered_invalid(void)
{
    m1.no_of_questions=4;
    TEST_ASSERT_EQUAL(1,check_question_number_entered(&m1));
}
/**
 * @brief Check for valid total question numbers entered by the user
 * 
 */
void test_check_question_number_entered_valid(void)
{
    m1.no_of_questions=5;
    TEST_ASSERT_EQUAL(0,check_question_number_entered(&m1));
}
/**
 * @brief Check for system error during integration of quiz questions
 * 
 */
void test_add_quiz_question_null(void)
{
    TEST_ASSERT_EQUAL(2,add_quiz_question(NULL));
}
/**
 * @brief Check for system error during integration of quiz answers
 * 
 */
void test_add_quiz_answer_null(void)
{
    TEST_ASSERT_EQUAL(2,add_quiz_answer(NULL));
}
/**
 * @brief Check for system error during integration of quiz hints/formulas
 * 
 */
void test_add_quiz_formula_null(void)
{
    TEST_ASSERT_EQUAL(2,add_quiz_formula(NULL));
}
/**
 * @brief Check for correct integration of quiz questions
 * 
 */
void test_add_quiz_question_valid(void)
{
    for(int i=0;i<30;i++)
    m1.question[i]=(char*)malloc(75*sizeof(char));
    TEST_ASSERT_EQUAL(0,add_quiz_question(&m1));
}
/**
 * @brief Check for correct integration of quiz answers
 * 
 */
void test_add_quiz_answer_valid(void)
{
    TEST_ASSERT_EQUAL(0,add_quiz_answer(&m1));
}
/**
 * @brief Check for correct integration of quiz formulas/hints
 * 
 */
void test_add_quiz_formula_valid(void)
{
    for(int i=0;i<30;i++)
    m1.formulae[i]=(char*)malloc(35*sizeof(char));
    TEST_ASSERT_EQUAL(0,add_quiz_formula(&m1));
}
/**
 * @brief Test for correct answer provided by the user
 * 
 */
void test_correct_answer(void)
{
    int q=1;
    int i1=1;
    m1.user_answers[i1]=5;
    m1.answer[q]=5;
    TEST_ASSERT_EQUAL(3,validate_answer(&m1,q,i1));
}
/**
 * @brief Test for wrong answer provided by the user
 * 
 */
void test_wrong_answer(void)
{
    int q=1;
    int i1=1;
    m1.user_answers[i1]=5;
    m1.answer[q]=55;
    TEST_ASSERT_EQUAL(4,validate_answer(&m1,q,i1));
}
/**
 * @brief Test for score when user provides correct answer
 * 
 */
void test_score_correct_answer(void)
{
    int q=1;
    int i1=1;
    m1.user_answers[i1]=5;
    m1.answer[q]=5;
    m1.score=4;
    TEST_ASSERT_EQUAL(3,validate_answer(&m1,q,i1));
    TEST_ASSERT_EQUAL(5,m1.score);
}
/**
 * @brief Test for score when user provides wrong answer
 * 
 */
void test_score_wrong_answer(void)
{
    int q=1;
    int i1=1;
    m1.user_answers[i1]=5;
    m1.answer[q]=55;
    m1.score=4;
    TEST_ASSERT_EQUAL(4,validate_answer(&m1,q,i1));
    TEST_ASSERT_EQUAL(4,m1.score);
}
int main()
{
///Initiate the Unity Test Framework
UNITY_BEGIN();
/// Run test cases
RUN_TEST(test_check_question_number_entered_null);
RUN_TEST(test_check_question_number_entered_invalid);
RUN_TEST(test_check_question_number_entered_valid);
RUN_TEST(test_add_quiz_question_null);
RUN_TEST(test_add_quiz_answer_null);
RUN_TEST(test_add_quiz_formula_null);
RUN_TEST(test_add_quiz_question_valid);
RUN_TEST(test_add_quiz_answer_valid);
RUN_TEST(test_add_quiz_formula_valid);
RUN_TEST(test_correct_answer);
RUN_TEST(test_wrong_answer);
RUN_TEST(test_score_correct_answer);
RUN_TEST(test_score_wrong_answer);
/// Close the Unity Test Framework
UNITY_END();
return 0;
}
