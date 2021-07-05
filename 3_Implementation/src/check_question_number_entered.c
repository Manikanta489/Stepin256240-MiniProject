/**
 * @file check_question_number_entered.c
 * @author Manikanta Suri (manikanta.suri@ltts.com)
 * @brief Function which checks whether the user has given valid number of question numbers
 * @version 0.1
 * @date 2021-07-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "MQuiz.h"
code_t check_question_number_entered(math_quiz *m_quiz)
{
    /**
     * @brief Check for System Error
     * 
     */
    if(m_quiz==NULL)
    return SYSTEM_ERROR;
    /**
     * @brief Check for Invalid Input
     * 
     */
    else if(!(m_quiz->no_of_questions==5||m_quiz->no_of_questions==10))
    return INVALID_INPUT;
    else
    return SUCESS;
}