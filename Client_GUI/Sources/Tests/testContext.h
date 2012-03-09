#ifndef TESTCONTEXT_H
#define TESTCONTEXT_H

#include <QObject>

class TestContext
{
public:

    TestContext( unsigned int (*pGetScore)(unsigned int*, void(*pFunc)(int)),void (*pSetPercent)(int))
    {
        pGetTestScore = pGetScore;
        pSetPercentDone = pSetPercent;
        score = 0;
    }
    unsigned int getTestScore(){return score;}
    unsigned int getErrorCode(){return errorCode;}
    void runTest()
    {
        errorCode = pGetTestScore(&score,pSetPercentDone);
        if(errorCode)
        {
            score = 0;
        }
    }

private:

    unsigned (*pGetTestScore)(unsigned int*,void(*pFunc)(int));
    void (*pSetPercentDone)(int);
    unsigned int score;
    unsigned int errorCode;
};

#endif // TESTCONTEXT_H
