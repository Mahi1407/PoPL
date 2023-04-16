%{
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include"lexer.c"
    #include "calc3.h"
    void yyerror(const char *s);
    int yylex();
    int yywrap();
    int add(char);
    void insert_type();
    int search(char *);
	void insert_type();
	void print_tree(struct node*);
	void print_inorder(struct node *);
    int check_declaration(char *);
	int get_index(char *);
	void check_return_type(char *);
	int check_types(char *, char *);
	char *get_type(char *);
	struct node* mknode(struct node *left, struct node *right, char *name);
    int count=0;
	int syn_error=0;
    int q;
	char type[10];
    extern int countn;
	struct node *head;
	int sem_errors=0;
	int label=0;
	char buff[100];
	char errors[10][100];
	char reserved[20][10] = {"numeric", "decimal", "char", "back", "when", "other_wise", "loop", "main", "back", "include","case","default"};
	int gg;

%}

%union { 
		struct var_name { 
			char name[100]; 
			struct node* nd;
		} nd_obj;
		struct var_name2 { 
			char name[100]; 
			struct node* nd;
			char type[5];
		} nd_obj2; 
		
	} 
%token VOID 
%token <nd_obj> CHARACTER PRINTFF SCANFF INT FLOAT CHAR FOR IF ELSE TRUE FALSE NUMBER FLOAT_NUM ID LE GE EQ NE GT LT AND OR STR ADD MULTIPLY DIVIDE SUBTRACT UNARY INCLUDE RETURN WHILE SWITCH  CASE  BREAK DEFAULT ELSEIF
%type <nd_obj> headers main body return datatype statement arithmetic relop program elseif condition case  break  temp1 temp2 caselist default
%type <nd_obj2> init value expression
%left GE LE EQ NE GT LT 
%left ADD SUBTRACT 
%left MULTIPLY DIVIDE 
%%

program: headers main '(' ')' '{' body return '}' { $2.nd = mknode($6.nd, $7.nd, "main"); $$.nd = mknode($1.nd, $2.nd, "program");head = $$.nd;};

headers: headers headers { $$.nd = mknode($1.nd, $2.nd, "headers"); }
| INCLUDE { add('H'); } { $$.nd = mknode(NULL, NULL, $1.name); }
;

main: datatype ID { add('F');  }
;

datatype: INT { insert_type(); }
| FLOAT { insert_type(); }
| CHAR { insert_type(); }
| VOID { insert_type(); }
;

temp1: statement{printf("ef \n");$$.nd=$1.nd;}
|{printf("eef \n");$$.nd=NULL;}
;

body: FOR { add('K'); } '('temp1 temp2 condition temp2 temp1 ')' '{' body '}' { 
	struct node *temp = mknode($6.nd, $8.nd, "CONDITION"); 
	struct node *temp2 = mknode($4.nd, temp, "CONDITION"); 
	$$.nd = mknode(temp2, $11.nd, $1.name); 
} 
|SWITCH { add('K'); } '('value')' '{' caselist '}' {
	$$.nd = mknode($4.nd, $7.nd, $1.name); 
}
|WHILE { add('K'); } '('condition')' '{' body '}' { 
	$$.nd = mknode($4.nd, $7.nd, $1.name); 
}
|IF { add('K'); } '(' condition ')' '{' body '}' elseif { 
	struct node *iff = mknode($4.nd, $7.nd, $1.name);
	$$.nd = mknode(iff, $9.nd, "when-other_wise");
}
|body body {$$.nd = mknode($1.nd, $2.nd, "statements");}
|statement {$$.nd=$1.nd}
|SCANFF { add('K'); } '(' STR ',' '&' ID ')' ';' { $$.nd = mknode(NULL, NULL, "scanf"); }
|{$$.nd=NULL}
;

break:BREAK { add('K'); } ';'{$$.nd=mknode(NULL,NULL,"break");};

case:CASE { add('K'); } value ':' body break  {
	//struct node *temp=mknode($5.nd,$6.nd,"case_body");
	$$.nd=mknode($3.nd,$5.nd,$1.name);
}
|case case{$$.nd=mknode($1.nd,$2.nd,"cases")}
|{$$.nd=NULL}
;

