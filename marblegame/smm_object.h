//
//  smm_object.h
//  marblegame
//
//  Created by MacBook Air on 2023/12/21.
//

#ifndef smm_object_h
#define smm_object_h

#define SMMNODE_TYPE_LECTURE            0
#define SMMNODE_TYPE_RESTAURANT         1
#define SMMNODE_TYPE_LABORATORY         2
#define SMMNODE_TYPE_HOME               3
#define SMMNODE_TYPE_GOTOLAB            4
#define SMMNODE_TYPE_FOODCHANCE         5
#define SMMNODE_TYPE_FESTIVAL           6

#define SMMNODE_TYPE_MAX                7

typedef enum smmObjType {
    smmObjType_board = 0,
    smmObjType_card,
    smmObjType_grade
} smmObjType_e;

/* node type :
    lecture,
    restaurant,
    laboratory,
    home,
    experiment,
    foodChance,
    festival
*/
typedef enum smmNodeType {
    LECTURE = 0,
    RESTAURANT = 1,
    LABORATORY = 2,
    HOME = 3,
    GOTOLAB = 4,
    FOODCHANCE = 5,
    FESTIVAL = 6
} smmNodeType;



/* grade :
    A+,
    A0,
    A-,
    B+,
    B0,
    B-,
    C+,
    C0,
    C-
*/
typedef enum smmGrade {
    A_PLUS = 0,
    A_ZERO = 1,
    A_MINUS = 2,
    B_PLUS = 3,
    B_ZERO = 4,
    B_MINUS = 5,
    C_PLUS = 6,
    C_ZERO = 7,
    C_MINUS = 8
} smmGrade;



//object generation
void smmObj_genObject(char* name, smmObjType_e objType, int type, int credit, int energy, smmObjType_e grade);

//member retrieving
char* smmObj_getNodeName(int node_nr);
int smmObj_getNodeType(int node_nr);
int smmObj_getNodeCredit(int node_nr);
int smmObj_getNodeEnergy(int node_nr);

//element to string
char* smmObj_getTypeName(int type);


#endif /* smm_object_h */
