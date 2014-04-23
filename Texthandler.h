//
//  Texthandler.h
//  DVHAnalysis
//
//  Created by 伊藤 拓也 on 2014/04/23.
//  Copyright (c) 2014年 伊藤 拓也. All rights reserved.
//

#ifndef __DVHAnalysis__Texthandler__
#define __DVHAnalysis__Texthandler__

#include <iostream>
#include <fstream>

#endif /* defined(__DVHAnalysis__Texthandler__) */

using namespace std;

class Texthandler
{
private:
    std::string textFileName;
    int rowNum=0;
    ifstream inputStream;
public:
    void readTextFile(string fileName);
    void getRowNum();
    
};