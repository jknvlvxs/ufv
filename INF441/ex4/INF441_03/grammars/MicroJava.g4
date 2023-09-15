grammar MicroJava;

@header {
package srcparser;
}

//---------------------------------------------------------
//    Lexer Definitions
//---------------------------------------------------------

fragment LETTER : 'a'..'z' | 'A'..'Z';
fragment DIGIT : '0'..'9';
IDENT : LETTER (LETTER | DIGIT)*;
INT_NUMBER : DIGIT+;
REAL_NUMBER :
  DIGIT+ ('.' DIGIT*)? EXPONENT?
  |
  '.' DIGIT+ EXPONENT?
  ;
fragment EXPONENT : ('e'|'E') ('+'|'-')? DIGIT+ ;

COMMENT : '/*' .*? '*/' ;
LINE_COMMENT : '//' ~('\n'|'\r')* '\r'? '\n'  ;
WS : (' ' | '\t' | '\r' | '\n') -> skip ;



//---------------------------------------------------------
//    Parser Definitions
//---------------------------------------------------------

program : 'program' IDENT methodDecl* ;

typeOrVoid : IDENT | 'void' ;

methodDecl :
   typeOrVoid IDENT '(' ')' (localVariable)* block;
   
localVariable : IDENT IDENT (',' IDENT)* ';';

block :
  '{' statement* '}' ;

statement :
  IDENT '=' expr ';'
  | 'return' expr? ';'
  | block
  | 'if' '(' condition ')' statement ('else' statement)?
  ;

expr : '-'? term (addOp term)* ;

term : factor (mulOp factor)* ;

factor :
  INT_NUMBER
  | IDENT
  | '(' expr ')'
  ;

addOp : '+' | '-' ;
mulOp : '*' | '/' | '%' ;
	
condition: expr relOp expr;

relOp: '>' | '<' | '==' | '!=' | '<=' | '>=' ;
