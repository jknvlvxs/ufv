grammar MicroJava;


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
CHAR_CONST : '\"' ~('\r' | '\n' | '\"')* '\"' ;

COMMENT : '/*' .*? '*/' -> skip;
LINE_COMMENT : '//' ~('\n'|'\r')* '\r'? '\n' -> skip;
WS : (' ' | '\t' | '\r' | '\n') -> skip;



//---------------------------------------------------------
//    Parser Definitions
//---------------------------------------------------------

program : 'program' IDENT (constDecl | varDecl | classDecl)* '{' methodDecl* '}' ;

constDecl : 'final' type IDENT '=' (INT_NUMBER | REAL_NUMBER | CHAR_CONST) ';' ;

varDecl : type (IDENT (',' IDENT)* | '[' ']') ';' ;

assignment: IDENT '=' expr;

classDecl : 'class' IDENT '{' varDecl* '}' ;

methodDecl : (type | 'void') IDENT '(' formPars? ')' varDecl* block ;

formPars : type IDENT (',' type IDENT)* ;

type : IDENT ('[' ']')? ;

block : '{' statement* '}' ;

statement :
  designator (('=' expr) | actPars)  ';'
  | 'if' '(' condition ')' statement ('else' statement)?
  | 'while' '(' condition ')' statement
  | 'return' expr? ';'
  | 'read' '(' designator ')' ';'
  | 'print' '(' expr (',' INT_NUMBER)? ')' ';'
  | block
  | ';'
  | 'for' '(' type assignment ';' condition ';' assignment ')' statement
  ;

actPars : '(' (expr (',' expr)*)? ')' ;

condition : 
	expr relop expr (logicOp condition)* 
	| 'not' condition 
	| '(' condition ')' 
	;

logicOp: 'and' | 'or';

relop : '>' |'<' |'==' |'>=' |'<=' |'!=' ;

expr :
	'-'? term
  | expr addOp term
  ;
	
term :
	factor
  | term mulOp factor
  ;

factor :
	designator actPars?
  | INT_NUMBER
  | REAL_NUMBER
  | CHAR_CONST
  | 'new' IDENT ('[' expr ']')?
  | '(' expr ')'
  ;

designator :
    IDENT 
  | designator '.' IDENT
  | designator '[' expr ']'
  ;

addOp : '+' | '-' ;

mulOp : '*' | '/' | '%' ;
