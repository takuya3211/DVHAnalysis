//
//  main.cpp
//  DVHAnalysis
//
//  Created by 伊藤 拓也 on 2014/04/22.
//  Copyright (c) 2014年 伊藤 拓也. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include "Texthandler.h"

//using namespace std;


void error(const char* p, const char* p2 = "")
{
    std::cerr << p << ' ' << p2 << '\n';
    std::exit(1);
}

int main()
{
    /*if (argc!=3) {
     error("Usage: CONVERT <input> <output>\n");
     return 1;
     }*/
    std::ifstream in;
    in.open("inputDVH.txt");   // 入力ファイルを開く
    if (!in) error("canot open input file");
    
    std::ofstream out;
    out.open("outputDVH.csv",std::ios::out);  // 出力ファイルを作成する
    
    if (!out) {
        error("Cannot open output file");
        return 1;
    }
    //std::ifstream ifs("inputDVH.txt");
    std::string str;
    int row = 1;
    while(getline(in,str))
    {
        if(row >= 4 && row < 279){
            /*std::string::size_type index = str.find("Volume");
            if(index != std::string::npos) {
                std::cout << str.substr(index) << std::endl;
                std::cout << index << std::endl;
            }*/
            //std::cout << str << std::endl;
            int i = 0;
            int j = 1;
            int count[5]={0,1,2,3,4};
            bool space_flag = false;
            
            for (i = 0; i < str.length(); i++) {
                if(str[i] == 0x20){
                    if(space_flag == false) {
                        //std::cout << i << ",";
                        count[j] = i;
                        //std::cout << count[j] << " , ";
                        j++;
                    }
                    space_flag = true;

                }
                else {
                    if(space_flag == true) {
                        //std::cout << i << ",";
                        count[j] = i;
                        //std::cout << count[j] << " , ";
                        j++;
                    }
                    space_flag = false;
                }
            }
            //std::cout << row << std::endl; //ただの改行
            out <<  str.substr(count[0],count[1]) << ",";
            out <<  str.substr(count[2],count[3] - count[2]) << ",";
            out <<  str.substr(count[4]) << std::endl;

        }
        row ++;
        //std::cout<< str << std::endl;
    }

    Texthandler th;
    //th.getRowNum();
    th.readTextFile("inputDVH.txt");
    
    if (!in.eof() || !out)
        error("something strange happend");

    in.close();
    out.close();


    
    std::cout << "Finished!!!" << std::endl;
}