default:DEFAULT {add('K')} ':' body break {
	//struct node *temp=mknode($4.nd,$5.nd,"case_body");
	$$.nd=mknode(NULL,$4.nd,$1.name)
};

caselist:case  default {$$.nd=mknode($1.nd,$2.nd,"cases")};


elseif: ELSEIF { add('K'); } '(' condition ')' '{' body '}' elseif {
	struct node *elif = mknode($4.nd, $7.nd, $1.name); 
	$$.nd = mknode(elif, $9.nd,"when-other_wise");
}
|ELSE { add('K'); } '{' body '}' { $$.nd = mknode($4.nd,NULL, $1.name); }
| { $$.nd =NULL;}

;
  
condition: expression relop expression  { $$.nd = mknode($1.nd, $3.nd, $2.nd->name);  }
| TRUE { add('K'); $$.nd = NULL; }
| FALSE { add('K'); $$.nd = NULL; }
// | ID { check_declaration($1.name); }  relop expression  { $1.nd = mknode(NULL, NULL, $1.name); $$.nd = mknode($1.nd, $4.nd, $3.name); }
;



temp2:';' {$$.nd = NULL; }
| { printf("bbb came\n");$$.nd = NULL }
;

statement: datatype ID {add('V'); gg=get_index($2.name)} init temp2 { 
	$2.nd = mknode(NULL, NULL, $2.name); 
	$2.nd->index=gg;
	$2.nd->name="Variable";
	$2.nd->id_name=$1.name;
	int t = check_types($1.name, $4.type);
	if(t>0) { 
		if(t == 1) {
			struct node *temp = mknode(NULL, $4.nd, "decimal_to_numeric"); 
			$$.nd = mknode($2.nd, temp, "declaration"); 
		} 
		else if(t == 2) { 
			struct node *temp = mknode(NULL, $4.nd, "numeric_to_decimal"); 
			$$.nd = mknode($2.nd, temp, "declaration"); 
		} 
		else if(t == 3) { 
			struct node *temp = mknode(NULL, $4.nd, "char_to_numeric"); 
			$$.nd = mknode($2.nd, temp, "declaration"); 
		} 
		else if(t == 4) { 
			struct node *temp = mknode(NULL, $4.nd, "numeric_to_char"); 
			$$.nd = mknode($2.nd, temp, "declaration"); 
		} 
		else if(t == 5) { 
			struct node *temp = mknode(NULL, $4.nd, "char_to_decimal"); 
			$$.nd = mknode($2.nd, temp, "declaration"); 
		} 
		else{
			struct node *temp = mknode(NULL, $4.nd, "decimal_to_char"); 
			$$.nd = mknode($2.nd, temp, "declaration"); 
		}
	} 
	else { 
		$$.nd = mknode($2.nd, $4.nd, "declaration"); 
	} 
}
| ID '=' expression temp2 {
	int u=check_declaration($1.name);
	$1.nd = mknode(NULL, NULL,$1.name);
	gg=get_index($1.name);
	$1.nd->index=gg;
	$1.nd->id_name=$1.name;
	$1.nd->name="Variable";
	if(u){
		printf("enter\n");
		char *id_type = get_type($1.name);
	
		if(strcmp(id_type, $3.type)) {
			if(!strcmp(id_type, "numeric")) {
				if(!strcmp($3.type, "float")){
					struct node *temp = mknode(NULL, $3.nd, "decimal_to_numeric");
					$$.nd = mknode($1.nd, temp, "assignment"); 
				}
				else{
					struct node *temp = mknode(NULL, $3.nd, "char_to_numeric");
					$$.nd = mknode($1.nd, temp, "assignment"); 
				}
				
			}
			else if(!strcmp(id_type, "float")) {
				if(!strcmp($3.type, "numeric")){
					struct node *temp = mknode(NULL, $3.nd, "numeric_to_decimal");
					$$.nd = mknode($1.nd, temp, "assignment"); 
				}
				else{
					struct node *temp = mknode(NULL, $3.nd, "char_to_decimal");
					$$.nd = mknode($1.nd, temp, "assignment"); 
				}
				
			}
			else{
				if(!strcmp($3.type, "numeric")){
					struct node *temp = mknode(NULL, $3.nd, "numeric_to_char");
					$$.nd = mknode($1.nd, temp, "assignment"); 
				}
				else{
					struct node *temp = mknode(NULL, $3.nd, "decimal_to_char");
					$$.nd = mknode($1.nd, temp, "assignment"); 
				}
			}
		}
	}
	else {
		$$.nd = mknode($1.nd, $3.nd, "assignment"); 
	}
}
| expression relop expression ';' {  $$.nd = mknode($1.nd, $3.nd, $2.nd->name); }
|ID  UNARY temp2  { 
	 
	check_declaration($1.name);
	$1.nd = mknode(NULL, NULL,$1.name);
	gg=get_index($1.name);
	$1.nd->index=gg;
	$1.nd->id_name=$1.name;
	$1.nd->name="Variable";
	printf("www %s %s\n",$1.name,$2.name);
	$2.nd=mknode(NULL,NULL,$2.name);
	$$.nd = mknode($1.nd, $2.nd,"post_inc"); 
	printf("wwf %s %s\n",$1.name,$2.name);
}
|UNARY ID temp2 { 
	check_declaration($2.name); 
	$1.nd = mknode(NULL, NULL,$1.name);
	$2.nd = mknode(NULL, NULL,$2.name);
	gg=get_index($2.name);
	$2.nd->index=gg;
	$2.nd->id_name=$2.name;
	$2.nd->name="Variable";
	$$.nd = mknode($1.nd, $2.nd, "pre_inc"); 
}
|PRINTFF { add('K'); } ID{gg=get_index($3.name)} ';' {
	 $3.nd = mknode(NULL, NULL,"Variable");
	 $3.nd->index=gg;
	 $3.nd->ty=symbol_table[gg].data_type;
	 $3.nd->i=symbol_table[gg].i;
	 $3.nd->f=symbol_table[gg].i;
	 $3.nd->c=symbol_table[gg].i;
	 $$.nd = mknode($3.nd, NULL, "printf");
}
|PRINTFF { add('K'); } value ';' {
	$$.nd = mknode($3.nd, NULL, "printf");
}
;

