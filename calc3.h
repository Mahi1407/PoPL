typedef struct node { 
    struct node *left; 
    struct node *right; 
    char *id_name;
    char *name; //variable const
    int index;
    char c;
    float f;
    int i;
    char *ty;// numeric const
    int f_index;
    char *f_name;
}node;
struct symbol_table {
    char * id_name;
    char * data_type;
    char * type;
    int i;
    float f;
    char c;
    int line_no;
    
} symbol_table[40];

struct s_table {
    char * id_name;
    char * data_type;
    char * type;
    int i;
    float f;
    char c;
    int line_no;
    
} s_table;
struct function_table {
    char * func_name;
    char * func_data_type;
    struct symbol_table func_sym_table[40];
    node *func_root;
    int line_no;
    int sym_i;
} function_table[40];