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
    char *token;
}node;
struct dataType {
    char * id_name;
    char * data_type;
    char * type;
    int i;
    float f;
    char c;
    int line_no;
} symbol_table[40];