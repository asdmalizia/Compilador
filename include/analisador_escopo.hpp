#ifndef analisador_escopo_hpp
#define analisador_escopo_hpp

#include <stdio.h>
#include "analisador_lexico.h"
#include "analisador_sintatico.hpp"

#define MAX_NEST_LEVEL 50

#define IS_TYPE_KIND(k) ((k)==ARRAY_TYPE_ || \
(k)==STRUCT_TYPE_|| \
(k)==ALIAS_TYPE_ || \
(k)==SCALAR_TYPE_)

//códigos de erro

typedef enum {
    ERR_REDCL,ERR_NO_DECL,ERR_TYPE_EXPECTED,ERR_BOOL_TYPE_EXPECTED,ERR_TYPE_MISMATCH,ERR_INVALID_TYPE,ERR_KIND_NOT_STRUCT,ERR_FIELD_NOT_DECL,ERR_KIND_NOT_ARRAY,ERR_INVALID_INDEX_TYPE,ERR_KIND_NOT_VAR,ERR_KIND_NOT_FUNCTION,ERR_TOO_MANY_ARGS,ERR_PARAM_TYPE,ERR_TOO_FEW_ARGS,ERR_RETURN_TYPE_MISMATCH
} errorcode;

//tipos disponíveis

typedef enum { NO_KIND_DEF_=-1, VAR_, PARAM_, FUNCTION_, FIELD_, ARRAY_TYPE_, STRUCT_TYPE_, ALIAS_TYPE_, SCALAR_TYPE_ , UNIVERSAL_} t_kind;

//data structure object

typedef struct object
{
    int nName;
    struct object *pNext;
    t_kind eKind;
    
    union {
        struct {
            struct object *pType;
            int nIndex;
            int nSize;
        } Var, Param, Field;
        struct {
            struct object *pRetType;
            struct object *pParams;
            int nIndex;
            int nParams;
            int nVars;
        } Function;
        struct {
            struct object *pElemType; int nNumElems;
            int nSize;
        } Array;
        struct {
            struct object *pFields;
            int nSize;
        } Struct;
        struct {
            struct object *pBaseType;
            int nSize;
        } Alias,Type;
    }_;
    
} object, *pobject;

// data structure t_attrib
typedef struct {
    t_nont nont;
    int nSize;
    union {
        struct {
            pobject obj;
            int name;}
        ID;
        struct {
            pobject type;
        } T, E,L,R,K,F,LV;
        struct {
            pobject type;
            pobject param;
            bool err;
        } MC;
        struct {
            int label;
        } MT,ME,MW,MA;
        struct{
            pobject type;
            pobject param;
            bool err;
            int n;
        } LE;
        struct {
            pobject list;
        } LI,DC,LP;
        struct {
            pobject type;
            bool val;
        } TRU,FALS;
        struct {
            pobject type;
            int pos;
            char val;
        } CHR;
        struct {
            pobject type;
            char* val;
            int pos;
        } STR;
        struct {
            pobject type;
            int val;
            int pos;
        } NUM;  
    }_;
} t_attrib;

extern void semantics(int rule);

#endif /* analisador_escopo_hpp */
