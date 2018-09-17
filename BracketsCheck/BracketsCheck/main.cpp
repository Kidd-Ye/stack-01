//
//  main.cpp
//  BracketsCheck
//
//  Created by kidd on 2018/9/17.
//  Copyright © 2018年 Kidd. All rights reserved.
//

#include <iostream>
#define MaxSize 50
#define ElemType char
typedef struct{
    ElemType data[MaxSize];
    int top;
} SqStack;

void InitStack(SqStack &S){
    S.top=-1;
}

void Pop(SqStack &S, ElemType &e){
    if (S.top == -1) {
        return;
    }
    e = S.data[S.top--];
}

void Push(SqStack &S, ElemType e){
    if (S.top == MaxSize-1) {
        return;
    }
    S.data[++S.top] = e;
}

bool IsEmpty(SqStack &S){
    return (S.top == -1) ? true : false;
}

bool BracketsCheck(char *str, SqStack &S){
    int i = 0;
    char temp = NULL;
    while (str[i]!= '\0') {
        switch (str[i]) {
            case '(': Push(S, '('); break;
            case '{': Push(S, '{'); break;
            case '}':
                Pop(S, temp);
                if (temp != '{') {
                    printf("括号不匹配\n");
                    return false;
                }
                break;
            case ')':
                Pop(S, temp);
                if (temp != '(') {
                    printf("括号不匹配\n");
                    return false;
                }
                break;
            default:
                break;
        }
        i++;
    }
    if (!IsEmpty(S)) {
        printf("括号不匹配\n");
        return false;
    }else{
        printf("括号匹配\n");
        return true;
    }
    
}
int main(int argc, const char * argv[]) {
    SqStack S;
    InitStack(S);
    char brackets[] = {'(','{','}',')','}'};
    
    BracketsCheck(brackets, S);
    return 0;
}
