//
//  Texthandler.cpp
//  DVHAnalysis
//
//  Created by 伊藤 拓也 on 2014/04/23.
//  Copyright (c) 2014年 伊藤 拓也. All rights reserved.
//

#include "Texthandler.h"

void Texthandler::readTextFile(string fileName){
    Texthandler::textFileName = fileName;
    Texthandler::inputStream.open(Texthandler::textFileName);   // 入力ファイルを開く
    string testText;
    getline(Texthandler::inputStream,testText);

    cout << testText;
}

void Texthandler::getRowNum(){
    std::cout << "Seikou!";
}

