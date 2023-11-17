grammar MicroJava;


//---------------------------------------------------------
//    Parser Definitions
//---------------------------------------------------------

program : 'program' IDENT (constDecl | varDecl | classDecl)* '{' methodDecl* '}' ;

varDecl : type IDENT (',' IDENT)* ';' ;

type:
    IDENT           # TypeWithoutArray
  | IDENT '[' ']'   # TypeWithArray
  ;

constDecl:
  'final' type IDENT '=' valConst ';';

valConst:
  INT_NUMBER          # ConstInt
  | REAL_NUMBER       # ConstReal
  | CHAR_CONST        # ConstStr
  ;

classDecl : 'class' IDENT '{' varDecl* '}' ;

typeOrVoid: type | 'void' ;

methodDecl : typeOrVoid IDENT '(' formPars ')' varDecl* block ;

formPars : ( formPar (',' formPar)* )?;

formPar: type IDENT ;

block : '{' statement* '}' ;

statement :
  designator '=' expr ';'                                  # Assign
  | designator actPars ';'                                 # Funcall
  | 'if' '(' condition ')' statement ('else' statement)?   # If
  | 'while' '(' condition ')' statement                    # While
  | 'return' expr? ';'                                     # Return
  | 'read' '(' designator ')' ';'                          # Read
  | 'print' '(' expr (',' INT_NUMBER)? ')' ';'             # Print
  | block                                                  # Stblock
  | ';'                                                    # Semicolon
  ;

actPars : '(' (expr (',' expr)*)? ')' ;

condition : expr relop expr ;

relop : '>' |'<' |'==' |'>=' |'<=' |'!=' ;

expr:
    op='-'? term             # OneTerm
  | expr op=('+'|'-') term   # AddSub
  ;

term:
    factor                         # OneFactor
  | term op=('*'|'/'|'%') factor   # MulDiv
  ;
  
factor:
    valConst                        # Value
  | designator actPars?             # Desig
  | 'new' IDENT ('[' expr ']')?     # New
  | '(' expr ')'                    # Parens
  ;
  
ADD : '+';
SUB : '-';
MUL : '*';
DIV : '/';
REM : '%';

designator :
  IDENT                       # DesigId
  | designator '.' IDENT      # DesigDot
  | designator '[' expr ']'   # DesigArray
  ;


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

