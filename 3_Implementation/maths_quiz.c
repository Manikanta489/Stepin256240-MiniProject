/**
 * @file math_quiz.c
 * @author Manikanta Suri (manikanta.suri@ltts.com)
 * @brief Function Which Implements Math Quiz
 * @version 0.1
 * @date 2021-07-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<stdio.h>
#include "MQuiz.h"
#include<time.h>
int main()
{
    math_quiz* contestant;
    code_t code;
    /**
     * @brief Allocate memory for the contestant
     * 
     */
    contestant=(math_quiz*)malloc(sizeof(math_quiz));
    for(int i=0;i<30;i++)
    {
    contestant->question[i]=(char*)malloc(75*sizeof(char));
    contestant->formulae[i]=(char*)malloc(35*sizeof(char));
    }
    printf("*****************************************************************************\n\n");
    printf("                     WELCOME TO MATH QUIZ\n\n");
    printf("            *******************************************\n");
    printf("                             RULES\n\n");
    printf("    1. There will two options 5 questions per set or 10 questions per set\n");
    printf("    2. The questions will be displayed and player has to type the answer\n");        
    printf("    3. Please enter the rounded off answer\n");
    printf("    4. If the precision is not followed it leads to wrong answer\n");
    printf("    5. Each correct answer is awarded with 1 point\n");
    printf("    6. No negative mark for wrong anser\n");
    printf("    7. Player cannot quit the game once started\n");
    printf("    8. The score will be displayed at the completion of all questions\n\n");
    printf("*****************************************************************************\n");    
    printf("Enter the number of questions (5/10):\n");
    scanf("%d", &(contestant->no_of_questions));
    quiz_ptr[0]=check_question_number_entered;
    quiz_ptr[1]=add_quiz_question;
    quiz_ptr[2]=add_quiz_answer;
    quiz_ptr[3]=add_quiz_formula;
    /**
     * @brief Add questions, answers, formulas for quiz 
     * 
     */
    for(int k=0;k<4;k++)
    {
    /**
     * @brief Check for proper input and proper integration of questions, answers and hints
     * 
     */
    code=quiz_ptr[k](contestant);
    if(code==1)
    {
    printf("Invalid Question Numbers Entered\n");
    exit(0);
    }
    if(code==2)
    {
    printf("System Error, Please Restart in few minutes\n");
    exit(0);
    }
    }
    /**
     * @brief Quiz begins here
     * 
     */
    int question_number;
    srand(time(0));
    contestant->score=0;
    for(int i = 0; i<(contestant->no_of_questions); i++)
    {
    question_number=rand()%30;
    /**
     * @brief Display question and get answer from user
     * 
     */
    printf("%s\n",contestant->question[question_number]);
    scanf("%d", &(contestant->user_answers[i]));
    /**
     * @brief Validate answer provided by the user
     * 
     */
    code=validate_answer(contestant,question_number,i);
    if(code==4)
    {
        printf("Wrong Answer\n");
        printf("Formula/Hint: %s\n",contestant->formulae[question_number]);
    }
    }
    /**
     * @brief Display final score attained by the user
     * 
     */
    printf("Final Score: %d\n",contestant->score);
    for(int i=0;i<30;i++)
    {
        free(contestant->question[i]);
        free(contestant->formulae[i]);
    }
    free(contestant);
    return 0;
}