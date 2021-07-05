/**
 * @file add_quiz_formula.c
 * @author Manikanta Suri (manikanta.suri@ltts.com)
 * @brief Function which add quiz question formula/hints
 * @version 0.1
 * @date 2021-07-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "MQuiz.h"

code_t add_quiz_formula(math_quiz *m_quiz)
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
         * @brief Add quiz formulas/hints
         * 
         */
    strcpy(m_quiz->formulae[0],"Apply Bodmas rule");
    strcpy(m_quiz->formulae[1],"888 + 88 + 8 + 8 + 8");
    strcpy(m_quiz->formulae[2],"100*3/5");
    strcpy(m_quiz->formulae[3],"Area of circle = pi*radius*radius");
    strcpy(m_quiz->formulae[4],"i^2=-1, i^4=1");
    strcpy(m_quiz->formulae[5],"Actual value of digit of the number");
    strcpy(m_quiz->formulae[6],"Use GP Series");
    strcpy(m_quiz->formulae[7],"Use HP Series");
    strcpy(m_quiz->formulae[8],"Use AGP Series");
    strcpy(m_quiz->formulae[9],"Use AP Series");
    strcpy(m_quiz->formulae[10],"Surface area = 4*pi*radius*radius");
    strcpy(m_quiz->formulae[11],"Distance=speed*time");
    strcpy(m_quiz->formulae[12],"LCM*HCF=Num1*Num2");
    strcpy(m_quiz->formulae[13],"Odd days=No.of days mod 7");
    strcpy(m_quiz->formulae[14],"No Hint Available");
    strcpy(m_quiz->formulae[15],"RRR=Runs/Overs");
    strcpy(m_quiz->formulae[16],"log 10=1, log 100=2");
    strcpy(m_quiz->formulae[17],"SI=amount*time*interest/100");
    strcpy(m_quiz->formulae[18],"Loss= CP-SP");
    strcpy(m_quiz->formulae[19],"Middle digit=Last+first digits");
    strcpy(m_quiz->formulae[20],"No Hint Available");
    strcpy(m_quiz->formulae[21],"No Hint Available");
    strcpy(m_quiz->formulae[22],"CI=(P(1+(R/100))^t)-P");
    strcpy(m_quiz->formulae[23],"Largest Rectangle =Square");
    strcpy(m_quiz->formulae[24],"No Hint Available");
    strcpy(m_quiz->formulae[25],"Use Ratio and Proportions");
    strcpy(m_quiz->formulae[26],"Probability= Required/Total");
    strcpy(m_quiz->formulae[27],"Distance=speed*time");
    strcpy(m_quiz->formulae[28],"No Hint available");
    strcpy(m_quiz->formulae[29],"Average=Runs/(Innings-Notouts]");
    return SUCESS;
    }
}