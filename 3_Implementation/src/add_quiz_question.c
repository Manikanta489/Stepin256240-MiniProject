/**
 * @file add_quiz_question.c
 * @author Manikanta Suri (manikanta.suri@ltts.com)
 * @brief Function which adds quiz questions
 * @version 0.1
 * @date 2021-07-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "MQuiz.h"

code_t add_quiz_question(math_quiz *m_quiz)
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
         * @brief Add quiz questions
         * 
         */
    strcpy(m_quiz->question[0],"Which number is equivalent to 3^(4)÷3^(2)");
    strcpy(m_quiz->question[1],"Using only an addition, how many numbers you add and get the number 1000");
    strcpy(m_quiz->question[2],"What is three fifth of 100");
    strcpy(m_quiz->question[3],"Find area of half circle for radius 7?");
    strcpy(m_quiz->question[4],"i power 98 is?");
    strcpy(m_quiz->question[5],"Face value of 4 in 24786");
    strcpy(m_quiz->question[6],"Find the next number in series 1,-3,9,-27,");
    strcpy(m_quiz->question[7],"Find the next number in series 1/9,1/7,1/5,1/3,");
    strcpy(m_quiz->question[8],"Find the next number in series 1,4,12,32,");
    strcpy(m_quiz->question[9],"Find the next number in series 99,90,81,72");
    strcpy(m_quiz->question[10],"Surface area of sphere with radius 17.5");
    strcpy(m_quiz->question[11],"Find the distance travelled(m) by train running with 90km/h in 15s");
    strcpy(m_quiz->question[12],"LCM=70,HCF=50,Num1=10,Num2 =?");
    strcpy(m_quiz->question[13],"Odd days does a 8 consective years will have starting from 2001");
    strcpy(m_quiz->question[14],"Find square of average of first 5 numbers from 1");
    strcpy(m_quiz->question[15],"Find the RRR for a team chasing 350 in 50 overs");
    strcpy(m_quiz->question[16],"if log 2=0.30103, number of digits in 2^97?");
    strcpy(m_quiz->question[17],"SI on Amount Rs.50 for 4 years at 7% interest?");
    strcpy(m_quiz->question[18],"If the CP of 15 books is equal to the SP of 20 books,loss%=");
    strcpy(m_quiz->question[19],"Odd man in series 396, 462, 572, 427, 671, 264");
    strcpy(m_quiz->question[20],"Angle of hour and minute hand at 3:40");
    strcpy(m_quiz->question[21],"How many times are the hands of a clock at right angle in a day");
    strcpy(m_quiz->question[22],"CI on Amount Rs.50 for 4 years at 7% interest?");
    strcpy(m_quiz->question[23],"Area of largest rectangle with one side 12");
    strcpy(m_quiz->question[24],"log16384/log2?");
    strcpy(m_quiz->question[25],"The fourth proportional to 5, 8, 15?");
    strcpy(m_quiz->question[26],"Probabilty % of prime number in total score of 2 dice throw");
    strcpy(m_quiz->question[27],"Speed of bus(km/h) covering 67 km in 30 min");
    strcpy(m_quiz->question[28],"Smallest perfect number");
    strcpy(m_quiz->question[29],"Average of batsman, Runs =1400, Innings =72, Notouts=32");
    return SUCESS;
    }
}