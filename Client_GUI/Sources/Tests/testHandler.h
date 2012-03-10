//      Name: testHandler.h
//
//      Description: class that gives an interface to run test
//
//      Copyright 2012 Vitaliy Sergienko <visergienko@ukr.net>
//
//      This program is free software; you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation; either version 2 of the License, or
//      (at your option) any later version.
//
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//
//      You should have received a copy of the GNU General Public License
//      along with this program; if not, write to the Free Software
//      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
//      MA 02110-1301, USA.
//

#ifndef TESTHANDLER_H
#define TESTHANDLER_H

#include <QObject>
#include <map>
#include <QString>

using namespace std;

class TestHandler
{
public:

    TestHandler(void (*pSetPercent)(int));
    unsigned int getTestScore();
    unsigned int getErrorCode(){return errorCode;}
    QString getTestName();
    void addTest(QString s, unsigned int (*pGetScore)(unsigned int*, void(*pFunc)(int)));
    bool runTest();
    bool nextTest();

private:

    map<QString, unsigned (*)(unsigned int*,void(*)(int))> testMap;
    map<QString, unsigned (*)(unsigned int*,void(*)(int))>::iterator testIter;
    map<QString, unsigned int> scoreMap;
    map<QString, unsigned int>::iterator scoreIter;
    void (*pSetPercentDone)(int);
    unsigned int errorCode;
};

#endif // TESTHANDLER_H
