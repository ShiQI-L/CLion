//
// Created by lkp on 2023/11/17.
//
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/**
 * 自增操作， 其中‘i+++’表示i先自增然后再与后面的数相加
 */
void Self_incrementing(){
    int i=1,j=1;
    int a=i+++(++j);
    printf("%d\n",a);
}

void DemoTest(){
    int a,b,c;
    a=3;b=2;c=1;
    if((a>b)==c){
        printf("true");
    } else{
        printf("F");
    }
    
}

void cTryTest(){
    DemoTest();
}