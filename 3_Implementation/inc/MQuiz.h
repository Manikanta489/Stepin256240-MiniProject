/**
 * @file MQuiz.h
 * @author Manikanta Suri (manikanta.suri@ltts.com)
 * @brief Header File for Math Quiz
 * @version 0.1
 * @date 2021-07-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/**
 * Header Gaurds
 */
#ifndef __HEADER_H__
#define __HEADER_H__
/**
 * Include header files
 */ 
#include<stdlib.h>
#include<string.h>
#include<stddef.h>
/**
 * @brief Structure which holds the quiz questions,answers,hints/formulas for answer, 
 * user answers,user score,user choosed number of questions
 * 
 */
typedef struct
{
  char* question[30];
  int answer[30];
  char* formulae[30];
  int user_answers[10];
  int score;
  unsigned int no_of_questions;
}math_quiz;
/**
 * @brief Enum which consists of implementation Codes
 * SUCESS (VALID INPUTS)=0
 * INVALID INPUT BY USER =1
 * SYSTEM ERROR=2
 * CORRECT ANSWER=3
 * WRONG ANSWER=4
 */
typedef enum
{
  SUCESS,
  INVALID_INPUT,
  SYSTEM_ERROR,
  CORRECT_ANSWER,
  WRONG_ANSWER,
}code_t;
/**
 * @brief Function which displays rules for Math Quiz
 * 
 */
void display_rules(void);

/**
 * @brief Function which checks whether the user entered valid number of questions
 * 
 * @return code
 */
code_t check_question_number_entered(math_quiz*);
/**
 * @brief Function which adds quiz questions
 * 
 * @return  code
 */
code_t add_quiz_question(math_quiz*);
/**
 * @brief Function whicn add quiz answers
 * 
 * @return  code
 */
code_t add_quiz_answer(math_quiz*);
/**
 * @brief Function which add quiz question formula/hints
 * 
 * @return  code
 */
code_t add_quiz_formula(math_quiz*);
/**
 * @brief Array of Function pointer holding 4 functions 
 * 
 */
code_t (*quiz_ptr[4])(math_quiz*);
/**
 * @brief Function which validates answer entered by the user
 * 
 * @return code_t 
 */
code_t validate_answer(math_quiz*, int, int);
#endif