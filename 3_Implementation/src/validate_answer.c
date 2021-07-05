/**
 * @file validate_answer.c
 * @author Manikanta Suri (manikanta.suri@ltts.com)
 * @brief Function which validates answer provided by the user
 * @version 0.1
 * @date 2021-07-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<stdio.h>
#include "MQuiz.h"
code_t validate_answer(math_quiz* m_quiz, int ques, int i)
{
    /**
     * @brief Check for right answer/wrong answer entered by the user
     * 
     */
    if((m_quiz->user_answers[i])==(m_quiz->answer[ques]))
    {
    m_quiz->score++;
    return CORRECT_ANSWER;
    }
    else
    return WRONG_ANSWER;
}