init: '=' value  {$$.nd = $2.nd; sprintf($$.type, $2.type); strcpy($$.name, $2.nd->name); }
| {  $$.nd = NULL }
;

expression: expression arithmetic expression { 
	if(!strcmp($1.type, $3.type)) {
		sprintf($$.type, $1.type);
		$$.nd = mknode($1.nd, $3.nd, $2.nd->name); 
	}
	else {
		if(!strcmp($1.type, "numeric") && !strcmp($3.type, "float")) {
			struct node *temp = mknode(NULL, $1.nd, "numeric_to_ofloat");
			sprintf($$.type, $3.type);
			$$.nd = mknode(temp, $3.nd, $2.name);
		}
		else if(!strcmp($1.type, "float") && !strcmp($3.type, "numeric")) {
			struct node *temp = mknode(NULL, $3.nd, "numeric_to_float");
			sprintf($$.type, $1.type);
			$$.nd = mknode($1.nd, temp, $2.name);
		}
		else if(!strcmp($1.type, "numeric") && !strcmp($3.type, "char")) {
			struct node *temp = mknode(NULL, $3.nd, "char_to_numeric");
			sprintf($$.type, $1.type);
			$$.nd = mknode($1.nd, temp, $2.name);
		}
		else if(!strcmp($1.type, "char") && !strcmp($3.type, "numeric")) {
			struct node *temp = mknode(NULL, $1.nd, "char_to_numeric");
			sprintf($$.type, $3.type);
			$$.nd = mknode(temp, $3.nd, $2.name);
		}
		else if(!strcmp($1.type, "decimal") && !strcmp($3.type, "char")) {
			struct node *temp = mknode(NULL, $3.nd, "char_to_decimal");
			sprintf($$.type, $1.type);
			$$.nd = mknode($1.nd, temp, $2.name);
		}
		else {
			struct node *temp = mknode(NULL, $1.nd, "chartofloat");
			sprintf($$.type, $3.type);
			$$.nd = mknode(temp, $3.nd, $2.name);
		}
	}
}
| value {strcpy($$.name, $1.name); sprintf($$.type, $1.type); $$.nd = $1.nd; }
;

