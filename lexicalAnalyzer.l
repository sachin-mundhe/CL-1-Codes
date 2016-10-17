/*  Author: Sachin
 *  Steps for execution
 *  1) lex lexicalAnalyzer.l 
 *  2) gcc lex.yy.c
 *  3) ./a.out
 */

%{
// Definition section
#include<stdio.h>
#include<stdlib.h>
%}

%%

[qQ][uU][iI][tT]          { yywrap(); } //Rule section..It consist of 'rule' and 'action'.
[eE][xX][iI][tT]          { yywrap(); }
[#][a-zA-Z]+              { printf("%s \tPreprocessor \n", yytext ); } 
[a-zA-Z]+[.][h]           { printf("%s \tHeader file \n", yytext ); }
"main"|"printf"|"scanf"   { printf("%s \tInbuilt function \n", yytext); }
"void"|"int"|"char"|"float"|"return"|"double" { printf("%s \tKeyword \n", yytext); }
"for"|"while"             { printf("%s \tLoop \n", yytext); }
"if"|"else"|"switch"      { printf("%s \tConditional \n", yytext); }
[%][a-z]                  { printf("%s \ttype cast\n", yytext); }
[a-zA-z]+[0-9a-zA-Z]*[(]  { printf("%s \tFunction \n", yytext); }
[a-zA-z]+[0-9a-zA-Z]*     { printf("%s \tIdentifier\n", yytext ); }
[0-9]+                    { printf("%s \tConstant \n", yytext ); }
[;|,|=|)|(|{|}|"|+|<|>]   { printf("%s \tInvalid character \n", yytext ); }
[ \t\n]                   { ECHO; }
.                         { ECHO; }

%%

//User subroutine section

int main() {
	yylex();
	return 0;
}


yywrap() {
	printf("Byeeeeee :-)\n");
	exit(1);
}
