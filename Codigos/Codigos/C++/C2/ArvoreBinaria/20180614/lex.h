#ifndef LEX_H
#define LEX_H

/* Define class constants; 0-255 reserved for ASCII characters: */
//#define EOF        256
#define IDENTIFIER 257
#define INTEGER    258
#define ERRONEOUS  259

typedef struct {
    char *file_name;
    int line_number;
    int char_number;
} Position_in_File;

typedef struct {
    int classe;
    char *repr;
    Position_in_File pos;
} Token_Type;

extern Token_Type Token;
extern void start_lex(char *ch );
extern void get_next_token(void);


#endif // LEX_H