arithmetic: ADD {$1.nd=mknode(NULL,NULL,"ADD");$$.nd=$1.nd}
| SUBTRACT {$1.nd=mknode(NULL,NULL,"SUB");$$.nd=$1.nd}
| MULTIPLY {$1.nd=mknode(NULL,NULL,"MUL");$$.nd=$1.nd}
| DIVIDE   {$1.nd=mknode(NULL,NULL,"DIV");$$.nd=$1.nd}
;

relop: LT {$1.nd=mknode(NULL,NULL,"LT");$$.nd=$1.nd}
| GT {$1.nd=mknode(NULL,NULL,"GT");$$.nd=$1.nd}
| LE {$1.nd=mknode(NULL,NULL,"LE");$$.nd=$1.nd}
| GE {$1.nd=mknode(NULL,NULL,"GE");$$.nd=$1.nd}
| EQ {$1.nd=mknode(NULL,NULL,"EQ");$$.nd=$1.nd}
| NE {$1.nd=mknode(NULL,NULL,"NE");$$.nd=$1.nd}
;

value: NUMBER { $1.nd=mknode(NULL,NULL,"const");$1.nd->name="const";$1.nd->ty="numeric";$1.nd->i=atoi($1.name); strcpy($$.name, $1.name); sprintf($$.type, "numeric"); add('C');$$.nd=$1.nd;  }
| FLOAT_NUM { $1.nd=mknode(NULL,NULL,"const");$1.nd->name="const";$1.nd->ty="float";$1.nd->i=atoi($1.name); strcpy($$.name, $1.name); sprintf($$.type, "float"); add('C');$$.nd=$1.nd;  }
| CHARACTER { $1.nd=mknode(NULL,NULL,"const");$1.nd->name="const";$1.nd->ty="char";$1.nd->i=atoi($1.name); strcpy($$.name, $1.name); sprintf($$.type, "char"); add('C');$$.nd=$1.nd;  }
| ID {
	gg=get_index($1.name);
	$1.nd = mknode(NULL, NULL, $1.name);
	$1.nd->id_name=$1.name;
	$1.nd->index=gg;
	$1.nd->name="Variable";
	strcpy($$.name, $1.name); 
	char *id_type = get_type($1.name); 
	sprintf($$.type, id_type); 
	check_declaration($1.name);
	$$.nd=$1.nd;
}
;

return: RETURN { add('K'); } value ';' { check_return_type($3.name); $1.nd = mknode(NULL, NULL, "back"); $$.nd = mknode($1.nd, $3.nd, "RETURN"); }
// | { $$.nd = NULL; }
;

%%

int main() {
    yyparse();
    printf("\n\n\n\n\n");
	
	printf("STEP 1: LEXICAL ANALYSIS  \n\n\n");
	
	printf("Processing....\n");
	printf("\nLexical analysis completed with no errors\n");

	printf("\n\n\t\t\t\t\t SYMBOL TABLE \n");
	printf("\n\nSYMBOL   \t\t\t\tDATATYPE   \t\t\t\tTYPE   \t\t\t\t\tLINE NUMBER \n");
	printf("____________________________________________________________________________________________________________________________________________\n\n");
	int i=0;
	
	for(i=0; i<count; i++) {
		printf("%s\t\t\t\t\t%s\t\t\t\t\t%s\t\t\t\t\t%d\t\t\t\t\n", symbol_table[i].id_name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line_no);
	}
	
	

	for(i=0;i<count;i++) {
		free(symbol_table[i].id_name);
		free(symbol_table[i].type);
	}
	printf("\n\n");
	printf("\t\t\t\t STEP 2: SYNTAX ANALYSIS \n\n");
	printf("Processing....\n\n");
	if(syn_error){
		printf("Syntax error found at %d ",countn+1);
	}else{
		printf("Syntax analysis is completed with no errors\n\n");

		print_tree(head); 
		printf("\n\n\n\n");
		printf("\t\t\t\t STEP 3: SEMANTIC ANALYSIS \n\n");
		if(sem_errors>0) {
			printf("Semantic analysis completed with %d errors\n", sem_errors);
			for(int i=0; i<sem_errors; i++){
				printf("\t - %s", errors[i]);
			}
		} else {
			printf("Semantic analysis completed with no errors\n\n\n");
		}
	}
	printf("OUTPUT \n\n");
	ex(head);
}

