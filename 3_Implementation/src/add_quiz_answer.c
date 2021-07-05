/**
 * @file add_quiz_answer.c
 * @author Manikanta Suri (manikanta.suri@ltts.com)
 * @brief Fumction which adds the quiz questions
 * @version 0.1
 * @date 2021-07-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "MQuiz.h"
code_t add_quiz_answer(math_quiz *m_quiz)
{
    /**
     * @brief Check for System Error
     * 
     */
    if(m_quiz==NULL)
    return SYSTEM_ERROR;
    else
    {
        /**
         * @brief Add quiz question answers
         * 
         */
    m_quiz->answer[0]=9;
    m_quiz->answer[1]=5;
    m_quiz->answer[2]=60;
    m_quiz->answer[3]=77;
    m_quiz->answer[4]=-1;
    m_quiz->answer[5]=10000;
    m_quiz->answer[6]=81;
    m_quiz->answer[7]=1;
    m_quiz->answer[8]=80;
    m_quiz->answer[9]=63;
    m_quiz->answer[10]=3850;
    m_quiz->answer[11]=375;
    m_quiz->answer[12]=350;
    m_quiz->answer[13]=3;
    m_quiz->answer[14]=9;
    m_quiz->answer[15]=7;
    m_quiz->answer[16]=20;
    m_quiz->answer[17]=14;
    m_quiz->answer[18]=25;
    m_quiz->answer[19]=671;
    m_quiz->answer[20]=130;
    m_quiz->answer[21]=44;
    m_quiz->answer[22]=7;
    m_quiz->answer[23]=144;
    m_quiz->answer[24]=14;
    m_quiz->answer[25]=24;
    m_quiz->answer[26]=42;
    m_quiz->answer[27]=134;
    m_quiz->answer[28]=6;
    m_quiz->answer[29]=35;
    return SUCESS;
    }
}