#include <stdio.h> 
#include "parser.h" 
#include "calc3.h"
int ex(node *p){
    // printf("vv %s\n",p->name);
    if(!p){
        // printf("NULL\n");
        return 0;
    }
    // else if(p->left==NULL && p->right==NULL){
    //     printf("leaf %s\n",p->name);
    // }
    // else{
    //     printf("%s\n",p->name);
    //     ex(p->left);
    //     ex(p->right);
    // }
    else if(strcmp(p->name,"function")==0){
            ex(p->right);
    }
    else if(strcmp(p->name,"func_args_body")==0){
            ex(p->left);
            ex(p->right);
    }
    else if(strcmp(p->name,"func_body")==0){
            ex(p->left);
            ex(p->right);
    }
    else if(strcmp(p->name,"program")==0){
                ex(p->right);
                return 0;
    }
    else if(strcmp(p->name,"main")==0){
                ex(p->left);
                ex(p->right);
                return 0;
    }
    else if(strcmp(p->name,"statements")==0){
                ex(p->left);
                ex(p->right);
                return 0;
    }else if(strcmp(p->name,"const")==0){
                return p->i;
    }else if(strcmp(p->name,"RETURN")==0){
        return 0;
    }else if(strcmp(p->name,"declaration")==0){
        symbol_table[p->left->index].i=ex(p->right);
        return 0;
    }else if(strcmp(p->name,"Variable")==0){
        return symbol_table[p->index].i;
    }else if(strcmp(p->name,"printf")==0){
           printf("%d\n",ex(p->left));
              return 0;
    }else if(strcmp(p->name,"+")==0){
        return ex(p->left)+ex(p->right);
    }
    else if(strcmp(p->name,"assignment")==0){
        symbol_table[p->left->index].i=ex(p->right);
    }else if(strcmp(p->name,"ADD")==0){
        return ex(p->left)+ex(p->right);
    }
    else if(strcmp(p->name,"SUB")==0){
        return ex(p->left)-ex(p->right);
    }
    else if(strcmp(p->name,"MUL")==0){
        return ex(p->left)*ex(p->right);
    }
    else if(strcmp(p->name,"DIV")==0){
        return ex(p->left)/ex(p->right);
    }
    else if(strcmp(p->name,"loop")==0){
        for(ex(p->left->left);ex(p->left->right->left);ex(p->left->right->right)){
            ex(p->right);
        }
        return 0;
    }else if(strcmp(p->name,"LT")==0){
            if(ex(p->left)<ex(p->right)){
                return 1;
            }else{
                return 0;
            }
    }else if(strcmp(p->name,"post_inc")==0){
            symbol_table[p->left->index].i=ex(p->left)+1;
            return 0;
    }
    else if(strcmp(p->name,"repeat")==0){
         while(ex(p->left)){
            ex(p->right);
         }
         return 0;
    }else if(strcmp(p->name,"when-other_wise")==0){
        if(strcmp(p->left->name,"when")==0){
            if(ex(p->left->left)){
                ex(p->left->right);
            }else{
                ex(p->right);
            }
        }else if(strcmp(p->left->name,"when-other_wise")==0){
            if(ex(p->left->left)){
                ex(p->left->right);
            }else{
                ex(p->right);
            }
        }
        return 0;
    }else if(strcmp(p->name,"other_wise")==0){
           ex(p->left);
           return 0;
    }
    else if(strcmp(p->name,"switch")==0){
             int b=1;
             int i=ex(p->left);
             p=p->right;
             node *t=p;
             if(p->left){
                p=p->left;
                while(b){
                    int j=ex(p->left->left);  
                    if(j==i){
                        b=0;
                       ex(p->left->right);
                    }else{
                        p=p->right;
                        if(strcmp(p->name,"case")==0){
                            if(ex(p->left)==i){
                                b=0;
                                ex(p->right);
                            }
                            break;
                        }
                    }
                }
             }
             if(b){
                ex(t->right->right);
             }
             return 0;
    }
    return 0;
}

void traverse(node *p){
   if(!p){
        return ;
    }
    else{
        if(strcmp(p->name,"function")==0){
            function_table[p->f_index].func_root=p;
        }
        traverse(p->left);
        traverse(p->right);
    }
    
}


