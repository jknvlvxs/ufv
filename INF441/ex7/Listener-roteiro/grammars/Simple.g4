grammar Simple;

//---------------------------------------------------------
//    Parser Definitions
//---------------------------------------------------------

program: statement*;

statement:
    IDENT '=' expr  ';' # Assign
  | 'print' expr';'		# Print
  ;

expr:
    op='-'? term 			# OneTerm
  | expr op=('+'|'-') term 	# AddSub
  ;

term:
    factor						# OneFactor
  | term op=('*'|'/') factor   	# MulDiv
  ;
  
factor:
    REAL_NUMBER				# Real
  | IDENT					# Id
  | '(' expr ')'			# Parens
  ;

ADD : '+';
SUB : '-';
MUL : '*';
DIV : '/';

//---------------------------------------------------------
//    Lexer Definitions
//---------------------------------------------------------

fragment LETTER : 'a'..'z' | 'A'..'Z';
fragment DIGIT : '0'..'9';
IDENT : LETTER (LETTER | DIGIT)*;
REAL_NUMBER :
  DIGIT+ ('.' DIGIT*)? EXPONENT?
  |
  '.' DIGIT+ EXPONENT?
  ;
fragment EXPONENT : ('e'|'E') ('+'|'-')? DIGIT+ ;

COMMENT : '/*' .*? '*/' -> skip;
LINE_COMMENT : '//' ~('\n'|'\r')* '\r'? '\n' -> skip;
WS : (' ' | '\t' | '\r' | '\n') -> skip;

