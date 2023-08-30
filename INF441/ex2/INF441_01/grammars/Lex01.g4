
/*
 * O arquivo contem a definicao de uma gramatica.
 * O tipo pode ser "grammar" ou "lexer grammar".
 * Se for "lexer grammar", e apenas um analisador lexico;
 * se for "grammar", combina analisador lexico e sintatico.
 * O nome da gramatica tem que ser o mesmo do arquivo.
 * Sera gerada uma classe Java com mesmo nome da gramatica.
 */

lexer grammar Lex01;

/*
 * Em seguida, devem ser listadas as regras que definem lexemas.
 * O nome dos lexemas deve come�ar com letra mai�scula.
 */

KW_CLASS : 'class';

KW_IF : 'if';

KW_WHILE : 'while';

SEMICOLON : ';';

OPEN_PAR : '(';

CLOSE_PAR : ')';

PERIOD : '.';

/*
 * Podem tambem ser definidos expressoes auxiliares que nao configuram lexemes,
 * mas sao usadas para auxiliar na construcao dos lexemas
 * (nesse caso, usar diretiva "fragment").
 */

fragment
LETTER : 'a'..'z' | 'A'..'Z' ;

fragment
DIGIT : '0'..'9' ;

fragment
FLOAT_AUX : PERIOD | 'e' | 'E+' | 'E-' ;

KW_PROGRAM : 'program';

IDENT : LETTER (LETTER | DIGIT)* ;

FLOAT_LITERAL : DIGIT* FLOAT_AUX+ DIGIT (DIGIT | FLOAT_AUX)* ;

INTEGER_LITERAL : DIGIT+ ;

/*
 * Se ao lexema for associada a acao "-> skip", esse lexema sera ignorado
 * e o programa ira prosseguir, tentando construir novo lexema com os
 * caracteres seguintes.
 */

WS : (' '|'\r'|'\t'|'\n') -> skip ;

COMMENT : '/*' .*? '*/' -> skip ;

LINE_COMMENT : '//' ~('\n'|'\r')* '\r'? '\n' -> skip ;