int search(char *type) {
	int i;
	for(i=count-1; i>=0; i--) {
		if(strcmp(symbol_table[i].id_name, type)==0) {
			return -i;
			break;
		}
	}
	return 0;
}
int  get_index(char *c) {
    q = search(c);
	int u=-q;
    if(!q) {
        sprintf(errors[sem_errors], "Line %d: Variable \"%s\" not declared before usage!\n", countn+1, c);
		sem_errors++;
		return 1;
    }
	return u;
}

int  check_declaration(char *c) {
    q = search(c);
    if(!q) {
        sprintf(errors[sem_errors], "Line %d: Variable \"%s\" not declared before usage!\n", countn+1, c);
		sem_errors++;
		return 1;
    }
	return 0;
}

void check_return_type(char *value) {
	char *main_datatype = get_type("main");
	char *return_datatype = get_type(value);
	if((!strcmp(main_datatype, "numeric") && !strcmp(return_datatype, "CONST")) || !strcmp(main_datatype, return_datatype)){
		return ;
	}
	else {
		sprintf(errors[sem_errors], "Line %d: Return type mismatch\n", countn+1);
		sem_errors++;
	}
}

int check_types(char *type1, char *type2){
	// declaration with no init
	if(!strcmp(type2, "null"))
		return -1;
	// both datatypes are same
	if(!strcmp(type1, type2))
		return 0;
	// both datatypes are different
	if(!strcmp(type1, "numeric") && !strcmp(type2, "decimal"))
		return 1;
	if(!strcmp(type1, "decimal") && !strcmp(type2, "numeric"))
		return 2;
	if(!strcmp(type1, "numeric") && !strcmp(type2, "char"))
		return 3;
	if(!strcmp(type1, "char") && !strcmp(type2, "numeric"))
		return 4;
	if(!strcmp(type1, "decimal") && !strcmp(type2, "char"))
		return 5;
	if(!strcmp(type1, "char") && !strcmp(type2, "decimal"))
		return 6;
}

char *get_type(char *var){
	for(int i=0; i<count; i++) {
		// Handle case of use before declaration
		if(!strcmp(symbol_table[i].id_name, var)) {
			return symbol_table[i].data_type;
		}
	}
}

int add(char c) {
	if(c == 'V'){
		for(int i=0; i<sizeof(reserved); i++){
			if(!strcmp(reserved[i], strdup(yytext))){
        		sprintf(errors[sem_errors], "Line %d: Variable name \"%s\" is a reserved keyword!\n", countn+1, yytext);
				sem_errors++;
				return -1;
			}
		}
	}
    q=search(yytext);
	if(!q) {
		if(c == 'H') {
			symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("Header");
			count++;
			return -1;
		}
		else if(c == 'K') {
			symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup("N/A");
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("Keyword\t");
			count++;
			return -1;
		}
		else if(c == 'V') {
			symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("Variable");
			count++;
			return count-1;
		}
		else if(c == 'C') {
			symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup("CONST");
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("Constant");
			count++;
			return -1;
		}
		else if(c == 'F') {
			symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("Function");
			count++;
			return -1;
		}
    }
    else if(c == 'V' && q) {
        sprintf(errors[sem_errors], "Line %d: Multiple declarations of \"%s\" not allowed!\n", countn+1, yytext);
		sem_errors++;
		return -1;
    }
}

struct node* mknode(struct node *left, struct node *right, char *name) {	
	struct node *newnode = (struct node *) malloc(sizeof(struct node));
	char *newstr = (char *) malloc(strlen(name)+1);
	strcpy(newstr, name);
	newnode->left = left;
	newnode->right = right;
	newnode->name = newstr;
	return(newnode);
}

void print_tree(struct node* tree) {
	printf("\n\nInorder traversal of the Parse Tree is: \n\n");
	print_inorder(tree);
}

void print_inorder(struct node *tree) {
	int i;
	if (tree->left) {
		print_inorder(tree->left);
	}
	printf("%s, ", tree->name);
	if (tree->right) {
		print_inorder(tree->right);
	}
	
}

void insert_type() {
	strcpy(type, yytext);
}

void yyerror(const char* msg) {
	printf("\n\n");
    fprintf(stdout, "%s\n",msg);
	syn_error++;
}