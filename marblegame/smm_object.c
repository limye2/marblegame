//
//  smm_object.c
//  marblegame
//
//  Created by MacBook Air on 2023/12/21.
//

#include "smm_common.h"
#include "smm_object.h"
#include "smm_database.h"
#include <string.h>

#define MAX_NODETYPE    7
#define MAX_GRADE   9
#define MAX_NODE    100

static char smmNodeName[SMMNODE_TYPE_MAX][MAX_CHARNAME] = {
    "강의",
    "식당",
    "실험실",
    "집",
    "실험실로이동",
    "음식찬스",
    "축제시간"
};

char* smmObj_getTypeName(int type)
{
    return (char*)smmNodeName[type];
}

typedef enum smmObjGrade {
    smmObjGrade_Ap = 0,
    smmObjGrade_A0,
    smmObjGrade_Am,
    smmObjGrade_Bp,
    smmObjGrade_B0,
    smmObjGrade_Bm,
    smmObjGrade_Cp,
    smmObjGrade_C0,
    smmObjGrade_Cm
} smmObjGrade_e;

typedef struct smmObject {
    char name[MAX_CHARNAME];
    smmObjType_e objType;
    int type;
    int credit;
    int energy;
    smmObjGrade_e grade;
} smmObject_t;

static smmObject_t smm_node[MAX_NODE];
static int smmObj_noNode = 0;

smmObject_t* smmObj_genObject(char* name, smmObjType_e objType, int type, int credit, int energy, smmObjGrade_e grade)
{
    smmObject_t* ptr;
    ptr=(smmObject_t*)malloc(sizeof(smmObject_t));
    
    strcpy(ptr->name, name);
    ptr->objType = objType;
    ptr->type = type;
    ptr->credit = credit;
    ptr->energy = energy;
    ptr->grade = grade;
    
    if (objType == smmObjType_board) {
        smmdb_addTail(LISTNO_NODE, ptr);}
    return ptr;
}

char* smmObj_getNodeName(smmObject_t* obj)
{
    return obj->name;
}

int smmObj_getNodeType(int node_nr)
{
    return smm_node[node_nr].type;
}

int smmObj_getNodeCredit(int node_nr)
{
    return smm_node[node_nr].credit;
}

int smmObj_getNodeEnergy(int node_nr)
{
    return smm_node[node_nr].energy;
}

